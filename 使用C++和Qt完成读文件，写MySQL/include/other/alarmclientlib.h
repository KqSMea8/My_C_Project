// alarmclientlib.h: implement for the CAlarmTrans and CAlarmEvent class.
#ifndef _ALARMEVENTLIB_2008_07_08_ZHANGNI_H_
#define _ALARMEVENTLIB_2008_07_08_ZHANGNI_H_

#include "../commgr/intfobjptra.h"     // for CIntfObjPtrA
#include "../../interface/alarmintf.h" // for IAlarmTrans��IAlarmEventBase

class CAlarmTrans : public CIntfObjPtrA<IAlarmTrans>
{
public:
	CAlarmTrans() : CIntfObjPtrA<IAlarmTrans>
		(MODULE_ALARMCLIENT, CLSID_AlarmTrans, IID_IAlarmTrans) { }
	
	//����һ���µ�IAlarmTrans�ӿڶ���
	//IAlarmTrans* CreateObject();
	
	//����һ���µ�IAlarmEventBase�ӿڶ���
	IAlarmEventBase* CreateAlarmEvent()
	{
		return (IAlarmEventBase*)CreateObject(CLSID_AlarmEventBase, IID_IAlarmEventBase);
	}
};

//DLL����Ľӿڶ�������
class CAlarmEvent : public CIntfObjPtrA<IAlarmEventBase>
{
public:
	CAlarmEvent() : CIntfObjPtrA<IAlarmEventBase>
		(MODULE_ALARMCLIENT, CLSID_AlarmEventBase, IID_IAlarmEventBase) { }
	
	//����һ���µ�IAlarmEventBase�ӿڶ���
	//IAlarmEventBase* CreateObject();
};

#endif 
