//igeneratorgroupdao.h

#ifndef _IGENERATORGROUPDAO_PENGSHIKANG_20170106_H_
#define _IGENERATORGROUPDAO_PENGSHIKANG_20170106_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../icsvalue.h"                   // for intarray

#define GENERATORGROUPDAO_CLASSID    "cgeneratorgroupdao"
#define GENERATORGROUPDAO_INTFID     "igeneratorgroupdao"

class IEquipDao;
class IEquipTypeDao;

class IGeneratorGroupDao : virtual public IBasicDao
{
public:
	//将指定位置的发电机机群对象加入发电机机群集合中
	virtual void AddObjectIntoGenGroupList(int pos, intarray& list) = 0;
	//根据发电机机群位置得到所连母线ID
	virtual int GetBusID(int pos) = 0;
	//根据发电机机群位置得到自身的微网ID
	virtual int GetSelfMicgridID(int pos) = 0;
	//根据发电机机群位置得到并网点电压遥测ID
	virtual int GetUID(int pos) = 0;
	//根据发电机机群位置得到总有功遥测ID
	virtual int GetPID(int pos) = 0;
	//根据发电机机群位置得到总无功遥测ID
	virtual int GetQID(int pos) = 0;
	//根据发电机机群位置得到有功反馈值遥测ID
	virtual int GetBckPID(int pos) = 0;
	//根据发电机机群位置得到无功反馈值遥测ID
	virtual int GetBckQID(int pos) = 0;
	//根据发电机机群位置得到最大有功出力遥测ID
	virtual int GetMaxPID(int pos) = 0;
	//根据发电机机群位置得到最大无功出力遥测ID
	virtual int GetMaxQID(int pos) = 0;
	//根据发电机机群位置得到最小有功出力遥测ID
	virtual int GetMinPID(int pos) = 0;
	//根据发电机机群位置得到最小无功出力遥测ID
	virtual int GetMinQID(int pos) = 0;

	//根据发电机机群位置得到远方就地压板ID
	virtual int GetFarFlagID(int pos) = 0;
	//根据发电机机群位置得到有功调节压板ID
	virtual int GetPFlagID(int pos) = 0;  
	//根据发电机机群位置得到无功调节压板ID
	virtual int GetQFlagID(int pos) = 0;  
	//根据发电机机群位置得到可增有功遥测ID
	virtual int GetIncPID(int pos) = 0;   
	//根据发电机机群位置得到可增无功遥测ID
	virtual int GetIncQID(int pos) = 0;   
	//根据发电机机群位置得到可减有功遥测ID
	virtual int GetDecPID(int pos) = 0;   
	//根据发电机机群位置得到可减无功遥测ID
	virtual int GetDecQID(int pos) = 0;   
	//根据发电机机群位置得到动态可增无功遥测ID
	virtual int GetDyIncQID(int pos) = 0; 
	//根据发电机机群位置得到动态可减无功遥测ID
	virtual int GetDyDecQID(int pos) = 0; 
	//根据发电机机群位置得到运行容量ID
	virtual int GetRunCapID(int pos) = 0; 
	//根据发电机机群位置得到有功可调容量ID
	virtual int GetCtrlCapID(int pos) = 0;

	//根据发电机机群位置得到功率流向方向
	virtual bool DispatchPIsOutput(int pos) = 0;
	//根据发电机机群位置得到功率单位
	virtual bool DispatchPInMW(int pos) = 0;

	//根据发电机机群位置得到数据通道连通状态
	virtual int GetSrcConnectState(int pos) = 0;
	//根据发电机机群位置设置数据通道连通状态
	virtual bool SeSrcConnectState(int pos, int srcState) = 0;

	//根据发电机机群位置得到当前电压标幺值
	virtual double GetRateVoltage(int pos) = 0;
	//根据发电机机群位置设置当前电压标幺值
	virtual double SetRateVoltage(int pos, double dRateVolt) = 0;
	//根据发电机机群位置得到当前电压有名值
	virtual double GetRealVoltage(int pos) = 0;


	//根据发电机机群位置得到控制计划有功功率
	virtual double GetPlanP(int pos) = 0;
	//根据发电机机群位置设置控制计划有功功率
	virtual bool SetPlanP(int pos, double planP) = 0;
	//根据发电机机群位置得到控制计划无功功率
	virtual double GetPlanQ(int pos) = 0;
	//根据发电机机群位置设置控制计划无功出力
	virtual bool SetPlanQ(int pos, double planQ) = 0;

