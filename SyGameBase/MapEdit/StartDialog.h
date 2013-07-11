#pragma once
/**
 * 游戏主界面
 */
#include "cocos2d.h"
#include "UIPanel.h"
#include "UIItem.h"
#include "UIChoiceList.h"
#include "UIBag.h"
#include "UILabel.h"
#include "UIEditField.h"
#include "UIWindow.h"
NS_CC_BEGIN

class StartDialog:public BaseDialog<StartDialog>{
public:
	virtual void doInitEvent();
};

class DefaultDialog:public BaseDialog<DefaultDialog>{
public:
};

/**
 * 定义操作Button 和 sysui
 */
class MainDialog:public BaseDialog<MainDialog>{
public:
	virtual void doInitEvent();
};
/**
 * 处理当前元素属性的展示
 **/
class PropDialog;
class PropBaseShow{
public:
	/**
	 * 展示基本数值
	 */
	void show(PropDialog *propDialog,UIBase *base);
};

class PropButtonShow:public PropBaseShow{
public:
	/**
	 * 展示Button的属性 设定应该展示的属性
	 */
	void show(PropDialog *propDialog,UIButton *button);
};

class PropPanelShow:public PropBaseShow{
public:
	void show(PropDialog* propDialog,UIPanel *panel);
};
/**
 * 定义Panel 
 */
class PropDialog :public BaseDialog<PropDialog>
{
public:
	virtual void doInitEvent();
	/**
	 * 隐藏属性
	 */
	void hideProps();
	/**
	 * 展示button 的属性
	 */
	void show(UIButton *button);

	/**
	 * 展示panel 的属性
	 */
	void show(UIPanel *panel);
	/**
	 * 展示基本控件
	 */
	void show(UIBase *base);
};
/**
 * 结束 处理当前元素属性的展示
 **/
/**
 * 一个Label 
 * 一个文本框
 * 两个按钮[Sure] [Cancel]
 */
class SavePanelDialog:public BaseDialog<SavePanelDialog>
{
public:
	virtual void doInitEvent();
	void savePanel(const std::string &name);
	UIPanel *nowPanel;
	SavePanelDialog()
	{
		nowPanel = NULL;
	}
};
NS_CC_END