#pragma once
#include "sys/socket.h"
#include "sys/epoll.h"
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
#include "vector"
#include "list"
#include "stdio.h"
namespace pool{
	void load(){}
	void unload(){}
	enum EVENT_TYPE{
		ACCEPT_EVT = 1 << 0, 
		OUT_EVT = 1 << 1, 
		IN_EVT = 1 << 2,
		ERROR_EVT = 1 << 3,
	};
	class Target{
	public:
		virtual int getHandle() = 0;
		virtual int getPeerHandle() {return -1;}
	};
	class EventBase{
	public:
		EventBase(Target *target):target(target)
		{}
		Target *target;
		int eventType;	
		struct epoll_event ev;
		int poolHandle;
		virtual void deal()
		{
			ev.data.ptr = this;
		}
		void set(int eventType)
		{
			EventBase::eventType = eventType;
			EventBase::ev.events = 0;
			if (eventType & IN_EVT)
			{
				EventBase::ev.events |= EPOLLIN;
			}
			if (eventType & OUT_EVT)
			{
				EventBase::ev.events |= EPOLLOUT;
			}
			if (eventType & ACCEPT_EVT)
			{
				EventBase::ev.events |= EPOLLIN;
			}
		//	EventBase::ev.events |= EPOLLET;
		}
		virtual void reset(int eventType){
			set(eventType);	
			epoll_ctl(poolHandle,EPOLL_CTL_MOD,target->getHandle(),&ev);
		}
		virtual void leave()
		{
			epoll_ctl(poolHandle,EPOLL_CTL_DEL,target->getHandle(),&ev);
		}
		int getPeerHandle()
		{
			return target->getPeerHandle();
		}
	};
	template<typename TARGET>
	class Event:public EventBase{
	public:
		Event(TARGET *target):EventBase(target)
		{}
		TARGET * operator->()
		{
			return (TARGET*)target;
		}
	};

	class EventPool{
	public:
		EventPool()
		{

		}
		void init()
		{
			eventBuffer.resize(1024);
			poolHandle = epoll_create(256);
		}	
		void bindEvent(Target *target,int eventType)
		{
			Event<Target> *evt = new Event<Target>(target);
			evt->set(eventType);
			evt->poolHandle = poolHandle;
			evt->deal(); // 构建事件 
			epoll_ctl(poolHandle,EPOLL_CTL_ADD,evt->target->getHandle(),&evt->ev);
		}
		std::vector<struct epoll_event> eventBuffer;
		int poolHandle;
		EventBase *pullEvent()
		{
			static std::list<EventBase*> events;
			int retcode = epoll_wait(poolHandle,&eventBuffer[0],eventBuffer.size(),-1);
			if (events.empty())
			{
				for (int i = 0; i < retcode;i++)
				{
					EventBase *target = (EventBase*) eventBuffer[i].data.ptr;
					if (target)
					{
						events.push_back(target);
					}
				}
			}
			else
			{
				events.pop_front();
			}
			if (events.empty()) return NULL;
			return events.front();
		}	
	};
};


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
