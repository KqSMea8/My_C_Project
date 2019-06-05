//irawdao.h

#ifndef _IRAWDAO_PENGSHIKANG_20100915_H_
#define _IRAWDAO_PENGSHIKANG_20100915_H_

#include "icsfdao.h"                             // for ICsfDao

#define RawDao_CLASSID    "crawdao"
#define RawDao_INTFID     "irawdao"

class IRawDao : virtual public ICsfDao
{
public:
	//数据正在处理加锁
	virtual void LockUpdate() = 0;
	//数据正在处理解锁
	virtual void UnlockUpdate() = 0;

	//根据实时采集量位置得到数据来源类型
	virtual int GetOrigin(int pos) = 0;
	//根据实时采集量位置设置数据来源类型
	virtual bool SetOrigin(int pos, int nValue) = 0;
	//保存整个数据来源类型
	virtual void SaveOrigin() = 0;

	//根据实时采集量位置得到数据品质因数
	virtual int GetQuality(int pos) = 0;
	//根据实时采集量ID得到数据品质因数
	virtual int GetQualityById(int id) = 0;
	//根据实时采集量位置设置数据品质因数
	virtual bool SetQuality(int pos, int nValue) = 0;

	//根据实时采集量位置得到采集值
	virtual double GetRawValue(int pos) = 0;

	//根据采样值获得计算值
	virtual double CalculateValue(int pos, double rawValue) = 0;
	
	//根据实时采集量位置进行人工置数(计算值)，并返回旧值
	virtual double SetManualValue(int pos, double curTime, double calValue, bool isIncValue=false) = 0;

	//根据实时采集量位置取消人工置数
	virtual bool CancelManualSet(int pos) = 0;
	//根据实时采集量ID取消人工置数
	virtual bool CancelManualSetById(int id) = 0;
	
	//仿真遥控遥调对量测量的影响结果
	virtual bool TestControlResult(int measId, float aimValue) = 0;

	//根据数据源通断状态修改三遥数据品质
	virtual bool UpdateQualityBySrcConnect(int nSrcId, bool isConnected) = 0;
	
protected:
	//根据实时采集量位置设置采集值和品质因素[无锁]
	virtual void SetRawValue0(int pos, int nSrcId, int nPntId, int curQualt, double curTime, const void* pRawValue) = 0;
	//根据实时采集量位置进行人工置数(计算值)，并返回旧值[无锁]
	virtual double SetManualValue0(int pos, double curTime, double calValue, bool isIncValue=false) = 0;

	//获取数据品质因数字段索引
	virtual int GetIndex_Quality() = 0;
	//使用数据品质因数字段索引
	virtual int UseIndex_Quality() = 0;
	//获取数据采集值字段索引
	virtual int GetIndex_RawValue() = 0;
	//使用数据采集值字段索引
	virtual int UseIndex_RawValue() = 0;
	//获取数据计算值字段索引
	virtual int GetIndex_CalcValue() = 0;
	//使用数据计算值字段索引
	virtual int UseIndex_CalcValue() = 0;
};

#endif
