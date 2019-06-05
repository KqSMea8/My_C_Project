
#ifndef _ISTRGSTATION_20190527_H
#define _ISTRGSTATION_20190527_H


#define STORAGEDAO_CLASSID    "cstoragedao"
#define STORAGEDAO_INTFID     "istoragedao"

class IEquipDao;
class IExprCalDao;
class ICommSrcDao;

class IStorageDao : virtual public IMgdDao
{
public:	
	//����ָ��λ�õĴ���װ�ô��ڻָ�״̬
	virtual void StartRecall(int pos) = 0;
	//��ָ��λ�õĴ���װ�ý����ָ�״̬
	virtual void EndRecall(int pos) = 0;
	//�ж�ָ��λ�õĴ���װ���Ƿ��ڻָ�״̬
	virtual bool IsRecalling(int pos) = 0;
	//�ж�ָ��λ�õĴ���װ���Ƿ���������ָ�״̬
	virtual bool CanEndRecall(int pos, bool isIsland) = 0;

	//�ж�ָ��λ�õĴ���װ���Ƿ���������й�����
	virtual bool CanAdjustPower(int pos) = 0;
	//�ж�ָ��λ�õĴ���װ���Ƿ�����ŵ�
	virtual bool CanDischange(int pos) = 0;
	//�ж�ָ��λ�õĴ���װ���Ƿ�������
	virtual bool CanChange(int pos) = 0;

	//��ָ��λ�õĴ���װ�ö�����봢��װ�ü�����
	virtual void AddObjectIntoStorageList(int pos, intarray& list) = 0;

	//���ݴ���װ��λ�ø���������Ϣ
	virtual double UpdateRunInfo(int pos, IExprCalDao* pExprCal, ICommSrcDao* pCommSrc, bool& bBmsState, bool& bNeedStop) = 0;//ʹ��m_idxMaxSocID��

	//���ݴ���װ��λ�õõ������Ӧʱ�䣨�죩
	virtual double GetRespTime(int pos) = 0;
	//���ݴ���װ��λ�ü��㵱ǰSOC��λֵ
	virtual int GetCurSocState(int pos) = 0;

	//���ݴ���װ��λ�õõ����õ�����ŵ��޹�����[���ǿ��ñ���]
	virtual double GetMaxChargePowerIn(int pos) = 0;
	//���ݴ���װ��λ�õõ����õ�����ŵ��й�����[���ǿ��ñ���]
	virtual double GetMaxDischargePowerIn(int pos) = 0;

	//���ݴ���װ��λ�õõ������������й�����[���ǿ��ñ��ʺ�SOC]
	virtual double GetMaxChargePower(int pos) = 0;
	//���ݴ���װ��λ�õõ���������ŵ��й�����[���ǿ��ñ��ʺ�SOC]
	virtual double GetMaxDischargePower(int pos) = 0;

	//���ݴ���װ��λ�õõ����õ����ų���й�����[���ǿ��ñ���]
	virtual double GetOptimizeChargePowerIn(int pos) = 0;
	//���ݴ���װ��λ�õõ����õ����ŷŵ��й�����[���ǿ��ñ���]
	virtual double GetOptimizeDischargePowerIn(int pos) = 0;

	//���ݴ���װ��λ�õõ���������ų���й�����[���ǿ��ñ��ʺ�SOC]
	virtual double GetOptimizeChargePower(int pos, bool isMain=false) = 0;
	//���ݴ���װ��λ�õõ���������ŷŵ��й�����[���ǿ��ñ��ʺ�SOC]
	virtual double GetOptimizeDischargePower(int pos, bool isMain=false) = 0;
	//���ݴ���װ��λ�õõ�Ŀ��ŵ��й�����[���ǿ��ñ��ʺ�SOC]
	virtual double GetAimDischargePower(int pos, bool isMain=false) = 0;

	//���ݴ���װ��λ�õõ��豸�������ʣ������(%)
	virtual double GetMaxSocInIsland(int pos) = 0;
	//���ݴ���װ��λ�õõ��豸������Сʣ������(%)
	virtual double GetMinSocInIsland(int pos) = 0;

	//���ݴ���װ��λ�õõ����õ������ʣ������(%)
	virtual double GetMaxSocInConnect(int pos) = 0;
	//���ݴ���װ��λ�õõ����õ�����Сʣ������(%)
	virtual double GetMinSocInConnect(int pos) = 0;

