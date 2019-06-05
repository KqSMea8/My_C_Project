//iacurvelmtdao.h

#ifndef _IACURVELMTDAO_PENGSHIKANG_20130310_H_
#define _IACURVELMTDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define ACURVELMTDAO_CLASSID    "cacurvelmtdao"
#define ACURVELMTDAO_INTFID     "iacurvelmtdao"

class IACurveLmtDao : virtual public IBasicDao
{
public:
	//根据模拟量曲线越限类型位置读取模拟量越限类型ID
	virtual int GetLimitType(int pos) = 0;
	
	//根据模拟量曲线越限类型位置得到时间范围
	virtual void GetTimeRange(int pos, double& startTime, double& endTime) = 0;
	
	//根据模拟量曲线越限类型位置得到报警限值
	virtual void GetLimitValues(int pos, double& upperVal, double& lowerVal) = 0;

	//根据模拟量曲线越限类型位置读取上限报警值
	virtual double GetUpperValue(int pos) = 0;

	//根据模拟量曲线越限类型位置读取下限报警值
	virtual double GetLowerValue(int pos) = 0;
};

#endif
