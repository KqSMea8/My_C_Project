#ifndef _IALARMTR_H__
#define _IALARMTR_H__

#define IID_IAlarmConvertor			"ialarmconvertor"
#define CLSID_AlarmConvertor		"alarmconvertor"
#define MODULE_ALARMCONVERTOR		"alarmconvertor"

#include "../icsunknown.h"

class IAlarmConvertorSinker
{
public:
	// ����ֱ���Ļص��ӿ�
	virtual void AlarmConvertorSinker(const char* sSyslogAlarm) = 0;
};

class IAlarmConvertor : public IICSUnknown
{
public:
	// ע�ᱨ��ֱ���Ļص��ӿ�
    virtual bool RigisterAlarmConvertorSinker(IAlarmConvertorSinker* pSinker) = 0;

	// ���ø澯ֱ��������
	virtual void ResetAlarmIndexTable() = 0;

	// ����
	virtual void ExportAlarmIndex(const char* sPath) = 0;

	// ����
	virtual void ImportAlarmIndex(const char* sPath, bool bTruncate) = 0;

};

#endif // _IALARMTR_H__
