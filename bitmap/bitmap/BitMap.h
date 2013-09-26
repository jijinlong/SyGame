#pragma once
#include <vector>
class BitMap{
public:
	BitMap()
	{
		maxSize =0;
	}
	unsigned int getBlockId(unsigned int index)
	{
		return index / (sizeof(unsigned int) * 8) ;
	}
	unsigned int getOffset(unsigned int index)
	{
		return index % (sizeof(unsigned int) * 8) ;
	}
	void set(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		tags[blockid] |= (1 << offset);
		if (index > maxSize) maxSize = index;
	}
	void set(unsigned int startindex,unsigned int size,unsigned int value)
	{
		// 一个低效的办法
		for (unsigned int index = 0 ; index < sizeof(unsigned int ) * 8 && index < size;index++)
		{
			if ((value >> index) & 1)
			{
				set(startindex + index);
			}
			else
				reset(startindex + index);
		}
	}
	unsigned get(unsigned int startindex,unsigned int size)
	{
		// 一个低效的办法
		int value = 0;
		for (unsigned int index = startindex; index < startindex + size;index++)
		{
			if (test(index))
			{
				value |= 1 << (index - startindex);
			}
		}
		return value;
	}
	void reset(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		tags[blockid] &= ~(1 << offset);
		if (index > maxSize) maxSize = index;
	}
	bool test(unsigned int index)
	{
		int blockid = getBlockId(index);
		if (blockid >= tags.size()) tags.resize(blockid + 1);
		int offset = getOffset(index);
		if (index > maxSize) maxSize = index;
		return (tags[blockid] & (1<<offset));
	}
	void clear()
	{
		for (int i = 0; i < tags.size();i++)
		{
			tags[i] = 0;
		}
	}
	unsigned int capacity()
	{
		return tags.size() * sizeof(unsigned int ) * 8;
	}
	unsigned int size()
	{
		return maxSize;
	}
	/**
	 * 可能弃用
	 **/
	void copyto(unsigned char*buffer,unsigned int buffersize)
	{
		// 低效做法 按字节拷贝
		unsigned int bytes = 0;
		for(std::vector<unsigned int>::iterator iter = tags.begin(); iter != tags.end() && bytes < buffersize;++iter)
		{
			unsigned int value = *iter;
			for (int index = 0; index < sizeof(unsigned int) && bytes < buffersize;index++)
			{
				*buffer = (value) >> (8 * index);
				buffer++;
				bytes++;
			}
		}
	}
	/**
	 * 可能弃用
	 **/
	void copyfrom(unsigned char*buffer,unsigned int buffersize)
	{
		tags.clear();
		// 低效做法 按字节拷贝
		int i = 0;
		while (i ++ < buffersize)
		{
			unsigned int value = 0;
			for (int index = 0; index < sizeof(unsigned int);index++)
			{
				value |= ((int)*buffer) << (8 * index);
				buffer++;
			}
			tags.push_back(value);
		}
	}
	std::vector<unsigned int> tags;
	unsigned int maxSize;
};