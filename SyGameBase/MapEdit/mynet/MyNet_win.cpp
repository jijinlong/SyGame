//
//  MyNet.cpp
//  Dragon
//
//  Created by GameDeveloper on 13-10-20.
//
//

#include "MyNet_win.h"
#if PLATFORM == PLATFORM_WIN32
#include <winsock2.h>
#include <MSWSock.h>
#pragma comment(lib,"ws2_32.lib")
class AcceptHelper{
public:
	AcceptHelper(){initLib = false;}
	void init(unsigned int socket)
	{
		if (initLib) return;
		initLib = true;
		GUID GuidAcceptEx = WSAID_ACCEPTEX;  
		DWORD dwBytes = 0;  
		if(SOCKET_ERROR == WSAIoctl(
			socket, 
			SIO_GET_EXTENSION_FUNCTION_POINTER, 
			&GuidAcceptEx, 
			sizeof(GuidAcceptEx), 
			&m_lpfnAcceptEx, 
			sizeof(m_lpfnAcceptEx), 
			&dwBytes, 
			NULL, 
			NULL))  
		{  
			initLib = false;
		}
	}
	static AcceptHelper &getMe()
	{
		static AcceptHelper helper;
		return helper;
	}
	void doAccept(SOCKET socket,SOCKET handle,WSABUF *lbuf,OVERLAPPED *lp)
	{
		init(socket);
		DWORD dwBytes = 0;  
		if(FALSE == (m_lpfnAcceptEx)(socket,
								handle,
								lbuf->buf,0,   
								sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, &dwBytes, lp)) 
			{  
				
			}
	}
	bool initLib;
	LPFN_ACCEPTEX m_lpfnAcceptEx;
};
namespace mynet {
    /**
     * *******************decoder ?????**********************
     */
    unsigned Decoder::leftsize()
	{
		return contents.size() -currentoffset;
	}
	void Decoder::refresh()
	{
		//
		switch(nowstate)
		{
			case START:
			{
				contents.resize(1);
				nowstate = PICK_HEAD;
				currentoffset = 0;
				tag = 0;
			}break;
			case PICK_HEAD:
			{
				tag = contents[0];
				if (tag & MIN_HEAD)
					contents.resize(1);
				else if (tag & MAX_HEAD)
					contents.resize(2);
				else
					printf("Decorder::refresh error %d\n",tag);
				nowstate = PICK_BODY;
				currentoffset = 0;
			}break;
			case PICK_BODY:
			{
				contents.resize(getbodysize());
				nowstate = END;
				currentoffset = 0;
				//printf("Will take body.size():%u\n",contents.size());
			}break;
			case END:
			{
				nowstate = START;
				contents.resize(0);
				currentoffset = 0;
				tag = 0;
			}break;
		}
	}
	bool Decoder::isFinished()
	{
		// ??????????????????
		return ((nowstate==END) && leftsize() == 0);
	}
	void Decoder::setbodysize(unsigned int size)
	{
		if (tag & MIN_HEAD)
		{
			*(unsigned char*)(&contents[1]) = size;
		}
		if (tag & MAX_HEAD)
		{
			*(unsigned short*)(&contents[1]) = size;
		}
	}
	unsigned int Decoder::getbodysize()
	{
		if (tag & MIN_HEAD)
		{
			return *(unsigned char*)&contents[0];
		}
		if (tag & MAX_HEAD)
		{
			return *(unsigned short*)&contents[0];
		}
		return 0;
	}
	Record * Decoder::getRecord()
	{
		Record *record = new Record(&contents[0],contents.size());
		return record;
	}
	void Decoder::encode(void *data,unsigned int len,bool ziptag,bool destag) // ??a????????
	{
		// ????????tag
		tag = 0;
		unsigned int headcontent = 0;
		if (len <= 255)
		{
			tag |= MIN_HEAD;
			ziptag = false; // ??????????????o??????????a?????
			headcontent = 1; // ?????????????????????????????????
		}
		else
		{
			tag |= MAX_HEAD;
			headcontent = 2;
		}
		if (ziptag) tag |= ZIP;
		if (destag) tag |= DES;
		
		if (ziptag)
		{
			len = zip(data,len,headcontent + 1);
		}
		else
		{
			contents.resize(len + headcontent + 1);
			memcpy(&contents[headcontent+1],data,len);
		}
		if (destag)
		{
			des();
		}
		
		contents[0] = tag;
		setbodysize(len);
	}
	unsigned int Decoder::unzip_size(unsigned int zip_size)
	{
		return zip_size * 120 / 100 + 12;
	}
	unsigned int Decoder::unzip(unsigned char *buffer,unsigned int len,unsigned int offset)
	{
		return len;
		// ??????
		if (tag & ZIP)
		{
			unsigned int unZipLen = len;
			int retcode = uncompress(buffer,(uLongf*)&unZipLen,&contents[offset],contents.size() - offset);
			return unZipLen;
		}
		return 0;
	}
	
