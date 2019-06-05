//iperiodtype.h
#ifndef _IPERIODTYPE_PENGSHIKANG_20080711_H_
#define _IPERIODTYPE_PENGSHIKANG_20080711_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODTYPE_CLASSID    "cperiodtype"
#define PERIODTYPE_INTFID     "iperiodtype"

class IPeriodType : virtual public IBasicDao
{
public:
	//创建时段类型对象集
	virtual void CreatePeriodTypes() = 0;

	//得到时段类型个数
	virtual int GetPeriodTypeCount() = 0;
	
	//得到全部的时段类型ID
	virtual bool GetAllPeriodTypeID(int pPeriodIDs[]) = 0;
	
    //根据时间得到所属的时段类型ID
    virtual int GetPeriodTypeID(double dTime, int& beginTime, int& endTime) = 0;

	//根据时段类型ID得到上网电价和下网电价
	virtual bool GetPriceByPrdTypID(int typeId, float& genPrice, float& usePrice) = 0;
	//得到最高下网电价的时段（尖峰时段）类型ID
    virtual int GetPeakPrdTypID() = 0;
	//得到最低下网电价的时段（尖谷时段）类型ID
    virtual int GetHollowPrdTypID() = 0;
};

#endif
