#pragma once

#ifdef DLL_BUILD
	#define GRAVITUMDLL __declspec(dllexport)
#else
	#define GRAVITUMDLL __declspec(dllimport)
#endif