//istatusdao.h

#ifndef _ISTATUSDAO_PENGSHIKANG_20081204_H_
#define _ISTATUSDAO_PENGSHIKANG_20081204_H_

#include "irawdao.h"                             // for IRawDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf
#include <qmap.h>

#define STATUSDAO_CLASSID    "cstatusdao"
#define STATUSDAO_INTFID     "istatusdao"

//特殊的遥信量测量类型
//#define ISSWITCHSTATE         20101 //开关状态
#define ISFAULTSIGN           20202 //事故总信号
#define ISALARMSIGN           20203 //预告总信号
#define ISSOESIGN             80101 //SOE信号

class IStatusDao : virtual public IRawDao, virtual public ICsfAlarmIntf
{
public:	
	//设置状态量处理结果
	virtual void SetStatusDiscord(int pos) = 0;//设置双位置状态量不一致品质因素
	virtual void SetStatisticCount(int pos, int nChangeNum, int nAccidNum) = 0;//状态量变位与事故跳闸统计次数
	virtual void SetStatusBadValue(int pos, CAPP_SDO_Status* pObject, int curQualt, int surgeNum, bool writPrevValu) = 0;
	virtual void SetStatusGoodValue(int pos, CAPP_SDO_Status* pObject, int curQualt, int curValue, int nChangeNum, int nAccidNum, bool& hasGzMsg) = 0;
	
	//获取延时处理状态量个数
	virtual int GetWaitStatusCount() = 0;
	//根据ID获取状态量在延时处理列表中的位置
	virtual int GetWaitStatusPos(int nObjId) = 0;
	//输出延时处理状态量地址队列
	virtual void OutputWaitPtrList(QMap<int, int>& waitPosById) = 0;

	//根据通讯采集数据源ID得到事故总信号状态类型。psk-20140514:修改返回类型
	virtual STATUSTYPE GetFaultSignValueOfSrcId(int nSrcId) = 0;
	//根据通讯采集数据源ID清除事故总信号状态值
	virtual void ClearFaultSignValueOfSrcId(int nSrcId) = 0;
	//根据通讯采集数据源ID得到预告总信号状态类型。psk-20140514:修改返回类型
	virtual STATUSTYPE GetAlarmSignValueOfSrcId(int nSrcId) = 0;
	//根据通讯采集数据源ID清除预告总信号状态值
	virtual void ClearAlarmSignValueOfSrcId(int nSrcId) = 0;

	//根据状态量位置得到采集时间
	virtual double GetRawTime(int pos) = 0;

	//根据状态量位置得到处理标志
	virtual int GetProcessFlag(int pos) = 0;
	//根据状态量位置得到延迟报警时间
	virtual int GetDelayTime(int pos) = 0;
	
	//根据状态量位置得到上次值
	virtual int GetLastValue(int pos) = 0;
	//根据状态量位置得到上次值时间
	virtual double GetLastTime(int pos) = 0;
	//根据状态量位置设置上次值和时间
	virtual void WriteLastValueAndTime(int pos) = 0;
	
	//根据状态量位置得到光字状态
	virtual int GetGZState(int pos) = 0;
	//根据状态量位置设置光字状态
	virtual bool SetGZState(int pos, int nValue) = 0;
	
	//根据状态量位置得到振荡次数
	virtual int GetSurgeTimes(int pos) = 0;
	//根据状态量位置设置振荡次数
	virtual bool SetSurgeTimes(int pos, int nValue) = 0;
	
	//根据状态量位置得到计次报警次数统计
	virtual int GetChangeCount(int pos) = 0;
	//根据状态量位置设置计次报警次数统计
	virtual bool SetChangeCount(int pos, int nValue) = 0;
	
	//根据状态量位置得到事故跳闸次数统计
	virtual int GetFaultCount(int pos) = 0;
	//根据状态量位置设置事故跳闸次数统计
	virtual bool SetFaultCount(int pos, int nValue) = 0;
	
	//根据状态量位置得到计次报警次数限值
	virtual int GetChangeCountMax(int pos) = 0;
	//根据状态量位置得到计次超限告警动作
	virtual int GetChangeAlarmAct(int pos) = 0;
	
	//根据状态量位置得到事故跳闸次数限值
	virtual int GetFaultCountMax(int pos) = 0;
	//根据状态量位置得到事故次数超限告警动作
	virtual int GetFaultAlarmAct(int pos) = 0;
	
	//根据状态量位置得到复归超时告警时限
	virtual int GetRevertTimeLimit(int pos) = 0;
	//根据状态量位置得到复归超时告警动作
	virtual int GetRevertAlarmAct(int pos) = 0;
	
	//根据状态量位置得到当前计算值
	virtual int GetCalValue(int pos) = 0;
	//根据状态量ID得到当前计算值
	virtual int GetCalValueById(int id, bool* ok=0) = 0;
	
	//根据状态量位置得到当前状态类型。psk-20140514:添加
	virtual STATUSTYPE GetStateType(int pos) = 0;
	//根据状态量ID得到当前状态类型。
	virtual STATUSTYPE GetStateTypeById(int id, bool bRequery=false) = 0;

	virtual bool ExistBayFault(int bayId) = 0;
	virtual bool ExistBayAlarm(int bayId) = 0;
	virtual bool ExistBayGzState(int bayId) = 0;
	virtual bool ExistStationFault(int facId) = 0;
	virtual bool ExistStationAlarm(int facId) = 0;
	virtual bool ExistStationGzState(int facId) = 0;

	//根据遥信位置读取统计存储周期（用于历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
};

#endif
