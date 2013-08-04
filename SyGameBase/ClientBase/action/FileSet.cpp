#include "FileSet.h"

NS_CC_BEGIN
void FileSet::createFromFile(const char *fileName)
{
		std::stringstream xmlFile;
		xmlFile << fileName <<".xml";
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(xmlFile.str().c_str());
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)
		{
			delete buffer;
			return;
		}
		if (script::tixmlCode::initFromString((char*)buffer))
		{
		}
		delete buffer;
}
void FileSet::initNode(script::tixmlCodeNode *node)
{
	if (node->equal("fileset"))
	{
		script::tixmlCodeNode fileNode = node->getFirstChildNode("file");
		while (fileNode.isValid())
		{
			stFilePos pos;
			pos.startPos = fileNode.getInt("startpos");
			pos.size = fileNode.getInt("size");
			std::string name = fileNode.getAttr("name");
			filesMap[name] = pos;
			fileNode = fileNode.getNextNode("file");
		}
		std::string packName = node->getAttr("name");
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(packName.c_str());
		contents = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&contentSize);
	}
}
void FileSet::takeNode(script::tixmlCodeNode *node)
{
	/**
	 * <fileset name="xxx.pack">
	 *		<file name="xxx" startPos="" size=""/>
	 * </fileset>
	 */
	if (node->equal("Config"))
	{
		script::tixmlCodeNode fileSetNode = node->getFirstChildNode("fileset");
		initNode(&fileSetNode);
	}
}
void  FileSet::addFile(const std::string &fileName)
{
	filesMap[fileName] = stFilePos();
}

void  FileSet::save(const std::string &fileName,const std::string &rootName)
{
	std::stringstream xmlFile;
	xmlFile << fileName <<".xml";
	std::stringstream binFileopen;
	binFileopen <<fileName <<".bin";
	// 构建xml 和 binary
	FILE *file = fopen(binFileopen.str().c_str(),"wb");
	TiXmlDocument *pDoc=new TiXmlDocument; //定义一个文档的指针
	//添加一个xml头。
	TiXmlDeclaration *pDeclaration=new TiXmlDeclaration("1.0","UTF-8","");
	pDoc->LinkEndChild(pDeclaration);
	//添加XMl的根节点
	TiXmlElement *configNode= new TiXmlElement("Config");
	pDoc->LinkEndChild(configNode);

	TiXmlElement * fileSetNode = new TiXmlElement("fileset");
	configNode->LinkEndChild(fileSetNode);
	std::stringstream packFile;
	packFile << fileName <<".bin";
	fileSetNode->SetAttribute("name",packFile.str());
	unsigned int offset = 0;
	for (FILES_MAP_ITER iter = filesMap.begin();iter != filesMap.end();++iter)
	{
		// 直接写到文件里
		std::stringstream tempName;
		tempName << rootName << iter->first;
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(tempName.str().c_str());
		unsigned long contentSize = 0;
		unsigned char* contents = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&contentSize);
		/**
		 * make Node 了
		 */
		TiXmlElement *fileNode=new TiXmlElement("file");
		fileSetNode->LinkEndChild(fileNode);
		fileNode->SetAttribute("name",iter->first);
		fileNode->SetAttribute("startpos",offset);
		fileNode->SetAttribute("size",contentSize);
		offset += contentSize;
		fwrite(contents,contentSize,1,file);
		delete contents;
	}
	pDoc->SaveFile(xmlFile.str());
	fclose(file);
}

unsigned char *FileSet::getFileData(const char *fileName,unsigned int &size)
{
	FILES_MAP_ITER iter = filesMap.find(fileName);

	if (iter != filesMap.end())
	{
		size = iter->second.size;
 		return contents + iter->second.startPos;
	}
	size = 0;
	return NULL;
}

void FileSet::destroy()
{
	if (contents) delete contents;
	contents = NULL;
}
NS_CC_END