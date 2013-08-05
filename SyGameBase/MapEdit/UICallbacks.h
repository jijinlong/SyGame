#pragma once

#include "UIButton.h"
#include "UIWindow.h"
#include "UIXmlBag.h"
#include "MapManager.h"
#include "MutiCartoon.h"
#include "MutiImage.h"
#include "MutiMonster.h"
#include "UILib.h"
#include "FileSet.h"
NS_CC_BEGIN

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
			std::string fileName = panel->getUILablevalue("filename");

			// 获取list 设置信息
			image->pngName = fileName;
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
 * 创建大图逻辑
 */
class CreateBigImageLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		if (window)
		{
			UIPanel *target = base->getPanel();
			std::string fileName = target->getUILablevalue("filename");
			MutiBigImage *image = MutiBigImage::create(fileName.c_str());

			MapManager::getMe().getMap()->addBigImage(image);

			target->setVisible(false);
			if (target->isModel())
			{
				target->getWindow()->popModel();
			}
		}
	}
	CreateBigImageLogic(UIWindow *window):window(window){}
	UIWindow *window;
};
/**
 * 创建动画系列///////////////////////////////////////////////////////////////////
 **/
class stFrameItem:public BaseUIItem<stFrameItem>
{
public:
	std::string name;
	stFrameItem()
	{
	
	}
}; // 每个帧
class stAddImageForCartoon:public UICallback{
public:
	void callback(UIBase *base)
	{
		if (window)
		{
			UIPanel *target = base->getPanel();
			std::string fileName = target->getUILablevalue("filename");
			UIPanel *dirFrameDialog = window->getPanel("cartoonedit/createcartoon");
			if (dirFrameDialog)
			{
				// 添加条目进list
				UISuperBag *list = LIST(dirFrameDialog,"list");
				if (list)
				{
					stFrameItem *fileItem = stFrameItem::create("cartoonedit/frame_item.xml");
					fileItem->name = fileName ;
					fileItem->getPanel()->setUILabelvalue("bgname",fileItem->name);
					list->addItem(fileItem);
					CCSprite * content = CCSprite::create(fileItem->name.c_str());
					if (content)
					{
						content->setAnchorPoint(ccp(0,0));
						fileItem->addChild(content);
					}
				}
				list->show();
			}
		}
	}
	stAddImageForCartoon(UIWindow *window):window(window){}
	UIWindow *window;
}; // 增加一个图片

struct stTakeEachImage:stBagExecEach{
	stTakeEachImage(CartoonInfo *cartoonInfo):cartoonInfo(cartoonInfo)
	{}
	CartoonInfo *cartoonInfo;
	std::vector<std::string> frames;
	void exec(UIItem *item)
	{
		stFrameItem *frameItem = (stFrameItem*) item;
		if (frameItem)
		{
			CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(frameItem->name.c_str());
			CCSpriteFrame *frame = CCSpriteFrame::frameWithTexture(texture,CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
			frame->retain();
			cartoonInfo->frames.push_back(frame);
			frames.push_back(frameItem->name.c_str());
		}
	}
};
class stTestCartoon:public UICallback{
public:
	void callback(UIBase *base)
	{
		// 获取list中的每个元素 构建动画 并 放置于Panel 测试
		UIPanel *dirFrameDialog = window->getPanel("cartoonedit/createcartoon");
		if (dirFrameDialog)
		{
			// 添加条目进list
			CartoonInfo cartoonInfo;
			UISuperBag *list = LIST(dirFrameDialog,"list");
			MutiCartoon *cartoon = MutiCartoon::create();
			std::string cartoonName = dirFrameDialog->getEditFieldValue("cartoonname");
			if (cartoonName == "") return;
			if (list)
			{
				stTakeEachImage take(&cartoonInfo);
				list->execEachItem(&take);
				FileSet fileSet;
				for (int index = 0; index < take.frames.size();index++)
				{
					fileSet.addFile(take.frames[index]);
					cartoon->pngNames.push_back(take.frames[index]);
				}	
				fileSet.save(cartoonName.c_str(),".\\"); // 保存一个动画的二进制数据
			}
			cartoonInfo.cartoonType = CartoonInfo::SELF;
			cartoonInfo.frameType = CartoonInfo::TIME_FRAMES;
			cartoonInfo.needTime = 1;
			GET_UI_BYNAME(dirFrameDialog,UIChoice,choice,"locationframe");
			if (choice && choice->isChoiced())
			{
				cartoonInfo.frameType = CartoonInfo::MOVE_FRAMES;
			}
			CCAnimate *animate = CCAnimate::create(cartoonInfo.createAnimation());
			
			cartoon->tapTime = 1;
			cartoon->cartoonName = cartoonName.c_str();
			cartoon->rebuild();
			
			MapManager::getMe().getMap()->addCartoon(cartoon);

			cartoonInfo.release();
		
		}
	}
	stTestCartoon(UIWindow *window,CCNode *edit):window(window),edit(edit){}
	UIWindow *window;
	CCNode *edit;
}; // 测试

///////END//动画///////////////////////////////////////////////////////////////////////////////

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
};

// 保存地图////////////////////////////

class SaveMapLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			std::string value = panel->getEditFieldValue("filename");
			MapManager::getMe().mapRoot->write(value);
			
			panel->setVisible(false); // 将自身隐藏
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
		}
	}
};

////设置阻挡点信息////////////////////////

struct SetBlockInfoLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			int  value = 0; 
			panel->getEditFieldValue("blockvalue",value);
			{
				MapManager::getMe().isSetBlock = true;
				MapManager::getMe().blockValue = value;
			}
		}
	}
};
struct ClearBlockInfoLogic:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			MapManager::getMe().isSetBlock = false;
			MapManager::getMe().blockValue = 0;
			panel->hide();
		}
	}
};

