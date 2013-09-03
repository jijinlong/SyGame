#include "DebugActionShow.h"
NS_CC_BEGIN
void LineLayer::addChild(DebugShow *show)
{
	showes.push_back(show);
	CCNode::addChild(show);
}
bool LineLayer::doTouch(int touchType,const CCPoint &point)
{
	for (std::vector<DebugShow*>::iterator iter = showes.begin(); iter != showes.end();++iter)
	{
		DebugShow *show =*iter;
		if (!show) continue;
		switch(touchType)
		{
			case UIBase::TOUCH_DOWN:
			{
				if (show->doTouch(touchType,point)) return true;
			}break;
			case UIBase::TOUCH_MOVE:
			{
				if (show->doTouch(touchType,point)) return true;
			}break;
			case UIBase::TOUCH_END:
			{
				show->doTouch(touchType,point);
			}break;
		}
	}
}

NS_CC_END