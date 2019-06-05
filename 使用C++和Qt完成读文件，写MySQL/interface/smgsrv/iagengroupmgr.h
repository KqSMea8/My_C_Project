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
	//�ָ��������ɵ����������������isNewGen--�Ƿ�Ϊ�����������
	virtual bool RecallAdjGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//���ӿɵ��������������������ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	virtual int IncreaseGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//�õ��ɵ�������Ŀ����ӳ���
	virtual void GetAdjustableGeneratorPower(int pos, double maxAdjP, double& incableP, double& decableP) = 0;

	//���ڵ���������޹����ʡ�����ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	//����groupCtrlType��0 --�����Ż����ƣ�1--�����鲥Ⱥ�أ�2--������������ơ�
	virtual int AdjustGeneratorQ(int pos, double& adjustQ, int groupCtrlType, bool bCheckVolt) = 0;
	//���������޹����ʵķ���������޹����㡣adjustQΪ����
	virtual bool IncreaseGeneratorQToZero(int pos, double& adjustQ) = 0;
	//���������޹����ʵķ���������޹����㡣adjustQΪ����
	virtual bool DecreaseGeneratorQToZero(int pos, double& adjustQ) = 0;

	//ִ�з�������ڲ���������ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	//����checkChanged��0 --�����仯����1--�����ȱ仯����2--Ⱥ�ر仯����
	virtual int ActAdjustGenerator(int pos, int ctrlReason, double planValue, double& actValue, int checkChanged) = 0;

	//����ϵͳ�����з������Ⱥ�޹���������
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//����ϵͳ�з������Ⱥ�޹�����,��֤��ŵ緽��һ��
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//������Ҫ���޹���������ϵͳ�����з������Ⱥ�޹�������dNeedQΪ����
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//������Ҫ���޹����ʼ���ϵͳ�����з������Ⱥ�޹�������dNeedQΪ����
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero, bool bCheckVolt) = 0;
	//����ϵͳ�з������Ⱥ�޹�����,��֤���˵�ѹ����
	virtual bool AdjustReactPowerForVoltage(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	
};

#endif