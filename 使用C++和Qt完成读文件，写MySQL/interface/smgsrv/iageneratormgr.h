//iageneratormgr.h

#ifndef _IAGENERATORMGR_SMG8000_PENGSHIKANG_20130301_H_
#define _IAGENERATORMGR_SMG8000_PENGSHIKANG_20130301_H_

#define AGENERATORMANAGER_CLASSID    "cAGeneratorMgr"
#define AGENERATORMANAGER_INTFID     "iAGeneratorMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IAGeneratorMgr : virtual public IICSUnknown 
{
public:
	//发电机是否可调
	virtual bool CanAdjust(int pos) = 0;

	//发电机是否位于指定微电网配置的主电源列表内
	virtual bool InMainSource(int id, MicgridObectInfo* pCurMgObj) = 0;
	//发电机是否为有效的非主发电机
	virtual bool IsUnmainSource(int pos, MicgridObectInfo* pCurMgObj) = 0;
	//发电机是否为运行的非主的电源
	virtual bool IsRunningUnmainGen(int pos, MicgridObectInfo* pCurMgObj) = 0;

	//执行发电机启动操作。返回：0--失败；1--等待；2--成功。
	virtual int ActStartGenerator(int pos, int ctrlReason, double& actP, bool blackStart=false, bool toMaxP=false) = 0;
	//切换到主电源模式
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//切换到非主电源模式
	virtual bool IntoUnmainMode(int pos, int ctrlReason) = 0;
	//执行发电机停止操作
	virtual bool ActStopGenerator(int pos, int ctrlReason, bool blackStart) = 0;
	//启动主发电机并切换到主电源模式
	virtual int StartMainGenerator(int pos, int ctrlReason, bool blackStart) = 0;

	//初始化可调发电机的出力。参数toZeroP：0--调节到0.0；1--调节到最小可调出力；2--调节到经济功率下限。
	virtual double InitAdjustGenerator(int pos, int ctrlReason, int toZeroP) = 0;
	//恢复可再生可调发电机出力操作。isNewGen--是否为可再生发电机
	virtual bool RecallAdjGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//增加可调发电机出力操作。返回值：0 --无动作；1--调节失败；2--调节成功。
	virtual int IncreaseGeneratorPower(int pos, int ctrlReason, bool toOptPow, bool bSendAgc, double& remainP, bool smoothPlant, double smoothRate) = 0;
	//得到可调发电机的可增加出力
	virtual void GetAdjustableGeneratorPower(int pos, double maxAdjP, double& incableP, double& decableP) = 0;

	//调节单个发电机无功功率。返回值：0 --无动作；1--调节失败；2--调节成功。
	//参数groupCtrlType：0 --单个优化控制；1--测试组播群控；2--按比例分配控制。
	virtual int AdjustGeneratorQ(int pos, double& adjustQ, int groupCtrlType, bool bCheckVolt) = 0;
	//单个吸收无功功率的发电机调节无功到零。adjustQ为正数
	virtual bool IncreaseGeneratorQToZero(int pos, double& adjustQ) = 0;
	//单个发出无功功率的发电机调节无功到零。adjustQ为负数
	virtual bool DecreaseGeneratorQToZero(int pos, double& adjustQ) = 0;

	//测试黑启动主发电机
	virtual void TestStartMainGenerator(int mgId, int genPos) = 0;
	//测试状态维持主发电机出力平衡操作
	virtual bool TestMainGenerator(int pos, double mainP) = 0;
	//测试模式下设置主发电机的启动功率
	virtual double TestMainGeneratorStartPower(int genPos, double growGen, bool bFreqAutoAdjust) = 0;

	//执行发电机调节操作。返回值：0 --无动作；1--调节失败；2--调节成功。
	//参数checkChanged：0 --不检测变化量；1--灵敏度变化量；2--群控变化量。
	virtual int ActAdjustGenerator(int pos, int ctrlReason, double planValue, double& actValue, int checkChanged, bool checkControl) = 0;
	
};

#endif