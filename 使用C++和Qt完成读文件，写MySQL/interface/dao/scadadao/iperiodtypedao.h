//iperiodtypedao.h

#ifndef _IPERIODTYPEDAO_PENGSHIKANG_20130328_H_
#define _IPERIODTYPEDAO_PENGSHIKANG_20130328_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define PERIODTYPEDAO_CLASSID     "cperiodtypedao"
#define PERIODTYPEDAO_INTFID      "iperiodtypedao"

class IPeriodTypeDao : virtual public IBasicDao
{
public:
	//根据时段类型ID得到上网电价和下网电价
	virtual bool GetPriceById(int id, double& genPrice, double& usePrice) = 0;

	//根据时段类型位置得到上网电价(生产电价)
	virtual double GetGenPrice(int pos) = 0;
	//根据时段类型位置得到下网电价(使用电价)
	virtual double GetUsePrice(int pos) = 0;

	//得到最高下网电价的时段(尖峰时段)类型ID
	virtual int GetPeakPrdTypID() = 0;
	//得到最低下网电价的时段(尖谷时段)类型ID
	virtual int GetHollowPrdTypID() = 0;
};

#endif
