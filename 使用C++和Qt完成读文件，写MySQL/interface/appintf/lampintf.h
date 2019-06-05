// LampIntf.h
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LAMPINTF_H__E11C7EC0_E7A1_43CA_9CB3_06184949445E__INCLUDED_)
#define AFX_LAMPINTF_H__E11C7EC0_E7A1_43CA_9CB3_06184949445E__INCLUDED_

#include "objsintf.h"

class ILampConsumer : public IICSUnknown
{
public:
	virtual void OnFaultedLamp(ITaskObject* pBay, ITaskObject* pLamp, double dt)=0;
	virtual void OnAlertedLamp(ITaskObject* pBay, ITaskObject* pLamp, double dt)=0;
	virtual void OnFaultLampReset(ITaskObject* pBay, ITaskObject* pLamp, double dt)=0;
	virtual void OnAlertLampReset(ITaskObject* pBay, ITaskObject* pLamp, double dt)=0;
};

#endif //AFX_LAMPINTF_H__E11C7EC0_E7A1_43CA_9CB3_06184949445E__INCLUDED_
