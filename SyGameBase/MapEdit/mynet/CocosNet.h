//
//  CocosNet.h
//  Dragon
//
//  Created by GameDeveloper on 13-10-20.
//
//

#ifndef Dragon_CocosNet_h
#define Dragon_CocosNet_h
#include "cocos2d.h"
#include "mynet.h"
#include "cmdobject.h"
/**
 * use example
 * CocosNet::getMe().init();
 * CocosNet::getMe().newClient(1,"",5050);
 * CocosNet::getMe().sendObject(1,cmdobj);
 * CocosNet::getMe().bind(1,handle);
 * use in lua
 * sync.req({data=jsondata,innerdata=obj},function(jsondata)
 *      -- 处理数据
 * end)
 */
class CocosNet;
class IO{
public:
	void start(CocosNet *net);
};

struct stReqData:public cocos2d::CCObject{
public:
    int reqId;
    stReqData()
    {
        reqId = 0;
    }
    ~stReqData()
    {
        
    }
};
/**
 * lua的请求数据
 */
class LuaReqData:public stReqData{
public:
    std::string content; // 发送的内容
    LuaReqData(){}
    ~LuaReqData(){}
    static LuaReqData * create()
    {
        LuaReqData * req = new LuaReqData();
        req->autorelease();
        return req;
    }
    void setContent(const char *content)
    {
        this->content =  content;
    }
};
/**
 * 发送到服务器
 */
class protoStringCmd:public CmdObject{
public:
    int reqID;
    std::string content;
    protoStringCmd():CmdObject(1)
    {
        reqID = 0;
    }
    CMD_SERIALIZE()
    {
        BIND(reqID);
        BIND(content);
    }
};

struct stWaitSendFileInfo{
	int fileSize;
	std::string fileName;
	int offset;
	int netIndex;
	stWaitSendFileInfo()
	{
		netIndex = -1;
		fileSize = 0;
		offset = 0;
	}
};
struct stSendFileInfo:public CmdObject{
	stSendFileInfo():CmdObject(8)
	{
		offset = 0;
	}
	int offset;
	std::vector<char> buffer;
	std::string fileName;
	CMD_SERIALIZE()
    {
        BIND(offset);
        BIND(buffer);
		BIND(fileName);
    }
};
class CocosNet:public cocos2d::CCObject,public mynet::Handles,public mynet::stGetPackage{
public:
	CocosNet()
	{
	}
    ~CocosNet()
    {}
    void newClient(int index,const char *ip,unsigned short port);
	void updateClient(int index);
	void init();
	void stop();
    static CocosNet * get()
    {
        return new CocosNet();
    }
    void sendtoServer(int index,LuaReqData *reqData);
public:
    IO io;
    mynet::EventPool *pool;
    std::vector<mynet::Client *> clients;
	static CocosNet & getMe()
	{
		static CocosNet t;
		return t;
	}
    void updateTimer(float dt);
	void bind(unsigned short commandID,mynet::MsgFuncHandler *handler)
	{
		addHandle(commandID,handler);
	}
    /**
	 * 
	 */
	void run();
	bool valid;
    
	void sendCmd(int index,void *cmd,unsigned int len);
private:
	void handle(void *cmd,unsigned int len);
    void doGetCommand(void *cmd,unsigned int len)
	{
		pushCommands(new mynet::Record(cmd,len));
	}
	void pushCommands(mynet::Record *record)
	{
		records.write(record); 
	}
	mynet::MyList<mynet::Record*> records;
	/**
     * 处理弹出消息   
	 */
	void popCommands()
	{
		mynet::Record * record = NULL;
		if (records.readAndPop(record))
		{
			handle(record->contents,record->contentSize); //
			delete record;
		}
		doSendFile();
	}
public:
	/**
	 * 确定文件大小 和 起始值
	 */
	void sendFile(int index,const char *fileName);
	/**
	 * 处理文件的发送
	 */
	mynet::MyList<stWaitSendFileInfo*> files;
	/**
	 * 实际发送文件
	 **/
	void doSendFile();

private:
    void sendObject(int index,CmdObject *object)
    {
        cmd::Stream ss = object->toStream();
        sendCmd(index,ss.content(),ss.size());
    }
	
    
    std::vector<stReqData*> reqDatas;
    std::set<int> emptyIDs; // 空闲ID号
    stReqData * getReqData(int reqId)
    {
        if (reqId < reqDatas.size())
        {
            return reqDatas[reqId];
        }
        return NULL;
    }
    void setReqData(stReqData *data)
    {
        if (emptyIDs.size())
        {
            int id = *emptyIDs.begin();
            emptyIDs.erase(emptyIDs.begin());
            reqDatas[id] = data;
            data->reqId = id;
        }else{
            data->reqId = reqDatas.size();
            reqDatas.push_back(data);
        }
    }
    void removeReqData(stReqData *data)
    {
        emptyIDs.insert(data->reqId);
        reqDatas[data->reqId] = NULL;
    }
};


#endif
