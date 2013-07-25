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

#include "CCSprite3D.h"
#include "CCDirector.h"
#include "kazmath/GL/matrix.h"
#include "shaders/CCShaderCache.h"
#include "effects/CCGrid.h"
#include "support/CCPointExtension.h"
#include "CCMD2Model.h"
NS_CC_BEGIN
CCSprite3D* CCSprite3D::create(const char* fileName, const char* textureName)
{
	CCSprite3D *d3sprite = new CCSprite3D();
	if (d3sprite && d3sprite->init(fileName,textureName))
	{
		d3sprite->autorelease();
		return d3sprite;
	}
	CC_SAFE_DELETE(d3sprite);
	return NULL;
}
bool CCSprite3D::init(const char* fileName, const char* textureName)
{
	CCGLProgram* program = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTexture);
	setShaderProgram(program);
	mModel = new CCMD2Model();
	mModel->Load((char*)fileName,(char*)textureName);
	CCScheduler *s = CCDirector::sharedDirector()->getScheduler();
	s->scheduleUpdateForTarget(this, 0, false);
	mModel->SetState(STATE_RUNNING);
	return true;
}
void CCSprite3D::update(float dt)
{
	if (dt > 0.0167f)
		dt = 0.0167f;

	//mYaw += dt*mSpeed;
	//mPitch += dt*mSpeed;
	//mRoll += dt*mSpeed;
	//mModel->SetState(STATE_RUNNING);
	mTimer += dt;
	if (mTimer > 10.0f)
	{
		mTimer = 0;
		mState = mState+1;
		if (mState >= MAX_ANIMATION)
			mState = STATE_IDLE;

	//	mModel->SetState(mState);
	}


	mModel->Update(dt);
}
void CCSprite3D::draw()
{
	CCDirector::sharedDirector()->setDepthTest(true);

	ccGLEnableVertexAttribs(kCCVertexAttribFlag_Position | kCCVertexAttribFlag_TexCoords );

	getShaderProgram()->use();

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	
	float scale = size.width/480.0f;

	kmMat4 matrixP;
    kmMat4 matrixMV;
    kmMat4 matrixMVP;

    kmGLGetMatrix(KM_GL_PROJECTION, &matrixP );
    kmGLGetMatrix(KM_GL_MODELVIEW, &matrixMV );

	kmQuaternion quat;

	kmMat3 rotation;

	kmVec3 translation;

	kmMat4 rotationAndMove;
	
	GLuint matrixId = glGetUniformLocation(getShaderProgram()->getProgram(), "u_MVPMatrix");
// 开始处理模型的渲染

	kmQuaternionRotationYawPitchRoll(&quat, 0, 90, mRoll);

	kmMat3RotationQuaternion(&rotation, &quat);

	kmVec3Fill(&translation, size.width/2-scale*35, size.height/2.2f, 200*scale);

	kmMat4RotationTranslation(&rotationAndMove, &rotation, &translation);

    kmMat4Multiply(&matrixMVP, &matrixP, &matrixMV);
	kmMat4Multiply(&matrixMVP, &matrixMVP, &rotationAndMove);

    getShaderProgram()->setUniformLocationwithMatrix4fv(matrixId, matrixMVP.mat, 1);

	if (mModel)
	{
		mModel->Render();
	}

    CC_INCREMENT_GL_DRAWS(1);
}
NS_CC_END
