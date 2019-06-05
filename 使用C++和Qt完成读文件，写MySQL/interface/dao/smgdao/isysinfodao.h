//isysinfodao.h

#ifndef _ISYSINFODAO_PENGSHIKANG_20100927_H_
#define _ISYSINFODAO_PENGSHIKANG_20100927_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SYSINFODAO_CLASSID    "csysinfodao"
#define SYSINFODAO_INTFID     "isysinfodao"

enum SYSCTRLMODE
{
	SYSCTRLMODE_ALLAUTO,      // 0--全自动
	SYSCTRLMODE_CUTAUTO,      // 1--控分自动控合监护
	SYSCTRLMODE_MANUAL,       // 2--全监护
	SYSCTRLMODE_ALARM,        // 3--仅报警提示
	SYSCTRLMODE_NOAUTO,       // 4--由控点配置确定
};

enum DISPATCHFLAGBIT
{
	REPOWER_EMERGE=6, 
	POWER_RECALL, 
	POWER_SETTING, 
	POWER_REVERSE, 
	POWER_SMOOTH, 
	STORAGE_PCURVE, 
	POWER_OPTIMIZE, 
	VOLTAGE_SETTING, 
	STORAGE_SOCKEEP, 
	EMERGE_SUPPORT, 
	EMERGE_STOP, 
	QORCOS_SETTING=13,
};

class ISysInfoDao : virtual public IBasicDao
{
public:
	virtual int GetStationNumber() = 0;        //得到开闭所个数
	virtual int GetMicgridNumber() = 0;        //得到微电网个数
	virtual int GetProFlag() = 0;              //得到处理标志
	virtual double GetExchangePlusMargin() = 0;//得到交换定值允许上偏差
	virtual double GetExchangeNegMargin() = 0; //得到交换定值允许下偏差
	virtual double GetStoragePlusMargin() = 0; //得到储能充放电允许上偏差
	virtual double GetStorageNegMargin() = 0;  //得到储能充放电允许下偏差
	virtual double GetMaxReversePower() = 0;   //得到防逆流最大功率门槛
	virtual double GetMinStoreCapacity1() = 0; //得到离网储能容量门限1：大于该值可以投2、3级负荷
	virtual double GetMinStoreCapacity2() = 0; //得到离网储能容量门限2：大于该值可以投1级负荷，小于等于该值可以切2、3级负荷
	virtual double GetMinStoreCapacity3() = 0; //得到离网储能容量门限3：小于等于该值可以切1级负荷
	virtual int GetExchangeFlag() = 0;         //得到定交换控制启动标志
	virtual int GetEmergeExchangeFlag() = 0;   //得到紧急交换控制启动标志
	virtual double GetExchangeSetValue() = 0;  //得到定交换功率定值
	//--------0809_0815_zff_new_add-------------------------------//
	virtual bool GetConnectType() = 0;   //得到系统并离网类型 0:离网型 1:并网型
	virtual int GetIslandproflag() = 0;  //得到离网型系统功能处理
	virtual int GetSysProflag() = 0;     //得到微电网系统功能处理标志
    virtual int GetBlackStartTime() = 0; //得到黑启动延时时间(秒)
	virtual int GetStylesWitchSpan() = 0;//得到运行方式切换时间间隔(分钟)
    virtual int GetSwitchDayMaxTimes() = 0; //得到开关日动作最大次数
	virtual double GetSwitchOperSpan() = 0; //得到开关动作时间间隔(分钟) 
	virtual double GetLoadMaxImpactTimes() = 0;//负荷最大启动冲击倍数
	//---------------------------------------------------------//
	virtual bool ModifyEmergeExchangeFlag(bool bRun) = 0;//(1)投入交换功率紧急支撑压板
	virtual bool ModifyEmergeStopFlag(bool bRun) = 0;//(2)投入交换功率紧急停运压板
	virtual bool ModifyExchangeSetValueFlag(bool bRun) = 0;//(3)投入交换功率定值调度压板
	virtual bool EnableEmergeExchange(int bEnable) = 0;//(4)启动交换功率紧急支撑功能
	virtual bool EnableEmergeStop(int bEnable) = 0;//(5)启动交换功率紧急停运功能
	virtual bool ModifyExchangeSetValue(double dESValue) = 0;//(6)修改定交换功率定值
	virtual bool ModifyDispatchFlag(DISPATCHFLAGBIT dispBit, bool bRun) = 0;//(7)投入调度策略压板

