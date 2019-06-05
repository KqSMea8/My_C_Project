//igeneratordao.h

#ifndef _IGENERATORDAO_PENGSHIKANG_20100323_H_
#define _IGENERATORDAO_PENGSHIKANG_20100323_H_

#include "imgddao.h"                             // for IMgdDao
#include "../../../icsvalue.h"                   // for intarray

#define GENERATORDAO_CLASSID    "cgeneratordao"
#define GENERATORDAO_INTFID     "igeneratordao"

class IEquipDao;
class IEquipTypeDao;

class IGeneratorDao : virtual public IMgdDao
{
public:
	//��ָ��λ�õķ����������뷢���������
	virtual void AddObjectIntoNewGenList(int pos, intarray& list, IEquipDao* pEquip) = 0;//1,���еĿ������ɵ������
	virtual void AddObjectIntoMaxGenList(int pos, intarray& list) = 0;//2,���еĲ��������ɵ������
	virtual void AddObjectIntoCurGenList(int pos, intarray& list) = 0;//3,���еĿ��г����ɵ������
	virtual void AddObjectIntoStopGenList(int pos, intarray& list) = 0;//4,ͣ�˵Ŀ�Ͷ�����
	//5,������������Ѱ���ǰ�ɱ���С��������Ķ����б���
	virtual void AddObjectIntoCostList(int pos, int* posList, int& count) = 0;
	
	//���ݷ����λ�ø��µ�ǰ��ͣ״̬			
	virtual bool UpdateRunState(int pos, int& runState) = 0;
	//���ݷ����λ�ø��¿���ģʽ			
	virtual bool UpdateControlMode(int pos, int& modeState) = 0;
	
	//���ݷ����λ�õõ�����й�����
	virtual double GetMaxP(int pos) = 0;
	//���ݷ����λ�õõ�����޹�����
	virtual double GetMaxQ(int pos) = 0;
	//���ݷ����λ�õõ��ɵ����������С�����й�����
	virtual double GetMinCtrlP(int pos) = 0;
	//���ݷ����λ�õõ��ɵ����������С�����޹�����
	virtual double GetMinCtrlQ(int pos) = 0;
	//���ݷ����λ�õõ��������������ʱ�������й�����
	virtual double GetOptimumP(int pos) = 0;
	//���ݷ����λ�õõ������Ӧʱ�䣨�죩
	virtual double GetRespTime(int pos) = 0;
	//���ݷ����λ�õõ���������ң��ID
	virtual int GetCosCtrlID(int pos) = 0;
	//���ݷ����λ�õõ�����й����ʵĵ��ڱ�־
	virtual int GetPCtrlFlag(int pos) = 0;
	//���ݷ����λ�õõ�����޹����ʵĵ��ڱ�־
	virtual int GetQCtrlFlag(int pos) = 0;

	//���ݷ����λ�õõ����һ������ͣ����ʼʱ��
	virtual double GetRecentStopTime(int pos) = 0;
	//���ݷ����λ���������һ������ͣ����ʼʱ��
	virtual bool SetRecentStopTime(int pos, double startTime) = 0;
	//���ݷ����λ�õõ����һ�ζ���ʱ��
	virtual double GetRecentActTime(int pos) = 0;
	//���ݷ����λ���������һ�ζ���ʱ��
    virtual bool SetRecentActTime(int pos, double actTime) = 0;
	//���ݷ����λ�õõ��ն�������
	virtual int GetActTimesOfToday(int pos) = 0;
	//���ݷ����λ�������ն�������
	virtual bool IncreaseActTimesOfToday(int pos) = 0;
	
	//������е�������ʧ�ܴ���
	virtual void ClearAllFailTimes() = 0;
	//�����΢���ڷ�����ĵ�������ʧ�ܴ���
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//���ݷ����λ�ó�ʼ����������ʧ�ܴ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//���ݷ����λ�����Ӷ�������ʧ�ܴ�����actType��0--�˳���1--Ͷ��
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//���ݷ����λ�õõ���������ʧ�ܴ���
	virtual int GetActFailTimes(int pos) = 0;
	//���ݷ����λ���ж��Ƿ�ɶ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual bool CanAct(int pos, int actType) = 0;

