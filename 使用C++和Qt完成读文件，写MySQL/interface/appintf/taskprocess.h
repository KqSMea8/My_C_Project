#ifndef _TASKPROCESS_H__
#define _TASKPROCESS_H__

#include "../icsunknown.h"

// 定义日志模块名称
#define LOG_TASKSERVER			"Log.taskserver"

typedef enum
{
	FLOAT_ANALOG = 0,			// 模拟量
	FLOAT_PULSE					// 电度量
} FLOATTYPE;

typedef enum					// 定义遥控令类型
{	
	CONTROL_SELECT = 0,			// 选择令
	CONTROL_EXECUTE,			// 执行令
	CONTROL_CANCEL,			    // 撤销令
	SETCTRL_SELECT,				// 定值选择令(单条)
	SETCTRL_EXECUTE,			// 定值执行令(单条)
	SETCTRL_CANCEL,			    // 定值撤销令(单条)
	SETCTRL_GETDATA				// 定值读取
} CONTROLTYPE_TASK;

typedef enum					// 定义分接头操作类型
{
	TAP_STOP = 0,				// 停
	TAP_LOWER,					// 降
	TAP_HIGHER,					// 升
	TAP_NONE					// 保留
} TAPTYPE;

typedef enum					// 定义定值操作类型
{
	SETTING_CALL = 0,			// 定值召唤
	SETTING_CALLZONE,
	SETTING_SELECT,				// 定值修改预发	
	SETTING_CANCEL,				// 定值修改撤销
	SETTING_EXECUTE,			// 定值修改执行
	SETTING_VERSION,			// 版本号查询
	SETTING_SWITCH		    	// 定值区切换
} SETTINGTYPE;

typedef enum					// 定义定值区类型
{
	ZONE_RUN = 1,				// 当前运行区
	ZONE_EDIT,					// 当前编辑区
	ZONE_NUM					// 定值区个数
} SETTINGZONETYPE;

typedef enum					// 定义定值类型
{
	SETTING_SPG = 0,			// 控制字
	SETTING_ING,				// 整型定值
	SETTING_ASG,				// 模拟量定值
	SETTING_CURVE				// 曲线定值
} SETTINGKIND;


#define TIMEOUT_CSF				10
#define ZERO_VALUE				1E-6

#define IID_ITASKBACK			"taskback"

// 业务数据下行接口
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

	//人工置数
	virtual bool SendAnalogManSet(bool bset, int iedid, int id, double value) = 0;
	virtual bool SendStatusManSet(bool bset, int iedid, int id, int value) = 0;
	virtual bool SendPulseManSet(bool bset, int iedid, int id, double value) = 0; 

	virtual bool SendMessage(char* mesg) = 0;
};

#endif