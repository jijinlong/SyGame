/**
 * email:jjl_2009_hi@163.com
 * Author jijinlong
 * Data 2011.10.14~2012.3.18~~
 * All Rights Resvered
 ***/
#pragma once
#include "handle.h"
/**
 * 消息分发器
 **/
class MsgDispatcher:public Handles{
public:
	static MsgDispatcher & getMe()
	{
		static MsgDispatcher md;
		return md;
	}
	/**
	 * 处理消息
	 * \param object 对象
	 * \param cmd 消息
	 * \param len 消息长度
	 **/
	template<class CALSS>
	bool handle(CALSS *object,void* cmd,unsigned int cmdLen)
	{
		stNullCmd *nullCmd = (stNullCmd*) cmd;
		Handles::handle(object,nullCmd->type,nullCmd->param,cmd,cmdLen);
		return false;
	}
};

#define theDispatcher MsgDispatcher::getMe() // 消息转发访问器
