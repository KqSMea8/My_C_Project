//icsfalmintf.h

#ifndef _ICSFALARMINTERFACE_PENGSHIKANG_20130227_H_
#define _ICSFALARMINTERFACE_PENGSHIKANG_20130227_H_

#include "../../../scadasrv/scadadatadef.h"      // for AlarmObjectInfo

class ICsfAlarmIntf
{
public:
	//����ǰ�òɼ���λ�õõ������ƻ����ļ�
	virtual const char* GetAlarmPage(int pos) = 0;
	//����ǰ�òɼ���λ�õõ����������ļ�
	virtual const char* GetAlarmVoice(int pos) = 0;
	//����ǰ�òɼ���λ�õõ�����������Ϣ
	virtual void GetAlarmObjectInfo(int id, int pos, double almTime, AlarmObjectInfo& alarmInfo) = 0;
};

#endif
