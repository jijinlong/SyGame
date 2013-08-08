#pragma once
#include "zlib/zlib.h"
#include "vector"
#include "Record.h"
#include "string.h"
#include <list>
class Decoder{
public:
	Decoder(){
		currentoffset = 0;
		nowstate = 0;
		tag = 0;
	}
private:
	unsigned int currentoffset; // 当前数据起始点
	std::vector<unsigned char> contents;

	enum{
		START,
		END,
		PICK_HEAD,
		PICK_BODY,
	};
	
	unsigned char nowstate; // 当前状态
	unsigned char tag; // 报文标识器
	static const unsigned int MAX_DATASIZE = 65536; // 最大接受报文
	enum{
		ZIP = 1 << 0, // ZIP压缩
		DES = 1 << 1, // DES加密
		MIN_HEAD = 1 << 2, // 小报文
		MAX_HEAD = 1 << 3, // 大报文
	};
	
	unsigned leftsize()
	{
		return contents.size() -currentoffset;
	}
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
	void refresh()
	{
		// 重新设定下一个大小
		switch(nowstate)
		{
			case START:
			{
				contents.resize(1);
				nowstate = PICK_HEAD;
				currentoffset = 0;
			}break;
			case PICK_HEAD:
			{
				tag = contents[0];
				if (tag & MIN_HEAD)
					contents.resize(1);
				if (tag & MAX_HEAD)
					contents.resize(2);
				nowstate = PICK_BODY;
				currentoffset = 0;
			}break;
			case PICK_BODY:
			{
				contents.resize(getbodysize());
				nowstate = END;
				currentoffset = 0;
			}break;
			case END:
			{
				nowstate = START;
			//	contents.clear();
			//	currentoffset = 0;
			}break;
		}
	}
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
	bool isFinished()
	{
		// 完整报文了
		return (nowstate==END);
	}
	void setbodysize(unsigned int size)
	{
		if (tag & MIN_HEAD)
		{
			*(unsigned char*)(&contents[1]) = size;
		}
		if (tag & MAX_HEAD)
		{
			*(unsigned short*)(&contents[1]) = size;
		}
	}
	unsigned int getbodysize()
	{
		if (tag & MIN_HEAD)
		{
			return *(unsigned char*)&contents[0];
		}
		if (tag & MAX_HEAD)
		{
			return *(unsigned short*)&contents[0];
		}
		return 0;
	}
public:
	template<typename Record>
	unsigned int decode(Record * target,void *buffer,unsigned int maxSize) // 解码器
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
	void decode(Record *target) // 解码器
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
				}
				else if (contents.size())
				{
					printf("ok %s\n",&contents[0]);
				}
				//target.done(buffer,retSize);
			}
		}
	}
	Record * getRecord()
	{
		Record *record = new Record(&contents[0],contents.size());
		return record;
	}
	void encode(void *data,unsigned int len,bool ziptag = false,bool destag = false) // 打包器
	{
		// 设置tag
		unsigned int headcontent = 0;
		if (len <= 255)
		{	
			tag |= MIN_HEAD;
			ziptag = false; // 小报文强制不打包
			headcontent = 1; // 一个字节长度的报文
		}
		else
		{
			tag |= MAX_HEAD;
			headcontent = 2; 
		}
		if (ziptag) tag |= ZIP;
		if (destag) tag |= DES;
		
		if (ziptag)
		{
			len = zip(data,len,headcontent + 1);
		}
		else
		{
			contents.resize(len + headcontent + 1);
			memcpy(&contents[headcontent+1],data,len);
		}
		if (destag)
		{
			des();
		}
		
		contents[0] = tag;
		setbodysize(len);
	}
private:
	unsigned int unzip_size(unsigned int zip_size)
	{
		return zip_size * 120 / 100 + 12;
	}
	unsigned int unzip(unsigned char *buffer,unsigned int len,unsigned int offset)
	{
		// 解压
		if (tag & ZIP)
		{
			unsigned int unZipLen = len;
			int retcode = uncompress(buffer,(uLongf*)&unZipLen,&contents[offset],contents.size() - offset);
			return unZipLen;
		}
		return 0;
	}
	
	void undes()
	{
		// 解密
		if (tag & DES)
		{
			
		}
	}
	unsigned int zip(void *data,unsigned int len,unsigned int offset)
	{
		if (tag & ZIP)
		{
			contents.resize(unzip_size(len));
			unsigned int outlen = 0;
			int retcode = compress(&contents[offset],(uLongf*)&outlen,(const Bytef *)data,len);
			contents.resize(outlen);
			len = outlen;
		}
		return len;
	}
	
	void des()
	{
		if (tag & DES)
		{
			
		}
	}
};
