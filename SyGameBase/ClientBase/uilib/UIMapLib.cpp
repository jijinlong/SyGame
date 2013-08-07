#include "UIMapLib.h"
#include "UIWindow.h"
#include "UIPanel.h"
#include "UIBase.h"
#include "UIFileList.h"
#include "MutiMap.h"
#include "MutiMonster.h"
NS_CC_BEGIN
#define BIND_MAP_LIB_ACTION(func)\
	{\
		UIMapLibAction *action = new UIMapLibAction;\
		action->type = script::__ACTION_CHECK__;\
		action->action = &UIMapLib::func;\
		actions[#func] = action;\
	}

void UIMapLib::bindActions()
{
	BIND_MAP_LIB_ACTION(var);	
	BIND_MAP_LIB_ACTION(print);
	BIND_MAP_LIB_ACTION(calc);
	BIND_MAP_LIB_ACTION(exec);
// 相关扩展
	BIND_MAP_LIB_ACTION(show_panel);
	BIND_MAP_LIB_ACTION(move_allmonsters_to_touch_point);
}
void UIMapLib::initWithFile(const char *fileName)
{
	bindActions();
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	initFromString((char*)buffer);
}
void UIMapLib::takeNode(script::tixmlCodeNode* node)
{
	if (!node) return; // 处理事件
	
}
void UIMapLib::destroy()
{
	script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::release();
}

/**
 * 弹出界面 
 */
int UIMapLib::show_panel(UIMapStub* stub,script::tixmlCodeNode * node)
{
	if (stub && node && stub->window)
	{
		if (stub->nowTouchObject)
		{
			UIPanel *panel = stub->window->showPanel(node->getAttr("name"));
			if(panel)
				panel->setPosition(stub->nowTouchPoint.x,stub->nowTouchPoint.y);
			stub->window->pushModel(panel);
			panel->setVisible(true);
		}
		return 1;
	}
	return 0;
}
/**
 * 设置所有怪物移动到touch点
 */
struct doCtlMonster:public stExecEachMonster{
	void exec(MutiMonster *monster)
	{
		if (monster)
		{
			monster->tryMoveUseAstr(dest);
		}
	}
	doCtlMonster(const GridIndex &point):dest(point){}

	GridIndex dest;
};
int UIMapLib::move_allmonsters_to_touch_point(UIMapStub* stub,script::tixmlCodeNode * node)
{
	if (stub && stub->map)
	{
		
		GridIndex index = stub->map->getIndexByLocation(stub->nowTouchPoint);
		doCtlMonster exec(index);
		stub->map->execAllMonster(&exec);
		return 1;
	}
	return 0;
}
/**
 * 检查当前怪物类型
 */
int UIMapLib::check_object_type(UIMapStub* stub,script::tixmlCodeNode * node)
{
	return 0;
}
/**
 * 当前选择为空
 */
 int UIMapLib::check_null_pick(UIMapStub* stub,script::tixmlCodeNode * node)
 {
	return 0;
 }
NS_CC_END