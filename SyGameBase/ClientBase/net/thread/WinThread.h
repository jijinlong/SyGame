#pragma once
#include <list>
#include <windows.h>
#include <vector>
class zCond;
/**
* \brief 临界区，封装了系统临界区，避免了使用系统临界区时候需要手工初始化和销毁临界区对象的操作
*
*/
class zMutex
{

	friend class zCond;

public:
	/**
	* \brief 构造函数，构造一个互斥体对象
	*
	*/
	zMutex() 
	{
		m_hMutex = CreateMutex(NULL,FALSE,NULL);
	}

	/**
	* \brief 析构函数，销毁一个互斥体对象
	*
	*/
	~zMutex()
	{
		CloseHandle(m_hMutex);
	}

	/**
	* \brief 加锁一个互斥体
	*
	*/
	inline void lock()
	{
		if( WaitForSingleObject(m_hMutex,10000) == WAIT_TIMEOUT )
		{
			//TODO error
		}
	}

	/**
	* \brief 解锁一个互斥体
	*
	*/
	inline void unlock()
	{
		ReleaseMutex(m_hMutex);
	}

private:

	HANDLE m_hMutex;    /**< 系统互斥体 */

};

/**
* \brief Wrapper
* 方便在复杂函数中锁的使用
*/
class zMutex_scope_lock
{

public:

	/**
	* \brief 构造函数
	* 对锁进行lock操作
	* \param m 锁的引用
	*/
	zMutex_scope_lock(zMutex &m) : mlock(m)
	{
		mlock.lock();
	}

	/**
	* \brief 析购函数
	* 对锁进行unlock操作
	*/
	~zMutex_scope_lock()
	{
		mlock.unlock();
	}

private:

	/**
	* \brief 锁的引用
	*/
	zMutex &mlock;

};
/**
* \brief 封装了系统读写锁，使用上要简单，省去了手工初始化和销毁系统读写锁的工作，这些工作都可以由构造函数和析构函数来自动完成
*
*/
class zRWLock
{

public:
	/**
	* \brief 构造函数，用于创建一个读写锁
	*
	*/
	zRWLock()
	{
		m_hMutex = CreateMutex(NULL,FALSE,NULL);
	}

	/**
	* \brief 析构函数，用于销毁一个读写锁
	*
	*/
	~zRWLock()
	{
		CloseHandle(m_hMutex);
	}

	/**
	* \brief 对读写锁进行读加锁操作
	*
	*/
	inline void rdlock()
	{
		WaitForSingleObject(m_hMutex,INFINITE);
	};

	/**
	* \brief 对读写锁进行写加锁操作
	*
	*/
	inline void wrlock()
	{
		WaitForSingleObject(m_hMutex,INFINITE);
	}

	/**
	* \brief 对读写锁进行解锁操作
	*
	*/
	inline void unlock()
	{
		ReleaseMutex(m_hMutex);
	}

private:

	HANDLE m_hMutex;    /**< 系统读写锁 */

};
/**
* \brief rdlock Wrapper
* 方便在复杂函数中读写锁的使用
*/
class zRWLock_scope_rdlock
{

public:

	/**
	* \brief 构造函数
	* 对锁进行rdlock操作
	* \param m 锁的引用
	*/
	zRWLock_scope_rdlock(zRWLock &m) : rwlock(m)
	{
		rwlock.rdlock();
	}

	/**
	* \brief 析购函数
	* 对锁进行unlock操作
	*/
	~zRWLock_scope_rdlock()
	{
		rwlock.unlock();
	}

private:

	/**
	* \brief 锁的引用
	*/
	zRWLock &rwlock;

};

/**
* \brief wrlock Wrapper
* 方便在复杂函数中读写锁的使用
*/
class zRWLock_scope_wrlock
{

public:

	/**
	* \brief 构造函数
	* 对锁进行wrlock操作
	* \param m 锁的引用
	*/
	zRWLock_scope_wrlock(zRWLock &m) : rwlock(m)
	{
		rwlock.wrlock();
	}

	/**
	* \brief 析购函数
	* 对锁进行unlock操作
	*/
	~zRWLock_scope_wrlock()
	{
		rwlock.unlock();
	}

private:

