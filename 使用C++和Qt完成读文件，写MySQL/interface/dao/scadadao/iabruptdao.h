//iabruptdao.h

#ifndef _IABRUPTDAO_PENGSHIKANG_20081201_H_
#define _IABRUPTDAO_PENGSHIKANG_20081201_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ABRUPTDAO_CLASSID    "cabruptdao"
#define ABRUPTDAO_INTFID     "iabruptdao"

class IAbruptDao : virtual public IBasicDao
{
public:
	//根据跳变报警类型位置读取是否是变化率
	virtual int IsDiff(int pos) = 0;
	//根据跳变报警类型位置读取变化方向
	virtual int GetTrend(int pos) = 0;
	//根据跳变报警类型位置读取变化门槛值
	virtual double GetGradeValue(int pos) = 0;
	//根据跳变报警类型位置读取跳变确认时间门槛
	virtual int GetQualtyTimeLmt(int pos) = 0;
	//根据跳变报警类型位置读取跳变报警延迟时间
	virtual int GetAlarmTimeLmt(int pos) = 0;
	//根据跳变报警类型位置读取是否为事故跳变
	virtual int IsFault(int pos) = 0;
	//根据跳变报警类型位置读取跳变报警动作掩码
	virtual int GetAbruptAct(int pos) = 0;
};

#endif
