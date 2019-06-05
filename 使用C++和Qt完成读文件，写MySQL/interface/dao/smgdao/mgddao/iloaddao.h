//iloaddao.h

#ifndef _ILOADDAO_PENGSHIKANG_20100323_H_
#define _ILOADDAO_PENGSHIKANG_20100323_H_

#include "imgddao.h"                             // for IMgdDao

#define LOADDAO_CLASSID    "cloaddao"
#define LOADDAO_INTFID     "iloaddao"

class ILoadDao : virtual public IMgdDao
{
public:
	//���ݸ���λ�õõ��������ȼ�
	virtual int GetPriority(int pos) = 0;

	//���ݸ���λ�õõ���ͣ�����
	virtual int GetCutTimes(int pos) = 0;
	//���ݸ���λ�����ӱ�ͣ�����
	virtual bool IncreaseCutTimes(int pos, double cutTime) = 0;

	//���ݸ���λ�õõ��ϴ�ͣ��ʱ��
	virtual double GetLastCutTime(int pos) = 0;
	//���ݸ���λ�������ϴ�ͣ��ʱ��
	virtual bool SetLastCutTime(int pos, double cutTime) = 0;

	//������е�������ʧ�ܴ���
	virtual void ClearAllFailTimes() = 0;
	//�����΢���ڸ��ɵĵ�������ʧ�ܴ���
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;
	//��ʼ����������ʧ�ܴ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//���ݸ���λ�����Ӷ�������ʧ�ܴ�����actType��0--�˳���1--Ͷ��
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//���ݸ���λ�õõ���������ʧ�ܴ���
	virtual int GetActFailTimes(int pos) = 0;
	//�ж�ָ��λ�õĸ����Ƿ�ɶ�����actType��0--�˳���1--Ͷ�룻2--ȫ��
	virtual int CanAct(int pos, int actType, int& cutCtrlId, int& addCtrlId) = 0;

	//�ж�ָ��λ�õĸ����Ƿ��ɲ����Զ��ж�
	virtual bool GetAutoCutFlag(int pos) = 0;
	//����ָ��λ�õĸ����Ƿ��ɲ����Զ��ж�
	virtual bool SetAutoCutFlag(int pos, bool autoCut=true) = 0;
	//���ݸ���λ�õõ����������������
	virtual double GetStartImpactRatio(int pos) = 0;

	//�ж�ָ��λ�õĸ����Ƿ��˹�������Ͷ�����
	virtual bool ManuLockAdd(int pos, int& ctrlId) = 0;
	//�ж�ָ��λ�õĸ����Ƿ��˹��������г�����
	virtual bool ManuLockCut(int pos, int& ctrlId) = 0;

	//��ָ��λ�õĸ���ִ���˹������Զ�Ͷ�����
	virtual bool DoManuLockAdd(int pos) = 0;

};

#endif
