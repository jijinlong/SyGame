#include "BollActor.h"

NS_CC_BEGIN
/**
 * 检查是否在行为概率内 失误行为计算 
 */
bool BollActor::checkInPercent(int value)
{
	return true;
}
/**
 * 计算距离
 */
int BollActor::calcDistance(BollActor *actor)
{
	return 0;
}

/**
 * 策略中下一步
 */
void BollActor::nextStep()
{
	/**
	 * 结合全局 决策出行为
	 */
	theBollManager.actor(this);
	CartoonInfo *info = theBollManager.getCartoonByActionName("yunqiu",0);
	this->runAction(this->getParent(),info,ccp(0,0),NULL);
}
CartoonInfo* BollActor::v_makeCartoon(int actionType)
{
	return theBollManager.getCartoonByActionType(actionType);
}
void BollActor::v_putCartoon(CartoonInfo *action)
{
	this->runAction(this->getParent(),action,ccp(0,0),NULL);
}
/**
* 执行
*/
void ActorAction::actor(BollActor *actor)
{
	// 根据命令 进行动作
	switch(actionType)
	{
		case WALK:
		{
			CartoonInfo *info = theBollManager.getCartoonByActionName(this->cartoonName.c_str(),0);
			CCPoint dest = this->getRandomPoint();
			actor->runMoveAction(actor->getParent(),*info,0.5f,dest);
			actor->setPosition(location);
		}break;
		case IDLE:
		{
			CartoonInfo *info = theBollManager.getCartoonByActionName(this->cartoonName.c_str(),0);
			actor->runAction(actor->getParent(),info,ccp(0,0),NULL);
			actor->setPosition( this->getRandomPoint());
		}break;
	}
}

CCPoint ActorAction::getRandomPoint()
{
	if (destinations.empty()) return ccp(0,0);
	return destinations.at(CCRANDOM_0_1() * (destinations.size() - 1));
}
void ActorAction::takeNode(script::tixmlCodeNode *node)
{
		std::string actionStrType = node->getAttr("actiontype");
		if (actionStrType == "walk")
		{
			actionType = WALK;
		}
		if (actionStrType == "idle")
		{
			actionType = IDLE;
		}
		location.x  = node->getInt("x");
		location.y = node->getInt("y");
		cartoonName = node->getAttr("cartoonname");
		script::tixmlCodeNode destNode = node->getFirstChildNode("destination");
		while (destNode.isValid())
		{
			CCPoint point = ccp(destNode.getInt("x"),destNode.getInt("y"));
			destinations.push_back(point);
			destNode = destNode.getNextNode("destination");
		}
		node->getAttr("playerid",id);
}
/**
 * 当前步骤是否过时
 */
bool BollStep::checkTimeOut()
{
	cc_timeval nowTime; // 上次执行时间
	CCTime::gettimeofdayCocos2d(&nowTime,NULL);
	if (CCTime::timersubCocos2d(&lastActionTime,&nowTime) / 1000 >= lastTime)
	{
		lastActionTime = nowTime;
		return true;
	}
	return false;
}

void BollStep::takeNode(script::tixmlCodeNode *node)
{
	node->getAttr("lasttime",lastTime);
	node->getAttr("tickcount",tickCount);
	script::tixmlCodeNode actionNode = node->getFirstChildNode("action");
	while(actionNode.isValid())
	{
		ActorAction action;
		action.takeNode(&actionNode);
		actorActions.push_back(action);
		actionNode = actionNode.getNextNode("action");
	}
}
 BollActor *BollActor::create()
 {
	BollActor *pRet = new BollActor();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
 }
 bool BollActor::init()
 {
	 CCSprite::init();
	 this->attachSprite(this);
	 return true;
 }
/**
 <step lasttime=""> <!--人物属性在这里反应-->
	<player id="" action="walk" destination="" cartoon=""/>
	<player id="" action="idle" cartoon=""/>
 </step>
 */
void BollStep::start(BollActorManager *bam)
{
	CCTime::gettimeofdayCocos2d(&lastActionTime,NULL);
	// 控制10个点的行为
	for (ACTORACTIONS_ITER iter = actorActions.begin(); iter != actorActions.end();++iter)
	{
		iter->actor(bam->getActorById(iter->id));
	}
}
void BollActorManager::actor(BollActor * actor)
{
	if (!actor) return;
	/**
	 * 决策算法 硬码
	 */
	// 判断球员位置信息
	// 检查是否防御 或盯人
		// 检查球所在方
	// 球在我这 检查防御 距离 投篮 传球 or 带球  

	// 盯人行为描述 walk to person or try defend action


	// 检查 球是否在我方
	if (checkBollInMineTeam(actor))
	{
		// 占位 接球 逃脱 头球 或过人
	}
	else
	{
		// 查看空防 接近 or 抢球  断球
	}
}
bool BollActorManager::checkBollInMineTeam(BollActor *actor)
{
	return true;
}

