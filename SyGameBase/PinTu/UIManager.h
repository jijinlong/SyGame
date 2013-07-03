#pragma once

#include "UIPanel.h"
NS_CC_BEGIN
class UIManager{
public:
	static UIManager&getMe()
	{
		static UIManager uim;
		return uim;
	}
	void addPanel(const std::string& name,UIPanel*panel);


	UIPanel * getPanel(const std::string &name);
	
	void removePanel(const std::string &name);

	void clear();

	void hideAll();
private:
	std::map<std::string,UIPanel*> panels;
	typedef std::map<std::string,UIPanel*>::iterator PANELS_ITER;
};

#define theUI UIManager::getMe()
NS_CC_END