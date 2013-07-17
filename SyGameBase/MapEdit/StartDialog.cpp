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
	// TODO 创建一个大图片
	GET_UI_BYNAME(this,UIButton,createBgImageBtn,"bigimage") // 打开一个地图 将会替换当前的地图
	if (createBgImageBtn)
	{
		createBgImageBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::createBigImage));
	}
	// TODO 打开当前地图属性
	GET_UI_BYNAME(this,UIButton,showMapBtn,"map") // 打开一个地图 将会替换当前的地图
	if (showMapBtn)
	{
		showMapBtn->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::showMapProp));
	}
	GET_UI_BYNAME(this,UIChoice,editBlockChoice,"editblock") // 打开一个地图 将会替换当前的地图
	if (editBlockChoice)
	{
		editBlockChoice->bind(UIBase::EVENT_CLICK_DOWN,ui_function(MainDialog::editBlock));
	}
	
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
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
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
				MapManager::getMe().replaceMap(map); // 增加地图
			}
			panel->setVisible(false); // 将自身隐藏
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
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
	window->pushModel(panel);
	panel->bindBtnClick("open",new OpenMapLogic()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->setVisible(true);
}
void MainDialog::saveMap(UIBase *base)
{
	MapManager::getMe().mapRoot->save();
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
			cartoon->rebuild();
			MapManager::getMe().getMap()->addCartoon(cartoon);
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
		nowPanel->hide();
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
				window->pushModel(addFrame);
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
	window->pushModel(panel);
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
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
		}
	}
};
/**
 * 响应创建图像的按钮
 */
void MainDialog::createImage(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("createimage");// 打开openmap.xml 的Panel
	window->pushModel(panel);
	panel->bindBtnClick("ok",new CreateImageLogic()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->setVisible(true);
}
/**
 * 创建图像
 */
class CreateBigImage:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			MutiBigImage *image = MutiBigImage::create(PANEL(panel,"extinfo")->getEditFieldValue("pngname").c_str());
			// 获取各个字段的值
			int x = 0, y = 0, w = 0, h = 0;
			PANEL(panel,"baseinfo")->getEditFieldValue("x",x);
			PANEL(panel,"baseinfo")->getEditFieldValue("y",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("w",y);
			PANEL(panel,"baseinfo")->getEditFieldValue("h",y);
			image->setBaseInfo(x,y,w,h);
			// 获取list 设置信息
			//image->rebuild();

			MapManager::getMe().getMap()->addBigImage(image);

			panel->setVisible(false);
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
		}
	}
};
/**
 * 响应展示创建背景按钮
 **/
void MainDialog::createBigImage(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("createimage");// 打开openmap.xml 的Panel
	window->pushModel(panel);
	panel->bindBtnClick("ok",new CreateBigImage()); // 绑定按钮的响应事件
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->setVisible(true);
}
class MapInfoItem:public BaseUIItem<MapInfoItem>
{
public:
	std::string mapName;
	MutiMap *map;
	MapInfoItem()
	{
		map = NULL;
	}
};
/**
 * 编辑当前条目
 */
struct stEditItem:public UICallback{
public:
	void callback(UIBase *base)
	{
		MapManager::getMe().choiceMap(map);
	}
	stEditItem(MapInfoItem *item,MutiMap *map):item(item),map(map)
	{
		
	}
	MapInfoItem *item;
	MutiMap *map;
};
struct stShowItem:public UICallback{
public:
	void callback(UIBase *base)
	{
		 UIChoice *choice = (UIChoice*) base;
		 if (choice && choice->isChoiced())
		 {
			map->show();
		 }
		 else if (choice)
		 {
			map->hide();
		 }
	}
	stShowItem(MapInfoItem *item,MutiMap *map):item(item),map(map)
	{
		
	}
	MapInfoItem *item;
	MutiMap *map;
};
struct stListItemDown:public UICallback{
public:
	void callback(UIBase *base)
	{
		// 展示详细信息
	}
};

/**
 * 创建新的背景
 **/
struct stNewBackGroud:public UICallback{
public:
	void callback(UIBase *base)
	{
		MapInfoItem *item = MapInfoItem::create("bgiteminfo.xml");
		if (item)
		{
			UIPanel *targetPanel = window->getPanel("showmap");
			UIPanel *infoPanel = window->getPanel("bginfo");
			if (targetPanel && infoPanel)
			{
				LIST(PANEL(targetPanel,"extinfo"),"list")->addItem(item);
				
				
				LIST(PANEL(targetPanel,"extinfo"),"list")->show();
				LIST(PANEL(targetPanel,"extinfo"),"list")->bind(UIBase::EVENT_CLICK_DOWN,new stListItemDown());
				// 创建关联的地图的属性
				GET_UI_BYNAME(item->getPanel(),UILabel,bgName,"bgname");
				if (bgName)
				{
					bgName->setContent(EIDTFIELD(infoPanel,"bgname")->getContent().c_str()); // 设置属性
				}
				// 创建一个底图
				MutiMap *muMap = MutiMap::create("defaultbg.xml");
				if (muMap && MapManager::getMe().getMap())
				{
					MapManager::getMe().getMap()->addMap(muMap);
					MapManager::getMe().choiceMap(muMap); // 当前地图为编辑对象
				}
				item->getPanel()->bindBtnClick("edit",new stEditItem(item,muMap)); // 绑定事件
				item->getPanel()->bindChoiceClick("show",new stShowItem(item,muMap)); // 绑定事件
				item->mapName = bgName->getContent();
			}
		}
	}
	stNewBackGroud(UIWindow *window):window(window)
	{
	
	}
	UIWindow *window;
};
/**
 * 展示创建背景展示属性界面
 */
