#include "MutiMonster.h"
#include "MutiMap.h"
NS_CC_BEGIN
std::map<unsigned int,MutiMonster::COBINE_ACTIONS > MutiMonster::conbineactionmaps;
std::map<std::string,unsigned int> ActionPool::actionsMap;
std::map<std::string,PrePathDecDirs> MutiMonster::prePaths;
void ActionPool::addAction(const std::string &name)
{
	unsigned int id = getActionIdByName(name);
	if (id != 0)
	{
		addAction(id);
	}
}
void ActionPool::addAction(const unsigned int& actionId)
{
	if (actionType == ALWAYS_ACTION)
	{
		actions = actionId;
	}
	if (actionType == CONBINE_ACTION)
	{
		actions += actionId;
	}
	if (actionType == SINGLE_ACTION)
	{
		actionStack.push_back(actionId);
	}
	/**
	if (actionType == REPLACE_ACTION)
	{
		//立即执行当前动作
		actions = actionId;
		stopAllActions();
		nextStep();
	}
	**/
}
/**
 * 获取动作
 */
unsigned int ActionPool::getAction()
{
	if (actionType == CONBINE_ACTION)
	{
		return actions;
	}
	if (actionType == SINGLE_ACTION)
	{
		if (actionStack.empty()) return 0;
		return actionStack.front();
	}
	if (actionType == ALWAYS_ACTION)
	{
		return actions;
	}
	return 0;
}
unsigned int ActionPool::getActionIdByName(const std::string&name)
{
	ACTIONSMAP_ITER iter = actionsMap.find(name);
	if (iter != actionsMap.end())
	{
		return iter->second;
	}
	return 0;
}
/**
 * 释放工作
 */
