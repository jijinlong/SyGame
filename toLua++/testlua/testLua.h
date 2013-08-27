#pragma once

class TestLua{
public:
	void doCall(const char *str)
	{
		func = str;
	}
	const char *doFunc()
	{
		return func.c_str();
	}
	std::string func;
};