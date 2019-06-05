//iastoragemgr.h

#ifndef _IASTORAGEMGR_SMG8000_PENGSHIKANG_20140122_H_
#define _IASTORAGEMGR_SMG8000_PENGSHIKANG_20140122_H_

#define ASTORAGEMANAGER_CLASSID    "cAStorageMgr"
#define ASTORAGEMANAGER_INTFID     "iAStorageMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

class IAStorageMgr : virtual public IICSUnknown 
{
public:
	//储能设备是否已启动
	virtual bool IsRunning(int pos, bool bRefresh=false) = 0;

	//储能设备是否位于指定微电网配置的主电源列表内
	virtual bool InMainSource(int id, MicgridObectInfo* pCurMgObj) = 0;
	//储能设备是否为有效的非主储能
	virtual bool IsUnmainSource(int pos, MicgridObectInfo* pCurMgObj) = 0;

	//启动储能设备
	virtual bool ActStartStorage(int pos, int ctrlReason, bool actMain=false) = 0;
	//停止储能设备[未用]
	virtual bool ActStopStorage(int pos, int ctrlReason, bool isActive) = 0;

	//启动储能并切换到主电源模式（VF模式）
	virtual bool StartMainStorage(int pos, int ctrlReason) = 0;
	//启动储能并切换到非主电源模式（PQ模式）
	virtual bool StartUnmainStorage(int pos, int ctrlReason) = 0;

	//切换到主电源模式
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//切换到非主电源模式
	virtual bool IntoUnmainMode(int pos, int ctrlReason) = 0;

	//并网系统中单个储能的保护性调节
	virtual bool StorageKeepNormalForContinent(int pos, int ctrlReason, double& actDchgP) = 0;
	//单个储能的保护性调节
	virtual bool StorageKeepNormal(int pos, int ctrlReason, bool isContinue, double maxAdjP, double& maxChgP, double& maxDchgP, double& actDchgP, double& incableP, double& decableP, bool iszero) = 0;

	//获取储能的保护性调节功率值
	virtual double GetAdjustPowerForProtect(int pos, double curP, bool& isProtect) = 0;
	//得到单个储能的最优放电功率[正数]
	virtual double GetStorageOptDchgPower(int pos) = 0;
	//得到单个储能的最优充电功率[负数]
	virtual double GetStorageOptChgPower(int pos) = 0;

	//执行单个储能装置有功调节操作
	virtual int ActAdjustStorage(int pos, int ctrlReason, double curValue, double planValue, bool forSoc, bool notGuard, bool actStart) = 0;
	//执行单个储能装置有功功率调节到0操作
	virtual int ActZeroStorage(int pos, int ctrlReason) = 0;

	//单个充电的储能恢复到不充放状态，curP < 0，remainP > 0。
	virtual bool ChangeStorageToZero(int pos, int ctrlReason, double curP, double maxAdjP, double& actDchgP) = 0;
	//单个放电的储能恢复到不充放状态，curP > 0，remainP < 0。
	virtual bool DischangeStorageToZero(int pos, int ctrlReason, double curP, double maxAdjP, double& actDchgP) = 0;
	//并网系统中单个储能恢复到不充放状态。
	virtual bool StorageToZeroForSOC(int pos, int ctrlReason, double maxAdjP, double& actDchgP) = 0;

	//调节单个储能设备无功功率。返回值：0 --无动作；1--调节失败；2--调节成功。
	virtual int AdjustStorageQ(int pos, double& adjustQ) = 0;
	//执行单个储能装置无功调节操作。返回值：0 --无动作；1--不需调节；2--调节成功。
	virtual int ActAdjustStorageQ(int pos, int ctrlReason, double curValue, double planValue, bool notGuard, bool actStart) = 0;
	//执行单个储能装置无功功率调节到0操作。返回值：0 --无动作；1--不需调节；2--调节成功。
	virtual int ActZeroStorageQ(int pos, int ctrlReason) = 0;
	//单个储能无功恢复到不充放状态。
	virtual bool StorageQToZero(int pos, int ctrlReason, double maxAdjQ) = 0;

	//测试执行单个储能装置调节操作
	virtual bool TestAdjustStorageP(int pos, double planValue) = 0;
	//测试启动主储能
	virtual void TestStartMainStorage(int mgId, int storPos) = 0;
	
	//得到储能的可调节出力
	virtual void GetAdjustableStorPower(int pos, double maxAdjP, double& incableP, double& decableP, double& totalP, bool bstor) = 0;

	//单个吸收无功功率的储能设备调节无功到零。adjustQ为正数
	virtual bool IncreaseStorageQToZero(int pos, double& adjustQ) = 0;
	//单个发出无功功率的储能设备调节无功到零。adjustQ为负数
	virtual bool DecreaseStorageQToZero(int pos, double& adjustQ) = 0;

};

#endif