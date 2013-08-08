//
//  KqueuePool.h
//  kqueue
//
//  Created by 季 金龙 on 13-7-30.
//  Copyright (c) 2013年 季 金龙. All rights reserved.
//

#ifndef kqueue_KqueuePool_h
#define kqueue_KqueuePool_h
#include "sys/socket.h"
#include <sys/time.h>
#include "sys/poll.h"
#include "sys/select.h"
#include "sys/types.h"
#include "netinet/in.h"
#include "fcntl.h"
#include "netdb.h"
#include "signal.h"
#include "memory.h"
#include <arpa/inet.h>
#include <pthread.h>
#include "strings.h"
#include "iconv.h"
#include <strings.h>
#include "unistd.h"
#include "poll.h"
#include "sys/event.h"
#include <sys/types.h>
namespace pool{
	void load(){}
	void unload(){}
    enum EVENT_TYPE{
        IN_EVT = 1 << 0,
        OUT_EVT = 1 << 1,
        ERR_EVT = 1 << 2,
        ACCEPT_EVT = 1 << 3,
    };
    class Target{
    public:
        virtual int getHandle() = 0;
		virtual int getPeerHandle() {return -1;}
    };
    class EventBase{
    public:
        int eventType;
        void delEevnt(int eventType)
        {
            if ((eventType & IN_EVT) | (ACCEPT_EVT & eventType))
            {
                struct kevent kevts[1];
                EV_SET(&kevts[0], target->getHandle(), EVFILT_READ, EV_DELETE, 0, 0, this);
                kevent(poolHandle, kevts, 1, NULL, 0, NULL);
                this->eventType &= ~IN_EVT;
            }
            if (eventType & OUT_EVT)
            {
                struct kevent kevts[1];
                EV_SET(&kevts[0], target->getHandle(), EVFILT_WRITE,EV_DELETE, 0, 0, this);
                kevent(poolHandle, kevts, 1, NULL, 0, NULL);
                this->eventType &= ~OUT_EVT;
            }
        }
        void addEvent(int eventType)
        {
            this->eventType |= eventType;
            if ((eventType & IN_EVT) | (ACCEPT_EVT & eventType))
            {
                struct kevent kevts[1];
                EV_SET(&kevts[0], target->getHandle(), EVFILT_READ, EV_ADD, 0, 0, this);
                kevent(poolHandle, kevts, 1, NULL, 0, NULL);
            }
            if (eventType & OUT_EVT)
            {
                struct kevent kevts[1];
                EV_SET(&kevts[0], target->getHandle(), EVFILT_WRITE,EV_ADD, 0, 0, this);
                kevent(poolHandle, kevts, 1, NULL, 0, NULL);
            }

        }
        int poolHandle;
        Target *target;
        EventBase(Target *target):target(target){}
        
        bool isOut()
        {
            return eventType & OUT_EVT;
        }
        
        bool isIn(){
            return eventType & IN_EVT;
        }
        
        bool isError()
        {
            return eventType & ERR_EVT;
        }
		int getPeerHandle()
		{
			return target->getPeerHandle();
		}
    };
    template<typename TARGET>
    class Event:public EventBase{
    public:
        TARGET* operator->()
        {
            return (TARGET*) target;
        }
        Event(TARGET *target):EventBase(target){
        
        }
    };
    class EventPool{
    public:
        void init()
        {
            poolHandle = kqueue();
            index = 0;
            maxCount = 0;
        }
        void bindEvent(EventBase *evt,int eventType)
        {
            evt->poolHandle = poolHandle;
            evt->addEvent(eventType);
        }
        static const unsigned int MAX_EVENT_COUNT = 100;
        EventBase * pullEvent()
        {
            if (index == maxCount)
            {
                maxCount = kevent(poolHandle, NULL, 0, events, MAX_EVENT_COUNT, NULL);
                index = 0;
            }
            if (index < maxCount)
            {
                EventBase* base = (EventBase*) events[index].udata;
                index++;
                return base;
            }
            return NULL;
        }
        int poolHandle;
        struct kevent events[MAX_EVENT_COUNT];
        int index;
        int maxCount;
    };
}
namespace net{
    class Connection:public pool::Target{
    public:
        int getHandle(){return socket;}
        void setHandle(int socket){this->socket = socket;}
        void read(){
			char buffer[1034] = {'\0'};
			::recv(socket,buffer,1024,0);
			printf("recv:%s\n",buffer);
        }
        int index;
        void send(){
			char buffer[1024]={'\0'} ;
            sprintf(buffer,"OK %d",index++);
			::send(socket,buffer,strlen(buffer),0);
        }
        Connection()
        {
  			index = 0;
        }
        int socket;
    };
    class Server:public pool::Target{
    public:
		Server(const char *ip,unsigned short port)
		{
			init(ip,port);
		}
		void init(const char *ip,unsigned short port)
		{
			struct sockaddr_in ServerAddress;
            
			socket = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			setnonblock(socket);
			int reuse = 1;
			setsockopt(socket,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
            
			memset((char *)&ServerAddress,0, sizeof(ServerAddress));
			ServerAddress.sin_family = AF_INET;
			ServerAddress.sin_addr.s_addr = inet_addr(ip);
			ServerAddress.sin_port = htons(port);
            
			bind(socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress));
            
			listen(socket,4026);
		}
		void setnonblock(int socket)
		{
			int opts;
			opts=fcntl(socket,F_GETFL);
			if(opts<0)
			{
				return;
			}
			opts = opts|O_NONBLOCK;
			if(fcntl(socket,F_SETFL,opts)<0)
			{
				return;
			}
		}
		int getPeerHandle(){
			socklen_t clilen = 1024;
			struct sockaddr_in addr;
			int con = ::accept(socket,(struct sockaddr*)(&addr),&clilen);
			setnonblock(con);
			return con;
		}	
		int getHandle(){return socket;}
		int socket;
    };
};
#endif
