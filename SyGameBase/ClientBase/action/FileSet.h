#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
NS_CC_BEGIN
struct stFilePos{
	unsigned int startPos;
	unsigned int size;
	stFilePos()
	{
		startPos = 0;
		size = 0;
	}
};
class FileSet:public script::tixmlCode{
public:
	FileSet()
	{
		contents= NULL;
		contentSize = 0;
	}
	void createFromFile(const char *fileName);

	void takeNode(script::tixmlCodeNode *node);


	void initNode(script::tixmlCodeNode *node);
	void addFile(const std::string &fileName);

	unsigned char *getFileData(const char *fileName,unsigned int &size);

	void save(const std::string &fileName,const std::string &rootName="tmp\\");

	std::map<std::string,stFilePos > filesMap;
	typedef std::map<std::string,stFilePos>::iterator FILES_MAP_ITER;
	//std::vector<unsigned char>contents;
	unsigned char *contents;
	unsigned long contentSize;
	void destroy();
};

NS_CC_END