#pragma once
#include <string>
extern "C"{
#include "lualib.h"
#include "lauxlib.h"
#include "tolua++.h"
}
#include <sstream>
extern lua_State* L;
struct TestObject{
public:
	TestObject(){}
	void callFunc(const char *funcStr)
	{
		name = funcStr;
	}
	const char *doFunc()
	{
		std::stringstream ss;
		ss << "local func = base64.stringfun(\""<<name<<"\") func(12)";
		luaL_dostring(L,ss.str().c_str());
		return name.c_str();
	}
	std::string name;
};