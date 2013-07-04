#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN

class UIImage :public UIBase{
public:
	static UIImage * create(const char *imgName);

	bool init(const char *imgName);
	 /** 
	 * 检查是否在区域里
	 */
	virtual bool touchDown(float x,float y);
	/**
	 * 更新位置
	 */
	virtual bool touchMove(float x,float y);
	/**
	 * 停止拖动
	 */
	virtual bool touchEnd(float x,float y);
	/**
	 * 设置位置
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * 设置大小
	 */
	virtual void setSize(float w,float h);
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * 创建父节点下的子节点
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
private:
	bool _editable;
	CCSprite *image;
	std::string imgName;
	UIImage()
	{
		_editable = false;
		image = NULL;
		_touchIn = false;
	}
	bool _touchIn;
	CCPoint nowTouchPoint;
};

NS_CC_END