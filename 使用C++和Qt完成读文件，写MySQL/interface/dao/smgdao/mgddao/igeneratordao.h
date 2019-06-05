//igeneratordao.h

#ifndef _IGENERATORDAO_PENGSHIKANG_20100323_H_
#define _IGENERATORDAO_PENGSHIKANG_20100323_H_

#include "imgddao.h"                             // for IMgdDao
#include "../../../icsvalue.h"                   // for intarray

#define GENERATORDAO_CLASSID    "cgeneratordao"
#define GENERATORDAO_INTFID     "igeneratordao"

class IEquipDao;
class IEquipTypeDao;

class IGeneratorDao : virtual public IMgdDao
{
public:
	//将指定位置的发电机对象加入发电机集合中
	virtual void AddObjectIntoNewGenList(int pos, intarray& list, IEquipDao* pEquip) = 0;//1,运行的可再生可调发电机
	virtual void AddObjectIntoMaxGenList(int pos, intarray& list) = 0;//2,运行的不可再生可调发电机
	virtual void AddObjectIntoCurGenList(int pos, intarray& list) = 0;//3,运行的可切除不可调发电机
	virtual void AddObjectIntoStopGenList(int pos, intarray& list) = 0;//4,停运的可投发电机
	//5,将发电机加入已按当前成本从小到大排序的对象列表中
	virtual void AddObjectIntoCostList(int pos, int* posList, int& count) = 0;
	
	//根据发电机位置更新当前启停状态			
	virtual bool UpdateRunState(int pos, int& runState) = 0;
	//根据发电机位置更新控制模式			
	virtual bool UpdateControlMode(int pos, int& modeState) = 0;
	
	//根据发电机位置得到最大有功出力
	virtual double GetMaxP(int pos) = 0;
	//根据发电机位置得到最大无功出力
	virtual double GetMaxQ(int pos) = 0;
	//根据发电机位置得到可调发电机的最小调节有功出力
	virtual double GetMinCtrlP(int pos) = 0;
	//根据发电机位置得到可调发电机的最小调节无功出力
	virtual double GetMinCtrlQ(int pos) = 0;
	//根据发电机位置得到发电机并网运行时的最优有功出力
	virtual double GetOptimumP(int pos) = 0;
	//根据发电机位置得到最快响应时间（天）
	virtual double GetRespTime(int pos) = 0;
	//根据发电机位置得到功率因素遥调ID
	virtual int GetCosCtrlID(int pos) = 0;
	//根据发电机位置得到输出有功功率的调节标志
	virtual int GetPCtrlFlag(int pos) = 0;
	//根据发电机位置得到输出无功功率的调节标志
	virtual int GetQCtrlFlag(int pos) = 0;

	//根据发电机位置得到最近一次自由停机开始时间
	virtual double GetRecentStopTime(int pos) = 0;
	//根据发电机位置设置最近一次自由停机开始时间
	virtual bool SetRecentStopTime(int pos, double startTime) = 0;
	//根据发电机位置得到最后一次动作时间
	virtual double GetRecentActTime(int pos) = 0;
	//根据发电机位置设置最后一次动作时间
    virtual bool SetRecentActTime(int pos, double actTime) = 0;
	//根据发电机位置得到日动作次数
	virtual int GetActTimesOfToday(int pos) = 0;
	//根据发电机位置增加日动作次数
	virtual bool IncreaseActTimesOfToday(int pos) = 0;
	
	//清除所有调控连续失败次数
	virtual void ClearAllFailTimes() = 0;
	//清除子微网内发电机的调控连续失败次数
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//根据发电机位置初始化动作连续失败次数。actType：0--退出；1--投入；2--全部
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//根据发电机位置增加动作连续失败次数。actType：0--退出；1--投入
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//根据发电机位置得到动作连续失败次数
	virtual int GetActFailTimes(int pos) = 0;
	//根据发电机位置判断是否可动作。actType：0--退出；1--投入；2--全部
	virtual bool CanAct(int pos, int actType) = 0;

	//根据发电机位置初始化启动连续失败次数。actType：0--复归；1--启动；2--全部
	virtual bool InitStartFailTimes(int pos, int actType) = 0;
	//根据发电机位置增加启动连续失败次数。actType：0--复归；1--启动
	virtual bool IncreaseStartFailTimes(int pos, int actType) = 0;
	//根据发电机位置得到启动连续失败次数
	virtual int GetStartFailTimes(int pos) = 0;
	//根据发电机位置判断是否可启动。actType：0--复归；1--启动；2--全部
	virtual bool CanStart(int pos, int actType) = 0;

	//根据发电机位置初始化调节连续失败次数。actType：0--有功；1--无功；2--全部
	virtual bool InitAdjustFailTimes(int pos, int actType) = 0;
	//根据发电机位置增加调节连续失败次数。actType：0--有功；1--无功
	virtual bool IncreaseAdjustFailTimes(int pos, int actType) = 0;
	//根据发电机位置得到调节连续失败次数
	virtual int GetAdjustFailTimes(int pos) = 0;
	//根据发电机位置判断是否可调节。actType：0--调节有功；1--调节无功；2--全部
	virtual bool CanAdjust(int pos, int actType) = 0;

