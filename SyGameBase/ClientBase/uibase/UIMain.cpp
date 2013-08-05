#include "UIMain.h"
NS_CC_BEGIN
void UIMain::init(UIEventCallback *callback)
{
	window = UIWindow::create();
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("mainui.xml");
	callback->init(window);
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	if (script::tixmlCode::initFromString((char*)buffer))
	{}
}
UIMain *UIMain::create(CCNode *scene,UIEventCallback *callback)
{
	UIMain *ui = new UIMain();
	ui->init(callback);
	scene->addChild(ui->window);
	return ui;
}
void UIMain::takeNode(script::tixmlCodeNode *node)
{
	if (node->equal("Config"))
	{
		script::tixmlCodeNode startNode = node->getFirstChildNode("start");
		if (startNode.isValid())
		{
			CommonPanel *panel = CommonPanel::create(window,&startNode);
		}

		script::tixmlCodeNode panelNode = node->getFirstChildNode("panel");
		while (panelNode.isValid())
		{
			CommonPanel *panel = CommonPanel::create(window,&panelNode);
			panelNode = panelNode.getNextNode("panel");
		}
	}
}

bool UIMain::touchDown(float x,float y)
{
	if (window) return window->touchDown(x,y);
	return false;
}
bool UIMain::touchMove(float x,float y)
{
	if (window) return window->touchMove(x,y);
	return false;
}
bool UIMain::touchEnd(float x,float y)
{
	if (window) return window->touchEnd(x,y);
	return false;
}
NS_CC_END