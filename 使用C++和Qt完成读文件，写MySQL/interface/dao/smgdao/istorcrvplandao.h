//istorcrvplandao.h

#ifndef _ISTORAGECURVEPLANDAO_PENGSHIKANG_20110314_H_
#define _ISTORAGECURVEPLANDAO_PENGSHIKANG_20110314_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STORCURVEPLANDAO_CLASSID    "cstorcurveplandao"
#define STORCURVEPLANDAO_INTFID     "istorcurveplandao"

class IStorCurvePlanDao : virtual public IBasicDao
{
public:
	//根据储能放电曲线计划位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;
	
	//根据储能放电曲线计划位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;

	//根据子微网ID得到有效的储能放电曲线计划ID
	virtual int GetEnableCurvePlanId(int mgId) = 0;
};

#endif
