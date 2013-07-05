#pragma once
#include <vector>
#include "cocos2d.h"
#include "UIItem.h"
#include "UIBase.h"
#include "UISuperBag.h"
#include "UIScrollView.h"
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * 包裹
 **/
class UIList:public UISuperBag{
public:
	static UIList* create();
	bool init();
	int nowItemId;
	virtual bool setItem(UIItem *item,int id);
	/**
	 * 获取当前可视的宽
	 */
	float getPixelWidth();
	/**
	 * 获取当前可视的高
	 **/
	float getPixelHeight();
	
	/**
	 * 通过bagid获取zpos
	 */
	//zPos getZPosByBagId(int bagId);
	CCPoint getPixelPosition(int x,int y);
	const CCSize & getContentSize();
public:
	/**
	 * 获取当前id 的像素位置
	 */
	virtual CCPoint getPixelPosition(int id);

	virtual int getNowTouchBagIdByCursorPosition(const CCPoint& pos);
	/**
	 * 检查坐标是否在区域内
	 */
	virtual bool checkIn(int x,int y);

	float _width; // 宽
	float _height; // 高
	float _eachUpSpan; // 每个高 span
	float _eachLeftSpan; // 每个左span
	UIList()
	{
		_width = _height = 0;
		_eachUpSpan = _eachLeftSpan = 0;
		nowItemId = -1;
	}
	float getViewWidth();
	float getViewHeight();
};
/**
 * 创建带视图的List
 */
class UIViewList:public UIList,public script::tixmlCode{
public:
	static UIViewList *create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	const CCSize & getContentSize();
	void show();
	void hide();
	bool isVisible();
	void addToParent(CCNode *node);
	/**
	 * 创建父节点下的子节点
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
	bool doTouch(int touchType,const CCPoint &touchPoint);
	UIViewList()
	{
		view = NULL;
		viewx = viewy = viewh = vieww = 0;
	}
	UIBase *view;
	std::string backName;
	float viewx;
	float viewy;
	float vieww;
	float viewh;
	std::string scrollTypeStr;
};

NS_CC_END