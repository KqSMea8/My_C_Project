//istationdao.h

#ifndef _ISTATIONDAO_PENGSHIKANG_20081129_H_
#define _ISTATIONDAO_PENGSHIKANG_20081129_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STATIONDAO_CLASSID    "cstationdao"
#define STATIONDAO_INTFID     "istationdao"

class IStationDao : virtual public IBasicDao
{
public:
	//���ݳ�վλ�õõ���վ����
	virtual const char* GetDescription(int pos) = 0;
	//���ݳ�վλ�õõ���վRTU��
	virtual const char* GetRtuId(int pos) = 0;

	//���ݳ�վλ�õõ�����״̬
	virtual int GetState(int nPos) = 0;
	//���ݳ�վλ����������״̬
	virtual bool SetState(int nPos, int nValue) = 0;

	//���ݳ�վλ�õõ�����״̬
	virtual int GetGZState(int pos) = 0;
	//���ݳ�վλ�����ù���״̬
	virtual bool SetGZState(int pos, int nValue) = 0;
	
	//���ݳ�վλ�õõ������־
	virtual int GetProFlag(int nPos) = 0;
	//���ݳ�վλ�����ô����־
	virtual bool SetProFlag(int nPos, int proFlag) = 0;

	//���ݳ�վλ�õõ�������־
	virtual int GetLockFlag(int nPos) = 0;
	//���ݳ�վλ�����ñ�����־
	virtual bool SetLockFlag(int nPos, int lockFlag) = 0;

	//���ݳ�վλ�õõ����ģʽ
	virtual int GetWfMode(int nPos) = 0;
	//���ݳ�վλ���������ģʽ
	virtual bool SetWfMode(int nPos, int wfMode) = 0;

	//���ݳ�վλ�õõ������ʱʱ��
	virtual int GetWfTime(int nPos) = 0;
	//���ݳ�վλ�����������ʱʱ��
	virtual int SetWfTime(int nPos, int wfTime) = 0;
	
	//
	virtual int GetFaultAttr(int nPos) = 0;
	virtual bool SetFaultAttr(int nPos, int nFault) = 0;
	virtual bool UnflickerFaultAttr(int nPos) = 0;

	virtual int GetAlarmAttr(int nPos) = 0;
	virtual bool SetAlarmAttr(int nPos, int nAlarm) = 0;
	virtual bool UnflickerAlarmAttr(int nPos) = 0;
};

#endif
