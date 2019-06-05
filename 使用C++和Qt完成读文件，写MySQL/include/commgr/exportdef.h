// exportdef.h: definition for the DLL_EXPORT symbol.

#ifndef _EXPORTDEFINE_2007_03_14_PENGSHIKANG_H_
#define _EXPORTDEFINE_2007_03_14_PENGSHIKANG_H_

#ifdef _MSC_VER
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT
#endif

#endif



