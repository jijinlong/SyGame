#include "MutiMonsterAI.h"
#include "MutiMonster.h"
NS_CC_BEGIN
bool MutiAI::action(MutiAIStub *stub,int event)
{
	if (event < timeEvts.size())
	{
		std::vector<MutiEvent> &evts = timeEvts.at(event);
		if (!evts.empty())
		{
			cc_timeval nowTime;
			CCTime::gettimeofdayCocos2d(&nowTime,NULL);
			for (std::vector<MutiEvent>::iterator iter = evts.begin(); iter != evts.end();++iter)
			{
				if (!iter->startTime.tv_sec || iter->execCount >= iter->execMaxCount)
				{
					CCTime::gettimeofdayCocos2d(&iter->startTime,NULL); // 重置时间
					iter->execCount = 0;
				}
			}
		}
	}
	if (event >= events.size()) return false;
	script::tixmlCodeNode *code = events.at(event);
	if (!code) return false;
	stub->ai = this;
	return theAILib.execCode(stub,code);
}
bool MutiEvent::checkTimeOut(cc_timeval & nowTime)
{
	float tap = CCTime::timersubCocos2d(&startTime,&nowTime) / 1000;
	if (tap >= this->tapTime)
	{
		return true;
	}
	return false;
}
/**
 * 定时执行事件
 */
