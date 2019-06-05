//igeneratorstatdao.h

#ifndef _IGENERATORSTATDAO_PENGSHIKANG_20150713_H_
#define _IGENERATORSTATDAO_PENGSHIKANG_20150713_H_

#include "mgddao/igeneratordao.h"                // for IMgdDao

#define GENERATORSTATDAO_CLASSID    "cgeneratorstatdao"
#define GENERATORSTATDAO_INTFID     "igeneratorstatdao"

class IGeneratorStatDao : virtual public IBasicDao
{
public:
	//将数据表的动态信息写入库中[save]
	virtual void WriteDynamicInfo1() = 0;

	//根据发电机统计位置读取统计存储周期（用于计划历史存储）
	virtual int GetSaveTimerID(int pos) = 0;

	//根据发电机统计位置得到日最大发电功率
	virtual double GetMaxPower(int pos) = 0;
	//根据发电机统计位置设置日最大发电功率
	virtual bool SetMaxPower(int pos, double maxPower) = 0;

	//根据发电机统计位置得到日停运时间(小时)
	virtual double GeStopHours(int pos) = 0;
	//根据发电机统计位置设置日停运时间(小时)
	virtual bool SetStopHours(int pos, double stopHours) = 0;

	//根据发电机统计位置得到日待机时间(小时)
	virtual double GetBackupHours(int pos) = 0;
	//根据发电机统计位置设置日待机时间(小时)
	virtual bool SetBackupHours(int pos, double waitHours) = 0;

	//根据发电机统计位置得到日发电时间(小时)
	virtual double GetRunHours(int pos) = 0;
	//根据发电机统计位置设置日发电时间(小时)
	virtual bool SetRunHours(int pos, double runHours) = 0;

	//根据发电机统计位置得到日限电时间(小时)
	virtual double GetLimitHours(int pos) = 0;
	//根据发电机统计位置设置日限电时间(小时)
	virtual bool SetLimitHours(int pos, double lmtHours) = 0;

	//根据发电机统计位置得到当前开机率
	virtual double GetRunGenRate(int pos) = 0;
	//根据发电机统计位置设置当前开机率
	virtual bool SetRunGenRate(int pos, double runRate) = 0;

	//根据发电机统计位置得到当前限电率
	virtual double GetLimitGenRate(int pos) = 0;
	//根据发电机统计位置设置当前限电率
	virtual bool SetLimitGenRate(int pos, double runRate) = 0;

	//根据发电机统计位置得到今日发电量
	virtual double GetTodayEnergy(int pos) = 0;
	//根据发电机统计位置得到累计发电量
	virtual double GetTotalEnergy(int pos) = 0;
	//根据发电机统计位置更新今日发电量和累计发电量
	virtual bool UpdateGenEnergy(int pos, double todayW, double totalW) = 0;

	//根据发电机统计位置得到日最大发电功率出现时间
	virtual double GetMaxPowerTime(int pos) = 0;
	//根据发电机统计位置设置日最大发电功率出现时间
	virtual bool SetMaxPowerTime(int pos, double curTime) = 0;

	//根据发电机统计位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据发电机统计位置设置最后一次统计时间
	virtual bool SetStatisticsTime(int pos, double curTime) = 0;

	//读取发电机统计表的统计存储标志
	virtual void ReadSaveFlags() = 0;
	//根据发电机统计位置得到统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//复位指定记录位置的统计存储标志
	virtual bool ResetSaveFlag(int pos) = 0;

};

#endif
