#include "UIImage.h"
NS_CC_BEGIN

UIImage * UIImage::create(const char *imgName)
{
	UIImage *node = new UIImage();
	if (node)
	{
		if (node->init(imgName))
		{
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool UIImage::init(const char *imgName)
{
	image = CCSprite::create(imgName);
	if (image)
	{
		this->imgName = imgName;
        this->addChild(image);
		return true;
	}
	return false;
}
 /** 
* 检查是否在区域里
*/
bool UIImage::touchDown(float x,float y)
{
	return false;
}
/**
* 更新位置
*/
bool UIImage::touchMove(float x,float y)
{
	 return false;
}
/**
* 停止拖动
*/
bool UIImage::touchEnd(float x,float y)
{
	 return false;
}
/**
* 设置位置
*/
void UIImage::setPosition(float x,float y)
{
	if (image)
	{
		this->x = x;
		this->y = y;
		image->setPosition(ccp(x,y));
	}
	return ;
}
	
/**
* 设置大小
*/
void UIImage::setSize(float w,float h)
{
	if (image)
	{
		this->w = w;
		this->h = h;
		image->setScaleX(w / image->getContentSize().width);
		image->setScaleY(h / image->getContentSize().height);
	}
	return ;
}
/**
 * 创建父节点下的子节点
 */
TiXmlElement * UIImage::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * imgNode = UIBase::makeNode(parent,"image");
	if (imgNode)
	{
		imgNode->SetAttribute("pngname",imgName);
		imgNode->SetAttribute("width",w);
		imgNode->SetAttribute("height",h);
	}
	return imgNode;
}
NS_CC_END