//istbasicdao.h

#ifndef _ISTBASICDAO_20190527_YANGZHENYU_H_
#define _ISTBASICDAO_20190527_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define STBASICDAO_CLASSID    "cstbasicdao"
#define STBASICDAO_INTFID     "istbasicdao"


class IStbasicdao : virtual public IBasicDao
{
public:	
	//静态
	//根据储能电站位置得到所属控制区id
	virtual int GetMgID(int pos) = 0;

	//根据储能电站位置得到额定装机容量(MW)
	virtual double GetBatCapacity(int pos) = 0;

	//根据储能电站位置得到设备装机台数
	virtual double GetTotalEqNum(int pos) = 0;

	//根据储能电站位置得到应用系统
	virtual const char* GetFamilyName(int pos) = 0;

	////根据储能电站位置得到剩余容量SOCID
	//virtual int GetSocId(int pos) = 0;

	////根据储能电站位置得到剩余容量SOC
	//virtual double GetCurSoc(int pos) = 0;

	////根据储能电站位置得到全站SOHID
	//virtual int GetSohId(int pos) = 0;

	////根据储能电站位置得到全站电池平均温度ID
	//virtual int GetTempId(int pos) = 0;

	////根据储能电站位置得到当前全站SOH
	//virtual double GetSoh(int pos) = 0;

	////根据储能电站位置得到当前全站电池平均温度
	//virtual double GetTemperature(int pos) = 0;

	//根据储能电站位置得到远方就地压板ID
	virtual int GetFarclampID(int pos) = 0;

	//根据储能电站位置得到AGC本地压板ID
	virtual int GetPclampID(int pos) = 0;

	//根据储能电站位置得到本地AGC运行状态ID
	virtual int GetAgcStatusid(int pos) = 0;

	//根据储能电站位置得到总运行容量ID
	virtual int GetRunGenCptyID(int pos) = 0;

	//根据储能电站位置得到有功可调容量ID
	virtual int GetCtrlGenCptyID(int pos) = 0;

	//根据储能电站位置得到最大可放有功ID
	virtual int GetMaxpID(int pos) = 0;

	//根据储能电站位置得到最大可充有功ID
	virtual int GetMinPID(int pos) = 0;

	//根据储能电站位置得到可增有功ID
	virtual int GetIncreasPID(int pos) = 0;

	//根据储能电站位置得到可减有功ID
	virtual int GetDiminsPID(int pos) = 0;

	//根据储能电站位置得到并网点总有功ID
	virtual int GetPccPid(int pos) = 0;

	////根据储能电站位置得到储能充放电总有功ID
	//virtual int GetStoragePid(int pos) = 0;

	//根据储能电站位置得到有功反馈值ID
	virtual int GetPFdbckID(int pos) = 0;

	//根据储能电站位置得到有功功率遥调ID
	virtual int GetPCtrlID(int pos) = 0;

	//根据储能电站位置得到本地AVC运行状态ID
	virtual int GetAvcStatusid(int pos) = 0;

	//根据储能电站位置得到AVC本地压板ID
	virtual int GetQclampID(int pos) = 0;

	//根据储能电站位置得到最大可发无功ID
	virtual int GetMaxQID(int pos) = 0;

	//根据储能电站位置得到最大可吸无功ID
	virtual int GetMinQID(int pos) = 0;

	//根据储能电站位置得到可增无功ID
	virtual int GetIncreasQID(int pos) = 0;

	//根据储能电站位置得到可减无功ID
	virtual int GetDiminsQID(int pos) = 0;

	//根据储能电站位置得到并网点电压ID
	virtual int GetVolID(int pos) = 0;

	//根据储能电站位置得到并网点总无功ID
	virtual int GetPccQid(int pos) = 0;

	////根据储能电站位置得到储能充放电无功ID
	//virtual int GetStorageQid(int pos) = 0;

	//根据储能电站位置得到无功反馈值ID
	virtual int GetQFdbckID(int pos) = 0;

