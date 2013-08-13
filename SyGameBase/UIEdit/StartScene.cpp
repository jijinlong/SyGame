#include "UIWindow.h"
#include "StartScene.h"
#include "StartDialog.h"
#include <pthread.h>
#include "PngPack.h"
USING_NS_CC;

CCScene* StartScene::scene()
{
    CCScene *scene = CCScene::create();
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
   
	//startDialog = StartDialog::create(window,"startui.xml");
	
	/**
	 * 操作界面
	 */
	MainDialog *mainDialog = MainDialog::create(window,"mainui.xml");
	
	/**
	 * 保存界面
	 */
	SavePanelDialog *saveDialog = SavePanelDialog::create(window,"savedialog.xml");
	saveDialog->setVisible(false);
	
	/**
	 * 属性界面
	 */
	PropDialog *propDialog = PropDialog::create(window,"prop.xml");
	

	this->schedule(schedule_selector(StartScene::step), 0.75f); 
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
	
}
void StartScene::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	if (window->touchMove(pos.x,pos.y)) return;
}
void StartScene::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
	CCTouch* touch = (CCTouch*)(* pTouches->begin());
    CCPoint pos = touch->getLocation();
	/**
	 * 处理窗口
	 */
	window->touchEnd(pos.x,pos.y);
}
void StartScene::step(float dt)
{

}