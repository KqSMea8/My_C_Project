//istorcurvedao.h

#ifndef _ISTORAGEPOWERCURVEDAO_PENGSHIKANG_20101103_H_
#define _ISTORAGEPOWERCURVEDAO_PENGSHIKANG_20101103_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define STORCURVEDAO_CLASSID    "cstorcurvedao"
#define STORCURVEDAO_INTFID     "istorcurvedao"

class IStorCurveDao : virtual public IBasicDao
{
public:
	//根据储能放电功率曲线位置得到曲线计划ID
	virtual int GetCurvePlanID(int pos) = 0;
	
	//根据储能放电功率曲线位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;

	//根据储能放电功率曲线位置得到时间范围
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//根据储能放电功率曲线位置读取储能放电功率值
	virtual double GetCurvePlanPower(int pos) = 0;

	//根据曲线计划ID和当前时间读取储能放电功率值，返回储能放电功率曲线位置。
	virtual int GetCurvePlanPowerByMinutes(int planId, int time, double& power) = 0;

	//根据储能放电功率曲线位置读取储能充放电目标类型
	/*
	0：固定值充放电。
	1：吸收多余发电：如果发电大于用电，储能充电，充电能力不足时不限制发电；如果用电大于发电，储能不放电。
	2：自发自用：如果发电大于用电，储能充电，充电能力不足时不限制发电；如果用电大于发电，储能放电，放电能力不足时不限制用电。
	*/
	virtual int GetCurvePlanAimType(int pos) = 0;
	
};

#endif
