//ireactcompdao.h

#ifndef _IREACTIVECOMPOMENTDAO_PENGSHIKANG_20120511_H_
#define _IREACTIVECOMPOMENTDAO_PENGSHIKANG_20120511_H_

#include "imgddao.h"                             // for IMgdDao
#include "../../../icsvalue.h"                   // for intarray

#define REACTIVECOMPOMENTDAO_CLASSID    "creactcompdao"
#define REACTIVECOMPOMENTDAO_INTFID     "ireactcompdao"

class IReactCompDao : virtual public IMgdDao
{
public:
	//��ָ��λ�õ��޹������豸�������ɵ����޹������豸������
	virtual void AddObjectIntoMaxQList(int pos, double power, intarray& list) = 0;
	
	//�����޹������豸λ�õõ������豸����
	virtual int GetCompType(int pos) = 0;
	//�����޹������豸λ�õõ�����޹�����
	virtual double GetMaxQ(int pos) = 0;
	//�����޹������豸λ�õõ���С�����޹�����
	virtual double GetMinCtrlQ(int pos) = 0;
	//�����޹������豸λ�õõ�����޹����ʵĵ��ڱ�־
	virtual int GetQCtrlFlag(int pos) = 0;
	//�����޹������豸λ�õõ������翹��
	virtual double GetReactiveRate(int pos) = 0;
	
	//�����޹������豸λ�õõ�Ͷ���ж���ʱ����
	virtual int GetMinQuitTimeSpan(int pos) = 0;
	//�����޹������豸λ�õõ��е�Ͷ����ʱ����
	virtual int GetMinJoinTimeSpan(int pos) = 0;
	
	//�����޹������豸λ�õõ����һ�ζ���ʱ��
	virtual double GetRecentActTime(int pos) = 0;
	//���ݷ����λ���������һ�ζ���ʱ��
	virtual bool SetRecentActTime(int pos, double actTime) = 0;
	//�����޹������豸λ�õõ��ն�������
	virtual int GetActTimesOfToday(int pos) = 0;
	//�����޹������豸λ�������ն�������
	virtual bool IncreaseActTimesOfToday(int pos) = 0;
	
	//������е�������ʧ�ܴ���
	virtual void ClearAllFailTimes() = 0;
	//�����΢�����޹������豸�ĵ�������ʧ�ܴ���
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//�����޹������豸λ�ó�ʼ����������ʧ�ܴ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//�����޹������豸λ�����Ӷ�������ʧ�ܴ�����actType��0--�˳���1--Ͷ��
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//�����޹������豸λ�õõ���������ʧ�ܴ���
	virtual int GetActFailTimes(int pos) = 0;
	//�����޹������豸λ���ж��Ƿ�ɶ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual int CanAct(int pos, int actType, int& cutCtrlId, int& addCtrlId) = 0;

	//�����޹������豸λ�ó�ʼ����������ʧ�ܴ�����
	virtual bool InitAdjustFailTimes(int pos) = 0;
	//�����޹������豸λ�����ӵ�������ʧ�ܴ�����
	virtual bool IncreaseAdjustFailTimes(int pos) = 0;
	//�����޹������豸λ�õõ���������ʧ�ܴ���
	virtual int GetAdjustFailTimes(int pos) = 0;
	//�����޹������豸λ���ж��Ƿ�ɵ����޹����ʡ�
	virtual bool CanAdjust(int pos) = 0;
	
	//�����޹������豸λ�õõ��ɲ����Զ��г���־
	virtual bool GetAutoCutFlag(int pos) = 0;
	//�����޹������豸λ�������ɲ����Զ��г���־
	virtual bool SetAutoCutFlag(int pos, bool bCut) = 0;

	//�����޹������豸λ�õõ���ֵ����
	virtual double GetZeroValueLmt(int pos) = 0;
	//�����޹������豸λ�õõ��޹�ң�������ȹ���ֵ
	virtual double GetSensitivityQ(int pos) = 0;
	//�����޹������豸λ�õõ����ϸ��������ID
	virtual int GetRevertCtrlId(int pos) = 0;
	//�����޹������豸λ�õõ�SVG��ͣ״̬ID
	virtual int GetRunStateID(int pos) = 0;
	//�����޹������豸λ�õõ���ǰSVG��ͣ״̬
	virtual int GetCurRunState(int pos) = 0;
	//�����޹������豸λ�����õ�ǰSVG��ͣ״̬
	virtual bool SetCurRunState(int pos, int runState) = 0;
	//�����޹������豸λ�ø���������Ϣ
	virtual void UpdateRunInfo(int pos, bool& canCtrl) = 0;
	//�����޹������豸λ���жϵ�ǰ�����Ƿ�����
	virtual bool IsStarted(int pos) = 0;

	//�ж�ָ��λ�õ��޹������豸�Ƿ��˹�������Ͷ�����
	virtual bool ManuLockAdd(int pos, int& ctrlId) = 0;
	//�ж�ָ��λ�õ��޹������豸�Ƿ��˹��������г�����
	virtual bool ManuLockCut(int pos, int& ctrlId) = 0;

	//�ж�ָ��λ�õ��޹������豸����������ʱ���Ƿ�ﵽҪ��
	virtual bool CheckRunTimeSpan(int pos, double curTime) = 0;
	//�ж�ָ��λ�õ��޹������豸������ͣ��ʱ���Ƿ�ﵽҪ��
	virtual bool CheckStopTimeSpan(int pos, double curTime) = 0;
	//�����޹������豸λ�õõ��ն���������
	virtual int GetMaxActTimesOfADay(int pos) = 0;

	//�����޹������豸λ�õõ���ǰλ�õõ�����ģʽ״̬ID
	virtual int GetModeStateID(int pos) = 0;
	//�����޹������豸λ�õõ���ǰVF����ģʽ��//12--ST_MOD_VF��VFģʽ��13--ST_MOD_PQ��PQģʽ��
	virtual int GetCurVFModStat(int pos) = 0;
	//�����޹������豸λ�����õ�ǰVF����ģʽ��//12--ST_MOD_VF��VFģʽ��13--ST_MOD_PQ��PQģʽ��
	virtual bool SetCurVFModStat(int pos, int mode) = 0;

	//�����޹������豸λ���ж��Ƿ�ɵ����޹�����
	virtual bool CanAdjustQ(int pos) = 0;
	//�����޹������豸λ���ж��Ƿ�ɵ����޹������豸�ĳ�����
	//������maxQ--�޲��豸����С������maxQ--�޲��豸����������curQ--�޲��豸�ĵ�ǰ������
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;
	//�����޹������豸λ�õõ�VFģʽ����ID
	virtual int GetVFmodeCtrlId(int pos) = 0;

	//�����޹������豸λ�û�ȡSVG���ȶ��޹����������Ӧ��ʱ��
	virtual bool GetBaseValueAndTime(int pos, double& baseValue, double& baseTime) = 0;
	//�����޹������豸λ������SVG���ȶ��޹����������Ӧ��ʱ��
	virtual bool SetBaseValueAndTime(int pos, double baseValue, double baseTime) = 0;

};

#endif
