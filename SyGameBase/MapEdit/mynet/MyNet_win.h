//
//  MyNet.h
//  Dragon
//
//  Created by GameDeveloper on 13-10-20.
//
//

#ifndef Dragon_MyNet_h
#define Dragon_MyNet_h
#include "platfrom.h"
#if PLATFORM == PLATFORM_WIN32
#include "zlib.h"
#include <vector>
#include <string>
#include <list>
#include "mythread.h"
/**
 * �ر�����lua���
 */
namespace mynet{
    /**
     ******************************** 2ƽ��ƻ����******************************
     *
     * Buffer ��л�ȡ��Ϣ� �����õ�ǰλ�
     */
    class Record{
    public:
        Record(void *cmd,unsigned int len)
        {
            contents = new unsigned char[len];
            memcpy(contents,cmd,len);
            contentSize = len;
            offset = 0;
        }
        Record()
        {
            offset = 0;
            contentSize = 0;
            contents = NULL;
        }
        ~Record()
        {
            if (contents) delete contents;
            contents = NULL;
        }
        unsigned int recv(void *buffer,unsigned int len)
        {
            if (empty()) return 0;
            len = leftsize() < len ? leftsize(): len;
            memcpy(buffer,contents + offset,len);
            offset += len;
            return len;
        }
        unsigned int leftsize()
        {
            return contentSize - offset;
        }
        template<class CONNECTION>
        bool sendOver(CONNECTION *connection)
        {
            unsigned int leftSize = leftsize();
            if ( 0 == leftSize) return true;
            int sendLen = connection->send(contents + offset,leftSize);
            offset += sendLen;
            if (sendLen < leftSize) return false;
            return true;
        }
        unsigned int offset;
        bool empty()
        {
            return offset == contentSize;
        }
        unsigned int contentSize;
        unsigned char *contents;
    };
    /**
     * ****************************��̰߳�ȫ����Ϣ���************************
     */
    template<typename CLASS>
    class Node{
    public:
        CLASS node;
        Node<CLASS> *next;
        Node()
        {
            next = NULL;
        }
    };
    template<typename CLASS>
    class MyList{
    public:
        Node<CLASS> *readPointer;
        Node<CLASS> *writePointer;
        
        MyList()
        {
            writePointer = new Node<CLASS>();
            readPointer = writePointer;
        }
        void write(CLASS object)
        {
            if (writePointer)
            {
                writePointer->node = object;
                Node<CLASS> * node = new Node<CLASS>();
                writePointer->next = node;
                writePointer = node;
            }
        }
        bool empty()
        {
            if (readPointer == writePointer) return true;
            return false;
        }
        bool readOnly(CLASS &object)
        {
            if (empty()) return false;
            object = readPointer->node;
            return true;
        }
        bool readAndPop(CLASS &object)
        {
            if (readPointer == writePointer) return false;
            object = readPointer->node;
            Node<CLASS> * node = readPointer;
            readPointer = readPointer->next;
            delete node;
            return true;
        }
        bool pop()
        {
            if (readPointer == writePointer) return false;
            Node<CLASS> * node = readPointer;
            readPointer = readPointer->next;
            delete node;
            return true;
        }
        ~MyList()
        {
            if (writePointer)
            {
                delete writePointer;
            }
            writePointer = NULL;
        }
    };
    /**
     * *************************н��봦�����*****************************************
     */
    struct stGetPackage{
        virtual void doGetCommand(void *cmd,unsigned int len) = 0;
    };
    /**
     * �����
     */
    class Decoder{
    public:
        Decoder(){
            currentoffset = 0;
            nowstate = 0;
            tag = 0;
        }
    private:
        unsigned int currentoffset; // ?��?a?��?�ި�???�̡???ƨ�??
        std::vector<unsigned char> contents;
        
        enum{
            START,
            END,
            PICK_HEAD,
            PICK_BODY,
        };
        
