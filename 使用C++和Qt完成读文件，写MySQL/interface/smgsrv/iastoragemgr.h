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
	//�����豸�Ƿ�������
	virtual bool IsRunning(int pos, bool bRefresh=false) = 0;

	//�����豸�Ƿ�λ��ָ��΢�������õ�����Դ�б���
	virtual bool InMainSource(int id, MicgridObectInfo* pCurMgObj) = 0;
	//�����豸�Ƿ�Ϊ��Ч�ķ�������
	virtual bool IsUnmainSource(int pos, MicgridObectInfo* pCurMgObj) = 0;

	//���������豸
	virtual bool ActStartStorage(int pos, int ctrlReason, bool actMain=false) = 0;
	//ֹͣ�����豸[δ��]
	virtual bool ActStopStorage(int pos, int ctrlReason, bool isActive) = 0;

	//�������ܲ��л�������Դģʽ��VFģʽ��
	virtual bool StartMainStorage(int pos, int ctrlReason) = 0;
	//�������ܲ��л���������Դģʽ��PQģʽ��
	virtual bool StartUnmainStorage(int pos, int ctrlReason) = 0;

	//�л�������Դģʽ
	virtual bool IntoMainMode(int pos, int ctrlReason) = 0;
	//�л���������Դģʽ
	virtual bool IntoUnmainMode(int pos, int ctrlReason) = 0;

	//����ϵͳ�е������ܵı����Ե���
	virtual bool StorageKeepNormalForContinent(int pos, int ctrlReason, double& actDchgP) = 0;
	//�������ܵı����Ե���
	virtual bool StorageKeepNormal(int pos, int ctrlReason, bool isContinue, double maxAdjP, double& maxChgP, double& maxDchgP, double& actDchgP, double& incableP, double& decableP, bool iszero) = 0;

	//��ȡ���ܵı����Ե��ڹ���ֵ
	virtual double GetAdjustPowerForProtect(int pos, double curP, bool& isProtect) = 0;
	//�õ��������ܵ����ŷŵ繦��[����]
	virtual double GetStorageOptDchgPower(int pos) = 0;
	//�õ��������ܵ����ų�繦��[����]
	virtual double GetStorageOptChgPower(int pos) = 0;

	//ִ�е�������װ���й����ڲ���
	virtual int ActAdjustStorage(int pos, int ctrlReason, double curValue, double planValue, bool forSoc, bool notGuard, bool actStart) = 0;
	//ִ�е�������װ���й����ʵ��ڵ�0����
	virtual int ActZeroStorage(int pos, int ctrlReason) = 0;

	//�������Ĵ��ָܻ��������״̬��curP < 0��remainP > 0��
	virtual bool ChangeStorageToZero(int pos, int ctrlReason, double curP, double maxAdjP, double& actDchgP) = 0;
	//�����ŵ�Ĵ��ָܻ��������״̬��curP > 0��remainP < 0��
	virtual bool DischangeStorageToZero(int pos, int ctrlReason, double curP, double maxAdjP, double& actDchgP) = 0;
	//����ϵͳ�е������ָܻ��������״̬��
	virtual bool StorageToZeroForSOC(int pos, int ctrlReason, double maxAdjP, double& actDchgP) = 0;

	//���ڵ��������豸�޹����ʡ�����ֵ��0 --�޶�����1--����ʧ�ܣ�2--���ڳɹ���
	virtual int AdjustStorageQ(int pos, double& adjustQ) = 0;
	//ִ�е�������װ���޹����ڲ���������ֵ��0 --�޶�����1--������ڣ�2--���ڳɹ���
	virtual int ActAdjustStorageQ(int pos, int ctrlReason, double curValue, double planValue, bool notGuard, bool actStart) = 0;
	//ִ�е�������װ���޹����ʵ��ڵ�0����������ֵ��0 --�޶�����1--������ڣ�2--���ڳɹ���
	virtual int ActZeroStorageQ(int pos, int ctrlReason) = 0;
	//���������޹��ָ��������״̬��
	virtual bool StorageQToZero(int pos, int ctrlReason, double maxAdjQ) = 0;

	//����ִ�е�������װ�õ��ڲ���
	virtual bool TestAdjustStorageP(int pos, double planValue) = 0;
	//��������������
	virtual void TestStartMainStorage(int mgId, int storPos) = 0;
	
	//�õ����ܵĿɵ��ڳ���
	virtual void GetAdjustableStorPower(int pos, double maxAdjP, double& incableP, double& decableP, double& totalP, bool bstor) = 0;

	//���������޹����ʵĴ����豸�����޹����㡣adjustQΪ����
	virtual bool IncreaseStorageQToZero(int pos, double& adjustQ) = 0;
	//���������޹����ʵĴ����豸�����޹����㡣adjustQΪ����
	virtual bool DecreaseStorageQToZero(int pos, double& adjustQ) = 0;

};

#endif