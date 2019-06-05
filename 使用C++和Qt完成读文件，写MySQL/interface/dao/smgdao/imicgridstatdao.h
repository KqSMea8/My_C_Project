//imicgridstatdao.h

#ifndef _ICSMICGRIDSTATISTICSDAO_PENGSHIKANG_20160923_H_
#define _ICSMICGRIDSTATISTICSDAO_PENGSHIKANG_20160923_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/smgdatadef.h"             // for MicgridObectInfo

#define CMICGRIDSTATDAO_CLASSID    "cmicgridstatdao"
#define CMICGRIDSTATDAO_INTFID     "imicgridstatdao"

class IAccumuDao;

class IMicgridStatDao : virtual public IBasicDao
{
public:
	//设置遥脉量实体对象
	virtual void SetAccumuDao(IAccumuDao* pAccumu) = 0;
	//根据子微网统计信息表位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, MicgridObectInfo* pCurMgObj, int& nAlarm) = 0;

	//根据子微网统计信息表位置得到今日上网电量
	virtual double GetTodaySaleEnergy(int pos) = 0;
	//根据子微网统计信息表位置得到累计上网电量
	virtual double GetTotalSaleEnergy(int pos) = 0;
	//根据子微网统计信息表位置得到今日下网电量
	virtual double GetTodayUseEnergy(int pos) = 0;
	//根据子微网统计信息表位置得到累计下网电量
	virtual double GetTotalUseEnergy(int pos) = 0;

	//根据子微网统计信息表位置设置今日上网电量
	virtual bool SetTodaySaleEnergy(int pos, double dTodaySaleWh) = 0;
	//根据子微网统计信息表位置设置累计上网电量
	virtual bool SetTotalSaleEnergy(int pos, double dTotalSaleWh) = 0;
	//根据子微网统计信息表位置设置今日下网电量
	virtual bool SetTodayUseEnergy(int pos, double dTodayUseWh) = 0;
	//根据子微网统计信息表位置设置累计下网电量
	virtual bool SetTotalUseEnergy(int pos, double dTotalUseWh) = 0;

	/////////////////////////////////////////////////////////////////////////////

	//根据子微网统计信息表位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;
	//根据子微网统计信息表位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据子微网统计信息表位置设置最后一次统计时间
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;
	//读取子微网表的统计存储标志
	virtual void ReadSaveFlags() = 0;
	//根据子微网统计信息表位置得到统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//复位指定记录位置的统计存储标志
	virtual bool ResetSaveFlag(int pos) = 0;

	//根据子微网统计信息表位置得到可调容量
	virtual double GetAdjPCapacity(int pos) = 0;
	//根据子微网统计信息表位置得到有功可调上限
	virtual double GetAdjPUpperLimit(int pos) = 0;
	//根据子微网统计信息表位置得到有功可调下限
	virtual double GetAdjPLowerLimit(int pos) = 0;
	//根据子微网统计信息表位置得到可增有功
	virtual double GetPIncreaseLimit(int pos) = 0;
	//根据子微网统计信息表位置得到可减有功
	virtual double GetDecreaseLimit(int pos) = 0;
	//根据子微网统计信息表位置得到参与调控损失有功功率
	virtual double GetLossPower(int pos) = 0;
	//根据子微网统计信息表位置得到有功上调节闭锁标志
	virtual int GetPIncLockFlag(int pos) = 0;
	//根据子微网统计信息表位置得到有功下调节闭锁标志
	virtual int GetPDecLockFlag(int pos) = 0;
	//根据子微网统计信息表位置得到无故障且未限电时的理论发电有功功率
	virtual double GetNaturalGeneratePower(int pos) = 0;
	//根据子微网统计信息表位置得到未限电时的可用发电有功功率
	virtual double GetRealGeneratePower(int pos) = 0;

};
#endif
