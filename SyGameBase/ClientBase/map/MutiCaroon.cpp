#include "MutiCartoon.h"
#include "FileSet.h"
#include "LocalSprite.h"
NS_CC_BEGIN
MutiCartoon * MutiCartoon::create()
{
	MutiCartoon *cartoon = new MutiCartoon();
	if (cartoon)
	{
		cartoon->autorelease();
		return cartoon;
	}
	CC_SAFE_DELETE(cartoon);
	return NULL;
}
/**
* 从节点上创建动画
*/
MutiCartoon * MutiCartoon::create(script::tixmlCodeNode *node)
{
	MutiCartoon *cartoon = new MutiCartoon();
	if (cartoon)
	{
		 cartoon->readNode(node);
		cartoon->init();
		cartoon->autorelease();
		return cartoon;
	}
	CC_SAFE_DELETE(cartoon);
	return NULL;
}
void MutiCartoon::rebuild()
{
	this->stopAllActions();
	init();
}
bool MutiCartoon::init()
{
	initWithTexture(NULL, CCRectZero);
	/**
	 * 创建动画
	 */
	CCAnimation* animation = CCAnimation::create();
	if (!fromSet)
	{
		for (int i = 0; i < pngNames.size(); i++)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(pngNames[i].c_str());
			CCSpriteFrame *frame = CCSpriteFrame::frameWithTexture(texture,
				CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
			animation->addSpriteFrame(frame);
		}
	}
	else
	{
		FileSet fileSet;
		fileSet.createFromFile(cartoonName.c_str());
		for (int i = 0; i < pngNames.size(); i++)
		{
			LocalSpriteFrame *frame = LocalSpriteFrame::create(pngNames[i].c_str(),&fileSet);
			animation->addSpriteFrame(frame);
		}
	}
	if (pngNames.empty()) return NULL;
	animation->setDelayPerUnit(tapTime / pngNames.size());
	animation->setRestoreOriginalFrame(true);
	if (repeateTimes != -1)
		CCSprite::runAction(CCRepeat::create(CCAnimate::create(animation),repeateTimes));
	else
		CCSprite::runAction(CCRepeatForever::create(CCAnimate::create(animation)));
	return true;
}
/**
* 从配置文件中读取信息
*/
void MutiCartoon::readNode(script::tixmlCodeNode *node)
{
	MutiObject::readNode(node);
	repeateTimes = node->getInt("repeatetimes");
	tapTime = node->getFloat("needtime");
	script::tixmlCodeNode frameNode = node->getFirstChildNode("frame");
	cartoonName = node->getAttr("name");
	while (frameNode.isValid())
	{
		std::string pngName = frameNode.getAttr("name");
		pngNames.push_back(pngName);
		frameNode = frameNode.getNextNode("frame");
	}
}

/**
* 将信息写入节点当中
*/
TiXmlElement * MutiCartoon::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *cartoonNode = MutiObject::writeNode(parent,"cartoon");
	if (cartoonNode)
	{
		cartoonNode->SetAttribute("repeatetimes",repeateTimes);
		cartoonNode->SetAttribute("needtime",tapTime);
		cartoonNode->SetAttribute("fromset","true");
		cartoonNode->SetAttribute("name",cartoonName);
		for (int i = 0; i < pngNames.size();i++)
		{
			TiXmlElement *frameNode=new TiXmlElement("frame");
			if (cartoonNode)
				cartoonNode->LinkEndChild(frameNode);
			frameNode->SetAttribute("name",pngNames[i].c_str());
		}
	}
	return cartoonNode;
}

bool MutiCartoon::checkIn(const CCPoint &point)
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