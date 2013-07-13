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
	readNode(node);
}
/**
 * 选择对象
 */
MutiObject *MutiMap::pickObject(const CCPoint &pixelPoint)
{
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
	return NULL;
}
/**
 * 从配置文件中读取信息
 */
void MutiMap::readNode(script::tixmlCodeNode *node)
{
	if (node && node->equal("Config"))
	{
		script::tixmlCodeNode mapNode = node->getFirstChildNode("map");
		zOrder = node->getInt("zorder");
		ratio.x = node->getInt("ratiox");
		ratio.y = node->getInt("rationy");
		offset.x = node->getInt("offsetx");
		offset.y = node->getInt("offsety");
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
/**
* 将信息写入节点当中
*/
TiXmlElement * MutiMap::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *mapNode=new TiXmlElement(name.c_str());
	if (parent)
		parent->LinkEndChild(mapNode);
	mapNode->SetAttribute("zorder",zOrder);
	mapNode->SetAttribute("ratiox",ratio.x);
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
NS_CC_END