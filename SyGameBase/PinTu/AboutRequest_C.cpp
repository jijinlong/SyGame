#include "AboutRequest.h"
#include "socket.h"
#include "UIManager.h"
using namespace cocos2d;
/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION(AboutRequest::retCanPlay)
	PARAM(std::vector<stBagInfo>,bags);
	BODY
	{
		printf("服务器本地调用");
	}
REMOTE_FUNCTION_END

/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION(AboutRequest::retMapInfo)
	PARAM(int,mapId);
	PARAM(std::string ,mapName);
	BODY
	{
		printf("服务器本地调用");
	}
REMOTE_FUNCTION_END

/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION(AboutRequest::retLogin)
	PARAM(std::string ,uniqueStr);
	BODY
	{
		// 登录成功 展示新的UI 或者调用新的场景
		UIPanel *loginPanel = theUI.getPanel("login");
		if (loginPanel)
		{
			loginPanel->setVisible(false);
		}
		UIPanel *mainPanel = theUI.getPanel("main");
		if (mainPanel)
		{
			mainPanel->setVisible(true);
		}
	}
REMOTE_FUNCTION_END