	//根据储能电站位置得到无功功率遥调ID
	virtual int GetQCtrlID(int pos) = 0;

	//根据储能电站位置得到当天充电电量ID
	virtual int GetTodayinPtID(int pos) = 0;

	//根据储能电站位置得到当天放电电量ID
	virtual int GetTodayoutPtID(int pos) = 0;

	//根据储能电站位置得到累计总充电量ID
	virtual int GetTotalinPtID(int pos) = 0;

	//根据储能电站位置得到累计总放电量ID
	virtual int GetTotaloutPtID(int pos) = 0;



	////根据储能电站位置得到储能站经济调度最大剩余容量
	//virtual double GetConMaxCap(int pos) = 0;
	//////根据储能电站位置设置储能站经济调度最大剩余容量
	////virtual bool SetConMaxCap(int pos, double ConMaxCap) = 0;

	////根据储能电站位置得到储能站经济调度最小剩余容量
	//virtual double GetConMinCap(int pos) = 0;
	//////根据储能电站位置设置储能站经济调度最小剩余容量
	////virtual bool SetConMinCap(int pos, double ConMinCap) = 0;

	////根据储能电站位置得到储能站允许最大剩余容量
	//virtual double GetExchMaxCap(int pos) = 0;
	//////根据储能电站位置设置储能站允许最大剩余容量
	////virtual bool SetExchMaxCap(int pos, double ExchMaxCap) = 0;

	////根据储能电站位置得到储能站允许最小剩余容量
	//virtual double GetDisconMinCap(int pos) = 0;
	//////根据储能电站位置设置储能站允许最小剩余容量
	////virtual bool SetDisconMinCap(int pos, double DisconMinCap) = 0;

	//根据储能电站位置得到历史值存储周期
	virtual int GetSvTimerID(int pos) = 0;
	////根据储能电站位置设置历史值存储周期
	//virtual bool SetSvTimerID(int pos, int SvTimerID) = 0;

	//根据储能电站位置得到遥调灵敏度系数
	virtual double GetSensitivity(int pos) = 0;
	////根据储能电站位置设置遥调灵敏度系数
	//virtual bool SetSensitivity(int pos, double Sensitivity) = 0;

	//根据储能电站位置得到运行设备台数遥测ID
	virtual int GetRunEqNumID(int pos) = 0;

	//根据储能电站位置得到事故总信号遥信ID
	virtual int GetTotalFtID(int pos) = 0;

	//根据储能电站位置得到动态可增无功ID
	virtual int GetDyInsQID(int pos) = 0;

	//根据储能电站位置得到动态可减无功ID
	virtual int GetDyDisQID(int pos) = 0;





	//动态
	////根据储能电站位置得到电池配置容量
	//virtual double GetBatCapacity(int pos) = 0;
	////根据储能电站位置设置电池配置容量
	//virtual bool SetBatCapacity(int pos, double BatCapacity) = 0;

	//根据储能电站位置得到当前远方就地压板
	virtual int GetFarclamp(int pos) = 0;
	//根据储能电站位置设置当前远方就地压板
	virtual bool SetFarclamp(int pos, int Farclamp) = 0;

	//根据储能电站位置得到当前AGC压板
	virtual int GetAGCclamp(int pos) = 0;
	//根据储能电站位置设置当前AGC压板
	virtual bool SetAGCclamp(int pos, int AGCclamp) = 0;

	//根据储能电站位置得到当前本地AGC运行状态
	virtual int GetAGCCurRunState(int pos) = 0;
	//根据储能电站位置设置当前本地AGC运行状态
	virtual bool SetAGCCurRunState(int pos, int AGCrunState) = 0;

	//根据储能电站位置得到当前本地AVC运行状态
	virtual int GetAVCCurRunState(int pos) = 0;
	//根据储能电站位置设置当前本地AVC运行状态
	virtual bool SetAVCCurRunState(int pos, int AVCrunState) = 0;

