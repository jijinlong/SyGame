#include "Monster2DEdit.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UIXmlBag.h"
#include "MapManager.h"
#include "MutiCartoon.h"
#include "MutiImage.h"
#include "MutiMonster.h"
#include "UILib.h"
#include "Cartoon.h"
#include "UIFileList.h"
NS_CC_BEGIN

class DoCreateMonster:public UICallback{
public:
	void callback(UIBase *base)
	{
		
	}
}; // 获取信息 创建一个Monster

class DoShowDirFrames:public UICallback{
public:
	void callback(UIBase *base)
	{
		
	}
}; // 展示创建一个方向的帧

class DoAddFrames:public UICallback{
public:
	void callback(UIBase *base)
	{
		
	}
}; // 增加一个序列帧
class stAddImage:public UICallback{
public:
	void callback(UIBase *base)
	{
		if (window)
		{
			UIPanel *dirFrameDialog = window->getPanel("monsteredit/add_dir_frames");
			if (dirFrameDialog)
			{
				// 添加条目进list
				UISuperBag *list = LIST(dirFrameDialog,"list");
				if (list)
				{
					UIFileItem *fileItem = UIFileItem::create("diritem.xml");
					list->addItem(fileItem);
				}
				list->show();
			}
		}
	}
	stAddImage(UIWindow *window):window(window){}
	UIWindow *window;
}; // 增加一个图片
class stDirItem:public BaseUIItem<stDirItem>
{
public:
	CartoonXmlAction xmlAction;
}; // 每个方向的条目

class stFramesItem:public BaseUIItem<stFramesItem>{
public:
	CartoonDirAction dirAction;
}; // 每个动作帧

void Monster2DEdit::doInitEvent()
{
	// 绑定内部逻辑到系统中
	UICallbackManager::getMe().addCallback("do_create_monster",new DoCreateMonster()); // 绑定按钮的响应事件
	UICallbackManager::getMe().addCallback("do_show_dir_frames",new DoShowDirFrames()); // 绑定按钮的响应事件
	UICallbackManager::getMe().addCallback("do_add_frames",new DoAddFrames()); // 绑定按钮的响应事件
	UICallbackManager::getMe().addCallback("do_add_image",new stAddImage(window)); // 绑定按钮的响应事件
}

NS_CC_END