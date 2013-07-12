#pragma once
#include "MutiMap.h"
#include "UIWindow.h"
NS_CC_BEGIN

/**
 * 当前地图管理器 
 * 包含场景 和 window 的实例
 */
class MapManager{
public:
	static MapManager & getMe()
	{
		static MapManager mm;
		return mm;
	}
	void addMap(MutiMap *map);
	UIWindow * getWindow();
	MutiMap *getMap();
	CCScene *getScene();
	UIWindow *window;
	MutiMap * map;
	CCScene *scene;
	MapManager()
	{
		scene = NULL;
		window = NULL;
		map = NULL;
	}
};

NS_CC_END