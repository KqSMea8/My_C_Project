//istrgstdao.h

#ifndef _ISTRGSTDAO_20190531_YANGZHENYU_H_
#define _ISTRGSTDAO_20190531_YANGZHENYU_H_

#include "../ibasicdao.h"                             // for IMgdDao

#define STRGSTDAO_CLASSID    "cstrgstdao"
#define STRGSTDAO_INTFID     "istrgstdao"


class IStrgstdao : virtual public IBasicDao
{
public:	
	//静态
	//根据储能电站位置得到储能站电池配置容量
	virtual double GetStBatCapacity(int pos) = 0;

	//根据储能电站位置得到储能站经济调度最大剩余容量
	virtual double GetConMaxCap(int pos) = 0;

	//根据储能电站位置得到储能站经济调度最小剩余容量
	virtual double GetConMinCap(int pos) = 0;

	//根据储能电站位置得到储能站允许最大剩余容量
	virtual double GetExchMaxCap(int pos) = 0;

	//根据储能电站位置得到储能站允许最小剩余容量
	virtual double GetDisconMinCap(int pos) = 0;

	//根据储能电站位置得到剩余容量SOCID
	virtual int GetSocId(int pos) = 0;

	//根据储能电站位置得到储能充放电总有功ID
	virtual int GetStoragePid(int pos) = 0;

	//根据储能电站位置得到储能充放电无功ID
	virtual int GetStorageQid(int pos) = 0;

	//根据储能电站位置得到全站SOHID
	virtual int GetSohId(int pos) = 0;

	//根据储能电站位置得到全站电池平均温度ID
	virtual int GetTempId(int pos) = 0;

	//根据储能电站位置得到充电完成状态ID
	virtual int GetChrFinishID(int pos) = 0;

	//根据储能电站位置得到放电完成状态ID
	virtual int GetDiscFinishID(int pos) = 0;

	//根据储能电站位置得到AGC充电闭锁ID
	virtual int GetChargeLockID(int pos) = 0;

	//根据储能电站位置得到AGC放电闭锁ID
	virtual int GetDisChargeLockID(int pos) = 0;

	//根据储能电站位置得到历史值存储周期
	virtual int GetSvTimerID(int pos) = 0;

	//根据储能电站位置得到应用系统
	virtual const char* GetFamilyName(int pos) = 0;





	//动态
	//根据储能电站位置得到剩余容量SOC
	virtual double GetCurSoc(int pos) = 0;
	//根据储能电站位置设置剩余容量SOC
	virtual bool SetCurSoc(int pos, double CurSoc) = 0;

	//根据储能电站位置得到当前全站SOH
	virtual double GetSoh(int pos) = 0;
	//根据储能电站位置设置当前全站SOH
	virtual bool SetSoh(int pos,double Soh) = 0;

	//根据储能电站位置得到当前全站电池平均温度
	virtual double GetTemperature(int pos) = 0;
	//根据储能电站位置设置当前全站电池平均温度
	virtual double SetTemperature(int pos,double Temperature) = 0;

	//根据储能电站位置得到当前储能充放电总有功
	virtual double GetCurStorageP(int pos) = 0;
	//根据储能电站位置设置当前储能充放电总有功
	virtual bool SetCurStorageP(int pos, double CurStorageP) = 0;

	//根据储能电站位置得到当前储能充放电总无功
	virtual double GetCurStorageQ(int pos) = 0;
	//根据储能电站位置设置当前储能充放电总无功
	virtual bool SetCurStorageQ(int pos, double CurStorageQ) = 0;

	//根据储能位置得到总充电次数
	virtual int GetChargeTimes(int pos) = 0;
	//根据储能位置设置总充电次数。
	virtual bool SetChargeTimes(int pos, int ChargeTimes) = 0;

	//根据储能位置得到总放电次数
	virtual int GetDisChargeTimes(int pos) = 0;
	//根据储能位置设置总放电次数。
	virtual bool SetDisChargeTimes(int pos, int DisChargeTimes) = 0;

	//根据储能位置得到今日充电次数
	virtual int GetTodayChargeTimes(int pos) = 0;
	//根据储能位置设置今日充电次数。
	virtual bool SetTodayChargeTimes(int pos, int TodayChargeTimes) = 0;

	//根据储能位置得到今日放电次数
	virtual int GetTodayDisChargeTimes(int pos) = 0;
	//根据储能位置设置今日放电次数。
	virtual bool SetTodayDisChargeTimes(int pos, int TodayDisChargeTimes) = 0;

	//计算当前功率充电可用时间(分钟)
	virtual double CalculateInableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	//计算当前功率放电可用时间(分钟)
	virtual double CalculateOutableT(float minSoc, float maxSoc, float curSoc, float curP, float Capacity) = 0;

	//计算最大功率充电可用时间(分钟)
	virtual double CalculateMaxPinableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	//计算最大功率放电可用时间(分钟)
	virtual double CalculateMaxPoutableT(float minSoc, float maxSoc, float curSoc, float MaxP, float Capacity) = 0;

	//根据储能位置得到充电完成状态
	virtual int GetChrFinishSt(int pos) = 0;
	//根据储能电站位置设置充电完成状态
	virtual bool SetChrFinishSt(int pos, int ChrFinishSt) = 0;

	//根据储能位置得到放电完成状态
	virtual int GetDiscFinishSt(int pos) = 0;
	//根据储能电站位置设置放电完成状态
	virtual bool SetDiscFinishSt(int pos, int DiscFinishSt) = 0;

	//根据储能电站位置得到AGC充电闭锁
	virtual int GetChargeLock(int pos) = 0;
	//根据储能电站位置设置AGC充电闭锁
	virtual bool SetChargeLock(int pos, int ChargeLock) = 0;

	//根据储能电站位置得到AGC放电闭锁
	virtual int GetDisChargeLock(int pos) = 0;
	//根据储能电站位置设置AGC放电闭锁
	virtual bool SetDisChargeLock(int pos, int DisChargeLock) = 0;
};

#endif
