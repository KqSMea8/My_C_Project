// moduleb.h: definition for the GetClassObject method.

#ifndef _MODULE_2007_03_14_PENGSHIKANG_H_
#define _MODULE_2007_03_14_PENGSHIKANG_H_

#include "icsunknown.h"//for IICSUnknown
#include "exportdef.h" //for DLL_EXPORT

//[ģ������ƽӿڹ淶]-�๤������(����׼ʵ��)
#ifdef __cplusplus
extern "C"
{
#endif 

	//[�°汾�ӿ�]�õ�DLL�ڲ���ʵ�������
	DLL_EXPORT bool GetNewClassObject(const char* classname, IICSUnknown** ppUnk, void* pParams[]);
	
#ifdef __cplusplus
}
#endif

#endif