	//���ݷ����λ�ó�ʼ����������ʧ�ܴ�����actType��0--���飻1--������2--ȫ��
	virtual bool InitStartFailTimes(int pos, int actType) = 0;
	//���ݷ����λ��������������ʧ�ܴ�����actType��0--���飻1--����
	virtual bool IncreaseStartFailTimes(int pos, int actType) = 0;
	//���ݷ����λ�õõ���������ʧ�ܴ���
	virtual int GetStartFailTimes(int pos) = 0;
	//���ݷ����λ���ж��Ƿ��������actType��0--���飻1--������2--ȫ��
	virtual bool CanStart(int pos, int actType) = 0;

	//���ݷ����λ�ó�ʼ����������ʧ�ܴ�����actType��0--�й���1--�޹���2--ȫ��
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//���ݷ����λ�����ӵ�������ʧ�ܴ�����actType��0--�й���1--�޹�
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//���ݷ����λ�õõ���������ʧ�ܴ���
	virtual int GetAdjustFailTimes(int pos) = 0;
	//���ݷ����λ���ж��Ƿ�ɵ��ڡ�actType��0--�����й���1--�����޹���2--ȫ��
	virtual bool CanAdjust(int pos, int actType) = 0;

	//���ݷ����λ�õõ���������ID
	virtual int GetStartCtrlID(int pos) = 0;
	//���ݷ����λ�õõ�ֹͣ����ID
	virtual int GetStopCtrlID(int pos) = 0;
	//���ݷ����λ�õõ���ͣ״̬ID
	virtual int GetRunStateID(int pos) = 0;
	//���ݷ����λ�õõ�VFģʽ����ID
	virtual int GetVFmodeCtrlId(int pos) = 0;
	//���ݷ����λ�õõ�PQģʽ����ID
	virtual int GetPQmodeCtrlId(int pos) = 0;
	//���ݷ����λ�õõ�����ģʽ״̬ID
	virtual int GetModeStateID(int pos) = 0;
	
	//���ݷ����λ�õõ��������;����
	virtual int GetUseType(int pos) = 0;
	//���ݷ����λ�õõ����������Դģʽ
	virtual int GetMainModeType(int pos) = 0;
	//���ݷ����λ�õõ��������������
	virtual int GetStartType(int pos) = 0;
	//���ݷ����λ�õõ������������Ҫ��ʱ����(��)
	virtual int GetStartActTime(int pos) = 0;
	//���ݷ����λ�õõ�����ɱ�
	virtual double GetProductCost(int pos) = 0;
	//���ݷ����λ�õõ��й�ң�������ȹ���ֵ
	virtual double GetSensitivity(int pos) = 0;
	//���ݷ����λ�õõ��������й�������(%)
	virtual double GetMaxEconomicPower(int pos) = 0;
	//���ݷ����λ�õõ��������й�������(%)
	virtual double GetMinEconomicPower(int pos) = 0;
	//��÷����豸����
	virtual int GetGenType(int pos) = 0;

	//���ݷ����λ�õõ���ǰVF����ģʽ
	virtual int GetCurVFModStat(int pos) = 0;   
	//���ݷ����λ�����õ�ǰVF����ģʽ
	virtual bool SetCurVFModStat(int pos, int mode) = 0;   
	//���ݷ����λ�õõ���ǰ�Ƿ��������Ƴ���
    virtual int GetRestrictedFlag(int pos) = 0;
	
	//���ݷ����λ�õõ�������������������ʱ��(����)
	virtual int GetRunSpanlmt(int pos) = 0;
	//���ݷ����λ�õõ�ͣ��������ͣ��ʱ��(����)
	virtual int GetStopSpanlmt(int pos) = 0;

	//���ݷ����λ�õõ���ǰ�������ͣ״̬
	virtual int GetCurRunState(int pos) = 0;   
	//���ݷ����λ�����õ�ǰ�������ͣ״̬
	virtual bool SetCurRunState(int pos, int runState) = 0;   

