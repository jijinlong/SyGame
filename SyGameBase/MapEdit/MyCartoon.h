#include "cocos2d.h"

USING_NS_CC;

/**
 * 帧集合
 */
class MyAnimation{
public:
	std::vector<CCSpriteFrame*> frames;

	CCSpriteFrame * getFrame(int index);

	void destroyFrames();
};
/**
 * 动画 多个动画的组合体 使模型支持换装 附带一个编辑器 使用lua编写
 */
class MyCartoon:public CCNode{
public:
	std::vector<CCSprite*> sprites; // 精灵集合
	std::vector<MyAnimation*> animations; // 动作集合
	/**
	 * actionId 当前的行为编号
	 * 展示 第startFrame 和第 endFrame 超时时间 timeout
	 * blockId 是指第几块
	 */
	void show(int actionId,int startFrame,int endFrame,int timeout,int blockId);

	void setFrame(int id,int blockId); // 设置当前帧

	void end(int actionId,int blockId); // 当前一次行为结束了
};