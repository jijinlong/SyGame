#include "MutiImage.h"
#include <png.hpp>
NS_CC_BEGIN
MutiImage * MutiImage::create(script::tixmlCodeNode *node)
{
	MutiImage *image = new MutiImage();
	if (image)
	{
		image->readNode(node);
		image->initWithFile(image->pngName.c_str());
		image->rebuild();
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
MutiImage * MutiImage::create()
{
	MutiImage *image = new MutiImage();
	if (image)
	{
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
/**
* 从配置文件中读取信息
*/
void MutiImage::readNode(script::tixmlCodeNode *node)
{
	MutiObject::readNode(node);
	pngName = node->getAttr("src");
}
/**
* 将信息写入节点当中
*/
TiXmlElement * MutiImage::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *imageNode = MutiObject::writeNode(parent,"image");
	if (imageNode)
	{
		imageNode->SetAttribute("src",pngName);
	}
	return imageNode;
}
void MutiImage::rebuild()
{
	initWithFile(pngName.c_str());
}
bool MutiImage::checkIn(const CCPoint &point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	float width = getContentSize().width * getScaleX();
	float height = getContentSize().height * getScaleY();
	float x = 0;
	float y = 0;
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}
MutiBigImage* MutiBigImage::create(script::tixmlCodeNode *node)
{
	MutiBigImage *image = new MutiBigImage();
	if (image)
	{
		image->readNode(node);
		image->rebuild();
		image->autorelease();
		return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
MutiBigImage* MutiBigImage::create(const char *pngName)
{
	MutiBigImage *image = new MutiBigImage();
	if (image && image->init(pngName))
	{
		 return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
bool MutiBigImage::init(const char *pngName)
{
	CCSprite::init();
	this->pngName = pngName;
	bool saveTemp = true;
	png::image< png::rgba_pixel > img;
	img.read(pngName);  
	
	std::vector<png::image< png::rgba_pixel> > tmpImgs;
	int width_size = img.get_width() / 512;
	int width_index = img.get_width() % 512;
	if (width_index)
	{
		width_size ++;
	}
	int width_pixel_width = img.get_width() / width_size; // 每个子图片的宽

	int height_size = img.get_height() / 512;
	int height_index = img.get_height() % 512;
	if (height_index)
	{
		height_size ++;
	}
	int height_pixel_height = img.get_height() / height_size; // 每个字图片的高
	offset = ccp(width_pixel_width/2,height_pixel_height/2);
	tmpImgs.resize(width_size * height_size);
	for (int i = 0; i < tmpImgs.size(); i++)
	{
		tmpImgs[i].resize(width_pixel_width,height_pixel_height);
	}
	for (int i = 0 ;i < img.get_width();i++)
		for (int j = 0; j < img.get_height();j++)
		{
			int imgId = i / width_pixel_width + (j / height_pixel_height) * width_size;
			tmpImgs[imgId].set_pixel(i % width_pixel_width,j % height_pixel_height,img.get_pixel(i,j));
		}
	for (int i = 0; i < tmpImgs.size();i++)
	{
		CCImage image; 
		png::image< png::rgba_pixel >& pImage = tmpImgs.at(i);
		std::stringstream buffer;
		pImage.write_stream(buffer);
		image.initWithImageData((void*)buffer.str().c_str(),buffer.str().size(),CCImage::kFmtPng);
		CCTexture2D* texture = new CCTexture2D();
        int y = i / width_size;
		int x = i % width_size;      
        if( texture &&
            texture->initWithImage(&image) )
        {
			if (texture)
			{
				CCRect rect = CCRectZero;
				rect.size = texture->getContentSize();
				CCSprite *sprite = CCSprite::create();
				sprite->initWithTexture(texture, rect);
				
				this->addChild(sprite);
				sprite->setPosition(ccp(offset.x + x * width_pixel_width,img.get_height() - y * height_pixel_height - offset.y));
			}
		}
		if (saveTemp)
		{
			std::stringstream pngNameC;
			pngNameC << "temps" << x <<"_"<< y << pngName;
			pImage.write(pngNameC.str().c_str());
		}
	}
	if (saveTemp)
	{
		saveToXml(width_pixel_width,offset,img.get_height(),height_pixel_height,pngName,width_size,tmpImgs.size());
	}
	// 尝试创建一个info.xml 来说明该分割的文件
	return true;
}
void MutiBigImage::saveToXml(float width_pixel_width,const CCPoint &offset,float image_height,float height_pixel_height,const char *pngName,int width_size,int imgSize)
{
	TiXmlDocument *pDoc=new TiXmlDocument; //定义一个文档的指针
	//添加一个xml头。
	TiXmlDeclaration *pDeclaration=new TiXmlDeclaration("1.0","UTF-8","");
	pDoc->LinkEndChild(pDeclaration);
	//添加XMl的根节点
	TiXmlElement *configNode= new TiXmlElement("Config");
	pDoc->LinkEndChild(configNode);

	TiXmlElement *imageNode= new TiXmlElement("image");
	configNode->LinkEndChild(imageNode);
	
	imageNode->SetAttribute("width_pixel_width",width_pixel_width);
	imageNode->SetAttribute("offsetx",offset.x);
	imageNode->SetAttribute("offsety",offset.y);
	imageNode->SetAttribute("height_pixel_height",height_pixel_height);
	imageNode->SetAttribute("width_size",width_size);
	imageNode->SetAttribute("image_height",image_height);
	imageNode->SetAttribute("imgsize",imgSize);
	imageNode->SetAttribute("pngname",pngName);
	std::stringstream fileName;
	fileName << pngName <<"xmlext";
	pDoc->SaveFile(fileName.str());
}

MutiBigImage* MutiBigImage::createFromXml(const  char *pngName)
{
	MutiBigImage *image = new MutiBigImage();
	if (image && image->initFromXml(pngName))
	{
		 return image;
	}
	CC_SAFE_DELETE(image);
	return NULL;
}
bool MutiBigImage::initFromXml(const char *pngName)
{
	CCSprite::init();
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(pngName);
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return false;
	if (script::tixmlCode::initFromString((char*)buffer))
	{
		return true;
	}
	return false;
}

void MutiBigImage::takeNode(script::tixmlCodeNode *node)
{
	if (node)
	{
		script::tixmlCodeNode imageNode = node->getFirstChildNode("image");
		if (imageNode.isValid())
		{
			float width_pixel_width = imageNode.getFloat("width_pixel_width");
			float height_pixel_height = imageNode.getFloat("height_pixel_height");
			offset.x = imageNode.getFloat("offsetx");
			offset.y = imageNode.getFloat("offsety");
			int width_size = imageNode.getInt("width_size");
			int image_height = imageNode.getInt("image_height");
			int imgSize = imageNode.getInt("imgsize");
			std::string pngName = imageNode.getAttr("pngname");
			for (int i = 0; i < imgSize;i++)
			{
				int y = i / width_size;
				int x = i % width_size;      
				std::stringstream name;
				name << "temps" << x <<"_"<< y << pngName;
				CCSprite * sprite = CCSprite::create(name.str().c_str());
				this->addChild(sprite);
				sprite->setPosition(ccp(offset.x + x * width_pixel_width,image_height - y * height_pixel_height - offset.y));
			}
		}
	}
}
/**
 * 从配置文件中读取信息
 */
void MutiBigImage::readNode(script::tixmlCodeNode *node)
{
	MutiObject::readNode(node);
	pngName = node->getAttr("src");
}
/**
 * 将信息写入节点当中
 */
TiXmlElement * MutiBigImage::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *imageNode = MutiObject::writeNode(parent,"bigimage");
	if (imageNode)
	{
		imageNode->SetAttribute("src",pngName.c_str());
	}
	return imageNode;
}

bool MutiBigImage::checkIn(const CCPoint &point)
{
	return false;
}
void MutiBigImage::rebuild()
{
	std::stringstream fileName;
	fileName << pngName << "xmlext";
	initFromXml(fileName.str().c_str());
}
NS_CC_END