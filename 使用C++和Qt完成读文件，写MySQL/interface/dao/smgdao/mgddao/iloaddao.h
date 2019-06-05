//iloaddao.h

#ifndef _ILOADDAO_PENGSHIKANG_20100323_H_
#define _ILOADDAO_PENGSHIKANG_20100323_H_

#include "imgddao.h"                             // for IMgdDao

#define LOADDAO_CLASSID    "cloaddao"
#define LOADDAO_INTFID     "iloaddao"

class ILoadDao : virtual public IMgdDao
{
public:
	//根据负荷位置得到保电优先级
	virtual int GetPriority(int pos) = 0;

	//根据负荷位置得到被停电次数
	virtual int GetCutTimes(int pos) = 0;
	//根据负荷位置增加被停电次数
	virtual bool IncreaseCutTimes(int pos, double cutTime) = 0;

	//根据负荷位置得到上次停电时间
	virtual double GetLastCutTime(int pos) = 0;
	//根据负荷位置设置上次停电时间
	virtual bool SetLastCutTime(int pos, double cutTime) = 0;

	//清除所有调控连续失败次数
	virtual void ClearAllFailTimes() = 0;
	//清除子微网内负荷的调控连续失败次数
	virtual void ClearAllFailTimesInMicgrid(int mgId) = 0;
	//初始化动作连续失败次数。actType：0--退出；1--投入；2--全部
	virtual bool InitActFailTimes(int pos, int actType) = 0;
	//根据负荷位置增加动作连续失败次数。actType：0--退出；1--投入
	virtual bool IncreaseActFailTimes(int pos, int actType) = 0;
	//根据负荷位置得到动作连续失败次数
	virtual int GetActFailTimes(int pos) = 0;
	//判断指定位置的负荷是否可动作。actType：0--退出；1--投入；2--全部
	virtual int CanAct(int pos, int actType, int& cutCtrlId, int& addCtrlId) = 0;

	//判断指定位置的负荷是否由策略自动切断
	virtual bool GetAutoCutFlag(int pos) = 0;
	//设置指定位置的负荷是否由策略自动切断
	virtual bool SetAutoCutFlag(int pos, bool autoCut=true) = 0;
	//根据负荷位置得到启动冲击电流倍数
	virtual double GetStartImpactRatio(int pos) = 0;

	//判断指定位置的负荷是否人工闭锁了投入操作
	virtual bool ManuLockAdd(int pos, int& ctrlId) = 0;
	//判断指定位置的负荷是否人工闭锁了切除操作
	virtual bool ManuLockCut(int pos, int& ctrlId) = 0;

	//对指定位置的负荷执行人工闭锁自动投入操作
	virtual bool DoManuLockAdd(int pos) = 0;

};

#endif
