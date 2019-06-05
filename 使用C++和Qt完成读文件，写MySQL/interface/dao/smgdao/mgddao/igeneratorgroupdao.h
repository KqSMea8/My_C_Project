//igeneratorgroupdao.h

#ifndef _IGENERATORGROUPDAO_PENGSHIKANG_20170106_H_
#define _IGENERATORGROUPDAO_PENGSHIKANG_20170106_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../icsvalue.h"                   // for intarray

#define GENERATORGROUPDAO_CLASSID    "cgeneratorgroupdao"
#define GENERATORGROUPDAO_INTFID     "igeneratorgroupdao"

class IEquipDao;
class IEquipTypeDao;

class IGeneratorGroupDao : virtual public IBasicDao
{
public:
	//��ָ��λ�õķ������Ⱥ������뷢�����Ⱥ������
	virtual void AddObjectIntoGenGroupList(int pos, intarray& list) = 0;
	//���ݷ������Ⱥλ�õõ�����ĸ��ID
	virtual int GetBusID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ������΢��ID
	virtual int GetSelfMicgridID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��������ѹң��ID
	virtual int GetUID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ����й�ң��ID
	virtual int GetPID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ����޹�ң��ID
	virtual int GetQID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��й�����ֵң��ID
	virtual int GetBckPID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��޹�����ֵң��ID
	virtual int GetBckQID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ�����й�����ң��ID
	virtual int GetMaxPID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ�����޹�����ң��ID
	virtual int GetMaxQID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���С�й�����ң��ID
	virtual int GetMinPID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���С�޹�����ң��ID
	virtual int GetMinQID(int pos) = 0;

	//���ݷ������Ⱥλ�õõ�Զ���͵�ѹ��ID
	virtual int GetFarFlagID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��й�����ѹ��ID
	virtual int GetPFlagID(int pos) = 0;  
	//���ݷ������Ⱥλ�õõ��޹�����ѹ��ID
	virtual int GetQFlagID(int pos) = 0;  
	//���ݷ������Ⱥλ�õõ������й�ң��ID
	virtual int GetIncPID(int pos) = 0;   
	//���ݷ������Ⱥλ�õõ������޹�ң��ID
	virtual int GetIncQID(int pos) = 0;   
	//���ݷ������Ⱥλ�õõ��ɼ��й�ң��ID
	virtual int GetDecPID(int pos) = 0;   
	//���ݷ������Ⱥλ�õõ��ɼ��޹�ң��ID
	virtual int GetDecQID(int pos) = 0;   
	//���ݷ������Ⱥλ�õõ���̬�����޹�ң��ID
	virtual int GetDyIncQID(int pos) = 0; 
	//���ݷ������Ⱥλ�õõ���̬�ɼ��޹�ң��ID
	virtual int GetDyDecQID(int pos) = 0; 
	//���ݷ������Ⱥλ�õõ���������ID
	virtual int GetRunCapID(int pos) = 0; 
	//���ݷ������Ⱥλ�õõ��й��ɵ�����ID
	virtual int GetCtrlCapID(int pos) = 0;

	//���ݷ������Ⱥλ�õõ�����������
	virtual bool DispatchPIsOutput(int pos) = 0;
	//���ݷ������Ⱥλ�õõ����ʵ�λ
	virtual bool DispatchPInMW(int pos) = 0;

	//���ݷ������Ⱥλ�õõ�����ͨ����ͨ״̬
	virtual int GetSrcConnectState(int pos) = 0;
	//���ݷ������Ⱥλ����������ͨ����ͨ״̬
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;

	//���ݷ������Ⱥλ�õõ���ǰ��ѹ����ֵ
	virtual double GetRateVoltage(int pos) = 0;
	//���ݷ������Ⱥλ�����õ�ǰ��ѹ����ֵ
	virtual double SetRateVoltage(int pos, double dRateVolt) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��ѹ����ֵ
	virtual double GetRealVoltage(int pos) = 0;


	//���ݷ������Ⱥλ�õõ����Ƽƻ��й�����
	virtual double GetPlanP(int pos) = 0;
	//���ݷ������Ⱥλ�����ÿ��Ƽƻ��й�����
	virtual bool SetPlanP(int pos, double planP) = 0;
	//���ݷ������Ⱥλ�õõ����Ƽƻ��޹�����
	virtual double GetPlanQ(int pos) = 0;
	//���ݷ������Ⱥλ�����ÿ��Ƽƻ��޹�����
	virtual bool SetPlanQ(int pos, double planQ) = 0;

