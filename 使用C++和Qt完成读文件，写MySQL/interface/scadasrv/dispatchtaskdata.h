//dispatchtaskdata.h

#ifndef _DISPATCHTASKDATA_PENGSHIKANG_2015_07_13_H_
#define _DISPATCHTASKDATA_PENGSHIKANG_2015_07_13_H_

#include "../icsvalue.h"                         //  for FIELDTYPE

enum DISPATCH_TASKTYPE //上行
{
	//DTT_UNKNOWN, 20160822 增加数据处理服务上线号0

	//----------------------------遥测（1-50）-------------------------------------
	DTT_DATA_MANAGE_SRV_ON = 0, //数据处理服务上线

	DTT_POWER_SETTING = 1, //有功功率设定值
	DTT_VOLTAGE_SETTING, //I母-电压设定值
	DTT_QORCOS_SETTING, //I母-无功/功率因数设定值- 20160401 改为表示无功上限目标值
	DTT_GENCAPA_SETTING_4 = 5, //未来四小时开机容量

	DTT_QORCOS_LOWERLIMIT = 6,//I母-无功/功率因数下限目标值
	DTT_POWER_MAXRATE = 7,//调度下发有功最大速率

	DTT_QORCOS_ADJUSTABLE_UP_LIMIT = 8,//无功可调上限
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT,//无功可调下限
	DTT_QORCOS_INCREASABLE_SETTING,//可增无功
	DTT_QORCOS_REDUCIBLE_SETTING,//可减无功

	//20160822 增加上行数据量 压板改为从50开始编号
	DTT_POWER_ADJUST_DEADZONE = 12,//调度下发调节死区	12

	DTT_POWER_ADJUSTABLE_UP_LIMI,//有功可调上限	13
	DTT_POWER_ADJUSTABLE_DOWN_LIMIT,//有功可调下限	14
	DTT_POWER_INCREASABLE_SETTING,//可增有功	15
	DTT_POWER_REDUCIBLE_SETTING,//可减有功	16

	DTT_CAPACITY = 17,//装机容量	17
	DTT_RUNNING_CAPACITY,//运行容量	18
	DTT_ADJUSTABLE_CAPACITY,//可调容量	19
	DTT_POWER_LOSS,//参与调控损失有功功率	20

	//20161212 增加动态无功可增/减目标值、实际值
	DTT_Q_DYNAMIC_INCREASABLE_SETTING = 22,//动态可增无功目标值 22
	DTT_Q_DYNAMIC_REDUCIBLE_SETTING,//动态可减无功目标值 23
	DTT_Q_DYNAMIC_INCREASABLE_VALUE,//动态可增无功实际值 24 
	DTT_Q_DYNAMIC_REDUCIBLE_VALUE,//动态可减无功实际值 25

	DTT_REAL_GENPOWER_VALUE,//可用发电有功功率 26
	DTT_NATURAL_GENPOWER__VALUE,//理论发电有功功率 27

	DTT_VOLTAGE_REFER,// 	电压参考值反校	28
	DTT_Q_REFER,// 	无功参考值反校	29
	DTT_Run_GenNum,//运行台数	30

	//20171204 宁夏追加遥测点 只计算并上送，不保存
	DTT_Q_COSAdjustableUpLimit_VALUE,//功率因数上限(全站可增总无功上限时功率因数)--31
	DTT_Q_COSAdjustableDownLimit_VALUE,//功率因数下限(全站可减总无功下限时功率因数)--32

	//20180920 江苏现场要求三条母线分别下发电压/无功目标值，增加支持II III母线的目标值
	DTT_VOLTAGE_SETTING_2,		//II母-电压设定值
	DTT_QORCOS_SETTING_2,		//II母-无功/功率因数设定值(上限)
	DTT_QORCOS_LOWERLIMIT_2,	//II母-无功/功率因数下限目标值
	DTT_VOLTAGE_SETTING_3,		//III母-电压设定值
	DTT_QORCOS_SETTING_3,		//III母-无功/功率因数设定值(上限)
	DTT_QORCOS_LOWERLIMIT_3,	//III母-无功/功率因数下限目标值

	DTT_VOLTAGE_REFER_2  =39,// II母-电压参考值反校	39
	DTT_Q_REFER_2,// 	II母-无功参考值反校	40
	DTT_VOLTAGE_REFER_3,// 	III母-电压参考值反校	41
	DTT_Q_REFER_3,// 	III母-无功参考值反校	42
	DTT_QORCOS_ADJUSTABLE_UP_LIMIT_2,//II母-无功可调上限
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT_2,//II母-无功可调下限
	DTT_QORCOS_ADJUSTABLE_UP_LIMIT_3,//III母-无功可调上限
	DTT_QORCOS_ADJUSTABLE_DOWN_LIMIT_3,//III母-无功可调下限