	//���ݷ����λ���ж��豸�Ƿ�Ϊ��������Դ�����豸
	virtual bool IsRenewable(int pos, IEquipDao* pEquip, IEquipTypeDao* pEqpType) = 0;
	//���ݷ����λ���жϵ�ǰ������Ƿ�Ϊ���������
	virtual bool IsWindGen(int pos, IEquipDao* pEquip) = 0;
	//���ݷ����λ���жϵ�ǰ������Ƿ�Ͷ��
	virtual bool IsAdded(int pos, bool bRefresh=false) = 0;
	//���ݷ����λ���жϵ�ǰ������Ƿ�����
	virtual bool IsStarted(int pos, IEquipDao* pEquip=0) = 0;
	//���ݷ����λ���жϵ�ǰ������Ƿ�ͣ��
	virtual bool IsStopped(int pos, IEquipDao* pEquip=0) = 0;
	//���ݷ����λ���жϵ�ǰ������Ƿ����������ģʽ
	virtual bool IsMainMode(int pos) = 0;

	//���ݷ����λ�õõ����������ϵ��
	virtual double GetGenAdjustCoef(int pos) = 0;
	//�ж�ָ��λ�õķ�����Ƿ��ɲ����Զ��ж�
	virtual bool GetAutoCutFlag(int pos) = 0;
	//����ָ��λ�õķ�����Ƿ��ɲ����Զ��ж�
	virtual bool SetAutoCutFlag(int pos, bool autoCut=true) = 0;
	//���ݷ����λ�õõ����������
	virtual double GetAntiImpactRatio(int pos) = 0;
	//���ݷ����λ�õõ������й�����
	virtual double GetBackupPower(int pos) = 0;

	//���ݷ����λ�õõ����������������
	virtual double GetStartImpactRatio(int pos) = 0;
	//���ݷ����λ�õõ����ϸ��������ID
	virtual int GetRevertCtrlId(int pos) = 0;  
	//���ݷ����λ�õõ����˵�ѹң��ID
	virtual int GetGenVolId(int pos) = 0;       
	//���ݷ����λ�õõ�����Ƶ��ң��IDs
	virtual int GetGenFreqId(int pos) = 0;        
	//���ݷ����λ�õõ���ǰ���˵�ѹ
	virtual double GetGeneratorVoltage(int pos) = 0;          
	//���ݷ����λ�õõ���ǰ����Ƶ��
	virtual double GetGeneratorFrequency(int pos) = 0;  
	//���ݷ����λ�ø��»��˵�ѹƵ��			
	virtual void UpdateGenUF(int pos) = 0;
	//���ݷ����λ�����õ�ǰ��ѹ��Ƶ��Ϊ����ֵ[������]
	virtual bool TestUFtoNormal(int pos, double rateF) = 0;

	//�ж�ָ��λ�õķ�����Ƿ��˹�������Ͷ�����
	virtual bool ManuLockAdd(int pos) = 0;
	//�ж�ָ��λ�õķ�����Ƿ��˹��������г�����
	virtual bool ManuLockCut(int pos) = 0;

	//�ж�ָ��λ�õķ��������������ʱ���Ƿ�ﵽҪ��
	virtual bool CheckRunTimeSpan(int pos, double curTime) = 0;
	//�ж�ָ��λ�õķ����������ͣ��ʱ���Ƿ�ﵽҪ��
	virtual bool CheckStopTimeSpan(int pos, double curTime) = 0;
	//�ж�ָ��λ�õķ��������������ͣ��ʱ���Ƿ�ﵽҪ��
	virtual bool CheckAutoStopTimeSpan(int pos, double curTime) = 0;

	//���ݷ����λ�õõ���������״̬ң��ID
	virtual int GetStandbyStatusId(int pos) = 0;
	//���ݷ����λ���ж��Ƿ��ڲ�������״̬
	virtual bool IsStandbyState(int pos) = 0;

	//���ݷ����λ�ø���������Ϣ
	virtual void UpdateRunInfo(int pos) = 0;

	//���ݷ����λ�õõ��й�����Ŀ��ֵң��ID
	virtual int GetCtrlAimPId(int pos) = 0;
	//���ݷ����λ�õõ��޹�����Ŀ��ֵң��ID
	virtual int GetCtrlAimQId(int pos) = 0;

