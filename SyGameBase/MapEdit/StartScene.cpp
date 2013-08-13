#include "UIWindow.h"
#include "StartScene.h"
//#include "StartDialog.h"
#include <pthread.h>
#include "PngPack.h"
#include "MapManager.h"
#include "MutiImage.h"
#include "UIFileList.h"
#include "MutiMonster.h"
//#include "Layer3D.h"
#include "CCSprite3D.h"
#include "UILib.h"
//#include "Cartoon2DEdit.h"
#include "UICallbacks.h"
#include "CCSprite3D.h"
#include "CCEditBox.h"
#include "CCScale9Sprite.h"
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
	theAILib.initWithFile("monsterai.xml");
	theUILib.initWithFile("uilib.xml");

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	LogicCallback initLogic;
	mainUI = UIMain::create(this,&initLogic);
	if ( !CCLayer::init() )
    {
        return false;  
    }
	
	CCSprite3D *d3sprite = CCSprite3D::create("terran.md2", "terran.png");
	if (d3sprite)
	{
		this->addChild(d3sprite);
	}

    this->setTouchEnabled(true);
	
	MapManager::getMe().window = mainUI->window;

	this->schedule(schedule_selector(StartScene::step), 0.75f);   
	

	MutiMap *map = MutiMap::create("map2.xml");
	if (map)
	{
		map->showGrids();
		MapManager::getMe().replaceMap(map);
	}
	
/*
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	extension::CCScale9Sprite * sacel9SprY=extension::CCScale9Sprite::create("cell.png");
	extension::CCEditBox * box = extension::CCEditBox::create(CCSizeMake(300,60), sacel9SprY);

	//    设置编辑框内的文字
	box->setText(" ");
	//    获取编辑框内的文字
	CCLOG("Text:%s",box->getText());
	box->setFontColor(ccc3(255, 0, 0));
	//    当编辑框中没有任何字符的提示
	box->setPlaceHolder("pleac input word");
	CCLOG("PlaceHolder:%s",box->getPlaceHolder());
	box->setMargins(2,1);
	//    最大输入文本长度
	box->setMaxLength(5);
	CCLOG("Length:%i", box->getMaxLength());
	//设置输入模式
	box->setInputFlag(extension::kEditBoxInputFlagPassword);
	//    设置return类型
	box->setReturnType(extension::kKeyboardReturnTypeDone);
	box->setPosition(ccp(size.width*0.5, 220));
	addChild(box);
*/

	return true;
}

void StartScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	
	/**
	 * 处理窗口
	 */
	if (mainUI->touchDown(pos.x,pos.y)) return;
	MapManager::getMe().doTouch(UIBase::TOUCH_DOWN,pos);
	
}
void StartScene::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	if (mainUI->touchMove(pos.x,pos.y)) return;
	MapManager::getMe().doTouch(UIBase::TOUCH_MOVE,pos);
}
void StartScene::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	mainUI->touchEnd(pos.x,pos.y);
	MapManager::getMe().doTouch(UIBase::TOUCH_END,pos);
}
void StartScene::step(float dt)
{

}