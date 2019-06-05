//ibusconndao.h

#ifndef _IBATSTATIONDAO_ZHANGMENG_20180708_H_
#define _IBATSTATIONDAO_ZHANGMENG_20180708_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define BATSTATIONDAO_CLASSID    "cbatstationdao"
#define BATSTATIONDAO_INTFID     "ibatstationdao"

class IBatStationDao : virtual public IBasicDao
{
public:
	virtual int GetSvTimerIDByPos(int pos)=0;//存储周期
	virtual int GetcondiByPos(int pos)=0;//全站充放电状态
	virtual double GetsocByPos(int pos)=0;//全站SOC
	virtual double GetsohByPos(int pos)=0;//全站SOH
	virtual double GettemperatureByPos(int pos)=0;//全站电池平均温度
	virtual double GettodayincyclesByPos(int pos)=0;//当天充电次数
	virtual double GettodayoutcyclesByPos(int pos)=0;//当天放电次数
	virtual double GetinableTByPos(int pos)=0;//当前功率充电可用时间
	virtual double GetoutableTByPos(int pos)=0;//当前功率放电可用时间
	virtual double GetMaxPinableTByPos(int pos)=0;//最大功率充电可用时间
	virtual double GetMaxPoutableTByPos(int pos)=0;//最大功率放电可用时间
	virtual double GetoutableQTByPos(int pos)=0;//可用无功出力时间
	virtual double GetinablePByPos(int pos)=0;//可用充电功率
	virtual double GetoutablePByPos(int pos)=0;//可用放电功率
	virtual double GetinablePtByPos(int pos)=0;//可充电量
	virtual double GetoutablePtByPos(int pos)=0;//可放电量
	virtual double GetoutableQByPos(int pos)=0;//可用无功功率
	virtual double GettodayinPtByPos(int pos)=0;//当天充电电量
	virtual double GettodayoutPtByPos(int pos)=0;//当天放电电量
	virtual double GettotalinPtByPos(int pos)=0;//累计总充电量
	virtual double GettotaloutPtByPos(int pos)=0;//累计总放电量
	virtual double GetmaxPinByPos(int pos)=0;//最大充电功率
	virtual double GetmaxPoutByPos(int pos)=0;//最大放电功率
	virtual double GetablecapByPos(int pos)=0;//可用能量
	virtual double Getdata1ByPos(int pos)=0;//预留1
	virtual double Getdata2ByPos(int pos)=0;//预留2
	virtual double Getdata3ByPos(int pos)=0;//预留3
	virtual double Getdata4ByPos(int pos)=0;//预留4
	
};

#endif
