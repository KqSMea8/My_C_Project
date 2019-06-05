/*******************************************************
 * isimultest -- smg服务端自动控制主业务接口
 *******************************************************/

#ifndef _ISIMULATIONTEST_PENGSHIKANG_20130303_H
#define _ISIMULATIONTEST_PENGSHIKANG_20130303_H

#include "smgdatadef.h"                          // for VQCAreaInfo

class ICtrlData;
class IVoltageOperate;
class IAnalogDao;
class IStatusDao;
class IControlDao;
class IBusDao;
class IPccDao;
class ITransformerDao;

class ISimulTest
{
public:
	//人工设置遥调对应的遥测量的结果值
	virtual bool TestAnalogControlResult(int anlgId, float aimValue) = 0;
	//人工给遥调对应的遥测量添加一个增量值
	virtual bool TestAnalogControlChange(int anlgId, float incValue, float* rsltValue) = 0;
	//人工设置遥控对应的遥信量的结果值
	virtual bool TestStatusControlResult(int sttsId, int aimValue) = 0;
	
	//人工置数实现控制的执行令
	virtual bool TestExecuteCmd(int ctrlPos, ICtrlData* pCtrlData) = 0;
	
	//人工设置微电网系统频率
	virtual bool ChangeSysFrequencyFrequencyForTest(int mgId, double newF) = 0;
	//根据母线ID人工设置当前电压和频率为正常值
	virtual bool TestUFtoNormalByBusId(int busId) = 0;
	//人工增加指定微电网的PCC的交换功率
	virtual bool AdjustPCCPowerForTest(int mgId, double exchangeP, bool isCombine) = 0;
	//人工调节分接头档位后变压器电压侧的电压变化
	virtual bool TestTransformerVoltageChange(int transPos, int windingNo, bool bAscend, int busId, float* pCurU) = 0;
	//增加无功出力对调节系统的影响
	virtual void TestIncreaseReactPower(IVoltageOperate* pVoltOprt, int busPos, VQCAreaInfo* pCurVQCArea, double actQ) = 0;
		
	//传入外部对象
	//virtual void SetControlData(ICtrlData* pCtrlData) = 0;
	virtual void SetAnalogDao(IAnalogDao* pAnalogDao) = 0;
	virtual void SetStatusDao(IStatusDao* pStatusDao) = 0;
	virtual void SetControlDao(IControlDao* pCtrlDao) = 0;
	virtual void SetBusDao(IBusDao* pBusDao) = 0;
	virtual void SetPccDao(IPccDao* pPccDao) = 0;
	virtual void SetTransformerDao(ITransformerDao* pTransDao) = 0;
};

#endif