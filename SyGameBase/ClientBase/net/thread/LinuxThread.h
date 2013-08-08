#ifndef _ZTHREAD_H
#define _ZTHREAD_H

/*************************************************锁处理开始*****************************************************/

class zCond;

//互斥琐
class zMutex : private zNoncopyable
{
	friend class zCond;
public:
	zMutex() 
	{
		pthread_mutex_init(&mutex, NULL);
	}
	~zMutex()
	{
		pthread_mutex_destroy(&mutex);
	}
	inline void lock()
	{
		pthread_mutex_lock(&mutex);
	}
	inline void unlock()
	{
		pthread_mutex_unlock(&mutex);
	}
private:
	pthread_mutex_t mutex;
};

//方便在复杂函数中锁的使用
class zMutex_scope_lock : private zNoncopyable
{
public:
	zMutex_scope_lock(zMutex &m) : mlock(m)
	{
		mlock.lock();
	}
	//对锁进行unlock操作
	~zMutex_scope_lock()
	{
		mlock.unlock();
	}
private:
	zMutex &mlock;
};

//读写琐
class zRWLock : private zNoncopyable
{
public:
	//读写计数测试
	DWORD rd_count;
	DWORD wr_count;

	zRWLock() : rd_count(0), wr_count(0)
	{
		pthread_rwlock_init(&rwlock, NULL);
	}
	
	~zRWLock()
	{
		pthread_rwlock_destroy(&rwlock);
	}

	inline void rdlock()
	{
		pthread_rwlock_rdlock(&rwlock);
		++rd_count;
	}

	inline void wrlock()
	{
		pthread_rwlock_wrlock(&rwlock);
		++wr_count;
		++rd_count;
	}

	inline void unlock()
	{
		pthread_rwlock_unlock(&rwlock);
		--rd_count;
	}

	pthread_rwlock_t rwlock;
};

class zRWLock_scope_rdlock : private zNoncopyable
{
public:
	zRWLock_scope_rdlock(zRWLock &m) : rwlock(m)
	{
		rwlock.rdlock();
	}

	~zRWLock_scope_rdlock()
	{
		rwlock.unlock();
	}
private:
	zRWLock &rwlock;
};

class zRWLock_scope_wrlock : private zNoncopyable
{
public:
	zRWLock_scope_wrlock(zRWLock &m) : rwlock(m)
	{
		rwlock.wrlock();
	}

	~zRWLock_scope_wrlock()
	{
		rwlock.unlock();
	}
private:
	zRWLock &rwlock;
};

class zCond : private zNoncopyable
{
public:
	zCond()
	{
		::pthread_cond_init(&cond, NULL);
	}
	~zCond()
	{
		::pthread_cond_destroy(&cond);
	}
	void broadcast()
	{
		::pthread_cond_broadcast(&cond);
	}
	void signal()
	{
		::pthread_cond_signal(&cond);
	}
	void wait(zMutex &mutex)
	{
		::pthread_cond_wait(&cond, &mutex.mutex);
	}
private:
	pthread_cond_t cond;
};

class zThread : private zNoncopyable
{
public:
	/**
	* \brief 构造函数，创建一个对象
	* \param name 线程名称
	* \param joinable 标明这个线程退出的时候是否保存状态，如果为true表示线程退出保存状态，否则将不保存退出状态
	*/
	zThread(const std::string &name = std::string("zThread"),const bool joinable = true) 
		: threadName(name),alive(false),complete(false),joinable(joinable)
       	{
	       	mthread = 0; 
	};

	virtual ~zThread()
	{
	}

	/**
	* \brief 使当前线程睡眠指定的时间，秒
	* \param sec 指定的时间，秒
	*/
	static void sleep(const long sec)
	{
		::sleep(1000 * sec);
	}

	/**
	* \brief 使当前线程睡眠指定的时间，毫秒
	* \param msec 指定的时间，毫秒
	*/
	static void msleep(const long msec)
	{
		::sleep(msec);
	}

	/**
	* \brief 使当前线程睡眠指定的时间，微秒
	* \param usec 指定的时间，微秒
	*/
	static void usleep(const long usec)
	{
		::sleep(usec / 1000);
	}

	/**
	* \brief 线程是否是joinable的
	* \return joinable
	*/
	const bool isJoinable() const
	{
		return joinable;
	}

	/**
	* \brief 检查线程是否在运行状态
	* \return 线程是否在运行状态
	*/
	const bool isAlive() const
	{
		return alive;
	}

	static void* threadFunc(void *arg);	//nice
	bool start();
	void join();

	/**
	* \brief 主动结束线程
	* 其实只是设置标记，那么线程的run主回调循环回检查这个标记，如果这个标记已经设置，就退出循环
	*/
	void final()
	{
		complete = true;
	}

	/**
	* \brief 判断线程是否继续运行下去
	* 主要用在run()函数循环中，判断循环是否继续执行下去
	* \return 线程主回调是否继续执行
	*/
	const bool isFinal() const 
	{
		return complete;
	}

	/**
	* \brief 纯虚构函数，线程主回调函数，每个需要实例华的派生类需要重载这个函数
	*
	* 如果是无限循环需要在每个循环检查线程退出标记isFinal()，这样能够保证线程安全退出
	* <pre>
	*   while(!isFinal())
	*   {
	*     ...
	*   }
	*   </pre>
	*
	*/
	virtual void run() = 0;

	/**
	* \brief 判断两个线程是否是同一个线程
	* \param other 待比较的线程
	* \return 是否是同一个线程
	*/
	bool operator==(const zThread& other) const
	{
		return pthread_equal(mthread,other.mthread) != 0;
	}

	/**
	* \brief 返回线程名称
	*
	* \return 线程名称
	*/
	const std::string &getThreadName() const
	{
		return threadName;
	}

public:

	std::string threadName;          /**< 线程名称 */
	zMutex mlock;         		 /**< 互斥锁 */
	zCond cond;			 //条件变量
	volatile bool alive;      	 /**< 线程是否在运行 */
	volatile bool complete;
	pthread_t mthread;		 //管理的线程id
	bool joinable;          	 /**< 线程属性，是否设置joinable标记 */
}; 

/**
* \brief 对线程进行分组管理的类
*/
class zThreadGroup : private zNoncopyable
{

public:
	typedef std::vector<zThread *> Container; 

	struct Callback
	{
		virtual void exec(zThread *e)=0;
		virtual ~Callback(){};
	};

	zThreadGroup();
	~zThreadGroup();
	void add(zThread *thread);
	zThread *getByIndex(const Container::size_type index);
	zThread *operator[] (const Container::size_type index);

	void joinAll();
	void execAll(Callback &cb);

	const Container::size_type size()
	{
		zRWLock_scope_rdlock scope_rdlock(rwlock);
		return vts.size();
	}

private:
	Container vts;                /**< 线程向量 */
	zRWLock rwlock;                /**< 读写锁 */
};

#endif
