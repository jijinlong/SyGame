#pragma once
/**
 * 怪物AI
 */

#include "scriptLib.h"
#include "cocos2d.h"
NS_CC_BEGIN
class UIWindow;
class UIPanel;
class UIBase;
class UIStub;
class UILib;
class UICallback;
typedef int (UILib::*UIAction)(UIStub *,script::tixmlCodeNode *);

//执行点
class UILibAction{
public:
	int type;
	UIAction action;
};

/**
 * ai 的执行者
 * */
class UIStub{
public:
	UIBase *base;
	UIWindow *window;
	UIStub()
	{
		base = NULL;
		window = NULL;
	}
	UIStub(UIBase *base,UIWindow *window):base(base),window(window)
	{}
};
/**
 * 执行库
 * 加载代码库 和 事件池
 **/
class UILib:public script::Lib<UILibAction,UIStub,UILib>
{
public:
	static UILib & getMe()
	{
		static UILib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * 只有在scope="stub" 的时候 type 才有效
     */
    int var(UIStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<UILibAction,UIStub,UILib>::var(stub,node);
    }
    /**
     * 输出
     */
    int print(UIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UILibAction,UIStub,UILib>::print(stub,node);
    }
    /**
     * 计算变量
     **/
    int calc(UIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UILibAction,UIStub,UILib>::calc(stub,node);
    }
    /**
     * 执行其他节点
     **/
    int exec(UIStub* stub,script::tixmlCodeNode * node)
    {
        execCode(stub,node->getAttr("name"));
        return 0;
    }
    void bindActions();
    void takeNode(script::tixmlCodeNode *node);
    /**
     * 清除资源
     * */
    void destroy();

/////////////////////////////////////////////////////////////////////////    
//			相关扩展
////////////////////////////////////////////////////////////////////////
    /**
	 * 展示自己
	 */
	int showme(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 隐藏自己 
	 **/
	int hideme(UIStub* stub,script::tixmlCodeNode * node);

	int hideparentpanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 改变自己位置
	 **/
	int setposition(UIStub *stub,script::tixmlCodeNode * node);
	/**
	 * 展示panel 
	 */
	int showpanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 隐藏Panel
	 */
	int hidepanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 绑定自身处理逻辑
	 **/
	int bind(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * 绑定自身panel 的处理逻辑 
	 */
	int panelbind(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 设置panel 上UILabel 的值
	 */
	int panel_label_set_value(UIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * 设置父类
	 */
	int parent_p_label_set_value(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 设置父类的bind
	 */
	int parent_p_bind(UIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * 展示所有文件
	 */
	int files_show(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * 设置选择框
	 */
	int panel_p_choice(UIStub *stub,script::tixmlCodeNode * node);
};

#define theUILib UILib::getMe()


class UICallbackManager{
public:
	UICallback * getCallback(const std::string &name)
	{
		CALLBACKS_ITER iter = callbacks.find(name);
		if (iter != callbacks.end())
		{
			return iter->second;
		}
		return NULL;
	}
	void addCallback(const std::string &name,UICallback* callback)
	{
		if (getCallback(name)) return;
		callbacks[name] = callback;
	}
	std::map<std::string,UICallback *> callbacks;
	typedef std::map<std::string,UICallback *>::iterator CALLBACKS_ITER;
	static UICallbackManager & getMe()
	{
		static UICallbackManager uicbm;
		return uicbm;
	}
	void clear()
	{
		for (CALLBACKS_ITER iter = callbacks.begin();iter != callbacks.end();++iter)
		{
			if (iter->second) delete iter->second;
		}
		callbacks.clear();
	}
};

#define UICALLBACK(name) UICallbackManager::getMe().getCallback(name)
NS_CC_END
