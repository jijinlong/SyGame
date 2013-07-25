//------------------------------------------------------------------------
//
//	CCMD2Model - Quake 2 model (MD2) renderer for cocos2d-x
//
//	Licensed under the BSD license, see LICENSE in root for details.
// 
//	Copyright (c) 2012 James Hui (a.k.a. Dr.Watson)
// 
//	For latest updates, please visit http://cn.cocos2d-x.org/bbs
//
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "CCMD2Model.h"


MD2Animation::MD2Animation(int start, int end)
{
	mStartFrame = start;
	mEndFrame = end;
}



//-------------------------------------------------------------------------------------------------
CCMD2Model::CCMD2Model()
{
	

	int endFrames[] = { 39, 46, 60, 66, 73, 95, 112, 122, 135, 154, 161, 169, 177, 185, 190, 198 };
	int startFrame = 0;

	mAnimations = (MD2Animation **)malloc(sizeof(MD2Animation)*MAX_ANIMATION);
	for (int i=0;i<MAX_ANIMATION;i++)
	{
		mAnimations[i] = new MD2Animation(startFrame, endFrames[i]);
		startFrame = endFrames[i]+1;
	}

	mState = -1;
	mNextState = STATE_IDLE;

	mModel = NULL;
	mAnimationSpeed = 6.0f;

	uv = NULL;
	vertices = NULL;

}


//-------------------------------------------------------------------------------------------------
CCMD2Model::~CCMD2Model()
{
	if (mModel)
	{
	
		if (mModel->triIndex != NULL)
			free(mModel->triIndex);
		if (mModel->pointList != NULL)
			free(mModel->pointList);
		if (mModel->st != NULL)
			free(mModel->st);
	
		free(mModel);
	}

	if (mAnimations)
	{
		for (int i=0;i<MAX_ANIMATION;i++)
			delete mAnimations[i];

		free(mAnimations);
	}

	CC_SAFE_DELETE_ARRAY(uv);
	CC_SAFE_DELETE_ARRAY(vertices);
	
}


