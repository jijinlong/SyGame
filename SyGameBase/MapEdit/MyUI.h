#pragma once
#include "cocos2d.h"

USING_NS_CC;
/**
* MIT 开源
* 一个简单在cocos2d-x 其上的UI系统
* 1. 图像检测有效区域的设定
* 2. 简单粗暴的解决方案 待优化
* 3. 支持控件 [Lable 可以展示复杂的信息] [Table 游戏中的包裹] [Tree 树形结构 用来管理资源]
*      [List 无限承载特性 可以用来展示榜] [ScrollView 展示有效区域 带有滚动效果] [Button 按钮]
*      [Choice 选择] [Bubble 水泡]
* 4. 简单 带来的是方便扩展
* 使用事例:
*
* 5. TODO 测试事件机制 支持点击
* 6. TODO 测试布局机制
* 7. TODO lua扩展 逻辑部分使用Lua
***/
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
	enum FitType{
		FIT_SELF = 0, // 自身适应 , 用户可以设定其大小
		FIT_GRID = 1, // 填满格子
	};
	class Panel;
    class Base;
    /**
     * 点击处理器
     */
    class TouchHandle:public CCObject{
    public:
        virtual void handleDown(Base *base){};
        virtual void handleMove(Base *base){};
        virtual void handleEnd(Base *base){};
        virtual void handleClick(Base *base){};
    };
	class Base:public CCNodeRGBA{
	public:
		Base()
		{
			touch = NULL;
			isActive = false;
            moveAble = false;
			panel = NULL;
            parent=NULL;
            touchHandle = NULL;
		}
		virtual bool checkIn(CCTouch *touch)
		{
			return false;
		}
        TouchHandle *touchHandle;
        void bindTouchHandle(TouchHandle *touchHandle);
        void setMoveable(bool moveableTag){moveAble = moveableTag;}
		/**
         * 响应touch事件
         * 支撑多点触控
         */
		virtual bool attachTouch(TouchEvent event,CCTouch *touch);
		virtual bool doTouch(TouchEvent event,CCTouch *touch)
		{
			return false;
		}
		CCTouch *touch; // 当前Touch 对象
		CCPoint nowTouchPoint; // 当前Touch点
		bool isActive; // 是否活跃
        bool moveAble; // 是否可以移动
		Panel *panel;
        CCNode *parent;
        /**
		 * 设置位置
		 */
		void setLocation(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);

		/**
		 * 设置在视图内部
		 */
		void setInView(const CCSize &size){}
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
		bool createImage(const char *fileName,CCImage* &image);
        ~Image()
        {
            if (image) delete image;
            image = NULL;
        }
		Image()
		{
			sprite = NULL;
			image = NULL;
		}
        CCImage* image;
        
        void runAction(CCAction *action);
        
        CCSize getViewSize();
        CCSize imageSize;
        void setsize(const CCSize &size);
		void setInView(const CCSize &size);
    };
	/**
	 * 按钮
	 **/
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
     * 选择器
     */
    class Choice:public Image{
    public:
        /**
		 * 创建按钮
		 */
		static Choice * create(const char *upName,const char *downName);
		/**
         * 响应touch事件
         * 主要控制图片的移动
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
        
		std::string upName;
		std::string downName;
        
        bool choiceAble;

    };
    /**
     * 气泡
     */
    class Bubble:public Choice{
    public:
        /**
		 * 创建按钮
		 */
		static Bubble * create(const char *upName,const char *downName);
		/**
         * 响应touch事件
         * 主要控制图片的移动
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
        
		std::string upName;
		std::string downName;
        
        void popUp();
    };
	/**
	 * 滑块
	 */
	class Slider:public Image{
	public:
		/**
		 * 创建滑块
		 */
		static Slider * create(const char *upName,const char *downName);
		
		/**
		 * 初始化滑块
		 */
		bool init(const char *upName,const char *downName);

		/**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
		/**
		 * 背景层
		 */
		CCSprite *backSprite;
        /**
		 *  滑块层
		 */
		CCSprite *sliderSprite;
		/**
		 * 获取值
		 */
		float getValue();
		/**
		 * 设置当前示意值
		 */
		void setValue(float value);
		
		/**
		 * 数值
		 */
		float value;

		Slider()
		{
			value = 0;
			backSprite = sliderSprite = NULL;
		}

		float getMaxValue();
	};
	/**
	 * 获取文本信息并展示
	 * 并不适用于频繁更改的需求
	 **/
	class Label:public Base{
	public:
		static Label * create(const char *content,const CCSize& size);
		/**
		 * 解析文本在区域内展示内容
		 */
		bool init(const char* content,const CCSize &size);
        /**
         * 获取字符串上的参数
         */
        static const char* getArgs(const char * content,int argc,std::vector<std::string> &args);
	
        /**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
    
        CCRect rect;
        
        void setNumber(int tag,double value);
        double getNumber(int tag);
        std::vector<CCLabelAtlas*> numbers;
    };
    /**
     * 血量条
     */
    class HPLabel:public Base{
    public:
        static HPLabel *create(const char *backName,const char *showName);
        bool init(const char *backName,const char *showName);
        void setValue(float value);
        CCSize viewSize; // 可视区域
        int maxValue;
        int value;
        CCSprite *backSprite;
        CCSprite *valueSprite;
        HPLabel()
        {
            backSprite = valueSprite = NULL;
            maxValue = 0;
            value = 0;
        }
    };
    /**
     * 树形结构
     **/
    class Tree:public Base{
    public:
        Tree()
        {
            parent = next = child = NULL;
            image = NULL;
            isOpen = true;
        }
        /**
         * 创建树结构
         */
        static Tree * create(Image *image);
        /**
         * 增加树
         */
        void addTree(Tree *tree);
        /**
         * 展示这颗树
         */
        void show();
        void visit();
        Tree *parent; // 父节点
        Tree *next; // 下一个节点
        Tree *child; // 子节点
        Image *image; // 内容
        bool isOpen; // 是否展开
        CCPoint show(Tree *tree,const CCPoint &point);
        /**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * 递归 检查是否点击在树上
         */
        bool checkInTree(CCTouch *touch,Tree *tree);
        /**
         * 递归处理点击事件 直至有事件被处理
         */
        bool touchInTree(TouchEvent event,CCTouch *touch,Tree *tree);
        /**
         * 关闭所有隐藏子节点
         */
        void hideCloseNode(Tree *node);
    };
    /**
     * 列表
     */
    class List:public Base{
    public:
        List()
        {
            image = NULL;
            nowTouchImage = NULL;
            exchageAble = true;
        }
        /**
         * 创建列表
         */
        static List *create(Image *image,const CCSize &cellSize = CCSizeMake(0,0));
        /**
         * 删除列表
         */
        void remove(List *list);
        /**
         * 增加列表
         */
        void add(Image *list);
        /**
         * 展示列表
         */
        void show();
        std::list<Image*> content;
        Image *image; // 图像
        CCSize cellSize; // 格子大小
        
        /**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * 获取改点对应的Table中的引索
         */
        int pickImageIndex(CCTouch *touch);
        
        /**
         * 根据引索获取图像
         */
        Image *pickImage(const int &index);

        Image *nowTouchImage;
        
        bool exchageAble;
    };
    /**
     * 表格
     */
    class Table:public Base{
    public:
        Table()
        {
            exchageAble = true;
            nowTouchImage = NULL;
        }
        static Table *create(const CCSize & tableSize,const CCSize &cellSize);
        bool exchageAble; //是否可以交换 指示元素是否可以相互交换
        std::vector<Image *> images;
        /**
         * 增加一个元素
         */
        void add(const CCPoint &point,Image *image);
        /**
         * 按次序增加一个元素
         */
        void push(Image *image);
        /**
         * 删除一个元素
         */
        void remove(Image *image);
        /**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * 获取改点对应的Table中的引索
         */
        CCPoint pickImageIndex(CCTouch *touch);

        /**
         * 根据引索获取图像
         */
        Image *pickImage(const CCPoint &point);

        /**
         * 展示元素   
         */
        void show();
        
        CCSize tableSize;
        CCSize cellSize;
        
        Image *nowTouchImage;
        void visit();
        void doExchange(Image *src,Image *dest);
        
        void removeIndex(Image *src);
    };
    /**
     * 可视裁剪区域 可滚动
     **/
    class ScrollView:public Base{
    public:
        static ScrollView * create(float width,float height);
        bool init(float width,float height);
        /**
         * 增加内容 
         */
        void add(Image *base);
        /**
         * 渲染
         */
        void visit();
        int width; // 视图宽
        int height; // 视图高
        ScrollView()
        {
            width = height = 0;
            child = NULL;
            scrollType = ALL;
        }
        CCSize eachTap;
        enum SCROLL_TYPE{
            UP_DOWN = 0,
            LEFT_RIGHT = 1,
            ALL = 2,
        };
        SCROLL_TYPE scrollType;
        void setEachTap(const CCSize eachTap){this->eachTap = eachTap;}
        void setScrollType(SCROLL_TYPE scrollType){this->scrollType = scrollType;}
        Image *child;
        /**
         * 检查是否命中Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * 响应touch事件
         * 主要控制图片的移动
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        
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
	class Panel:public Image{
	public:
        static Panel *create();
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
}
