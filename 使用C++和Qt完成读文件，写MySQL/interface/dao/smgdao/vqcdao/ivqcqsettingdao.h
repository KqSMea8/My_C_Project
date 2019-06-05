//ivqcqsettingdao.h

#ifndef _IVQCQSETTINGPARAMDAO_PENGSHIKANG_20120531_H_
#define _IVQCQSETTINGPARAMDAO_PENGSHIKANG_20120531_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for VqcRange、VqcSettingInfo

#define VQCQSETTINGDAO_CLASSID    "cvqcqsettingdao"
#define VQCQSETTINGDAO_INTFID     "ivqcqsettingdao"

class IVqcQSettingDao : virtual public IBasicDao
{
public:
	//根据VQC定值类型ID和当前时间得到VQC定值信息位置
	virtual int GetPositionByTypeAndTime(int typeId, int nMinutes) = 0;
	
	//根据VQC定值类型ID和当前电压得到VQC定值信息位置
	virtual int GetPositionByTypeAndVoltage(int typeId, double dVoltage) = 0;
	
	//根据VQC定值信息位置读取VQC定值类型ID
	virtual int GetLimitType(int pos) = 0;
	
	//根据VQC定值信息位置得到定值时间范围
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;

	//根据VQC定值信息位置得到定值电压范围
	virtual void GetVoltageRange(int pos, double& startVolt, double& endVolt) = 0;
	
	//根据VQC定值信息位置得到功率因数_无功限值
	virtual void GetRePowerOrCosPowerLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	
	//根据VQC定值信息位置得到VQC定值信息
	virtual void GetReactPowerSetting(int pos, VqcRange& rpSetting) = 0;
	virtual bool GetCurrentSettingValueByTypeId(int typeId, VqcSettingInfo& settingInfo) = 0;
	
};

#endif
