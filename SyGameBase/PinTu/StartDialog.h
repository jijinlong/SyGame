#pragma once
/**
 * 游戏主界面
 */
#include "cocos2d.h"
#include "UIPanel.h"
#include "UIItem.h"
#include "UIChoiceList.h"
#include "UIBag.h"
#include "UILabel.h"
#include "UIEditField.h"
#include "UIWindow.h"
NS_CC_BEGIN

class StartDialog:public BaseDialog<StartDialog>{
public:
	virtual void doInitEvent();
};


class MainDialog:public BaseDialog<MainDialog>{
public:
	virtual void doInitEvent();
};

class GameItem:public UIItem{
public:
	static GameItem *create(script::tixmlCodeNode *node);
	void initWithNode(script::tixmlCodeNode *node);
	virtual void setSize(float w,float h);
	GameItem()
	{
		back = NULL;
	}
private:
	CCSprite *back;
};

class GameDialog:public BaseDialog<GameDialog>{
public:
	virtual void doInitEvent();
	void vTakeNode(script::tixmlCodeNode *node);
};
NS_CC_END