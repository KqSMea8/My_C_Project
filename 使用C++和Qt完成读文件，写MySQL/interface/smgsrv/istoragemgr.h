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
	//ֹͣ��ǰ΢�������з��������豸[׼��������]
	virtual bool StopAllStorages(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//������ǰ΢�������з��������豸
	virtual bool StartAllStorages(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//�õ������ܵ�SOC״̬
	virtual int GetMainStorSocState(MicgridObectInfo* pCurMgObj) = 0;

	//ͳ���������豸�Ĺ���״��
	virtual void StatisticMainPower(MicgridObectInfo* pCurMgObj, int storPos) = 0;

	//�����еķ��������豸�ķ����й�����������΢�����Ĵ��ܶ����б�
	virtual void MakeStorageList(MicgridObectInfo* pCurMgObj, int pos, double curP, double proP, bool isProtect) = 0;

	//����ʱ΢��ϵͳ���д���ִ�б����Իָ����ԡ�����ֵ��true--�ָ������У�false--�ָ�������
	virtual bool ExecStorageRecallStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;
	//�����������ʵ���ʱִ�д��ܽ������Ȳ���
	virtual bool ExecStorageEmergeStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& remainP) = 0;

	//����ʱ���д���װ�ý���ָ�״̬
	virtual void StartRecalls(MicgridObectInfo* pCurMgObj) = 0;
	//����ʱ���д���װ�ý����ָ�״̬[δ��]
	virtual void EndRecalls(MicgridObectInfo* pCurMgObj) = 0;

	//int�ͺ������ؽ����0--δ������1--������δ�ﵽĿ�ꣻ2--������ﵽĿ�ꡣ
	//��1�����ڴ���װ�õ��й���������
	//��1.1������ϵͳ���ڴ���װ�õ��й��������ԡ�������dischgP--����������Ҫ���ӷŵ�Ĺ��ʣ�������ʾ��磩
	virtual int AdjustStorageStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double& actP, bool bprotect=false) = 0;
	//��1.2������ϵͳά������װ�õ�SOC����
	virtual int ProtectStorageStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, bool bzero) = 0;
	//��1.3������ϵͳ���ڴ���װ�õ��й��������ԡ�������dischgP--����������Ҫ���ӷŵ�Ĺ��ʣ�������ʾ��磩
	virtual int AdjustStorageForContinent(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double minActP, double& actP, bool needStart, bool toZeroP, intarray dealList) = 0;
	//��1.4��Ϊ�������������������ڴ���װ�õ��й��������ԡ�������dischgP--����������Ҫ���ӷŵ�Ĺ��ʣ�������ʾ��磩
	virtual int AdjustStorageForReverse(MicgridObectInfo* pCurMgObj, int ctrlReason, double dischgP, double& actP, bool needStart) = 0;
	//��2��ִ����΢�����ڸ������ܵı����Ե��ڣ���֤�������������͸������ܵĳ�ŵ緽��һ��
	// ������decStorP--�������ܿ��Լ��ٷŵ�Ĺ��ʣ���������incStorP--�������ܿ������ӷŵ�Ĺ��ʣ���������
	virtual int AdjustStorageForAccord(MicgridObectInfo* pCurMgObj, int ctrlReason, double decStorP, double incStorP, double& actP) = 0;
	//��3��ִ����΢�������ø���Ŀ�������Դ���������ܽ��лָ��Ե��ڲ��ԡ�actP--�������ܷŵ���
	virtual bool ExecStorageProtectForNormalP(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, double& incableP, double& decableP, bool hasAccord, bool iszero) = 0;

	//����ϵͳ�����д����豸�޹���������
	virtual bool AdjustReactPower(VQCAreaInfo* pCurVQCArea) = 0;

	//���Ե��������ܳ���
	virtual void TestAdjustMainStorage(MicgridObectInfo* pCurMgObj, double mainCurP) = 0;

	//���ڴ���װ�õ��й���������
	virtual bool AdjustStoragePStrategy(intarray storList, int ctrlReason, double& remainP, double maxAdjP=100000000.0) = 0;
	//���ڴ���װ�õ��޹���������
	virtual bool AdjustStorageQStrategy(intarray storList, int ctrlReason, double& remainP) = 0;

	//���ô���ת����ĳ�������
	virtual bool SetStorageCurP(intarray storList, int ctrlReason) = 0;

	//���ִ���װ�õ������й���������
	virtual void KeepupStoragePStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;
	//���ִ���װ�õ������޹���������
	virtual void KeepupStorageQStrategy(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//���ڴ���װ�õ��й�����
	virtual bool AdjustStoragePower(intarray storList, int ctrlReason, double totalCurP, double maxAdjP, double& remainP, bool needStart, bool isIsland=true) = 0;

	//����ϵͳ���SOC״������ȫ�����ܵı����Ե���
	virtual bool MicgridStorageKeepNormalForContinent(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP) = 0;
	//ֹͣ��ǰ΢�������з��������豸���޹�����
	virtual bool StopAllStoragesQ(MicgridObectInfo* pCurMgObj, int ctrlReason) = 0;

	//���SOC״������ȫ�����ܵı����Ե���
	virtual bool MicgridStorageKeepNormal(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP, double& incableP, double& decableP, bool iszero) = 0;
	//�����������ܵ��������
	virtual void GetAllIncreasablePower(MicgridObectInfo* pCurMgObj, double& incableP, double& decableP, double& totalP) = 0;

	virtual bool AdjustStorageListByOrder(MicgridObectInfo* pCurMgObj, intarray& storlist, double& remainP, int ctrlReason) = 0;

	//���SOC״������ȫ�����ܵı����Ե���--����Դ���ǽ�����(0.9-0.1)
	virtual bool MicgridStorageKeepNormalOnly(MicgridObectInfo* pCurMgObj, int ctrlReason, double& actP,  bool iszero) = 0;

	//����ϵͳ�����д����豸�޹���������
	virtual bool AdjustReactPowerToZero(VQCAreaInfo* pCurVQCArea) = 0;
	//����ϵͳ�д����豸�޹�����,��֤��ŵ緽��һ��
	virtual bool AdjustReactPowerForAccord(VQCAreaInfo* pCurVQCArea, double& incQ) = 0;
	//������Ҫ���޹���������ϵͳ�����д����豸�޹�������dNeedQΪ����
	virtual bool IncreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero) = 0;
	//������Ҫ���޹����ʼ���ϵͳ�����д����豸�޹�������dNeedQΪ����
	virtual bool DecreaseReactPowerByNeedQ(VQCAreaInfo* pCurVQCArea, double dNeedQ, double& dActQ, bool toZero) = 0;

	//�Ӵ��ܼƻ����߱��л�ȡ��ǰ���ܳ���Ŀ��ֵ
	virtual bool DealStoragePlanPowerValue(MicgridObectInfo* pCurMgObj, int minutes, double& storAimP) = 0;
};

#endif