#ifndef _TASKPROCESS_H__
#define _TASKPROCESS_H__

#include "../icsunknown.h"

// ������־ģ������
#define LOG_TASKSERVER			"Log.taskserver"

typedef enum
{
	FLOAT_ANALOG = 0,			// ģ����
	FLOAT_PULSE					// �����
} FLOATTYPE;

typedef enum					// ����ң��������
{	
	CONTROL_SELECT = 0,			// ѡ����
	CONTROL_EXECUTE,			// ִ����
	CONTROL_CANCEL,			    // ������
	SETCTRL_SELECT,				// ��ֵѡ����(����)
	SETCTRL_EXECUTE,			// ��ִֵ����(����)
	SETCTRL_CANCEL,			    // ��ֵ������(����)
	SETCTRL_GETDATA				// ��ֵ��ȡ
} CONTROLTYPE_TASK;

typedef enum					// ����ֽ�ͷ��������
{
	TAP_STOP = 0,				// ͣ
	TAP_LOWER,					// ��
	TAP_HIGHER,					// ��
	TAP_NONE					// ����
} TAPTYPE;

typedef enum					// ���嶨ֵ��������
{
	SETTING_CALL = 0,			// ��ֵ�ٻ�
	SETTING_CALLZONE,
	SETTING_SELECT,				// ��ֵ�޸�Ԥ��	
	SETTING_CANCEL,				// ��ֵ�޸ĳ���
	SETTING_EXECUTE,			// ��ֵ�޸�ִ��
	SETTING_VERSION,			// �汾�Ų�ѯ
	SETTING_SWITCH		    	// ��ֵ���л�
} SETTINGTYPE;

typedef enum					// ���嶨ֵ������
{
	ZONE_RUN = 1,				// ��ǰ������
	ZONE_EDIT,					// ��ǰ�༭��
	ZONE_NUM					// ��ֵ������
} SETTINGZONETYPE;

typedef enum					// ���嶨ֵ����
{
	SETTING_SPG = 0,			// ������
	SETTING_ING,				// ���Ͷ�ֵ
	SETTING_ASG,				// ģ������ֵ
	SETTING_CURVE				// ���߶�ֵ
} SETTINGKIND;


#define TIMEOUT_CSF				10
#define ZERO_VALUE				1E-6

#define IID_ITASKBACK			"taskback"

// ҵ���������нӿ�
class ITaskBack : public IICSUnknown
{
public:
	virtual bool SendControlCmd(CONTROLTYPE_TASK type, int control, long value) = 0;
	virtual bool SendTapCmd(CONTROLTYPE_TASK type, int control, TAPTYPE tapType) = 0;
	virtual bool SendSettingCmd(SETTINGTYPE type, long ied, long cpu, long zone) = 0;
	virtual bool SendSettingSelCmd(long ied, long cpu, long zone, long succ, long size, 
					   long start, double* pCoes, double* pVals) = 0;
	virtual bool SendSwitchSetting(long ied, long cpu, long zone) = 0;
	virtual bool SendCallProtect(long sIEDID, long sSector, long nSinNo) = 0;

	//�˹�����
	virtual bool SendAnalogManSet(bool bset, int iedid, int id, double value) = 0;
	virtual bool SendStatusManSet(bool bset, int iedid, int id, int value) = 0;
	virtual bool SendPulseManSet(bool bset, int iedid, int id, double value) = 0; 

	virtual bool SendMessage(char* mesg) = 0;
};

#endif