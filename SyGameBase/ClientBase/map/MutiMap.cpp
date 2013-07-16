#include "MutiMap.h"

NS_CC_BEGIN
MutiMap * MutiMap::create(script::tixmlCodeNode *node)
{
	MutiMap *map = new MutiMap();
	if (map)
	{
		map->readNode(node);
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}
MutiMap * MutiMap::create(const char *fileName)
{
	MutiMap *map = new MutiMap();
	if (map)
	{
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return false;
		map->initFromString((char*)buffer);
		map->fileName = fileName;
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}
void  MutiMap::takeNode(script::tixmlCodeNode *node)
{
	if (node && node->equal("Config"))
	{
		script::tixmlCodeNode mapNode = node->getFirstChildNode("map");
		readNode(&mapNode);
	}
}
/**
 * 选择对象
 */
MutiObject *MutiMap::pickObject(const CCPoint &pixelPoint)
{
	if (!this->isVisible() || isHide) return NULL;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			return *iter;
		}
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			return *iter;
		}
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin();iter != _bigImages.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			return *iter;
		}
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin();iter != _bigTerrains.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			return *iter;
		}
	}
	return NULL;
}
void MutiMap::execEachBg(stExecEachBackgroud *bg)
{
	for (GROUDS_ITER iter = _grouds.begin();iter != _grouds.end();++iter)
	{
		bg->exec(*iter);
	}
	bg->exec(this);
}
/**
 * 从配置文件中读取信息
 */
void MutiMap::readNode(script::tixmlCodeNode *node)
{
	script::tixmlCodeNode &mapNode = *node;
	if (mapNode.isValid())
	{
		zOrder = mapNode.getInt("zorder");
		ratio.x = mapNode.getFloat("rationx");
		ratio.y = mapNode.getFloat("rationy");
		offset.x = mapNode.getInt("offsetx");
		offset.y = mapNode.getInt("offsety");
		fileName = mapNode.getAttr("name");
		if (mapNode.isValid())
		{
			script::tixmlCodeNode imageNode = mapNode.getFirstChildNode("image");
			while(imageNode.isValid())
			{
				MutiImage *image = MutiImage::create(&imageNode);
				if (image)
				{
					CCNode::addChild(image);
					_images.push_back(image);
				}
				imageNode = imageNode.getNextNode("image");
			}
			script::tixmlCodeNode cartoonNode = mapNode.getFirstChildNode("cartoon");
			while(cartoonNode.isValid())
			{
				MutiCartoon *cartoon = MutiCartoon::create(&cartoonNode);
				if (cartoon)
				{
					CCNode::addChild(cartoon);
					_cartoons.push_back(cartoon);
				}
				cartoonNode = cartoonNode.getNextNode("cartoon");
			}
			script::tixmlCodeNode bigImageNode = mapNode.getFirstChildNode("bigimage");
			while(bigImageNode.isValid())
			{
				MutiBigImage *image = MutiBigImage::create(&bigImageNode);
				if (image)
				{
					CCNode::addChild(image);
					_bigImages.push_back(image);
				}
				bigImageNode = bigImageNode.getNextNode("bigimage");
			}
			script::tixmlCodeNode bigTerrainNode = mapNode.getFirstChildNode("bigterrain");
			while(bigTerrainNode.isValid())
			{
				MutiBigTerrain *image = MutiBigTerrain::create(&bigTerrainNode);
				if (image)
				{
					CCNode::addChild(image);
					_bigTerrains.push_back(image);
				}
				bigTerrainNode = bigTerrainNode.getNextNode("bigterrain");
			}
			/**
			 * 递归的方式创建子节点
			 */
			script::tixmlCodeNode childMapNode = mapNode.getFirstChildNode("map");
			while (childMapNode.isValid())
			{
				MutiMap *map = MutiMap::create(&childMapNode);
				if (map)
				{
					this->addChild(map,map->zOrder,map->ratio,map->offset);
					_grouds.push_back(map);
				}
				childMapNode = childMapNode.getNextNode("map");
			}
		}
	}
}
void MutiMap::addImage(MutiImage *image)
{
	CCNode::addChild(image);
	_images.push_back(image);
}
void MutiMap::addCartoon(MutiCartoon *cartoon)
{
	CCNode::addChild(cartoon);
	_cartoons.push_back(cartoon);
}
void MutiMap::addMap(MutiMap *map)
{
	this->addChild(map,map->zOrder,map->ratio,map->offset);
	_grouds.push_back(map);
}
void MutiMap::addBigImage(MutiBigImage *bigImage)
{
	CCNode::addChild(bigImage);
	_bigImages.push_back(bigImage);
}
/**
* 将信息写入节点当中
*/
TiXmlElement * MutiMap::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *mapNode=new TiXmlElement(name.c_str());
	if (parent)
		parent->LinkEndChild(mapNode);
	mapNode->SetAttribute("zorder",zOrder);
	mapNode->SetAttribute("rationx",ratio.x);
	mapNode->SetAttribute("rationy",ratio.y);
	mapNode->SetAttribute("offsetx",offset.x);
	mapNode->SetAttribute("offsety",offset.y);
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"image");
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"cartoon");
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"map");
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"bigimage");
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"bigterrain");
	}
	return mapNode;
}

/**
 * 将地图保存到文件
 */
void MutiMap::write(const std::string &name)
{
	TiXmlDocument *pDoc=new TiXmlDocument; //定义一个文档的指针
	//添加一个xml头。
	TiXmlDeclaration *pDeclaration=new TiXmlDeclaration("1.0","UTF-8","");
	pDoc->LinkEndChild(pDeclaration);
	//添加XMl的根节点
	TiXmlElement *configNode= new TiXmlElement("Config");
	pDoc->LinkEndChild(configNode);
	
	TiXmlElement *mapNode = writeNode(configNode,"map");

	pDoc->SaveFile(name);
}

void MutiMap::hide()
{
	isHide = true;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->hide();
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
}
void MutiMap::show()
{
	isHide = false;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->show();
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
}
NS_CC_END