//ivoltadjcoefdao.h

#ifndef _IVOLTAGEADJUSTCOEFICIENT_PENGSHIKANG_20170213_H_
#define _IVOLTAGEADJUSTCOEFICIENT_PENGSHIKANG_20170213_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define VOLTADJCOEFDAO_CLASSID    "cvoltadjcoefdao"
#define VOLTADJCOEFDAO_INTFID     "ivoltadjcoefdao"

class IVoltAdjCoefDao  : virtual public IBasicDao 
{
public:
	//根据接入点及考核点电压等级ID得到投退1单位无功引起考核点标幺电压变化百分率（%Ue/MVar）
	virtual double GetVoltageChangeCoef(int nJoinVoltId, int nChekVoltId) = 0;
	//根据接入点及考核点电压等级ID得到投退1单位无功引起考核点输出无功变化百分率（kVar/100kVar）
	virtual double GetReactPowerChangeCoef(int nJoinVoltId, int nChekVoltId) = 0;
};

#endif
