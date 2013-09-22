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

function doMyCallback(obj)
	obj.doclick()
end

local func = base64.stringfun(funcStr)(111)
print("Test Object =================================")
local obj = TestObject:new_local()
obj.doclick = function()
	print(" i do click")
	print(obj.name)
end
obj.name = "jijinlong".."fuck111"
obj:doFunc(function(s) 
	print("hello,world"..s.name)
end)

local obj1 = TestObject:new_local()
obj1.doclick = function()
	print("111 i do click")
	print(obj1.name)
end
obj1:doFunc(function(s) 
	print("hello,world"..s.name)
end)

print("==================================处理table")

gloab_files={}

function insert(names)
	local a={}
	table.foreach(names, function(i, v)
		table.insert(a,{
			name = v,
			count = 0
		})
	end)
	table.insert(gloab_files,{
		value = a,
		allCount =0
	})
end

insert(
	{"hello","world"}
)

table.foreach(gloab_files, function(i, v)
	print(v.allCount)
	v.allCount = 100
	table.foreach(v.value,function(index,object) 
		print(object.name,object.count)
		object.count = 12
	end)
end)
table.foreach(gloab_files, function(i, v)
	print(v.allCount)
	table.foreach(v.value,function(index,object) 
		print(object.name,object.count)
	end)
end)


print("=================================处理string")

local var = "function sayhell()print(\"\xxxxxxxxxxxxxxxxxxx\") end sayhell()"

func =loadstring(var) ()

print("=========================")
function ssss()

	return "hehhe"
end
testTable={
	init = 	ssss (),
}

print(testTable.init)
print("==============================================");
function TouchBase(config)
	return {
		onTouchBegan = function(x,y) end,
		onTouchMoved = function(x,y) end,
		onTouchEnded = function(x,y) end
	}
end
function Button(config)
	local touch = TouchBase(config)
	local touchIn = false 
	touch.onTouchBegan = function(x,y) 
		touchIn = true
	end
	touch.onTouchMoved = function(x,y)
		print("touchMoved")
	end
	
	touch.onTouchEnded = function(x,y)
		print(touchIn)
	end
	--touch.sprite = CCSprite:create()
	--touch.upFrame = 
	--touch.downFrame = 
	return touch
end

local btn = Button({})

btn.onTouchBegan()
btn.onTouchMoved()
btn.onTouchEnded()