void ActionPool::popAction()
{
	if (actionType == CONBINE_ACTION)
	{
		actions = 0;
	}
	if (actionType == SINGLE_ACTION)
	{
		actionStack.pop_front();
	}
}
MutiMonster * MutiMonster::create()
{
	MutiMonster *monster = new MutiMonster();
	if (monster)
	{
		monster->initWithTexture(NULL, CCRectZero);
		monster->autorelease();
		monster->attachSprite(monster);
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}
/**
 * 尝试从动作列表中获取一个动作 并行为
 * 若无动作则执行延时
 * 从配置文件中获取动作优先级列表 并初始化
 * <actions count="10">
 *	<action name=""  priority=""/>
 * </actions>
 */
void MutiMonster::start(const std::string &actionFile)
{
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(actionFile.c_str());
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	initFromString((char*)buffer);

	// 从配置文件中加载信息
	doAction();

	tryAction("idle");
	CCSprite * test = CCSprite::create("cell.png");
	this->addChild(test);
	test->setPosition(offset);
	this->setAnchorPoint(ccp(offset.x/size.width,offset.y / size.height));
}
/**
 * 执行某个动作 获取当前动作的优先级 然后放入到列表中 默认为0
 */
void MutiMonster::tryAction(const std::string& name)
{
	int step = 0;
	PRIORITYMAP_ITER iter = priorityMap.find(name);
	if (iter != priorityMap.end())
	{
		step = iter->second;
	}
	if (step >= actionPools.size())
	{
		actionPools.resize(step+1);
	}
	actionPools[step].addAction(name);
	if (actionPools[step].actionType == ActionPool::REPLACE_ACTION)
	{
		this->stopActionByTag(step);
		nextStep();
	}
}
/**
 * 下一个动作前夕 根据动作做出行为
 */
void MutiMonster::nextStep()
{
//	 TODO
	map->clearBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
	nowLocationIndex = this->maybeLocationIndex;
//	当前路径不为空 或者目的地有效
	if (isMoving())
	{
		MoveActionPoint &point = movePath.front();
		if (point.moveState == MoveActionPoint::DOWNING)
		{
			if (this->checkOnlyButtomCollide(point.index)) // 检查是否只是下部碰撞
			{
				movePath.clear();// 停止				
			}
			else
			{
				getPreparePath("down",this->getStartMyIndex());
			}
		}
		if (point.moveState == MoveActionPoint::UPING)
		{
			if (this->checkCollideInMap(point.index)) // 存在碰撞了 则下降
			{
				if (this->checkOnlyButtomCollide(getPreDownIndex())) // 无法下降
				{
					movePath.clear();// 停止	
				}
				else if (this->checkNotDownCollide(getPreDownIndex())) // 如果下部没碰撞 则下落
				{
					movePath.clear();// 重新设定路径
					getPreparePath("down",this->getPreDownIndex());
				}
			}
		}
		if (point.moveState == MoveActionPoint::LEFTING)
		{
			// 向左移动
			
		}
		if (point.moveState == MoveActionPoint::RIGHTING)
		{
			// 向右移动
		}
	}
	if (nowAstarDestination.index.isValid() && nowAstarDestination.index.equal(getNowIndex()))
	{
	//	nowAstarDestination.index.x = -1;
	}
	// 检查是否在终点
	// 不在继续走
	if (nowAstarDestination.index.isValid() && !nowAstarDestination.index.equal(getNowIndex()) && !isMoving()) // 使用Astar 继续寻路
		moveToUseAstar(nowAstarDestination.index);
	else if(!isMoving())
	{
		if (!this->checkOnlyButtomCollide(this->getStartMyIndex()))
			getPreparePath("down",this->getStartMyIndex()); // 尝试下坠
	}
	doAction();
	
}

void MoveActionPoint::takeNode(script::tixmlCodeNode *node)
{
	actionName = node->getAttr("name");
	index.x = node->getInt("x");
	index.y = node->getInt("y");
	std::string moveStateStr = node->getAttr("movestate");
	if (moveStateStr == "uping")
	{
		moveState = MoveActionPoint::UPING;
	}
	if (moveStateStr == "downing")
	{
		moveState = MoveActionPoint::DOWNING;
	}
	if (moveStateStr == "lefting")
	{
		moveState = MoveActionPoint::LEFTING;
	}
	if (moveStateStr == "righting")
	{
		moveState = MoveActionPoint::RIGHTING;
	}
}
void PrePathDec::takeNode(script::tixmlCodeNode *node)
{
	dir = node->getInt("dir");
	script::tixmlCodeNode pointNode = node->getFirstChildNode("point");
	while(pointNode.isValid())
	{
		MoveActionPoint point;
		point.takeNode(&pointNode);
		indexs.push_back(point);
		pointNode = pointNode.getNextNode("point");
	}
}
void PrePathDecDirs::takeNode(script::tixmlCodeNode *node)
{
	name = node->getAttr("name");
	script::tixmlCodeNode pathNode = node->getFirstChildNode("path");
	while(pathNode.isValid())
	{
		PrePathDec dec;
		dec.takeNode(&pathNode);
		paths.push_back(dec);
		pathNode = pathNode.getNextNode("path");
	}
}
/**
 * 从配置文件中获取信息
 **/
void MutiMonster::takeNode(script::tixmlCodeNode *node)
{
	initNode(node);
}
void MutiMonster::initNode(script::tixmlCodeNode *node)
{
	// 加载组合动作
	script::tixmlCodeNode conbinesNode = node->getFirstChildNode("conbineactions");
	if (conbinesNode.isValid() && conbineactionmaps.empty())
	{
		script::tixmlCodeNode actionsNode = conbinesNode.getFirstChildNode("actions");
		while(actionsNode.isValid())
		{
			unsigned int actionsName = actionsNode.getInt("name");
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
	script::tixmlCodeNode actionPriorityNode = node->getFirstChildNode("actionpriority");
	if (actionPriorityNode.isValid())
	{
		script::tixmlCodeNode priorityNode = actionPriorityNode.getFirstChildNode("priority");
		while (priorityNode.isValid())
		{
			std::string name = priorityNode.getAttr("name");
			int value = priorityNode.getInt("value");
			priorityMap[name] = value;
			priorityNode = priorityNode.getNextNode("priority");
		}
	}
	script::tixmlCodeNode actionPoolsNode = node->getFirstChildNode("actionpools");
	if (actionPoolsNode.isValid())
	{
		script::tixmlCodeNode poolNode = actionPoolsNode.getFirstChildNode("pool");
		while (poolNode.isValid())
		{
			int id = poolNode.getInt("id");
			std::string typeStr = poolNode.getAttr("type");
			if (id >= actionPools.size()) actionPools.resize(id + 1);
			if (typeStr == "always")
				actionPools[id].actionType = ActionPool::ALWAYS_ACTION;
			if (typeStr == "single")
				actionPools[id].actionType = ActionPool::SINGLE_ACTION;
			if (typeStr == "conbine")
				actionPools[id].actionType = ActionPool::CONBINE_ACTION;
			if (typeStr == "replace")
				actionPools[id].actionType = ActionPool::REPLACE_ACTION;
			poolNode = poolNode.getNextNode("pool");
		}

	}
	// 加载动作名字对应的ID
	script::tixmlCodeNode actionNameNode = node->getFirstChildNode("actionnames");
	if (actionNameNode.isValid())
	{
		script::tixmlCodeNode actionNode = actionNameNode.getFirstChildNode("action");
		while (actionNode.isValid())
		{
			std::string actionName = actionNode.getAttr("name");
			unsigned int id = actionNode.getInt("id");
			ActionPool::actionsMap[actionName] = id;
			actionNode = actionNode.getNextNode("action");
		}
	}
	script::tixmlCodeNode myindexsNode = node->getFirstChildNode("myindexs");
	if (myindexsNode.isValid())
	{
		script::tixmlCodeNode indexNode = myindexsNode.getFirstChildNode("index");
		while (indexNode.isValid())
		{
			GridIndex index;
			index.x = indexNode.getInt("x");
			index.y = indexNode.getInt("y");
			myindexs.push_back(index); // 自己占据的格子数
			indexNode = indexNode.getNextNode("index");
		}
	}
	script::tixmlCodeNode myRectNode = node->getFirstChildNode("rect");
	if (myRectNode.isValid())
	{
		offset.x = myRectNode.getInt("x");
		offset.y = myRectNode.getInt("y");
		size = CCSizeMake(myRectNode.getInt("w"),myRectNode.getInt("h"));
	}
	script::tixmlCodeNode prePathNode = node->getFirstChildNode("prepaths");
	while (prePathNode.isValid())
	{
		PrePathDecDirs prePath;
		prePath.takeNode(&prePathNode);
		prePaths[prePath.name] = prePath;
		prePathNode = prePathNode.getNextNode("prepaths");
	}
}
void MutiMonster::doAction()
{
	int step =0;
	for (ACTIONPOOLS_ITER iter = actionPools.begin(); iter != actionPools.end();++iter,++step)
	{
		unsigned int actionId = iter->getAction();
		if (actionId != 0)
		{
			CartoonInfo *cartoonInfo = makeMyCartoon(actionId,dir);
			if (cartoonInfo && cartoonInfo->isValid())
			{
				nowActionName = actionId;
				iter->popAction();
				cartoonInfo->actionTag = step;
				putMyCartoon(cartoonInfo);
				return ;
			}
			iter->popAction();
		}
	}
	// 执行一个空回调
	CCSprite::runAction(CCSequence::create(CCDelayTime::create(0.5),
					CCCallFunc::create(this, callfunc_selector(MutiMonster::nextStep)),NULL));
	
}

CartoonInfo * MutiMonster::makeMyCartoon(const unsigned int &name,int dir)
{
	CONBINEACTIONMAPS_ITER iter = conbineactionmaps.find(name);
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
bool MutiMonster::isMoving()
{
	return !movePath.empty();
}
/**
 * 技能等可以交叉在行为里
 */
void MutiMonster::putMyCartoon(CartoonInfo *info)
{
	if (!info) return;
	 //处理动作
	if (isMoving())
	{
		CCPoint dest = getLocationByIndex(movePath.front().index);
		movePath.pop_front();
		runAction(this->getParent(),info,dest,getNowTarget());
	}
	else
	{
		runAction(this->getParent(),info,ccp(-1,-1),getNowTarget());
	}
}

// 处理移动了
void MutiMonster::moveToUseAstar(const GridIndex &point)
{
		//使用Astar 移动
	GridIndex nextIndex;
	if (map->getNextPosition(getNowIndex(),point,nextIndex))
	{
		nowLocationIndex = getNowIndex();
		maybeLocationIndex = nextIndex;
		map->setBlock(maybeLocationIndex,GridIndex::MONSTER_BLOCK);
		map->setBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
	
		MoveActionPoint movePoint;
		movePoint.actionName = "move";
		movePoint.index = nextIndex;
		movePath.push_back(movePoint);
	}
}
void MutiMonster::tryMoveUseAstr(const GridIndex &index)
{
	nowAstarDestination.actionName = "move";
	nowAstarDestination.index = index;
}
void MutiMonster::clearAstar()
{
	nowAstarDestination.index.x = -1;
	nowAstarDestination.index.y = -1;
}
void MutiMonster::jumpTo(const GridIndex &point)
{
	this->getPreparePath("jump",this->getStartMyIndex());
}

GridIndex MutiMonster::getStartMyIndex()
{
	GridIndex index = getNowIndex();
	index.x += myindexs.size()?myindexs.at(0).x:0;
	index.y += myindexs.size()?myindexs.at(0).y:0;
	return index;
}
bool MutiMonster::checkIn(const CCPoint &point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	float width = 64;
	float height = 64;
	float x = offset.x-32;
	float y = offset.y-32;
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}
/**
 * 检查当前一个引索 是否碰撞
 */
bool MutiMonster::checkCollideInMap(const GridIndex& nextIndex)
{
	std::vector<GridIndex> tempindexs;
	for (std::vector<GridIndex>::iterator iter = myindexs.begin(); iter != myindexs.end();++iter)
	{
		GridIndex temp;
		temp.x = nextIndex.x + iter->x;
		temp.y = nextIndex.y + iter->y;
		tempindexs.push_back(temp);
	}
	return map->checkCollide(nextIndex,&tempindexs);
}
/**
 * 根据点获取地图上实际像素位置
 */
CCPoint MutiMonster::getLocationByIndex(const GridIndex &index)
{
	if (!map) return ccp(-1,-1);
	return map->getLocationByIndex(index);
}
/**
 * 获取当前的引索
 */
GridIndex MutiMonster::getNowIndex()
{
	GridIndex index =  map->getIndexByLocation(this->getPosition());
	return index;
}

/**
 * 检查当前行为中是否包含自己
 */
bool MutiMonster::isNowAction(const std::string &name)
{
	unsigned int id = ActionPool::getActionIdByName(name);
	if (id & nowActionName) return true;
	return false;
}
MutiMonster * MutiMonster::getNowTarget()
{
	return NULL;
}

void MutiMonster::setPosition(const GridIndex &point)
{
	CCSprite::setPosition(map->getLocationByIndex(point));
}
void MutiMonster::setPosition(const CCPoint &point)
{
	CCPoint dest = point;//map->getLocationByIndex(map->getIndexByLocation(point));
	CCSprite::setPosition(dest);
	map->showGrids();
}

void MutiMonster::freshBlock()
{
	map->clearBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
	map->setBlock(getNowIndex(),GridIndex::MONSTER_BLOCK);
	nowLocationIndex = getNowIndex();
}
/**
* 检查只是底部碰撞了
*/
bool MutiMonster::checkOnlyButtomCollide(const GridIndex &nextIndex)
{
	if (map->checkCollide(nextIndex,NULL)) return true;
	return false;
}

/**
* 下部没有碰撞
*/
bool MutiMonster::checkNotDownCollide(const GridIndex &nextIndex)
{
	if (map->checkCollide(nextIndex,NULL)) return false;
	return true;
}
/**
* 左部没有碰撞
*/
bool MutiMonster::checkNotLeftCollide(const GridIndex &nextIndex)
{
	if (map->checkCollide(nextIndex,NULL)) return false;
	return true;
}
/**
* 上部没有碰撞
*/
bool MutiMonster::checkNotUpCollide(const GridIndex &nextIndex)
{
	if (map->checkCollide(nextIndex,NULL)) return false;
	return true;
}
/**
* 右部没有碰撞
*/
bool MutiMonster::checkNotRightCollide(const GridIndex &nextIndex)
{
	if (map->checkCollide(nextIndex,NULL)) return false;
	return true;
}
/**
* 获取将要下降的点的引索
*/
GridIndex MutiMonster::getPreDownIndex()
{
	GridIndex start = this->getStartMyIndex();
	return GridIndex(start.x,start.y-1);
}
/**
* 获取以point 为起始的路径列表 包含当前路径
*/
void MutiMonster::getPreparePath(const std::string &name,const GridIndex &point)
{
	PRE_PATHS_ITER iter = prePaths.find(name);
	if (iter != prePaths.end() && iter->second.paths.size())
	{
		std::vector<MoveActionPoint>& points = iter->second.paths.at(0).indexs;
		for (int i = 0; i < points.size();i++)
		{
			MoveActionPoint temp = points.at(i);
			temp.index.x += point.x;
			temp.index.y += point.y;
			movePath.push_back(temp);
		}
	}
}
NS_CC_END