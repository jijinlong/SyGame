#include "UIList.h"
#include "UIPanel.h"
NS_CC_BEGIN
//////////////////////////// 包裹 /////////////////////////////////////
UIList* UIList::create()
{
	UIList *node = new UIList();
	if (node && node->init())
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
bool UIList::init()
{
	this->_eachHeight = 64;
	this->_eachWidth = 64;
	this->_width = 4;
	this->_height = 4;
	_items.resize(this->_width* this->_height);
	_eachLeftSpan = 1;
	_eachUpSpan = 1;
	return true;
}
bool UIList::setItem(UIItem *item,int id)
{
	if (!item) return false;
	return UISuperBag::setItem(item,id);
}

/**
* 获取当前id 的像素位置
*/
CCPoint UIList::getPixelPosition(int id)
{
	int x = 0;
	int y = id; // y 轴向下
	return getPixelPosition(x,y);
}

CCPoint UIList::getPixelPosition(int x,int y)
{
	CCPoint pos = ccp( x * (_eachWidth + _eachLeftSpan) + _eachLeftSpan,
	1 - y  * (_eachUpSpan + _eachHeight) + _eachUpSpan);
	return pos;
}
const CCSize & UIList::getContentSize()
{
	return CCSizeMake(_eachWidth+_eachLeftSpan,_items.size()*(_height + _eachUpSpan));
}
int UIList::getNowTouchBagIdByCursorPosition(const CCPoint& point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	if ( pos.x >= 0 && pos.y <= _eachUpSpan + _eachHeight  && pos.x <= getViewWidth() && pos.y >= -getViewHeight())
	{
		if (pos.y >= 0)
			return 0;
		else
		{
			int dy = (pos.y) / (_eachUpSpan + _eachHeight) ;

			return 1 - dy ;
		}
	}
	return -1;
}
float UIList::getViewWidth()
{
	return (_eachWidth + _eachLeftSpan);
}
float UIList::getViewHeight()
{
	return _items.size() * (_eachUpSpan + _eachHeight) ;
}
/**
* 检查坐标是否在区域内
*/
bool UIList::checkIn(int x,int y)
{
	if ( x >= 0 && y <= _eachUpSpan + _eachHeight && x <= getViewWidth() && y >= -getViewHeight())
	{
		return true;
	}
	return false;
}

float UIList::getPixelWidth()
{
	return (_eachWidth + _eachLeftSpan);
}
float UIList::getPixelHeight()
{ 
	return (_eachHeight + _eachUpSpan) * (_items.size());
}
///////////////////创建UIXmlList///////////////////////

UIViewList *UIViewList::create(script::tixmlCodeNode *snode)
{
	UIViewList *node = new UIViewList();
	if (node && node->initWithNode(snode))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
/**
 * 设置位置
 */
void UIList::setPosition(float x,float y)
{
	UISuperBag::setPosition(x,y);
}
bool  UIViewList::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (view)
	{
		return view->doTouch(touchType,touchPoint);
	}
	else
	{
		return UIList::doTouch(touchType,touchPoint);
	}
	return false;
}
bool UIViewList::initWithNode(script::tixmlCodeNode *node)
{
	if (node->equal("list"))
	{
		backName = node->getAttr("back");
		if (backName != "")
		{
			CCSprite *back = CCSprite::create(backName.c_str());
			if (back)
			{
				this->addChild(back,-10);
				back->setAnchorPoint(ccp(0,0));
			}
		}
		this->setAnchorPoint(ccp(0,0));
		this->_eachHeight = node->getInt("eachheight");
		this->_eachWidth = node->getInt("eachwidth");
		this->_width = node->getInt("width");
		_eachLeftSpan =  node->getInt("leftspan");
		_eachUpSpan =  node->getInt("upspan");
		this->setPosition(node->getInt("x"),node->getInt("y"));
		script::tixmlCodeNode viewNode = node->getFirstChildNode("face");
		if (viewNode.isValid())
		{
			viewx = viewNode.getFloat("viewx");
			viewy = viewNode.getFloat("viewy");
			vieww = viewNode.getFloat("vieww");
			viewh = viewNode.getFloat("viewh");
			view = UIScrollView::create(viewx,viewy,vieww,viewh);
			scrollTypeStr = node->getAttr("scrollable");
			if (view)
			{
				((UIScrollView*)view)->addContent(this);
				((UIScrollView*)view)->setScrollType(UIScrollView::UP_DOWN);
				((UIScrollView*)view)->setBack("panel_back.png");
				view->setEditable(false);
				if (scrollTypeStr == "true")
				((UIScrollView*)view)->setScrollAble(true);
				else
				((UIScrollView*)view)->setScrollAble(false);
			}
		}
	}
	show();
	return true;
}
/**
 * 创建父节点下的子节点
 */
TiXmlElement * UIViewList::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * bagNode = UIBase::makeNode(parent,"list");
	if (bagNode)
	{
		bagNode->SetAttribute("back",backName);
		bagNode->SetAttribute("width",_width);
		bagNode->SetAttribute("height",_height);
		bagNode->SetAttribute("leftspan",_eachLeftSpan);
		bagNode->SetAttribute("upspan",_eachUpSpan);
		bagNode->SetAttribute("eachheight",_eachHeight);
		bagNode->SetAttribute("eachwidth",_eachWidth);
		
		TiXmlElement *faceNode = new TiXmlElement("face");
		bagNode->LinkEndChild(faceNode);
		faceNode->SetAttribute("viewx",viewx);
		faceNode->SetAttribute("viewy",viewy);
		faceNode->SetAttribute("vieww",vieww);
		faceNode->SetAttribute("viewh",viewh);
		faceNode->SetAttribute("scrollable",scrollTypeStr);
	}
	return bagNode;
}

const CCSize & UIViewList::getContentSize()
{
	return CCSizeMake(this->_eachWidth ,this->_eachHeight * this->_height);
}
void UIViewList::show()
{
	UIList::show();
	if (view)
	{
		view->setVisible(true);
	}
}
void UIViewList::hide()
{
	if (view)
	{
		view->setVisible(false);
	}
}
bool UIViewList::isVisible()
{
	if (view)
	{
		return view->isVisible();
	}
	else
		return CCNode::isVisible();
	return false;
}
void UIViewList::addToParent(CCNode *node)
{
	if (view)
	{
		node->addChild(view);
	}
	else
	{
		node->addChild(this);
	}
}
/**
 * 设置位置
 */
 void UIViewList::setPosition(float x,float y)
 {
	if (view)
	{
		if (y < 0) y = 0;
		if (y > this->_eachHeight * (this->_height + 1)) y = this->_eachHeight * (this->_height + 1);
		UIList::setPosition(x,y);
	}
	else
	{
		UIList::setPosition(x,y);
	}
 }
NS_CC_END