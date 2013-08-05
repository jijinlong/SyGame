#include "LocalSprite.h"

NS_CC_BEGIN
void LocalSprite::initWithName(const char *pngName,FileSet *fileSet)
{
	CCTexture2D * texture = NULL;
	std::string pathKey = pngName;

	pathKey = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(pathKey.c_str());
	texture = (CCTexture2D*)CCTextureCache::sharedTextureCache()->m_pTextures->objectForKey(pathKey.c_str());

	std::string fullpath = pathKey; // (CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(path));
//	if( ! texture ) 
	{
		std::string lowerCase(pngName);
		for (unsigned int i = 0; i < lowerCase.length(); ++i)
		{
			lowerCase[i] = tolower(lowerCase[i]);
		}
		// all images are handled by UIImage except PVR extension that is handled by our own handler
		do 
		{
			{
				bool needdes = false;
				CCImage::EImageFormat eImageFormat = CCImage::kFmtUnKnown;
					if (std::string::npos != lowerCase.find(".png"))
				{
					eImageFormat = CCImage::kFmtPng;
				}
				else
				{
					return;
				}
				
				CCImage image;     
				
				unsigned int nSize = 0;
				unsigned char* pBuffer = fileSet->getFileData(pngName, nSize);
				if (needdes)
				{
				}
				if (! image.initWithImageData((void*)pBuffer, nSize, eImageFormat))
				{
					return;
				}
				else
				{
				}                

				CCTexture2D * texture = new CCTexture2D();
                
				if( texture &&
					texture->initWithImage(&image) )
				{
					CCTextureCache::sharedTextureCache()->m_pTextures->setObject(texture, pathKey.c_str());
						CCRect rect = CCRectZero;
					rect.size = texture->getContentSize();
					initWithTexture(texture, rect);
					texture->release();
				}
				else
				{
					CCLOG("cocos2d: Couldn't add image:%s in CCTextureCache", path);
				}
			}
		} while (0);
	}
}
void LocalSpriteFrame::initWithName(const char *pngName,FileSet *fileSet)
{
	CCTexture2D * texture = NULL;
	std::string pathKey = pngName;

	pathKey = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(pathKey.c_str());
	texture = (CCTexture2D*)CCTextureCache::sharedTextureCache()->m_pTextures->objectForKey(pathKey.c_str());

	std::string fullpath = pathKey; // (CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(path));
	//if( ! texture ) 
	{
		std::string lowerCase(pngName);
		for (unsigned int i = 0; i < lowerCase.length(); ++i)
		{
			lowerCase[i] = tolower(lowerCase[i]);
		}
		// all images are handled by UIImage except PVR extension that is handled by our own handler
		do 
		{
			{
				bool needdes = false;
				CCImage::EImageFormat eImageFormat = CCImage::kFmtUnKnown;
					if (std::string::npos != lowerCase.find(".png"))
				{
					eImageFormat = CCImage::kFmtPng;
				}
				else
				{
					return;
				}
				
				CCImage image;     
				
				unsigned int nSize = 0;
				unsigned char* pBuffer = fileSet->getFileData(pngName, nSize);
				if (needdes)
				{
				//	CEncrypt encode;
				//encode.setEncMethod(CEncrypt::ENCDEC_DES);
				//				const_ZES_cblock key = {1,0,0,1,0,1,1};
				//				encode.set_key_des(&key);
				//				encode.encdec(pBuffer,nSize,false);
				}
				if (! image.initWithImageData((void*)pBuffer, nSize, eImageFormat))
				{
				//	CC_SAFE_DELETE_ARRAY(pBuffer);
					return;
				}
				else
				{
				//	CC_SAFE_DELETE_ARRAY(pBuffer);
				}                

				CCTexture2D * texture = new CCTexture2D();
                
				if( texture &&
					texture->initWithImage(&image) )
				{
					CCTextureCache::sharedTextureCache()->m_pTextures->setObject(texture, pathKey.c_str());
						CCRect rect = CCRectZero;
					rect.size = texture->getContentSize();
					CCRect rectInPixels = CC_RECT_POINTS_TO_PIXELS(rect);
					initWithTexture(texture, rectInPixels, false, CCPointZero, rectInPixels.size);
				}
				else
				{
					CCLOG("cocos2d: Couldn't add image:%s in CCTextureCache", path);
				}
			}
		} while (0);
	}
}
NS_CC_END