	//���ݷ������Ⱥλ�õõ���ǰ�й�����
	virtual double GetCurP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�޹�����
	virtual double GetCurQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�й�����ֵ
	virtual double GetBackP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�޹�����ֵ
	virtual double GetBackQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ����й�����
	virtual double GetMaxP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ����޹�����
	virtual double GetMaxQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��С�й�����
	virtual double GetMinP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��С�޹�����
	virtual double GetMinQ(int pos) = 0;

	//���ݷ������Ⱥλ�õõ���ǰԶ���͵�ѹ��
	virtual int GetFarFlag(int pos) = 0;
	//���ݷ������Ⱥλ�õõ�����й����ʵ��ڵ�ʹ��ѹ��
	virtual int GetPCtrlFlag(int pos) = 0;
	//���ݷ������Ⱥλ�õõ�����޹����ʵ��ڵ�ʹ��ѹ��
	virtual int GetQCtrlFlag(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�����й�����
	virtual double GetCanIncP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�����޹�����
	virtual double GetCanIncQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�ɼ��й�����
	virtual double GetCanDecP(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�ɼ��޹�����
	virtual double GetCanDecQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��̬�����޹�����
	virtual double GetCanIncDynQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��̬�ɼ��޹�����
	virtual double GetCanDecDynQ(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ��������
	virtual double GetCapacity(int pos) = 0;
	//���ݷ������Ⱥλ�õõ���ǰ�й��ɵ�����
	virtual double GetAdjPwrCapa(int pos) = 0;

	//���ݷ������Ⱥλ�õõ��ϴ��й�����ʱ��
	virtual double GetPCtrlTime(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��ϴ��޹�����ʱ��
	virtual double GetQCtrlTime(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��ϴ��й�ʧ�ܱ���ʱ��
	virtual double GetPLockTime(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��ϴ��޹�ʧ�ܱ���ʱ��
	virtual double GetQLockTime(int pos) = 0;

	//���ݷ������Ⱥλ�������ϴ��й�����ʱ��
	virtual bool SetPCtrlTime(int pos, double dPCtrlTime) = 0;
	//���ݷ������Ⱥλ�������ϴ��޹�����ʱ��
	virtual bool SetQCtrlTime(int pos, double dQCtrlTime) = 0;
	//���ݷ������Ⱥλ�������ϴ��й�ʧ�ܱ���ʱ��
	virtual bool SetPLockTime(int pos, double dPLockTime) = 0;
	//���ݷ������Ⱥλ�������ϴ��޹�ʧ�ܱ���ʱ��
	virtual bool SetQLockTime(int pos, double dQLockTime) = 0;

	//������е�������ʧ�ܴ���
	virtual void ClearAllFailTimes() = 0;
	//�����΢���ڷ�����ĵ�������ʧ�ܴ���
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;
	//���ݷ������Ⱥλ�ó�ʼ����������ʧ�ܴ�����actType��0--�й���1--�޹���2--ȫ��
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//���ݷ������Ⱥλ�����ӵ�������ʧ�ܴ�����actType��0--�й���1--�޹�
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//���ݷ������Ⱥλ�õõ���������ʧ�ܴ�����actType��0--�й���1--�޹�
	virtual int GetAdjustFailTimes(int pos, int actType) = 0;
	//���ݷ������Ⱥλ���ж��Ƿ�ɵ��ڡ�actType��0--�����й���1--�����޹���2--ȫ��
	virtual bool CanAdjust(int pos, int actType) = 0;


	//���ݷ������Ⱥλ�ø���������Ϣ
	virtual void UpdateRunInfo(int pos) = 0;
	//���ݷ������Ⱥλ���ж��Ƿ����������ʵ�����״̬
	virtual bool IsMaxPowerRunState(int pos) = 0;

	//���ݷ������Ⱥλ���ж��Ƿ�ɵ����й�����
	virtual bool CanAdjustP(int pos) = 0;
	//���ݷ������Ⱥλ���ж��Ƿ�ɵ����޹�����
	virtual bool CanAdjustQ(int pos) = 0;

	//���ݷ������Ⱥλ���ж��Ƿ�����ӷ�������й�������
	//������maxP--�����ʵ���ܴﵽ������й�������incP--������ɵ������ӵ��й�������
	virtual bool CanIncreasePValue(int pos, double& maxP, double& incP) = 0;
	//���ݷ������Ⱥλ���ж��Ƿ�ɵ��ڷ�������޹�������
	//������minQ--���������С�޹�������maxQ--�����������޹�������curQ--������ĵ�ǰ�޹�������
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;

	//���ݷ������Ⱥλ�õõ��й�ң��ID
	virtual int GetPCtrlID(int pos) = 0;
	//���ݷ������Ⱥλ�õõ��޹�ң��ID
	virtual int GetQCtrlID(int pos) = 0;

};

#endif
