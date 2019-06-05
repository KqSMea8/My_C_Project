//iperioddao.h

#ifndef _IPERIODDAO_PENGSHIKANG_20130328_H_
#define _IPERIODDAO_PENGSHIKANG_20130328_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODDAO_CLASSID     "cperioddao"
#define PERIODDAO_INTFID      "iperioddao"

class IPeriodDao : virtual public IBasicDao
{
public:
	/* 根据时间得到时分秒对应的秒数 */
	static int GetSecondsByTime(double dTime)
	{
		return (int)((dTime - int(dTime)) * 86400.0 + 0.5);
	}

	/* 根据日期值和秒数得到时间 */
	static double GetTimeBySeconds(double dayTime, int secCount)
	{
		return (double)(int(dayTime) + secCount / 86400.0);
	}

	//根据时段位置得到起止时间
	virtual void GetTimes(int pos, double& beginTime, double& endTime) = 0;

	//根据时段位置得到开始时间
	virtual double GetBeginTime(int pos) = 0;
	//根据时段位置得到结束时间
	virtual double GetEndTime(int pos) = 0;

	//根据时间得到所属的时段类型ID
	virtual int GetPeriodTypeID(double dTime, int* beginSeconds=0, int* endSeconds=0) = 0;

};

#endif
