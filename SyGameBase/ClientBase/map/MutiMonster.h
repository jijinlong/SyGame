#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "HexagonGrids.h"
#include "MutiObject.h"
#include "quickidmanager.h"
NS_CC_BEGIN
class MutiMap;
class MutiMonster;
class ActionPool{
public:
	static std::map<std::string,unsigned int> actionsMap;
	typedef std::map<std::string,unsigned int>::iterator ACTIONSMAP_ITER;
	unsigned int actions; // 并行IDs
	std::list<unsigned int> actionStack;
	typedef std::list<unsigned int>::iterator ACTIONS_ITER;
	void addAction(const std::string &name);
	void addAction(const unsigned int &actionId);
	enum ACTION_TYPE{
		CONBINE_ACTION = 0, // 同时行为
		SINGLE_ACTION = 1, // 独立行为
		ALWAYS_ACTION = 2, // 永久行为 不离开
		REPLACE_ACTION = 3, // 替换执行
	};
	ACTION_TYPE actionType; // 行为类型
	/**
	 * 获取动作
	 */
	unsigned int getAction();
	/**
	 * 释放工作
	 */
	void popAction();

	static unsigned int getActionIdByName(const std::string&name); 

	ActionPool()
	{
		actions = 0;
		actionType = SINGLE_ACTION;
	}
};
/**
 * 当前点是否能够执行
 */
class MoveCheckLogic{
public:
	std::vector<GridIndex> offsets; // 检查的偏移列表
	bool isCollide; // 判断是否碰撞
	std::string actionName; // 行为名字
	GridIndex destination; // 目的地
	int blockType;
	MoveCheckLogic()
	{
		blockType = 1;
		isCollide = false;
	}
	/**
	 * 执行当前行为
	 * \param monster 怪物
	 * \return 该条件是否执行
	 **/
	bool doLogic(MutiMonster *monster);
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * 当前点执行
 */
class MoveActionLogic{
public:
	std::vector<MoveCheckLogic> checks;
	typedef std::vector<MoveCheckLogic>::iterator CHECKS_ITER;
	MoveActionLogic()
	{
	}
	void takeNode(script::tixmlCodeNode *node);
	void doLogic(MutiMonster *monster);
};
typedef std::list<MoveActionLogic> MOVE_LOGICS;
/**
 * 预定义的路径说明
 */
class PrePathDec{
public:
	int dir; // 方向
	MOVE_LOGICS indexs; // 引索列表
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * 各个方向的路径
 **/
class PrePathDecDirs{
public:
	std::string name; // 名字
	std::vector<PrePathDec> paths;
	void takeNode(script::tixmlCodeNode *node);

	MOVE_LOGICS* getLogic(int dir)
	{
		if (dir < paths.size())
		{
			return &paths.at(dir).indexs;
		}
		return NULL;
	}
};
class MutiMonsterQuickSerach:public QuickIdManager{
public:
	static MutiMonsterQuickSerach &getMe()
	{
		static MutiMonsterQuickSerach me;
		return me;
	}
};
/**
 * 实现怪物在地图上的各种动作
 */
class MutiMonster:public MutiObject,public script::tixmlCode,public QuickObjectBase{
public:
	int uniqueSerachId;
	 /**
	 * 设置快速唯一索引
	 * \param uniqueQuickId 设置快速唯一索引
	 */
	virtual void setUniqueQuickId(int uniqueQuickId)
	{
		this->uniqueSerachId = uniqueQuickId;
	}
	/**
	 * 获取快速唯一索引
	 * \return 快速唯一索引
	 */
	virtual int getUniqueQuickId()
	{
		return uniqueSerachId;
	}
	static MutiMonster * create();
	int dir;
	CCPoint offset; // 相对偏移
	CCSize size; // 我的有效面积
	MutiMap *map;
	MutiMonster()
	{
		uniqueSerachId = 0;
		dir = 0;
		map = NULL;
		objectType = MutiObject::MOSTER_TYPE;
	}
	/**
	 * 尝试从动作列表中获取一个动作 并行为
	 * 若无动作则执行延时
	 * 从配置文件中获取动作优先级列表 并初始化
	 * <actions count="10">
	 *	<action name=""  priority=""/>
	 * </actions>
	 */
	void start(const std::string &actionFile);
	/**
	 * 执行某个动作 获取当前动作的优先级 然后放入到列表中 默认为0
	 */
	void tryAction(const std::string& name);
	/**
	 * 下一个动作前夕 根据动作做出行为
	 */
	void nextStep();
	void doAIControl();
	void doMoveControl();
	/**
	 * 检查是否需要停止
	 */
	bool checkNeedStop(const GridIndex &index);
	/**
	 * 执行行为
	 */
	void doAction();
	/**
	 * 从配置文件中获取信息
	 **/
	void takeNode(script::tixmlCodeNode *node);
	void initNode(script::tixmlCodeNode *node);
	std::vector<ActionPool> actionPools;
	typedef std::vector<ActionPool>::iterator ACTIONPOOLS_ITER;
	std::map<std::string,int> priorityMap; // 优先级列表 从配置中加载
	typedef std::map<std::string,int>::iterator PRIORITYMAP_ITER;

