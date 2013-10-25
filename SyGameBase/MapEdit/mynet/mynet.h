#include "platfrom.h"
#if PLATFORM == PLATFORM_WIN32
	#include "MyNet_win.h"
#else 
	#include "MyNet_mac.h"
#endif