	//���ݴ���װ��λ�õõ���������ң��ID
	virtual int GetCosCtrlID(int pos) = 0;
	//���ݴ���װ��λ�õõ�ʣ������ID
	virtual int GetCurSocID(int pos) = 0;

	//���ݴ���װ��λ�õõ�ʣ������
	virtual double GetCurSoc(int pos) = 0;
	virtual double GetCurCapacity(int pos) = 0;

	//���ݴ���װ��λ������һ�γ�����
	//virtual void IncreaseChargeCount(int pos) = 0;

	//���ݴ���װ��λ������һ�ηŵ����
	//virtual void IncreaseDischargeCount(int pos) = 0;

	//���ݴ���װ��λ�õõ���ŵ��־
	virtual int GetChargeFlag(int pos) = 0;

	//���ݴ���װ��λ������һ�γ�����
	virtual void IncreaseChargeCount(int pos, double actTime) = 0;
	//���ݴ���װ��λ������һ�ηŵ����
	virtual void IncreaseDischargeCount(int pos, double actTime) = 0;

	//���ݴ���װ��λ�õõ����һ�ο���ʱ��
	virtual double GetRecentActTime(int pos) = 0;
	//���ݷ����λ���������һ�ζ���ʱ��
	virtual bool SetRecentActTime(int pos, double actTime) = 0;

	//���ݴ���װ��λ�����������ܵĿɵ��ڹ���
	virtual void IncreaseAdjustStorP(int pos, bool isIsland, float& dMaxDchgP, float& dMaxChgP) = 0;

	//���ݴ���װ��λ�õõ�PCS��������ID
	virtual int GetStartCtrlID(int pos) = 0;
	//���ݴ���װ��λ�õõ�PCSֹͣ����ID
	virtual int GetStopCtrlID(int pos) = 0;
	//���ݴ���װ��λ�õõ�PCS��ͣ״̬ID
	virtual int GetRunStateID(int pos) = 0;
	//���ݴ���װ��λ�õõ�VFģʽ����ID
	virtual int GetVFmodeCtrlId(int pos) = 0;
	//���ݴ���װ��λ�õõ�PQģʽ����ID
	virtual int GetPQmodeCtrlId(int pos) = 0;
	//���ݴ���װ��λ�õõ�����ģʽ״̬ID
	virtual int GetModeStateID(int pos) = 0;

	//���ݴ���װ��λ�õõ�������;����
	virtual int GetUseType(int pos) = 0;
	//���ݴ���װ��λ�õõ�����Դģʽ
	virtual int GetMainModeType(int pos) = 0;
	//���ݴ���װ��λ�õõ���ŵ�����Ч��
	virtual double GetConverseEffect(int pos) = 0;
	//���ݴ���װ��λ�õõ�����ɱ�
	virtual double GetProductCost(int pos) = 0;
	//���ݴ���װ��λ�õõ��й�ң�������ȹ���ֵ
	virtual double GetSensitivity(int pos) = 0;

	//���ݴ���װ��λ�õõ���ǰ���������͡�0��������Կɿأ�1�������˹����ƣ�2�������żƻ�����
	virtual int GetControllerType(int pos) = 0;
	//���ݴ���װ��λ�����õ�ǰ���������͡�0��������Կɿأ�1�������˹����ƣ�2�������żƻ�����
	virtual bool SetControllerType(int pos, int ctrlType) = 0;

	//���ݴ���װ��λ�õõ���ǰVF����ģʽ
	virtual int GetCurVFModStat(int pos) = 0;
	//���ݴ���װ��λ�����õ�ǰVF����ģʽ
	virtual bool SetCurVFModStat(int pos, int mode) = 0;

	//���ݴ���λ���жϵ�ǰ�����Ƿ�Ͷ��
	virtual bool IsAdded(int pos, bool bRefresh=false) = 0;
	//���ݴ���λ���жϵ�ǰ�����Ƿ�����
	virtual bool IsStarted(int pos) = 0;
	//���ݴ���λ���жϵ�ǰ�����Ƿ����������ģʽ
	virtual bool IsMainMode(int pos) = 0;
	//���ݴ���λ���жϵ�ǰ�����Ƿ���PQ����ģʽ
	virtual bool IsPQMode(int pos) = 0;
	//���ݴ���λ�õõ����������
	virtual double GetAntiImpactRatio(int pos) = 0;
	//���ݴ���λ�õõ������й�����
	virtual double GetBackupPower(int pos) = 0;