//-------------------------------------------------------------------------------------------------
// loads MD2 model
bool CCMD2Model::Load(char *filename, char *textureName)
{

	//FILE *filePtr;						// file pointer
	unsigned long fileLen = 0;			// length of model file
    //char *buffer;						// file buffer
		
	modelHeader_t *modelHeader;			// model header

	stIndex_t *stPtr;					// texture data
    frame_t *frame;						// frame data
	kmVec3 *pointListPtr;				// index variable
    mesh_t *triIndex, *bufIndexPtr;		// index variables
    int i, j;							// index variables

	// open the model file

	std::string path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(filename);

	//unsigned long nSize = 0;
	unsigned char* buffer = CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "rb", &fileLen);
    
	if (buffer == NULL)
		return false;

	//const char *path = filename;//GetPath(filename);
	/*filePtr = fopen(path, "rb");
	if (filePtr == NULL)
		return false;*/

	// find length of file
    //fseek(filePtr, 0, SEEK_END);
    //fileLen = ftell(filePtr);
    //fseek(filePtr, 0, SEEK_SET);

    //// read entire file into buffer
    //buffer = (char*)malloc(fileLen + 1);
    //fread(buffer, sizeof(char), fileLen, filePtr);

	// extract model file header from buffer
    modelHeader = (modelHeader_t*)buffer;

	// allocate memory for model data
   	mModel = (modelData_t*)malloc(sizeof(modelData_t));
	if (mModel == NULL)
    {
        CC_SAFE_DELETE_ARRAY(buffer);
		return false;
    }

	// allocate memory for all vertices used in model, including animations
    mModel->pointList = (kmVec3 *)malloc(sizeof(kmVec3)*modelHeader->numXYZ * modelHeader->numFrames);

	// store vital model data
    mModel->numPoints = modelHeader->numXYZ;
    mModel->numFrames = modelHeader->numFrames;
	mModel->frameSize = modelHeader->framesize;

    // loop number of frames in model file
    for(j = 0; j < modelHeader->numFrames; j++)
    {
       // offset to the points in this frame
       frame = (frame_t*)&buffer[modelHeader->offsetFrames + modelHeader->framesize * j];

	   // calculate the point positions based on frame details
       pointListPtr = (kmVec3 *)&mModel->pointList[modelHeader->numXYZ * j];
       for(i = 0; i < modelHeader->numXYZ; i++)
       {
          pointListPtr[i].x = frame->scale[0] * frame->fp[i].v[0] + frame->translate[0];
          pointListPtr[i].y = frame->scale[1] * frame->fp[i].v[1] + frame->translate[1];
          pointListPtr[i].z = frame->scale[2] * frame->fp[i].v[2] + frame->translate[2];
       }
    }
			 
	CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(textureName);
	if (tex)
		mModel->modelTex = tex;
	else
	{
		free(mModel);
		mModel = NULL;
		
		CC_SAFE_DELETE_ARRAY(buffer);
		//free(buffer);
		return false;
	}


	CCSize size = tex->getContentSizeInPixels();
	float texWidth = size.width;
	float texHeight = size.height;


    // allocate memory for the model texture coordinates
    mModel->st = (texCoord_t*)malloc(sizeof(texCoord_t)*modelHeader->numST);

	// store number of texture coordinates
    mModel->numST = modelHeader->numST;

	// set texture pointer to texture coordinate offset
    stPtr = (stIndex_t*)&buffer[modelHeader->offsetST];

	// calculate and store the texture coordinates for the model
    for (i = 0; i < modelHeader->numST; i++)
    {
		mModel->st[i].s = (float)stPtr[i].s / texWidth;
        mModel->st[i].t = (float)stPtr[i].t / texHeight;
    }

	// allocate an index of triangles
	triIndex = (mesh_t*)malloc(sizeof(mesh_t) * modelHeader->numTris);

	// set total number of triangles
	mModel->numTriangles = modelHeader->numTris;
	mModel->triIndex = triIndex;
	
	// point to triangle indexes in buffer
	bufIndexPtr = (mesh_t*)&buffer[modelHeader->offsetTris];

	// create a mesh (triangle) list
	for (j = 0; j < mModel->numFrames; j++)		
	{
		// for all triangles in each frame
		for(i = 0; i < modelHeader->numTris; i++)
		{
		   triIndex[i].meshIndex[0] = bufIndexPtr[i].meshIndex[0];
		   triIndex[i].meshIndex[1] = bufIndexPtr[i].meshIndex[1];
		   triIndex[i].meshIndex[2] = bufIndexPtr[i].meshIndex[2];
		   triIndex[i].stIndex[0] = bufIndexPtr[i].stIndex[0];
		   triIndex[i].stIndex[1] = bufIndexPtr[i].stIndex[1];
		   triIndex[i].stIndex[2] = bufIndexPtr[i].stIndex[2];
		}
	}

	// close file and free memory
	//fclose(filePtr);
    //free(buffer);
	CC_SAFE_DELETE_ARRAY(buffer);

	mModel->currentFrame = 0;
	mModel->nextFrame = 1;
	mModel->interpol = 0.0;

	uv = new float[mModel->numTriangles * 6];
	vertices = new float[mModel->numTriangles * 9];

	CheckNextState();

    return true;
}


void CCMD2Model::ReloadTexture(const char *textureName)
{
	CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(textureName);
	if (tex)
	{
		delete mModel->modelTex;
		mModel->modelTex = tex;
	}
}


//-------------------------------------------------------------------------------------------------
// given 3 points, calculates the normal to the points
void CCMD2Model::CalculateNormal(kmVec3 *normal, float *p1, float *p2, float *p3)
{
   float a[3], b[3], result[3];
   float length;

   a[0] = p1[0] - p2[0];
   a[1] = p1[1] - p2[1];
   a[2] = p1[2] - p2[2];

   b[0] = p1[0] - p3[0];
   b[1] = p1[1] - p3[1];
   b[2] = p1[2] - p3[2];

   result[0] = a[1] * b[2] - b[1] * a[2];
   result[1] = b[0] * a[2] - a[0] * b[2];
   result[2] = a[0] * b[1] - b[0] * a[1];

   // calculate the length of the normal
   length = (float)sqrt(result[0]*result[0] + result[1]*result[1] + result[2]*result[2]);

   if (length == 0.0f)
	   length = SMALLEST_FP;

   normal->x = result[0]/length;
   normal->y = result[1]/length;
   normal->z = result[2]/length;

}


