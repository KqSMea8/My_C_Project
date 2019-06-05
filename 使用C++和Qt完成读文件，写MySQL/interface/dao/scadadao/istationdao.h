//istationdao.h

#ifndef _ISTATIONDAO_PENGSHIKANG_20081129_H_
#define _ISTATIONDAO_PENGSHIKANG_20081129_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STATIONDAO_CLASSID    "cstationdao"
#define STATIONDAO_INTFID     "istationdao"

class IStationDao : virtual public IBasicDao
{
public:
	//根据厂站位置得到厂站描述
	virtual const char* GetDescription(int pos) = 0;
	//根据厂站位置得到厂站RTU号
	virtual const char* GetRtuId(int pos) = 0;

	//根据厂站位置得到运行状态
	virtual int GetState(int nPos) = 0;
	//根据厂站位置设置运行状态
	virtual bool SetState(int nPos, int nValue) = 0;

	//根据厂站位置得到光字状态
	virtual int GetGZState(int pos) = 0;
	//根据厂站位置设置光字状态
	virtual bool SetGZState(int pos, int nValue) = 0;
	
	//根据厂站位置得到处理标志
	virtual int GetProFlag(int nPos) = 0;
	//根据厂站位置设置处理标志
	virtual bool SetProFlag(int nPos, int proFlag) = 0;

	//根据厂站位置得到闭锁标志
	virtual int GetLockFlag(int nPos) = 0;
	//根据厂站位置设置闭锁标志
	virtual bool SetLockFlag(int nPos, int lockFlag) = 0;

	//根据厂站位置得到五防模式
	virtual int GetWfMode(int nPos) = 0;
	//根据厂站位置设置五防模式
	virtual bool SetWfMode(int nPos, int wfMode) = 0;

	//根据厂站位置得到五防超时时间
	virtual int GetWfTime(int nPos) = 0;
	//根据厂站位置设置五防超时时间
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
