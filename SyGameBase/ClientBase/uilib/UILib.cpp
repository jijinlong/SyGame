#include "UILib.h"
#include "UIWindow.h"
#include "UIPanel.h"
#include "UIBase.h"
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
// �����չ
	BIND_LIB_ACTION(setposition);
	BIND_LIB_ACTION(showme);
	BIND_LIB_ACTION(hideme);
	BIND_LIB_ACTION(showpanel);
	BIND_LIB_ACTION(hidepanel);
	BIND_LIB_ACTION(bind);
	BIND_LIB_ACTION(panelbind);
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
	if (!node) return; // �����¼�
	
}
void UILib::destroy()
{
	script::Lib<UILibAction,UIStub,UILib>::release();
}

/**
* չʾ�Լ�
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
* �����Լ� 
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
* �ı��Լ�λ��
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
* չʾpanel 
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
* ����Panel
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
 * �����������߼� C++ д���߼�
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
 * ������panel �Ĵ����߼� C++ д���߼�
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
NS_CC_END