#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * 当动画移动到目的地时展示
 */
class stCollideTargetCallback{
public:
	virtual void exec(CCNode *node) = 0;
};
/**
 * 动画信息
 */
class CartoonInfo:public CCObject{
public:
	/**
	 * 创建动画信息 并且autorelease
	 */
	static CartoonInfo* create(const CartoonInfo &info);
	static CartoonInfo* create();
	/**
	 * 根据动画创建自身动作
	 * \param parent 当是离身动画时 承载临时Sprite
	 */
	CCFiniteTimeAction * createAction(CCNode * self,CCNode *parent,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback);
	int actionTag;
	int cartoonId; // 动画的编号
	std::string cartoonName; // 动画名字
	enum{
		SELF = 0, // 自身
		OTHER = 1, // 离身
		FOLLOW = 2, // 跟随动画
	};
	int cartoonType;// 动画类型 离身 还是 自身

	enum{
		TIME_FRAMES = 0,
		MOVE_FRAMES = 1,
		FOLLOW_FRAMES = 2,
		FOLLOW_ANIMATIONS = 3, 
	};
	int frameType; // 是时间帧 还是移动帧
	
	float needTime; // 所需时间
	int actionType; // 动作类型 子类定义
	std::vector<CCSpriteFrame*> frames; // 临时创建的变量	
	int nextConbineType; // 下一个合并类型
	enum{
		SEQUENCE = 0,// 序列 
		TOGETHER = 1, // 一起
	};
	// 在此控制该动作的播放概率
	bool isValid(){return true;}
	/**
	 * 增加下一个动画序列
	 */
	CartoonInfo* addNextCartoonInfo(int nextConbineType,const CartoonInfo& info);
	CartoonInfo* nextCartoon; // 下一个动画信息
	/**
	 * 释放自身
	 */
	void release();
	/**
	 * 创建动画帧
	 */
	CCAnimation * createAnimation(float costtime=0);

	CartoonInfo()
	{
		nextConbineType = SEQUENCE;
		cartoonId = -1;
		actionType = -1;
		cartoonType = -1;
		needTime = -1;
		nextCartoon = NULL;
		actionTag = -1;
		frameType = MOVE_FRAMES;
	}
	CartoonInfo &operator = (const CartoonInfo &info)
	{
		this->actionType = info.actionType;
		this->cartoonType = info.cartoonType;
		this->nextCartoon = info.nextCartoon;
		this->nextConbineType = info.nextConbineType;
		this->cartoonName = info.cartoonName;
		this->frameType = info.frameType;
		this->frames = info.frames;
		this->needTime = info.needTime;
		return *this;
	}
};
/**
 * 动画移动动作 将会作用在自己身上 
 * 动画帧与移动相关联
 */
class CartoonMoveAction:public CCMoveTo{
public:
	
	virtual void update(float time);
	bool isTempTarget;
	CartoonMoveAction()
	{
		isTempTarget = false;
	}

	/**
	 * 创建动画
	 */
	static CartoonMoveAction* create(const CartoonInfo &cartoonInfo, const CCPoint& position);
	/**
	 * 初始化cartoon 移动行为
	 */
	bool init(const CartoonInfo &cartoonInfo, const CCPoint& position);
	/**
	 * 释放自己所占有的帧
	 */
	void stop(void);
protected:
	CartoonInfo cartoonInfo;
};
/**
 * 创建非移动的自身动画 
 */
class CartoonAction:public CCAnimate{
public:
	bool isTempTarget;
	CartoonAction()
	{
		isTempTarget = false;
	}
	virtual void update(float time)
	{
		CCAnimate::update(time);
	}
	/**
	 * 创建卡通动作
	 */
	static CartoonAction* create(const CartoonInfo &cartoonInfo);
	/**
	 * 初始化动作
	 */
	bool init(const CartoonInfo &cartoonInfo);
	/**
	 * 释放自己所占有的帧
	 */
	void stop(void);
};
/**
 * 这是一个特殊动作
 * 跟随目标对象来动作 
 * 将target retain 每帧检查是否只有 1 若是1则 返回 说明对象消失 记录的目标不变
 * 自身的动画与移动不关联
 */

class CartoonFollowAction:public CCMoveTo{
public:
	CartoonFollowAction()
	{
		isTempTarget = false;
		target = NULL;
		callback = NULL;
	}
	 static CartoonFollowAction* create(const CartoonInfo &cartoonInfo,CCNode *target);
	 /**
	 * 更新
	 */
	 virtual void update(float t);
	 /**
	 * 为使动作更加连续
	 */
	void stop(void);

	bool initWithAnimation(CCAnimation *pAnimation);

    virtual void startWithTarget(CCNode *pTarget);
	void updateAnimate(float t);
	bool isTempTarget;
	stCollideTargetCallback *callback;
private:
	