	virtual int GetControlPattern() = 0; //得到策略自动执行方式
	virtual int GetSysRunStyle() = 0; //得到当前系统运行模式
	virtual bool SetSysRunStyle(int runStyle) = 0; //设置当前系统运行模式
	virtual bool SetSysAimRunStyle(int runStyle) = 0; //设置系统目标运行模式
	virtual int  GetSysAimRunStyle() = 0; //得到系统目标运行模式
	virtual bool SetSysNextRunStyle(int runStyle) = 0;//设置目标未来系统运行模式
	virtual int GetSysNextRunStyle() = 0;	//得到未来系统运行模式
	virtual int GetConnStragetySpan() = 0;	//得到并网策略执行间隔时间(秒)
	virtual int GetDispatchFlagUpdate() = 0;//得到AGC调度压板更新状态
	virtual int GetOnlyLocalFlag() = 0;     //得到本地策略压板投入标志：0--远方；1--本地。
	virtual bool GetLocalFlagUpdate(int& localFlag) = 0;//获取本地策略压板投入标志是否变更
	virtual int GetGroupCtrlFlag() = 0;     //得到组播方式群控标志
	virtual double GetMaxAdjustPStep() = 0; //得到并网有功控制步长
	virtual double GetMaxAdjustQStep() = 0; //得到并网无功控制步长
	virtual bool IsPlantSystem() = 0;       //是否为升压站系统

	virtual double GetMaxAdjustPRate() = 0; //获取调度下发的有功调节最大速率(kW/Min)
	virtual bool ModifyMaxPowerRate(double dMaxPRate) = 0; //修改调度下发的有功调节最大速率(kW/Min)
	virtual double GetMinAdjustPower() = 0;//获取调度下发的调节死区(kW)
	virtual bool ModifyMinAdjustPower(double dMinAdjustP) = 0;//修改调度下发的调节死区(kW)
	virtual int GetMaxPowerGenerateMode() = 0;//获取调度下发的自由发电控制模式。1：自由发电模式，0：功率控制模式
	virtual bool ModifyMaxPowerGenerateMode(int isMaxPGene) = 0;//修改调度下发的自由发电控制模式
	virtual double GetStartWindSpeedOfGenerator() = 0;//风力发电机的启动风速(m/s)
	virtual double GetStartLightIntensityOfGenerator() = 0;//光伏发电机的启动光照(W/m2)
	virtual bool InEmergeAvcControlling() = 0;//判断是否起用紧急AVC控制模式

	virtual double GetFreqCtrlCoef() = 0;//获取频率调差率
	virtual double GetFreqCtrlStep() = 0;//获取调频控制功率步长(kW)
	virtual double GetPLossBaseValue() = 0;//获取有功基准损耗(kVar)
	virtual double GetPOutLossRate() = 0;//获取输出有功损耗偏差
	virtual double GetPInputLossRate() = 0;//获取吸收有功损耗偏差
	virtual int GetAgcAimAbnormalActFlag() = 0;//获取AGC目标值异常是否响应
	virtual int GetAvcOnlyLocalFlag() = 0;//获取AVC本地远方压板：按位取值，位（bit）值：0--本地；1--远方
	virtual bool GetAvcLocalFlagUpdate(int& localFlag) = 0;//获取AVC本地策略压板投入标志是否变更
	virtual double GetQLossBaseValue() = 0;//获取无功基准损耗(kVar)
	virtual double GetQOutLossRate() = 0;//获取输出无功损耗偏差
	virtual double GetQInputLossRate() = 0;//获取吸收无功损耗偏差
	virtual int GetAvcAimAbnormalActFlag() = 0;//获取AVC目标值异常是否响应

};

#endif
