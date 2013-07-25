#include "NpcAI.h"
#include "Npc.h"
bool NpcAI::action(NpcAIStub *stub,int event)
{
	if (event >= events.size()) return false;
	script::tixmlCodeNode *code = events.at(event);
	if (!code) return false;
	return theNpcAILib.execCode(stub,code);
}
#define BIND_AI_EVENT(event)\
	if (name == #event)\
	{\
		if (event >= events.size())\
		{\
			events.resize(event);\
		}\
		events[event] = code;\
	}
bool NpcAI::addCode(script::tixmlCodeNode *code,std::string name)
{
	if (name == "DEATH")
	{
		if (DEATH >= events.size())
		{
			events.resize(DEATH);
		} 
		events[DEATH] = code;
	}
	else if (name == "BIRTH")
	{
		if (BIRTH >= events.size())
		{
			events.resize(BIRTH);
		}
		events[BIRTH] = code;
	}
	// 以后扩展欢迎使用宏
	BIND_AI_EVENT(OBJECT_IN); // 玩家进入视野	
	BIND_AI_EVENT(OBJECT_LEAVE);
	BIND_AI_EVENT(TIMER);
}
#define BIND_AI_ACTION(func)\
	{\
		AILibAction *action = new AILibAction;\
		action->type = script::__ACTION_CHECK__;\
		action->action = &NpcAILib::func;\
		actions[#func] = action;\
	}

void NpcAILib::bindActions()
{
	BIND_AI_ACTION(var);	
	BIND_AI_ACTION(print);
	BIND_AI_ACTION(calc);
	BIND_AI_ACTION(exec);
// 相关npc ai 的扩展
	BIND_AI_ACTION(putskill);
	BIND_AI_ACTION(searchuser);
	BIND_AI_ACTION(moveto);
	BIND_AI_ACTION(setweight);
	BIND_AI_ACTION(timer);
	BIND_AI_ACTION(resettimer);
	BIND_AI_ACTION(timerpass);
	BIND_AI_ACTION(addtimer);
	BIND_AI_ACTION(deltimer);
	BIND_AI_ACTION(choicenearest);
	BIND_AI_ACTION(checkexist);
	BIND_AI_ACTION(checkdistance);
	BIND_AI_ACTION(settarget);
	BIND_AI_ACTION(timerexsit);
	BIND_AI_ACTION(percent);
}

void NpcAILib::takeNode(script::tixmlCodeNode* node)
{
	if (!node) return; // 处理事件
	if (node->equal("npcai"))
	{
		script::tixmlCodeNode codePtr = node->getFirstChildNode("event");
		NpcAI *ai = new NpcAI();
		node->getAttr("id",ai->id);
		while (codePtr.isValid())
		{
			std::string name = codePtr.getAttr("name");
			std::string code = codePtr.getAttr("code");
			if (ai->id >= npcAis.size()) npcAis.resize(ai->id);
			if (!npcAis[ai->id])
			{
				npcAis[ai->id] = ai;	
				ai->addCode(findCode(code.c_str()),name);
			}
			else
			{
				delete ai;
			}	
			codePtr = codePtr.getNextNode("event");	
		}	
	}		
}
void NpcAILib::destroy()
{
	for (std::vector<NpcAI*>::iterator iter = npcAis.begin();
		 iter != npcAis.end();++iter)
	{
		NpcAI * npcAi = *iter;
		if (npcAi)
		{
			delete npcAi;
		}
	}
	npcAis.clear();
	script::Lib<AILibAction,NpcAIStub,NpcAILib>::release();
}
void NpcAILib::execEvent(DWORD npcAIID,NpcAIStub *stub,int event)
{
	if (npcAIID < npcAis.size())
	{
		NpcAI * ai = npcAis.at(npcAIID);
		if (ai)
		{
			ai->action(stub,event);	
		}
	}	
}
/**
 * 释放skill给当前npc选择的对象
 * <putskill id="1" targetlist="0-1-5" targettype="random" targetnum=""/> 
 * */
int NpcAILib::putskill(NpcAIStub* stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0; 	
	Npc *npc = stub->npc;
	if (!npc) return 0;
	return 1;
}
/**
 * <searchuser maxnum="" range="">
 *    <putskill id="1" targettype="random"/> <!--释放技能--> 
 *    <putskill id="1" targetlist="0-1-5" targettype="random" targetnum=""/> 
 *    <moveto target="0" destination="50:50 相对点" trycount="10" tryusetime="800" succode="" errcode=""/>
 * </searchuser>
 * */
int NpcAILib::searchuser(NpcAIStub* stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	return 1;
}
/**
 *移动到某点
 * <moveto target="0" destination="50:50 相对点" trycount="10" tryusetime="800" succode="" errcode=""/>
 * */
int NpcAILib::moveto(NpcAIStub* stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	
	return 1;
}
/**
 * 设置权值
 * <setweight id="" value=""/> 
 * */
int NpcAILib::setweight(NpcAIStub* stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	return 1;
}

int NpcAILib::timerpass(NpcAIStub *stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	if (npc->passStartTime.second == 0 && npc->passStartTime.msecond == 0)
	{
		npc->passStartTime = sys::sTime::getNowTime();
		return 0;
	}
	DWORD value = 0;
	node->getAttr("value",value);
	if (npc->passStartTime + value < sys::sTime::getNowTime())
	{
		return 1;
	}
	return 0;
}

int NpcAILib::resettimer(NpcAIStub *stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	npc->passStartTime = sys::sTime::getNowTime();
	return 1;
}

int NpcAILib::timer(NpcAIStub *stub,script::tixmlCodeNode * node)
{
	if (!stub || !node) return 0;
	Npc *npc = stub->npc;
	if (!npc) return 0;
	DWORD timerid = 0;
	node->getAttr("timerid",timerid);
	DWORD lasttime = 0;
	node->getAttr("lasttime",lasttime);
	if (npc->checkTimeOut(timerid,lasttime)) return 1;
	return 0;
}

/**
 * 攻击
 **/
int NpcAILib::attack(NpcAIStub *stub,script::tixmlCodeNode *node)
{

}
/**
 * <addtimer id=""/>
 * */
int NpcAILib::addtimer(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <deltimer id=""/>
 */
int NpcAILib::deltimer(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <choicenearest type="nine/now" toid=""/>
 * */
int NpcAILib::choicenearest(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <checkdistance id="" value=""/>
 * */
int NpcAILib::checkdistance(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <checkexist id=""/>
 **/
int NpcAILib::checkexist(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 *<settarget toid="" type=""/>
 * */
int NpcAILib::settarget(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <percent value="9" subvalue="1000"/>
 * */
int NpcAILib::percent(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <timerexsit value=""/>
 * */
int NpcAILib::timerexsit(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
/**
 * <checkninehaduser/>
 * */
int NpcAILib::checkninehaduser(NpcAIStub *stub,script::tixmlCodeNode * node)
{

}