	//���ݴ���λ�õõ�PCS���ϸ������ID
	virtual int GetRevertCtrlId(int pos) = 0;

	//������е�������ʧ�ܴ���
	virtual void ClearAllFailTimes() = 0;
	//�����΢���ڴ���װ�õĵ�������ʧ�ܴ���
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//���ݴ���λ�ó�ʼ����������ʧ�ܴ�����actType��0--���飻1--������2--ȫ��
	virtual bool InitStartFailTimes(int pos, int actType) = 0;
	//���ݴ���λ��������������ʧ�ܴ�����actType��0--���飻1--����
	virtual bool IncreaseStartFailTimes(int pos, int actType) = 0;
	//���ݴ���λ�õõ���������ʧ�ܴ���
	virtual int GetStartFailTimes(int pos) = 0;
	//���ݴ���λ���ж��Ƿ��������actType��0--���飻1--������2--ȫ��
	virtual bool CanStart(int pos, int actType) = 0;

	//���ݴ���λ�ó�ʼ����������ʧ�ܴ�����actType��0--�й���1--�޹���2--ȫ��
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//���ݴ���λ�����ӵ�������ʧ�ܴ�����actType��0--�й���1--�޹�
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//���ݴ���λ�õõ���������ʧ�ܴ���
	virtual int GetAdjustFailTimes(int pos) = 0;
	//���ݴ���λ���ж��Ƿ�ɵ��ڡ�actType��0--�����й���1--�����޹���2--ȫ��
	virtual bool CanAdjust(int pos, int actType) = 0;

	//���㴢��SOC��λ
	virtual int CalculateSocPos(float minSoc, float maxSoc, float curSoc, float curP) = 0;

	//���ݴ���λ���ж�ָ��λ�õĴ���װ���Ƿ��˹�������Ͷ�����
	virtual bool ManuLockAdd(int pos) = 0;
	//���ݴ���λ���ж�ָ��λ�õĴ���װ���Ƿ��˹��������г�����
	virtual bool ManuLockCut(int pos) = 0;

	//���ݴ���λ�õõ��й�����Ŀ��ֵң��ID
	virtual int GetCtrlAimPId(int pos) = 0;
	//���ݴ���λ�õõ��޹�����Ŀ��ֵң��ID
	virtual int GetCtrlAimQId(int pos) = 0;

	//���ݴ���λ�õõ�PCS����������ID
	virtual int GetBlackStartCtrlID(int pos) = 0;
	//���ݴ���λ�õõ���ǰ���ܿ���֧·����
	virtual double GetCurCapaRate(int pos) = 0;

	//���ݴ���λ�õõ�PCS��ֵ����(kVar)
	virtual double GetPcsZeroValue(int pos) = 0;
	//���ݴ���λ�õõ�PCS����kW
	virtual double GetPcsCapacity(int pos) = 0;

	//���ݴ����豸λ�õõ���ǰ����״̬
	virtual int GetCurRunState(int pos) = 0;
	//���ݴ����豸λ�����õ�ǰ����״̬
	virtual bool SetCurRunState(int pos, int runState) = 0;

	//��ָ��λ�õĴ��ܸ����й������Ӵ�С���봢��װ�ü�����
	virtual void AddObjectIntoStorageListByP(int pos, intarray& list) = 0; 
	//��ָ��λ�õĴ��ܸ����޹������Ӵ�С���봢��װ�ü�����
	virtual void AddObjectIntoStorageListByQ(int pos, intarray& list) = 0;

	//���ݴ����豸λ���ж��Ƿ�ɵ����й�����
	virtual bool CanAdjustP(int pos) = 0;
	//���ݴ����豸λ���ж��Ƿ�ɵ����޹�����
	virtual bool CanAdjustQ(int pos) = 0;

	//���㴢���豸���ۺ�����״̬
	virtual RUNSTATETYPE CalcCurRunStateType(int pos, bool& canAdjP, IEquipDao* pEquip, int* eqpPos) = 0;

	//���ݴ���װ��λ�õõ����ɵ��޹����͡� 0���̶�ֵ  1�����������뵱ǰ�й�ʵʱ����
	virtual int GetQCtrlType(int pos) = 0;

};

#endif
