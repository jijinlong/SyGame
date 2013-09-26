#include "BitMap.h"
#include "stdio.h"

int main()
{
	BitMap map;
	map.set(65535);
	if (map.test(65535))
	{
		printf("hellow1 %d %d %d\n",map.size(),map.capacity(),map.tags.size());
	}
	map.reset(100);
	if (map.test(100))
	{
		printf("hellow2 %d\n",map.capacity());
	}
	map.set(0,32,111112127);
	int value = map.get(0,32);
	printf("value:%d",value);
	BitMap next;
	unsigned char buffer[200] = {'h','w','l','\0'};
	next.copyfrom(buffer,4);
	
	unsigned char buffer1[200] ={'\0'};
	next.copyto(buffer1,4);
	printf("next:value:%s",buffer1);
}