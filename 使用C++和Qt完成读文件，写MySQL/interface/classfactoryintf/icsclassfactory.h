/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�icsclassfactory.h
* ժ    Ҫ��ģ���๤���ӿڶ���
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _ICSCLASSFACTORY_H_
#define _ICSCLASSFACTORY_H_

#include <qstringlist.h>

#include "../icsunknown.h"
#include "../qiptr.h"

#define IID_IICSClassFactory	"iicsclassfactory"
#define CLSID_ICSClassFactory	"ICSClassFactory"

/*
 *  ģ���๤���ӿ�
 */
class IICSClassFactory : virtual public IICSUnknown
{
public:
	virtual QStringList EnumClasses() = 0;
	virtual bool CreateInstance( const QString& clsid, IICSUnknown** ppUnknown ) = 0;
};

#pragma   warning(disable:4250)

/*����ӿڵ�����ָ��*/
typedef CQIPtr<IICSClassFactory> ICSClassFactory;

#endif	//_ICSCLASSFACTORY_H_