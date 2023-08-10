#pragma once

#ifdef REALENGINE_PLATFORM_WINDOWS
	#ifdef REALENGINE_BUILD_DLL
		#define REALENGINE_API __declspec(dllexport)
	#else
		#define REALENGINE_API __declspec(dllimport)
	#endif
#else
#error realengine only supports windows.
#endif
