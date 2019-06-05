/*******************************************************
 * isimultest -- smg������Զ�������ҵ��ӿ�
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
	//�˹�����ң����Ӧ��ң�����Ľ��ֵ
	virtual bool TestAnalogControlResult(int anlgId, float aimValue) = 0;
	//�˹���ң����Ӧ��ң�������һ������ֵ
	virtual bool TestAnalogControlChange(int anlgId, float incValue, float* rsltValue) = 0;
	//�˹�����ң�ض�Ӧ��ң�����Ľ��ֵ
	virtual bool TestStatusControlResult(int sttsId, int aimValue) = 0;
	
	//�˹�����ʵ�ֿ��Ƶ�ִ����
	virtual bool TestExecuteCmd(int ctrlPos, ICtrlData* pCtrlData) = 0;
	
	//�˹�����΢����ϵͳƵ��
	virtual bool ChangeSysFrequencyFrequencyForTest(int mgId, double newF) = 0;
	//����ĸ��ID�˹����õ�ǰ��ѹ��Ƶ��Ϊ����ֵ
	virtual bool TestUFtoNormalByBusId(int busId) = 0;
	//�˹�����ָ��΢������PCC�Ľ�������
	virtual bool AdjustPCCPowerForTest(int mgId, double exchangeP, bool isCombine) = 0;
	//�˹����ڷֽ�ͷ��λ���ѹ����ѹ��ĵ�ѹ�仯
	virtual bool TestTransformerVoltageChange(int transPos, int windingNo, bool bAscend, int busId, float* pCurU) = 0;
	//�����޹������Ե���ϵͳ��Ӱ��
	virtual void TestIncreaseReactPower(IVoltageOperate* pVoltOprt, int busPos, VQCAreaInfo* pCurVQCArea, double actQ) = 0;
		
	//�����ⲿ����
	//virtual void SetControlData(ICtrlData* pCtrlData) = 0;
	virtual void SetAnalogDao(IAnalogDao* pAnalogDao) = 0;
	virtual void SetStatusDao(IStatusDao* pStatusDao) = 0;
	virtual void SetControlDao(IControlDao* pCtrlDao) = 0;
	virtual void SetBusDao(IBusDao* pBusDao) = 0;
	virtual void SetPccDao(IPccDao* pPccDao) = 0;
	virtual void SetTransformerDao(ITransformerDao* pTransDao) = 0;
};

#endif