/// 展示地图逻辑
/**
 * 展示创建背景展示属性界面/////////////////////////////////////
 */

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
/**
 * 遍历场景上的每个地图
 */
struct stShowEachBg:public stExecEachBackgroud{
public:
	void exec(MutiMap *map)
	{
		MapInfoItem *item = MapInfoItem::create("maprop/iteminfo.xml");
		if (item)
		{
			UIPanel *targetPanel = window->getPanel("maprop/showmap");
			if (targetPanel)
			{
				// 先遍历是否存在相同的
				UISuperBag * list = LIST(targetPanel,"list");
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
				panel->getEditFieldValue("x",map->m_tPosition.x);
				panel->getEditFieldValue("y",map->m_tPosition.y);
				map->setZOrder(atoi(panel->getEditFieldValue("zorder").c_str())); // 设置zorder 属性
				std::string name = panel->getEditFieldValue("name");
				if (name != "")
					map->fileName = name; 
			}
		}
	}
};

struct stShowMapProp:public UICallback{
public:
	void callback(UIBase *base)
	{
		if (window)
		{
			UIPanel *panel = window->showPanel("maprop/showmap");// 打开showmap.xml 的Panel
			if (panel)
			{
				stShowEachBg exec;
				exec.window = window;
				MapManager::getMe().mapRoot->execEachBg(&exec); // 刷新列表
				panel->setVisible(true);
			}
		}
	}
	UIWindow *window;

	stShowMapProp(UIWindow *window):window(window)
	{}
};
/**
 * 创建新的背景
 **/
struct stAddLayer:public UICallback{
public:
	void callback(UIBase *base)
	{
		MapInfoItem *item = MapInfoItem::create("maprop/iteminfo.xml");
		if (item)
		{
			UIPanel *targetPanel = window->getPanel("maprop/showmap");
			UIPanel *infoPanel = window->getPanel("maprop/addnewlayer");
			if (targetPanel && infoPanel)
			{
				std::string newLayerName = EIDTFIELD(infoPanel,"bgname")->getContent().c_str();
				if (newLayerName == "") return;
				LIST(targetPanel,"list")->addItem(item);
				
				LIST(targetPanel,"list")->show();
				
				// 创建关联的地图的属性
				GET_UI_BYNAME(item->getPanel(),UILabel,bgName,"bgname");
				if (bgName)
				{
					bgName->setContent(newLayerName.c_str()); // 设置属性
				}
				// 创建一个底图
				MutiMap *muMap = MutiMap::create("maprop/defaultbg.xml");
				
				if (muMap && MapManager::getMe().getMap())
				{
					muMap->fileName = newLayerName;
					MapManager::getMe().getMap()->addMap(muMap);
					MapManager::getMe().choiceMap(muMap); // 当前地图为编辑对象
				}
				item->getPanel()->bindBtnClick("edit",new stEditItem(item,muMap)); // 绑定事件
				item->getPanel()->bindChoiceClick("show",new stShowItem(item,muMap)); // 绑定事件
				item->mapName = bgName->getContent();
			}
		}
	}
	stAddLayer(UIWindow *window):window(window)
	{
	
	}
	UIWindow *window;
};
	

// 增加怪物//////////////////////
struct stAddMonster:public UICallback{
public:
	void callback(UIBase *base)
	{
		UIPanel *targetPanel = window->getPanel("createmonster/createmonster");
		if (targetPanel)
		{
			std::string monstername= targetPanel->getEditFieldValue("monstername");
			if (monstername == "")
			{
				return;
			}
			MutiMonster *monster = MutiMonster::create();
			if (monster)
			{
				targetPanel->getEditFieldValue("bossai",monster->monsterAIID);
				monster->start(monstername.c_str());
				MapManager::getMe().mapRoot->addMonster(monster);
				monster->setPosition(GridIndex(0,2));
			}
		}
	}
	stAddMonster(UIWindow *window):window(window)
	{
	
	}
	UIWindow *window;
};

// 初始化事件池

class LogicCallback:public UIEventCallback{
public:
	void init(UIWindow *window)
	{
		UICallbackManager::getMe().addCallback("do_add_big_image",new CreateBigImageLogic(window));
		UICallbackManager::getMe().addCallback("do_add_image",new CreateImageLogic());

		UICallbackManager::getMe().addCallback("do_add_image_for_cartoon",new stAddImageForCartoon(window));
		UICallbackManager::getMe().addCallback("testcatoon",new stTestCartoon(window,window)); // 绑定按钮的响应事件

		UICallbackManager::getMe().addCallback("openmaplogic",new OpenMapLogic()); // 绑定按钮的响应事件

		UICallbackManager::getMe().addCallback("savemaplogic",new SaveMapLogic()); // 绑定按钮的响应事件

		UICallbackManager::getMe().addCallback("set_map_block",new SetBlockInfoLogic()); // 绑定按钮的响应事件

		UICallbackManager::getMe().addCallback("cancel_set_map_block",new ClearBlockInfoLogic()); // 绑定按钮的响应事件
	
		UICallbackManager::getMe().addCallback("do_show_map_prop",new stShowMapProp(window)); // 展示地图属性

		UICallbackManager::getMe().addCallback("add_new_layer",new stAddLayer(window)); // 增加新的层
		
		UICallbackManager::getMe().addCallback("do_add_monster",new stAddMonster(window)); // 增加新的层
	}
};
NS_CC_END