	DTT_QORCOS_INCREASABLE_SETTING_2,	//II母-可增无功
	DTT_QORCOS_REDUCIBLE_SETTING_2,		//II母-可减无功
	DTT_QORCOS_INCREASABLE_SETTING_3,	//III母-可增无功
	DTT_QORCOS_REDUCIBLE_SETTING_3,		//III母-可减无功

	//----------------------------遥信（51-100）-------------------------------------
	DTT_POWER_SWITCH = 51,		//有功功率调度压板投退
	DTT_EMERGESUPPORT_SWITCH,	//功率紧急支撑压板投退
	DTT_EMERGESTOP_SWITCH,		//紧急停运压板投退
	DTT_VOLTAGE_SWITCH,			//I母-电压调度压板投退

	DTT_EMERGESUPPORT_ENABLE = 57,//紧急支撑启动
	DTT_EMERGESTOP_ENABLE,			//紧急停运启动

	DTT_LOCALPLATEN_SWITCH = 59,//本地策略压板投退

	DTT_Q_UP_LOCK_SWITCH = 60,	//无功上调节闭锁标志
	DTT_Q_DOWN_LOCK_SWITCH,		//无功下调节闭锁标志

	DTT_AGC_RUN_CONDITION,		// 	AGC运行状态	62
	DTT_AGC_ENABLE_CONDITION,	// 	AGC允许状态	63
	DTT_P_UP_LOCK_SWITCH,		// 	有功功率增闭锁	64
	DTT_P_DOWN_LOCK_SWITCH,		// 	有功功率减闭锁	65

	DTT_FREE_GENERATION_MODE,// 	调度下发自由发电模式66 0表示自由发电；1表示按控制值发电

	DTT_P_ORDER_SOURCE = 67,	//20161212 增加有功目标指令来源

	DTT_QORCOS_CTRL_MODE = 68,	//20161216 增加电压无功控制模式遥信

	DTT_P_AGCSWITCH_BACK = 69,	//20180605 江苏要求：调度请求远方投入/退出返校值，我们用AGC压板应对YK调度请求远方投入/退出,同时把这个遥控记到smgsysinfo的AGC禁止状态字段里

	DTT_AVC_LocalRemote,// 	AVC子站远方/本地	70
	DTT_EMERGESUPPORT_Dis_ENABLE_REFER,// 	紧急支撑恢复遥控反校值	71
	DTT_EMERGESTOP_Dis_ENABLE_REFER,// 	紧急停运恢复遥控反校值	72

	DTT_EMERGESUPPORT_ENABLE_REFER,// 	紧急支撑遥控反校值	73
	DTT_EMERGESTOP_ENABLE_REFER,// 	紧急停运遥控反校值	74

	//20180920 AGC/AVC 指令异常闭锁信号
	DTT_AGC_AIMERROR,//AGC指令异常闭锁 75

	DTT_AVC_AIMERROR,//I母-AVC指令异常闭锁 76
	DTT_AVC_AIMERROR_2,//II母-AVC指令异常闭锁 77
	DTT_AVC_AIMERROR_3,//III母-AVC指令异常闭锁 78

	DTT_QORCOS_CTRL_MODE_2,	//II母-电压无功控制模式遥信
	DTT_QORCOS_CTRL_MODE_3,	//III母-电压无功控制模式遥信

	DTT_AVC_LocalRemote_2,//II母-AVC子站远方/本地	81
	DTT_AVC_LocalRemote_3,//III母-AVC子站远方/本地	82

	DTT_VOLTAGE_Remote_SWITCH,			//I母-电压调度 计划生效投退
	DTT_VOLTAGE_Remote_SWITCH_2,		//II母-电压调度 计划生效投退
	DTT_VOLTAGE_Remote_SWITCH_3,		//III母-电压调度 计划生效投退

	DTT_Q_UP_LOCK_SWITCH_2 ,	//II母无功上调节闭锁标志
	DTT_Q_DOWN_LOCK_SWITCH_2,	//II母无功下调节闭锁标志
	DTT_Q_UP_LOCK_SWITCH_3 ,	//III母无功上调节闭锁标志
	DTT_Q_DOWN_LOCK_SWITCH_3,	//III母无功下调节闭锁标志

//----------------------------曲线（101-）-------------------------------------
	DTT_DECLARE_CURVE_POWER_DAY = 101, //日发电功率申报曲线
	DTT_DECLARE_CURVE_ON_CAPACITY_DAY, //日开机容量申报曲线
	DTT_DECLARE_CURVE_POWER_4H , //四小时发电功率申报曲线

//----------------------------遥测（1001-）-------------------------------------
	DTT_Q_SETTING_MID = 1001, //I母-无功上下限目标值中值
	DTT_Q_SETTING_MID_2, //I母-无功上下限目标值中值
	DTT_Q_SETTING_MID_3, //I母-无功上下限目标值中值
};

