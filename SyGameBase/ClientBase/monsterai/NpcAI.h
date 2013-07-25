#pragma once
#include "scriptLib.h"
#include "sys.h"
#include "Engine/Singleton.h"
#include "Engine/MemAllocManager.h"
class Npc;
class MapObject;
class NpcAILib;
class NpcAIStub;
class NpcAI{
public:
	MEMALLOC_FROM_POOL
	NpcAI()
	{
		id = 0;
	}
	DWORD id;
	/**
 	 * 执行一个事件
 	 * */
	bool action(NpcAIStub * stub,int event);
	enum{
		DEATH = 0, // 死亡
		BIRTH = 1, // 出生
		OBJECT_IN = 2, // 物品进入视野
		TIMER = 3, // 定时器
		ATTACK_ME = 4, // 被人攻击
		OBJECT_LEAVE = 5, // 物品离开视野
	};
	/**
 	 * 增加一个code
 	 * \param code 代码节点
 	 * \param name 代码名称
 	 * \return ture 成功 false 失败
 	 * */
	bool addCode(script::tixmlCodeNode* code,std::string name);
private:
	std::vector<script::tixmlCodeNode*> events;	
};
typedef int (NpcAILib::*AIAction)(NpcAIStub *,script::tixmlCodeNode *);

//执行点
class AILibAction{
public:
	int type;
	AIAction action;
};
/**
 * ai 的执行者
 * */
class NpcAIStub{
public:
	Npc *npc;
	MapObject *object;
	NpcAIStub()
	{
		npc = NULL;
		object = NULL;
	}
	NpcAIStub(Npc *npc,MapObject *object)
	{
		this->npc = npc;
		this->object = object;
	}
};
/**
 * 执行库
 * 加载代码库 和 事件池
 **/
class NpcAILib:public script::Lib<AILibAction,NpcAIStub,NpcAILib>,public Singleton<NpcAILib>{
public:
    MEMALLOC_FROM_POOL
    /**
     * 只有在scope="stub" 的时候 type 才有效
     */
    int var(NpcAIStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<AILibAction,NpcAIStub,NpcAILib>::var(stub,node);
    }
    /**
     * 输出
     */
    int print(NpcAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,NpcAIStub,NpcAILib>::print(stub,node);
    }
    /**
     * 计算变量
     **/
    int calc(NpcAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,NpcAIStub,NpcAILib>::calc(stub,node);
    }
    /**
     * 执行其他节点
     **/
    int exec(NpcAIStub* stub,script::tixmlCodeNode * node)
    {
        execCode(stub,node->getAttr("name"));
        return 0;
    }
    void bindActions();
    void takeNode(script::tixmlCodeNode *node);
    /**
     * 清除资源
     * */
    void destroy();
    /**
     * 执行事件
     * \param npcAIID ai 号
     * \param npc 怪物
     * \param event 事件
     * */
    void execEvent(DWORD npcAIID,NpcAIStub *stub,int event);
    std::vector<NpcAI*> npcAis;
/////////////////////////////////////////////////////////////////////////    
//			相关扩展
////////////////////////////////////////////////////////////////////////
    /**
     * 触发技能
     * */    
    int putskill(NpcAIStub* stub,script::tixmlCodeNode * node);

    /**
     * 搜寻玩家
     * */
    int searchuser(NpcAIStub* stub,script::tixmlCodeNode * node);
    /**
     * 移动到 
     **/
    int moveto(NpcAIStub* stub,script::tixmlCodeNode * node);
    /**
     * 设置权值
     **/
    int setweight(NpcAIStub* stub,script::tixmlCodeNode * node);
    /**
     * 检查timerpass value 毫秒数
     **/
    int timerpass(NpcAIStub* stub,script::tixmlCodeNode * node);
    /**
     * 重置timer时间
     **/
    int resettimer(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 时间定时行为
     * */
    int timer(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 攻击
     **/
    int attack(NpcAIStub *stub,script::tixmlCodeNode *node);
    /**
     * 增加定时器
     * */
    int addtimer(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 删除定时器
     * */
    int deltimer(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 检查当前最近的物品
     **/
    int choicenearest(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 检查与当前对象的距离
     * */
    int checkdistance(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 检查当前槽是有对对象
     * */
    int checkexist(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 设置当前对象到n号处理槽
     * */
    int settarget(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 概率条件
     * */
    int percent(NpcAIStub *stub,script::tixmlCodeNode * node);
    /**
     * 检查定时的超时时间
     * */
    int timerexsit(NpcAIStub *stub,script::tixmlCodeNode * node); 
    /**
     * 检查周围是否有玩家
     * */
    int checkninehaduser(NpcAIStub *stub,script::tixmlCodeNode * node);
};

#define theNpcAILib NpcAILib::getMe()
