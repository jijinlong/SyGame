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
	GET_UI_BYNAME(this,UIButton,saveBtn,"save"); // 打开一个地图 将会替换当前的地图
	if (saveBtn)
	{
		saveBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::saveMap));
	}
	// TODO 创建一个新的地图

	// TODO 创建一个图片
	GET_UI_BYNAME(this,UIButton,createImgBtn,"image"); // 打开一个地图 将会替换当前的地图
	if (createImgBtn)
	{
		createImgBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::createImage));
	}
	// TODO 创建一个动画
	GET_UI_BYNAME(this,UIButton,createCartoonBtn,"cartoon") // 打开一个地图 将会替换当前的地图
	if (createCartoonBtn)
	{
		createCartoonBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::createCartoon));
	}
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
void MainDialog::saveMap(UIBase *base)
{
	MapManager::getMe().getMap()->save();
}
/**
 * 帧的条目
 */
struct stFrameItem:public UIItem{
public:
	// list中的元素
	static stFrameItem *create(const std::string &pngName)
	{
		stFrameItem *node = new stFrameItem();
		node->autorelease();
		node->init(pngName);
		return node;
	}
	void init(const std::string &pngName)
	{
		this->pngName = pngName;
		UILabel *info = UILabel::create(pngName.c_str(),32);
		if (info)
		{
			this->addChild(info);
			info->setPosition(84,25);
		}
		sprite = CCSprite::create(pngName.c_str());
		if (sprite)
		{
			addChild(sprite);
			sprite->setAnchorPoint(ccp(0,0));
		}
	}
	virtual void setSize(float w,float h)
	{
		if (sprite)
		{
			sprite->setScaleX(64/sprite->getContentSize().width);
			sprite->setScaleY(h / sprite->getContentSize().height);
		}
	}
	CCSprite *sprite;
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
		LIST(panel,"list")->show();
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
				addFrame->bindBtnClick("cancel",new CloseMe());
				addFrame->setVisible(true);
			}
		}
	}
	stShowAddFrame(UIWindow *window):window(window)
	{}
	UIWindow *window;
};
class stChoiceBasePanel:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		UIChoice *choice = (UIChoice*) base;
		PANEL(panel,"extinfo")->setVisible(false);
		PANEL(panel,"baseinfo")->setVisible(false);
		if (panel && !choice->isChoiced())
		{
			PANEL(panel,"baseinfo")->setVisible(true);
			CHOICE(panel,"extchoice")->setChoiced(false);
		}
		else if (panel)
		{
			PANEL(panel,"extinfo")->setVisible(true);
		}
	}
};
class stChoiceExtPanel:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		UIChoice *choice = (UIChoice*) base;
		PANEL(panel,"extinfo")->setVisible(false);
		PANEL(panel,"baseinfo")->setVisible(false);
		if (panel && !choice->isChoiced())
		{
			PANEL(panel,"extinfo")->setVisible(true);
			CHOICE(panel,"basechoice")->setChoiced(false);
		}
		else if(panel)
		{
			PANEL(panel,"baseinfo")->setVisible(true);
		}
	}
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
	PANEL(panel,"extinfo")->setVisible(false);
	GET_UI_BYNAME(PANEL(panel,"extinfo"),UISuperBag,bag,"list");
	//bag->bind(); 处理bag的点击消息
	panel->bindChoiceClick("basechoice",new stChoiceBasePanel());
	panel->bindChoiceClick("extchoice",new stChoiceExtPanel());
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
