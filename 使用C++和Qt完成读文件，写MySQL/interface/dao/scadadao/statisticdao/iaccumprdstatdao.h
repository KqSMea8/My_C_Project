//iaccumprdstatdao.h

#ifndef _IACCUMUPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _IACCUMUPROIDSTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "iperiodstatdao.h"                    // for IPeriodStatDao

#define ACCUMPRDSTATDAO_CLASSID    "caccumprdstatdao"
#define ACCUMPRDSTATDAO_INTFID     "iaccumprdstatdao"

class IAccumPrdStatDao : virtual public IPeriodStatDao
{
public:
	//设置累加量时段统计处理结果
	virtual bool SetAccumPrdStatValue(int objPos, double incValue, double curTime) = 0;
};

#endif
