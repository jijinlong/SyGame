/**
 * 容器类 可以承载 其他容器 并且可以拥有移动能力
 */
#pragma once
#include "cocos2d.h"
#include "UIBase.h"
#include "xmlScript.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UINumber.h"
#include "UIImage.h"
#include "UIEditField.h"
#include "UIChoice.h"
NS_CC_BEGIN
class UIWindow;
struct stExecPanelEach{
	virtual void exec(UIBase *base) = 0;
};
class UIPanel:public UIBase{
public:
	/**
	* 创建Button
	*/
	static UIBase * createButton(const CCPoint &position,const CCSize &size,const char * upImgName,const char *downImgName,UIPanel *parent = NULL,int uniqueId = -1);
	static UIBase * createButton(const CCPoint &position,const CCSize &size,const char* buttonName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * 创建label
	 **/
	static UIBase *createLabel(const CCPoint &position,const CCSize &size,const char *content,float fontSize,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * 创建textfield
	 */
	static UIBase *createTextField(const CCPoint& position,const CCSize &size,const char* defaultContent,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * 创建图像
	 */
	static UIBase *createImage(const CCPoint& position,const CCSize &size,const char *pngName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * 创建选择框
	 */
	static UIBase *createChoice(const CCPoint &position,const CCSize &size,const char * upImgName,const char *downImgName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * 创建lineValue
	 */
	static UIBase *createLineValue(const CCPoint &position,float minValue,float maxValue,float defaultValue,UIPanel * parent = NULL,int uniqueId = -1);
	/**
	 * 设置edit模式
	 */
	void setEditable();

	void addUI(UIBase *base);
	
	bool addGloabUI(UIBase *base);

	 /** 
	 * 检查是否在区域里
	 */
	virtual bool touchDown(float x,float y);
	/**
	 * 更新位置
	 */
	virtual bool touchMove(float x,float y);
	/**
	 * 停止拖动
	 */
	virtual bool touchEnd(float x,float y);

	/**
	 * 设置位置
	 */
	virtual void setPosition(float x,float y) ;
	
	/**
	 * 设置大小
	 */
	virtual void setSize(float w,float h) ;
	/**
	 * 获取UIBase
	 */
	UIBase *getUIById(int id);

	void setEditable(bool tag);
	static UIPanel* create();

	static UIPanel * createFromNode(script::tixmlCodeNode *node);
	/**
	 * 创建父节点下的子节点
	 */
	void makeXmlFile(const std::string &name);
	bool initXFromNode(script::tixmlCodeNode *node);
	UIPanel()
	{
		_moveable = true;
		_width = 500;
		_height = 500;
		_touchIn = false;
		back = NULL;
		_nowTouchUI = NULL;
		uiType = UIBase::UI_PANEL;
		_onlyMe = false; // 只响应自己的时间
	}
	void replaceBack(const char *pngName);
	void  setMovable(bool tag)
	{
		_moveable = tag;
	}
	

	void beLoaded();
	void loadFromFile(const char *fileName);

	void saveToFile(const char *fileName);

	void execEach(stExecPanelEach *exec);
	/**
	 * 展示自己是 只响应自身事件
	 */
	void beginModel(){_onlyMe = true;}
	bool isModel(){return _onlyMe;}
	void endModel(){_onlyMe = false;}
	UIBase *getUIByName(std::string name);
	void removeBack()
	{
		if (back)
		{
			this->removeChild(back,true);
			back = NULL;
		}
	}
	UIButton * createBtn(script::tixmlCodeNode &btnNode);
	UILabel * createLblFromNode(script::tixmlCodeNode * node);
	UINumber *createNumFromNode(script::tixmlCodeNode *node);
    UIImage * createImgFromNode(script::tixmlCodeNode *node);
	UIChoice * createChoiceFromNode(script::tixmlCodeNode *node);
    UIEditField *createFieldFromNode(script::tixmlCodeNode *node);
	void showByAction(int actionId);
	CCSprite *back;
	virtual bool isMovable(){return _moveable;}
protected:
	CCPoint nowTouchPoint;
	bool _moveable;
	bool _touchIn;
	std::vector<UIBase*> childuis;
	typedef std::vector<UIBase*>::iterator CHILD_UIS_ITER;
	/**
	 * 系统的基本界面集合
	 */
	std::vector<UIBase*> uis;
	std::map<std::string,UIBase *> nameuis;
	typedef std::map<std::string,UIBase*>::iterator NAME_UIS_ITER;
	float _width;
	float _height;
	UIBase *_nowTouchUI;
	bool _onlyMe;
	std::string backimg;
	static int const ALIGN_TOP = 1 << 0;
	static int const ALIGN_X_CENTER = 1 << 1;
	static int const ALIGN_DOWN = 1 << 2;
	static int const ALIGN_RIGHT = 1 << 3;
	static int const ALIGN_LEFT = 1 << 4;
	static int const ALIGN_Y_CENTER = 1 << 5;
};

template<class CHILD>
class BaseDialog:public script::tixmlCode,public UIPanel{
public:
	static CHILD* create(UIWindow *window,const char *uixml)
	{
		CHILD *node = new CHILD();
		if (node)
		{
			node->window = window;
			node->initFromFile(uixml);
			node->autorelease();
			return node;
		}
		CC_SAFE_DELETE(node);
		return NULL;
	}
	bool initFromFile(const char *fileName)
	{
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return false;
		if (script::tixmlCode::initFromString((char*)buffer))
		{
			doInitEvent();
			return true;
		}
		return false;
	}
	/**
	 * 从配置文件中加载配置
	 * \param node 配置根节点
	 */
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node && node->equal("Config"))
		{
 			// 加载Label TextArea Button 生成界面系统
			// 创建欢迎动画
			script::tixmlCodeNode mainNode = node->getFirstChildNode("start");
			std::string root = mainNode.getAttr("root");
			if (mainNode.isValid())
			{
				this->initXFromNode(&mainNode);
				if (root != "")
				{
					window->addUI(this);
				}
				else
					window->addPanel(this);
				this->setZOrder(12);
			}
		}
		vTakeNode(node);
	}
	virtual void vTakeNode(script::tixmlCodeNode *node){}
	BaseDialog()
	{
		window = NULL;
	}
	UIWindow *window;
protected:
	virtual void doInitEvent(){}
};

NS_CC_END