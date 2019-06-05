//icheckonlineupdate.h

#ifndef _ICHECKONLINEUPDATE_PENGSHIKANG_20101011_H_
#define _ICHECKONLINEUPDATE_PENGSHIKANG_20101011_H_

enum WRITERTDBSTATE
{
	CANWRITERTDB, NEEDREAD, NEEDUPDATE, CANUPDATE,
};

class ICheckOnlineUpdate
{
public:
	//����д���ݿ���״̬
	virtual void SetWriteState(WRITERTDBSTATE bCanWrite) = 0;
	//�õ�д���ݿ���״̬
	virtual WRITERTDBSTATE GetWriteState() = 0;
	//�����Ƿ���д���ݿ��
	virtual bool CanWrite() = 0;
	//�����Ƿ���д���ݿ��
	//static bool CannotWrite();
	
	//�������ݿ����߸����¼������������ݿ����̴߳���
	virtual void LockProcess(const char* sType) = 0;
	virtual bool TryLockProcess() = 0;
	//�������ݿ����߸����¼������������ݿ����̴߳���
	virtual void UnlockProcess(bool bLog=true) = 0;
	//�������ݿ����߸����¼��ȴ��������ڷ������ݿ����̴߳������
	virtual void WaitUntilProcessesFinish() = 0;

	//��ʼ�������ݿ��ľ�̬��Ϣ
	virtual void StartLoadRtdb() = 0;
	//ֹͣ�������ݿ��ľ�̬��Ϣ
	virtual void StopLoadRtdb() = 0;
	//���ڵȴ�״̬��ֱ��ֹͣ�������ݿ��̬��ϢΪֹ
	virtual void WaitUntilStopLoadRtdb() = 0;

	//׼�����߸��µ����ݿ�����Ƽ���
	virtual bool PrepareUpdateTableSet(const char* insertTables, const char* editTables) = 0;
	//�������߸��µ����ݿ�����Ƽ���
	virtual void CreateUpdateTableSet() = 0;
	//�Ƿ�������߸��µ����ݿ����
	virtual bool HasUpdateTableSet() = 0;
	//ָ�������ݿ�������Ƿ���Ҫ���߸���
	virtual bool UpdatedTable(const char* curTable) = 0;
	//�ͷ����߸��µ����ݿ�����Ƽ���
	virtual void FreeUpdateTableSet() = 0;
};

#endif
