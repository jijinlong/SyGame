#include "MutiImage.h"
#include <png.hpp>
#include "FileSet.h"
#include "LocalSprite.h"
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
	size = CCSizeMake(img.get_width(),img.get_height());
	if (height_index)
	{
		height_size ++;
	}
	int height_pixel_height = img.get_height() / height_size; // 每个字图片的高
	offset = ccp(width_pixel_width/2,height_pixel_height/2);
	tmpImgs.resize(width_size * height_size + 1);
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
	FileSet fileSet;
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
			{
			std::stringstream pngNameC;
			pngNameC << "temps" << x <<"_"<< y << pngName;
			fileSet.addFile(pngNameC.str());
			}
			{
			std::stringstream pngNameC;
			pngNameC << "tmp\\temps" << x <<"_"<< y << pngName;
			pImage.write(pngNameC.str().c_str());
			}
		}
	}

	if (saveTemp)
	{
		saveToXml(width_pixel_width,offset,img.get_height(),height_pixel_height,pngName,width_size,tmpImgs.size());
		std::stringstream setInfo;
		setInfo<<pngName;
		fileSet.save(setInfo.str().c_str());
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
	imageNode->SetAttribute("fileset","true");
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
			std::string fileSetName = imageNode.getAttr("fileset");
			FileSet fileSet;
			if (fileSetName == "true")
			{
				fileSet.createFromFile(pngName.c_str());
			}
			for (int i = 0; i < imgSize;i++)
			{
				int y = i / width_size;
				int x = i % width_size;      
				std::stringstream name;
				name << "temps" << x <<"_"<< y << pngName;
				CCSprite * sprite = NULL;
				if (fileSetName != "true")
				{
					sprite = CCSprite::create(name.str().c_str());
					this->addChild(sprite);
				}
				else
				{
					sprite = LocalSprite::create(name.str().c_str(),&fileSet);
					this->addChild(sprite);
				}
				if (sprite)
					sprite->setPosition(ccp(offset.x + x * width_pixel_width,image_height - y * height_pixel_height - offset.y));
			}
			size = CCSizeMake(width_pixel_width * width_size,image_height);
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
	CCPoint pos = this->convertToNodeSpace(point);
	float width = size.width;
	float height = size.height;
	float x = 0;
	float y = 0;
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}
void MutiBigImage::rebuild()
{
	std::stringstream fileName;
	fileName << pngName << "xmlext";
	initFromXml(fileName.str().c_str());
}

/**
* 大地表的实现
**/
/**
 * 创建一个地表
 */
MutiBigTerrain* MutiBigTerrain::create(const char *fileName,int width,int height)
{
	MutiBigTerrain *mapb = new MutiBigTerrain();
	mapb->_width = width;
	mapb->_height = height;
    if (mapb && mapb->initWithFile(fileName))
    {
        mapb->autorelease();
        return mapb;
    }
    CC_SAFE_DELETE(mapb);
    return NULL;
}

/**
 * 使用纹理初始化
 */
bool MutiBigTerrain::initWithTexture(CCTexture2D *pTexture, const CCRect& rect, bool rotated)
{
	 m_pobBatchNode = NULL;
    // shader program
    setShaderProgram(CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor));

    m_bRecursiveDirty = false;
    setDirty(false);

    m_bOpacityModifyRGB = true;
    m_nOpacity = 255;
    m_sColor = m_sColorUnmodified = ccWHITE;

    m_sBlendFunc.src = CC_BLEND_SRC;
    m_sBlendFunc.dst = CC_BLEND_DST;

    m_bFlipX = m_bFlipY = false;

    // default transform anchor: center
    setAnchorPoint(ccp(0.5f, 0.5f));

    // zwoptex default values
    m_obOffsetPosition = CCPointZero;

    m_bHasChildren = false;
    
    // clean the Quad
    memset(&m_sQuad, 0, sizeof(m_sQuad));

    // update texture (calls updateBlendFunc)
    setTexture(pTexture);
    setTextureRect(rect, rotated, rect.size);

    // by default use "Self Render".
    // if the sprite is added to a batchnode, then it will automatically switch to "batchnode Render"
    setBatchNode(NULL);

    return true;
}
/**
 * 设置数据
 */
 void MutiBigTerrain::setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize)
 {
	m_bRectRotated = rotated;

    setContentSize(untrimmedSize);
    setVertexRect(rect);
    setTextureCoords(rect);  // 设置纹理坐标

    CCPoint relativeOffset = m_obUnflippedOffsetPositionFromCenter;

    // issue #732
    if (m_bFlipX)
    {
        relativeOffset.x = -relativeOffset.x;
    }
    if (m_bFlipY)
    {
        relativeOffset.y = -relativeOffset.y;
    }

    m_obOffsetPosition.x = relativeOffset.x + (m_tContentSize.width - m_obRect.size.width) / 2;
    m_obOffsetPosition.y = relativeOffset.y + (m_tContentSize.height - m_obRect.size.height) / 2;

    // rendering using batch node
    if (m_pobBatchNode)
    {
        // update dirty_, don't update recursiveDirty_
        setDirty(true);
    }
    else
    {
        // self rendering
        _eachWidth = rect.size.width;
		_eachHeight = rect.size.height;
        // Atlas: Vertex
        float x = 0 + _eachWidth/2;
        float y = 0 + _eachHeight/2;
		// Atlas: Color
		ccColor4B tmpColor = { 255, 255, 255, 255 };
	
		// 设置顶点坐标
        // Don't update Z.
		
		int eachWidth = _eachWidth;
		int eachHeight = _eachHeight;
	//	if (eachWidth > _width) eachWidth = _width;
	//	if (eachHeight > _height) eachHeight = _height;

		std::vector<ccV3F_C4B_T2F> tpoints;
		int widthSize =	_width;// / eachWidth ;
		int heightSize = _height;/// eachHeight;
		for (int i = 0; i < widthSize;i++)
			for (int j = 0; j < heightSize;j++)
			{
				ccV3F_C4B_T2F point;
				point.vertices = vertex3(i * eachWidth + x,j * eachHeight + y,0);
				tpoints.push_back(point);
			} // 生成顶点集合
		for (int i = 0; i < widthSize;i++)
			for (int j = 0; j < heightSize;j++)
			{
				ccVertex3F point = tpoints[i* widthSize + j].vertices; // 生成顶点编号
				static ccV3F_C4B_T2F pointList[4];
				pointList[0].vertices = vertex3(point.x,point.y,point.z);
				pointList[2].vertices = vertex3(point.x + eachWidth,point.y,point.z);
				pointList[1].vertices= vertex3(point.x ,point.y + eachHeight,point.z);
				pointList[3].vertices= vertex3(point.x + eachWidth ,point.y + eachHeight,point.z);
				// 确定纹理映射
				static int indexs[] = {0,1,2,1,2,3}; // 固态的指定渲染的引索号 
				static float textures[] = {0,1,0,0,1,1,1,0}; // 纹理映射点
				for (int z = 0; z < 6 ;z++)
				{
					ccV3F_C4B_T2F p;
					p.vertices = pointList[indexs[z]].vertices;
					p.colors = tmpColor;
					p.texCoords.u = textures[indexs[z]*2];
					p.texCoords.v = textures[indexs[z]*2+1];
					points.push_back(p);
				}
				//增加到plist中
			} // 生成三角形集合
		}
 }
 void MutiBigTerrain::updateTransform(void)
 {
	for (int i = 0; i < points.size();++i)
	{
		float x1 = m_obOffsetPosition.x;
        float y1 = m_obOffsetPosition.y;
        float x = m_transformToBatch.tx;
        float y = m_transformToBatch.ty;
		points[i].vertices = vertex3(x1 + x,y1 +y , 0);
	}
 }
