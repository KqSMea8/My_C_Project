//ipccdao.h

#ifndef _IPCCDAO_PENGSHIKANG_20100324_H_
#define _IPCCDAO_PENGSHIKANG_20100324_H_

#include "imgddao.h"                             // for IMgdDao

#define PCCDAO_CLASSID    "cpccdao"
#define PCCDAO_INTFID     "ipccdao"

class IPccDao : virtual public IMgdDao
{
public:
	//根据公共连接点位置更新配电侧电压和频率
	virtual void UpdateDisnetUF(int pos, double& dValueU, double& dValueF) = 0;
	
	//根据公共连接点位置得到所连上级微电网线路ID
	virtual int GetLineID(int pos) = 0;
	//根据公共连接点位置得到配电侧电压遥测ID
	virtual int GetUID(int pos) = 0;
	//根据公共连接点位置得到配电侧频率遥测ID
	virtual int GetFID(int pos) = 0;
	//根据公共连接点位置得到配电侧当前电压
	virtual double GetCurU(int pos) = 0;
	//根据公共连接点位置得到配电侧当前频率
	virtual double GetCurF(int pos) = 0;	

	//根据公共连接点位置得到上网电量遥脉ID
	virtual int GetSaleEnergyID(int pos) = 0;
	//根据公共连接点位置得到下网电量遥脉ID
	virtual int GetUseEnergyID(int pos) = 0;
	//根据公共连接点位置得到今日上网电量
	virtual double GetTodaySaleEnergy(int pos) = 0;
	//根据公共连接点位置得到累计上网电量
	virtual double GetTotalSaleEnergy(int pos) = 0;
	//根据公共连接点位置得到今日下网电量
	virtual double GetTodayUseEnergy(int pos) = 0;
	//根据公共连接点位置得到累计下网电量
	virtual double GetTotalUseEnergy(int pos) = 0;

	//根据公共连接点位置设置今日上网电量
	virtual bool SetTodaySaleEnergy(int pos, double dTodaySaleWh) = 0;
	//根据公共连接点位置设置累计上网电量
	virtual bool SetTotalSaleEnergy(int pos, double dTotalSaleWh) = 0;
	//根据公共连接点位置设置今日下网电量
	virtual bool SetTodayUseEnergy(int pos, double dTodayUseWh) = 0;
	//根据公共连接点位置设置累计下网电量
	virtual bool SetTotalUseEnergy(int pos, double dTotalUseWh) = 0;
};

#endif
