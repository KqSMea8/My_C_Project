//iagengroupmgr.h

#ifndef _IAGENERATORGROUPMGR_SMG8000_PENGSHIKANG_20170123_H_
#define _IAGENERATORGROUPMGR_SMG8000_PENGSHIKANG_20170123_H_

#define AGENGROUPMANAGER_CLASSID    "cAGenGroupMgr"
#define AGENGROUPMANAGER_INTFID     "iAGenGroupMgr"

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo
#include "vqcdatadef.h"                          // for VQCAreaInfo

class IAGenGroupMgr : virtual public IICSUnknown 
{
public:
	//恢复可再生可调发电机出力操作。isNewGen--是否为可再生发电机
	virtual bool RecallAdjGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//增加可调发电机出力操作。返回值：0 --无动作；1--调节失败；2--调节成功。
	virtual int IncreaseGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//得到可调发电机的可增加出力
	virtual void GetAdjustableGeneratorPower(int pos, double maxAdjP, double& incableP, double& decableP) = 0;

	//调节单个发电机无功功率。返回值：0 --无动作；1--调节失败；2--调节成功。
	//参数groupCtrlType：0 --单个优化控制；1--测试组播群控；2--按比例分配控制。
	virtual int AdjustGeneratorQ(int pos, double& adjustQ, int groupCtrlType, bool bCheckVolt) = 0;
	//单个吸收无功功率的发电机调节无功到零。adjustQ为正数
	virtual bool IncreaseGeneratorQToZero(int pos, double& adjustQ) = 0;
	//单个发出无功功率的发电机调节无功到零。adjustQ为负数
	virtual bool DecreaseGeneratorQToZero(int pos, double& adjustQ) = 0;

	//执行发电机调节操作。返回值：0 --无动作；1--调节失败；2--调节成功。
	//参数checkChanged：0 --不检测变化量；1--灵敏度变化量；2--群控变化量。
	virtual int ActAdjustGenerator(int pos, int ctrlReason, double planValue, double& actValue, int checkChanged) = 0;

	//调节系统中所有发电机机群无功出力到零
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//调节系统中发电机机群无功出力,保证充放电方向一致
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//根据需要的无功功率增加系统中所有发电机机群无功出力，dNeedQ为正。
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//根据需要的无功功率减少系统中所有发电机机群无功出力，dNeedQ为负。
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//调节系统中发电机机群无功出力,保证机端电压正常
	virtual bool AdjustReactPowerForVoltage(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	
};

#endif