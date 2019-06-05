// istoragecurvectrl.h: interface for the IConti_StorageCurve class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_CONTI_STORAGECURVE_H__95842619_A817_458C_A35C_3DCD947CFCE1__INCLUDED_
#define AFX_CONTI_STORAGECURVE_H__95842619_A817_458C_A35C_3DCD947CFCE1__INCLUDED_

#include "icontrolstrategy.h"                  // for IControlStrategy  

class IStorCurveDao;
class ISysInfoDao;

class IStorageCurveCtrl : public IControlStrategy  
{
public:
	//传入外部对象
	virtual void SetStorCurveDao(IStorCurveDao* pCurMgObj) = 0;
	virtual void SetSysInfoDao(ISysInfoDao* pSysInfo) = 0; 
};

#endif
