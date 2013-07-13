#include "MutiImage.h"
NS_CC_BEGIN
MutiImage * MutiImage::create(script::tixmlCodeNode *node)
{
	MutiImage *image = new MutiImage();
	if (image)
	{
		image->readNode(node);
		image->initWithFile(image->pngName.c_str());
		image->rebuild();
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
MutiImage * MutiImage::create()
{
	MutiImage *image = new MutiImage();
	if (image)
	{
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
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
void MutiImage::rebuild()
{
	initWithFile(pngName.c_str());
}
bool MutiImage::checkIn(const CCPoint &point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	float width = getContentSize().width * getScaleX();
	float height = getContentSize().height * getScaleY();
	float x = 0;
	float y = 0;
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}
NS_CC_END