#include "StartDialog.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UIXmlBag.h"
#include "MapManager.h"
#include "MutiCartoon.h"
#include "MutiImage.h"
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
	GET_UI_BYNAME(this,UIButton,createImgBtn,"image"); // 打开一个地图 将会替换当前的地图
	if (createImgBtn)
	{
		createImgBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::createImage));
	}
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
			MutiMap *map = MutiMap::create(value.c_str());
			if (map)
			{
				MapManager::getMe().addMap(map); // 增加地图
			}
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

/**
 * 帧的条目
 */
struct stFrameItem:public UIItem{
public:
	// list中的元素
	static stFrameItem *create(const std::string &pngName)
	{
		return NULL;
	}
	std::string pngName;
};
/**
 * 获取动画信息
 */
struct stGetCartoonInfo:stBagExecEach{
	void exec(UIItem *item) 
	{
		stFrameItem *frameItem = (stFrameItem*)(item);
		if (frameItem && cartoon)
		{
			cartoon->pngNames.push_back(frameItem->pngName);
		}
	}
	MutiCartoon *cartoon;
	stGetCartoonInfo(MutiCartoon *cartoon):cartoon(cartoon)
	{
		
	}
};
/**
 * 尝试创建动画
 */
class CreateCartoonLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			MutiCartoon *cartoon = MutiCartoon::create();
			// 获取各个字段的值
			int x = 0, y = 0, w = 0, h = 0;
			PANEL(panel,"baseinfo")->getEditFieldValue("x",x);
			PANEL(panel,"baseinfo")->getEditFieldValue("y",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("w",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("h",y);
			cartoon->setBaseInfo(x,y,w,h);

			// 获取list 设置信息
			stGetCartoonInfo exec(cartoon);
			LIST(PANEL(panel,"extinfo"),"list")->execEachItem(&exec);
			PANEL(panel,"extinfo")->getEditFieldValue("taptime",cartoon->tapTime);
			PANEL(panel,"extinfo")->getEditFieldValue("repeatetimes",cartoon->repeateTimes);

		}
	}
};
/**
 * 将帧添加进Panel
 */
struct stAddFrame:public UICallback{
public:
	void callback(UIBase *base)
	{
		// 从panel中获取List 然后添加进元素
		UIPanel *nowPanel = base->getPanel();
		stFrameItem *item = stFrameItem::create(nowPanel->getEditFieldValue("pngname"));
		LIST(panel,"list")->addItem(item);
		nowPanel->setVisible(false);
	}
	stAddFrame(UIWindow *window,UIPanel *panel):window(window),panel(panel)
	{
		
	}
	UIWindow *window;
	UIPanel *panel;
};
/**
 * 弹出对话框 供增加帧信息
 */
class stShowAddFrame:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			UIPanel *addFrame = window->showPanel("addframe"); // TODO 增加帧
			if (addFrame)
			{
				addFrame->bindBtnClick("ok",new stAddFrame(window,panel));
			}
		}
	}
	stShowAddFrame(UIWindow *window):window(window)
	{}
	UIWindow *window;
};
/**
 * 创建动画
 */
void MainDialog::createCartoon(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("createcartoon");// 打开openmap.xml 的Panel
	panel->bindBtnClick("ok",new CreateCartoonLogic()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件

	// 绑定增加frame的按钮
	PANEL(panel,"extinfo")->bindBtnClick("addframe",new stShowAddFrame(window));
	GET_UI_BYNAME(PANEL(panel,"extinfo"),UISuperBag,bag,"list");
	//bag->bind(); 处理bag的点击消息
	panel->bindChoiceClick("basechoice",NULL);
	panel->bindChoiceClick("extchoice",NULL);
	panel->setVisible(true);
}

/**
 * 创建图像
 */
class CreateImageLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			MutiImage *image = MutiImage::create();
			// 获取各个字段的值
			int x = 0, y = 0, w = 0, h = 0;
			PANEL(panel,"baseinfo")->getEditFieldValue("x",x);
			PANEL(panel,"baseinfo")->getEditFieldValue("y",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("w",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("h",y);
			image->setBaseInfo(x,y,w,h);

			// 获取list 设置信息
			image->pngName = PANEL(panel,"extinfo")->getEditFieldValue("pngname");
			image->rebuild();

			MapManager::getMe().getMap()->addImage(image);

			panel->setVisible(false);
		}
	}
};
void MainDialog::createImage(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("createimage");// 打开openmap.xml 的Panel
	panel->bindBtnClick("ok",new CreateImageLogic()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->setVisible(true);
}
NS_CC_END
