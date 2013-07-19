#include "UIWindow.h"
#include "StartScene.h"
#include "StartDialog.h"
#include <pthread.h>
#include "PngPack.h"
#include "MapManager.h"
#include "MutiImage.h"
#include "UIFileList.h"
#include "MutiMonster.h"
USING_NS_CC;


LoadProcess* LoadProcess::create(const char *backName,const char *backValue)
{
	LoadProcess *pRet = new LoadProcess();
    if (pRet && pRet->init(backName, backValue))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool LoadProcess::init(const char *backName,const char *backValue)
{
	this->maxValue = 100;
	this->value = 0;
	this->backSprite = CCSprite::create("load_back.png");
	this->backSprite->setAnchorPoint(ccp(0,0.5));
	this->addChild(this->backSprite);
	this->valueSprite = CCSprite::create("load_show.png");
	this->valueSprite->setAnchorPoint(ccp(0,0.5));
	this->addChild(this->valueSprite);
	setValue(value);

	this->setScaleX(700 / this->backSprite->getContentSize().width);
	return true;
}
void LoadProcess::setValue(float valuep)
{
	this->value = valuep * maxValue;
	float width = 433;
	width *= ((float)value) / maxValue;
	valueSprite->setTextureRect(CCRectMake(0,0,
	width,valueSprite->getContentSize().height));
}
void LoadProcess::setColor(const ccColor3B& color)
{
	this->backSprite->setColor(color);
	this->valueSprite->setColor(color);
}

CCScene* StartScene::scene()
{
    CCScene *scene = CCScene::create();
	MapManager::getMe().scene = scene;
    StartScene *layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

/**
 * 一个简单的游戏
 * 进入直接玩 有定时功能 主场景是个BAG
 */

bool StartScene::init()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	window = UIWindow::create();
	if (!window) return false;
	
	this->addChild(window);
	if ( !CCLayer::init() )
    {
        return false;
    }
	
    this->setTouchEnabled(true);
	
	/**
	 * 操作界面 几个Button 
	 */
	MainDialog *mainDialog = MainDialog::create(window,"mainui.xml");
	
	
	MapManager::getMe().window = window;

	this->schedule(schedule_selector(StartScene::step), 0.75f); 

	MutiBigImage *image = MutiBigImage::createFromXml("bigimage.pngxmlext");
	if (image)
	{
	//	this->addChild(image);
	}
	MutiBigTerrain *terrain = MutiBigTerrain::create("grass.png",2,2);
	if (terrain)
	{
		//this->addChild(terrain);
		terrain->setPosition(ccp(10,10));
	}
	MutiMap *map = MutiMap::create("defaultmap.xml");
	if (map)
	{
		map->showGrids();
		MapManager::getMe().replaceMap(map);
	}
	UIFileList *list = UIFileList::create(window,"filelist.xml");
	if (list)
	{
		list->show(".");
		window->pushModel(list);
	}
	for (int i = 0; i < 5;i++)
	{
		MutiMonster *monster = MutiMonster::create();
		if (monster)
		{
			monster->start("monster1.xml");
			map->addMonster(monster);
			monster->tryMove(GridIndex(5,5+i));
			monster->setPosition(GridIndex(0,i));
		}
	}
	MutiMonster *monster = MutiMonster::create();
	if (monster)
	{
		monster->start("monster1.xml");
		map->addMonster(monster);
		
		monster->setPosition(GridIndex(0,0));
	}
	CCSprite *sprite = CCSprite::create("cell.png");
	if (sprite)
	{
		map->addSprite(sprite);
	}
	return true;
}

void StartScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	
	/**
	 * 处理窗口
	 */
	if (window->touchDown(pos.x,pos.y)) return;
	MapManager::getMe().doTouch(UIBase::TOUCH_DOWN,pos);
	
}
void StartScene::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	if (window->touchMove(pos.x,pos.y)) return;
	MapManager::getMe().doTouch(UIBase::TOUCH_MOVE,pos);
}
void StartScene::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	window->touchEnd(pos.x,pos.y);
	MapManager::getMe().doTouch(UIBase::TOUCH_END,pos);
}
void StartScene::step(float dt)
{

}