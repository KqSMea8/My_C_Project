// modulec.h: definition for the GetClassObject method.

#ifndef _MODULEC_2008_11_05_PENGSHIKANG_H_
#define _MODULEC_2008_11_05_PENGSHIKANG_H_

#include "icsunknown.h"//for IICSUnknown
#include "exportdef.h" //for DLL_EXPORT

//[ģ������ƽӿڹ淶]-�๤������(����׼ʵ��)
#ifdef __cplusplus
extern "C"
{
#endif 

	//[�°汾�ӿ�]�õ�DLL�ڲ���ʵ�������
	DLL_EXPORT bool GetNewClassObject(const char* classname, IICSUnknown** ppUnk, void* pParams[]);
	//DLL��ʼ������
	DLL_EXPORT bool Initialize();
	//DLL����ʼ������
	DLL_EXPORT bool Uninitialize();
	
#ifdef __cplusplus
}
#endif

#endif
