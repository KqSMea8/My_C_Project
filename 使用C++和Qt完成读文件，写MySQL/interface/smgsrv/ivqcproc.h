//ivqcproc.h
#ifndef _IVQCPROC_ZHANG_PENG_20130225_20150317_H_
#define _IVQCPROC_ZHANG_PENG_20130225_20150317_H_

//#include "icontrolstrategy.h"
#include "../icsunknown.h"                       // for IICSUnknown

#define VOLTAGECONTROL_MODULE     "vqcproc"
#define VOLTAGECONTROL_CLASSID    "cVoltageControl"
#define VOLTAGECONTROL_INTFID     "iVoltageControl"

class IStorageMgr;
class IGeneratorMgr;
class ITransformerMgr;
class IReactCompMgr;

class IAutoCtrl;
class IActionAlarm;
class IScadaDao;
class ISmgDao;

class IVqcProc : virtual public IICSUnknown // virtual public IControlStrategy 
{
public:
	//初始化VQC实时表的静态信息
	virtual void InitializeVqcRtdbInfo() = 0;
	//更新所有数据表的实时无功功率值
	virtual int RefreshAllReactPowerValues(int& nLocalFlag, int& nAreaNoChange) = 0;
	//实时进行电压质量控制
	virtual bool RealVoltageControl(int adjustCount) = 0;

	virtual bool NewAvcControl(int adjustNo, double dValue, int nCtrlType) = 0;

	//更新所有电压无功设备表的实时无功功率值。
	virtual void RefreshAllReactPowerData() = 0;

};

#endif
