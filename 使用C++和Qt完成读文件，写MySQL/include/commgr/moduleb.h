// moduleb.h: definition for the GetClassObject method.

#ifndef _MODULE_2007_03_14_PENGSHIKANG_H_
#define _MODULE_2007_03_14_PENGSHIKANG_H_

#include "icsunknown.h"//for IICSUnknown
#include "exportdef.h" //for DLL_EXPORT

//[模块二进制接口规范]-类工厂函数(含标准实现)
#ifdef __cplusplus
extern "C"
{
#endif 

	//[新版本接口]得到DLL内部的实现类对象。
	DLL_EXPORT bool GetNewClassObject(const char* classname, IICSUnknown** ppUnk, void* pParams[]);
	
#ifdef __cplusplus
}
#endif

#endif