	CartoonInfo * makeMyCartoon(const unsigned int&,int dir);
	void putMyCartoon(CartoonInfo *info);
	typedef std::vector<CartoonConbineAction> COBINE_ACTIONS;
	/*static*/ std::map<unsigned int,COBINE_ACTIONS > conbineactionmaps; // 行为表
	typedef std::map<unsigned int,COBINE_ACTIONS >::iterator CONBINEACTIONMAPS_ITER;
	unsigned int nowActionName;

	/*static*/ std::map<std::string,PrePathDecDirs> prePaths; // 各种预定义的路径
	typedef std::map<std::string,PrePathDecDirs>::iterator PRE_PATHS_ITER;

	bool checkIn(const CCPoint &point);
	
	std::vector<GridIndex> myindexs; // 自己的格子列表 从配置中加载
	
	GridIndex getStartMyIndex(); // 获取自己的起始格子

	bool checkNotDirCollide(const GridIndex &nextIndex,std::vector<GridIndex> &dirindexs,int index=1);
	/**
	 * 获取将要下降的点的引索
	 */
	GridIndex getPreDownIndex();
	/**
	 * 根据点获取地图上实际像素位置
	 */
	CCPoint getLocationByIndex(const GridIndex &index);
	/**
	 * 获取当前的引索
	 */
	GridIndex getNowIndex();

	/**
	 * 检查当前行为中是否包含自己
	 */
	bool isNowAction(const std::string &name);
	/**
	 * 使用Star 寻路到目的地
	 */
	void tryMoveUseAstr(const GridIndex &index);
	/**
	 * 清除Astar 寻路
 	 */
	void clearAstar();
	void setPosition(const GridIndex &point);
	/**
	 * 获取以point 为起始的路径列表 包含当前路径
	 */
	void getPreparePath(const std::string &name,const GridIndex &point);

	void setPosition(const CCPoint &point);

	void freshBlock();

	void setMyBlocks(const GridIndex &point);
	void clearMyBlocks(const GridIndex &point);

	void doControl(const std::string &name);
public:
	/**
	 * 判断当前是否移动
	 */
	bool isMoving();
	bool isControl(){return logics.size();}
	
	/**
	 * 当前目的地 使用于Astar
	 */
	GridIndex nowAstarDestination;
	/**
	 * 将移动的路径
	 */
	std::list<GridIndex> movePath;

	MOVE_LOGICS logics;
	/**
	 * 当前目标集合
	 */
	std::list<MutiMonster*> targets;
	
	/**
	 * 获取当前的目标
	 */
	MutiMonster * getNowTarget();
	GridIndex nowLocationIndex; // 现在的点
	GridIndex maybeLocationIndex; // 将来的点
	/**
	 * 当前在目的点时 放置位置 且设定空闲动作 使用Astar 算法 若Astar算法失败 使用向最近有效点移动的策略 若需要掉头 
	 * 则先掉头 等待下一步策略
	 */
	void moveToUseAstar(const GridIndex &point);
	/**
	 * 尝试掉头
	 */
	void setDir(int dir);
	
	/**
	 * 尝试实现马里奥的版本 使用六边形网格系统 几种路径预先定义
	 * 按照既定的逻辑路线行走 若在上升阶段碰撞 则下落(碰撞静止) 若在下降阶段碰撞 则静止
	 */
	void jumpTo();

	void moveLeft();
public:
	MoveActionLogic idleLogic;
};

NS_CC_END