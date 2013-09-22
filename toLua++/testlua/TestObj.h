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
		printf("ehuw\n");
	}
	const char *doFunc()
	{
		callFunc("TestObject:xxxx");
		return NULL;
	}
	std::string name;
};