/**
 * 通过actionType获取动画信息
 */
CartoonInfo *BollActorManager::getCartoonByActionType(int actionType)
{
	return NULL;
}
void BollActorManager::init()
{
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("bollactors.xml");
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return;
		if (script::tixmlCode::initFromString((char*)buffer))
		{
			return ;
		}
		return;
}
/**
* 固定动画播放
*/
void BollActorManager::tick()
{
	if (nowStep && nowStep->checkTimeOut())
	{
		nowStep = NULL;
	}
	if (!nowStep && steps.size())
	{
		nowStep = steps.front();
		nowStep->start(this);
		steps.pop_front();
	}
	for (std::list<BollStep*>::iterator iter =  tickSteps.begin(); iter != tickSteps.end();++iter)
	{
		BollStep *step = *iter;
		if (step->checkTimeOut() && (step->tickCount == -1 || step->tickCount  -- > 0))
		{
			step->start(this);
		}
	}
}
BollActor * BollActorManager::getActorById(int id)
{
	if (id < actors.size())
	{
		return actors.at(id);
	}
	return NULL;
}
CartoonInfo *BollActorManager::getCartoonByActionName(const std::string& actionName,int dir)
{
	CONBINEACTIONMAPS_ITER iter = conbineactionmaps.find(actionName);
	if (iter != conbineactionmaps.end())
	{
		COBINE_ACTIONS& actions = iter->second;
		CartoonInfo *root = NULL;
		CartoonInfo * temp = NULL;
		for (COBINE_ACTIONS::iterator pos = actions.begin(); pos != actions.end();++pos)
		{
			if (temp)
			{
				temp->nextCartoon = pos->getCartoonInfo(dir);
				temp = temp->nextCartoon;
				temp->nextConbineType = pos->nextType;
			}
			else if (!root)
			{
				root = pos->getCartoonInfo(dir);
				temp = root;
				temp->nextConbineType = pos->nextType;
				continue;
			}
			else
			{
				break;
			}
		}
		return root;
	}
	return NULL;
}
/**
* 从配置文件中加载配置
* \param node 配置根节点
*/
void BollActorManager::takeNode(script::tixmlCodeNode *node)
{
	script::tixmlCodeNode conbinesNode = node->getFirstChildNode("cobineactions");
	if (conbinesNode.isValid())
	{
		script::tixmlCodeNode actionsNode = conbinesNode.getFirstChildNode("actions");
		while(actionsNode.isValid())
		{
			std::string actionsName = actionsNode.getAttr("name");
			script::tixmlCodeNode actionNode = actionsNode.getFirstChildNode("action");
			COBINE_ACTIONS actions_vec;
			while(actionNode.isValid())
			{
				CartoonConbineAction rpgAction;
				rpgAction.takeNode(&actionNode);
				actions_vec.push_back(rpgAction);
				actionNode = actionNode.getNextNode("action");
			}
			conbineactionmaps[actionsName] = actions_vec;
			actionsNode = actionsNode.getNextNode("actions");
		}
	}
	script::tixmlCodeNode stepsNode = node->getFirstChildNode("steps");
	while (stepsNode.isValid())
	{
		std::string name = stepsNode.getAttr("name");
		std::list<BollStep*> steps;
		script::tixmlCodeNode stepNode = stepsNode.getFirstChildNode("step");
		while (stepNode.isValid())
		{
			BollStep *step = new BollStep;
			step->takeNode(&stepNode);
			steps.push_back(step);
			stepNode = stepNode.getNextNode("step");
		}
		namesteps[name] = steps;
		stepsNode = stepsNode.getNextNode("steps");
	}
	script::tixmlCodeNode ticksNode = node->getFirstChildNode("ticks");
	if (ticksNode.isValid())
	{
		script::tixmlCodeNode stepNode = ticksNode.getFirstChildNode("step");
		while (stepNode.isValid())
		{
			BollStep *step = new BollStep;
			step->takeNode(&stepNode);
			tickSteps.push_back(step);
			stepNode = stepNode.getNextNode("step");
		}
	}
	script::tixmlCodeNode actorNode = node->getFirstChildNode("actor");
	while (actorNode.isValid())
	{
		BollActor *actor = BollActor::create();
		if (nowScene) nowScene->addChild(actor);
		actors.push_back(actor);
		actorNode = actorNode.getNextNode("actor");
	}
}
void BollActorManager::start(const std::string& name)
{
	NAMESTEPS_ITER iter = namesteps.find(name);
	if (iter != namesteps.end())
	{
		steps = iter->second;
	}
}
/**
* 清场
*/
void BollActorManager::clear()
{
	for (std::list<BollStep*>::iterator iter = steps.begin() ; iter != steps.end();++iter)
	{
		BollStep *step = *iter;
		if (step)
		{
			delete step;
		}
	}
	steps.clear();
}
NS_CC_END