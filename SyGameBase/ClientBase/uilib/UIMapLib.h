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
class UIMapStub;
class UIMapLib;
class UICallback;
class MutiObject;
class MutiMap;
typedef int (UIMapLib::*UIMapAction)(UIMapStub *,script::tixmlCodeNode *);

//执行点
class UIMapLibAction{
public:
	int type;
	UIMapAction action;
};

/**
 * ai 的执行者
 * */
class UIMapStub{
public:
	MutiMap *map;
	UIWindow *window;
	MutiObject *nowTouchObject;// 当前接触的对象
	CCPoint nowTouchPoint; // 当前接触的点
	UIMapStub()
	{
		map = NULL;
		window = NULL;
		nowTouchObject = NULL;
	}
};
/**
 * 执行库
 * 加载代码库 和 事件池 
 * 响应两种事件 点击事件 和 touch事件 可以触发各种行为 包括UI的展示
 **/
class UIMapLib:public script::Lib<UIMapLibAction,UIMapStub,UIMapLib>
{
public:
	UIMapLib()
	{
		bindActions();
	}
	static UIMapLib & getMe()
	{
		static UIMapLib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * 只有在scope="stub" 的时候 type 才有效
     */
    int var(UIMapStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::var(stub,node);
    }
    /**
     * 输出
     */
    int print(UIMapStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::print(stub,node);
    }
    /**
     * 计算变量
     **/
    int calc(UIMapStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::calc(stub,node);
    }
    /**
     * 执行其他节点
     **/
    int exec(UIMapStub* stub,script::tixmlCodeNode * node)
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
	 * 弹出界面 
	 */
	int show_panel(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * 设置所有怪物移动到touch点
	 */
	int move_allmonsters_to_touch_point(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * 检查当前怪物类型
	 */
	int check_object_type(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * 当前选择为空
	 */
	 int check_null_pick(UIMapStub* stub,script::tixmlCodeNode * node);
};

#define theMapUILib UIMapLib::getMe()

NS_CC_END
