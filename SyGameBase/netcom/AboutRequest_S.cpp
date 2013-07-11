#include "AboutRequest.h"
#include "socket.h"
/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION2(AboutRequest,retCanPlay)
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
IMP_REMOTE_FUNCTION2(AboutRequest,retMapInfo)
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
IMP_REMOTE_FUNCTION2(AboutRequest,retLogin)
	PARAM(std::string ,uniqueStr);
	BODY
	{
		// 登录成功 展示新的UI 或者调用新的场景
		
	}
REMOTE_FUNCTION_END

/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION2(AboutRequest,getMapInfo)
	PARAM(int,mapWidth);
	PARAM(int ,mapHeight);
	BODY
	{
		
	}
REMOTE_FUNCTION_END

/**
 * 请求场景的信息
 * \param mapWidth 地图的宽
 * \param mapHeight 地图的高
 */
IMP_REMOTE_FUNCTION2(AboutRequest,reqLogin)
	PARAM(std::string,name);
	PARAM(std::string,pwd);
	BODY
	{
		printf("reqLogin %s %s\n",name.c_str(),pwd.c_str());
		retLogin(socket,"tickyou");
	}
REMOTE_FUNCTION_END