#pragma once

/**
 * 游戏主界面
 */
#include "cocos2d.h"
#include "UIPanel.h"
#include "UIWindow.h"
#include "UIList.h"
NS_CC_BEGIN

/**
 * 文件条目
 */
class UIFileItem:public BaseUIItem<UIFileItem>{
public:
	enum FILETYPE{
		__DIR__,
		__FILE_
	};
	void setFileType(FILETYPE type);
	FILETYPE nowType;
};
/**
 * 文件列表
 */
class UIFileList:public BaseDialog<UIFileList>{
public:

	/**
	 * 初始化List 和绑定事件
	 */
	virtual void doInitEvent();

	void show(const char *root,const char * listName="list",const char *dirItemName="diritem.xml",const char *fileItemName="fileitem.xml");
};

NS_CC_END