	//���㷢������ۺ�����״̬
	virtual RUNSTATETYPE CalcCurRunStateType(int pos, bool& canAdjust, IEquipDao* pEquip, int* eqpPos=0) = 0;
	//���ݷ����λ�õõ���ǰ���������״̬����
	virtual RUNSTATETYPE GetCurRunStateType(int pos) = 0;
	//���ݷ����λ�����õ�ǰ���������״̬����
	virtual bool SetCurRunStateType(int pos, RUNSTATETYPE runType) = 0;

	//���ݷ����λ���ж��Ƿ����������ʵ�����״̬
	virtual bool IsMaxPowerRunState(int pos) = 0;

	//�õ�������ң��ID�ֶ�����
	virtual FIELDTYPE GetGenEnergyIdType() = 0;       
	//���ݷ����λ�õõ��ۼƷ�����ң��ID�ֶ�ָ��
	virtual void GetGenEnergyIdPoint(int pos, void* pTodayWId, void* pTotalWId) = 0;        
	//���ݷ����λ�õõ����շ�����
	virtual double GetTodayEnergy(int pos) = 0;          
	//���ݷ����λ�õõ��ۼƷ�����
	virtual double GetTotalEnergy(int pos) = 0;  
	//���ݷ����λ�ø��½��շ��������ۼƷ�����
	virtual void UpdateGenEnergy(int pos, double todayW, double totalW) = 0;

	//���ݷ����λ���ж��Ƿ�ɵ����й�����
	virtual bool CanAdjustP(int pos) = 0;
	//���ݷ����λ���ж��Ƿ�ɵ����޹�����
	virtual bool CanAdjustQ(int pos) = 0;

	//���ݷ����λ���ж��Ƿ�����ӷ�������й�������
	//������maxP--�����ʵ���ܴﵽ������й�������incP--������ɵ������ӵ��й�������
	virtual bool CanIncreasePValue(int pos, double& maxP, double& incP) = 0;
	//���ݷ����λ���ж��Ƿ�ɵ��ڷ�������޹�������
	//������minQ--���������С�޹�������maxQ--�����������޹�������curQ--������ĵ�ǰ�޹�������
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;

	//���ݷ����λ�õõ��޹�ң�������ȹ���ֵ
	virtual double GetSensitivityQ(int pos) = 0;
	//���ݷ����λ�ö�ȡͳ�ƴ洢����ID��������ʷ�洢��
	virtual int GetSaveTimerID(int pos) = 0;

	virtual void AddObjectIntoActTimeGenList(int pos, intarray& list) = 0;//6,������ʱ����絽������ķ����

	//���ݷ����λ���жϵ�ǰ������Ƿ�Ϊ��������
	virtual bool IsPVGen(int pos, IEquipDao* pEquip) = 0;

	//���ݷ����λ���жϵ�ǰ�����������ǰ�Ƿ���Ҫ������С��������
	virtual bool NeedAdjustPowerBeforeStart(int pos, IEquipDao* pEquip) = 0;

	virtual void AddObjectIntoIncQGenList(int pos, intarray& list) = 0;//7,�������޹����ʴӴ�С����ķ����
	virtual void AddObjectIntoDecQGenList(int pos, intarray& list) = 0;//8,���ɼ��޹����ʴӴ�С����ķ����
	virtual void AddObjectIntoVoltGenList(int id, intarray& list, IEquipDao* pEquip) = 0;//9,�����˵�ѹ�Ӹߵ�������ķ����

	//���ݷ����λ�õõ��޵�״̬ң��ID
	virtual int GetRestrictStatusId(int pos) = 0;
	//���ݷ����λ���ж��Ƿ����޵�״̬
	virtual bool IsRestrictState(int pos) = 0;
	//���ݷ����λ�õõ������豸�ͺ�ID
	virtual int GetGeneratorModeId(int pos) = 0;

	//���ݷ����λ�õõ����ٷֱȵ���ʱ�Ļ�׼�޹�����
	virtual double GetBaseQ(int pos) = 0;

	//�������з�����ĵ�ǰ���������״̬����
	virtual void SaveCurRunStateType() = 0;

};

#endif
