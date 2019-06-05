//istatusprdstisdao.h

#ifndef _ISTATUSPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _ISTATUSPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "iperiodstatdao.h"                    // for IPeriodStatDao

#define STTSPRDSTISDAO_CLASSID    "csttsprdstisdao"
#define STTSPRDSTISDAO_INTFID     "isttsprdstisdao"

class ISttsPrdStisDao : virtual public IPeriodStatDao
{
public:
	//设置状态量时段统计处理结果 [用于状态量数据统计处理线程]
	virtual bool SetSttsPrdStisValue(int nObjPos, bool isConnect, double curTime, double dSmpTime) = 0;
	
	//时段到时的状态量分时段统计 [用于时段到时统计线程]
	virtual void PeriodStatistics() = 0;
};

#endif