/**
 * 绘制
 */
 void MutiBigTerrain::draw(void)
 {
	  CC_PROFILER_START_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");

    CCAssert(!m_pobBatchNode, "If CCSprite is being rendered by CCSpriteBatchNode, CCSprite#draw SHOULD NOT be called");

    CC_NODE_DRAW_SETUP();

    ccGLBlendFunc( m_sBlendFunc.src, m_sBlendFunc.dst );

    if (m_pobTexture != NULL)
    {
        ccGLBindTexture2D( m_pobTexture->getName() );
    }
    else
    {
        ccGLBindTexture2D(0);
    }
    
    //
    // Attributes
    //

    ccGLEnableVertexAttribs( kCCVertexAttribFlag_PosColorTex );

#define kQuadSize sizeof(m_sQuad.bl)
	if (points.size())
	{
		long offset = (long)&points[0];

		// vertex
		int diff = offsetof( ccV3F_C4B_T2F, vertices);
		glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, kQuadSize, (void*) (offset + diff));

		// texCoods
		diff = offsetof( ccV3F_C4B_T2F, texCoords);
		glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, kQuadSize, (void*)(offset + diff));

		// color
		diff = offsetof( ccV3F_C4B_T2F, colors);
		glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (void*)(offset + diff));


		glDrawArrays(GL_TRIANGLES, 0, points.size());
	}
    CHECK_GL_ERROR_DEBUG();

    CC_INCREMENT_GL_DRAWS(1);

    CC_PROFILER_STOP_CATEGORY(kCCProfilerCategorySprite, "CCSprite - draw");
 }
 bool MutiBigTerrain::checkIn(float x,float y)
 {
	 int width = (_width ) * this->_eachWidth ;
	 int height = (_height) * this->_eachHeight;
	 CCRect rect = CCRectMake(
			 this->_eachWidth /2,
			 this->_eachHeight/2,
			width,
			height);
	if (rect.containsPoint(ccp(x,y)))
	{
		return true;
	}
	return false;
 }
void MutiBigTerrain::setPosition(const CCPoint &point)
{
	CCPoint offset = ccp(0,0);//ccp(_eachWidth/2,_eachHeight/2);
	CCNode::setPosition(ccpAdd(point,offset));
}
bool MutiBigTerrain::checkIn(const CCPoint &point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	return checkIn(pos.x,pos.y);
}

/**
 * 从配置文件中读取信息
 */
void MutiBigTerrain::readNode(script::tixmlCodeNode *node)
{
	MutiObject::readNode(node);
	pngName = node->getAttr("src");
	_width = node->getInt("width");
	_height = node->getInt("height");
}
/**
 * 将信息写入节点当中
 */
TiXmlElement * MutiBigTerrain::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *imageNode = MutiObject::writeNode(parent,"bigterrain");
	if (imageNode)
	{
		imageNode->SetAttribute("src",pngName.c_str());
		imageNode->SetAttribute("width",_width);
		imageNode->SetAttribute("height",_height);
	}
	return imageNode;
}
void MutiBigTerrain::rebuild()
{
	initWithFile(pngName.c_str());
	setPosition(this->getPosition());
}
MutiBigTerrain* MutiBigTerrain::create(script::tixmlCodeNode *node)
{
	MutiBigTerrain *terrain = new MutiBigTerrain();
	if (terrain)
	{
		terrain->readNode(node);
		terrain->rebuild();
		terrain->autorelease();
		return terrain;
	}
	CC_SAFE_DELETE(terrain);
	return NULL;
}
NS_CC_END