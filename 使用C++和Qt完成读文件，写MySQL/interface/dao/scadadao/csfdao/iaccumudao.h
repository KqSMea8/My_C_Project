//iaccumudao.h

#ifndef _IACCUMULATORDAO_PENGSHIKANG_20100805_H_
#define _IACCUMULATORDAO_PENGSHIKANG_20100805_H_

#include "irawdao.h"                           // for IRawDao

#define ACCUMUDAO_CLASSID    "caccumudao"
#define ACCUMUDAO_INTFID     "iaccumudao"

class IAccumuDao : virtual public IRawDao
{
public:
	//将数据表的动态信息写入库中
	virtual void WriteDynamicInfo1() = 0;
		
	//设置累加量处理结果（坏数据）
	virtual bool SetAccumuValue(int nAcumPos, int nSrcId, int nPntId, double curTime, 
		double rawValue, int curQualt) = 0;
	
	//设置累加量处理结果（好数据）
	virtual bool SetAccumuValue(int nAcumPos, int nSrcId, int nPntId, double curTime, double rawValue, 
		int curQualt, double relValue, double incValue, double amoValue, double accValue) = 0;
	
	//根据累加量位置得到累加量类型
	virtual int GetAccumuType(int pos) = 0;
	//根据累加量位置得到度量单位
	virtual int GetMeasUnit(int pos) = 0;
	//根据累加量位置判断是否分时段统计
	virtual int IsPeriodStatistic(int pos) = 0;
	//根据累加量位置得到乘系数
	virtual double GetScaleFactor(int pos) = 0;
	//根据累加量位置得到加系数
	virtual double GetOffset(int pos) = 0;
	//根据累加量位置计算累加量增量值
	virtual bool IncreaseValue(int pos, double calValue, double& increVal, double& amontVal, double& accValue) = 0;
	
	//根据累加量位置得到物理量程上限
	virtual double GetMaxValue(int pos) = 0;
	//根据累加量位置得到物理量程下限
	virtual double GetMinValue(int pos) = 0;
	//判断当前值是否为正常值
	virtual bool IsNormalValue(int pos, double curVal) = 0;

	//根据累加量位置得到满码上限值
	virtual double GetUpperValue(int pos) = 0;
	
	//根据累加量位置得到相对值
	virtual double GetRelativeValue(int pos) = 0;
	//根据累加量位置得到增量值
	virtual double GetIncrementValue(int pos) = 0;
	
	//读取时段统计表的统计存储标志
	virtual void ReadSaveFlags() = 0;
	//根据数据对象位置得到统计存储标志
	virtual int GetSaveFlag(int pos) = 0;
	//复位指定记录位置的统计存储标志
	virtual bool ResetSaveFlag(int pos) = 0;
	
	//根据累加量位置得到计算值
	virtual double GetCalValue(int pos) = 0;
	//根据累加量ID得到计算值
	virtual double GetCalValueById(int id, bool* ok=0) = 0;

	//根据累加量位置得到总累计值
	virtual double GetTotalValue(int pos) = 0;
};

#endif
