//istoragemgr.h

#ifndef _ISTORAGEMGR_SMG8000_PENGSHIKANG_20130301_H_
#define _ISTORAGEMGR_SMG8000_PENGSHIKANG_20130301_H_

#define STORAGEMANAGER_CLASSID    "cStorageMgr"
#define STORAGEMANAGER_INTFID     "iStorageMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IAStorageMgr;

class IStorageMgr : virtual public IICSUnknown 
{
public:
	//停止当前微网的所有非主储能设备[准备黑启动]
	virtual bool StopAllStorages(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//启动当前微网的所有非主储能设备
	virtual bool StartAllStorages(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//得到主储能的SOC状态
	virtual int GetMainStorSocState(MicgridObectInfo* pCurMgObj) = 0;

	//统计主储能设备的功率状况
	virtual void StatisticMainPower(MicgridObectInfo* pCurMgObj, int storPos) = 0;

	//将运行的非主储能设备的分类有功出力加入子微电网的储能对象列表
	virtual void MakeStorageList(MicgridObectInfo* pCurMgObj, int pos, double curP, double proP, bool isProtect) = 0;

	//并网时微网系统所有储能执行保护性恢复策略。返回值：true--恢复进行中；false--恢复结束。
	virtual bool ExecStorageRecallStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;
	//并网紧急功率调度时执行储能紧急调度策略
	virtual bool ExecStorageEmergeStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//并网时所有储能装置进入恢复状态
	virtual void StartRecalls(MicgridObectInfo* pCurMgObj) = 0;
	//并网时所有储能装置结束恢复状态[未用]
	virtual void EndRecalls(MicgridObectInfo* pCurMgObj) = 0;

	//int型函数返回结果：0--未动作；1--动作后未达到目标；2--动作后达到目标。
	//（1）调节储能装置的有功出力策略
	//（1.1）离网系统调节储能装置的有功出力策略。参数：dischgP--辅助储能需要增加放电的功率（负数表示充电）
	virtual int AdjustStorageStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double& actP, bool bprotect=false) = 0;
	//（1.2）离网系统维护储能装置的SOC策略
	virtual int ProtectStorageStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, bool bzero) = 0;
	//（1.3）并网系统调节储能装置的有功出力策略。参数：dischgP--辅助储能需要增加放电的功率（负数表示充电）
	virtual int AdjustStorageForContinent(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double minActP, double& actP, bool needStart, bool toZeroP, intarray dealList) = 0;
	//（1.4）为防交换功率逆流而调节储能装置的有功出力策略。参数：dischgP--辅助储能需要增加放电的功率（负数表示充电）
	virtual int AdjustStorageForReverse(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double& actP, bool needStart) = 0;
	//（2）执行子微电网内辅助储能的保护性调节，保证主储能与能量型辅助储能的充放电方向一致
	// 参数：decStorP--辅助储能可以减少放电的功率（负数）；incStorP--辅助储能可以增加放电的功率（正数）。
	virtual int AdjustStorageForAccord(MicgridObectInfo* pCurMgObj, int ctrlReason, double decStorP, double incStorP, double& actP) = 0;
	//（3）执行子微电网内用富余的可再生能源给辅助储能进行恢复性调节策略。actP--辅助储能放电量
	virtual bool ExecStorageProtectForNormalP(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, double& incableP, double& decableP, bool hasAccord, bool iszero) = 0;

	//调节系统中所有储能设备无功出力操作
	virtual bool AdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;

	//测试调节主储能出力
	virtual void TestAdjustMainStorage(MicgridObectInfo* pCurMgObj, double mainCurP) = 0;

	//调节储能装置的有功出力策略
	virtual bool AdjustStoragePStrategy(intarray storList, int ctrlReason, double& remainP, double maxAdjP=100000000.0) = 0;
	//调节储能装置的无功出力策略
	virtual bool AdjustStorageQStrategy(intarray storList, int ctrlReason, double& remainP) = 0;

	//设置储能转换后的出力不变
	virtual bool SetStorageCurP(intarray storList, int ctrlReason) = 0;

	//保持储能装置的现有有功出力策略
	virtual void KeepupStoragePStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//保持储能装置的现有无功出力策略
	virtual void KeepupStorageQStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//调节储能装置的有功出力
	virtual bool AdjustStoragePower(intarray storList, int ctrlReason, double totalCurP, double maxAdjP, double& remainP, bool needStart, bool isIsland=true) = 0;

	//并网系统针对SOC状况进行全部储能的保护性调节
	virtual bool MicgridStorageKeepNormalForContinent(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP) = 0;
	//停止当前微网的所有非主储能设备的无功出力
	virtual bool StopAllStoragesQ(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//针对SOC状况进行全部储能的保护性调节
	virtual bool MicgridStorageKeepNormal(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, double& incableP, double& decableP, bool iszero) = 0;
	//计算正常储能的冗余出力
	virtual void GetAllIncreasablePower(MicgridObectInfo* pCurMgObj, double& incableP, double& decableP, double& totalP) = 0;

	virtual bool AdjustStorageListByOrder(MicgridObectInfo* pCurMgObj, intarray& storlist, double& remainP, int ctrlReason) = 0;

	//针对SOC状况进行全部储能的保护性调节--主电源考虑紧急限(0.9-0.1)
	virtual bool MicgridStorageKeepNormalOnly(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP,  bool iszero) = 0;

	//调节系统中所有储能设备无功出力到零
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//调节系统中储能设备无功出力,保证充放电方向一致
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//根据需要的无功功率增加系统中所有储能设备无功出力，dNeedQ为正。
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero) = 0;
	//根据需要的无功功率减少系统中所有储能设备无功出力，dNeedQ为负。
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero) = 0;

	//从储能计划曲线表中获取当前储能出力目标值
	virtual bool DealStoragePlanPowerValue(MicgridObectInfo* pCurMgObj, int minutes, double& storAimP) = 0;
};

#endif