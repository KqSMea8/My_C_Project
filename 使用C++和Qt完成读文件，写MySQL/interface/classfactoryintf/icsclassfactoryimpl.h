/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：icsclassfactoryimpl.h
* 摘    要：模块工厂接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _ICSCLASSFACTORYIMPL_H_
#define _ICSCLASSFACTORYIMPL_H_

#include "icsclassfactory.h"

/*
 *  模块工厂接口实现模板
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