	CCNode *target;
	CartoonInfo cartoonInfo;
	/**
	 * 来自Animate的数据
	 */
	CCAnimation* m_pAnimation;
	std::vector<float> m_pSplitTimes;
	int                m_nNextFrame;
	CCSpriteFrame*  m_pOrigFrame;
	unsigned int    m_uExecutedLoops;
	
};

class FollowAnimationAction:public CCMoveTo{
public:
    FollowAnimationAction()
	{
		isTempTarget = false;
		followTarget = NULL;
		callback = NULL;
	}
    static FollowAnimationAction* create(CCNode *target,float needTime);
   
    virtual void update(float t);
    
	void stop(void);
    
    
    virtual void startWithTarget(CCNode *pTarget);
    bool isTempTarget;
	stCollideTargetCallback *callback;
private:
    CCNode *followTarget; // follow it
};
/**
 * 包裹类 尝试播放动画
 */
class Cartoon:public CCSprite{
public:
	/** 自身做改变
	 * 目标点 position
	 * 动态构建Action
	 */
	void runSelfAction(const CartoonInfo &info,const CCPoint &position);

	/**
	 * 附加在离身的动作 指定目的地
	 **/
	void runFlyAction(CCNode* parent,const CartoonInfo &info,const cocos2d::CCPoint &point);
	/**
	 * 创建跟随动画
	 * 碰到对象就消息
	 */
	void runFllowAction(CCNode *parent,const CartoonInfo&info,CCNode *target);
    void runState(CCNode *parent, CartoonInfo &info,CCNode *target);
    void runMoveState(CCNode *parent, CartoonInfo &info,CCNode * target,float aniTime = 0);
	void runMoveAction(CCNode *parent,CartoonInfo &info,float animationTime,const CCPoint &point);
	/**
	 * 组合动画的播放
	 * \param parent fly 承载节点
	 * \param info 动画信息
	 * \param point 目的地
	 * \param target 跟随对象
	 */
	void runAction(CCNode *parent,const CartoonInfo*info,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback = NULL);
	/**
	 * 飞行结束后需要清除临时节点
	 */
	void flyEnd(CCNode *pSender,void *arg);
	/**
	 * 动画结束
	 */
	void doCartoonEnd();
	/**
	 * 执行下一步
	 */
	virtual void nextStep(){}

	void attachSprite(CCSprite *sprite)
	{
		this->sprite = sprite;
	}
private:
	CCSprite *sprite;
	
public:
	 /**
	  * 以某个行为为初始执行状态
	  */
	 void start(int id);
	 void tryNextAction(int id);
	 /**
	  * 并行的执行行为
	  */
	 void tryConbineAction(int type);
	 int actionType;
	 int oldActionType;
	 Cartoon()
	 {
		actionType = 0;
		oldActionType = -1;
		sprite = NULL;
	 }
	 /**
	  * 检查当前行为
	  */
	 bool isNowAction(int actionType);
	 /**
	  * 下一个动作里去除该系
	  */
	 void clearAction(int type);
	 /**
	  * 根据优先级 生成相应的动作
	  */
	 void putConbineAction();
protected:
	 void setAction(int actionType);
	 virtual CartoonInfo* makeCartoon(int actionType);
	 virtual void putCartoon(CartoonInfo *action);
	 virtual CartoonInfo* v_makeCartoon(int actionType) {return NULL;};
	 virtual void v_putCartoon(CartoonInfo *action){};
};


class CartoonDirAction{
public:
	std::string FramesName; // 帧名字
	std::string frameLoadType; // 帧加载类型
	std::vector<std::string> frames;
	CartoonDirAction()
	{
		
	}
	/**
	 * 获取多帧
	 */
	bool getFrames(std::vector<CCSpriteFrame *> &frames);
	/**
	 * 处理节点
	 */
	void takeNode(script::tixmlCodeNode *node);
};

class CartoonXmlAction{
public:
	std::string actionName; // 动作名字
	int actionType; // 动作类型
	float needTime; // 需要时间
	int frameType; // 帧类型 时间 或者移动类型
	int cartoonType; // 动画类型 [SELF,OTHER]
	std::map<int,CartoonDirAction> dirActions;
	typedef std::map<int,CartoonDirAction>::iterator DIRACTIONS_ITER;
	/**
	 * 获取帧集合
	 * \param frames 帧集合 
	 */
	bool getFrames(int dir,std::vector<CCSpriteFrame *> &frames);
	CartoonXmlAction()
	{
		actionType = 0;
		needTime = 0;
		cartoonType = 0;
		frameType = 0;
	}
	/**
	 * 处理节点
	 */
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * 组合拳
 */
class CartoonConbineAction:public CartoonXmlAction{
public:
	int nextType; // 下一个类型
	/**
	 * 处理节点
	 */
	void takeNode(script::tixmlCodeNode *node);
	/**
	 * 构建动画
	 */
	CartoonInfo* getCartoonInfo(int dir);
};

NS_CC_END