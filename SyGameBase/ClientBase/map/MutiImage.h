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

class MutiBigImage:public MutiObject,public script::tixmlCode{
public:
	static MutiBigImage* create(script::tixmlCodeNode *node);
	static MutiBigImage* create(const char *pngName);
	bool init(const char *pngName);

	void saveToXml(float width_pixel_width,const CCPoint &offset,float image_height,float height_pixel_height,const char *pngName,int width_size,int imgSize);

	static MutiBigImage* createFromXml(const  char *pngName);
	bool initFromXml(const char *pngName);

	void takeNode(script::tixmlCodeNode *node);

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
private:
	CCPoint offset;
	std::string pngName;
	CCSize size;
};
NS_CC_END