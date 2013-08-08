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
#define BIND_MSG_FUNC(type,CLASS,func){\
	MsgFuncHandler *handle = new MsgFunction<CLASS>(&CLASS::func);\
	if (!theDispatcher.addHandle(type,new MsgFunction<CLASS>(this,&CLASS::func))) delete handle;} \

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
	virtual void init(){};
};

class MsgFuncHandler{
public:
	/**
	 * 调用器
	 * \param delegate 代理
	 * \paran object 对象
	 */
	virtual void call(void* cmd,unsigned int cmdLen){
	
	}
};
/**
 * 子类函数 包容函数
 */
template<class CLASS>
class MsgFunction:public MsgFuncHandler{
private:
	typedef int (CLASS::*Handle)(void* cmd,unsigned int cmdLen);
	Handle handle1;
	CLASS *object;
public:
	/**
	 * 使用1号方式构建
	 * (Socket *,int ,void*)
	 */
	MsgFunction(CLASS *object,Handle handle):object(object),handle1(handle){}
	
	/**
	 * 调用器
	 * \param delegate 代理
	 * \paran object 对象
	 */
	virtual void call(void* cmd,unsigned int cmdLen){
		if (object && object->__msg_de_name__ == __msg_de_name__) // 校验
		{
			((*object).*handle1)(cmd,cmdLen);
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
	 * \param T_HANDLE handle 处理句柄
	 **/
	bool addHandle(WORD type,MsgFuncHandler* handle)
	{
		if (type >= tables.size())
		{
			tables.resize(type + 1);
		}
		if (tables[type]) return false;
		tables[type] = handle;
		return true;
	}
	/**
	 * 处理消息
	 * \param object 对象
	 * \param cmd 消息
	 * \param len 消息长度
	 **/
	bool handle(WORD type,void*cmd,unsigned int cmdLen)
	 {
		MsgFuncHandler *h = NULL;
		if (type >= tables.size())
		{
			return false;
		}
		h =  tables[type];
		if (h) {
			h->call(cmd,cmdLen);
			return true;
		}
		return false;
	 }
private:
	std::vector<MsgFuncHandler*> tables;
};