#include "UIManager.h"

NS_CC_BEGIN
void UIManager::addPanel(const std::string& name,UIPanel*panel)
{
	if (!getPanel(name))
	{
		panels[name] = panel;
		panel->retain();
	}
}


UIPanel * UIManager::getPanel(const std::string &name)
{
	PANELS_ITER iter = panels.find(name);
	if (iter != panels.end())
	{
		return iter->second;
	}
	return NULL;
}

void UIManager::removePanel(const std::string &name)
{
	PANELS_ITER iter = panels.find(name);
	if (iter != panels.end())
	{
		iter->second->release();
		panels.erase(iter);
	}
}

void UIManager::clear()
{
	for (PANELS_ITER iter = panels.begin(); iter != panels.end();++iter)
	{
		iter->second->release();
	}
	panels.clear();
}

void UIManager::hideAll()
{
	for (PANELS_ITER iter = panels.begin(); iter != panels.end();++iter)
	{
		iter->second->setVisible(false);
	}
}
NS_CC_END