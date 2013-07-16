#include "MapManager.h"

NS_CC_BEGIN
UIWindow * MapManager::getWindow()
{
	return window;
}
MutiMap *MapManager::getMap()
{
	return nowMap;
}
CCScene *MapManager::getScene()
{
	return scene;
}
void MapManager::replaceMap(MutiMap *map)
{
	if (this->nowMap)
	{
		nowMap->save();
		scene->removeChild(this->nowMap,true);
	}
	this->nowMap = map;
	if (scene)
		scene->addChild(map,-2);
}
void MapManager::addMap(MutiMap *map)
{
	if (nowMap) nowMap->setVisible(false); 
	nowMap = map;
	mapList.push_back(map);
}
void MapManager::choiceMap(MutiMap *map)
{
	nowMap = map;
	bool had = false;
	for (MAPLIST_ITER iter = mapList.begin(); iter != mapList.end();++iter)
	{
		if (*iter == map)
		{
			had = true;
		}
		(*iter)->hide();
	}
	if (!had) mapList.push_back(map);
	nowMap->show();
}
void MapManager::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (!nowMap) return;
	switch(touchType)
	{
		case UIBase::TOUCH_DOWN:
		{
			nowObject = nowMap->pickObject(touchPoint);
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
				CCPoint nowPoint = nowMap->getPosition();
				nowMap->setPosition(ccp(nowPoint.x + touchPoint.x - nowTouchPoint.x,
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