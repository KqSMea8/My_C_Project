/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：icsclassfactory.h
* 摘    要：模块类工厂接口定义
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _ICSCLASSFACTORY_H_
#define _ICSCLASSFACTORY_H_

#include <qstringlist.h>

#include "../icsunknown.h"
#include "../qiptr.h"

#define IID_IICSClassFactory	"iicsclassfactory"
#define CLSID_ICSClassFactory	"ICSClassFactory"

/*
 *  模块类工厂接口
 */
class IICSClassFactory : virtual public IICSUnknown
{
public:
	virtual QStringList EnumClasses() = 0;
	virtual bool CreateInstance( const QString& clsid, IICSUnknown** ppUnknown ) = 0;
};

#pragma   warning(disable:4250)

/*定义接口的智能指针*/
typedef CQIPtr<IICSClassFactory> ICSClassFactory;

#endif	//_ICSCLASSFACTORY_H_