#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "MutiImage.h"
#include "MutiObject.h"
#include "MutiCartoon.h"
NS_CC_BEGIN
/**
 * 创建一个多层地图
 *	<map name="" width="" height="">
 *		<points name="" str="base64code"/>
 *		<points name="" str="base64code"/>
 *		<img src=""/>
 *		<cartoon src=""/>
 *		<map name="" speedx="" speedy="" x="" y= "" zorder="">
 *		</map>
 *	</map>
 */
class MutiMap:public CCParallaxNode,public script::tixmlCode{
public:
	static MutiMap * create(script::tixmlCodeNode *node);
	/**
	 * 选择对象
	 */
	MutiObject *pickObject(const CCPoint &pixelPoint);

	/**
	 * 从配置文件中读取信息
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * 将信息写入节点当中
	 */
	virtual TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	void write(const std::string &name);


	static MutiMap * create(const char *fileName);
	void takeNode(script::tixmlCodeNode *node);

	void addImage(MutiImage *image);
	void addBigImage(MutiBigImage *bigImage);
	void addMap(MutiMap *map);
	void addCartoon(MutiCartoon *cartoon);
	void save(){write(fileName.c_str());}
protected:
	std::string fileName;
	std::list<MutiImage*> _images; // 图片集合
	std::list<MutiCartoon*> _cartoons; // 动画集合
	std::list<MutiMap*> _grouds; // 远层集合
	std::list<MutiBigImage*> _bigImages;
	typedef std::list<MutiImage*>::iterator IMAGES_ITER;
	typedef std::list<MutiCartoon*>::iterator CARTOONS_ITER;
	typedef std::list<MutiMap*>::iterator GROUDS_ITER;
	typedef std::list<MutiBigImage*>::iterator BIG_IMAGES_ITER;
	int zOrder;
	CCPoint ratio;
	CCPoint offset;
};

/**
 * 地图的编辑模式
 */
class MutiMapEdit:public MutiMap{
public:
protected:
	MutiMap *nowBackgroud;
	MutiImage *nowImage;
	MutiCartoon *nowCartoon;
};
NS_CC_END