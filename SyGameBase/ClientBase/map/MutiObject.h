#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
NS_CC_BEGIN

class MutiObject :public CCSprite{
public:
	/**
	 * 从配置文件中读取信息
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * 将信息写入节点当中
	 */
	virtual TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	bool checkIn(const CCPoint &point);
};

NS_CC_END