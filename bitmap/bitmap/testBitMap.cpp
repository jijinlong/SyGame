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
}