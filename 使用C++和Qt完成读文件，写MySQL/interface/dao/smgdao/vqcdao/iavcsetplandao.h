//iavcsetplandao.h

#ifndef _IAVCSETPLANDAO_PENGSHIKANG_20150824_H_
#define _IAVCSETPLANDAO_PENGSHIKANG_20150824_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define AVCSETPLANDAO_CLASSID    "cavcsetplandao"
#define AVCSETPLANDAO_INTFID     "iavcsetplandao"

typedef enum
{
	LOCAL_QCURVE, DISPATCH_QSETTING, DISPATCH_QCURVE5, DISPATCH_QCURVE15, QUNDEFINE,
}QCurvePlanType;

typedef struct 
{
	int iCount;
	int busIds[4];
	int planPos[4];
}MultBusPlan;


class IAvcSetPlanDao : virtual public IBasicDao
{
public:

	//根据无功定值计划类型得到AVC定值计划位置
	virtual int GetDispatchCurvePlanPos(QCurvePlanType& dispType) = 0;
	//根据当前时间判断指定位置的AVC定值计划是否有效
	virtual bool IsValidDispatchCurvePlan(int pos, double curTime) = 0;

	//根据AVC定值计划位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;

	//根据AVC定值计划位置读取电压无功调节类型。
	//返回值：0：恒电压；1：恒无功功率（kVar/Mvar）；2：恒功率因数；3：无功区间值；4：功率因数区间值；5：无功增量值。
	virtual int GetVQCosAdjustType(int pos) = 0;
	//根据AVC定值计划位置读取计划来源类型。
	//返回值：0：本地设置计划曲线；1: 远程调度下发控制值；2：远方调度下发5分钟计划曲线；3：远方调度下发15分钟计划曲线。
	virtual int GetCurveValueOrigin(int pos) = 0;
	//根据AVC定值计划位置读取调度无功功率值是否以输出到大电网为正值。
	//返回值：true: 子站输出无功为正；false：无功流入子站为正。 
	virtual bool DispatchQIsOutput(int pos) = 0;
	//根据AVC定值计划位置读取调度无功功率值是否以MVar为单位。
	//返回值：true: 单位为MVar；false：单位为kVar。 
	virtual bool DispatchQInMVar(int pos) = 0;
	//根据AVC定值计划位置得到闭锁电压限值
	virtual void GetLockVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//根据AVC定值计划计划位置得到电压值类型：0--标幺值；1--有名值；2--标幺增量值；3--有名增量值。
	virtual int GetVoltageAimValueType(int pos) = 0;


	//根据AVC定值计划位置得到AVC调节策略类型
	virtual int GetStrategyType(int pos) = 0;
	//根据AVC定值计划位置判断无功调节目标是否为无功
	virtual bool TargetIsRp(int pos) = 0;
	//根据AVC定值计划位置判断是否允许无功倒送
	virtual bool CanRpReverse(int pos) = 0;
	//根据AVC定值计划位置得到功率方向相反时无功倒送上限
	virtual double GetMaxRpReverse(int pos) = 0;
	//根据AVC定值计划位置得到电压调节值类型
	virtual int GetVoltageValueType(int pos) = 0;
	//根据AVC定值计划位置读取调度指令有效时间间隔
	virtual double GetValidTimeSpan(int pos) = 0;
	//根据AVC定值计划位置读取远程调度下发周期定时器ID
	virtual int GetCommTimerID(int pos) = 0;

	//根据AVC定值计划位置读取远程调度命令接收时间
	virtual double GetReceiveTime(int pos) = 0;
	//根据AVC定值计划位置更改远程调度命令接收时间
	virtual bool SetReceiveTime(int pos, double recvTime) = 0;

	//根据AVC定值计划位置读取当前计划电压值（标幺值）
	virtual double GetPlanVol(int pos) = 0;
	//根据AVC定值计划位置更改当前计划电压值（标幺值）
	virtual bool SetPlanVol(int pos, double planvol) = 0;

	//根据AVC定值计划位置读取当前计划无功-功率因数值
	virtual double GetPlanRF(int pos) = 0;
	//根据AVC定值计划位置更改当前计划无功-功率因数值
	virtual bool SetPlanRF(int pos, double planrf) = 0;

