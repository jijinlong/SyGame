#include "MutiImage.h"
NS_CC_BEGIN
static MutiImage * create(script::tixmlCodeNode *node)
{
	MutiImage *image = new MutiImage();
	if (image)
	{
		image->readNode(node);
		image->initWithFile(image->pngName.c_str());
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
MutiImage * MutiImage::create()
{
	return NULL;
}
/**
* 从配置文件中读取信息
*/
void MutiImage::readNode(script::tixmlCodeNode *node)
{
	MutiObject::readNode(node);
	pngName = node->getAttr("src");
}
/**
* 将信息写入节点当中
*/
TiXmlElement * MutiImage::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *imageNode = MutiObject::writeNode(parent,"image");
	if (imageNode)
	{
		imageNode->SetAttribute("src",pngName);
	}
	return imageNode;
}

NS_CC_END