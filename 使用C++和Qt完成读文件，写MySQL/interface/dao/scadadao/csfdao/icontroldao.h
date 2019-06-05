//icontroldao.h

#ifndef _ICONTROLDAO_PENGSHIKANG_20100323_H_
#define _ICONTROLDAO_PENGSHIKANG_20100323_H_

#include "icsfdao.h"                              // for ICsfDao

#define CONTROLDAO_CLASSID    "ccontroldao"
#define CONTROLDAO_INTFID     "icontroldao"

class IControlDao : virtual public ICsfDao
{
public:
	//���ݿ�����λ�õõ����ƴ����־
	virtual int GetProcessFlag(int pos) = 0;
	//���ݿ�����λ�õõ���������
	virtual int GetCtrlType(int pos) = 0;
	//���ݿ�����λ�õõ�������ID
	virtual int GetCtrlGroupId(int pos) = 0;
	
	//���ݿ�����λ�õõ������������ʽ
	virtual const char* GetLockExpCal(int pos) = 0;
	
	//���ݹ����Ķ���ID�õ�������ID
	virtual int GetControlIdByRelationObject(int relatType, int objId) = 0;
	//���ݿ�����λ�õõ���������������
	virtual int GetRelationType(int pos) = 0;
	//���ݿ�����λ�õõ���������ID
	virtual int GetRelationObjectId(int pos) = 0;
	//���ݿ�����λ�õõ�������״̬��ID
	virtual int GetRelationStatusId(int pos) = 0;
	//���ݿ�����ID�õ�������״̬��ID
	virtual int GetRelationStatusIdByID(int id) = 0;
	
	//���ݿ�����λ�õõ������Ʋ�������
	virtual int GetMaxCtrlCount(int pos) = 0;

	//���ݿ�����λ�õõ�������ʱʱ��
	virtual int GetOprTimeLimit(int pos) = 0;

	//���ݿ�����λ�õõ����Ʋ�������
	virtual int GetCurCtrlCount(int pos) = 0;

	//���ݿ�����λ�õõ��������ң�ر�־
	virtual int GetWfFlag(int pos) = 0;
	//���ݿ�����λ�������������ң�ر�־
	virtual bool SetWfFlag(int pos, int wfFlag) = 0;
	
	//���ݿ�����λ�õõ����һ�γɹ�����ֵ
	virtual double GetLastControlValue(int pos) = 0;
	//���ݿ�����λ���������һ�γɹ�����ֵ
	virtual bool SetLastControlValue(int pos, double ctrlVal) = 0;
	
	//���ݿ�����λ�ü�¼���ο��Ʋ���
	virtual bool RecordCurCtrlCount(int pos, double oprTime) = 0;
	//���ݿ�����λ�ü�¼�ɹ��Ŀ��Ʋ���
	virtual bool RecordSucCtrlCount(int pos, double oprTime, double ctrlVal) = 0;
	
	//�õ�ָ���������п������ĸ���
	virtual int GetControlCountByGroupId(int groupId) = 0;
	//�õ�ָ���������п�����ID����
	virtual const int* GetControlIdSetByGroupId(int groupId) = 0;
	//�õ�ָ����������ָ��Ԫ�صĿ�����ID
	virtual int GetControlIdByGroupIndex(int groupId, int index) = 0;	

	//���ݿ�����λ���ж��Ƿ��˹���������  sunr add
	virtual bool IsManuLock(int pos) = 0;
	//����ǰ���ϴ���λ�������˹�����������־  sunr add
	virtual bool SetManuLockFlag(int pos, bool bManuLock) = 0;
	//���ݿ�����ID�ж��Ƿ��ڱ�����
	virtual bool InManuLockingById(int id) = 0;

	//���ݿ�����λ�õõ�ң��˫����
	virtual const char* GetDoubleCode(int pos) = 0;
	
	//���ݿ�����ID�õ����һ�ο���ʱ��
	virtual double GetLastControlTimeByID(int id) = 0;

	//���ݿ�����λ�õõ���ǰ����ֵ��Ӧң��[����ֵ]ID
	virtual int GetRealCtrlValueAnlgID(int pos) = 0;

	//���ݿ�����ID��¼���һ�ο���ʱ��
	virtual bool SetLastControlTimeByID(int id, double oprTime) = 0;

	//���ݿ�����λ�õõ����һ�γɹ�����ʱ��
	virtual double GetLastControlTime(int pos) = 0;
	//���ݿ�����λ�õõ����ճɹ����Ʋ�������
	virtual int GetTodaySucCtrlCount(int pos) = 0;

	//������һ�ο���ʱ��[����]
	virtual void ClearLastControlTime() = 0;
};

#endif