//-------------------------------------------------------------------------------------------------
// render a single frame of a MD2 model
void CCMD2Model::Render(int frameNum)
{
	kmVec3 *pointList;

    // create a pointer to the frame we want to show
    pointList = &mModel->pointList[mModel->numPoints * frameNum];

	//CCRenderBox *renderBox = CCRenderBox::GetInstance();
	
	//renderBox->BindTexture(mModel->modelTex);

	ccGLBindTexture2D( mModel->modelTex->getName() );


	//float uv[mModel->numTriangles * 6];
	//float vertices[mModel->numTriangles * 9];
	
	int uvIdx = 0;
	int vertexIdx = 0;

	for(int i = 0; i < mModel->numTriangles; i++)
	{
		//CalculateNormal(&vertices[n].normal,
		//				pointList[mModel->triIndex[i].meshIndex[0]].v,
		//              pointList[mModel->triIndex[i].meshIndex[2]].v,
		//              pointList[mModel->triIndex[i].meshIndex[1]].v);
		
	
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[0]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[0]].t;
		
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[0]].x;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[0]].y;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[0]].z;

		//vertices[n].normal.x = vertices[n-1].normal.x;
		//vertices[n].normal.y = vertices[n-1].normal.y;
		//vertices[n].normal.z = vertices[n-1].normal.z;

		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[2]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[2]].t;

		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[2]].x;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[2]].y;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[2]].z;
		
		
		//vertices[n].normal.x = vertices[n-1].normal.x;
		//vertices[n].normal.y = vertices[n-1].normal.y;
		//vertices[n].normal.z = vertices[n-1].normal.z;
		
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[1]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[1]].t;

		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[1]].x;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[1]].y;
		vertices[vertexIdx++] = pointList[mModel->triIndex[i].meshIndex[1]].z;
	
	}

	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, uv);
	//glVertexPointer(3, GL_FLOAT, 0, vertices);
	//glTexCoordPointer(2, GL_FLOAT, 0, uv);
	glDrawArrays(GL_TRIANGLES, 0, mModel->numTriangles*3);
		
}


//-------------------------------------------------------------------------------------------------
void CCMD2Model::SetState(int newState)
{
	mNextState = newState;

}


//-------------------------------------------------------------------------------------------------
void CCMD2Model::CheckNextState()
{
	if (mState != mNextState)
	{
		mState = mNextState;
		mModel->currentFrame = mAnimations[mState]->mStartFrame;
		mModel->nextFrame = mAnimations[mState]->mStartFrame+1;
		mModel->interpol = 0.0f;
	}
}


void CCMD2Model::Update(float dt)
{

	mModel->interpol += mAnimationSpeed*dt;

	if (mModel->interpol >= 1.0)
	{
		mModel->interpol = 0.0f;

		int startFrame = mAnimations[mState]->mStartFrame;
		int endFrame = mAnimations[mState]->mEndFrame;

		if ( (startFrame < 0) || (endFrame < 0) )
			return;

		if ( (startFrame >= mModel->numFrames) || (endFrame >= mModel->numFrames) )
			return;

		mModel->currentFrame++;
		if (mModel->currentFrame >= endFrame)
			mModel->currentFrame = startFrame;

		mModel->nextFrame = mModel->currentFrame + 1;

		if (mModel->nextFrame >= endFrame)
		{
			mModel->nextFrame = startFrame;
			CheckNextState();
		}
	}

}


void CCMD2Model::SetAnimationSpeed(float speed)
{
	mAnimationSpeed = speed;
}


int CCMD2Model::GetPolygonCount()
{
	return mModel->numTriangles;
}


