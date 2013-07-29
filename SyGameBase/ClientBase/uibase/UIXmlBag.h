#pragma once
#include "cocos2d.h"
#include "UISuperBag.h"
#include "xmlScript.h"
#include "UIScrollView.h"
NS_CC_BEGIN
class UIPanel;
/**
 * 包裹
 **/
class UIRectBag:public UISuperBag{
public:
	static UIRectBag* create();
	bool init();
	int nowItemId;
	virtual bool setItem(UIItem *item,int id);
	virtual bool addItem(int itemId,int itemNum);
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
	UIRectBag()
	{
		_width = _height = 0;
		_eachUpSpan = _eachLeftSpan = 0;
		nowItemId = -1;
	}
	float getViewWidth();
	float getViewHeight();
};

/**
 * 包裹
 */
class UIViewBag:public UIRectBag,public script::tixmlCode{
public:
	/**
	 * 创建UI对象
	 */
	static UIViewBag *create(const char*bagName);
	static UIViewBag *create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	bool init(const char*bagName);
	const CCSize & getContentSize();
	void show();
	void hide();
	bool isVisible();
	void addToParent(CCNode *node);
	void takeNode(script::tixmlCodeNode *node);
	/**
	 * 创建父节点下的子节点
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
	bool doTouch(int touchType,const CCPoint &touchPoint);
	UIViewBag()
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

class XmlBagItem:public UIItem{
public:
	static XmlBagItem* create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	XmlBagItem()
	{
		panel = NULL;
	}
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	UIPanel * getPanel(){return panel;}
	virtual void setSize(float width,float height);

	void doCreateEvent();

	std::string onCreateName;
private:
	UIPanel *panel;
};
NS_CC_END