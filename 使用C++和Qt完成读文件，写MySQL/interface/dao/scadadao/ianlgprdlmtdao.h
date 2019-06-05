//ianlgprdlmtdao.h

#ifndef _IANALOGPEROIDLIMITDAO_PENGSHIKANG_20130310_H_
#define _IANALOGPEROIDLIMITDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define APRDLMTDAO_CLASSID    "caprdlmtdao"
#define APRDLMTDAO_INTFID     "iaprdlmtdao"

class IAPrdLmtDao : virtual public IBasicDao
{
public:
	//根据模拟量越限类型ID和时段类型ID得到模拟量时段越限类型位置
	virtual int GetPositionByID(int nALmtTyp, int nPrdTyp) = 0;

	//根据模拟量时段越限类型位置读取上限报警值
	virtual double GetUpperValue(int pos) = 0;
	//根据模拟量时段越限类型位置读取下限报警值
	virtual double GetLowerValue(int pos) = 0;	
};

#endif
