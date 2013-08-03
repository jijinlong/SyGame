#include "UIFileList.h"
#include "UISuperBag.h"
NS_CC_BEGIN

void UIFileItem::setFileType(FILETYPE type)
{
	nowType = type;
}
struct stHideMe:public UICallback{
	void callback(UIBase *base)
	{
		UIPanel *panel = base->getPanel();
		if (panel)
		{
			panel->setVisible(false);
			if (panel->isModel())
			{
				panel->getWindow()->popModel();
			}
		}
	}
};
void UIFileList::doInitEvent()
{
	this->bindBtnClick("close",new stHideMe());
}
struct stOpenSubDir:public UICallback{
	void callback(UIBase *base)
	{
		UIFileList *fileList = UIFileList::create(window,uiXmlName.c_str());
		if (fileList)
		{
			fileList->show(root.c_str());
			window->pushModel(fileList);
		}
	}
	stOpenSubDir(UIWindow *window,const std::string& subdir,const std::string &uixmlName):window(window),root(subdir),uiXmlName(uixmlName)
	{
	
	}
	UIWindow *window;
	std::string root;
	std::string uiXmlName;
};
bool UIFileList::checkIn(const std::string &name)
{
	if (showes.empty()) return true;
	for (std::vector<std::string>::iterator iter = showes.begin();iter != showes.end();++iter)
	{
		if (name.find(*iter) != std::string::npos) return true;
	}
	return false;
}
void UIFileList::show(const char *root,const char * listName,const char *dirItemName,const char *fileItemName)
{
	/**
	 * 遍历文件
	 */
	WIN32_FIND_DATA fd; 
    ZeroMemory(&fd, sizeof(WIN32_FIND_DATA)); 
  
	std::string filePathName = root ;
  
    filePathName += ('\\'); 
    filePathName += ("*"); 
  
	UISuperBag *list = LIST(this,listName);
	if (!list) return;
	//list->clear();
    HANDLE m_hFind = FindFirstFile(filePathName.c_str(), &fd); 
    if (strcmp(fd.cFileName, (".")) && strcmp(fd.cFileName, ("..")))
	{
		if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
		{ 
			std::string fname = fd.cFileName;
			std::string subDir = std::string(root) + std::string("\\") + fname;
			// 目录
			UIFileItem *fileItem = UIFileItem::create(dirItemName);
			if (fileItem)
			{
				fileItem->setFileType(UIFileItem::__DIR__);
				fileItem->getPanel()->bindBtnClick("open",new stOpenSubDir(this->getWindow(),subDir,uiXmlName));
			}
			list->addItem(fileItem);
		} 
		else
		{
			// 文件
			std::string fname = fd.cFileName;
			if (checkIn(fname))
			{
				UIFileItem *fileItem = UIFileItem::create(fileItemName);
				if (fileItem)
				{
					fileItem->setFileType(UIFileItem::__FILE_);
					fileItem->getPanel()->setUILabelvalue("filename",fname);
				}
				list->addItem(fileItem);
			}
		}
	}
    BOOL bSearchFinished = FALSE; 
    while( !bSearchFinished ) 
    { 
        if( FindNextFile(m_hFind, &fd)) 
        { 
			if (strcmp(fd.cFileName, (".")) && strcmp(fd.cFileName, ("..")))
			{
				if ((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) 
				{
					std::string fname = fd.cFileName;
					std::string subDir = std::string(root) + std::string("\\") + fname;
					// 目录
					UIFileItem *fileItem = UIFileItem::create(dirItemName);
					if (fileItem)
					{
						fileItem->setFileType(UIFileItem::__DIR__);
						fileItem->getPanel()->bindBtnClick("open",new stOpenSubDir(this->getWindow(),subDir,uiXmlName));
					}
					list->addItem(fileItem);
				} 
				else
				{
					// 文件
					std::string fname = fd.cFileName;
					if (checkIn(fname))
					{
						UIFileItem *fileItem = UIFileItem::create(fileItemName);
						if (fileItem)
						{
							fileItem->setFileType(UIFileItem::__FILE_);
							fileItem->getPanel()->setUILabelvalue("filename",fname);
						}
						list->addItem(fileItem);
					}
				}
			}
		} 
        else
        { 
            break; 
        } 
    }
	list->show();
    FindClose(m_hFind);     

}
NS_CC_END