/**
 * email:jjl_2009_hi@163.com
 * Author jijinlong
 * Data 2011.10.14~2012.3.18~~
 * All Rights Resvered
 ***/
#pragma once
#include "stdio.h"
#include "vector"
#include <string>
#define BIND_MSG_FUNC(type,param,CLASS,func){\
	MsgFuncHandler *handle = new MsgFunction<CLASS>(&CLASS::func);\
	handle->__msg_de_name__ = #CLASS;\
	if (!theDispatcher.addHandle(type,param,new MsgFunction<CLASS>(&CLASS::func))) delete handle;} \

#define DEC_MSG_BIND_TABLES(__class__) __class__():MsgCallDelegate(#__class__){init();} static void handleTables();

#define MSG_BIND_TABLES_START(__class__)AutoUserRun<__class__> __class__##run;void __class__::handleTables(){
		
#define MSG_BIND_TABLES_END } 

template<class T>
struct AutoUserRun{
	AutoUserRun()
	{
		T::handleTables();
	}
};

class MsgCallDelegate{
public:
	MsgCallDelegate(){}
	MsgCallDelegate(std::string name):__msg_de_name__(name){}
	std::string __msg_de_name__; // delegate 的名字
	virtual void init(){};
};

class MsgFuncHandler{
public:
	/**
	 * 调用器
	 * \param delegate 代理
	 * \paran object 对象
	 */
	virtual void call(MsgCallDelegate *delegate,void* cmd,unsigned int cmdLen){
	
	}
	std::string __msg_de_name__; // 名字
};
/**
 * 子类函数 包容函数
 */
template<class CLASS>
class MsgFunction:public MsgFuncHandler{
private:
	typedef int (CLASS::*Handle)(void* cmd,unsigned int cmdLen);
	Handle handle1;
public:
	/**
	 * 使用1号方式构建
	 * (Socket *,int ,void*)
	 */
	MsgFunction(Handle handle):handle1(handle){}
	
	/**
	 * 调用器
	 * \param delegate 代理
	 * \paran object 对象
	 */
	virtual void call(MsgCallDelegate *delegate,void* cmd,unsigned int cmdLen){
		CLASS* runObject = (CLASS*) delegate;
		if (runObject->__msg_de_name__ == __msg_de_name__) // 校验
		{
			((*runObject).*handle1)(cmd,cmdLen);
		}
	}	
};

/**
 * 处理消息
 */
class Handles{
public:
	/**
	 * 增加消息处理的句柄
	 * \param type 消息类型
	 * \param param 消息子类型
	 * \param T_HANDLE handle 处理句柄
	 **/
	bool addHandle(BYTE type,WORD param,MsgFuncHandler* handle)
	{
		if (type >= tables.size())
		{
			tables.resize(type + 1);
		}
		if (param >= tables[type].size())
		{
			tables[type].resize(param + 1);
		}
		if (tables[type][param]) return false;
		tables[type][param] = handle;
		return true;
	}
	/**
	 * 处理消息
	 * \param object 对象
	 * \param cmd 消息
	 * \param len 消息长度
	 **/
	bool handle(MsgCallDelegate *msgcall,BYTE type,WORD param,void*cmd,unsigned int cmdLen)
	 {
		MsgFuncHandler *h = NULL;
		if (type >= tables.size())
		{
			return false;
		}
		if (param >= tables[type].size())
		{
			if (tables[type].size() == 1)
			{
				h =  tables[type][0];
			}
			return false;
		}
		h =  tables[type][param];
		if (h) {
			h->call(msgcall,cmd,cmdLen);
			return true;
		}
		return false;
	 }
private:
	std::vector<std::vector<MsgFuncHandler*> > tables;
};