	//根据发电机位置得到启动控制ID
	virtual int GetStartCtrlID(int pos) = 0;
	//根据发电机位置得到停止控制ID
	virtual int GetStopCtrlID(int pos) = 0;
	//根据发电机位置得到启停状态ID
	virtual int GetRunStateID(int pos) = 0;
	//根据发电机位置得到VF模式控制ID
	virtual int GetVFmodeCtrlId(int pos) = 0;
	//根据发电机位置得到PQ模式控制ID
	virtual int GetPQmodeCtrlId(int pos) = 0;
	//根据发电机位置得到控制模式状态ID
	virtual int GetModeStateID(int pos) = 0;
	
	//根据发电机位置得到发电机用途属性
	virtual int GetUseType(int pos) = 0;
	//根据发电机位置得到发电机主电源模式
	virtual int GetMainModeType(int pos) = 0;
	//根据发电机位置得到发电机启动属性
	virtual int GetStartType(int pos) = 0;
	//根据发电机位置得到发电机启动需要的时间间隔(秒)
	virtual int GetStartActTime(int pos) = 0;
	//根据发电机位置得到发电成本
	virtual double GetProductCost(int pos) = 0;
	//根据发电机位置得到有功遥调灵敏度功率值
	virtual double GetSensitivity(int pos) = 0;
	//根据发电机位置得到经济运行功率上限(%)
	virtual double GetMaxEconomicPower(int pos) = 0;
	//根据发电机位置得到经济运行功率下限(%)
	virtual double GetMinEconomicPower(int pos) = 0;
	//获得发电设备属性
	virtual int GetGenType(int pos) = 0;

	//根据发电机位置得到当前VF控制模式
	virtual int GetCurVFModStat(int pos) = 0;   
	//根据发电机位置设置当前VF控制模式
	virtual bool SetCurVFModStat(int pos, int mode) = 0;   
	//根据发电机位置得到当前是否正在抑制出力
    virtual int GetRestrictedFlag(int pos) = 0;
	
	//根据发电机位置得到启动后至少连续运行时间(分钟)
	virtual int GetRunSpanlmt(int pos) = 0;
	//根据发电机位置得到停机后至少停留时间(分钟)
	virtual int GetStopSpanlmt(int pos) = 0;

	//根据发电机位置得到当前发电机启停状态
	virtual int GetCurRunState(int pos) = 0;   
	//根据发电机位置设置当前发电机启停状态
	virtual bool SetCurRunState(int pos, int runState) = 0;   

	//根据发电机位置判断设备是否为可再生能源发电设备
	virtual bool IsRenewable(int pos, IEquipDao* pEquip, IEquipTypeDao* pEqpType) = 0;
	//根据发电机位置判断当前发电机是否为风力发电机
	virtual bool IsWindGen(int pos, IEquipDao* pEquip) = 0;
	//根据发电机位置判断当前发电机是否投入
	virtual bool IsAdded(int pos, bool bRefresh=false) = 0;
	//根据发电机位置判断当前发电机是否启动
	virtual bool IsStarted(int pos, IEquipDao* pEquip=0) = 0;
	//根据发电机位置判断当前发电机是否停机
	virtual bool IsStopped(int pos, IEquipDao* pEquip=0) = 0;
	//根据发电机位置判断当前发电机是否处于主发电机模式
	virtual bool IsMainMode(int pos) = 0;

	//根据发电机位置得到发电机调节系数
	virtual double GetGenAdjustCoef(int pos) = 0;
	//判断指定位置的发电机是否由策略自动切断
	virtual bool GetAutoCutFlag(int pos) = 0;
	//设置指定位置的发电机是否由策略自动切断
	virtual bool SetAutoCutFlag(int pos, bool autoCut=true) = 0;
	//根据发电机位置得到抗冲击倍数
	virtual double GetAntiImpactRatio(int pos) = 0;
	//根据发电机位置得到备用有功功率
	virtual double GetBackupPower(int pos) = 0;

	//根据发电机位置得到启动冲击电流倍数
	virtual double GetStartImpactRatio(int pos) = 0;
	//根据发电机位置得到故障复归控制量ID
	virtual int GetRevertCtrlId(int pos) = 0;  
	//根据发电机位置得到机端电压遥测ID
	virtual int GetGenVolId(int pos) = 0;       
	//根据发电机位置得到机端频率遥测IDs
	virtual int GetGenFreqId(int pos) = 0;        
	//根据发电机位置得到当前机端电压
	virtual double GetGeneratorVoltage(int pos) = 0;          
	//根据发电机位置得到当前机端频率
	virtual double GetGeneratorFrequency(int pos) = 0;  
	//根据发电机位置更新机端电压频率			
	virtual void UpdateGenUF(int pos) = 0;
	//根据发电机位置设置当前电压和频率为正常值[测试用]
	virtual bool TestUFtoNormal(int pos, double rateF) = 0;

