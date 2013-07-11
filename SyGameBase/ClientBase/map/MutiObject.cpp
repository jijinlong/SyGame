#include "MutiObject.h"
NS_CC_BEGIN
/**
* 从配置文件中读取信息
*/
void MutiObject::readNode(script::tixmlCodeNode *node)
{
	CCSprite::setPosition(ccp(node->getFloat("x"),node->getFloat("y")));
	float w = node->getFloat("w");
	float h = node->getFloat("h");
	if (w && h)
	{
		this->setScaleX(w / this->getContentSize().width);
		this->setScaleY(h / this->getContentSize().height);
	}
}
/**
* 将信息写入节点当中
*/
TiXmlElement * MutiObject::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *objectNode=new TiXmlElement(name.c_str());
	if (parent)
		parent->LinkEndChild(objectNode);
	if (objectNode)
	{
		objectNode->SetAttribute("x",this->getPositionX());
		objectNode->SetAttribute("y",this->getPositionY());
		objectNode->SetAttribute("w",this->getScaleX() * this->getContentSize().width);
		objectNode->SetAttribute("h",this->getScaleY() * this->getContentSize().height);
	}
	return objectNode;
}

NS_CC_END