struct stShowBackgroud:public UICallback{
public:
	void callback(UIBase *base)
	{
		// 展示bg的属性界面
		UIPanel *panel = window->showPanel("bginfo");// 打开bginfo.xml 的Panel
		if (panel)
		{
			panel->bindBtnClick("ok",new stNewBackGroud(window));
			panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
		}
	}
	stShowBackgroud(UIWindow *window):window(window)
	{}
	UIWindow *window;
};
struct stHadQqualItem:public stBagExecEach{
	void exec(UIItem *item) 
	{
		MapInfoItem *infoItem = (MapInfoItem*) item;
		if (infoItem->mapName == mapName)
		{
			value = true;
		}
	}
	bool value;
	stHadQqualItem()
	{
		value = false;
	}
	std::string mapName;
};
/**
 * 遍历场景上的每个地图
 */
struct stShowEachBg:public stExecEachBackgroud{
public:
	void exec(MutiMap *map)
	{
		MapInfoItem *item = MapInfoItem::create("bgiteminfo.xml");
		if (item)
		{
			UIPanel *targetPanel = window->getPanel("showmap");
			if (targetPanel)
			{
				// 先遍历是否存在相同的
				UISuperBag * list = LIST(PANEL(targetPanel,"extinfo"),"list");
				stHadQqualItem exec;
				exec.mapName = map->fileName;
				list->execEachItem(&exec);
				if (!exec.value)
				{
					list->addItem(item);
					item->getPanel()->bindBtnClick("edit",new stEditItem(item,map)); // 绑定事件
					item->getPanel()->bindChoiceClick("show",new stShowItem(item,map)); // 绑定事件
				}
				GET_UI_BYNAME(item->getPanel(),UILabel,bgName,"bgname");
				if (bgName)
				{
					bgName->setContent(map->fileName.c_str()); // 设置属性
				}
				item->mapName = map->fileName;

				list->show();
			}
		}
	}
	UIWindow *window;
};

class SetPanelProp:public UICallback{
public:
	void callback(UIBase *base)
	{
		// 设定当前的map的属性
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			MutiMap *map = MapManager::getMe().getMap();
			if (map)
			{
				PANEL(panel,"baseinfo")->getEditFieldValue("x",map->m_tPosition.x);
				PANEL(panel,"baseinfo")->getEditFieldValue("y",map->m_tPosition.y);
				map->setZOrder(atoi(PANEL(panel,"baseinfo")->getEditFieldValue("zorder").c_str())); // 设置zorder 属性
				std::string name = PANEL(panel,"baseinfo")->getEditFieldValue("name");
				if (name != "")
					map->fileName = name; 
			}
			panel->hide();
		}
	}
};

/**
 * 响应展示属性按钮
 */
void MainDialog::showMapProp(UIBase *base)
{
	UIWindow *window = getWindow();
	/**
	 * 展示一个dialog 携带对应的btn 的处理事件
	 */
	UIPanel *panel = window->showPanel("showmap");// 打开showmap.xml 的Panel
//	window->pushModel(panel);
	// 尝试绑定相关的处理事件
	PANEL(panel,"extinfo")->bindBtnClick("addbg",new stShowBackgroud(window)); // 增加一个层
	panel->bindBtnClick("cancel",new CloseMe());// 绑定按钮的响应事件
	panel->bindBtnClick("ok",new SetPanelProp()); // 设定Panel 的属性
	PANEL(panel,"extinfo")->setVisible(false);
	panel->bindChoiceClick("basechoice",new stChoiceBasePanel());
	panel->bindChoiceClick("extchoice",new stChoiceExtPanel());
	panel->setVisible(true);
	stShowEachBg exec;
	exec.window = window;
	MapManager::getMe().mapRoot->execEachBg(&exec); // 刷新列表
}

void MainDialog::editBlock(UIBase *base)
{
	UIChoice *choice = (UIChoice*) base;
	if (choice)
	{
		if (choice->isChoiced())
		{
			MapManager::getMe().isSetBlock = true;
		}
		else
		{
			MapManager::getMe().isSetBlock = false;
		}
	}
}
NS_CC_END
