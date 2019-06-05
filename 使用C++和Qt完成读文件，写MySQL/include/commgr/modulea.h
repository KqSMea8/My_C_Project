// modulea.h: definition for the GetClassObject method.

#ifndef _MODULE_2007_03_14_PENGSHIKANG_H_
#define _MODULE_2007_03_14_PENGSHIKANG_H_

#include "icsunknown.h"//for IICSUnknown
#include "exportdef.h" //for DLL_EXPORT

//[模块二进制接口规范]-类工厂函数(含标准实现)
#ifdef __cplusplus
extern "C"
{
#endif 

	//[旧版本接口]得到DLL内部的实现类对象。
	DLL_EXPORT bool GetClassObject(char* classname, IICSUnknown** ppUnk);
	
#ifdef __cplusplus
}
#endif

#endif
