#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "Cartoon.h"
#include "MutiMap.h"
NS_CC_BEGIN

class ActionPool{
public:
	std::list<std::string> actions;
};
/**
 * 实现怪物在地图上的各种动作
 */
class MutiMonster:public Cartoon,public script::tixmlCode{
public:
	static MutiMonster * create();
	int dir;
	MutiMap *map;
	MutiMonster()
	{
		dir = -1;
		map = NULL;
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
	/**
	 * 执行行为
	 */
	void doAction();
	/**
	 * 从配置文件中获取信息
	 **/
	void takeNode(script::tixmlCodeNode *node);
	std::vector<ActionPool> actionPools;
	typedef std::vector<ActionPool>::iterator ACTIONPOOLS_ITER;
	std::map<std::string,int> priorityMap; // 优先级列表
	typedef std::map<std::string,int>::iterator PRIORITYMAP_ITER;

	CartoonInfo * makeMyCartoon(const std::string &name,int dir);
	void putMyCartoon(CartoonInfo *info);
	typedef std::vector<CartoonConbineAction> COBINE_ACTIONS;
	static std::map<std::string,COBINE_ACTIONS > conbineactionmaps;
	typedef std::map<std::string,COBINE_ACTIONS >::iterator CONBINEACTIONMAPS_ITER;
	std::string nowActionName;
public:
	/**
	 * 移动到某点
	 */
	GridIndex destionation;
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
	void jumpTo(const GridIndex &point);
public:

};

NS_CC_END