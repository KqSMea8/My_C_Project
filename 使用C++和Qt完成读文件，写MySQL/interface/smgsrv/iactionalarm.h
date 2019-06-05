// iactionalarm.h: interface for the IActionAlarm class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IACTIONALARM_H__PENGSHIKANG_20130304__INCLUDED_
#define _IACTIONALARM_H__PENGSHIKANG_20130304__INCLUDED_

#include "../alarmintf.h"                        // for AlarmParam

class IActionAlarm  
{
public:
	//�������󱨾����͡����ڿ��ơ�����������ٻ������顢���ù�������������������л�����PostAlarm()���á�
	virtual void ObjectAlarmPost(int alarmID, int objID, const char* objType, std::list<AlarmParam>* pParams,
		const char* objDesc, const char* objPath="", const char* actUser="", const char* almPage="", const char* almVoice="") = 0;
	//�豸���󱨾����͡����ڷ���������ɡ�����װ�á��޹������豸����ѹ���Ĳ���������
	virtual void EquipmentAlarmPost(int alarmID, int eqpID, const char* eqpType, const char* actUser, const char* eqpName, bool isSuccess) = 0;
	//���ƻ�ֵ���豸���󱨾����͡����ڷ����������װ�á��޹������豸�Ĺ��ʵ��ڲ������������ڳɹ�ʱ�����á�
	virtual void EquipmentAlarmPost(int alarmID, int eqpID, const char* eqpType, const char* actUser, const char* eqpName, bool isSuccess, double planPower) = 0;
	//����ִ�е���ʾ��Ϣд��־������������bAlarm��0 -- ��������1 -- SOE������2 -- ���Ʊ���
	virtual void WriteControlLogAndAlarm(int bAlarm, const char* context, ...) = 0;
		
};


#endif
