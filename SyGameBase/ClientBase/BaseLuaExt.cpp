#include "BaseLuaExt.h"
#include "MutiMap.h"
#include "UIWindow.h"
#include "UIBase.h"
#include "UIPanel.h"
#include "LuaCocos2d.h"
#include "UIItem.h"
#include "UISuperBag.h"
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "tolua++.h"
	#include "tolua_fix.h"
}
#include "lua_tinker.h"
NS_CC_BEGIN

BaseLuaExt* BaseLuaExt::create()
{
	BaseLuaExt * baseLuaExt = new BaseLuaExt();
	if (baseLuaExt)
	{
		baseLuaExt->init();
	}
	return baseLuaExt;
}
void BaseLuaExt::init()
{
	m_state = lua_open();
    luaL_openlibs(m_state);
    tolua_Cocos2d_open(m_state);
	_map = map;
	_monster = monster;
	_mainUI = mainUI;
	initLuaExt();
	 toluafix_open(m_state);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    addLuaLoader(loader_Android);
#endif
    return;
}
/**
 * lua环境的扩展
 * function function_net(object)
 *		// 登录成功
 *		
 * end
 * function doInitMainUI(base) // 回调函数1 
 *      mainUI:bind(1,doLoginIn);
 *      mainUI:bindnetcallbck(1,function_net);
 * end
 * function doLoginIn()
 *		theNet:send(1,"ssss:xxx");
 * end
 * mainUI = createUIMain("xxx.xml"); // xml文件可以使用编辑器生成
 */
void BaseLuaExt::initLuaExt()
{
	lua_tinker::class_add<MutiMap>(m_state, "MutiMap");
	lua_tinker::class_def<MutiMap>(m_state, "create", &MutiMap::create); // 创建

	lua_tinker::class_add<UIMain>(m_state, "UIMain");
	lua_tinker::class_def<UIMain>(m_state, "create", &UIMain::create); // 创建主界面系统

	lua_tinker::class_add<UIBase>(m_state, "UIBase");
	lua_tinker::class_mem<UIBase>(m_state, "x", &UIBase::x);
	lua_tinker::class_mem<UIBase>(m_state, "y", &UIBase::y);
	lua_tinker::class_def<UIBase>(m_state, "setVisible", &UIBase::setVisible); // 设置是否可见
	lua_tinker::class_def<UIBase>(m_state, "bind", &UIBase::bindLua); // 绑定lua脚本

	lua_tinker::class_add<UIPanel>(m_state, "UIPanel");
	lua_tinker::class_inh<UIPanel, UIBase>(m_state); // 继承UIbase 
	lua_tinker::class_def<UIPanel>(m_state, "getUILablevalue", &UIPanel::getUILablevalue); // 获取标签字段值
	lua_tinker::class_def<UIPanel>(m_state, "hide", &UIPanel::hide); // 隐藏
	lua_tinker::class_def<UIPanel>(m_state, "getEditFieldValue", &UIPanel::getEditFieldValue); // 获取输入框字段值
	lua_tinker::class_def<UIPanel>(m_state, "getUIByName", &UIPanel::getUIByName); // 获取控件
	
	// StoreBag 
	// 遍历器
	// iter = list:getIterator();
	// iter:getNext();
	//
	lua_tinker::class_add<UIBagIterator>(m_state, "UIBagIterator");
	lua_tinker::class_def<UIBagIterator>(m_state, "getNext", &UIBagIterator::getNext); // 获取下一个条目
	
	lua_tinker::class_add<CommonUIItem>(m_state, "CommonUIItem"); // 条目
	lua_tinker::class_def<CommonUIItem>(m_state, "getPanel", &CommonUIItem::getPanel); // 获取获取Panel
	lua_tinker::class_def<CommonUIItem>(m_state, "create", &CommonUIItem::create); // 创建

	lua_tinker::class_add<UISuperBag>(m_state, "UISuperBag");
	lua_tinker::class_def<UISuperBag>(m_state, "getIterator", &UISuperBag::getIterator); // 获取遍历器
	lua_tinker::class_def<UISuperBag>(m_state, "show", &UISuperBag::show); // 展示自己

	/**
	 * 创建Window
	 */
	lua_tinker::class_add<UIWindow>(m_state,"UIWindow");
	lua_tinker::class_inh<UIWindow, UIBase>(m_state); // 继承UIbase 
	lua_tinker::class_def<UIWindow>(m_state, "showPanel", &UIWindow::showPanel); // 展示Panel
	lua_tinker::class_def<UIWindow>(m_state, "getPanel", &UIWindow::getPanel); // 获取Panel

	/**
	 * panel:bindnetcallbck(1,function); // 绑定网络处理函数
	 * panel:bindbtnclick("",function); // 绑定按钮点击事件
	 * net:send(1,""); // 发送消息
	 */
	lua_tinker::set(m_state, "theNet", &theNet); // 全局对象 网络模块
}

void BaseLuaExt::doString(const char*cmd)
{
	 this->executeString(cmd);
	 return;
}

NS_CC_END