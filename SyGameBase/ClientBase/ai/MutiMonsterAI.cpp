#include "MutiMonsterAI.h"
#include "MutiMonster.h"
NS_CC_BEGIN
bool MutiAI::action(MutiAIStub *stub,int event)
{
	if (event >= events.size()) return false;
	script::tixmlCodeNode *code = events.at(event);
	if (!code) return false;
	return theAILib.execCode(stub,code);
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
bool MutiAI::addCode(script::tixmlCodeNode *code,std::string name)
{
	if (name == std::string("DEATH"))
	{
		if (DEATH >= events.size())
		{
			events.resize(DEATH + 1);
		} 
		events[DEATH] = code;
	}
	else if (name == std::string("BIRTH"))
	{
		if (BIRTH >= events.size())
		{
			events.resize(BIRTH + 1);
		}
		events[BIRTH] = code;
	}
	
	// 以后扩展欢迎使用宏
	BIND_AI_EVENT(TARGET_ENTER); // 对象进入视野	
	BIND_AI_EVENT(TARGET_LEAVE); // 对象离开视野
	BIND_AI_EVENT(IDLE_ACTION); // 空闲行为
	BIND_AI_EVENT(ATTACK_ME); // 攻击我了
	BIND_AI_EVENT(MEET_TARGET); // 目标在攻击范围内
	BIND_AI_EVENT(HAD_TARGET_LEAVE); // 有对象离开
	BIND_AI_EVENT(HAD_TARGET); //有对象
	BIND_AI_EVENT(ATTACK_TRIED); // 攻击累了
	return true;
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
	CCTime::gettimeofdayCocos2d(&ref.attackStartTime,NULL);
	for (TARGETPOOL_ITER iter = targetPool.begin();iter != targetPool.end();++iter)
	{
		if (!iter->monster)
		{
			iter->monster = monster;
			iter->uniqueId = monster->uniqueSerachId;
			CCTime::gettimeofdayCocos2d(&iter->attackStartTime,NULL);
			return;
		}
	}
	targetPool.push_back(ref);

}
bool MutiMonsterRefrence::checkTimeOut(int timeout)
{
	cc_timeval nowTime;
	CCTime::gettimeofdayCocos2d(&nowTime,NULL);
	float dis = CCTime::timersubCocos2d(&attackStartTime,&nowTime) / 1000;
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
	BIND_AI_ACTION(checkattacklasttime);
	BIND_AI_ACTION(resetattacktime);
	BIND_AI_ACTION(clearmovepath);
	BIND_AI_ACTION(checknowtarget);
	BIND_AI_ACTION(checknowposition);
	BIND_AI_ACTION(moverandarround);
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
			npcAis[ai->id]->addCode(findCode(code.c_str()),name);
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
int MonsterAILib::resetattacktime(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		MutiMonsterRefrence * ref = stub->getTargetRef();
		if (ref)
		{
			 CCTime::gettimeofdayCocos2d(&ref->attackStartTime,NULL);
		}
	}
	return 1;
}
/**
 * 检查攻击的持续时间
 */
int MonsterAILib::checkattacklasttime(MutiAIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->npc)
	{
		int lastTime = node->getInt("value");
		MutiMonsterRefrence * ref = stub->getTargetRef();
		if (ref)
		{
			cc_timeval nowTime;
			CCTime::gettimeofdayCocos2d(&nowTime,NULL);
			float disTime = CCTime::timersubCocos2d(&ref->attackStartTime,&nowTime) / 1000;
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
NS_CC_END