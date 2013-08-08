#pragma once
#include "platfrom.h"
#if PLATFORM == PLATFORM_WIN32
	#include "thread/WinThread.h"
#elif PLATFORM == PLATFORM_APPLE
	#include "thread/LinuxThread.h"
#else
	#include "thread/LinuxThread.h"
#endif