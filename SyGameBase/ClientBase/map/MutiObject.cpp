#include "MutiObject.h"
NS_CC_BEGIN
/**
* �������ļ��ж�ȡ��Ϣ
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
* ����Ϣд��ڵ㵱��
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