bool MutiAI::timer(MutiAIStub * stub,int event)
{
	if (event >= events.size()) return false;
	std::vector<MutiEvent> &evts = timeEvts.at(event);
	if (evts.empty()) return false;
	cc_timeval nowTime;
	CCTime::gettimeofdayCocos2d(&nowTime,NULL);
	for (std::vector<MutiEvent>::iterator iter = evts.begin(); iter != evts.end();++iter)
	{
		if (iter->startTime.tv_sec && iter->checkTimeOut(nowTime) && iter->execCount < iter->execMaxCount)
		{
			theAILib.execCode(stub,iter->code);
			iter->startTime = nowTime;
			iter->execCount ++;
		}
	}
	return true;
}
#define BIND_AI_EVENT(event)\
	if (name == std::string(#event))\
	{\
		if (event >= events.size())\
		{\
			events.resize(event + 1);\
		}\
		events[event] = code;\
	}
#define BIND_TIME_AI_EVT(event)\
	if (name == std::string(#event))\
	{\
		MutiEvent timeEvt;\
		timeEvt.code = code;\
		timeEvt.tapTime = tapTime;\
		timeEvt.execMaxCount = info->getInt("execcount");\
		if (timeEvt.execMaxCount) timeEvt.execMaxCount = 1; \
		if (event >= timeEvts.size())\
		{\
			timeEvts.resize(event + 1);\
		}\
		timeEvts[event].push_back(timeEvt);\
	}
#define BIND_EVENT_ID(event)\
	if (name == std::string(#event))\
    {\
		return event;\
    }

bool MutiAI::addCode(script::tixmlCodeNode *code,script::tixmlCodeNode *info)
{
	std::string name = info->getAttr("name");
	int tapTime = info->getInt("taptime");
	if (tapTime == 0)
	{
		/*
		BIND_AI_EVENT(DEATH); // 死亡
		BIND_AI_EVENT(BIRTH); // 出生
		BIND_AI_EVENT(TARGET_ENTER); // 对象进入视野	
		BIND_AI_EVENT(TARGET_LEAVE); // 对象离开视野
		BIND_AI_EVENT(IDLE_ACTION); // 空闲行为
		BIND_AI_EVENT(ATTACK_ME); // 攻击我了
		BIND_AI_EVENT(MEET_TARGET); // 目标在攻击范围内
		BIND_AI_EVENT(HAD_TARGET_LEAVE); // 有对象离开
		BIND_AI_EVENT(HAD_TARGET); //有对象
		BIND_AI_EVENT(ATTACK_TRIED); // 攻击累了*/
		unsigned int eventId = getEventIdByName(name);
		if (eventId == (unsigned int) -1) return false;
		if (eventId >= events.size())
		{
			events.resize(eventId + 1);
		}
		events[eventId] = code;
	}
	else
	{
		/*
		BIND_TIME_AI_EVT(DEATH); // 死亡
		BIND_TIME_AI_EVT(BIRTH); // 出生
		BIND_TIME_AI_EVT(TARGET_ENTER); // 对象进入视野	
		BIND_TIME_AI_EVT(TARGET_LEAVE); // 对象离开视野
		BIND_TIME_AI_EVT(IDLE_ACTION); // 空闲行为
		BIND_TIME_AI_EVT(ATTACK_ME); // 攻击我了
		BIND_TIME_AI_EVT(MEET_TARGET); // 目标在攻击范围内
		BIND_TIME_AI_EVT(HAD_TARGET_LEAVE); // 有对象离开
		BIND_TIME_AI_EVT(HAD_TARGET); //有对象
		BIND_TIME_AI_EVT(ATTACK_TRIED); // 攻击累了
		*/
		MutiEvent timeEvt;
		timeEvt.code = code;
		timeEvt.tapTime = tapTime;
		timeEvt.execMaxCount = info->getInt("execcount");
		if (timeEvt.execMaxCount) timeEvt.execMaxCount = 1; 
		unsigned int eventId = getEventIdByName(name);
		if (eventId == (unsigned int) -1) return false;
		if (eventId >= timeEvts.size())
		{
			timeEvts.resize(eventId + 1);
		}
		timeEvts[eventId].push_back(timeEvt);
	}
	return true;
}
void MutiAI::bindEvent(const std::string &name,script::tixmlCodeNode *code)
{
	unsigned int eventId = getEventIdByName(name);
	if (eventId == (unsigned int) -1)return ;
	if (eventId >= events.size())
	{
		events.resize(eventId + 1);
	}
	events[eventId] = code;
}

void MutiAI::clearEvent(const std::string &name)
{
	unsigned int eventId = getEventIdByName(name);
	if (eventId == (unsigned int) -1) return ;
	if (eventId >= events.size())
	{
		events.resize(eventId + 1);
	}
	events[eventId] = NULL;
}

unsigned int MutiAI::getEventIdByName(const std::string &name)
{
	BIND_EVENT_ID(DEATH); // 死亡
	BIND_EVENT_ID(BIRTH); // 出生
	BIND_EVENT_ID(TARGET_ENTER); // 对象进入视野	
	BIND_EVENT_ID(TARGET_LEAVE); // 对象离开视野
	BIND_EVENT_ID(IDLE_ACTION); // 空闲行为
	BIND_EVENT_ID(ATTACK_ME); // 攻击我了
	BIND_EVENT_ID(MEET_TARGET); // 目标在攻击范围内
	BIND_EVENT_ID(HAD_TARGET_LEAVE); // 有对象离开
	BIND_EVENT_ID(HAD_TARGET); //有对象
	BIND_EVENT_ID(TOUCH_TIME_OUT); // 当前对象时间在池中过长
	BIND_EVENT_ID(MOVE_TO_DESTIONATION); // 移动到指定点
	BIND_EVENT_ID(ACTION_END); // 攻击技能结束
	return (unsigned int )-1;
}
int MutiAIStub::getTargetCount() // 当前对象的数量
{
	int count = 0;
	for (TARGETPOOL_ITER iter = targetPool.begin();iter != targetPool.end();++iter)
	{
		if (iter->monster)
		{
			count ++;
		}
	}
	return count;
}
void MutiAIStub::pickSuitTarget() // 挑选合适的对象
{
	int minWeight = 0,target = 0;
	for ( unsigned int index = 0; index < targetPool.size();index++)
	{
		if (targetPool[index].monster)
		{
			if (!minWeight)
			{
				minWeight = targetPool[index].weight;
				target = index;
			}
			else if (minWeight < targetPool[index].weight)
			{
				minWeight = targetPool[index].weight;
				target = index;
			}
		}
	}
	if (targetPool.empty() && target < targetPool.size() && target != 0)
	{
		MutiMonsterRefrence ref = targetPool[0];
		targetPool[0] = targetPool[target];
		targetPool[target] = ref;
	}
}
void MutiAIStub::removeTarget()
{
	if (targetPool.size()) targetPool.at(0).monster = NULL;
}
MutiMonster * MutiAIStub::getTarget() // 获取当前对象
{
	if (targetPool.size()) return targetPool.at(0).monster;
	return NULL;
}
MutiMonsterRefrence * MutiAIStub::getTargetRef()
{
	if (targetPool.size()) return &targetPool.at(0);
	return NULL;
}
void MutiAIStub::addTarget(MutiMonster *monster) // 增加对象
{
	for (TARGETPOOL_ITER iter = targetPool.begin();iter != targetPool.end();++iter)
	{
		if (iter->monster == monster)
		{
			return;
		}
	}
	MutiMonsterRefrence ref;
	ref.monster = monster;
	ref.uniqueId = monster->uniqueSerachId;
	CCTime::gettimeofdayCocos2d(&ref.touchStartTime,NULL);
	for (TARGETPOOL_ITER iter = targetPool.begin();iter != targetPool.end();++iter)
	{
		if (!iter->monster)
		{
			iter->monster = monster;
			iter->uniqueId = monster->uniqueSerachId;
			CCTime::gettimeofdayCocos2d(&iter->touchStartTime,NULL);
			return;
		}
	}
	targetPool.push_back(ref);

}
bool MutiMonsterRefrence::checkTimeOut(int timeout)
{
	cc_timeval nowTime;
	CCTime::gettimeofdayCocos2d(&nowTime,NULL);
	float dis = CCTime::timersubCocos2d(&touchStartTime,&nowTime) / 1000;
	if (dis >= timeout) return true;
	return false;
}
#define BIND_AI_ACTION(func)\
	{\
		AILibAction *action = new AILibAction;\
		action->type = script::__ACTION_CHECK__;\
		action->action = &MonsterAILib::func;\
		actions[#func] = action;\
	}

void MonsterAILib::bindActions()
{
	BIND_AI_ACTION(var);	
	BIND_AI_ACTION(print);
	BIND_AI_ACTION(calc);
	BIND_AI_ACTION(exec);
// 相关npc ai 的扩展
	BIND_AI_ACTION(putskill);
	BIND_AI_ACTION(move);
	BIND_AI_ACTION(movetotarget);
	BIND_AI_ACTION(check_touch_lasttime);
	BIND_AI_ACTION(reset_touch_lasttime);
	BIND_AI_ACTION(clearmovepath);
	BIND_AI_ACTION(checknowtarget);
	BIND_AI_ACTION(checknowposition);
	BIND_AI_ACTION(moverandarround);
	BIND_AI_ACTION(bind_event);
	BIND_AI_ACTION(clear_event);
	BIND_AI_ACTION(reset_notify);
	BIND_AI_ACTION(add_timer);
	BIND_AI_ACTION(check_timer);
	BIND_AI_ACTION(reset_timer);
	BIND_AI_ACTION(del_timer);
	BIND_AI_ACTION(check_now_monster_action);
}
void MonsterAILib::initWithFile(const char *fileName)
{
	bindActions();
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	initFromString((char*)buffer);
}
void MonsterAILib::takeNode(script::tixmlCodeNode* node)
{
	if (!node) return; // 处理事件
	script::tixmlCodeNode aiNode = node->getFirstChildNode("ai");
	while (aiNode.isValid())
	{
		script::tixmlCodeNode codePtr = aiNode.getFirstChildNode("event");
		MutiAI *ai = new MutiAI();
		aiNode.getAttr("id",ai->id);
		if (ai->id >= npcAis.size())
		{
			npcAis.resize(ai->id + 1);
		}
		if (!npcAis[ai->id])
		{
			npcAis[ai->id] = ai;	
		}
		else
			delete ai;
		while (codePtr.isValid())
		{
			std::string name = codePtr.getAttr("name");
			std::string code = codePtr.getAttr("code");
			npcAis[ai->id]->addCode(findCode(code.c_str()),&codePtr);
			codePtr = codePtr.getNextNode("event");	
		}	
		aiNode = aiNode.getNextNode("ai");
	}		
}
void MonsterAILib::destroy()
{
	for (std::vector<MutiAI*>::iterator iter = npcAis.begin();
		 iter != npcAis.end();++iter)
	{
		MutiAI * npcAi = *iter;
		if (npcAi)
		{
			delete npcAi;
		}
	}
	npcAis.clear();
	script::Lib<AILibAction,MutiAIStub,MonsterAILib>::release();
}
void MonsterAILib::execEvent(DWORD npcAIID,MutiAIStub *stub,int event)
{
	if (npcAIID < npcAis.size())
	{
		MutiAI * ai = npcAis.at(npcAIID);
		if (ai)
		{
			ai->action(stub,event);	
		}
	}	
}
void MonsterAILib::tapExecEvent(DWORD npcAIID,MutiAIStub *stub,int event)
{
	if (npcAIID < npcAis.size())
	{
		MutiAI * ai = npcAis.at(npcAIID);
		if (ai)
		{
			ai->timer(stub,event);	
		}
	}	
}
int MonsterAILib::putskill(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub->npc)
	{
		stub->npc->tryAction(node->getAttr("name"));
	}
	return 1;
}

/**
 * 行走到 目标
 * <movetotarget/>
 **/
int MonsterAILib::movetotarget(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	MutiMonster *target = stub->getTarget();
	if (stub && target)
	{
		stub->npc->tryMoveUseAstr(target->getNowIndex());
	}
	return 1;
}
/**
 * 设定距离最短的为当前攻击对象 重新设定lock对象
 * <lockmindistacetarget/>
 */
int MonsterAILib::lockmindistacetarget(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	return 1;
}
/**
 * 将权值最大者锁定 重新设定
 * <locksuittarget/>
 **/
int MonsterAILib::locksuittarget(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	// 权值最大的挑选为首位
	if (stub) stub->pickSuitTarget();
	return 1;
}
/**
 * 行走到目的地
 * <move targetx="" targety=""/>
 */
int MonsterAILib::move(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		stub->npc->tryMoveUseAstr(GridIndex(node->getInt("x"),node->getInt("y")));
	}
	return 1;
}
/**
 * 沿着目标绕圈
 * <moverandarround/>
 */
int MonsterAILib::moverandarround(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	MutiMonster *target = stub->getTarget();
	if (stub && target)
	{
		stub->npc->tryMoveUseAstr(target->getAroundRandomPoint());
	}
	return 1;
}

int MonsterAILib::clearmovepath(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		stub->npc->movePath.clear();
	}
	return 1;
}

/**
 * 设置当前攻击时间
 */
int MonsterAILib::reset_touch_lasttime(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		MutiMonsterRefrence * ref = stub->getTargetRef();
		if (ref)
		{
			 CCTime::gettimeofdayCocos2d(&ref->touchStartTime,NULL);
		}
	}
	return 1;
}
/**
 * 检查攻击的持续时间
 */
int MonsterAILib::check_touch_lasttime(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		int lastTime = node->getInt("value");
		MutiMonsterRefrence * ref = stub->getTargetRef();
		if (ref)
		{
			cc_timeval nowTime;
			CCTime::gettimeofdayCocos2d(&nowTime,NULL);
			float disTime = CCTime::timersubCocos2d(&ref->touchStartTime,&nowTime) / 1000;
			if (disTime >= lastTime)
			{
				return 1;
			}
		}
	}
	return 0;
}
/**
 * 检查当前的位置
 */
int MonsterAILib::checknowposition(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		GridIndex nowIndex = stub->npc->getNowIndex();
		
		if (nowIndex.equal(GridIndex(node->getInt("x"),node->getInt("y"))))
		{
			return 1;
		}
	}
	return 0;
}

/**
 * 检查当前的目标
 */
int MonsterAILib::checknowtarget(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		MutiMonster *monster = stub->getTarget();	
		if (monster)
		{
			return monster->data.id = node->getInt("id");
		}
	}
	return 0;
}
/**
 * 更改事件响应函数
 **/
