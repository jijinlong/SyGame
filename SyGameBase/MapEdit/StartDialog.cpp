#include "StartDialog.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UIXmlBag.h"
NS_CC_BEGIN


void MainDialog::doInitEvent()
{	
	GET_UI_BYNAME(this,UIButton,openBtn,"open"); // 打开一个地图 将会替换当前的地图
	if (openBtn)
	{
		openBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::openMap));
	}
	// TODO 创建一个新的地图

	// TODO 创建一个图片

	// TODO 创建一个动画

	// TODO 创建一个背景
}

/**
 * 关闭自己
 */
class CloseMe:public UICallback
{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			panel->setVisible(false);
		}
	}
};
/**
 * 打开地图逻辑
 */
class OpenMapLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			std::string value = panel->getEditFieldValue("filename");
			// 创建一个map

			panel->setVisible(false); // 将自身隐藏
		}
	}
	//CCScene *scene;
};
void MainDialog::openMap(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("openmap");// 打开openmap.xml 的Panel
	panel->bindBtnClick("open",new OpenMapLogic()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->setVisible(true);
}
NS_CC_END
