//ivoltagedao.h

#ifndef _IVOLTAGEGRADEDAO_PENGSHIKANG_20120601_H_
#define _IVOLTAGEGRADEDAO_PENGSHIKANG_20120601_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define VOLTAGEDAO_CLASSID    "cvoltagedao"
#define VOLTAGEDAO_INTFID     "ivoltagedao"

class IVoltageDao : virtual public IBasicDao
{
public:
	//根据电压等级ID得到额定电压(kV)
	virtual double GetRateVoltage(int id) = 0;
	//根据电压等级ID得到合格电压上限
	virtual double GetUpperVoltage(int id) = 0;
	//根据电压等级ID得到合格电压下限
	virtual double GetLowerVoltage(int id) = 0;
	//根据电压等级ID得到紧急电压上限
	virtual double GetUUpperVoltage(int id) = 0;
	//根据电压等级ID得到紧急电压下限
	virtual double GetLLowerVoltage(int id) = 0;
	//根据电压等级ID得到电压失压门槛值
	virtual double GetZeroVoltageThreshold(int id) = 0;
	//根据电压等级ID判断指定电压值是否位于合格区内。
	// 返回值：0 --合格；-1 --越合格下限；1 --越合格上限；
	//  -2 --越紧急下限； 2 --越紧急上限；-3 -- 失压。
	virtual int IsNormalVoltage(int id, double dCurU) = 0;
	//根据电压等级ID得到电压值是否以“kV”为单位计算
	virtual bool IsKVUnit(int id) = 0;
};

#endif