	//根据储能电站位置得到当前运行容量
	virtual double GetCurRunGenCpty(int pos) = 0;
	//根据储能电站位置设置当前运行容量
	virtual bool SetCurRunGenCpty(int pos, double CurRunGenCpty) = 0;

	//根据储能电站位置得到当前有功可调容量
	virtual double GetCurCtrlGenCpty(int pos) = 0;
	//根据储能电站位置设置当前有功可调容量
	virtual bool SetCurCtrlGenCpty(int pos, double CurCtrlGenCpty) = 0;

	//根据储能电站位置得到当前并网有功
	virtual double GetCurPccP(int pos) = 0;
	//根据储能电站位置设置当前并网有功
	virtual bool SetCurPccP(int pos, double CurPccP) = 0;

	////根据储能电站位置得到当前储能充放电有功
	//virtual double GetCurStorageP(int pos) = 0;
	////根据储能电站位置设置当前储能充放电有功
	//virtual bool SetCurStorageP(int pos, double CurStorageP) = 0;

	//根据储能电站位置得到当前有功反馈值
	virtual double GetCurPFdbck(int pos) = 0;
	//根据储能电站位置设置当前有功反馈值
	virtual bool SetCurPFdbck(int pos, double CurPFdbck) = 0;

	//根据储能电站位置得到当前最大可放有功
	virtual double GetCurMaxP(int pos) = 0;
	//根据储能电站位置设置当前最大可放有功
	virtual bool SetCurMaxP(int pos, double CurMaxP) = 0;

	//根据储能电站位置得到当前最大可充有功
	virtual double GetCurMinP(int pos) = 0;
	//根据储能电站位置设置当前最大可充有功
	virtual bool SetCurMinP(int pos, double CurMinP) = 0;

	//根据储能电站位置得到当前可增有功
	virtual double GetCurIncreasP(int pos) = 0;
	//根据储能电站位置设置当前可增有功
	virtual bool SetCurIncreasP(int pos, double CurIncreasP) = 0;

	//根据储能电站位置得到当前可减有功
	virtual double GetCurDiminsP(int pos) = 0;
	//根据储能电站位置设置当前可减有功
	virtual bool SetCurDiminsP(int pos, double CurDiminsP) = 0;

	//根据储能电站位置得到有功控制计划值
	virtual double GetPlanP(int pos) = 0;
	//根据储能电站位置设置有功控制计划值
	virtual bool SetPlanP(int pos, double PlanP) = 0;

	////根据储能电站位置得到有功控制原因
	//virtual int GetPctrlSort(int pos) = 0;
	////根据储能电站位置设置有功控制原因
	//virtual bool SetPctrlSort(int pos, int PctrlSort) = 0;

	//根据储能电站位置得到有功控制时间
	virtual double GetPCtrlTime(int pos) = 0;
	//根据储能电站位置设置有功控制时间
	virtual bool SetPCtrlTime(int pos) = 0;

	//根据储能位置初始化有功调节失败次数。
	virtual bool InitPCtrlFailTimes(int pos) = 0;
	//根据储能位置增加有功调节失败次数。
	virtual bool IncreasePCtrlFailTimes(int pos) = 0;
	//根据储能位置得到有功调节失败次数
	virtual int GetPCtrlFailTimes(int pos) = 0;

	//根据储能电站位置得到有功失败闭锁时间
	//virtual double GetPLockedTime(int pos) = 0;
	////根据储能电站位置设置有功失败闭锁时间
	//virtual bool SetPLockedTime(int pos, double PLockedTime) = 0;

	//根据储能电站位置得到当前电压有名值(kV)
	virtual double GetCurVolVal(int pos) = 0;
	//根据储能电站位置设置当前电压有名值(kV)
	virtual bool SetCurVolVal(int pos, double CurVolVal) = 0;

