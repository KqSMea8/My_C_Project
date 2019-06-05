//ianalogdao.h

#ifndef _IANALOGDAO_PENGSHIKANG_20081202_H_
#define _IANALOGDAO_PENGSHIKANG_20081202_H_

#include "irawdao.h"                             // for IRawDao
#include "icsfalmintf.h"                         // for ICsfAlarmIntf

#define ANALOGDAO_CLASSID    "canalogdao"
#define ANALOGDAO_INTFID     "ianalogldao"

class IAnalogDao : virtual public IRawDao, virtual public ICsfAlarmIntf
{
public:	
	//设置模拟量的采样值和品质因素
	virtual void SetAnalogValue(int nAnlgPos, int nSrcId, int nPntId, 
								double curTime, double rawValue, int curQualt) = 0;
	//设置模拟量处理结果
	virtual void SetAnalogValue(int nAnlgPos, int nSrcId, int nPntId, 
								double curTime, double rawValue, double calValue, int curQualt) = 0;
	
	//根据模拟量位置得到度量单位
	virtual int GetMeasUnit(int pos) = 0;
	//根据模拟量位置得到处理标志
	virtual int GetProcessFlag(int pos) = 0;
	//根据模拟量位置得到乘系数
	virtual double GetScaleFactor(int pos) = 0;
	//根据模拟量位置得到加系数
	virtual double GetOffset(int pos) = 0;
	//根据模拟量位置得到零漂死区值
	virtual double GetZeroDb(int pos) = 0;

	//根据模拟量位置得到变化死区值(%)
	virtual double GetDiffDb(int pos) = 0;
	//根据模拟量位置得到不变数据时间门限值
	virtual int GetOlddataTimeLmt(int pos) = 0;
	
	//根据模拟量位置得到物理量程上限
	virtual double GetMaxValue(int pos) = 0;
	//根据模拟量位置得到物理量程下限
	virtual double GetMinValue(int pos) = 0;
	//判断当前值是否为正常值
	virtual bool IsNormalValue(int pos, double curVal) = 0;
	
	//根据模拟量位置得到合格上限值
	virtual double GetQualifyUpperValue(int pos) = 0;
	//根据模拟量位置得到合格下限值
	virtual double GetQualifyLowerValue(int pos) = 0;
	//判断当前值是否为合格值
	virtual bool IsQualifyValue(int pos, double curVal) = 0;

	//根据模拟量位置得到是否采用限值类型
	virtual int GetUseLimitTypeFlag(int pos) = 0;
	//根据模拟量位置得到越限类型ID
	virtual int GetLimitType(int pos) = 0;
	//根据模拟量位置得到跳变类型ID
	virtual int GetAbruptType(int pos) = 0;
	//根据模拟量位置得到越限报警延迟时间
	virtual int GetDelayTime(int pos) = 0;
	//根据模拟量位置得到越限恢复死区
	virtual double GetDeadZone(int pos) = 0;
	//根据模拟量位置得到越限报警的上限值
	virtual double GetUpperValue(int pos) = 0;
	//根据模拟量位置得到越限报警的下限值
	virtual double GetLowerValue(int pos) = 0;
	//根据模拟量位置得到越上限告警动作掩码
	virtual int GetUpperAct(int pos) = 0;
	//根据模拟量位置得到越下限告警动作掩码
	virtual int GetLowerAct(int pos) = 0;

	//根据模拟量位置得到数据值越限状态
	virtual int GetAlarmState(int pos) = 0;
	//根据模拟量位置设置数据值越限状态
	virtual bool SetAlarmState(int pos, int nValue) = 0;
	
	//根据模拟量位置得到数据值跳变状态
	virtual int GetAbruptState(int pos) = 0;
	//根据模拟量位置设置数据值跳变状态
	virtual bool SetAbruptState(int pos, int nValue) = 0;
	
	//根据模拟量位置得到越限时间间隔
	virtual int GetExcepTime(int pos, bool isUULL=false) = 0;
	//根据模拟量位置设置越限时间间隔
	virtual bool SetExcepTime(int pos, int nValue, bool isUULL=false) = 0;
	//根据模拟量位置累加越限时间间隔
	virtual int AddExcepTime(int pos, int nValue, bool isUULL=false) = 0;
	
	//根据模拟量位置得到数据不变时间间隔
	virtual int GetUnchangeTime(int pos) = 0;
	//根据模拟量位置设置数据不变时间间隔
	virtual bool SetUnchangeTime(int pos, int nValue) = 0;
	//根据模拟量位置累加数据不变时间间隔
	virtual void AddUnchangeTime(int pos, int nValue) = 0;
	
	//根据模拟量位置得到跳变时间间隔
	virtual int GetAbruptTime(int pos) = 0;
	//根据模拟量位置设置跳变时间间隔
	virtual bool SetAbruptTime(int pos, int nValue) = 0;
	//根据模拟量位置累加跳变时间间隔
	virtual void AddAbruptTime(int pos, int nValue) = 0;
	
	//根据模拟量位置得到计算值
	virtual double GetCalValue(int pos) = 0;
	//根据模拟量ID得到计算值
	virtual double GetCalValueById(int id, bool* ok=0) = 0;

	//根据模拟量位置设置越限报警状态
	virtual void SetAlarmStateInfo(int pos, int nAlmState, int nExcpTime1, int nExcpTime2) = 0;
	//根据模拟量位置设置无越限报警状态
	virtual void SetNormalStateInfo(int pos) = 0;

	virtual bool TestControlChange(int id, float incValue, float* rsltValue=0) = 0;	

	//根据模拟量位置得到双量测差额告警定值
	virtual double GetMaxRawOffset(int pos) = 0;
};

#endif
