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

	//��ʼ���������еĿɵ��ķ�����ĳ���
	virtual void InitAllAdjustGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//ͳ���������豸�Ĺ���״��
	virtual void StatisticMainPower(MicgridObectInfo* pCurMgObj, int genPos) = 0;

	//���ڲ������������������������
	virtual int AdjustUnwGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool toOptPow=true) = 0;
	//���ڿ����������������������
	virtual int AdjustWGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool toOptPow=true) = 0;

	//����ʱִ�п�����������ָ��������ԡ�toOptCtrl��0-�������������ź����1-��������ֱ�ӻָ����2-�鲥Ⱥ��ֱ�ӻָ���󡣷���ֵ��true--�ָ������У�false--�ָ�������
	virtual bool ExecRenewableGeneratorRecallPower(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, int toOptCtrl) = 0;
	//����ʱִ�п�����������ָ����в��ԡ�����ֵ��true--�ָ������У�false--�ָ�������
	virtual bool ExecRenewableGeneratorRecallRun(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, bool isGrpCtrl) = 0;
	//����ʱִ�з���������������ָ����ԡ�����ֵ��true--�ָ������У�false--�ָ�������
	virtual bool RecallRenewableGeneratorToNormal(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//��������������ڵ�ָ��ֵ����
	virtual bool TestAdjustMainGenPowerToCur(MicgridObectInfo* pCurMgObj, double curP) = 0;
	//��������������ڵ����ֵ����
	virtual void TestAdjustMainGenPowerToMax(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
	//��������������ڵ���Сֵ����
	virtual void TestAdjustMainGenPowerToMin(MicgridObectInfo* pCurMgObj, double ratioP) = 0;
	//������Ƶ�ʵı䶯�������������
	virtual void TestAdjustMainGenByFrequency(MicgridObectInfo* pCurMgObj, double ratioP) = 0;

	//////////////////////////////////////////////////////////////////////////////////////////
	//���º������ؽ����0--δ������1--������δ�ﵽĿ�ꣻ2--������ﵽĿ�ꡣ
	//decPtoMaxMP--�������ܡ���������������ٷ����Ĺ��ʣ�incPtoMinMP--�������ܡ�������������Զ෢���Ĺ��ʡ�
	//////////////////////////////////////////////////////////////////////////////////////////
	//Ͷ�������������������ʳ���,ƽ�⹦��ȱ������
	virtual int IncreaseMicgridPowerByAddGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int IncreaseMicgridPowerByAddWGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int IncreaseMicgridPowerByAddUnwGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	//Ͷ������������������ʳ���,ƽ�⹦��ȱ������
	virtual bool IncreaseMicgridPowerByAddMainGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos) = 0;
	//Ͷ����������������ʳ���,ƽ�⹦��ȱ������
	virtual int IncreaseMicgridPowerByAddPeakGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP) = 0;
	//�г���������������ٹ��ʳ���,ƽ�⹦��ӯ������
	virtual int DecreaseMicgridPowerByCutGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int DecreaseMicgridPowerByCutWGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int DecreaseMicgridPowerByCutUnwGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, double decPtoMaxMP, double incPtoMinMP, double& needAddP, bool isNormalF=false) = 0;
	virtual int StopGeneratorOfBackupState(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//�г�������������ٹ��ʳ���,ƽ�⹦��ӯ������
	virtual bool DecreaseMicgridPowerByCutMainGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos, double& actP) = 0;
	//�г����巢��������ٹ��ʳ���,ƽ�⹦��ӯ������
	virtual bool DecreaseMicgridPowerByCutPeakGenerator(MicgridObectInfo* pCurMgObj, int ctrlReason, int& genPos, double& actP) = 0;
	//�г�ȫ�������[׼��������]
	virtual bool ActCutAllGenerators(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//����ϵͳ�����пɵ�������޹���������
	virtual bool AdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;

	//ִ�е��ڿɵ��������������
	virtual int AdjustGeneratorStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, bool isWGen, double& remainP, bool toOptPow, bool bSendAgc=false) = 0;

	//����ɵ���������������
	virtual void GetAllIncreasableWGenPower(MicgridObectInfo* pCurMgObj, double& incableP, double& decableP) = 0;
	
	//��������ͣ��ҵ��ִ�����з����ͣ�����ԡ�����ֵ��true--�ָ������У�false--�ָ�������
	virtual bool ExecAllGeneratorStopStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;
	
	//�����鲥Ⱥ�ط�ʽ���ڷ���������й�����������ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���3--���ڲ��ֳɹ���
	virtual int TestAdjustGroupGeneratorP(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP, double ratePow, bool bSendAgc) = 0;
	//�����鲥Ⱥ�ط�ʽ���ڷ���������޹�����
	virtual bool TestAdjustGroupGeneratorQ(VQCAreaInfo* pCurVQCArea, double& remainQ, double rateQ, bool isGrpCtrl) = 0;

	//����ϵͳ�����пɵ�������޹���������
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//����ϵͳ�пɵ�������޹�����,��֤��ŵ緽��һ��
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//������Ҫ���޹���������ϵͳ�����пɵ�������޹�������dNeedQΪ����
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//������Ҫ���޹����ʼ���ϵͳ�����пɵ�������޹�������dNeedQΪ����
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//����ϵͳ�пɵ�������޹�����,��֤���˵�ѹ����
	virtual bool AdjustReactPowerForVoltage(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
};

#endif