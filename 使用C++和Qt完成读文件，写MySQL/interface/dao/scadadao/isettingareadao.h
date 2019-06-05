//isettingareadao.h

#ifndef _ISETTINGAREADAO_PENGSHIKANG_20101126_H_
#define _ISETTINGAREADAO_PENGSHIKANG_20101126_H_

#include "../ibasicdao.h"                        // for IBasicDao

#define SETTINGAREADAO_CLASSID    "csettingareadao"
#define SETTINGAREADAO_INTFID     "isettingareadao"

class ISettAreaDao : virtual public IBasicDao
{
public:	
	//根据定值区号和定值量ID得到定值区表的位置
	virtual int GetPositionBySettingID(int nAreaNo, int nSettingId) = 0;
	
	//根据定值区位置得到定值区号
	virtual int GetSettingArea(int pos) = 0;
	//根据定值区位置得到定值区量ID
	virtual int GetSettingId(int pos) = 0;

	//根据定值区位置得到定值值
	virtual const char* GetSettingValue(int pos) = 0;
	//根据定值区位置设置定值值
	virtual bool SetSettingValue(int pos, const char* sSettValue) = 0;
	
	//根据定值区位置得到定值召唤设置时间
	virtual double GetSettingTime(int pos) = 0;
	//根据定值量位置设置定值召唤设置时间
	virtual bool SetSettingTime(int pos, double dSettTime) = 0;
};

#endif
