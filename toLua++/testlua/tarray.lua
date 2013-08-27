require("json")
require("base64")

test = {
  one='first',two='second',three={2,3,5}
}

jsonTest = json.encode(test)
print('JSON encoded test is: ' .. jsonTest)
local PAR_TABLE =  
{  
    MAPNAME = "冰星",  
    MONSTER = {"哥斯拉", 1, 1},  --表项为常量的也需声明为常量表  
}  
print(PAR_TABLE.MAPNAME)
print(PAR_TABLE.MONSTER[2])

local NET_COMMAND_ID={
	LOGIN_IN = 1,
	RET_LOGIN = 2,
}

print("Array test OK"..a[9])
--a[0].test = "HHHEHEHEHHEHEHEHEHEHEHE"
--print(a[0].test)
Monster={
	onclick=function()
		print("jack i am")
	end,
}

Monster.onclick=function(d) print(" jack i changed"..d) end

Monster.onclick(100)

function testFunctionBack(i)
	print("....testFunctionBack...."..i)
end

local funcStr = base64.funstring(testFunctionBack)

--bind(funcStr,funcStrLen)


local func = base64.stringfun(funcStr)(111)
print("=================================")
obj = TestObject:new_local()
print(obj)
obj:callFunc(base64.funstring(function(i) -- 函数式编程 极大的化简了编程的模式 使用于现有的UI 和文件回调 以及网络回调
	print("hello,world"..i)
	print(obj)
end))

obj:doFunc()



