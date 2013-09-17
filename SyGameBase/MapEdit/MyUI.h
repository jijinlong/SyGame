#pragma once
#include "cocos2d.h"

USING_NS_CC;

namespace myui{
	enum TouchEvent{
		TOUCH_DOWN = 1,
		TOUCH_MOVE = 2,
		TOUCH_END = 3,
	}; // 点击事件
	enum AlignType{
		ALIGN_LEFT = 1 << 0,
		ALIGN_RIGHT = 1 << 1,
		ALIGN_UP = 1 << 2,
		ALIGN_BOTTOM = 1 << 3,
		ALIGN_CENTER = 1 << 4,
	}; // 对齐方式
	class Base{
	public:
		Base()
		{
			touch = NULL;
			isActive = false;
			parent = NULL;
		}
		virtual bool checkIn(CCTouch *touch)
		{
			return false;
		}
		/**
		* 响应touch事件
		* 支撑多点触控
		*/
		virtual bool attachTouch(TouchEvent event,CCTouch *touch)
		{
			if (event == TOUCH_DOWN && !this->touch && checkIn(touch))
			{
				this->touch = touch;
				return doTouch(event,touch);
			}
			if (event == TOUCH_MOVE && touch == this->touch)
			{
				return doTouch(event,touch);
			}
			if (event == TOUCH_END && touch == this->touch)
			{
				bool tag =  doTouch(event,touch);
				this->touch = NULL;
				return tag;
			}
			return false;
		}
		virtual bool doTouch(TouchEvent event,CCTouch *touch)
		{
			return false;
		}
		CCTouch *touch;
		CCPoint nowTouchPoint;
		bool isActive;
		CCNode *parent;
		virtual void render(){}
	};

	/**
	 * 1.可以根据图片轮廓去检查是否碰撞
	 * 2.可以多点控制界面原色
	 * 3.在Touch 中后 界面元素会在最上
	 * 4. 不在继承内部对象
	 */
	class Image:public Base{
	public:
		static Image *create(const char *pngName);
		/**
		 * 检查是否命中Touch
		 */
		bool checkIn(CCTouch *touch);
		/**
		* 检查该点是否在图片上
		*/
		bool checkIn(const CCPoint &point);
		std::string pngName; // png图片
		std::string outlinePngName; // 轮廓png名字
		/**
		* 设置轮廓图片
		*/
		void setOutLine(const char *pngName);
		/**
		* 响应touch事件
		* 主要控制图片的移动
		*/
		bool doTouch(TouchEvent event,CCTouch *touch);

		/**
		* 内部精灵元素
		*/
		CCSprite *sprite;

		void show(CCNode *node)
		{
			if (sprite)
				node->addChild(sprite);
		}
		/**
		* 替换当前图片
		*/
		void replacePng(const char *name);
		bool checkIn(const CCPoint point,CCSprite *sprite,const char *fileName);
		bool checkInRect(const CCPoint point,CCSprite *sprite);
		bool createImage(const char *fileName,CCImage &image);

		Image()
		{
			sprite = NULL;
		}
		virtual void render()
		{
			if (sprite) sprite->visit();
		}
	};
	class Button:public Image{
	public:
		/**
		 * 创建按钮
		 */
		static Button * create(const char *upName,const char *downName);
		/**
		* 响应touch事件
		* 主要控制图片的移动
		*/
		bool doTouch(TouchEvent event,CCTouch *touch);
	
		std::string upName;
		std::string downName;
	};
	/**
	 * 读取xml 获取文本信息并展示
	 * 并不适用于频繁更改的需求
	 **/
	class Label:public Base{
	public:
		static Label * create(const char *content,const CCSize& size);
		/**
		 * 解析文本在区域内展示内容
		 */
		bool init(const char* content,const CCSize &size);
	};
	/**
	 * 没办法 这东西得放入场景上 就继承CCNode 了 
	 * 1.支持多点触发事件的分发 需要开启多点触控机制
	 * 2.需要更改渲染代码
	 * 3.布局管理
	 *	 1.孤岛方案 每个单元独立配置
	 *		算法说明: 每个单元可以定制自己的细分格子 和 在细分网格上的位置
	 * 4.该Panel 是有界的 默认一幅有色的图片
	 **/
	class Panel:public CCNode,public Base{
	public:
		std::list<Base*> uis;  // 界面元素列表 当Base 被激活时 优先展示
		std::list<Base*> actives; // 激活的ui列表
		std::list<Base*> firsts; // 优先级的列表 实现模式框
		typedef std::list<Base*>::iterator BASES_ITER;
		/**
		* 响应touch事件
		* 将激活的Base 放入actives
		*/
		bool attachTouch(TouchEvent event,CCTouch *touch);
		/**
		 * 增加界面元素
		 */
		void addUI(Base *base);
		/**
		 * 渲染
		 */
		void visit();
		virtual void render()
		{
			visit();
		}
		/**
		 * 设置坐落的位置
		 */
		void setLocation(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
		/**
		 * 设置大小
		 */
		void setSize(const CCSize &size);
		CCRect rect; // 自身所在的区域
		CCSize getSize(); // 获取大小
		/**
		 * 获取当前布局产生的位置
		 */
		CCPoint getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
	};
	/**
	 * 窗口
	 */
	class Window:public CCLayer{
	public:
		static Window*create();
		bool init();
		void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
		void ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
		void ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
		std::list<Base*> uis;
		typedef std::list<Base*>::iterator UIS_ITER;
		std::list<Base*> actives; // 激活的ui列表
		std::list<Base*> firsts; // 优先级的列表 实现模式框
		/**
		 * 增加界面元素
		 */
		void addUI(Base *base);
		 /**
		  * 渲染
		  */
		void visit();
		/**
		 * 获取窗口大小
		 */
		static CCSize getWindowSize();
		/**
		 * 获取点的信息
		 * \param clignType 对齐方式
		 * \spliteSize 划分格局
		 * \location 格子编号
		 */
		static CCPoint getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
	};
};