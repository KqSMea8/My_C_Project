//icsfalmintf.h

#ifndef _ICSFALARMINTERFACE_PENGSHIKANG_20130227_H_
#define _ICSFALARMINTERFACE_PENGSHIKANG_20130227_H_

#include "../../../scadasrv/scadadatadef.h"      // for AlarmObjectInfo

class ICsfAlarmIntf
{
public:
	//根据前置采集量位置得到报警推画面文件
	virtual const char* GetAlarmPage(int pos) = 0;
	//根据前置采集量位置得到报警语音文件
	virtual const char* GetAlarmVoice(int pos) = 0;
	//根据前置采集量位置得到报警对象信息
	virtual void GetAlarmObjectInfo(int id, int pos, double almTime, AlarmObjectInfo& alarmInfo) = 0;
};

#endif
