#pragma once
#include <vector>
#include "cocos2d.h"
#include "xmlScript.h"

NS_CC_BEGIN
class UIPanel;
/**
 * 实现容纳固定大小的sprite 且空间可以大于展示的空间 可以拖动内容，并且放置
 */
class UIBag;
class UIItem:public CCNode{
public:
	/**
	 * 在包裹中的位置
	 */
	int bagId;
	virtual void setSize(float width,float height);
	void hide();
	void show(const CCRect& viewRect);
	void setPosition(float x,float y);
	void show();
	virtual void visit();
	CREATE_FUNC(UIItem);
	virtual bool init(){return true;}
	/**
	 * 检查点是否在Item 中
	 */
	bool checkIn(float x,float y);
	virtual UIItem *clone(); // 复制自己一份
	/**
	 * 检查自身能移动到该位置否
	 */
	virtual bool canMove(int bagId){return true;}
	virtual void setOpacity(float o){}
	/**
	 * 处理点击
	 * \parma touchType 点击类型
	 * \param touchPoint 点击点
	 */
	virtual bool doTouch(int touchType,const CCPoint &touchPoint){return false;}
protected:
	friend class UIBag;
	UIBag * _bag;
	CCRect _viewRect;
	CCRect _oldRect;
	bool downTag; // 标识是否按下按钮
	bool showInView;
	UIItem()
	{
		showInView = false;
		downTag = false;
		bagId = 0;
		_bag = NULL;
	}
};

class XmlUIItem:public UIItem{
public:
	static XmlUIItem* create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	XmlUIItem()
	{
		panel = NULL;
	}
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	UIPanel * getPanel();
	virtual void setSize(float width,float height);
private:
	UIPanel *panel;
};
template<typename CHILD>
class BaseUIItem:public XmlUIItem,public script::tixmlCode{
public:
	static CHILD * create(const std::string &name)
	{
		CHILD *node = new CHILD();
		if (node)
		{
			node->init(name);
			node->autorelease();
			return node;
		}
		CC_SAFE_DELETE(node);
		return NULL;
	}

	bool init(const std::string &name)
	{
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(name);
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return false;
		if (script::tixmlCode::initFromString((char*)buffer))
		{
			doInitEvent();
			return true;
		}
		return false;
	}
	/**
	 * 从配置文件中加载配置
	 * \param node 配置根节点
	 */
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node && node->equal("Config"))
		{
			XmlUIItem::initWithNode(&node);
		}
		vTakeNode(node);
	}
	virtual void vTakeNode(script::tixmlCodeNode *node){}
protected:
	virtual void doInitEvent(){}
};
NS_CC_END
