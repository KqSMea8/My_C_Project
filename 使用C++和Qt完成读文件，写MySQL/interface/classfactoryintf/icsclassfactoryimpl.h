/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�icsclassfactoryimpl.h
* ժ    Ҫ��ģ�鹤���ӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _ICSCLASSFACTORYIMPL_H_
#define _ICSCLASSFACTORYIMPL_H_

#include "icsclassfactory.h"

/*
 *  ģ�鹤���ӿ�ʵ��ģ��
 */
template <class T>
class IICSClassFactoryImpl : public IICSClassFactory
{
public:
	QStringList (EnumClasses)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IICSClassFactory_EnumClasses();
	}
	bool (CreateInstance)( const QString& clsid, IICSUnknown** ppUnknown )
	{
		T* pT = static_cast<T*>(this);
		return pT->IICSClassFactory_CreateInstance( clsid, ppUnknown );
	}
};

#endif	//_ICSCLASSFACTORYIMPL_H_