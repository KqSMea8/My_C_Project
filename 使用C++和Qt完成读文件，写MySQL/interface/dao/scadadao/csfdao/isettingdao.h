//isettingdao.h

#ifndef _ISETTINGDAO_PENGSHIKANG_20101126_H_
#define _ISETTINGDAO_PENGSHIKANG_20101126_H_

#include "icsfdao.h"                           // for ICsfDao

#define SETTINGDAO_CLASSID    "csettingdao"
#define SETTINGDAO_INTFID     "isettingdao"

class ISettingDao : virtual public ICsfDao
{
public:
	//根据采集数据源和采集点位置得到定值量位置
	virtual int GetPositionByCommSrcID(int nSrcId, int nPntId) = 0;
	
	//根据定值量位置得到定值值类型
	virtual int GetSettValueType(int pos) = 0;
	
	//根据定值量位置得到定值值
	virtual const char* GetSettingValue(int pos) = 0;
	//根据定值量位置设置定值值
	virtual bool SetSettingValue(int pos, const char* sSettValue) = 0;

	//  -------------------------------------  WX Modify  -------------------------------------  //
	//根据定值量位置获取CPU号   
	virtual int GetCpuNo(int pos) = 0;
	
	//根据定值量位置设置定值编辑区
	virtual bool SetEditArea(int pos, int& iEditArea) = 0;

	//根据定值量位置设置定值激活区
	virtual bool SetActArea(int pos, int& iActArea) = 0;
	//  -------------------------------------  WX Modify  -------------------------------------  //
	
	//根据定值量位置得到定值区号
	virtual int GetSettingArea(int pos) = 0;
	//根据定值量位置设置定值区号
	virtual bool SetSettingArea(int pos, int nSettArea) = 0;

	//根据定值量位置得到参数枚举数据类型定义ID
	virtual int GetSettingEnumId(int pos) = 0;
	//根据定值量位置得到控制字类型定义ID
	virtual int GetCtrlWordDefId(int pos) = 0;
	//根据定值量位置得到度量单位ID
	virtual int GetMeasUnit(int pos) = 0;
	//根据定值量位置得到最大值
	virtual double GetMaxValue(int pos) = 0;
	//根据定值量位置得到最小值
	virtual double GetMinValue(int pos) = 0;
};

#endif
