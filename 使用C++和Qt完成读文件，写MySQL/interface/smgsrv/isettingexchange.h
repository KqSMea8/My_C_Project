// isettingexchange.h: interface for the IExchangeSetting class.
//
////////////////////////////////////////////////////////////////////////

#ifndef AFX_ISETTINGEXCHANGE_H__91A01EE2_B624_41A6_856A_69FF841445BE__INCLUDED_
#define AFX_ISETTINGEXCHANGE_H__91A01EE2_B624_41A6_856A_69FF841445BE__INCLUDED_

#include "icontrolstrategy.h"                  //for IControlStrategy

class ISysInfoDao;
class IExPowCurveDao;
class IGeneratorMgr;
class IStorageMgr;

class ISettingExchange : public IControlStrategy  
{
public:
	//传入外部对象
	virtual void SetStorageMgr(IStorageMgr* pStorageMgr) = 0;
	virtual void SetGeneratorMgr(IGeneratorMgr* pGeneratorMgr) = 0;
	virtual void SetSysInfoDao(ISysInfoDao* pSysInfo) = 0;
	virtual void SetExPowCurveDao(IExPowCurveDao* pExPowCurve) = 0;
};

#endif
