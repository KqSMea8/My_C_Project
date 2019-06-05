//iweatherdao.h

#ifndef _IWEARTHERDATADAO_PENGSHIKANG_20120521_H_
#define _IWEARTHERDATADAO_PENGSHIKANG_20120521_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define WEATHERDAO_CLASSID    "cweatherdao"
#define WEATHERDAO_INTFID     "iweatherdao"

class IWeatherDao : virtual public IBasicDao
{
public:
	//根据天气数据的位置设置各个量测量实时值
	virtual void SetMeasureValues(int pos, double& dWind, double& dHeat, double& dLight, double& dWet, double& dBaro) = 0;
	
	//根据天气数据位置得到子微网ID
	virtual int GetSubMicGridID(int pos) = 0;

	//根据天气数据位置得到风速遥测ID
	virtual int GetWindID(int pos) = 0;
	//根据天气数据位置得到温度遥测ID
	virtual int GetHeatID(int pos) = 0;
	//根据天气数据位置得到光照遥测ID
	virtual int GetLightID(int pos) = 0;
	//根据天气数据位置得到湿度遥测ID
	virtual int GetWetID(int pos) = 0;
	//根据天气数据位置得到气压遥测ID
	virtual int GetBaroID(int pos) = 0;
	//根据天气数据位置得到当前风速
	virtual double GetCurWind(int pos) = 0;
	//根据天气数据位置得到当前温度
	virtual double GetCurHeat(int pos) = 0;
	//根据天气数据位置得到当前光照
	virtual double GetCurLight(int pos) = 0;
	//根据天气数据位置得到当前湿度
	virtual double GetCurWet(int pos) = 0;
	//根据天气数据位置得到当前气压
	virtual double GetCurBaro(int pos) = 0;

	//根据天气数据位置得到设备ID
	virtual int GetEquipID(int pos) = 0;
	//根据天气数据位置得到光照散射辐照强度遥测ID
	virtual int GetSunScatRadiID(int pos) = 0;
	//根据天气数据位置得到当前光照散射辐照强度
	virtual double GetCurSunScatRadi(int pos) = 0;
	//根据天气数据位置得到光照总辐照强度遥测ID
	virtual int GetSunTotalRadiID(int pos) = 0;
	//根据天气数据位置得到当前光照总辐照强度
	virtual double GetCurSunTotalRadi(int pos) = 0;
	//根据天气数据位置得到风向遥测ID
	virtual int GetWindDirectionID(int pos) = 0;
	//根据天气数据位置得到当前风向
	virtual double GetCurWindDirection(int pos) = 0;

	//根据子微电网ID得到天气数据位置
	virtual int GetPositionByMicgridID(int mgId) = 0;
	//根据设备ID得到天气数据位置
	virtual int GetPositionByEquipmentID(int eqpId) = 0;
};

#endif
