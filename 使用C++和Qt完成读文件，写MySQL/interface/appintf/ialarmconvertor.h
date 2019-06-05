#ifndef _IALARMTR_H__
#define _IALARMTR_H__

#define IID_IAlarmConvertor			"ialarmconvertor"
#define CLSID_AlarmConvertor		"alarmconvertor"
#define MODULE_ALARMCONVERTOR		"alarmconvertor"

#include "../icsunknown.h"

class IAlarmConvertorSinker
{
public:
	// 报警直传的回调接口
	virtual void AlarmConvertorSinker(const char* sSyslogAlarm) = 0;
};

class IAlarmConvertor : public IICSUnknown
{
public:
	// 注册报警直传的回调接口
    virtual bool RigisterAlarmConvertorSinker(IAlarmConvertorSinker* pSinker) = 0;

	// 重置告警直传索引表
	virtual void ResetAlarmIndexTable() = 0;

	// 导出
	virtual void ExportAlarmIndex(const char* sPath) = 0;

	// 导入
	virtual void ImportAlarmIndex(const char* sPath, bool bTruncate) = 0;

};

#endif // _IALARMTR_H__
