// iconfiginfo.h: interface for the IConfigInfo class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICONFIGINFO_H__PENGSHIKANG_20131209__INCLUDED_
#define _ICONFIGINFO_H__PENGSHIKANG_20131209__INCLUDED_

class IConfigInfo  
{
public:
	virtual bool ReadConfigInfo() = 0;//从配置文件读取配置信息
	
	virtual const double GetOffsetPowerRatio() const = 0;//得到功率允许偏差的修正系数
	virtual const double GetMaxFrequency() const = 0;//得到可能的最高频率
	virtual const double GetMinFrequency() const = 0;//得到可能的最低频率
	virtual const double GetAMinute() const = 0;//一分钟的时间间隔

	virtual const bool IsDebug()    const = 0;//是否处于测试阶段
	virtual const bool WriteSmg()   const = 0;//是否写Smg策略日志
	virtual const bool IsTest()     const = 0;//是否为仿真控制状态
	virtual const bool FreqTest()   const = 0;//是否仿真二次调频
	virtual const bool HasSmooth()  const = 0;//平滑控制是否写日志
	virtual const bool HasStatus()  const = 0;//是否进行遥信数据处理
	virtual const bool HasAnalog()  const = 0;//是否进行遥测数据处理
	virtual const bool HasAccumu()  const = 0;//是否进行遥脉数据处理
	virtual const bool HasSoe()     const = 0;//是否进行SOE数据处理
	virtual const bool HasDumCalc() const = 0;//是否进行虚点数据计算处理
	virtual const bool HasControl() const = 0;//是否进行遥控遥调处理
	virtual const bool HasMicgrid() const = 0;//是否进行微电网数据处理
	virtual const bool HasFDTask()  const = 0;//是否加载五防处理业务
	
	virtual const float GetRateF()  const = 0;//额定频率
	virtual const float GetKGene()  const = 0;//发电机的频率调节效应系数（标幺值）
	virtual const float GetKLoad()  const = 0;//负荷的频率调节效应系数（标幺值）
	
	virtual const bool OpenConsoleLog() const = 0;//module console-log open status
	virtual const bool OpenFileLog()    const = 0;//module file-log open status

	virtual const unsigned GetAnalogCycle() const = 0;//模拟量定时主动上送周期（毫秒）
	virtual const unsigned GetStatusCycle() const = 0;//状态量定时主动上送周期（毫秒）
	virtual const unsigned GetAccumuCycle() const = 0;//累加量定时主动上送周期（毫秒）
	virtual const unsigned GetExprcalCycle() const = 0;//虚点计算量定时主动上送周期（毫秒）
	virtual const char* GetCfgGuardianor()  const = 0;//监护机1
	virtual const char* GetCfgGuardianor2() const = 0;//监护机2
	virtual const char* GetProjectName() const = 0;//项目名

	virtual const bool CompareWithCurrentTime() const = 0;//前置采集数据时间是否检测不能超出当前时间过长（1小时）
	virtual const bool AutoCtrlWaitResult() const = 0;//自动策略是否等待结果返回
	virtual const unsigned GetAutoCtrlCheckTime() const = 0;//自动策略检测结果变化的等待时间（秒）
	virtual const char* GetPowerNetType() const = 0;//电网类型名称
};

#endif

