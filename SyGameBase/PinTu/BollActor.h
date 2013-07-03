#pragma once
#include "Cartoon.h"

NS_CC_BEGIN
/**
 * 球员的属性
 */
struct stBollActorData{
	/**
	内线：篮板、力量
	投篮：三分、中投
	防守：干扰、盖帽
	素质：速度、体能
	 */
	float lanban;
	float power;
	float sanfen;
	float zhongtou;
	float ganrao;
	float gaimao;
	float speed;
	float tineng;
};
/**
 * 球员 继承与Cartoon 可以进行多种行为
 */
class BollActor:public Cartoon{
public:
	enum{
		ACTION_IDLE, // 空闲
		ACTION_MOVE, // 移动
		ACTION_TOULAN, // 投篮
		ACTION_FANGSHOU, // 防守
		ACTION_KOULAN, // 扣篮动作
		ACTION_TALK, // 说话
	};
	stBollActorData data;
	BollActor()
	{
		
	}
	bool init();
	static BollActor *create();
	/**
	 * 检查是否在行为概率内 失误行为计算 
	 */
	bool checkInPercent(int value);
	/**
	 * 计算距离
	 */
	int calcDistance(BollActor *actor);

	/**
	 * 策略中下一步
	 */
	virtual void nextStep();
	virtual CartoonInfo* v_makeCartoon(int actionType);
	virtual void v_putCartoon(CartoonInfo *action);
	/**
	 * 获取防御点
	 */
	CCPoint getDefendPoint(BollActor *defender);

	/**
	 * 获取下一个可移动点
	 */
	CCPoint getCanWalkPoint();
};
class ActorAction{
public:
	int id;
	int actionType;
	std::vector<CCPoint> destinations;
	std::string cartoonName;
	CCPoint location;
	enum{
		WALK,
		IDLE,
	};
	/**
	 * 执行
	 */
	void actor(BollActor *actor);
	
	CCPoint getRandomPoint();

	void takeNode(script::tixmlCodeNode *node);

	ActorAction &operator = (const 	ActorAction actor)
	{
		id = actor.id;
		actionType = actor.actionType;
		destinations = actor.destinations;
		cartoonName = actor.cartoonName;
		return *this;
	}
};
class BollActorManager;
/**
 * 球场动画 简单固定式设定
 * 定义每个点每个人员的位置 动作
 */
class BollStep{
public:
	std::string stepName;
	int lastTime; // 持续时间
	int actionsStepType; // 当前行为类型
	cc_timeval lastActionTime; // 上次执行时间
	int tickCount; // 定时次数
	enum{
		ACTIONS_STEP_FROM_XML = 0, // 行为来自配置 时间轴机制
		ACTIONS_STEP_AI = 1,
	};
	BollStep()
	{
		CCTime::gettimeofdayCocos2d(&lastActionTime,NULL);
		tickCount = -1;
	}
	bool checkTimeOut();
	void start(BollActorManager *bam);
	void takeNode(script::tixmlCodeNode *node);
	std::list<ActorAction> actorActions;
	typedef std::list<ActorAction>::iterator ACTORACTIONS_ITER;
};
/**
 * 管理和指挥球员
 */
class BollActorManager:public script::tixmlCode{
public:
	static BollActorManager&getMe()
	{
		static BollActorManager bam;
		return bam;
	}
	BollActorManager()
	{
		nowBollActor = NULL;
		nowScene = NULL;
	}
	void init();
	/**
	 * 球员听从命令 进行动作
	 * 1. 回防占位
	 * 2. 贴近防守
	 * 3. 概率断球
	 * 4. 传球 硬闯
	 * 5. 球员互斥
	 * 6. 犯规
	 * 7. 开场抢球
	 */
	void actor(BollActor * actor);
	/**
	 * 清场
	 */
	void clear();
	
	/**
	 * 通过actionType获取动画信息
	 */
	CartoonInfo *getCartoonByActionType(int actionType);
	CartoonInfo *getCartoonByActionName(const std::string& actionName,int dir);
	bool checkBollInMineTeam(BollActor *actor);
	/**
	 * 固定动画播放
	 */
	void tick();

	BollActor * getActorById(int id);

	CCNode *nowScene; // 当前场景

	void start(const std::string& name);
private:
	std::list<BollStep*> steps;

	std::list<BollStep*> tickSteps; // 每时每刻 都有步骤
	BollStep *nowStep; // 当前的步骤
	BollActor *nowBollActor; // 当前球表演者
	std::vector<BollActor*> actors;
	typedef std::vector<BollActor*>::iterator BOLLACTORS_ITER;

	std::map<std::string,std::list<BollStep*> > namesteps;
	typedef std::map<std::string,std::list<BollStep*> >::iterator NAMESTEPS_ITER;
	/**
	 * 系统中的组合拳动作
	 */
	typedef std::vector<CartoonConbineAction> COBINE_ACTIONS;
	std::map<std::string,COBINE_ACTIONS > conbineactionmaps;
	typedef std::map<std::string,COBINE_ACTIONS>::iterator CONBINEACTIONMAPS_ITER; 
	/**
	 * 从配置文件中加载配置
	 * \param node 配置根节点
	 */
	void takeNode(script::tixmlCodeNode *node);
};

#define theBollManager BollActorManager::getMe()
NS_CC_END