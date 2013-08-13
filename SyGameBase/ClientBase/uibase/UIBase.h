#pragma once
#include "serialize.h"
#include "vector"
#include <string>
#include "cocos2d.h"
#include "tinyxml.h"
NS_CC_BEGIN
class UIBase;
typedef void (UIBase::*UI_EVENT_HANDLE)(UIBase*);
#define ui_function(_SELECTOR) FunctionInfo((UI_EVENT_HANDLE)(&_SELECTOR),this)

#define ui_object_function(object,_SELECTOR) FunctionInfo((UI_EVENT_HANDLE)(&_SELECTOR),object)
#define REGISTER_EVENT 
class UIItem;
class UIPanel;
class UIWindow;
struct stBagExecEach{
	virtual  void exec(UIItem *item) = 0;
};
#define GET_UI_BYID(Panel,Class,Fieldname,UniqueId)\
	Class *Fieldname = static_cast<Class*>( Panel->getUIById(UniqueId));
#define GET_UI_BYNAME(Panel,Class,Fieldname,UniqueName)\
	Class *Fieldname = static_cast<Class*>( Panel->getUIByName(UniqueName));
// 获取面板
#define PANEL(Panel,UniqueName) \
	(static_cast<UIPanel*>( Panel->getUIByName(UniqueName)))
// 获取按钮
#define BUTTON(Panel,UniqueName) \
	((UIButton*) Panel->getUIByName(UniqueName))
// 获取标签
#define LABEL(Panel,UniqueName) \
	(UILabel*) Panel->getUIByName(UniqueName))
// 获取编辑框
#define EIDTFIELD(Panel,UniqueName) \
		(static_cast<UIEditField*>( Panel->getUIByName(UniqueName)))
// 获取列表
#define LIST(Panel,UniqueName) \
		(static_cast<UIViewList*>( Panel->getUIByName(UniqueName)))
// 获取单选框
#define CHOICE(Panel,UniqueName) \
		(static_cast<UIChoice*>( Panel->getUIByName(UniqueName)))
struct FunctionInfo{
	UI_EVENT_HANDLE handle;
	UIBase *object;
	FunctionInfo()
	{
		object = NULL;
		handle = NULL;
	}
	FunctionInfo(UI_EVENT_HANDLE handle,UIBase *object)
	{
		this->handle = handle;
		this->object = object;
	}
};
struct UICallback{
	virtual void callback(UIBase *base) = 0;
};
/**
 * UI 的基础类
 */
class UIBase:public CCNode{
public:
	int uniqueId; // 唯一编号
	std::string name; // 控件名字
	std::string uniqueName;
	std::string onCreateCodeName; // 创建代码
	std::string onClickCodeName; // 点击代码
	enum{
		UI_LABEL = 0, // 静态文本框
		UI_IMAGE_BUTTON = 1, // 图像按钮
		UI_BUTTON = 2, // 按钮
		UI_LIST = 3, // 列表
		UI_CHOICE = 4, // 选择
		UI_BAG = 5, // 包裹
		UI_TEXT_FIELD = 6, // 输入框
		UI_RICH_TEXT = 7, // 富文本域
		UI_VALUE = 8, // 数值条
		UI_PANEL = 9, // 容器
	};
//	SERIALIZE_KIND(0);
	int uiType; // 控件类型
	int eventPriority;// 事件优先级
	enum{
		EVENT_NULL = 0, // 空事件
		EVENT_CLICK_DOWN = 1, // 某个条目被按下
		EVENT_EDIT_DOWN = 2, // 某个条目被编辑
		EVENT_PANEL_LOAD = 3, // panel加载完毕
		EVENT_DRAG_OUT = 4, //物体被拽出
		EVENT_TOUCH_IN, // 进入
		EVENT_TOUCH_MOVE, // 在其上移动
		EVENT_TOUCH_OUT, // 出来
		EVENT_TOUCH_NO_CHILD_IN,
	};
	virtual UIPanel * getPanel();
	/**
	 * 创建一个基本的ui 用于持久化
	 */
	static UIBase * create(int kind);
	/**
	 * 绑定事件处理对象
	 */
	virtual bool bind(int uiEvent,const FunctionInfo& function);
	virtual bool bind(int uiEvnet,UICallback *callback);
	bool bind(int uiEvent,const char *luaFunctionName);
	virtual void doEvent(int uiEvent,UIBase *base);
	UIWindow *getDepthWindow();
	UIBase()
	{
		eventPriority = 0;
		uniqueId = 0;
		x = y = w = h = 0;
		uiType = -1;
	}
	~UIBase()
	{
		for (UI_CALLBACK_ITER iter = event_callbacks.begin(); iter != event_callbacks.end();++iter)
		{
//			if(*iter) delete *iter;
		}
	}
	std::vector<FunctionInfo> event_functions;
	std::vector<UICallback*> event_callbacks;
	typedef std::vector<FunctionInfo>::iterator EVENT_FUNCTIONS_ITER;
	typedef std::vector<UICallback*>::iterator UI_CALLBACK_ITER;
	/**
	 * 设置位置
	 */
	virtual void setPosition(float x,float y) {return;}
	enum{
		TOUCH_DOWN = 0, // 按下
		TOUCH_MOVE = 1, // 移动
		TOUCH_END = 2, // 结束
	};
	/**
	 * 处理点击
	 * \parma touchType 点击类型
	 * \param touchPoint 点击点
	 */
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	virtual bool doTouch(int touchType,CCTouch* touch)
	{
		return false;
	}
	/**
	 * 设置大小
	 */
	virtual void setSize(float w,float h) {return;}
	 /** 
	 * 检查是否在区域里
	 */
	virtual bool touchDown(float x,float y) {return false;}
	/**
	 * 更新位置
	 */
	virtual bool touchMove(float x,float y){return false;}
	/**
	 * 停止拖动
	 */
	virtual bool touchEnd(float x,float y) {return false;}

	/**
	 * 设置为可编辑模式
	 */
	virtual void setEditable(bool tag) {return ;}
	virtual bool isMovable(){return true;}
	/**
	 * 设置 可见
	 */
	void setVisible(bool tag);

	virtual void draw(){
		CCNode::draw();
	}

	virtual  void visit()
	{
		CCNode::visit();
	}
	static std::string toUTF8(const std::wstring& ); 
	/**
	 * 创建父节点下的子节点
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
public:
	float x;
	float y;
	float w;
	float h;
};

NS_CC_END