	void Decoder::undes()
	{
		// ??????
		if (tag & DES)
		{
			
		}
	}
	unsigned int Decoder::zip(void *data,unsigned int len,unsigned int offset)
	{
		return len;
		if (tag & ZIP)
		{
			contents.resize(unzip_size(len));
			unsigned int outlen = 0;
			int retcode = compress(&contents[offset],(uLongf*)&outlen,(const Bytef *)data,len);
			contents.resize(outlen);
			len = outlen;
		}
		return len;
	}
	
	void Decoder::des()
	{
		if (tag & DES)
		{
			
		}
	}
    /**
     * *******************???????**************************
     */
    /**
	 * ????????????
	 * \param type ???????
	 * \param T_HANDLE handle ?????
	 **/
	bool Handles::addHandle(unsigned short type,MsgFuncHandler* handle)
	{
		if (type >= tables.size())
		{
			tables.resize(type + 1);
		}
		if (tables[type]) return false;
		tables[type] = handle;
		return true;
	}
	/**
	 * ??????
	 * \param object ???
	 * \param cmd ????
	 * \param len ??????
	 **/
	bool Handles::handle(unsigned short type,void*cmd,unsigned int cmdLen)
    {
		MsgFuncHandler *h = NULL;
		if (type >= tables.size())
		{
			return false;
		}
		h =  tables[type];
		if (h) {
			h->call(cmd,cmdLen);
			return true;
		}
		return false;
    }
    /**
     * Pool ?????
     **/
    template<typename TARGET>
	class Event:public EventBase{
    public:
        Event(TARGET *target):EventBase(target)
        {
			reset();
		}
        TARGET * operator->()
        {
            return (TARGET*)target;
        }
        bool checkValid()
        {
            return target;
        }
           
		WSABUF         m_wsaBuf;                                 
		char           buffer[MAX_BUFFER_LEN];             
		           
		DWORD msgLen;
		
