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
NS_CC_END