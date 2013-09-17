#include "MyUI.h"

namespace myui{
	Image *Image::create(const char *pngName)
	{
		Image *image = new Image;
		if (image)
		{
			image->outlinePngName = pngName;
			image->pngName = pngName;
			image->sprite = CCSprite::create(pngName);
			image->sprite->retain();
		}
		return image;
	}
	/**
	* 设置轮廓图片
	*/
	void Image::setOutLine(const char *pngName)
	{
		this->outlinePngName = pngName;
	}
	/**
	 * 检查是否命中Touch
	 */
	bool Image::checkIn(CCTouch *touch)
	{
		if (!touch) return false;
		CCPoint point = touch->getLocation();
		return checkIn(point);
	}
	void Image::replacePng(const char *name)
	{
		if (sprite)
		{
			sprite->initWithFile(name);
		}
		else
		{
			sprite = CCSprite::create(name);
			setOutLine(name);
		}
	}
	/**
	* 检查该点是否在图片上
	*/
	bool Image::checkIn(const CCPoint &point)
	{
		if (!sprite) return false;
		CCPoint pos = parent->convertToNodeSpace(point);
		return checkIn(pos,sprite,this->outlinePngName.c_str());
	}
	bool Image::checkIn(const CCPoint point,CCSprite *sprite,const char *fileName)
	{
		if (!sprite) return false;
		if (checkInRect(point,sprite))
		{
			ccColor4B c = {0, 0, 0, 0};
			CCPoint touchPoint = point;
			CCSize cSize = sprite->getContentSize();
			CCPoint pos(sprite->getPositionX() - cSize.width/2, sprite->getPositionY()- cSize.height/2);
			CCPoint localPoint = ccp(touchPoint.x - pos.x,cSize.height - (touchPoint.y -pos.y));
			if (localPoint.x < 0 || localPoint.y < 0) return false;
			unsigned int x = localPoint.x, y = localPoint.y; 
			CCImage image;
			createImage(fileName,image);
			unsigned char *data_ = image.getData();
			unsigned int *pixel = (unsigned int *)data_;
			pixel = pixel + (y * (int)cSize.width) + x ;
			c.r = *pixel & 0xff;
			c.g = (*pixel >> 8) & 0xff;
			c.b = (*pixel >> 16) & 0xff;
			c.a = (*pixel >> 24) & 0xff;
			if (c.a == 0) {
				return false; 
			}else
			{
				return true;
			}
	 
		}
		else return false;
	}
	bool Image::createImage(const char *fileName,CCImage &image)
	{
		if (!fileName) return false;
		std::string pathKey = fileName;

		pathKey = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(pathKey.c_str());

		std::string fullpath = pathKey;
		{
			std::string lowerCase(fileName);
			for (unsigned int i = 0; i < lowerCase.length(); ++i)
			{
				lowerCase[i] = tolower(lowerCase[i]);
			}
			do 
			{
				CCImage::EImageFormat eImageFormat = CCImage::kFmtUnKnown;
				if (std::string::npos != lowerCase.find(".png"))
				{
					eImageFormat = CCImage::kFmtPng;
				}
				else 
				{
					return false;
				}
						 
				unsigned long nSize = 0;
				unsigned char* pBuffer = CCFileUtils::sharedFileUtils()->getFileData(fullpath.c_str(), "rb", &nSize);
				if (! image.initWithImageData((void*)pBuffer, nSize, eImageFormat))
				{
					CC_SAFE_DELETE_ARRAY(pBuffer);
					break;
				}
				else
				{
					CC_SAFE_DELETE_ARRAY(pBuffer);
				}                
				return true;
			} while (0);
		}
		return false;
	}
	bool Image::checkInRect(const CCPoint point,CCSprite *sprite)
	{
		if (!sprite) return false;
		CCRect rect = CCRectMake(
			sprite->getPositionX()-sprite->getContentSize().width/2,
			sprite->getPositionY()-sprite->getContentSize().width/2,
				sprite->getContentSize().width,
				sprite->getContentSize().height);
		if (rect.containsPoint(point))
		{
			return true;
		}
		return false;
	}

