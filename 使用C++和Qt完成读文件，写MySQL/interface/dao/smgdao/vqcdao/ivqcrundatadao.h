//ivqcrundatadao.h

#ifndef _IVQCRUNDATADAO_PENGSHIKANG_20120628_H_
#define _IVQCRUNDATADAO_PENGSHIKANG_20120628_H_

#include "../../ibasicdao.h"                     // for IBasicDao

#define VQCRUNDATADAO_CLASSID    "cvqcrundatadao"
#define VQCRUNDATADAO_INTFID     "ivqcrundatadao"

class IVqcRunDataDao : virtual public IBasicDao
{
public:
	virtual void SetTargetIsRp(int pos, int isRpTarget) = 0;
	virtual void SetVoltageRange(int pos, double upper, double lower) = 0;
	virtual void SetQOrCosRange(int pos, double upper, double lower) = 0;
	virtual void SetCurrentVoltage(int pos, double rateVolt, double realVolt) = 0;
	virtual void SetCurrentPower(int pos, double curP, double curQ, double curPF) = 0;
	virtual void SetEnableFlag(int pos, bool isEnable) = 0;
	virtual void ClearEnableFlag() = 0;

	//根据Vqc实时运行表位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据Vqc实时运行表位置读取统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//根据Vqc实时运行表位置复位该记录的统计存储标志
	virtual bool ResetSaveFlag(int pos) = 0;

	virtual void SetVoltageBase(int pos, double baseV) = 0;
	virtual void SetVoltageRatio(int pos, double dUdatio) = 0;
	virtual void SetRefVoltageRange(int pos, double upper, double lower) = 0;
	virtual void SetRefVoltageValue(int pos, double refVolt) = 0;

	//根据Vqc实时运行表位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据Vqc实时运行表位置设置最后一次统计时间
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;

	virtual int GetTargetIsRp(int pos) = 0;
	virtual double GetRateVoltage(int pos) = 0;
	virtual double GetRealVoltage(int pos) = 0;
	virtual double GetVoltageUpper(int pos) = 0;
	virtual double GetVoltageLower(int pos) = 0;
	virtual double GetRealReactPower(int pos) = 0;
	virtual double GetReactPowerUpper(int pos) = 0;
	virtual double GetReactPowerLower(int pos) = 0;

	virtual void SetRateVoltage(int pos, double dValue) = 0;
	virtual void SetRealVoltage(int pos, double dValue) = 0;
	virtual void SetRealReactPower(int pos, double dValue) = 0;
	virtual void SetReactPowerUpper(int pos, double dValue) = 0;
	virtual void SetReactPowerLower(int pos, double dValue) = 0;
		
	virtual bool SetAdjustQLower(int pos, double dValue) = 0;
	virtual double GetAdjustQLower(int pos) = 0;
	virtual bool SetAdjustQUpper(int pos, double dValue) = 0;
	virtual double GetAdjustQUpper(int pos) = 0;
	virtual bool SetAdjustQIncLimit(int pos, double dValue) = 0;
	virtual double GetAdjustQIncLimit(int pos) = 0;
	virtual bool SetAdjustQDecLimit(int pos, double dValue) = 0;
	virtual double GetAdjustQDecLimit(int pos) = 0;
	virtual bool SetAdjustQIncLock(int pos, int iValue) = 0;
	virtual int GetAdjustQIncLock(int pos) = 0;
	virtual bool SetAdjustQDecLock(int pos, int iValue) = 0;
	virtual int GetAdjustQDecLock(int pos) = 0;
	//将数据表的动态信息写入库中[save]
	virtual void WriteDynamicInfo1() = 0;
	virtual double GetRealPowerFactor(int pos) = 0;

	virtual void SetAvcPlanTypeAndPlanId(int pos, int iPlanType, int iPlanID) = 0;
	// 读取当前电压无功控制计划类型 0 -- VQC;1 -- AVC
	virtual int GetCurPlanType(int pos) = 0;
	// 读取当前电压无功控制计划ID 
	virtual int GetCurPlanID(int pos) = 0;
	// 读取当前电压基准值
	virtual double GetVoltageBase(int pos) = 0;

	//得到当前电压无功连续控制次数
	virtual bool GetCurCtrlTimes(int id, int& areaNo, int& actCount) = 0;
	//得到当前状态点处于九区图中的区号
	virtual int GetNineAreaPos(int pos) = 0;
	//设置当前电压无功连续控制次数
	virtual bool SetCurCtrlTimes(int pos, int ctrlTimes) = 0;
	//设置当前状态点在九区图中的区号
	virtual bool SetNineAreaPos(int pos, int areaNo) = 0;
	//更新当前电压无功连续控制次数
	virtual bool UpdateCurCtrlTimes(int id, int areaNo, bool hasAct) = 0;
	//将当前电压无功连续控制次数写入实时库中
	virtual void WriteCurCtrlTimes() = 0;

	//判断数据表中是否存在参考电压上限、下限、当前值等字段
	virtual bool HasRefVoltageValue() = 0;
	//判断数据表中是否存在当前连续控制次数、九区图中区号字段
	virtual bool HasCurCtrlTimes() = 0;

	virtual bool SetRpcAdjustQLowerValue(int pos, double dValue) = 0;//设置动态无功可调下限值
	virtual double GetRpcAdjustQLowerValue(int pos) = 0;//得到动态无功可调下限值
	virtual bool SetRpcAdjustQUpperValue(int pos, double dValue) = 0;//设置动态无功可调上限值
	virtual double GetRpcAdjustQUpperValue(int pos) = 0;//得到动态无功可调上限值
	virtual bool SetRpcAdjustQLowerAim(int pos, double dValue) = 0;//设置动态无功可调下限目标值
	virtual double GetRpcAdjustQLowerAim(int pos) = 0;//得到动态无功可调下限目标值
	virtual bool SetRpcAdjustQUpperAim(int pos, double dValue) = 0;//设置动态无功可调上限目标值
	virtual double GetRpcAdjustQUpperAim(int pos) = 0;//得到动态无功可调上限目标值

	virtual bool SetCurTotalRpcQ(int pos,double dValue) = 0; //设置全站动态总无功
	virtual double GetCurTotalRpcQ(int pos) = 0;//得到全站动态总无功
	virtual bool SetMaxTotalRpcQ(int pos,double dValue) = 0; //设置动态无功值上限
	virtual double GetMaxTotalRpcQ(int pos) = 0;//得到全动态无功值上限
	virtual bool SetMinTotalRpcQ(int pos,double dValue) = 0; //设置动态无功值下限
	virtual double GetMinTotalRpcQ(int pos) = 0;//得到动态无功值下限

	//根据VQC实时运行记录位置设置控制母线ID
	virtual bool SetCtrlBusID(int pos, int iBusId) = 0;
	//根据VQC实时运行记录位置读取控制母线ID
	virtual int GetCtrlBusID(int pos) = 0;
	//根据控制母线ID得到VQC实时运行记录位置。若返回-1，表示不存在该母线对应的记录
	virtual int GetPositionByBusID(int iBusId) = 0;

	//根据VQC实时运行记录位置读取当前记录是否有效
	virtual bool IsEnabled(int pos) = 0;


};

#endif
