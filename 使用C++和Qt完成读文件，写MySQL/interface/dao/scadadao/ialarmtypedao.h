//ialarmtypedao.h

#ifndef _IALARMTYPEDAO_PENGSHIKANG_20130310_H_
#define _IALARMTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ALMTYPDAO_CLASSID    "calmtypdao"
#define ALMTYPDAO_INTFID     "ialmtypdao"

class IAlmTypDao : virtual public IBasicDao
{
public:
	//根据越限报警类型位置读取是否是百分比
	virtual int IsPercentum(int pos) = 0;

	//根据越限报警类型位置读取时段类型标志
	virtual int GetPeroidFlag(int pos) = 0;

	//根据越限报警类型位置读取越限恢复死区
	virtual double GetDeadZone(int pos) = 0;

	//根据越限报警类型位置读取报警延迟时间
	virtual int GetAlarmDelayTime(int pos) = 0;

	//根据越限报警类型位置读取越限类型基值
	virtual double GetBaseValue(int pos) = 0;

	//根据越限报警类型位置读取上限报警值
	virtual double GetUpperValue(int pos) = 0;

	//根据越限报警类型位置读取下限报警值
	virtual double GetLowerValue(int pos) = 0;

	//根据越限报警类型位置读取上上限报警值
	virtual double GetUUpperValue(int pos) = 0;

	//根据越限报警类型位置读取下下限报警值
	virtual double GetLLowerValue(int pos) = 0;

	//根据越限报警类型位置读取越上下限是否是事故
	virtual int IsFaultUL(int pos) = 0;

	//根据越限报警类型位置读取越上上下下限是否是事故
	virtual int IsFaultUL2(int pos) = 0;

	//根据越限报警类型位置读取越上限动作掩码
	virtual int GetUpperAct(int pos) = 0;

	//根据越限报警类型位置读取越下限动作掩码
	virtual int GetLowerAct(int pos) = 0;

	//根据越限报警类型位置读取越上上限动作掩码
	virtual int GetUUpperAct(int pos) = 0;

	//根据越限报警类型位置读取越下下限动作掩码
	virtual int GetLLowerAct(int pos) = 0;
};

#endif
