//icontroldao.h

#ifndef _ICONTROLDAO_PENGSHIKANG_20100323_H_
#define _ICONTROLDAO_PENGSHIKANG_20100323_H_

#include "icsfdao.h"                              // for ICsfDao

#define CONTROLDAO_CLASSID    "ccontroldao"
#define CONTROLDAO_INTFID     "icontroldao"

class IControlDao : virtual public ICsfDao
{
public:
	//根据控制量位置得到控制处理标志
	virtual int GetProcessFlag(int pos) = 0;
	//根据控制量位置得到控制类型
	virtual int GetCtrlType(int pos) = 0;
	//根据控制量位置得到控制组ID
	virtual int GetCtrlGroupId(int pos) = 0;
	
	//根据控制量位置得到闭锁条件表达式
	virtual const char* GetLockExpCal(int pos) = 0;
	
	//根据关联的对象ID得到控制量ID
	virtual int GetControlIdByRelationObject(int relatType, int objId) = 0;
	//根据控制量位置得到关联量测量类型
	virtual int GetRelationType(int pos) = 0;
	//根据控制量位置得到关联对象ID
	virtual int GetRelationObjectId(int pos) = 0;
	//根据控制量位置得到关联的状态量ID
	virtual int GetRelationStatusId(int pos) = 0;
	//根据控制量ID得到关联的状态量ID
	virtual int GetRelationStatusIdByID(int id) = 0;
	
	//根据控制量位置得到最大控制操作次数
	virtual int GetMaxCtrlCount(int pos) = 0;

	//根据控制量位置得到操作超时时限
	virtual int GetOprTimeLimit(int pos) = 0;

	//根据控制量位置得到控制操作次数
	virtual int GetCurCtrlCount(int pos) = 0;

	//根据控制量位置得到五防允许遥控标志
	virtual int GetWfFlag(int pos) = 0;
	//根据控制量位置设置五防允许遥控标志
	virtual bool SetWfFlag(int pos, int wfFlag) = 0;
	
	//根据控制量位置得到最后一次成功控制值
	virtual double GetLastControlValue(int pos) = 0;
	//根据控制量位置设置最后一次成功控制值
	virtual bool SetLastControlValue(int pos, double ctrlVal) = 0;
	
	//根据控制量位置记录本次控制操作
	virtual bool RecordCurCtrlCount(int pos, double oprTime) = 0;
	//根据控制量位置记录成功的控制操作
	virtual bool RecordSucCtrlCount(int pos, double oprTime, double ctrlVal) = 0;
	
	//得到指定控制组中控制量的个数
	virtual int GetControlCountByGroupId(int groupId) = 0;
	//得到指定控制组中控制量ID数组
	virtual const int* GetControlIdSetByGroupId(int groupId) = 0;
	//得到指定控制组中指定元素的控制量ID
	virtual int GetControlIdByGroupIndex(int groupId, int index) = 0;	

	//根据控制量位置判断是否人工操作闭锁  sunr add
	virtual bool IsManuLock(int pos) = 0;
	//根据前置上传量位置设置人工操作闭锁标志  sunr add
	virtual bool SetManuLockFlag(int pos, bool bManuLock) = 0;
	//根据控制量ID判断是否处于闭锁中
	virtual bool InManuLockingById(int id) = 0;

	//根据控制量位置得到遥控双编码
	virtual const char* GetDoubleCode(int pos) = 0;
	
	//根据控制量ID得到最后一次控制时间
	virtual double GetLastControlTimeByID(int id) = 0;

	//根据控制量位置得到当前控制值对应遥测[期望值]ID
	virtual int GetRealCtrlValueAnlgID(int pos) = 0;

	//根据控制量ID记录最后一次控制时间
	virtual bool SetLastControlTimeByID(int id, double oprTime) = 0;

	//根据控制量位置得到最后一次成功控制时间
	virtual double GetLastControlTime(int pos) = 0;
	//根据控制量位置得到今日成功控制操作次数
	virtual int GetTodaySucCtrlCount(int pos) = 0;

	//清除最后一次控制时间[置零]
	virtual void ClearLastControlTime() = 0;
};

#endif
