//ibaydao.h

#ifndef _IBAYDAO_PENGSHIKANG_20130310_H_
#define _IBAYDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BAYDAO_CLASSID    "cbaydao"
#define BAYDAO_INTFID     "ibaydao"

class IBayDao : virtual public IBasicDao
{
public:
	//���ݼ����λ�õõ���վID
	virtual int GetStationId(int pos) = 0;
	//���ݼ��λ�õõ�����
	virtual const char* GetDescription(int pos) = 0;

	//���ݼ��λ�õõ�����״̬
	virtual int GetState(int nPos) = 0;
	//���ݼ��λ����������״̬
	virtual bool SetState(int pos, int nValue) = 0;
	//���ݼ��λ�õõ�����״̬
	virtual int GetGZState(int pos) = 0;
	//���ݼ��λ�����ù���״̬
	virtual bool SetGZState(int pos, int nValue) = 0;
	//���ݼ��λ�õõ�������־
	virtual int GetLockFlag(int nPos) = 0;
	//���ݼ��λ�����ñ�����־
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;
	//���ݼ��λ�õõ������ID [������·�滻]
	virtual int GetBossBayId(int nPos) = 0;
	//���ݼ��λ�����������ID [������·�滻]
	virtual int SetBossBayId(int nPos, int bossId) = 0;

	virtual int GetFaultAttr(int nPos) = 0;
	virtual bool SetFaultAttr(int nPos, int nFault) = 0;
	virtual bool UnflickerFaultAttr(int nPos) = 0;

	virtual int GetAlarmAttr(int nPos) = 0;
	virtual bool SetAlarmAttr(int nPos, int nAlarm) = 0;
	virtual bool UnflickerAlarmAttr(int nPos) = 0;
};

#endif
