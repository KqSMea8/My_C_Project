//iloadmgr.h

#ifndef _ILOADMGR_SMG8000_20130301_H_
#define _ILOADMGR_SMG8000_20130301_H_

#define LOADMANAGER_CLASSID    "cLoadMgr"
#define LOADMANAGER_INTFID     "iLoadMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

class ILoadMgr : virtual public IICSUnknown 
{
public:
	//获取指定微电网中可以投入的被切除负荷位置
	virtual int GetMinCanAddLoadPosInMicgrid(MicgridObectInfo* pCurMgObj, double& loadP) = 0;

	//获取子微电网的未投入负荷的数量
	virtual int GetCutLoadCount(MicgridObectInfo* pCurMgObj) = 0;

	//执行恢复负荷操作。返回值：true--有动作；false--无动作。
	virtual bool RecallLoadForCombine(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool onlyOne) = 0;
	//并网时执行负荷恢复策略
	virtual bool ExecLoadRecallStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool onlyOne) = 0;
	//紧急功率调度时执行负荷切除策略
	virtual bool ExecLoadEmergeStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//根据限值投运子微网中最小的高等级负荷操作
	virtual bool ActAddMinLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double mainSoc, double maxAddP, double& actP) = 0;
	//根据储能SOC状态执行切负荷操作
	virtual bool ActCutLoadByStorageSOC(MicgridObectInfo* pCurMgObj, int ctrlReason, double mainSoc, double maxCutP, int loadGrade, double& actP) = 0;
	//切除子微网中所有的负荷操作
	virtual bool ActCutAllLoads(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//////////////////////////////////////////////////////////////////////////////////////////
	//以下函数返回结果：0--未动作；1--动作后未达到目标；2--动作后达到目标。
	//decPtoMaxMP--可以少切除\多投入的负荷功率，incPtoMinMP--可以多切除\少投入的负荷功率。
	//////////////////////////////////////////////////////////////////////////////////////////
	//切除负荷来增长功率出力,平衡功率缺乏现象。remainP为正数
	virtual int IncreaseMicgridPowerByCutLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& remainP) = 0;
	//投入负荷来减少功率出力,平衡功率盈余现象。remainP为负数
	virtual int DecreaseMicgridPowerByAddLoad(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& remainP) = 0;

	//测试因频率的变动而调节负荷
	virtual void TestAdjustLoadByFrequency(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
};

#endif