        unsigned char nowstate; //
        unsigned char tag; //
        static const unsigned int MAX_DATASIZE = 65536; //
        enum{
            ZIP = 1 << 0, // ZIP
            DES = 1 << 1, // DES
            MIN_HEAD = 1 << 2, //
            MAX_HEAD = 1 << 3, //
        };
        
        unsigned leftsize();
        template<typename Record>
        bool pickdata(Record *record)
        {
            unsigned int left_size = leftsize();
            if (left_size == 0) return true;
            int ret = record->recv(&contents[currentoffset],left_size);
            if (ret < left_size)
            {
                currentoffset += ret;
                return false;
            }
            currentoffset += ret;
            return true;
        }
        void refresh();
        template<typename Record>
        bool run(Record *record)
        {
            if ( currentoffset == contents.size())
            {
                refresh();
                return pickdata(record) || isFinished();
            }
            return pickdata(record);
        }
        bool isFinished();
        void setbodysize(unsigned int size);
        unsigned int getbodysize();
    public:
        template<typename Record>
        unsigned int decode(Record * target,void *buffer,unsigned int maxSize) // ??�ꨢ?????
        {
            while(run(target))
            {
                if (isFinished())
                {
                    undes();
                    unsigned int retSize = unzip((unsigned char*)buffer,maxSize,0);
                    return retSize;
                }
            }
            return 0;
        }
        template<typename Record>
        void decode(Record *target,stGetPackage *callback) // ??�ꨢ?????
        {
            while(run(target))
            {
                if (isFinished())
                {
                    undes();
                    if (tag & ZIP)
                    {
                        unsigned char buffer[MAX_DATASIZE]={'\0'};
                        unsigned int retSize = unzip(buffer,MAX_DATASIZE,0);
                        if (callback)
                            callback->doGetCommand(buffer,retSize);
                    }
                    else if (contents.size())
                    {
                        if (callback)
                            callback->doGetCommand(&contents[0],contents.size());
                    }
                }
            }
        }
        Record * getRecord();
        void encode(void *data,unsigned int len,bool ziptag = false,bool destag = false);
    private:
        unsigned int unzip_size(unsigned int zip_size);
        unsigned int unzip(unsigned char *buffer,unsigned int len,unsigned int offset);
        
        void undes();
        unsigned int zip(void *data,unsigned int len,unsigned int offset);
		
        void des();
    };
    /**
     * *****************************��Ϣת���***********************************
     * obj.req({reqId=1,retId=2,data={content="hello,world"}},function(jsondata)
     *
     * end)
     * ����ﴦ��Ϊ �ص�� ���Դ���Я��object
     */
    class MsgFuncHandler{
    public:
        /**
         * ĵ����
         * \param delegate ���
         * \paran object ���
         */
        virtual void call(void* cmd,unsigned int cmdLen){
            
        }
    };
    /**
     * ����ຯ� ���ݺ��
     */
    template<class CLASS>
    class MsgFunction:public MsgFuncHandler{
    private:
        typedef int (CLASS::*Handle)(void* cmd,unsigned int cmdLen);
        Handle handle1;
        CLASS *object;
    public:
        /**
         * �ʹ�1úŷ�ʽ����
         * (Socket *,int ,void*)
         */
        MsgFunction(CLASS *object,Handle handle):object(object),handle1(handle){}
        
        /**
         * �����
         * \param delegate ���
         * \paran object ���
         */
        virtual void call(void* cmd,unsigned int cmdLen){
            if (object) // �У�
            {
                ((*object).*handle1)(cmd,cmdLen);
            }
        }
    };
    
    
    class Handles{
    public:
        bool addHandle(unsigned short type,MsgFuncHandler* handle);
       
        bool handle(unsigned short type,void*cmd,unsigned int cmdLen);
    private:
        std::vector<MsgFuncHandler*> tables;
    };
    /**
     *********************** Poolȴ����*******************************
     **/
    enum EVENT_TYPE{
		ACCEPT_EVT = 1 << 0,  
		OUT_EVT = 1 << 1, 
		IN_EVT =1 << 2,  
		ERR_EVT = 1 << 3, 
	};

