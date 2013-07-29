#include "UILib.h"
#include "UIWindow.h"
#include "UIPanel.h"
#include "UIBase.h"
#include "UIFileList.h"
NS_CC_BEGIN
#define BIND_LIB_ACTION(func)\
	{\
		UILibAction *action = new UILibAction;\
		action->type = script::__ACTION_CHECK__;\
		action->action = &UILib::func;\
		actions[#func] = action;\
	}

void UILib::bindActions()
{
	BIND_LIB_ACTION(var);	
	BIND_LIB_ACTION(print);
	BIND_LIB_ACTION(calc);
	BIND_LIB_ACTION(exec);
// 相关扩展
	BIND_LIB_ACTION(setposition);
	BIND_LIB_ACTION(showme);
	BIND_LIB_ACTION(hideme);
	BIND_LIB_ACTION(showpanel);
	BIND_LIB_ACTION(hidepanel);
	BIND_LIB_ACTION(bind);
	BIND_LIB_ACTION(panelbind);
	BIND_LIB_ACTION(panel_label_set_value);
	BIND_LIB_ACTION(parent_p_label_set_value);
	BIND_LIB_ACTION(parent_p_bind);
	BIND_LIB_ACTION(files_show);
}
void UILib::initWithFile(const char *fileName)
{
	bindActions();
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	initFromString((char*)buffer);
}
void UILib::takeNode(script::tixmlCodeNode* node)
{
	if (!node) return; // 处理事件
	
}
void UILib::destroy()
{
	script::Lib<UILibAction,UIStub,UILib>::release();
}

/**
* 展示自己
*/
int UILib::showme(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		stub->base->setVisible(true);
	}
	return 1;
}
/**
* 隐藏自己 
**/
int UILib::hideme(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		stub->base->setVisible(false);
	}
	return 1;
}
/**
* 改变自己位置
**/
int UILib::setposition(UIStub *stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		stub->base->setPosition(node->getInt("x"),node->getInt("y"));
	}
	return 1;
}
/**
* 展示panel 
*/
int UILib::showpanel(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIWindow *window = stub->base->getDepthWindow();
		if (window)
		{
			UIPanel *panel = window->showPanel(node->getAttr("name"));
			std::string tag = node->getAttr("model");
			if (tag == "true" && panel)
			{
				panel->setVisible(true);
				window->pushModel(panel);
			}
		}
	}
	return 1;
}
/**
* 隐藏Panel
*/
int UILib::hidepanel(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIWindow *window = stub->base->getDepthWindow();
		if (window)
		{
			UIPanel *target = window->getPanel(node->getAttr("name"));
			if (target)
			{
				target->hide();
			}
		}
	}
	return 1;
}
/**
 * 绑定自身处理逻辑 C++ 写的逻辑
 **/
int UILib::bind(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		stub->base->bind(UIBase::EVENT_CLICK_DOWN,UICALLBACK(node->getAttr("event")));
	}
	return 1;
}
/**
 * 绑定自身panel 的处理逻辑 C++ 写的逻辑
 */
int UILib::panelbind(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIPanel *panel = stub->base->getPanel();
		if (panel)
		{
			UIWindow *window = panel->getWindow();
			if (window)
			{
				UIPanel *target = window->getPanel(node->getAttr("name"));
				if (target)
					target->bindBtnClick(node->getAttr("btnname"),UICALLBACK(node->getAttr("event")));
			}	
		}
	}
	return 1;
}
/**
 * 设置panel 上UILabel 的值
 */
int UILib::panel_label_set_value(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIPanel *panel = stub->base->getPanel();
		if (panel)
		{
			UIWindow *window = panel->getWindow();
			if (window)
			{
				UIPanel *target = window->getPanel(node->getAttr("name"));
				if (target)
				{
					target->setUILabelvalue(node->getAttr("labelname"),node->getAttr("value"));
				}
			}	
		}
	}
	return 1;
}

/**
 * 设置父类
 */
int UILib::parent_p_label_set_value(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIPanel *panel = stub->base->getPanel();
		if (panel)
		{
			panel->setUILabelvalue(node->getAttr("labelname"),node->getAttr("value"));
		}
	}
	return 1;
}

/**
 * 设置父类的bind
 */
int UILib::parent_p_bind(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIPanel *panel = stub->base->getPanel();
		if (panel)
		{
			panel->bindBtnClick(node->getAttr("btnname"),UICALLBACK(node->getAttr("event")));
		}
	}
	return 1;
}

/**
 * 展示所有文件
 */
int UILib::files_show(UIStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->base)
	{
		UIWindow *window = stub->base->getDepthWindow();
		if (window)
		{
			UIFileList *list = UIFileList::create(window,node->getAttr("showxml"));
			if (list)
			{
				list->show(".");
				window->pushModel(list);
			}
		}
	}
	return 1;
}
NS_CC_END