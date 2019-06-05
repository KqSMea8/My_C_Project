//ibaydao.h

#ifndef _IBAYDAO_PENGSHIKANG_20130310_H_
#define _IBAYDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BAYDAO_CLASSID    "cbaydao"
#define BAYDAO_INTFID     "ibaydao"

class IBayDao : virtual public IBasicDao
{
public:
	//根据间隔量位置得到厂站ID
	virtual int GetStationId(int pos) = 0;
	//根据间隔位置得到描述
	virtual const char* GetDescription(int pos) = 0;

	//根据间隔位置得到运行状态
	virtual int GetState(int nPos) = 0;
	//根据间隔位置设置运行状态
	virtual bool SetState(int pos, int nValue) = 0;
	//根据间隔位置得到光字状态
	virtual int GetGZState(int pos) = 0;
	//根据间隔位置设置光字状态
	virtual bool SetGZState(int pos, int nValue) = 0;
	//根据间隔位置得到闭锁标志
	virtual int GetLockFlag(int nPos) = 0;
	//根据间隔位置设置闭锁标志
	virtual bool SetLockFlag(int pos, int lockFlag) = 0;
	//根据间隔位置得到主间隔ID [用于旁路替换]
	virtual int GetBossBayId(int nPos) = 0;
	//根据间隔位置设置主间隔ID [用于旁路替换]
	virtual int SetBossBayId(int nPos, int bossId) = 0;

	virtual int GetFaultAttr(int nPos) = 0;
	virtual bool SetFaultAttr(int nPos, int nFault) = 0;
	virtual bool UnflickerFaultAttr(int nPos) = 0;

	virtual int GetAlarmAttr(int nPos) = 0;
	virtual bool SetAlarmAttr(int nPos, int nAlarm) = 0;
	virtual bool UnflickerAlarmAttr(int nPos) = 0;
};

#endif
