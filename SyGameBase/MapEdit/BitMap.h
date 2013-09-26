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
private:
	std::vector<unsigned int> tags;
	unsigned int maxSize;
};