#pragma once

#include "MutiObject.h"

NS_CC_BEGIN

class MutiImage:public MutiObject{
public:
	std::string pngName;
	static MutiImage * create();
	static MutiImage * create(script::tixmlCodeNode *node);
	/**
	 * 从配置文件中读取信息
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * 将信息写入节点当中
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);
	
	bool checkIn(const CCPoint &point);
	void rebuild();
};
NS_CC_END