	bool Image::doTouch(TouchEvent event,CCTouch *touch)
	{
		CCPoint pos = touch->getLocation();
		switch(event)
		{
			case TOUCH_DOWN:
			{
				nowTouchPoint = pos;
				return true;
			}break;
			case TOUCH_MOVE:
			{
				CCPoint nowPoint = sprite->getPosition();
				sprite->setPosition(ccp(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y));
				nowTouchPoint = pos;
				return true;
			}break;
			case  TOUCH_END:
			{
				
			}break;
		}
		return false;
	}
	/**
	* 响应touch事件
	* 主要控制图片的移动
	*/
	bool Button::doTouch(TouchEvent event,CCTouch *touch)
	{
		CCPoint pos = touch->getLocation();
		switch(event)
		{
			case TOUCH_DOWN:
			{
				nowTouchPoint = pos;
				this->replacePng(downName.c_str());
				return true;
			}break;
			case TOUCH_MOVE:
			{
				CCPoint nowPoint = sprite->getPosition();
				sprite->setPosition(ccp(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y));
				nowTouchPoint = pos;
				return true;
			}break;
			case  TOUCH_END:
			{	
				this->replacePng(upName.c_str());
				return true;
			}break;
		}
		return false;
	}
	/**
	 * 创建按钮
	 */
	Button * Button::create(const char *upName,const char *downName)
	{
		Button *button = new Button();
		if (button)
		{
			button->upName = upName;
			button->downName=downName;
			button->replacePng(upName);
			button->sprite->retain();
		}
		return button;
	}
		
