#pragma once
/**
 * 全局变量
 * 系统中承载dialog dialog限制嵌套
 */
#include "cocos2d.h"
#include "UIPanel.h"
NS_CC_BEGIN
class CommonPanel:public BaseDialog<CommonPanel>
{};
class UIWindow:public CCNode{
public:

	static UIWindow * create();
	/**
	 * 增加一个容器
	 */
	void addPanel(UIPanel *panel);

	/** 
	 * 检查是否在区域里
	 */
	bool touchDown(float x,float y);
	/**
	 * 更新位置
	 */
	bool touchMove(float x,float y);
	/**
	 * 停止拖动
	 */
	bool touchEnd(float x,float y);

	UIPanel * getNowTouchPanel(){return _nowTouchPanel;}
	/**
	 * 删除当前活动Panel
	 */
	void removeNowPanel();
	/**
	 * 设置鼠标图片
	 */
	void setCursor(CCSprite *sprite);
	/**
	 * 增加ui
	 */
	void addUI(UIBase *base);

	void setNowTouchPanel(UIPanel * pan);
	static bool isClose()
	{
		return false;
	}
	CCPoint getCursorPoint();
	static void release();

	void setEndFunction(const FunctionInfo &function);
	/**
	 * 展示当前出错信息
	 */
	void showErr(const std::string& info);
	UIPanel *getPanel(const std::string &name);
	UIPanel *showPanel(const std::string &name);
	/**
	 * 将panel 设置为模态
	 */
	void pushModel(UIPanel *panel);
	/**
	 * 弹出当前模态框
	 */
	void popModel();
private:
	CCLabelTTF * _errLbl;
	void insertBase(UIBase *base);
	typedef std::list<UIPanel*> PANELS;
	PANELS _panels;
	typedef PANELS::iterator PANELS_ITER;
	typedef std::list<UIBase*> BASES;
	std::vector<UIPanel*> _models;
	BASES _bases;
	typedef BASES::iterator BASES_ITER;
	UIPanel *_nowTouchPanel;
	UIPanel *_nowModel;
	CCSprite *_cursor; // 鼠标游标
	UIBase *_nowTouchUI;
	CCPoint nowCursorPoint;
	bool endFlag;
	UIWindow()
	{
		_nowModel = NULL;
		_errLbl = NULL;
		endFlag = false;
		_nowTouchUI = NULL;
		_cursor = NULL;
		_nowTouchPanel = NULL;
	}
};
NS_CC_END
