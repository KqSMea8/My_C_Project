// setdllpool.h: implement for the SetDllPool method.
#ifndef _SETDLLPOOL_2007_12_19_PENGSHIKANG_H_
#define _SETDLLPOOL_2007_12_19_PENGSHIKANG_H_

#include "icsintflib.h" // for CICSIntfLib
#include "exportdef.h"  // for DLL_EXPORT

//…Ë÷√DLL¥Ê¥¢≥ÿ
#ifdef __cplusplus
extern "C"
{
#endif

	DLL_EXPORT void SetDllPool(QMap<QString, CICSIntfLib*>* pDllPool);

#ifdef __cplusplus
}
#endif
	
#endif 
