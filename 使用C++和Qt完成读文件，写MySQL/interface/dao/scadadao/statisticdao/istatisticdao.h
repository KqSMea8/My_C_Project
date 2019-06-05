//istatisticdao.h

#ifndef _ISTATISTICSDAO_PENGSHIKANG_20130310_H_
#define _ISTATISTICSDAO_PENGSHIKANG_20130310_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../icsvalue.h"                   // for intarray

#define STATISTICDAO_CLASSID    "cstatisticdao"
#define STATISTICDAO_INTFID     "istatisticdao"

class IStatisticDao : virtual public IBasicDao
{
public:
	//写入统计表的动态信息
	virtual void WriteDynamicInfo1() = 0;
	
	//根据定时器类型ID统计对应的公式计算记录集
	virtual int StatisticsDatasByTimerId(int timerId) = 0;
	
	//根据存储周期ID得到对应的测点数据记录集
	virtual intarray* GetDataIdSetByType(int nTypeId) = 0;

	//根据状态量统计位置得到最后一次统计时间
	virtual double GetStatisticsTime(int pos) = 0;
	
	//读取统计表的统计存储标志
	virtual void ReadSaveFlags() = 0;
	//根据数据对象位置得到统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//复位指定记录位置的统计存储标志
	virtual bool ResetSaveFlag(int pos) = 0;
	
	//根据数据对象位置得到统计存储周期ID
	virtual int GetSaveTimerId(int pos) = 0;

protected:
	virtual int GetIndex_StaticTime() = 0;
	virtual int GetIndex_SaveFlag() = 0;
	//是否存储标志未变动
	virtual bool IsOldSaveFlag() = 0;
	//初始化全记录统计存储标志内存
	virtual void InitSaveFlagMemory() = 0;
	//生成全记录统计存储标志内存
	virtual void MallocSaveFlagMemory(int statNum) = 0;
	//释放全记录统计存储标志内存
	virtual void FreeSaveFlagMemory() = 0;

};

#endif