	//根据储能电站位置得到当前电压标幺值
	virtual double GetCurVolPer(int pos) = 0;
	//根据储能电站位置设置当前电压标幺值
	virtual bool SetCurVolPer(int pos, double CurVolPer) = 0;

	//根据储能电站位置得到当前并网无功
	virtual double GetCurPccQ(int pos) = 0;
	//根据储能电站位置设置当前并网无功
	virtual bool SetCurPccQ(int pos, double CurPccQ) = 0;

	////根据储能电站位置得到当前储能充放电无功
	//virtual double GetCurStorageQ(int pos) = 0;
	////根据储能电站位置设置当前储能充放电无功
	//virtual bool SetCurStorageQ(int pos, double CurStorageQ) = 0;

	//根据储能电站位置得到当前无功反馈值
	virtual double GetCurQFdbck(int pos) = 0;
	//根据储能电站位置设置当前无功反馈值
	virtual bool SetCurQFdbck(int pos, double CurQFdbck) = 0;

	//根据储能电站位置得到当前最大可发无功
	virtual double GetCurMaxQ(int pos) = 0;
	//根据储能电站位置设置当前最大可发无功
	virtual bool SetCurMaxQ(int pos, double CurMaxQ) = 0;

	//根据储能电站位置得到当前最大可吸无功
	virtual double GetCurMinQ(int pos) = 0;
	//根据储能电站位置设置当前最大可吸无功
	virtual bool SetCurMinQ(int pos, double CurMinQ) = 0;

	//根据储能电站位置得到当前AVC压板
	virtual int GetCurQClamp(int pos) = 0;
	//根据储能电站位置设置当前AVC压板
	virtual bool SetCurQClamp(int pos, int CurQClamp) = 0;

	//根据储能电站位置得到当前可增无功
	virtual double GetCurIncreasQ(int pos) = 0;
	//根据储能电站位置设置当前可增无功
	virtual bool SetCurIncreasQ(int pos, double CurIncreasQ) = 0;

	//根据储能电站位置得到当前可减无功
	virtual double GetCurDiminsQ(int pos) = 0;
	//根据储能电站位置设置当前可减无功
	virtual bool SetCurDiminsQ(int pos, double CurDiminsQ) = 0;

	//根据储能电站位置得到无功控制计划值
	virtual double GetPlanQ(int pos) = 0;
	//根据储能电站位置设置无功控制计划值
	virtual bool SetPlanQ(int pos, double PlanQ) = 0;

	////根据储能电站位置得到无功控制原因
	//virtual int GetQCtrlSort(int pos) = 0;
	////根据储能电站位置设置无功控制原因
	//virtual bool SetQCtrlSort(int pos, int QCtrlSort) = 0;

	//根据储能电站位置得到无功控制时间
	virtual double GetQCrlTime(int pos) = 0;
	//根据储能电站位置设置无功控制时间
	virtual bool SetQCrlTime(int pos) = 0;

	//根据储能位置初始化无功调节失败次数。
	virtual bool InitQCtrlFailTimes(int pos) = 0;
	//根据储能位置增加无功调节失败次数。
	virtual bool IncreaseQCtrlFailTimes(int pos) = 0;
	//根据储能位置得到无功调节失败次数
	virtual int GetQCtrlFailTimes(int pos) = 0;

	//根据储能电站位置得到无功失败闭锁时间
	//virtual double GetQLockedTime(int pos) = 0;
	////根据储能电站位置设置无功失败闭锁时间
	//virtual bool SetQLockedTime(int pos, double QLockedTime) = 0;

	////根据储能位置初始化总充电次数。
	//virtual bool InitChargeTimes(int pos) = 0;
	////根据储能位置增加总充电次数。
	//virtual bool IncreaseChargeTimes(int pos) = 0;
	////根据储能位置得到总充电次数
	//virtual int GetChargeTimes(int pos) = 0;

