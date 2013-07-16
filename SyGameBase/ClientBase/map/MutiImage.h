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

class MutiBigTerrain:public MutiObject{
public:
	static MutiBigTerrain* create(script::tixmlCodeNode *node);

	/**
	 * 创建一个地表
	 */
	static MutiBigTerrain* create(const char *fileName,int width,int height);
	/**
	 * 使用纹理初始化
	 */
	virtual bool initWithTexture(CCTexture2D *pTexture, const CCRect& rect, bool rotated);
	/**
	 * 设置数据
	 */
	void setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize);
	/**
	 * 绘制
	 */
	virtual void draw(void);
	virtual void updateTransform(void);

	bool checkIn(float x,float y);

	void setPosition(const CCPoint &point);

	/**
	 * 从配置文件中读取信息
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * 将信息写入节点当中
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);
	void rebuild();

	bool checkIn(const CCPoint &point);
private:
	std::vector<ccV3F_C4B_T2F> points; // 顶点集合
	int _width;
	int _height;
	int _eachWidth;
	int _eachHeight;
	std::string pngName; // 图片集合
};
NS_CC_END