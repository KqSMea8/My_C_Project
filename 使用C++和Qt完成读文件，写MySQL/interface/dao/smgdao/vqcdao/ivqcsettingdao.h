//ivqcsettingdao.h

#ifndef _IVQCSETTINGPARAMDAO_PENGSHIKANG_20120503_H_
#define _IVQCSETTINGPARAMDAO_PENGSHIKANG_20120503_H_

#include "../../ibasicdao.h"                     // for IBasicDao
#include "../../../smgsrv/vqcdatadef.h"          // for VqcRange、VqcSettingInfo

#define VQCSETTINGDAO_CLASSID    "cvqcsettingdao"
#define VQCSETTINGDAO_INTFID     "ivqcsettingdao"

class IVqcSettingDao : virtual public IBasicDao
{
public:
	//根据VQC定值类型ID和当前时间得到VQC定值信息位置
	virtual int GetPositionByTypeAndTime(int typeId, int nMinutes) = 0;
	
	//根据VQC定值信息位置读取VQC定值类型ID
	virtual int GetLimitType(int pos) = 0;
	
	//根据VQC定值信息位置得到定值时间范围
	virtual void GetTimeRange(int pos, int& startTime, int& endTime) = 0;
	
	//根据VQC定值信息位置得到控制侧电压限值
	virtual void GetControlVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//根据VQC定值信息位置得到参考侧电压限值
	virtual void GetReferenceVoltageLimitValues(int pos, double& upperVal, double& lowerVal) = 0;
	//根据VQC定值信息位置得到控制侧闭锁电压限值
	virtual void GetControlVoltageLockValues(int pos, double& upperVal, double& lowerVal) = 0;
	//根据VQC定值信息位置得到参考侧闭锁电压限值
	virtual void GetReferenceVoltageLockValues(int pos, double& upperVal, double& lowerVal) = 0;
	
	//根据VQC定值信息位置得到VQC定值信息
	virtual void GetVoltageSetting(int pos, VqcSettingInfo& settingInfo) = 0;
	virtual bool GetCurrentVoltageSettingByType(int typeId, VqcSettingInfo& settingInfo) = 0;
	
};

#endif
