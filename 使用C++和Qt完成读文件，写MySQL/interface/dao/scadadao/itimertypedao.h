//itimertypedao.h

#ifndef _ITIMERTYPEDAO_PENGSHIKANG_20101012_H_
#define _ITIMERTYPEDAO_PENGSHIKANG_20101012_H_

#include "../ibasicdao.h"                        // for IBasicDao
//Added by qt3to4:
#include <Q3ValueList>

#define TIMERTYPEDAO_CLASSID    "ctimertypedao"
#define TIMERTYPEDAO_INTFID     "itimertypedao"

class ITimerTypeDao : virtual public IBasicDao
{
public:
	//根据定时器类型位置得到计算周期类型
	virtual void GetCycleType(int pos, int& mode, int& span) = 0;
	//根据定时器类型位置得到计算起始时间
	virtual double GetStartTime(int pos) = 0;

	//根据定时器类型位置得到初始计算时间
	virtual double GetInitCalTime(int pos) = 0;
	//得到目前该计算的定时器类型
	virtual void GetTimeoutType(double* pCalTime, Q3ValueList<int>& typeList) = 0;  
};

#endif
