#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "MutiImage.h"
#include "MutiObject.h"
#include "MutiCartoon.h"
#include "HexagonGrids.h"

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

class MutiMap;
class MutiMonster;
struct stExecEachBackgroud{
public:
	virtual void exec(MutiMap *map) = 0;
};
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

	void addMonster(MutiMonster *monster);
	void save(){write(fileName.c_str());}

	void addSprite(CCSprite *sprite);
	std::string fileName;
	void hide();
	void show();
	bool isHide;
	void execEachBg(stExecEachBackgroud *bg);
	MutiMap()
	{
		isHide = false;
		_grids = NULL;
	}

	void showGrids();
	/**
	 * 设置阻挡点信息
	 */
	void setBlock(const GridIndex &index);

	void setBlockByTouchPoint(const CCPoint &touchPoint);
protected:
	AStarSeachInHexagonGrids<int>* _grids; // 网格系统
	std::list<MutiImage*> _images; // 图片集合
	std::list<MutiCartoon*> _cartoons; // 动画集合
	std::list<MutiMap*> _grouds; // 远层集合
	std::list<MutiBigImage*> _bigImages;
	std::list<MutiBigTerrain*> _bigTerrains;
	typedef std::list<MutiImage*>::iterator IMAGES_ITER;
	typedef std::list<MutiCartoon*>::iterator CARTOONS_ITER;
	typedef std::list<MutiMap*>::iterator GROUDS_ITER;
	typedef std::list<MutiBigImage*>::iterator BIG_IMAGES_ITER;
	typedef std::list<MutiBigTerrain*>::iterator BIG_TERRAINS_ITER;
	int zOrder;
	CCPoint ratio;
	CCPoint offset;
};

NS_CC_END