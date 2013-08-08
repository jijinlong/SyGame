#pragma once
#include "handle.h"
#include "NetCommand.h"
#include "pool.h"
#include "thread.h"
/**
 * theNet.bind(command,new FuncCall<CALSS>(this,function);
 * visit()
 * {
     theNet.popCommands(); // 弹出并分发消息
 *}
 */

// TODO 负责不间断短连接
// TODO 负责接收消息到缓存
// TODO 在逻辑主循环里分发事件
// TODO 负责发送消息
// 发送 与接收消息在一个线程里

class Net:public Hanldes,public zThread,public net::RecvPackageCallback{
public:
	Net()
	{
		init();
	}
	// 初始化 启动连接 和 处理线程
	void init()
	{
		valid = true;
		pool::load();
		client.init"127.0.0.1",5050);
		pool.bindEvent(&client,pool::IN_EVT|pool::OUT_EVT);
		start(); // 开启线程
	}
	void stop()
	{
		valid = false;
	}
	pool::EventPool pool;
	pool.init();
	net::Client client;
	static Net & getMe()
	{
		static Net t;
		return t;
	}
	void bind(unsigned short commandID,MsgFuncHandler *handler)
	{
		addHandle(commandID,handler);
	}
	/**
	 * 线程中运行
	 */
	void run()
	{
		while (valid) // 服务器单线程框架
		{
			pool::EventBase *evt = pool.pullEvent();
			if (evt)
			{
				if (evt->isErr()) // 出错删除
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					net::Connection *conn = (net::Connection*) connEvt->target;
					if (conn)
					{
						conn->destroy();
						delete conn;
					}
					continue;
				}
				if (evt->isOut()) // 写
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					if (connEvt->target)
					{
						(*connEvt)->doSend(evt);
					}
				}
				if (evt->isIn()) // 读
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					if (connEvt->target)
					{
						(*connEvt)->doRead(evt,this);
					}
				}
				
			}
		}
	}
	bool valid;

	void sendCmd(void *cmd,unsigned int len)
	{
		// 放入到 循环队列中 超出部分放入本队列里 太多则丢包
		client.sendCmd(cmd,len);
	}
private:
	void handle(void *cmd,unsigned int len)
	{
		stNullCmd *nullCmd = (stNullCmd*) cmd;
		Hanldes::handle(nullCmd->type,cmd,len); // 处理逻辑
	}
	void doGetCommand(void *cmd,unsigned int len)
	{
		pushCommands(new Record(cmd,len));
	}
	void pushCommands(Record *record)
	{
	//	records.push_back(record); // 使用循环队列 不加锁
	}
	//std::vector<Record*> records;
public:
	/**
	 * 在场景on_visit 里调用 当对象删除时 要从事件池中取消自己
	 */
	void popCommands()
	{
		//handle(record->content,record->contentSize); 从循环队列中取数据
	}
};

#define theNet Net::getMe()