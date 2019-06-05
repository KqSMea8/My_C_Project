// alarmclientlib.h: implement for the CAlarmTrans and CAlarmEvent class.
#ifndef _ALARMEVENTLIB_2008_07_08_ZHANGNI_H_
#define _ALARMEVENTLIB_2008_07_08_ZHANGNI_H_

#include "../commgr/intfobjptra.h"     // for CIntfObjPtrA
#include "../../interface/alarmintf.h" // for IAlarmTrans、IAlarmEventBase

class CAlarmTrans : public CIntfObjPtrA<IAlarmTrans>
{
public:
	CAlarmTrans() : CIntfObjPtrA<IAlarmTrans>
		(MODULE_ALARMCLIENT, CLSID_AlarmTrans, IID_IAlarmTrans) { }
	
	//创建一个新的IAlarmTrans接口对象
	//IAlarmTrans* CreateObject();
	
	//创建一个新的IAlarmEventBase接口对象
	IAlarmEventBase* CreateAlarmEvent()
	{
		return (IAlarmEventBase*)CreateObject(CLSID_AlarmEventBase, IID_IAlarmEventBase);
	}
};

//DLL输出的接口对象引用
class CAlarmEvent : public CIntfObjPtrA<IAlarmEventBase>
{
public:
	CAlarmEvent() : CIntfObjPtrA<IAlarmEventBase>
		(MODULE_ALARMCLIENT, CLSID_AlarmEventBase, IID_IAlarmEventBase) { }
	
	//创建一个新的IAlarmEventBase接口对象
	//IAlarmEventBase* CreateObject();
};

#endif 
