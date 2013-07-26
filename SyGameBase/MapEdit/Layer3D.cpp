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

#include "Layer3D.h"

#include "CCMD2Model.h"


Layer3D::Layer3D()
{
	mModel = NULL;
	mGun = NULL;

	mTerran = NULL;
	mTerranGun = NULL;

}


Layer3D::~Layer3D()
{
	CC_SAFE_DELETE(mModel);
	CC_SAFE_DELETE(mGun);

	CC_SAFE_DELETE(mTerran);
	CC_SAFE_DELETE(mTerranGun);


}


// on "init" you need to initialize your instance
bool Layer3D::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

		mTexture = CCTextureCache::sharedTextureCache()->addImage("HelloWorld.png");

		CCGLProgram* program = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTexture);
		setShaderProgram(program);

		CCScheduler *s = CCDirector::sharedDirector()->getScheduler();
		s->scheduleUpdateForTarget(this, 0, false);

		mSpeed = 80;

		mYaw = 0;
		mPitch = 90.0f;
		mRoll = 0;

        bRet = true;

		mState = STATE_IDLE;
		mTimer = 0;

		mModel = new CCMD2Model();
		mModel->Load("tris.md2", "abarlith.png");

		mGun = new CCMD2Model();
		mGun->Load("weapon.md2", "weapon.png");

		mTerran = new CCMD2Model();
		mTerran->Load("terran.md2", "terran.png");

		mTerranGun = new CCMD2Model();
		mTerranGun->Load("terran_weapon.md2", "terran_weapon.png");


    } while (0);

    return bRet;
}


void Layer3D::update(float dt)
{
	if (dt > 0.0167f)
		dt = 0.0167f;

	mYaw += dt*mSpeed;
	mPitch += dt*mSpeed;
	mRoll += dt*mSpeed;

	mTimer += dt;
	if (mTimer > 10.0f)
	{
		mTimer = 0;
		mState = mState+1;
		if (mState >= MAX_ANIMATION)
			mState = STATE_IDLE;

		mModel->SetState(mState);
		mGun->SetState(mState);

		mTerran->SetState(mState);
		mTerranGun->SetState(mState);

	}


	mModel->Update(dt);
	mGun->Update(dt);

	mTerran->Update(dt);
	mTerranGun->Update(dt);

}


void Layer3D::draw()
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
	kmQuaternionRotationYawPitchRoll(&quat, mYaw, mPitch, mRoll);

	kmMat3 rotation;
	kmMat3RotationQuaternion(&rotation, &quat);

	kmVec3 translation;
	kmVec3Fill(&translation, size.width/2, size.height/2.2f, 0);

	kmMat4 rotationAndMove;
	kmMat4RotationTranslation(&rotationAndMove, &rotation, &translation);

    kmMat4Multiply(&matrixMVP, &matrixP, &matrixMV);
	kmMat4Multiply(&matrixMVP, &matrixMVP, &rotationAndMove);				// apply rotation and translation to the matrix

	GLuint matrixId = glGetUniformLocation(getShaderProgram()->getProgram(), "u_MVPMatrix");
    getShaderProgram()->setUniformLocationwithMatrix4fv(matrixId, matrixMVP.mat, 1);

	// texture for the box	
    ccGLBindTexture2D( mTexture->getName() );

	ccVertex3F vertices[4];
	ccVertex2F uv[4];

	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, uv);

	float x = 0;
	float y = 0;
	float len = 40*scale;

	/////////// front
	vertices[0] = vertex3(x-len,y-len,len);		
	vertices[1] = vertex3(x-len,y+len,len);
	vertices[2] = vertex3(x+len,y-len,len);
	vertices[3] = vertex3(x+len,y+len,len);

	uv[0] = vertex2(0, 1);
	uv[1] = vertex2(0, 0);
	uv[2] = vertex2(1, 1);
	uv[3] = vertex2(1, 0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	////////// right
	vertices[0] = vertex3(x+len,y-len,len);			
	vertices[1] = vertex3(x+len,y+len,len);
	vertices[2] = vertex3(x+len,y-len,-len);
	vertices[3] = vertex3(x+len,y+len,-len);

	uv[0] = vertex2(0, 1);
	uv[1] = vertex2(0, 0);
	uv[2] = vertex2(1, 1);
	uv[3] = vertex2(1, 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	///////// back
	vertices[0] = vertex3(x+len,y-len,-len);	
	vertices[1] = vertex3(x+len,y+len,-len);
	vertices[2] = vertex3(x-len,y-len,-len);
	vertices[3] = vertex3(x-len,y+len,-len);

	uv[0] = vertex2(0, 1);
	uv[1] = vertex2(0, 0);
	uv[2] = vertex2(1, 1);
	uv[3] = vertex2(1, 0);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	////////// left
	vertices[0] = vertex3(x-len,y-len,len);			
	vertices[1] = vertex3(x-len,y+len,len);
	vertices[2] = vertex3(x-len,y-len,-len);
	vertices[3] = vertex3(x-len,y+len,-len);

	uv[0] = vertex2(0, 1);
	uv[1] = vertex2(0, 0);
	uv[2] = vertex2(1, 1);
	uv[3] = vertex2(1, 0);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	

	///////// top
	vertices[0] = vertex3(x+len,y+len,len);	
	vertices[1] = vertex3(x-len,y+len,len);
	vertices[2] = vertex3(x+len,y+len,-len);
	vertices[3] = vertex3(x-len,y+len,-len);

	uv[0] = vertex2(0, 0);
	uv[1] = vertex2(1, 0);
	uv[2] = vertex2(0, 1);
	uv[3] = vertex2(1, 1);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	///////// bottom
	vertices[0] = vertex3(x+len,y-len,len);	
	vertices[1] = vertex3(x-len,y-len,len);
	vertices[2] = vertex3(x+len,y-len,-len);
	vertices[3] = vertex3(x-len,y-len,-len);

	uv[0] = vertex2(0, 0);
	uv[1] = vertex2(1, 0);
	uv[2] = vertex2(0, 1);
	uv[3] = vertex2(1, 1);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


	//////////////// render first MD2 models
	kmQuaternionRotationYawPitchRoll(&quat, 0, 90, mRoll);

	kmMat3RotationQuaternion(&rotation, &quat);

	kmVec3Fill(&translation, size.width/2-scale*35, size.height/2.2f, 200*scale);

	kmMat4RotationTranslation(&rotationAndMove, &rotation, &translation);

    kmMat4Multiply(&matrixMVP, &matrixP, &matrixMV);
	kmMat4Multiply(&matrixMVP, &matrixMVP, &rotationAndMove);

    getShaderProgram()->setUniformLocationwithMatrix4fv(matrixId, matrixMVP.mat, 1);

	mModel->Render();
	mGun->Render();

	//////////////// render second MD2 models
	kmVec3Fill(&translation, size.width/2+scale*35, size.height/2.2f, 200*scale);

	kmMat4RotationTranslation(&rotationAndMove, &rotation, &translation);

    kmMat4Multiply(&matrixMVP, &matrixP, &matrixMV);
	kmMat4Multiply(&matrixMVP, &matrixMVP, &rotationAndMove);

    getShaderProgram()->setUniformLocationwithMatrix4fv(matrixId, matrixMVP.mat, 1);

	mTerran->Render();
	mTerranGun->Render();

    CC_INCREMENT_GL_DRAWS(1);


}


