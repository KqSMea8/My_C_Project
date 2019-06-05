// icontrolstrategy.h: interface for the IControlStrategy class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICONTROLSTRATEGY_H__PENGSHIKANG_20130304__INCLUDED_
#define _ICONTROLSTRATEGY_H__PENGSHIKANG_20130304__INCLUDED_

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

#define SMGCONTINENTPROCESS_MODULE     "smgcontiproc"
#define SMGCONTINENTPROCESS_CLASSID    "cSmgContinentProcess"
#define SMGCONTINENTPROCESS_INTFID     "iSmgContinentProcess"

class CMscDataAgcProc;

class IControlStrategy : virtual public IICSUnknown 
{
public:
	//执行微电网的自动控制策略
	virtual bool ExecuteStrategy(MicgridObectInfo* pCurMgObj, int proFlag, CMscDataAgcProc* pAgcStraSend) = 0;
	//更新子微网有功功率平滑控制实时值
	virtual void UpdateSmoothCtrlInfo(MicgridObectInfo* pCurMgObj) = 0;
	//调节PCC的交换功率[测试添加]
	virtual bool AdjustMainPowerForTest(int smgID, double exchangeP, bool isCombine) = 0;
};

#endif