	/**
	* \brief 锁的引用
	*/
	zRWLock &rwlock;

};
/**
* \brief 封装了系统条件变量，使用上要简单，省去了手工初始化和销毁系统条件变量的工作，这些工作都可以由构造函数和析构函数来自动完成
*
*/
class zCond 
{

public:

	/**
	* \brief 构造函数，用于创建一个条件变量
	*
	*/
	zCond()
	{
		m_hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
	}

	/**
	* \brief 析构函数，用于销毁一个条件变量
	*
	*/
	~zCond()
	{
		CloseHandle(m_hEvent);
	}

	/**
	* \brief 对所有等待这个条件变量的线程广播发送信号，使这些线程能够继续往下执行
	*
	*/
	void broadcast()
	{
		SetEvent(m_hEvent);
	}

	/**
	* \brief 对所有等待这个条件变量的线程发送信号，使这些线程能够继续往下执行
	*
	*/
	void signal()
	{
		SetEvent(m_hEvent);
	}

	/**
	* \brief 等待特定的条件变量满足
	*
	*
	* \param m_hMutex 需要等待的互斥体
	*/
	void wait(zMutex &mutex)
	{
		WaitForSingleObject(m_hEvent,INFINITE);
	}

private:

	HANDLE m_hEvent;    /**< 系统条件变量 */

};

/**
* \brief 封装了线程操作，所有使用线程的基类
*
*/
class zThread
{
public:

	/**
	* \brief 构造函数，创建一个对象
	*
	* \param name 线程名称
	* \param joinable 标明这个线程退出的时候是否保存状态，如果为true表示线程退出保存状态，否则将不保存退出状态
	*/
	zThread(const std::string &name = std::string("zThread"),const bool joinable = true) 
		: threadName(name),alive(false),complete(false),joinable(joinable) { m_hThread = NULL; };

	/**
	* \brief 析构函数，用于销毁一个对象，回收对象空间
	*
	*/
	virtual ~zThread()
	{
		if (NULL != m_hThread)
		{
			CloseHandle(m_hThread);
		}
	};

	/**
	* \brief 使当前线程睡眠指定的时间，秒
	*
	*
	* \param sec 指定的时间，秒
	*/
	static void sleep(const long sec)
	{
		::Sleep(1000 * sec);
	}

	/**
	* \brief 使当前线程睡眠指定的时间，毫秒
	*
	*
	* \param msec 指定的时间，毫秒
	*/
	static void msleep(const long msec)
	{
		::Sleep(msec);
	}

	/**
	* \brief 使当前线程睡眠指定的时间，微秒
	*
	*
	* \param usec 指定的时间，微秒
	*/
	static void usleep(const long usec)
	{
		::Sleep(usec / 1000);
	}

	/**
	* \brief 线程是否是joinable的
	*
	*
	* \return joinable
	*/
	const bool isJoinable() const
	{
		return joinable;
	}

	/**
	* \brief 检查线程是否在运行状态
	*
	* \return 线程是否在运行状态
	*/
	const bool isAlive() const
	{
		return alive;
	}

	static DWORD WINAPI threadFunc(void *arg);
	bool start();
	void join();

	/**
	* \brief 主动结束线程
	*
	* 其实只是设置标记，那么线程的run主回调循环回检查这个标记，如果这个标记已经设置，就退出循环
	*
	*/
	void final()
	{
		complete = true;
	}

	/**
	* \brief 判断线程是否继续运行下去
	*
	* 主要用在run()函数循环中，判断循环是否继续执行下去
	*
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
	* \brief 返回线程名称
	*
	* \return 线程名称
	*/
	const std::string &getThreadName() const
	{
		return threadName;
	}

public:

	std::string threadName;      /**< 线程名称 */
	zMutex mlock;          /**< 互斥锁 */
	volatile bool alive;      /**< 线程是否在运行 */
	volatile bool complete;
	HANDLE m_hThread;        /**< 线程编号 */
	bool joinable;          /**< 线程属性，是否设置joinable标记 */

}; 

/**
* \brief 对线程进行分组管理的类
*
*/
class zThreadGroup
{

public:

	struct Callback
	{
		virtual void exec(zThread *e)=0;
		virtual ~Callback(){};
	};

	typedef std::vector<zThread *> Container;  /**< 容器类型 */

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