	bool Panel::attachTouch(TouchEvent event,CCTouch *touch)
	{
		if (firsts.size()) // 优先级的列表
		{
			return firsts.back()->attachTouch(event,touch);
		}
		// 设定actives
		bool tag = false;
		switch (event)
		{
			case TOUCH_DOWN:
			{
				for (BASES_ITER iter = uis.begin();iter != uis.end();++iter)
				{
					Base *base = *iter;
					if (base && base->attachTouch(event,touch))
					{
						actives.push_back(base);
						tag  = true;
					}
				}
			}break;
			case TOUCH_MOVE:
			case TOUCH_END:
			{
				for (BASES_ITER iter = actives.begin();iter != actives.end();++iter)
				{
					Base *base = *iter;
					if (base && base->attachTouch(event,touch))
						tag = true;
				}
				
			}break;
		}
		if (event == TOUCH_END)
		{
			actives.clear();
		}
		return tag;
	}
	void Panel::addUI(Base *base)
	{
		base->parent = this;
		uis.push_back(base);
	}
	void Panel::visit()
	{
		kmGLPushMatrix();
		this->transform();
		// 渲染firsts
		for (BASES_ITER iter = firsts.begin(); iter != firsts.end();++iter)
		{
			Base *base = *iter;
			if (base) base->render();
		}
		// 渲染actives
		for (BASES_ITER iter = actives.begin(); iter != actives.end();++iter)
		{
			Base *base = *iter;
			if (base)
			{
				base->isActive = true;
				base->render();
			}
		}
		// 当base 是active 的话不渲染
		for (BASES_ITER iter = uis.begin(); iter != uis.end();++iter)
		{
			Base *base = *iter;
			if (base && !base->isActive)
			{
				base->render();
			}
			else
			{
				base->isActive = false;
			}
		}
		kmGLPopMatrix();
	}
	/**
	 * 设置坐落的位置
	 */
	void Panel::setLocation(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation)
	{
		CCPoint point = getPoint(alignType,splitSize,gridLocation);
		rect.origin = point;
		CCNode::setPosition(point);
	}
	/**
	 * 设置大小
	 */
	void Panel::setSize(const CCSize &size)
	{
		rect.size = size;
	}
	CCSize Panel::getSize() // 获取大小
	{
		if (!rect.size.width || !rect.size.height) return Window::getWindowSize();
		return rect.size;
	}
	/**
	 * 获取当前布局产生的位置
	 */
	CCPoint Panel::getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation)
	{
		if (!rect.size.width || !rect.size.height) return Window::getPoint(alignType,splitSize,gridLocation);
		CCSize size = rect.size;
		float x = (size.width / splitSize.width) * gridLocation.x;
		float y = (size.height / splitSize.height) * gridLocation.y;
		if (alignType & myui::ALIGN_RIGHT)
		{
			x = x+splitSize.width;
		}
		if (alignType & myui::ALIGN_UP)
		{
			y = y + splitSize.height;
		}
		if (alignType & myui::ALIGN_CENTER)
		{
			x = x+splitSize.width/2;
			y = y + splitSize.height/2;
		}
		return ccp(x,y);
	}
	/**
	 * 窗口
	 **/
	Window* Window::create()
	{
		Window *window = new Window;
		if (window && window->init())
		{
			window->autorelease();
		}
		return window;
	}
	bool Window::init()
	{
		this->setTouchEnabled(true);
		return true;
	}
	void Window::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		CCSetIterator it;

		for( it = pTouches->begin(); it != pTouches->end(); ++it)
		{
			CCTouch* touch = (CCTouch*)(*it);
		
			if (firsts.size()) // 优先级的列表
			{
				firsts.back()->attachTouch(TOUCH_DOWN,touch);
				return;
			}
			// 设定actives
			bool tag = false;
		
			for (UIS_ITER iter = uis.begin();iter != uis.end();++iter)
			{
				Base *base = *iter;
				if (base && base->attachTouch(TOUCH_DOWN,touch))
				{
					actives.push_back(base);
					tag  = true;
				}
			}
		}
		return;	
	}
	void Window::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		CCSetIterator it;

		for( it = pTouches->begin(); it != pTouches->end(); ++it)
		{
			CCTouch* touch = (CCTouch*)(*it);
			if (firsts.size()) // 优先级的列表
			{
				firsts.back()->attachTouch(TOUCH_DOWN,touch);
				return;
			}
			bool tag = false;
			for (UIS_ITER iter = actives.begin();iter != actives.end();++iter)
			{
				Base *base = *iter;
				if (base && base->attachTouch(TOUCH_MOVE,touch))
					tag = true;
			}
		}
		return;
	}
	void Window::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		CCSetIterator it;

		for( it = pTouches->begin(); it != pTouches->end(); ++it)
		{
			CCTouch* touch = (CCTouch*)(*it);
			if (firsts.size()) // 优先级的列表
			{
				firsts.back()->attachTouch(TOUCH_DOWN,touch);
				return;
			}
			bool tag = false;
			for (UIS_ITER iter = actives.begin();iter != actives.end();++iter)
			{
				Base *base = *iter;
				if (base && base->attachTouch(TOUCH_END,touch))
					tag = true;
			}
			actives.clear();
		}
		return;
	}
	void Window::addUI(Base *base)
	{
		uis.push_back(base);
	}
	void Window::visit()
	{
		// 渲染firsts
		for (UIS_ITER iter = firsts.begin(); iter != firsts.end();++iter)
		{
			Base *base = *iter;
			if (base) base->render();
		}
		// 渲染actives
		for (UIS_ITER iter = actives.begin(); iter != actives.end();++iter)
		{
			Base *base = *iter;
			if (base)
			{
				base->isActive = true;
				base->render();
			}
		}
		// 当base 是active 的话不渲染
		for (UIS_ITER iter = uis.begin(); iter != uis.end();++iter)
		{
			Base *base = *iter;
			if (base && !base->isActive)
			{
				base->render();
			}
			else
			{
				base->isActive = false;
			}
		}
	}
	CCSize Window::getWindowSize()
	{
		return CCDirector::sharedDirector()->getWinSize();
	}
	/**
	 * 获取点的信息
	 * \param clignType 对齐方式
	 * \spliteSize 划分格局
	 * \location 格子编号
	 */
	CCPoint Window::getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation)
	{
		CCSize size = getWindowSize();
		float x = (size.width / splitSize.width) * gridLocation.x;
		float y = (size.height / splitSize.height) * gridLocation.y;
		if (alignType & myui::ALIGN_RIGHT)
		{
			x = x+splitSize.width;
		}
		if (alignType & myui::ALIGN_UP)
		{
			y = y + splitSize.height;
		}
		if (alignType & myui::ALIGN_CENTER)
		{
			x = x+splitSize.width/2;
			y = y + splitSize.height/2;
		}
		return ccp(x,y);
	}
}