#include "mythread.h"
#include "stdio.h"
class MyThread:public thread::Thread{
public:
	void run()
	{
		while (true)
		{
			printf(".\n");
		}
	}
};
int main()
{	
	MyThread thread;
	thread.start();
	thread.join();
}

