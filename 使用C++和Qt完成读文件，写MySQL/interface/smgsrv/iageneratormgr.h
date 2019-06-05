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
	//������Ƿ�ɵ�
	virtual bool CanAdjust(int pos) = 0;

	//������Ƿ�λ��ָ��΢�������õ�����Դ�б���
	virtual bool InMainSource(int id, MicgridObectInfo* pCurMgObj) = 0;
	//������Ƿ�Ϊ��Ч�ķ��������
	virtual bool IsUnmainSource(int pos, MicgridObectInfo* pCurMgObj) = 0;
	//������Ƿ�Ϊ���еķ����ĵ�Դ
	virtual bool IsRunningUnmainGen(int pos, MicgridObectInfo* pCurMgObj) = 0;

	//ִ�з�����������������أ�0--ʧ�ܣ�1--�ȴ���2--�ɹ���
	virtual int ActStartGenerator(int pos, int ctrlReason, double& actP, bool blackStart=false, bool toMaxP=false) = 0;
	//�л�������Դģʽ
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//�л���������Դģʽ
	virtual bool IntoUnmainMode(int pos, int ctrlReason) = 0;
	//ִ�з����ֹͣ����
	virtual bool ActStopGenerator(int pos, int ctrlReason, bool blackStart) = 0;
	//��������������л�������Դģʽ
	virtual int StartMainGenerator(int pos, int ctrlReason, bool blackStart) = 0;

	//��ʼ���ɵ�������ĳ���������toZeroP��0--���ڵ�0.0��1--���ڵ���С�ɵ�������2--���ڵ����ù������ޡ�
	virtual double InitAdjustGenerator(int pos, int ctrlReason, int toZeroP) = 0;
	//�ָ��������ɵ����������������isNewGen--�Ƿ�Ϊ�����������
	virtual bool RecallAdjGeneratorPower(int pos, int ctrlReason, bool toOptPow, double& remainP) = 0;
	//���ӿɵ��������������������ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	virtual int IncreaseGeneratorPower(int pos, int ctrlReason, bool toOptPow, bool bSendAgc, double& remainP, bool smoothPlant, double smoothRate) = 0;
	//�õ��ɵ�������Ŀ����ӳ���
	virtual void GetAdjustableGeneratorPower(int pos, double maxAdjP, double& incableP, double& decableP) = 0;

	//���ڵ���������޹����ʡ�����ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	//����groupCtrlType��0 --�����Ż����ƣ�1--�����鲥Ⱥ�أ�2--������������ơ�
	virtual int AdjustGeneratorQ(int pos, double& adjustQ, int groupCtrlType, bool bCheckVolt) = 0;
	//���������޹����ʵķ���������޹����㡣adjustQΪ����
	virtual bool IncreaseGeneratorQToZero(int pos, double& adjustQ) = 0;
	//���������޹����ʵķ���������޹����㡣adjustQΪ����
	virtual bool DecreaseGeneratorQToZero(int pos, double& adjustQ) = 0;

	//���Ժ������������
	virtual void TestStartMainGenerator(int mgId, int genPos) = 0;
	//����״̬ά�������������ƽ�����
	virtual bool TestMainGenerator(int pos, double mainP) = 0;
	//����ģʽ�����������������������
	virtual double TestMainGeneratorStartPower(int genPos, double growGen, bool bFreqAutoAdjust) = 0;

	//ִ�з�������ڲ���������ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	//����checkChanged��0 --�����仯����1--�����ȱ仯����2--Ⱥ�ر仯����
	virtual int ActAdjustGenerator(int pos, int ctrlReason, double planValue, double& actValue, int checkChanged, bool checkControl) = 0;
	
};

#endif