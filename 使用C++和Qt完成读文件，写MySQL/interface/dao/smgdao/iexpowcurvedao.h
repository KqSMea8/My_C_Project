//iexpowcurvedao.h

#ifndef _IEXCHANGEPOWERCURVEDAO_PENGSHIKANG_20101025_H_
#define _IEXCHANGEPOWERCURVEDAO_PENGSHIKANG_20101025_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EXPOWCURVEDAO_CLASSID    "cexpowcurvedao"
#define EXPOWCURVEDAO_INTFID     "iexpowcurvedao"

class IExPowCurveDao : virtual public IBasicDao
{
public:
	//根据交换功率曲线位置得到曲线计划ID
	virtual int GetCurvePlanID(int pos) = 0;
	//根据交换功率曲线位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;
	//根据交换功率曲线位置得到时间范围
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;
	//根据交换功率曲线位置读取交换功率值
	virtual double GetCurvePlanPower(int pos) = 0;
	//根据子微网ID和当前时间读取交换功率值
	virtual int GetCurvePlanPower(int planId, int time, double& expow) = 0;	
	//根据交换功率曲线位置设置交换功率计划值
	virtual bool SetCurvePlanPower(int pos, double expow, int flag=0) = 0;

	//根据子微网ID和当前时间得到交换功率曲线位置
	virtual int GetPositionByTime(int planId, int time) = 0;
	//根据交换功率曲线位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据交换功率曲线位置读取统计存储标志
	virtual int GetSaveFlag(int pos) = 0;

	//根据交换功率曲线位置读取交换功率实际值
	virtual double GetCurveActualPower(int pos) = 0;
	//根据交换功率曲线位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据交换功率曲线位置设置交换功率实际值
	virtual bool SetCurveActualPower(int pos, double curPower, double curTime) = 0;

	//将数据表的动态信息写入库中[save]
	virtual void WriteDynamicInfo1() = 0;
};

#endif
