#pragma once
#include "platfrom.h"
#if PLATFORM == PLATFORM_WIN32
	#include "pool/IocpPool.h"
#elif PLATFORM == PLATFORM_APPLE
	#include "kqueue/KqueuePool.h"
#else
	#include "epoll/EpollPool.h"
#endif