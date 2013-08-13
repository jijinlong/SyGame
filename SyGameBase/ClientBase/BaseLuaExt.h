/**
 * 
 */
#pragma once
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
NS_CC_BEGIN
/**
 * 地图lua的扩展
 */
class BaseLuaExt:public CCLuaEngine{
public:
	BaseLuaExt()
	{
	}
	static BaseLuaExt* create();
	/**
	 * lua环境的扩展
	 */
	void initLuaExt();

	void doString(const char *cmd);
private:
};


NS_CC_END