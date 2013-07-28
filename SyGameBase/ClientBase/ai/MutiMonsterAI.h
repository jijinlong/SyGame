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
		HAD_TARGET_LEAVE = 8, // 有对象离开
		MOVE_TO_DESTIONATION = 9,// 移动到目的地
		ATTACK_TRIED = 10, // 连续攻击时间过长
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
	int uniqueId;
	cc_timeval attackStartTime; // 攻击持续时间
	int weight;
	bool isValid(){return true;} // 当前引用是否有效
	MutiMonsterRefrence()
	{
		CCTime::gettimeofdayCocos2d(&attackStartTime,NULL);
		monster = NULL;
		uniqueId  = -1;
		weight = 0;
	}
	bool checkTimeOut(int timeout);

	MutiMonsterRefrence & operator=(const MutiMonsterRefrence &ref)
	{
		monster = ref.monster;
		uniqueId = ref.uniqueId;
		attackStartTime = ref.attackStartTime;
		weight = ref.weight;
		return *this;
	}
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
	void removeTarget();
	int getTargetCount(); // 当前对象的数量
	MutiMonster * getTarget(); // 获取当前对象
	MutiMonsterRefrence * getTargetRef(); // 获取当前对象池
	void addTarget(MutiMonster *monster); // 增加对象
	void pickSuitTarget(); // 挑选合适的对象
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
	int movetotarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 设定距离最短的为当前攻击对象 重新设定lock对象
	 * <lockmindistacetarget/>
	 */
	int lockmindistacetarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 将权值最大者锁定 重新设定
	 * <locksuittarget/>
	 **/
	int locksuittarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 行走到目的地
	 * <move targetx="" targety=""/>
	 */
	int move(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 沿着目标绕圈
	 * <moverandarround/>
	 */
	int moverandarround(MutiAIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * 清除当前移动路径
	 */
	int clearmovepath(MutiAIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * 设置当前攻击时间
	 */
	int resetattacktime(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 检查攻击的持续时间
	 */
	int checkattacklasttime(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 检查当前的位置
	 */
	int checknowposition(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 更改事件响应函数
	 **/
	
	/**
	 * 检查当前的目标
	 */
	int checknowtarget(MutiAIStub* stub,script::tixmlCodeNode * node);
};

#define theAILib MonsterAILib::getMe()

NS_CC_END
