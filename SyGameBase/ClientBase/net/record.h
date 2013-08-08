#pragma once
#include "string.h"
/**
 * Buffer 中获取信息后 会重置当前位置
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
	unsigned int offset;
	bool empty()
	{
		return offset == contentSize;
	}
	unsigned int contentSize;
	unsigned char *contents;
};