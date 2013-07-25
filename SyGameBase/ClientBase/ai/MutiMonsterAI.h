#pragma once 

/**
 * 怪物AI
 */

#include "scriptLib.h"
#include "cocos2d.h"
NS_CC_BEGIN
class MutiMonster;
class MutiAIStub;
class MonsterAILib;
class MutiAI{
public:
	MutiAI()
	{
		id = 0;
	}
	DWORD id;
	/**
 	 * 执行一个事件
 	 * */
	bool action(MutiAIStub * stub,int event);
	enum{
		DEATH = 0, // 死亡
		BIRTH = 1, // 出生
		TARGET_ENTER = 2, // 物体进入视野
		TARGET_LEAVE = 3, // 物体离开视野
		ATTACK_ME = 4, // 被人攻击
		IDLE_ACTION = 5, // 空闲时间段
		MEET_TARGET = 6, // 对象在攻击范围内 
		HAD_TARGET = 7, // 有目标的状态
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
typedef int (MonsterAILib::*AIAction)(MutiAIStub *,script::tixmlCodeNode *);

//执行点
class AILibAction{
public:
	int type;
	AIAction action;
};
class MutiMonsterRefrence
{
public:
	MutiMonster * monster;
	DWORD uniqueId;

	bool isValid(){return true;} // 当前引用是否有效
};
/**
 * ai 的执行者
 * */
class MutiAIStub{
public:
	MutiMonster *npc;
	std::vector<MutiMonsterRefrence> targetPool; // 对象池 0 号对象为默认处理池
	typedef std::vector<MutiMonsterRefrence>::iterator TARGETPOOL_ITER;
	MutiAIStub()
	{
		npc = NULL;
	}
	MutiAIStub(MutiMonster *npc)
	{
		this->npc = npc;
	}
};
/**
 * 执行库
 * 加载代码库 和 事件池
 **/
class MonsterAILib:public script::Lib<AILibAction,MutiAIStub,MonsterAILib>
{
public:
	static MonsterAILib & getMe()
	{
		static MonsterAILib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * 只有在scope="stub" 的时候 type 才有效
     */
    int var(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::var(stub,node);
    }
    /**
     * 输出
     */
    int print(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::print(stub,node);
    }
    /**
     * 计算变量
     **/
    int calc(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::calc(stub,node);
    }
    /**
     * 执行其他节点
     **/
    int exec(MutiAIStub* stub,script::tixmlCodeNode * node)
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
    void execEvent(DWORD npcAIID,MutiAIStub *stub,int event);
    std::vector<MutiAI*> npcAis;
/////////////////////////////////////////////////////////////////////////    
//			相关扩展
////////////////////////////////////////////////////////////////////////
    /**
     * 触发技能
     * */    
    int putskill(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 行走到 目标
	 * <movetotarget/>
	 **/
	
	/**
	 * 设定距离最短的为当前攻击对象 重新设定lock对象
	 * <lockmindistacetarget/>
	 */
	
	/**
	 * 将权值最大者锁定 重新设定
	 * <locksuittarget/>
	 **/

	/**
	 * 行走到目的地
	 * <move targetx="" targety=""/>
	 */
	
	/**
	 * 沿着目标绕圈
	 * <moverandarround/>
	 */
};

#define theAILib MonsterAILib::getMe()

NS_CC_END