//20160822 由于上下行数据不在严格对应，故增加一组枚举量用于下行数据，原来的枚举量用于上行数据。
enum DISPATCH_TASKTYPE_DOWN
{
	//----------------------------遥调（1-20）-------------------------------------
	DTTD_POWER_SETTING = 1, //有功功率设定值
	DTTD_VOLTAGE_SETTING, //I母电压设定值
	DTTD_QORCOS_SETTING, //I母无功/功率因数设定值- 20160401 改为表示无功上限目标值
	DTTD_QORCOS_LOWERLIMIT = 6,//I母无功/功率因数下限目标值

	DTTD_POWER_MAXRATE = 7,//调度下发有功最大速率
	
	DTTD_POWER_ADJUST_DEADZONE = 8,//调度下发调节死区

	//20161212 增加动态无功可增/减目标值
	DTTD_Q_DYNAMIC_INCREASABLE_SETTING = 9,//动态可增无功目标值 9
	DTTD_Q_DYNAMIC_REDUCIBLE_SETTING,//动态可减无功目标值 10

	DTTD_VOLTAGE_REFER,//电压参考值 11
	DTTD_VOLTAGE_INCREMENT,//电压增量值 12

	DTTD_Q_REFER,// 	无功参考值	13

	//20180920 江苏现场要求三条母线分别下发电压/无功目标值，增加支持II III母线的目标值
	DTTD_VOLTAGE_SETTING_2 = 14,	//II母 电压设定值
	DTTD_QORCOS_SETTING_2,			//II母 无功/功率因数设定值
	DTTD_QORCOS_LOWERLIMIT_2,		//II母 无功/功率因数下限目标值
	DTTD_VOLTAGE_SETTING_3,			//III母 电压设定值
	DTTD_QORCOS_SETTING_3,			//III母 无功/功率因数设定值
	DTTD_QORCOS_LOWERLIMIT_3,		//III母 无功/功率因数下限目标值


	//----------------------------遥控（21-50）-------------------------------------
	DTTD_POWER_SWITCH = 21, //有功功率计划是否生效
	DTTD_EMERGESUPPORT_SWITCH, //功率紧急支撑压板投退
	DTTD_EMERGESTOP_SWITCH, //紧急停运压板投退
	DTTD_VOLTAGE_SWITCH, //电压调度压板投退
	//DTTD_QORRCOS_SWITCH, //无功/功率因数调度压板投退

	DTTD_LOCALPLATEN_SWITCH = 25,//本地策略压板投退

	DTTD_EMERGESUPPORT_ENABLE = 27,//紧急支撑启动
	DTTD_EMERGESTOP_ENABLE,//紧急停运启动

	
	DTTD_FREE_GENERATION_MODE = 29,// 	调度下发自由发电模式 0表示自由发电；1表示按控制值发电

	DTTD_P_ORDER_SWITCH,//有功目标指令切换 30  //20161212 增加有功目标指令切换

	DTTD_EMERGESUPPORT_Dis_ENABLE = 31,//紧急支撑恢复
	DTTD_EMERGESTOP_Dis_ENABLE,//紧急停运恢复

	DTTD_VOLTAGE_Remote_SWITCH,			//I母-电压调度 计划生效投退
	DTTD_VOLTAGE_Remote_SWITCH_2,		//II母-电压调度 计划生效投退
	DTTD_VOLTAGE_Remote_SWITCH_3,		//III母-电压调度 计划生效投退

	//----------------------------下行曲线（51-）-------------------------------------
	DTTD_POWER_CURVE = 51, //有功曲线
	DTTD_VOLTAGE_CURVE, //电压曲线
	DTTD_QORCOS_CURVE, //无功、功率因数曲线

	//----------------------------总召（100）-------------------------------------
	DTTD_DISPATCH_CALL_BACK = 100,	////总召命令


	//----------------------------遥调（1001-）-------------------------------------业务点号不够了，现场已经和调度对过点，不能整个调整，只能续
	DTTD_VOLTAGE_REFER_2 = 1001,	//II母 电压参考值 1001
	DTTD_Q_REFER_2,			//II母 无功参考值 1002
	DTTD_VOLTAGE_REFER_3,	//III母 电压参考值 1003
	DTTD_Q_REFER_3,			//III母 无功参考值 1004

};

enum DISPATCH_TOHISTYPE //TO HISSTRATEGY 类型
{
	DTOHIS_NO = 0,//0-不向历史存储发送消息 
	DTOHIS_DispatchSwitc,//1-发送压板变化消息 
	DTOHIS_RemoteValChange_SQL,//2-发送sql语句
};
struct DispatchTaskData
{
	short taskType;
	FIELDTYPE dataType;
	icsvalue dataValue;
};

struct DispatchSetting
{
	//业务数据，用于返回信息给调度端
	DispatchTaskData taskData;
	//远程调度下发策略压板信息，同步到配置库
	int toHisSave;//0-不向历史存储发送消息 1-发送压板变化消息 2-发送sql语句
	icsvalue saveData;
	//本地控制下发启停令，结果信息返回给界面
	int senderType;
	char senderName[128];
};

#endif