//-------------------------------------------------------------------------------------------------
// displays a frame of the model between startFrame and endFrame with an interpolation percent
void CCMD2Model::Render()
{

	CheckNextState();

	kmVec3 *pointList;			// current frame vertices
	kmVec3 *nextPointList;		// next frame vertices
	int i;						
	float x1, y1, z1;				// current frame point values
	float x2, y2, z2;				// next frame point values

	kmVec3 vertex[3];	

	if (mModel == NULL)
		return;
	
	pointList = &mModel->pointList[mModel->numPoints*mModel->currentFrame];
	nextPointList = &mModel->pointList[mModel->numPoints*mModel->nextFrame];
	
	//CCRenderBox *renderBox = CCRenderBox::GetInstance();
	
	//renderBox->BindTexture(mModel->modelTex);
	ccGLBindTexture2D( mModel->modelTex->getName() );

	//float uv[mModel->numTriangles * 6];
	//float vertices[mModel->numTriangles * 9];
	
	int uvIdx = 0;
	int vertexIdx = 0;

	for (i = 0; i < mModel->numTriangles; i++)
	{
		// get first points of each frame
		x1 = pointList[mModel->triIndex[i].meshIndex[0]].x;
		y1 = pointList[mModel->triIndex[i].meshIndex[0]].y;
		z1 = pointList[mModel->triIndex[i].meshIndex[0]].z;
		x2 = nextPointList[mModel->triIndex[i].meshIndex[0]].x;
		y2 = nextPointList[mModel->triIndex[i].meshIndex[0]].y;
		z2 = nextPointList[mModel->triIndex[i].meshIndex[0]].z;

		// store first interpolated vertex of triangle
		vertex[0].x = x1 + mModel->interpol * (x2 - x1);
		vertex[0].y = y1 + mModel->interpol * (y2 - y1);
		vertex[0].z = z1 + mModel->interpol * (z2 - z1);
	
		// get second points of each frame
		x1 = pointList[mModel->triIndex[i].meshIndex[2]].x;
		y1 = pointList[mModel->triIndex[i].meshIndex[2]].y;
		z1 = pointList[mModel->triIndex[i].meshIndex[2]].z;
		x2 = nextPointList[mModel->triIndex[i].meshIndex[2]].x;
		y2 = nextPointList[mModel->triIndex[i].meshIndex[2]].y;
		z2 = nextPointList[mModel->triIndex[i].meshIndex[2]].z;

		// store second interpolated vertex of triangle
		vertex[2].x = x1 + mModel->interpol * (x2 - x1);
		vertex[2].y = y1 + mModel->interpol * (y2 - y1);
		vertex[2].z = z1 + mModel->interpol * (z2 - z1);	

		// get third points of each frame
		x1 = pointList[mModel->triIndex[i].meshIndex[1]].x;
		y1 = pointList[mModel->triIndex[i].meshIndex[1]].y;
		z1 = pointList[mModel->triIndex[i].meshIndex[1]].z;
		x2 = nextPointList[mModel->triIndex[i].meshIndex[1]].x;
		y2 = nextPointList[mModel->triIndex[i].meshIndex[1]].y;
		z2 = nextPointList[mModel->triIndex[i].meshIndex[1]].z;

		// store third interpolated vertex of triangle
		vertex[1].x = x1 + mModel->interpol * (x2 - x1);
		vertex[1].y = y1 + mModel->interpol * (y2 - y1);
		vertex[1].z = z1 + mModel->interpol * (z2 - z1);


		//CalculateNormal(&vertices[n].normal,
		//				 vertex[0].v,
		//               vertex[2].v,
		//               vertex[1].v);
		
		
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[0]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[0]].t;
		
		vertices[vertexIdx++] = vertex[0].x;
		vertices[vertexIdx++] = vertex[0].y;
		vertices[vertexIdx++] = vertex[0].z;

		//vertices[n].normal.x = vertices[n-1].normal.x;
		//vertices[n].normal.y = vertices[n-1].normal.y;
		//vertices[n].normal.z = vertices[n-1].normal.z;

		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[2]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[2]].t;

		vertices[vertexIdx++] = vertex[2].x;
		vertices[vertexIdx++] = vertex[2].y;
		vertices[vertexIdx++] = vertex[2].z;
	
		
		//vertices[n].normal.x = vertices[n-1].normal.x;
		//vertices[n].normal.y = vertices[n-1].normal.y;
		//vertices[n].normal.z = vertices[n-1].normal.z;
		
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[1]].s;
		uv[uvIdx++] = mModel->st[mModel->triIndex[i].stIndex[1]].t;

		vertices[vertexIdx++] = vertex[1].x;
		vertices[vertexIdx++] = vertex[1].y;
		vertices[vertexIdx++] = vertex[1].z;

	}
	
	//glVertexPointer(3, GL_FLOAT, 0, vertices);
	//glTexCoordPointer(2, GL_FLOAT, 0, uv);
	//glDrawArrays(GL_TRIANGLES, 0, mModel->numTriangles*3);

	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, 0, uv);
	
	glDrawArrays(GL_TRIANGLES, 0, mModel->numTriangles*3);

}

