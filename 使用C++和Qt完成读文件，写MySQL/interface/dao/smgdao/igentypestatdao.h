//igentypestatdao.h

#ifndef _IGENERATORTYPESTATISTICSDAO_PENGSHIKANG_20120518_H_
#define _IGENERATORTYPESTATISTICSDAO_PENGSHIKANG_20120518_H_

#include "../ibasicdao.h"                        // for IBasicDao
#include "../../smgsrv/genstatisdef.h"           // for GeneClassStatisInfo

#define GENSTATDAO_CLASSID    "cgenstatdao"
#define GENSTATDAO_INTFID     "igenstatdao"

class IGenStatDao : virtual public IBasicDao
{
public:
	//将数据表的动态信息写入库中[save]
	virtual void WriteDynamicInfo1() = 0;

	//根据发电机类型ID和子微网ID得到发电分类统计记录的位置
	virtual int GetPositionByGenTypeAndSmgID(int genType, int smgId) = 0;
	
	//根据发电分类统计表的位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, GeneClassStatisInfo* pGenSttsInfo) = 0;
	
	//根据发电分类统计表位置得到发电设备类型ID
	virtual int GetGeneratorTypeID(int pos) = 0;
	//根据发电分类统计表位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;
	
	//根据发电分类统计表位置得到当前总有功
	virtual double GetCurTotalP(int pos) = 0;
	//根据发电分类统计表位置得到当前总无功
	virtual double GetCurTotalQ(int pos) = 0;
	
	//根据发电分类统计表发电类型和微电网ID得到当前总有功
	virtual double GetCurTotalP(int genType, int smgId) = 0;
	//根据发电分类统计表发电类型和微电网ID得到当前总无功
	virtual double GetCurTotalQ(int genType, int smgId) = 0;	

	//根据发电分类统计表位置得到总容量
	virtual double GetTotalGenCapacity(int pos) = 0;
	//根据发电分类统计表位置设置总容量
	virtual bool SetTotalGenCapacity(int pos, double genCapa) = 0;

	//根据发电分类统计表位置得到开机容量
	virtual double GetRunGenCapacity(int pos) = 0;
	//根据发电分类统计表位置设置开机容量
	virtual bool SetRunGenCapacity(int pos, double genCapa) = 0;
	//根据发电分类统计表位置得到限电容量
	virtual double GetLimitGenCapacity(int pos) = 0;
	//根据发电分类统计表位置设置限电容量
	virtual bool SeLimitGenCapacity(int pos, double genCapa) = 0;

	//根据发电分类统计表位置得到总台数
	virtual int GetTotalGenCount(int pos) = 0;
	//根据发电分类统计表位置设置总台数
	virtual bool SetTotalGenCount(int pos, int genNum) = 0;
	//根据发电分类统计表位置得到当前开机台数
	virtual int GetRunGenCount(int pos) = 0;
	//根据发电分类统计表位置设置当前开机台数
	virtual bool SetRunGenCount(int pos, int genNum) = 0;
	//根据发电分类统计表位置得到当前限电台数
	virtual int GetLimitGenCount(int pos) = 0;
	//根据发电分类统计表位置设置当前限电台数
	virtual bool SetLimitGenCount(int pos, int genNum) = 0;

	//根据发电分类统计表位置得到当前开机率
	virtual double GetRunGenRate(int pos) = 0;
	//根据发电分类统计表位置设置当前开机率
	virtual bool SetRunGenRate(int pos, double runRate) = 0;
	//根据发电分类统计表位置得到当前限电率
	virtual double GetLimitGenRate(int pos) = 0;
	//根据发电分类统计表位置设置当前限电率
	virtual bool SetLimitGenRate(int pos, double runRate) = 0;

	//根据发电分类统计表位置得到今日发电量
	virtual double GetTodayEnergy(int pos) = 0;          
	//根据发电分类统计表位置得到累计发电量
	virtual double GetTotalEnergy(int pos) = 0;  
	//根据发电分类统计表位置汇总今日发电量和累计发电量			
	virtual void SummaryGenEnergy(int pos, double todayW, double totalW) = 0;

	//根据发电分类统计表位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	//根据发电分类统计表位置设置最后一次统计时间
	virtual bool SetStatisticsTime(int pos, double sttsTime) = 0;

	//根据发电分类统计表位置得到检修台数
	virtual int GetRepairNum(int pos) = 0;
	//根据发电分类统计表位置得到待机台数
	virtual int GetStandbyNum(int pos) = 0;
	//根据发电分类统计表位置得到故障台数
	virtual int GetFaultNum(int pos) = 0;

	//根据发电分类统计表位置得到可调容量
	virtual double GetAdjPCapacity(int pos) = 0;
	//根据发电分类统计表位置得到有功可调上限
	virtual double GetAdjPUpperLimit(int pos) = 0;
	//根据发电分类统计表位置得到有功可调下限
	virtual double GetAdjPLowerLimit(int pos) = 0;
	//根据发电分类统计表位置得到可增有功
	virtual double GetPIncreaseLimit(int pos) = 0;
	//根据发电分类统计表位置得到可减有功
	virtual double GetDecreaseLimit(int pos) = 0;
	//根据发电分类统计表位置得到参与调控损失有功功率
	virtual double GetLossPower(int pos) = 0;
	//根据发电分类统计表位置得到有功上调节闭锁标志
	virtual int GetPIncLockFlag(int pos) = 0;
	//根据发电分类统计表位置得到有功下调节闭锁标志
	virtual int GetPDecLockFlag(int pos) = 0;
	//根据发电分类统计表位置得到无故障且未限电时的理论发电有功功率
	virtual double GetNaturalGeneratePower(int pos) = 0;
	//根据发电分类统计表位置得到未限电时的可用发电有功功率
	virtual double GetRealGeneratePower(int pos) = 0;

};

#endif