	////根据储能位置初始化总放电次数。
	//virtual bool InitDisChargeTimes(int pos) = 0;
	////根据储能位置增加总放电次数。
	//virtual bool IncreaseDisChargeTimes(int pos) = 0;
	////根据储能位置得到总放电次数
	//virtual int GetDisChargeTimes(int pos) = 0;

	////根据储能位置初始化今日充电次数。
	//virtual bool InitTodayChargeTimes(int pos) = 0;
	////根据储能位置增加今日充电次数。
	//virtual bool IncreaseTodayChargeTimes(int pos) = 0;
	////根据储能位置得到今日充电次数
	//virtual int GetTodayChargeTimes(int pos) = 0;

	////根据储能位置初始化今日放电次数。
	//virtual bool InitTodayDisChargeTimes(int pos) = 0;
	////根据储能位置增加今日放电次数。
	//virtual bool IncreaseTodayDisChargeTimes(int pos) = 0;
	////根据储能位置得到今日放电次数
	//virtual int GetTodayDisChargeTimes(int pos) = 0;

	//根据储能位置得到当天充电电量
	virtual double GetTodayinPt(int pos) = 0;
	//根据储能电站位置设置当天充电电量
	virtual bool SetTodayinPt(int pos, double TdInP) = 0;

	//根据储能位置得到当天放电电量
	virtual double GetTodayoutPt(int pos) = 0;
	//根据储能电站位置设置当天放电电量
	virtual bool SetTodayoutPt(int pos, double TdOutP) = 0;

	//根据储能位置得到累计总充电量
	virtual double GetTotalinPt(int pos) = 0;
	//根据储能电站位置设置累计总充电量
	virtual bool SetTotalinPt(int pos, double TotalInP) = 0;

	//根据储能位置得到累计总放电量
	virtual double GetTotaloutPt(int pos) = 0;
	//根据储能电站位置设置累计总放电量
	virtual bool SetTotaloutPt(int pos, double TotalOutP) = 0;

	////计算当前功率充电可用时间(分钟)
	//virtual double CalculateInableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	////计算当前功率放电可用时间(分钟)
	//virtual double CalculateOutableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	////计算最大功率充电可用时间(分钟)
	//virtual double CalculateMaxPinableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	////计算最大功率放电可用时间(分钟)
	//virtual double CalculateMaxPoutableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	////根据储能电站位置得到全站充电闭锁标志
	//virtual int GetChargeLock(int pos) = 0;
	////根据储能电站位置设置全站充电闭锁标志
	//virtual bool SetChargeLock(int pos, int ChargeLock) = 0;

	////根据储能电站位置得到全站放电闭锁标志
	//virtual int GetDisChargeLock(int pos) = 0;
	////根据储能电站位置设置全站放电闭锁标志
	//virtual bool SetDisChargeLock(int pos, int DisChargeLock) = 0;

	//根据储能电站位置得到当前通讯状态
	virtual int GetCurNetState(int pos) = 0;
	//根据储能电站位置设置当前通讯状态
	virtual bool SetCurNetState(int pos, int CurNetState) = 0;

	//根据储能电站位置得到运行设备台数
	virtual int GetCurRunEqNum(int pos) = 0;
	//根据储能电站位置设置运行设备台数
	virtual bool SetCurRunEqNum(int pos, int CurRunEqNum) = 0;

	//根据储能电站位置得到事故总信号
	virtual int GetTotalFt(int pos) = 0;
	//根据储能电站位置设置事故总信号
	virtual bool SetTotalFt(int pos, int TotalFt) = 0;

	//根据储能电站位置得到当前动态可增无功
	virtual double GetCurDyInsQ(int pos) = 0;
	//根据储能电站位置得到当前动态可增无功
	virtual bool SetCurDyInsQ(int pos, double CurDyInsQ) = 0;

	//根据储能电站位置得到当前动态可减无功
	virtual double GetCurDyDisQ(int pos) = 0;
	//根据储能电站位置得到当前动态可减无功
	virtual bool SetCurDyDisQ(int pos, double CurDyDisQ) = 0;
};

#endif