		HANDLE poolHandle; 
		virtual void reset()
		{
			memset(buffer,0,MAX_BUFFER_LEN);
			memset(&overlapped,0,sizeof(overlapped));  
			m_wsaBuf.buf = buffer;
			m_wsaBuf.len = MAX_BUFFER_LEN;
			eventType     = 0;
			msgLen = 0;
		}
		virtual void deal(){};
		virtual void redo(){deal();}
    };
	/**
	 * ??????
	 */
	template<typename TARGET>
	class InEvent:public Event<TARGET>{
	public:
		InEvent(TARGET *target):Event<TARGET>(target)
        {
			
		}
		void deal()
		{
			DWORD dwFlags = 0;
			DWORD dwBytes = 0;
			WSABUF *p_wbuf   = &m_wsaBuf;
			OVERLAPPED *p_ol = (OVERLAPPED*)&overlapped;
			reset();
			eventType = IN_EVT;
			int nBytesRecv = WSARecv((SOCKET)target->getHandle(), p_wbuf, 1, &msgLen, &dwFlags, p_ol, NULL );
			if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
			{
				return;
			}
		}
	};
	/**
	 * ??????
	 */
	template<typename TARGET>
	class OutEvent:public Event<TARGET>{
	public:
		OutEvent(TARGET *target):Event<TARGET>(target)
		{
			
		}
		mynet::MyList<char*> buffers;
		void deal()
		{
			if (!dataLen) return;
			DWORD dwFlags = 0;
			msgLen = 0;
			WSABUF *p_wbuf   = &m_wsaBuf;
			m_wsaBuf.len = dataLen;
			OVERLAPPED *p_ol = (OVERLAPPED*)&overlapped;
			eventType = OUT_EVT;
			p_wbuf->buf = buffer;
			int nBytesRecv = WSASend((SOCKET)target->getHandle(), p_wbuf, 1, &msgLen, dwFlags, p_ol, NULL );
			if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
			{
				return;
			}
			return;
		}
	};
	/**
	 *  ???????
	 **/
	template<typename TARGET>
	class AcceptEvent:public Event<TARGET>{
	public:
		AcceptEvent(TARGET *target):Event<TARGET>(target)
		{
			SOCKET socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);  
			if( INVALID_SOCKET ==  socket)  
			{  
				return;  
			} 
			handle = socket;	
		}
		void deal()
		{
			DWORD dwBytes = 0;  
			eventType = ACCEPT_EVT;  
			WSABUF *p_wbuf   = &m_wsaBuf;
			OVERLAPPED *p_ol = (OVERLAPPED*)&overlapped;
			// ???AcceptEx
			
			AcceptHelper::getMe().doAccept((SOCKET)target->getHandle(),handle,p_wbuf,p_ol);
		}
		SOCKET handle;
		virtual HANDLE getPeerHandle() {return (HANDLE)handle;}
	};
   
	bool EventPool::init()
	{
		static bool initLoad = false;
		if (!initLoad)
		{
			WSADATA wsaData;
			int nResult;
			nResult = WSAStartup(MAKEWORD(2,2), &wsaData);
			initLoad = true;
		}
		poolHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0 );
		return poolHandle != NULL;
	}
    void EventPool::bindEvent(Target *target,int eventType)
	{
		 HANDLE tempHandle = CreateIoCompletionPort((HANDLE)target->getHandle(), poolHandle, (DWORD)target, 0);
		 if (eventType & ACCEPT_EVT)
		 {
			target->inEvt = new AcceptEvent<Target>(target);
			target->inEvt->deal();
		 }
		 if (eventType & IN_EVT)
		 {
			target->inEvt = new InEvent<Target>(target);
			target->inEvt->deal();
		 }
		 if (eventType & OUT_EVT)
		 {
			target->outEvt = new OutEvent<Target>(target);
			target->doSend(target->outEvt);
		 }
	}

	EventBase* EventPool::pullEvent()
	{
		// ????????
		OVERLAPPED *pOverlapped = NULL;
		Target*target = NULL;
		DWORD dataLen = 0;
		BOOL bReturn = GetQueuedCompletionStatus(
			poolHandle,
			&dataLen,
			(PULONG_PTR)&target,
			&pOverlapped,
			INFINITE
		);
		// ?????????????????????????
		if ( 0==(DWORD)target)
		{
			return NULL;
		}
		// ??�???????????
		if( !bReturn )  
		{
			if (!target->inEvt) return NULL;
			target->inEvt->eventType = ERR_EVT;
			return target->inEvt;  
		}  
		else  
		{
			// ??????????
			EventBase* evt = CONTAINING_RECORD(pOverlapped, EventBase, overlapped); 
			evt->dataLen = dataLen;
			// ??evt ???????
			if (dataLen == 0 && (evt->isIn() || evt->isOut()))
			{
				evt->eventType = ERR_EVT; // ???ب�????
			}
			return evt;
		}
		return NULL;
	}
	/**
	 * ??????
	 **/
	void Connection::destroy()
	{
		Target::destroy();
		closesocket(socket);
	}
	Connection:: Connection()
	{
		directDealCmd = true;
	}
	 void* Connection::getHandle(){return (void*)socket;}
	 void Connection::setHandle(unsigned int socket){this->socket = socket;}
	 
	 /**
	  * ???????
	  */
	 void Connection::sendCmd(void *cmd,unsigned int len)
	 {
		Decoder  decoder;
		decoder.encode(cmd,len);
		sends.write(decoder.getRecord());
		if (outEvt)
			doSend(outEvt,false);
	 }
	 void Connection::recvCmdCallback(void *cmd,unsigned int len)
	 {
		// ????�??????
	 }
	 /** 
	  * ??????
	  */
	 unsigned int Connection::getCmd(void *cmd,unsigned int len)
	 {
		return decoder.decode(this,cmd,len);
	 }
	 /**
	  * ?????????????
	  **/
	 unsigned int Connection::recv(void *cmd,unsigned int size)
	 {
		unsigned int realcopy = 0;
	//	while (recvs.size())
		while (!recvs.empty())
		{
			Record *record = NULL;
			if (recvs.readOnly(record))
			{
				realcopy = record->recv(cmd,size);
				if (record->empty())
				{
					delete record;
					recvs.pop();
				}
				if (realcopy == size)
				{
					return size;
				}
			}else break;
		}
		return realcopy;
	}
		
	/**
	 * ??pool ??է?????
	 **/
	 void Connection::doRead(EventBase *evt,stGetPackage *callback)
	{
		Event<Connection>* event = static_cast<Event<Connection>*>( evt );
		if (directDealCmd) // ??????????
		{
			Record record(event->m_wsaBuf.buf,evt->dataLen);
			decoder.decode(&record,callback);
		}
		else
		{
			Record *record = new Record(event->m_wsaBuf.buf,evt->dataLen);
			recvs.write(record);
		}
		evt->redo();
	}
	/**
	 * ?pool ??է????
	 **/
	void Connection::doSend(EventBase *evt,bool over)
	{
		thread::Mutex_scope_lock safelock(mutex);
		bool tag = false;
		Event<Connection>* event = static_cast<Event<Connection>*>( evt );
		if (event->msgLen < event->dataLen && !over)
		{
			return;
		}
		event->dataLen = 0;
		event->reset();
		int leftLen = EventBase::MAX_BUFFER_LEN;
		while (!sends.empty() && leftLen > 0)
		{
			tag = true;
			Record *record = NULL;
			if (sends.readOnly(record))
			{
				unsigned int realCopySize = record->recv(event->buffer,leftLen);
				evt->dataLen += realCopySize;
				
				if (leftLen == realCopySize)
				{
					leftLen = 0;
					if (record->empty())
					{
						delete record;
						sends.pop();
					}
					break;
				}
				else
				{
					leftLen -= realCopySize;
					if(!record->empty())
					{
						// TODO ERROR
					}
					sends.pop();
				}
			}else break;
		}
		if (tag)
			evt->redo();
	}
    /**
     * ???Client
     **/
    void Client::init(const char *ip,unsigned short port)
    {
        socket = ::socket(AF_INET,SOCK_STREAM,0);
        if(socket == -1)
        {
            // TODO error
        }
        struct sockaddr_in addrServer;

        memset(&addrServer,0,sizeof(sockaddr_in));
        addrServer.sin_family = AF_INET;
        addrServer.sin_addr.s_addr = inet_addr(ip);
        addrServer.sin_port = htons(port);
        
        if(connect(socket,(const struct sockaddr *)&addrServer,sizeof(sockaddr)) != 0)
        {
            // TODO error
            socket = -1;
        }
       // setnonblock(socket);
    }
    void Client::close()
    {
        
        socket = -1;
    }
    /**
     * ??Server
     */
	Server::Server(const char *ip,WORD port)
	{
		init(ip,port);
	}
	void Server::init(const char *ip,WORD port)
	{
		struct sockaddr_in ServerAddress;

		// ???????????Socket?????

		socket = (unsigned int)WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

		// ????????
		ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));
		ServerAddress.sin_family = AF_INET;
		//ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);                      
		ServerAddress.sin_addr.s_addr = inet_addr(ip);         
		ServerAddress.sin_port = htons(port);                          

		// ????????
		if (SOCKET_ERROR == ::bind((SOCKET)socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress))) 
		{
			return;
		}
		else
		{
		}

		// ??????է??
		if (SOCKET_ERROR == listen((SOCKET)socket,SOMAXCONN))
		{
			return;
		}
		else
		{
		}
	}
}
#endif