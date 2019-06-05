//iavcplancurdao.h

#ifndef _IAVCPLANCURDAO_PENGSHIKANG_20150824_H_
#define _IAVCPLANCURDAO_PENGSHIKANG_20150824_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define AVCPLANCURDAO_CLASSID    "cavcplancurdao"
#define AVCPLANCURDAO_INTFID     "iavcplancurdao"

class IAvcPlanCurDao : virtual public IBasicDao
{
public:
	//根据AVC子站定值位置得到定值计划ID
	virtual int GetAvcSetPlanId(int pos) = 0;

	//根据AVC子站定值位置得到时间范围
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//根据AVC定值计划ID和当前时间得到AVC子站定值位置
	virtual int GetPositionByTime(int planId, int time) = 0;
	//根据AVC定值计划ID和当前时间读取计划电压值
	virtual bool GetPlanVoltage(int planId, int time, double& aimVoltage) = 0;
	//根据AVC定值计划ID和当前时间读取计划无功-功率因数值
	virtual bool GetPlanQorCosfa(int planId, int time, double& aimQorCosfa) = 0;

	//根据AVC子站定值位置读取当前计划电压值
	virtual double GetPlanVoltage(int pos) = 0;
	//根据AVC子站定值位置设置当前计划电压值
	virtual bool SetPlanVoltage(int pos, double aimVoltage) = 0;

	//根据AVC子站定值位置读取当前计划无功-功率因数值
	virtual double GetPlanQorCosfa(int pos) = 0;
	//根据AVC子站定值位置设置当前计划无功-功率因数值
	virtual bool SetPlanQorCosfa(int pos, double aimQorCosfa) = 0;

	//根据AVC子站定值位置读取当前实际电压值
	virtual double GetCurVoltage(int pos) = 0;
	//根据AVC子站定值位置设置当前实际电压值
	virtual bool SetCurVoltage(int pos, double aimVoltage) = 0;

	//根据AVC子站定值位置读取当前实际无功-功率因数值
	virtual double GeCurQorCosfa(int pos) = 0;
	//根据AVC子站定值位置设置当前实际无功-功率因数值
	virtual bool SetCurQorCosfa(int pos, double aimQorCosfa) = 0;

	//将数据表的动态信息写入库中
	virtual void WriteDynamicInfo1() = 0;

	//根据AVC子站定值位置读取计划无功-功率因数下限值
	virtual double GetCtrlRFLow(int pos) = 0;
	//根据AVC子站定值位置更改计划无功-功率因数下限值
	virtual bool SetCtrlRFLow(int pos, double minctrlrf) = 0;

	//根据AVC子站定值位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据AVC子站定值位置读取统计存储标志
	virtual int GetSaveFlag(int pos) = 0;

};

#endif