	//根据发电机机群位置得到当前有功出力
	virtual double GetCurP(int pos) = 0;
	//根据发电机机群位置得到当前无功出力
	virtual double GetCurQ(int pos) = 0;
	//根据发电机机群位置得到当前有功反馈值
	virtual double GetBackP(int pos) = 0;
	//根据发电机机群位置得到当前无功反馈值
	virtual double GetBackQ(int pos) = 0;
	//根据发电机机群位置得到当前最大有功出力
	virtual double GetMaxP(int pos) = 0;
	//根据发电机机群位置得到当前最大无功出力
	virtual double GetMaxQ(int pos) = 0;
	//根据发电机机群位置得到当前最小有功出力
	virtual double GetMinP(int pos) = 0;
	//根据发电机机群位置得到当前最小无功出力
	virtual double GetMinQ(int pos) = 0;

	//根据发电机机群位置得到当前远方就地压板
	virtual int GetFarFlag(int pos) = 0;
	//根据发电机机群位置得到输出有功功率调节的使能压板
	virtual int GetPCtrlFlag(int pos) = 0;
	//根据发电机机群位置得到输出无功功率调节的使能压板
	virtual int GetQCtrlFlag(int pos) = 0;
	//根据发电机机群位置得到当前可增有功出力
	virtual double GetCanIncP(int pos) = 0;
	//根据发电机机群位置得到当前可增无功出力
	virtual double GetCanIncQ(int pos) = 0;
	//根据发电机机群位置得到当前可减有功出力
	virtual double GetCanDecP(int pos) = 0;
	//根据发电机机群位置得到当前可减无功出力
	virtual double GetCanDecQ(int pos) = 0;
	//根据发电机机群位置得到当前动态可增无功出力
	virtual double GetCanIncDynQ(int pos) = 0;
	//根据发电机机群位置得到当前动态可减无功出力
	virtual double GetCanDecDynQ(int pos) = 0;
	//根据发电机机群位置得到当前运行容量
	virtual double GetCapacity(int pos) = 0;
	//根据发电机机群位置得到当前有功可调容量
	virtual double GetAdjPwrCapa(int pos) = 0;

	//根据发电机机群位置得到上次有功控制时间
	virtual double GetPCtrlTime(int pos) = 0;
	//根据发电机机群位置得到上次无功控制时间
	virtual double GetQCtrlTime(int pos) = 0;
	//根据发电机机群位置得到上次有功失败闭锁时间
	virtual double GetPLockTime(int pos) = 0;
	//根据发电机机群位置得到上次无功失败闭锁时间
	virtual double GetQLockTime(int pos) = 0;

	//根据发电机机群位置设置上次有功控制时间
	virtual bool SetPCtrlTime(int pos, double dPCtrlTime) = 0;
	//根据发电机机群位置设置上次无功控制时间
	virtual bool SetQCtrlTime(int pos, double dQCtrlTime) = 0;
	//根据发电机机群位置设置上次有功失败闭锁时间
	virtual bool SetPLockTime(int pos, double dPLockTime) = 0;
	//根据发电机机群位置设置上次无功失败闭锁时间
	virtual bool SetQLockTime(int pos, double dQLockTime) = 0;

	//清除所有调控连续失败次数
	virtual void ClearAllFailTimes() = 0;
	//清除子微网内发电机的调控连续失败次数
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;
	//根据发电机机群位置初始化调节连续失败次数。actType：0--有功；1--无功；2--全部
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//根据发电机机群位置增加调节连续失败次数。actType：0--有功；1--无功
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//根据发电机机群位置得到调节连续失败次数。actType：0--有功；1--无功
	virtual int GetAdjustFailTimes(int pos, int actType) = 0;
	//根据发电机机群位置判断是否可调节。actType：0--调节有功；1--调节无功；2--全部
	virtual bool CanAdjust(int pos, int actType) = 0;


	//根据发电机机群位置更新运行信息
	virtual void UpdateRunInfo(int pos) = 0;
	//根据发电机机群位置判断是否处于输出最大功率的运行状态
	virtual bool IsMaxPowerRunState(int pos) = 0;

	//根据发电机机群位置判断是否可调节有功功率
	virtual bool CanAdjustP(int pos) = 0;
	//根据发电机机群位置判断是否可调节无功功率
	virtual bool CanAdjustQ(int pos) = 0;

	//根据发电机机群位置判断是否可增加发电机的有功出力。
	//参数：maxP--发电机实际能达到的最大有功出力；incP--发电机可调节增加的有功出力。
	virtual bool CanIncreasePValue(int pos, double& maxP, double& incP) = 0;
	//根据发电机机群位置判断是否可调节发电机的无功出力。
	//参数：minQ--发电机的最小无功出力；maxQ--发电机的最大无功出力；curQ--发电机的当前无功出力。
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;

	//根据发电机机群位置得到有功遥调ID
	virtual int GetPCtrlID(int pos) = 0;
	//根据发电机机群位置得到无功遥调ID
	virtual int GetQCtrlID(int pos) = 0;

};

#endif
