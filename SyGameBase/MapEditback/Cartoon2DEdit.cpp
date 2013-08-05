#include "Cartoon2DEdit.h"
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
#include "FileSet.h"
NS_CC_BEGIN
class stFrameItem:public BaseUIItem<stFrameItem>
{
public:
	std::string name;
	stFrameItem()
	{
	
	}
}; // 每个帧
class stAddImage:public UICallback{
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
	stAddImage(UIWindow *window):window(window){}
	UIWindow *window;
}; // 增加一个图片

struct stTakeEachImage:stBagExecEach{
	stTakeEachImage(Cartoon2DEdit *edit,CartoonInfo *cartoonInfo):edit(edit),cartoonInfo(cartoonInfo)
	{}
	Cartoon2DEdit *edit;
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
			if (list)
			{
				stTakeEachImage take(edit,&cartoonInfo);
				list->execEachItem(&take);
				FileSet fileSet;
				for (int index = 0; index < take.frames.size();index++)
				{
					fileSet.addFile(take.frames[index]);
				}	
				fileSet.save("temp.cartoon",".\\"); // 保存一个动画的二进制数据
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

			edit->cartoon->runAction(CCRepeatForever::create(animate));

			cartoonInfo.release();
		
		}
	}
	stTestCartoon(UIWindow *window,Cartoon2DEdit *edit):window(window),edit(edit){}
	UIWindow *window;
	Cartoon2DEdit *edit;
}; // 测试

void Cartoon2DEdit::doInitEvent()
{
	// 绑定内部逻辑到系统
	UICallbackManager::getMe().addCallback("do_add_image",new stAddImage(window)); // 绑定按钮的响应事件
	UICallbackManager::getMe().addCallback("testcatoon",new stTestCartoon(window,this)); // 绑定按钮的响应事件

	cartoon = CCSprite::create();
	if (cartoon)
	{
		this->addChild(cartoon);
	}
}

NS_CC_END