//iexchcrvplandao.h

#ifndef _IEXCHANGEPOWERCURVEPLANDAO_PENGSHIKANG_20110314_H_
#define _IEXCHANGEPOWERCURVEPLANDAO_PENGSHIKANG_20110314_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EXCHCURVEPLANDAO_CLASSID    "cexchcurveplandao"
#define EXCHCURVEPLANDAO_INTFID     "iexchcurveplandao"

typedef enum
{
	LOCAL_CURVE, DISPATCH_SETTING, DISPATCH_CURVE5, DISPATCH_CURVE15, DISPATCH_INCREMENT, DISPATCH_SETTING_WK, UNDEFINE,
	// 本地，       调度定值，     调度5分钟曲线，  调度15分钟曲线，     调度增量，          调度稳控，         终止符，
}CurvePlanType;

class IExchCurvePlanDao : virtual public IBasicDao
{
public:
	//根据交换功率曲线位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;
	//根据交换功率曲线位置读取是否有效标志
	virtual int IsEnable(int pos) = 0;
	//根据子微网ID得到有效的本地交换功率曲线计划ID[暂未用]
	virtual int GetEnableCurvePlanId(int mgId) = 0;	
	//得到调度交换功率曲线计划位置
	virtual int GetDispatchCurvePlanPos(CurvePlanType& dispType) = 0;
	//根据调度交换功率曲线计划位置判断是否有效
	virtual bool IsValidDispatchCurvePlan(int pos, double curTime) = 0;

	//根据交换功率曲线计划位置读取功率调节类型。
	//返回值：0：输出按功率进行调节；1：输出按发电额定容量百分比调节
	virtual int GetPowerAdjustType(int pos) = 0;
	//根据交换功率曲线计划位置读取计划曲线值来源。
	//返回值：0：本地设置计划曲线；1: 远程调度下发控制值；2：远方调度下发5分钟计划曲线；3：远方调度下发15分钟计划曲线；4：远方调度下发有功增量。
	virtual int GetCurveValueOrigin(int pos) = 0;
	//根据交换功率曲线计划位置读取调度有功功率值是否以输出到大电网为正值。
	//返回值：true: 子站输出有功为正；false：有功流入子站为正。 
	virtual bool DispatchPIsOutput(int pos) = 0;
	//根据交换功率曲线计划位置读取调度有功功率值是否以MW为单位。
	//返回值：true: 单位为MW；false：单位为kW。 
	virtual bool DispatchPInMW(int pos) = 0;
	//根据交换功率曲线计划位置读取远程调度命令接收时间
	virtual double GetReceiveTime(int pos) = 0;
	//根据交换功率曲线计划位置读取远程调度下发周期定时器ID
	virtual int GetUpdateTimerID(int pos) = 0;
	//根据交换功率曲线计划位置读取调度指令有效时间间隔
	virtual double GetValidTimeSpan(int pos) = 0;
	//根据交换功率曲线计划位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据交换功率曲线计划位置读取统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//根据交换功率曲线计划位置读取当前交换功率目标值
	virtual double GetCurrentAimValue(int pos) = 0;
	//根据交换功率曲线计划位置设置当前交换功率目标值
	virtual bool SetCurrentAimValue(int pos, double aimValue) = 0;

	//根据交换功率曲线计划位置保存远程调度曲线命令信息
	virtual bool SaveDispatchCurveInfo(int pos, double recvTime) = 0;
	//根据交换功率曲线计划位置保存远程调度定值命令信息
	virtual bool SaveDispatchValueInfo(int pos, double recvTime, double aimValue) = 0;

	//根据交换功率曲线计划位置读取当前交换功率实际值
	virtual double GetActualPower(int pos) = 0;
	//根据交换功率曲线计划位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据交换功率曲线计划位置设置当前交换功率实际值
	virtual bool SetActualPower(int pos, double curValue, double curTime) = 0;

	//根据子微网ID得到有效的本地交换功率曲线计划位置
	virtual int GetLocalCurvePlanPos(int mgId) = 0;	

	//根据交换功率曲线计划位置读取调度下发是否有效标志
	virtual bool IsDispatchEnable(int pos) = 0;
	//根据交换功率曲线计划位置设置调度下发是否有效标志
	virtual bool SetDispatchEnable(int pos, int nDispEnable) = 0;
	//根据曲线计划类型得到有效的交换功率曲线计划位置
	virtual int GetPositionByPlanType(CurvePlanType dispType, bool bEnable=true) = 0;
	//根据交换功率曲线位置设置是否有效标志，返回被设置的记录位置( >= 0 )。设置失败时返回-1。
	virtual int SetEnableFlagByPlanType(CurvePlanType dispType, bool bEnable) = 0;

	//根据交换功率曲线计划位置读取控制目标类型。0：交换功率； 1：新能源发电功率； 2：储能充放电功率。
	virtual int GetCtrlAimType(int pos) = 0;
	//根据交换功率曲线计划位置读取调度目标值异常标志
	virtual int GetAimAbnormalFlag(int pos) = 0;
	//根据交换功率曲线计划位置设置调度目标值异常标志
	virtual bool SetAimAbnormalFlag(int pos, int nAbnormalFlag) = 0;

};

#endif