	class EventBase;
	/**
	 * �Ŀ����
	 */
	class Target{
	public:
		virtual void* getHandle() = 0;
		virtual void* getPeerHandle() {return NULL;}
		EventBase *inEvt;
		EventBase *outEvt;
		Target()
		{
			inEvt = outEvt = NULL;
		}
		virtual void destroy()
		{
			if (inEvt)
				delete inEvt;
			if (outEvt)
				delete outEvt;
			inEvt = NULL;
			outEvt = NULL;
		}
		virtual void doSend(EventBase *evt){};
	};
	struct __OVERLAPPED {
    unsigned long Internal;
    unsigned long InternalHigh;
    union {
        struct {
            unsigned long  Offset;
            unsigned long  OffsetHigh;
        };

        void * Pointer;
    };

    void*  hEvent;
	};
	/**
	 * ��¼���
	 */
	class EventBase{
	public:
		__OVERLAPPED overlapped;
		Target * target; // �Ŀ�
		int eventType;     // ��ʶ�����������(Ͷ�Ӧ�����ö�)
		unsigned dataLen; // ���ݴ���ĳ��
		virtual void deal() = 0;
		
		EventBase(Target * target):target(target)
		{
			dataLen = 0;
		}
		virtual void* getPeerHandle() {return NULL;}
		
		bool isIn()
		{
			return eventType &IN_EVT;
		}
		bool isOut()
		{
			return eventType & OUT_EVT;
		}
		bool isErr()
		{
			return eventType & ERR_EVT;
		}
		bool isAccept()
		{
			return eventType & ACCEPT_EVT;
		}
		virtual void redo() = 0;
		static const unsigned int MAX_BUFFER_LEN = 9000;
	};
	
	/**
	 * ��¼�صķ�װ
	 **/
    class EventPool {
    public:
        EventPool()
        {
           
        }
		bool init();
		void* poolHandle;
        void bindEvent(Target *target,int eventType);
		EventBase* pullEvent();
    };
    /*
     *******************�ͻ��˷�����***********************
     */
    class Connection:public Target{
    public:
         virtual void destroy();
		 Connection();
		 void* getHandle();
		 void setHandle(unsigned int socket);
		 
		 /**
		  *
		  */
		 void sendCmd(void *cmd,unsigned int len);
		 void recvCmdCallback(void *cmd,unsigned int len);
		 Decoder decoder;
		 bool directDealCmd;
		 /** 
		  *  
		  */
		 unsigned int getCmd(void *cmd,unsigned int len);
		 /**
		  * 
		  **/
		 unsigned int recv(void *cmd,unsigned int size);
		 int send(void *cmd,unsigned int len);
		/**
		 * 
		 **/
		 void doRead(EventBase *evt,stGetPackage *callback = NULL);
		/**
		 *  
		 **/
		void doSend(EventBase *evt,bool over = true);

		thread::Mutex mutex;
		 //  
		unsigned int socket;
		MyList<Record*> recvs;
		MyList<Record*> sends;
    };
    /**
     * *************************Client ********************************
     */
    class Client:public Connection{
    public:
        Client(const char *ip,unsigned short port)
        {
			init(ip,port);
            this->peerIp = ip;
            this->port = port;
        }
        void reconnect()
        {
            init(peerIp.c_str(), port);
        }
        std::string peerIp;
        unsigned short port;
        void init(const char *ip,unsigned short port);
        void close();
		bool checkValid(){return socket != -1;}
    };
    /**
     **************************Server**********************************
     */
    class Server:public Target{
    public:
		Server(const char *ip,unsigned short port);
		void init(const char *ip,unsigned short port);
		void* getHandle(){return (void*)socket;}
		unsigned int socket;
	};
}
#endif
#endif