	//根据AVC定值计划位置读取当前实际电压值（标幺值）
	virtual double GetCurVol(int pos) = 0;
	//根据AVC定值计划位置更改当前实际电压值（标幺值）
	virtual bool SetCurVol(int pos, double curVol) = 0;

	//根据AVC定值计划位置读取当前实际无功-功率因数值
	virtual double GetCurRF(int pos) = 0;
	//根据AVC定值计划位置更改当前实际无功-功率因数值
	virtual bool SetCurRF(int pos, double curRf) = 0;

	//根据AVC定值计划位置保存远程调度AVC定值接收时间[save]
	virtual bool SaveDispatchReceiveTime(int pos, double recvTime) = 0;
	//根据AVC定值计划位置保存远程调度AVC电压定值信息[save]
	virtual bool SaveDispatchVoltageInfo(int pos, double recvTime, double aimVoltage) = 0;
	//根据AVC定值计划位置保存当前电压值信息[save]
	virtual bool SaveCurrentAimVoltage(int pos, double curVoltage) = 0;
	//根据AVC定值计划位置保存远程调度AVC无功-功率因数定值信息[save]
	virtual bool SaveDispatchQorCosfaInfo(int pos, double recvTime, double aimQorCosfa) = 0;
	//根据AVC定值计划位置保存当前无功-功率因数值定值信息[save]
	virtual bool SaveCurrentQorCosfaValue(int pos, double curQorCosfa) = 0;

	//得到有效的本地AVC曲线计划位置
	virtual int GetLocalCurvePlanPos() = 0;

	//根据AVC定值计划位置读取当前计划无功-功率因数下限值
	virtual double GetPlanRFLow(int pos) = 0;
	//根据AVC定值计划位置更改当前计划无功-功率因数下限值
	virtual bool SetPlanRFLow(int pos, double minplanrf) = 0;
	//根据AVC定值计划位置保存远程调度AVC无功-功率因数下限值信息[save]
	virtual bool SaveDispatchQorCosfaLower(int pos, double recvTime, double aimQorCosfa) = 0;
	//根据AVC定值计划位置保存当前无功-功率因数区间值信息[save]
	virtual bool SaveCurrentQorCosfaRange(int pos, double curQUpper, double curQLower) = 0;

	//根据电压无功调节类型和调度类型得到AVC定值计划位置
	virtual int GetDispatchCurvePlanPosByType(int adjustType, QCurvePlanType dispType) = 0;
	//根据调度类型优先级和调度下发时间得到AVC定值计划位置
	virtual int GetDispatchCurvePlanPosByTime(QCurvePlanType& dispType) = 0;

	//根据AVC定值计划位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据AVC定值计划位置读取统计存储标志
	virtual int GetSaveFlag(int pos) = 0;

	//根据AVC定值计划位置读取控制母线ID
	virtual int GetCtrlBusID(int pos) = 0;
	//根据AVC定值计划位置读取调度目标值异常标志
	virtual int GetAimAbnormalFlag(int pos) = 0;
	//根据AVC定值计划位置设置调度目标值异常标志
	virtual bool SetAimAbnormalFlag(int pos, int nAbnormalFlag) = 0;
	//根据调度类型优先级和控制母线ID得到AVC定值计划位置
	virtual int GetDispatchCurvePlanPosByBusID(int busId, QCurvePlanType& dispType) = 0;
	//根据调度类型得到AVC定值计划母线组
	virtual MultBusPlan GetDispatchCurvePlanGroupByType(int adjustType, QCurvePlanType dispType) = 0;
	//根据AVC定值计划位置保存是否有效标志
	virtual bool SaveEnable(int pos, int iEnable) = 0;

	//根据母线ID得到有效的本地AVC曲线计划位置
	virtual int GetLocalCurvePlanPos(int busId) = 0;

	//根据AVC定值计划位置读取当前实际电压参考值
	virtual double GetVoltageReferValue(int pos) = 0;
	//根据AVC定值计划位置设置当前实际电压参考值
	virtual bool SetVoltageReferValue(int pos, double dVoltRef) = 0;
	//根据AVC定值计划位置读取当前实际无功功率参考值
	virtual double GetRepowerReferValue(int pos) = 0;
	//根据AVC定值计划位置设置当前实际无功功率参考值
	virtual bool SetRepowerReferValue(int pos, double dRepowRef) = 0;
};

#endif
