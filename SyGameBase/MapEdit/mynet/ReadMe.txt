// C++ 使用模块
CocosNet::getMe().init();
CocosNet::getMe().newClient(1,"112.124.26.245",5050);
LuaReqData *data= LuaReqData::create();
data->content = "hello,world";
CocosNet::getMe().sendtoServer(1,data);


-- 测试网络模块 lua使用模块
sync.init()
sync.req({reqData=1},function(content)
    print(content)
end)
sync.req({reqData=2},function(content)
    print(content)
end)
local obj = "ewewe"
sync.req({idData=2},function(content)
    print(obj)
end)

sync.send(1,{}) -- 发送消息
sync.with(2,function(data) -- 处理指定的返回信息

end)