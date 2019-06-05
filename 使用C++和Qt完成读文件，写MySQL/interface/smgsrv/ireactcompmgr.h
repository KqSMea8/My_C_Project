//ireactcompmgr.h


#ifndef _IREACTCOMPMGR_ZHANGPENG_20130301_H_
#define _IREACTCOMPMGR_ZHANGPENG_20130301_H_

#define REACTCOMPMANAGER_CLASSID    "cReactCompMgr"
#define REACTCOMPMANAGER_INTFID     "iReactCompMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IReactCompMgr : virtual public IICSUnknown 
{
public:
	//执行投切设备减少无功出力操作
	virtual bool ActDecreaseReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//执行投切设备增加无功出力操作
	virtual bool ActIncreaseReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//执行调节设备无功出力操作
	virtual bool ActAdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;
	//执行调节无功补偿设备设备电压操作。返回值：0 --无动作(已达目标)；1--调节失败；2--调节成功。
	virtual int ActAdjustRPCVoltage(VQCAreaInfo* pCurVQCArea, bool toZero=false) = 0;
	//根据给定的无功增量执行调节设备无功出力操作
	virtual bool DoActAdjustReactPower(VQCAreaInfo* pCurVQCArea, double needQ, double& dActQ) = 0;
	//根据需要的无功功率增加系统中所有可调无功补偿设备的无功出力
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ) = 0;
	//调节系统中可调无功补偿设备的无功出力,保证充放电方向一致
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& dActQ) = 0;

	//切换到主电源模式
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//切换到非主电源模式
	virtual bool IntoUnmainMode(int pos, int ctrlReason, double curQ) = 0;
};

#endif  //_IREACTCOMPMGR_ZHANGPENG_20130301_H_
