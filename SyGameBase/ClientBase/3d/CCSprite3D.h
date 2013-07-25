/****************************************************************************

Copyright (c) 2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCSPRITE3D_H__
#define __CCSPRITE3D_H__

#include "base_nodes/CCNode.h"
#include "kazmath/vec3.h"
#include "CCMD2Model.h"
/**
 * @addtogroup Sprite3D
 * @{
 */

NS_CC_BEGIN

class CCSprite3D : public CCNode
{
public:
    CCSprite3D()
	{
		mModel = NULL;
		mYaw = 0;
		mPitch = 90.0f;
		mRoll = 0;
		mState = STATE_IDLE;
		mTimer = 0;
		mSpeed = 50;
	}
    virtual ~CCSprite3D()
	{
	}
    
    static CCSprite3D* create(const char* fileName, const char* textureName);
    virtual bool init(const char* fileName, const char* textureName);

    void setModel(CCMD2Model* pModel);
    CCMD2Model* getModel();
	CCMD2Model *mModel;

	void draw();

	float mYaw;
	float mPitch;
	float mRoll;

	float mSpeed;
	int mState;
	float mTimer;

	float mScale;
	virtual void update(float dt);
};

NS_CC_END

// end of Network group
/// @}

#endif // __CCSPRITE3D_H__