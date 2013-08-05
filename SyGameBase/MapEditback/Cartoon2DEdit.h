/**
 * 怪物动作编辑器
 * 增加一组动作 保存到文件 测试 
 * 1.动作1 自身播放
 * 2.动作2 离身播放
 * 3.动作3 播放到指定点 将接受碰撞 可以传入回调逻辑名称
 * 4.动作4 跟随地方播放 将接受碰撞 可以传入回调逻辑名称
 */
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
#include "Cartoon.h"
NS_CC_BEGIN
class Cartoon2DEdit:public BaseDialog<Cartoon2DEdit>{
public:
	virtual void doInitEvent();
	CCSprite *cartoon;
	Cartoon2DEdit()
	{
		cartoon = NULL;
	}
};

NS_CC_END