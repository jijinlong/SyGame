//------------------------------------------------------------------------
//
//	Layer3D - Use cocos2d-x to render simple 3D objects.
//
//	Licensed under the BSD license, see LICENSE in root for details.
// 
//	Copyright (c) 2012 James Hui (a.k.a. Dr.Watson)
// 
//	For latest updates, please visit http://cn.cocos2d-x.org/bbs
//
//------------------------------------------------------------------------

#ifndef __LAYER3D_H__
#define __LAYER3D_H__

#include "cocos2d.h"

using namespace cocos2d;

class CCMD2Model;

class Layer3D : public cocos2d::CCLayer
{
public:

	Layer3D();
	virtual ~Layer3D();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // implement the "static node()" method manually
    CREATE_FUNC(Layer3D);

	virtual void draw();

	virtual void update(float dt);

private:
	cocos2d::CCSprite* pSprite;

	cocos2d::CCTexture2D *mTexture;

	

	float mYaw;
	float mPitch;
	float mRoll;

	CCMD2Model *mModel;
	CCMD2Model *mGun;

	CCMD2Model *mTerran;
	CCMD2Model *mTerranGun;
	float mSpeed;
	int mState;
	float mTimer;

	float mScale;

};

#endif 
