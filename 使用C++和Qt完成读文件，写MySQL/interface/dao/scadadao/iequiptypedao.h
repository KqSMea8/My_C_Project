//iequiptypedao.h

#ifndef _IEQUIPTYPEDAO_PENGSHIKANG_20130310_H_
#define _IEQUIPTYPEDAO_PENGSHIKANG_20130310_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define EQUIPTYPEDAO_CLASSID    "cequiptypedao"
#define EQUIPTYPEDAO_INTFID     "iequiptypedao"

class IEquipTypeDao : virtual public IBasicDao
{
public:
	//根据设备类型位置得到设备类型编码
	virtual const char* GetCode(int pos) = 0;
	//根据设备类型位置得到设备分类编码
	virtual int GetEquipClass(int pos) = 0;

	//根据设备ID得到是否是双位置设备和双位置设备变化延迟时间[可独立调用]
	virtual bool IsDoubleStatusByID(int id, int& nDelayTime, bool bRequery=false) = 0;
	//根据设备类型位置判断设备是否是双位置设备
	virtual bool IsDoubleStatus(int pos) = 0;
	//根据设备类型位置得到双位置设备变化延迟时间
	virtual int GetDpsDelayTime(int pos) = 0;
	//根据设备类型ID判断设备是否为可再生能源发电设备[可独立调用]
	virtual bool IsRenewableEnergyByID(int id, bool bRequery=false) = 0;	
};

#endif
