//igeneratormgr.h

#ifndef _IGENERATORMGR_SMG8000_20130301_H_
#define _IGENERATORMGR_SMG8000_20130301_H_

#define GENERATORMANAGER_CLASSID    "cGeneratorMgr"
#define GENERATORMANAGER_INTFID     "iGeneratorMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IAGeneratorMgr;

class IGeneratorMgr : virtual public IICSUnknown 
{
public:
	virtual unsigned int GetCutMainGenCount(MicgridObectInfo* pCurMgObj) = 0;

	//初始化所有运行的可调的发电机的出力
	virtual void InitAllAdjustGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//统计主发电设备的功率状况
	virtual void StatisticMainPower(MicgridObectInfo* pCurMgObj, int genPos) = 0;

	//调节不可再生非主发电机出力策略
	virtual int AdjustUnwGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool toOptPow=true) = 0;
	//调节可再生非主发电机出力策略
	virtual int AdjustWGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool toOptPow=true) = 0;

	//并网时执行可再生发电机恢复出力策略。toOptCtrl：0-单个单个先最优后最大；1-单个单个直接恢复最大；2-组播群控直接恢复最大。返回值：true--恢复进行中；false--恢复结束。
	virtual bool ExecRenewableGeneratorRecallPower(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, int toOptCtrl) = 0;
	//并网时执行可再生发电机恢复运行策略。返回值：true--恢复进行中；false--恢复结束。
	virtual bool ExecRenewableGeneratorRecallRun(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool isGrpCtrl) = 0;
	//离网时执行非主可再生发电机恢复策略。返回值：true--恢复进行中；false--恢复结束。
	virtual bool RecallRenewableGeneratorToNormal(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//测试主发电机调节到指定值策略
	virtual bool TestAdjustMainGenPowerToCur(MicgridObectInfo* pCurMgObj, double curP) = 0;
	//测试主发电机调节到最大值策略
	virtual void TestAdjustMainGenPowerToMax(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
	//测试主发电机调节到最小值策略
	virtual void TestAdjustMainGenPowerToMin(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
	//测试因频率的变动而调节主发电机
	virtual void TestAdjustMainGenByFrequency(MicgridObectInfo* pCurMgObj, double ratioP) = 0;

	//////////////////////////////////////////////////////////////////////////////////////////
	//以下函数返回结果：0--未动作；1--动作后未达到目标；2--动作后达到目标。
	//decPtoMaxMP--辅助储能、非主发电机可以少发出的功率；incPtoMinMP--辅助储能、非主发电机可以多发出的功率。
	//////////////////////////////////////////////////////////////////////////////////////////
	//投入非主发电机来增长功率出力,平衡功率缺乏现象
	virtual int IncreaseMicgridPowerByAddGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int IncreaseMicgridPowerByAddWGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int IncreaseMicgridPowerByAddUnwGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	//投入主发电机来增长功率出力,平衡功率缺乏现象
	virtual bool IncreaseMicgridPowerByAddMainGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos) = 0;
	//投入调峰电机来增长功率出力,平衡功率缺乏现象
	virtual int IncreaseMicgridPowerByAddPeakGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP) = 0;
	//切除非主发电机来减少功率出力,平衡功率盈余现象
	virtual int DecreaseMicgridPowerByCutGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int DecreaseMicgridPowerByCutWGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int DecreaseMicgridPowerByCutUnwGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int StopGeneratorOfBackupState(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//切除主发电机来减少功率出力,平衡功率盈余现象
	virtual bool DecreaseMicgridPowerByCutMainGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos, double& actP) = 0;
	//切除调峰发电机来减少功率出力,平衡功率盈余现象
	virtual bool DecreaseMicgridPowerByCutPeakGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos, double& actP) = 0;
	//切除全部发电机[准备黑启动]
	virtual bool ActCutAllGenerators(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//调节系统中所有可调发电机无功出力操作
	virtual bool AdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;

	//执行调节可调发电机出力策略
	virtual int AdjustGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, bool isWGen, double& remainP, bool toOptPow, bool bSendAgc=false) = 0;

	//计算可调发电机的冗余出力
	virtual void GetAllIncreasableWGenPower(MicgridObectInfo* pCurMgObj, double& incableP, double& decableP) = 0;
	
	//并网紧急停机业务执行所有发电机停机策略。返回值：true--恢复进行中；false--恢复结束。
	virtual bool ExecAllGeneratorStopStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;
	
	//测试组播群控方式调节非主发电机有功出力。返回值：0 --无动作；1--调节失败；2--调节成功；3--调节部分成功。
	virtual int TestAdjustGroupGeneratorP(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, double ratePow, bool bSendAgc) = 0;
	//测试组播群控方式调节非主发电机无功出力
	virtual bool TestAdjustGroupGeneratorQ(VQCAreaInfo* pCurVQCArea, double& remainQ, double rateQ, bool isGrpCtrl) = 0;

	//调节系统中所有可调发电机无功出力到零
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//调节系统中可调发电机无功出力,保证充放电方向一致
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//根据需要的无功功率增加系统中所有可调发电机无功出力，dNeedQ为正。
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//根据需要的无功功率减少系统中所有可调发电机无功出力，dNeedQ为负。
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//调节系统中可调发电机无功出力,保证机端电压正常
	virtual bool AdjustReactPowerForVoltage(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
};

#endif