#pragma once
#include "sys.h"
#include "aiagent.h"
#include "aienv.h"
#include <map>
#include "agentmanager.h"
#include "LocalBlockMap.h"
#include "Engine/MemAllocManager.h"
#include "MapObject.h"
#include "Astar.h"
#include "quickidmanager.h"
#include "AbilityLogic.h"
class Map;
struct stNpcTarget{
	DWORD objectID; // 物品id
	DWORD weight; // 权重
	BYTE objectType; // 物品类型
	DWORD eventType; // 对象的触发类型
	DWORD lastTime;
	sys::stTimeValue createTime;
	stNpcTarget()
	{
		lastTime = 0;
		objectID = 0;
		weight = 0;
		objectType = 0;
		eventType = 0;
	}
};

struct stNpcTimeTick{
	sys::stTimeValue startTime;
	DWORD timerid;
	sys::stTimeValue createTime;
	stNpcTimeTick()
	{
		timerid = (DWORD) -1;
	}
};
struct NpcDoOneTarget{
	sys::stTimeValue createTime;
	DWORD objectId;
	DWORD weight;
};
class Npc:public MapObject,public zAStar<>,public Entity{
public:
	Npc():MapObject(TYPE_GAME_NPC),npcAbility(this)
	{
		npcid = 0;
		hp = 0;
		npcAIID = 0;
		extLibId = 0;
	}
	MEMALLOC_FROM_POOL
public:
	DWORD npcid; // 当前被标识的id
	DWORD npcAIID; // npc 的只能模块
	DWORD baseInfoId; // 基础id,游戏数值定义
	sys::stTimeValue passStartTime;
	/**
 	 * 加载配置
 	 * */
	bool initWithNode(script::tixmlCodeNode *node);
	/**
 	 * 执行ai 行为
 	 * */
	void execAIEvent(int event);
	void execAIEvent(MapObject *object,int event);
	/**
 	 * 攻击列表
 	 **/
	std::vector<stNpcTarget> targetList;
   	/**
 	 * 增加目标
 	 * \param objectID 物品id
 	 * \param objectType 物品类型
 	 * \param eventType 事件下触发
 	 * \param weight 权值
 	 * */	
	void addTarget(DWORD objectID,DWORD objectType,DWORD eventType,DWORD weight,DWORD lastTime,int id = -1);
	std::vector<stNpcTimeTick> ticks;
	bool checkTimePassed(DWORD timeid,DWORD lasttime);
	bool checkTimeOut(DWORD timerid,DWORD lasttime);
	void addTimer(DWORD timeid,DWORD lasttime);
	void delTimer(DWORD timeid,DWORD lasttime);
	/**
 	 * 一个微型行为机制
 	 * */
	void doTick();
protected:
	virtual bool doTalk(const NIO & nio) 
	{
		printf("doTalk;\n");
		return false;
	}
	virtual bool doSleep(const NIO& nio) 
	{
		//printf("%u doSleep;%u\n",getObjectId(),nio.lastTime);
		return false;
	}
	virtual bool doAttack(const NIO& nio); 
	virtual bool doFlee(const NIO& nio) 
	{
		sys::AynaTime time;
		return false;
	}
	virtual bool doWalk(const NIO &nio);
	virtual AICondition takeCondition(AIObject *object) 
	{
		// 该部分可以在npcbase 里配置
		if (object == (AIObject*)this) 
			return AICondition::FRIEND; // 自身是朋友
		return AICondition::EMERY; // 眼里都是敌人
	}
public: // 寻路系统相关
	bool moveable(const zPos &tempPos,const zPos &destPos,const int radius1);
	bool moveTo(zPos &dest);
	bool gotoFindPath(const zPos &srcPos, const zPos &destPos);
public:
	NIO now_nio;
	DWORD extLibId;
	void doNIO(NIO &nio);
	void anaysicsNIO(NIO &nio);
	NpcDoOneTarget objectInfo;	
public: // 场景同步相关
	/**
 	 * 场景加入节点回调
 	 * \param 通知 entry 我的增加
 	 * */
	virtual void tellAdd(localmap::Entry *entry);
	/**
 	 * 场景通知删除回调
 	 * \param 通知entry 我的删除 
 	 * */
	virtual void tellDel(localmap::Entry *entry);	
	bool intoMap(Map *map);	

	AbilityNpc npcAbility;	
	
	
public:
	void updateHpToClients(int);
	void sendCmdToNine(const void *msg, const UINT32 msgLen);
	Map * getMap();
	UINT64 hp; // 血量
};