	//判断指定位置的发电机是否人工闭锁了投入操作
	virtual bool ManuLockAdd(int pos) = 0;
	//判断指定位置的发电机是否人工闭锁了切除操作
	virtual bool ManuLockCut(int pos) = 0;

	//判断指定位置的发电机的连续运行时间是否达到要求
	virtual bool CheckRunTimeSpan(int pos, double curTime) = 0;
	//判断指定位置的发电机的连续停机时间是否达到要求
	virtual bool CheckStopTimeSpan(int pos, double curTime) = 0;
	//判断指定位置的发电机的连续自由停机时间是否达到要求
	virtual bool CheckAutoStopTimeSpan(int pos, double curTime) = 0;

	//根据发电机位置得到并网待机状态遥信ID
	virtual int GetStandbyStatusId(int pos) = 0;
	//根据发电机位置判断是否处于并网待机状态
	virtual bool IsStandbyState(int pos) = 0;

	//根据发电机位置更新运行信息
	virtual void UpdateRunInfo(int pos) = 0;

	//根据发电机位置得到有功调节目标值遥测ID
	virtual int GetCtrlAimPId(int pos) = 0;
	//根据发电机位置得到无功调节目标值遥测ID
	virtual int GetCtrlAimQId(int pos) = 0;

	//计算发电机的综合运行状态
	virtual RUNSTATETYPE CalcCurRunStateType(int pos, bool& canAdjust, IEquipDao* pEquip, int* eqpPos=0) = 0;
	//根据发电机位置得到当前发电机运行状态类型
	virtual RUNSTATETYPE GetCurRunStateType(int pos) = 0;
	//根据发电机位置设置当前发电机运行状态类型
	virtual bool SetCurRunStateType(int pos, RUNSTATETYPE runType) = 0;

	//根据发电机位置判断是否处于输出最大功率的运行状态
	virtual bool IsMaxPowerRunState(int pos) = 0;

	//得到发电量遥测ID字段类型
	virtual FIELDTYPE GetGenEnergyIdType() = 0;       
	//根据发电机位置得到累计发电量遥测ID字段指针
	virtual void GetGenEnergyIdPoint(int pos, void* pTodayWId, void* pTotalWId) = 0;        
	//根据发电机位置得到今日发电量
	virtual double GetTodayEnergy(int pos) = 0;          
	//根据发电机位置得到累计发电量
	virtual double GetTotalEnergy(int pos) = 0;  
	//根据发电机位置更新今日发电量和累计发电量
	virtual void UpdateGenEnergy(int pos, double todayW, double totalW) = 0;

	//根据发电机位置判断是否可调节有功功率
	virtual bool CanAdjustP(int pos) = 0;
	//根据发电机位置判断是否可调节无功功率
	virtual bool CanAdjustQ(int pos) = 0;

	//根据发电机位置判断是否可增加发电机的有功出力。
	//参数：maxP--发电机实际能达到的最大有功出力；incP--发电机可调节增加的有功出力。
	virtual bool CanIncreasePValue(int pos, double& maxP, double& incP) = 0;
	//根据发电机位置判断是否可调节发电机的无功出力。
	//参数：minQ--发电机的最小无功出力；maxQ--发电机的最大无功出力；curQ--发电机的当前无功出力。
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;

	//根据发电机位置得到无功遥调灵敏度功率值
	virtual double GetSensitivityQ(int pos) = 0;
	//根据发电机位置读取统计存储周期ID（用于历史存储）
	virtual int GetSaveTimerID(int pos) = 0;

	virtual void AddObjectIntoActTimeGenList(int pos, intarray& list) = 0;//6,按动作时间从早到晚排序的发电机

	//根据发电机位置判断当前发电机是否为光伏发电机
	virtual bool IsPVGen(int pos, IEquipDao* pEquip) = 0;

	//根据发电机位置判断当前发电机在启动前是否需要设置最小启动功率
	virtual bool NeedAdjustPowerBeforeStart(int pos, IEquipDao* pEquip) = 0;

	virtual void AddObjectIntoIncQGenList(int pos, intarray& list) = 0;//7,按可增无功功率从大到小排序的发电机
	virtual void AddObjectIntoDecQGenList(int pos, intarray& list) = 0;//8,按可减无功功率从大到小排序的发电机
	virtual void AddObjectIntoVoltGenList(int id, intarray& list, IEquipDao* pEquip) = 0;//9,按机端电压从高到低排序的发电机

	//根据发电机位置得到限电状态遥信ID
	virtual int GetRestrictStatusId(int pos) = 0;
	//根据发电机位置判断是否处于限电状态
	virtual bool IsRestrictState(int pos) = 0;
	//根据发电机位置得到发电设备型号ID
	virtual int GetGeneratorModeId(int pos) = 0;

	//根据发电机位置得到按百分比调节时的基准无功出力
	virtual double GetBaseQ(int pos) = 0;

	//保存所有发电机的当前发电机运行状态类型
	virtual void SaveCurRunStateType() = 0;

};

#endif
