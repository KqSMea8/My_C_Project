//ireactcompdao.h

#ifndef _IREACTIVECOMPOMENTDAO_PENGSHIKANG_20120511_H_
#define _IREACTIVECOMPOMENTDAO_PENGSHIKANG_20120511_H_

#include "imgddao.h"                             // for IMgdDao
#include "../../../icsvalue.h"                   // for intarray

#define REACTIVECOMPOMENTDAO_CLASSID    "creactcompdao"
#define REACTIVECOMPOMENTDAO_INTFID     "ireactcompdao"

class IReactCompDao : virtual public IMgdDao
{
public:
	//将指定位置的无功补偿设备对象加入可调节无功补偿设备集合中
	virtual void AddObjectIntoMaxQList(int pos, double power, intarray& list) = 0;
	
	//根据无功补偿设备位置得到补偿设备类型
	virtual int GetCompType(int pos) = 0;
	//根据无功补偿设备位置得到最大无功出力
	virtual double GetMaxQ(int pos) = 0;
	//根据无功补偿设备位置得到最小调节无功出力
	virtual double GetMinCtrlQ(int pos) = 0;
	//根据无功补偿设备位置得到输出无功功率的调节标志
	virtual int GetQCtrlFlag(int pos) = 0;
	//根据无功补偿设备位置得到串联电抗率
	virtual double GetReactiveRate(int pos) = 0;
	
	//根据无功补偿设备位置得到投到切动作时间间隔
	virtual int GetMinQuitTimeSpan(int pos) = 0;
	//根据无功补偿设备位置得到切到投动作时间间隔
	virtual int GetMinJoinTimeSpan(int pos) = 0;
	
	//根据无功补偿设备位置得到最后一次动作时间
	virtual double GetRecentActTime(int pos) = 0;
	//根据发电机位置设置最后一次动作时间
	virtual bool SetRecentActTime(int pos, double actTime) = 0;
	//根据无功补偿设备位置得到日动作次数
	virtual int GetActTimesOfToday(int pos) = 0;
	//根据无功补偿设备位置增加日动作次数
	virtual bool IncreaseActTimesOfToday(int pos) = 0;
	
	//清除所有调控连续失败次数
	virtual void ClearAllFailTimes() = 0;
	//清除子微网内无功补偿设备的调控连续失败次数
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;

	//根据无功补偿设备位置初始化动作连续失败次数。actType：0--退出；1--投入；2--全部
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//根据无功补偿设备位置增加动作连续失败次数。actType：0--退出；1--投入
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//根据无功补偿设备位置得到动作连续失败次数
	virtual int GetActFailTimes(int pos) = 0;
	//根据无功补偿设备位置判断是否可动作。actType：0--退出；1--投入；2--全部
	virtual int CanAct(int pos, int actType, int& cutCtrlId, int& addCtrlId) = 0;

	//根据无功补偿设备位置初始化调节连续失败次数。
	virtual bool InitAdjustFailTimes(int pos) = 0;
	//根据无功补偿设备位置增加调节连续失败次数。
	virtual bool IncreaseAdjustFailTimes(int pos) = 0;
	//根据无功补偿设备位置得到调节连续失败次数
	virtual int GetAdjustFailTimes(int pos) = 0;
	//根据无功补偿设备位置判断是否可调节无功功率。
	virtual bool CanAdjust(int pos) = 0;
	
	//根据无功补偿设备位置得到由策略自动切除标志
	virtual bool GetAutoCutFlag(int pos) = 0;
	//根据无功补偿设备位置设置由策略自动切除标志
	virtual bool SetAutoCutFlag(int pos, bool bCut) = 0;

	//根据无功补偿设备位置得到零值死区
	virtual double GetZeroValueLmt(int pos) = 0;
	//根据无功补偿设备位置得到无功遥调灵敏度功率值
	virtual double GetSensitivityQ(int pos) = 0;
	//根据无功补偿设备位置得到故障复归控制量ID
	virtual int GetRevertCtrlId(int pos) = 0;
	//根据无功补偿设备位置得到SVG启停状态ID
	virtual int GetRunStateID(int pos) = 0;
	//根据无功补偿设备位置得到当前SVG启停状态
	virtual int GetCurRunState(int pos) = 0;
	//根据无功补偿设备位置设置当前SVG启停状态
	virtual bool SetCurRunState(int pos, int runState) = 0;
	//根据无功补偿设备位置更新运行信息
	virtual void UpdateRunInfo(int pos, bool& canCtrl) = 0;
	//根据无功补偿设备位置判断当前储能是否启动
	virtual bool IsStarted(int pos) = 0;

	//判断指定位置的无功补偿设备是否人工闭锁了投入操作
	virtual bool ManuLockAdd(int pos, int& ctrlId) = 0;
	//判断指定位置的无功补偿设备是否人工闭锁了切除操作
	virtual bool ManuLockCut(int pos, int& ctrlId) = 0;

	//判断指定位置的无功补偿设备的连续运行时间是否达到要求
	virtual bool CheckRunTimeSpan(int pos, double curTime) = 0;
	//判断指定位置的无功补偿设备的连续停机时间是否达到要求
	virtual bool CheckStopTimeSpan(int pos, double curTime) = 0;
	//根据无功补偿设备位置得到日动作最大次数
	virtual int GetMaxActTimesOfADay(int pos) = 0;

	//根据无功补偿设备位置得到当前位置得到控制模式状态ID
	virtual int GetModeStateID(int pos) = 0;
	//根据无功补偿设备位置得到当前VF控制模式。//12--ST_MOD_VF：VF模式；13--ST_MOD_PQ：PQ模式。
	virtual int GetCurVFModStat(int pos) = 0;
	//根据无功补偿设备位置设置当前VF控制模式。//12--ST_MOD_VF：VF模式；13--ST_MOD_PQ：PQ模式。
	virtual bool SetCurVFModStat(int pos, int mode) = 0;

	//根据无功补偿设备位置判断是否可调节无功功率
	virtual bool CanAdjustQ(int pos) = 0;
	//根据无功补偿设备位置判断是否可调节无功补偿设备的出力。
	//参数：maxQ--无补设备的最小出力；maxQ--无补设备的最大出力；curQ--无补设备的当前出力。
	virtual bool CanIncreaseQValue(int pos, double& minQ, double& maxQ, double& curQ) = 0;
	//根据无功补偿设备位置得到VF模式控制ID
	virtual int GetVFmodeCtrlId(int pos) = 0;

	//根据无功补偿设备位置获取SVG的稳定无功出力及其对应的时间
	virtual bool GetBaseValueAndTime(int pos, double& baseValue, double& baseTime) = 0;
	//根据无功补偿设备位置设置SVG的稳定无功出力及其对应的时间
	virtual bool SetBaseValueAndTime(int pos, double baseValue, double baseTime) = 0;

};

#endif
