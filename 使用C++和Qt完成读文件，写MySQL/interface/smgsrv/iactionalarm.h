// iactionalarm.h: interface for the IActionAlarm class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IACTIONALARM_H__PENGSHIKANG_20130304__INCLUDED_
#define _IACTIONALARM_H__PENGSHIKANG_20130304__INCLUDED_

#include "../alarmintf.h"                        // for AlarmParam

class IActionAlarm  
{
public:
	//操作对象报警发送。用于控制、界面操作、召唤、复归、定置管理、五防报警、并离网切换。被PostAlarm()调用。
	virtual void ObjectAlarmPost(int alarmID, int objID, const char* objType, std::list<AlarmParam>* pParams,
		const char* objDesc, const char* objPath="", const char* actUser="", const char* almPage="", const char* almVoice="") = 0;
	//设备对象报警发送。用于发电机、负荷、储能装置、无功补偿设备、变压器的操作报警。
	virtual void EquipmentAlarmPost(int alarmID, int eqpID, const char* eqpType, const char* actUser, const char* eqpName, bool isSuccess) = 0;
	//带计划值的设备对象报警发送。用于发电机、储能装置、无功补偿设备的功率调节操作报警。调节成功时被调用。
	virtual void EquipmentAlarmPost(int alarmID, int eqpID, const char* eqpType, const char* actUser, const char* eqpName, bool isSuccess, double planPower) = 0;
	//策略执行的提示信息写日志并报警。参数bAlarm：0 -- 不报警；1 -- SOE报警；2 -- 控制报警
	virtual void WriteControlLogAndAlarm(int bAlarm, const char* context, ...) = 0;
		
};


#endif
