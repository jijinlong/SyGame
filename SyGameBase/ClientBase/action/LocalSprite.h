#pragma once
#include "cocos2d.h"
#include "FileSet.h"
NS_CC_BEGIN
class LocalSprite:public CCSprite{
public:
	static LocalSprite * create(const char *pngName,FileSet *fileSet)
	{
		LocalSprite *image = new LocalSprite();
		if (image)
		{
			image->initWithName(pngName,fileSet);
			return image;
		}
		CC_SAFE_DELETE(image);
		return NULL;
	}
	void initWithName(const char *pngName,FileSet *fileSet);	
};
class LocalSpriteFrame:public CCSpriteFrame{
public:
	static LocalSpriteFrame * create(const char *pngName,FileSet *fileSet)
	{
		LocalSpriteFrame *image = new LocalSpriteFrame();
		if (image)
		{
			image->initWithName(pngName,fileSet);
			return image;
		}
		CC_SAFE_DELETE(image);
		return NULL;
	}
	void initWithName(const char *pngName,FileSet *fileSet);	
};
NS_CC_END