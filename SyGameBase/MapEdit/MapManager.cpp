#include "MapManager.h"

NS_CC_BEGIN
UIWindow * MapManager::getWindow()
{
	return window;
}
MutiMap *MapManager::getMap()
{
	return map;
}
CCScene *MapManager::getScene()
{
	return scene;
}
void MapManager::addMap(MutiMap *map)
{
	if (this->map) scene->removeChild(this->map,true);
	this->map = map;
	if (scene)
		scene->addChild(map);
}

void MapManager::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (!map) return;
	switch(touchType)
	{
		case UIBase::TOUCH_DOWN:
		{
			nowObject = map->pickObject(touchPoint);
			nowTouchPoint = touchPoint;
		}break;
		case UIBase::TOUCH_MOVE:
		{
			if (nowObject)
			{
				CCPoint nowPoint = nowObject->getPosition();
				nowObject->setPosition(ccp(nowPoint.x + touchPoint.x - nowTouchPoint.x,
                                  nowPoint.y + touchPoint.y - nowTouchPoint.y));
				nowTouchPoint = touchPoint;
				return;
			}
			else
			{
				CCPoint nowPoint = map->getPosition();
				map->setPosition(ccp(nowPoint.x + touchPoint.x - nowTouchPoint.x,
                                  nowPoint.y + touchPoint.y - nowTouchPoint.y));
				nowTouchPoint = touchPoint;
				return;
			}
		}break;
		case UIBase::TOUCH_END:
		{
			nowObject = NULL;
		}break;
	}
}
NS_CC_END