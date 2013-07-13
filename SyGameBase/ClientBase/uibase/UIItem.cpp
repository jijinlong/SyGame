#include "UIItem.h"
#include "UIPanel.h"
NS_CC_BEGIN
UIItem *UIItem::clone()
{
	UIItem *item = UIItem::create();
	if (item)
	{
		item->bagId = bagId;
		item->setSize(_oldRect.size.width,_oldRect.size.height);
		return item;
	}
	CC_SAFE_DELETE(item);
	return NULL;
}

void UIItem::show()
{
	this->setVisible(true);
}
/**
* 在包裹中的位置
*/
void UIItem::setSize(float width,float height)
{
	_oldRect = CCRectMake(0,0,width,height);
}
void UIItem::hide()
{
	this->setVisible(false);
}
void UIItem::show(const CCRect& viewRect)
{
	_viewRect = viewRect;
	showInView = true;
}
void UIItem::setPosition(float x,float y)
{
	this->setAnchorPoint(ccp(0,0));
	CCNode::setPosition(ccp(x,y));
}
	
void UIItem::visit()
{
	if (showInView)
	{
		CCSize szLimitSize= CCSizeMake(_viewRect.size.width ,_viewRect.size.height);

		CCPoint worldPt = ccp(_viewRect.origin.x,_viewRect.origin.y);
		worldPt = this->getParent()->convertToWorldSpace(worldPt);
		CCSize size;

		if (CC_CONTENT_SCALE_FACTOR() != 1)
		{
			size.height = szLimitSize.height * CC_CONTENT_SCALE_FACTOR();
			size.width = szLimitSize.width * CC_CONTENT_SCALE_FACTOR();
			worldPt = ccpMult(worldPt, CC_CONTENT_SCALE_FACTOR());
		}
		else

		{
			size.width = szLimitSize.width;
			size.height =szLimitSize.height;
		}
		glEnable(GL_SCISSOR_TEST);  
		CCDirector::sharedDirector()->getOpenGLView()->setScissorInPoints(worldPt.x ,worldPt.y,  size.width, size.height);
		CCNode::visit();  
		glDisable(GL_SCISSOR_TEST);  
	}
	else
		CCNode::visit();  
}
/**
 * 检查点是否在Item 中
 */
bool UIItem::checkIn(float x,float y)
{
	float width = _oldRect.size.width;
	float height = _oldRect.size.height;
	CCPoint pos = getPosition();
	CCRect rect = CCRectMake(
			pos.x,
			pos.y,
			width,
			height);
	if (rect.containsPoint(ccp(x,y)))
	{
		return true;
	}
	return false;
}

XmlUIItem* XmlUIItem::create(script::tixmlCodeNode *snode)
{
	XmlUIItem *node = new XmlUIItem();
	if (node && node->initWithNode(snode))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
bool XmlUIItem::initWithNode(script::tixmlCodeNode *node)
{
	panel = UIPanel::createFromNode(node);
	this->addChild(panel);
	panel->setAnchorPoint(ccp(0,0));
	if (panel->back)
	panel->back->setAnchorPoint(ccp(0,0));
	return true;
}
bool XmlUIItem::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (panel)
	{
		panel->doTouch(touchType,touchPoint);
	}
	return true;
}
void XmlUIItem::setSize(float width,float height)
{
	if (panel)
	{
		panel->setSize(width,height);
	}
}
UIPanel * XmlUIItem::getPanel(){return panel;}
NS_CC_END