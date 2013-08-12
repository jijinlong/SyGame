#pragma once
#include "UIScrollView.h"
#include "UIMain.h"
#include "UIWindow.h"
#include "UIValue.h"
/**
 * ¿ªÊ¼³¡¾°
 **/
class StartScene: public cocos2d::CCLayer{
public:
	 // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // touch callback
    void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    void ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);

	CREATE_FUNC(StartScene);
	
	UIMain *mainUI;
	void step(float dt);
private:
	StartScene()
	{
		mainUI = NULL;
	}
};