int MonsterAILib::bind_event(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->ai)
	{
		stub->ai->bindEvent(node->getAttr("event"),findCode(node->getAttr("code")));
	}
	return 0;
}
/**
 * 清除事件
 **/
int MonsterAILib::clear_event(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->ai)
	{
		stub->ai->clearEvent(node->getAttr("event"));
	}
	return 0;
}
/**
 * 重置事件触发 由于事件触发后不再进行 触发了 需要有此机制
 * <reset_notify stub="self" event="MOVE_TO_DESTIONATION" />
 **/
int MonsterAILib::reset_notify(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (!stub || !stub->ai)  return 0;
	// target or self
	std::string stubName = node->getAttr("stub");
	unsigned int eventId = stub->ai->getEventIdByName(node->getAttr("event"));
	if (eventId == (unsigned int)-1) return 0;
	if (stubName == "self")
	{
		stub->resetNotify(eventId);
	}
	if (stubName == "target")
	{
		if (stub->getTargetRef())
			stub->getTargetRef()->resetNotify(eventId);
	}
	return 0;
}
/**
 * 增加时间
 */
int MonsterAILib::add_timer(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && node)
	{
		int timerId = node->getInt("id");
		stub->addTimer(timerId);
		return 1;
	}
	return 0;
}

/**
 * 检查时间
 **/
int MonsterAILib::check_timer(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && node)
	{
		int timerId = node->getInt("id");
		int timeout = node->getInt("timeout");
		stTimeInfo *timerInfo = stub->getTimer(timerId);
		if (timerInfo && timerInfo->checkTimeOut(timeout))
			return 1;
	}
	return 0;
}

/**
 * 重置时间
 */
int MonsterAILib::reset_timer(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	int timerId = node->getInt("id");
	stTimeInfo *timeInfo = stub->getTimer(timerId);
	if (timeInfo)
	{
		timeInfo->reset();
		return 1;
	}
	return 0;
}

/**
 * 删除时间
 */
int MonsterAILib::del_timer(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && node)
	{
		int timerId = node->getInt("id");
		stub->delTimer(timerId);
		return 1;
	}
	return 0;
}

/**
 * 检查怪物当前行为
 */
int MonsterAILib::check_now_monster_action(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && node)
	{
		int actionId = node->getInt("id");
		if (actionId == stub->npc->nowActionName) return 1;
	}
	return 0;
}
NS_CC_END