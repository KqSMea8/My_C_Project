#ifndef _TASKDBDEFINE_H__
#define _TASKDBDEFINE_H__

/* 定义业务对象访问实时库数据表及数据字段 */

// 公用字段
#define FIELD_ID					"ID"
#define FIELD_NAME					"Name"
#define FIELD_UNAME					"NAME"
#define FIELD_IEDID					"IEDID"
#define FIELD_BAYID					"BAYID"
#define FIELD_CPUNO					"CPUNO"
#define FIELD_TYPE					"TYPE"
#define FIELD_ATTRIBUTE				"ATTRIBUTE"
#define FIELD_NO                    "NO"
#define FIELD_RELATIVEID            "RELATIVEID"
#define FIELD_INFODEFTABLE2ID       "INFODEFTABLE2ID"
// 站对象
#define FIELD_PRVEIEW				"STATUS"			// 预演状态(厂站)

// 控制量对象
#define FIELD_CTRL_DBFLAG			"DoubleCtrlFlag"	// 双遥标志
#define FIELD_CTRL_UDBFLAG			"DOUBLECTRLFLAG"	// 双遥标志
#define FIELD_CTRL_TRIPID			"TripStrID"			// 控分描述(ID)
#define FIELD_CTRL_CLOSEID			"CloseStrID"		// 控合表述(ID)
#define FIELD_CTRL_TRIPEXP			"TripLockExpID"		// 控分表达式(ID)
#define FIELD_CTRL_CLOSEEXP			"CloseLockExpID"	// 控合表达式(ID)
#define FIELD_CTRL_OPFLAG			"OPFLAG"			// 程控标志
#define FIELD_CTRL_ATTRIBUTE		"ATTRIBUTE"			// 相关对象类型

// 控制量(61850)
#define FIELD_CTRL_INFOTBL			"INFODEFTABLE1"
#define FIELD_CTRL_INFOTBLID		"INFODEFTABLE1ID"
#define FIELD_CTRL_RELATIVEID		"RELATIVEID"
#define TYPE_CTRL_TAP				4				// 控制量：分接头类型

// 定义控制量104表字段(61850)
#define TABLE_CTRL104				"ctrltcp104"
#define NUM_BASE_INFOADDR			24677


// 表达式相关
#define TABLE_EXPRESSION			"expression"
#define FIELD_EXP_FORMULA			"FORMULA"
#define FIELD_EXP_DESC				"DESCRIPTION"

// 状态量相关
#define TABLE_STATUS				"status"
#define FIELD_STA_DBFLAG			"DoublePointFlag"
#define FIELD_STA_VALUE				"Value"
#define FIELD_STA_UVALUE			"VALUE"
#define FIELD_STA_ID				"ID"
#define FIELD_STA_INF104			"INFODEFTABLE1ID"
// 状态量(61850)
#define VALUE_DPS_CLOSE				2				// 定义双点合位置数值
#define QUALITY_VALID				3				// 有效质量标志
#define FIELD_STA_DUMMYFLAG			"DUMMYFLAG"


// 模拟量相关
#define TABLE_ANALOG				"analog"
#define FIELD_ANA_VALUE				"CalValue"
// 模拟量(61850)
#define FIELD_ANA_SCALE				"SECONDTATV"
#define FIELD_ANA_BASEVALUE			"BASEVALUE"


// 状态量104协议表
#define TABLE_CTRL104				"ctrltcp104"
#define FIELD_CTRL104_CPU			"CPUNO"
#define FIELD_CTRL104_ADDR			"COMMONADDRESS"
#define FIELD_CTRL104_INF			"INFOADDR104"
#define FIELD_CTRL104_ASDU			"MSGTYPE104"


// 装置相关
#define FIELD_IED_ADDRESS			"ADDRESS"
// 定义装置表字段(61850)
#define FIELD_IED_SESSIONID			"SESSIONID"


// 程序化操作票相关
#define TITLE_MSG					"程控操作票预演"
#define TABLE_TICKET				"ticket"
#define FIELD_TICKET_IOA			"IOA"

// 间隔设备态相关
#define FIELD_BAYS_EXPID			"EXPID"
#define FIELD_BAYS_STATE			"STATE"


// 定义定值区表字段(61850)
#define TABLE_SETZONE				"settingzone"
#define FIELD_ZONE_ZONETYPE			"ZONETYPE"
#define TYPE_SWITCHZONE				11				// 切换定值区类型

// 定义定值量字段(61850)
#define TABLE_SETTING				"setting"
#define SETINGZONE_CURRENT			15
#define MAX_SETTING					256				// 最大定值个数
#define COE_SETTING1				0				// 定值项类型及系数  zqx 修改为0
#define COE_SETTING2				16
#define COE_SETTING3				0x0002
#define MINUS_SETTING				0x0080
#define FACTOR_SETTING3				0.01
#define FIELD_SET_FACTOR			"SECONDCOL"
#define FIELD_SET_OFFSET			"OFFSET"
#define CODE_SET_VALUE				0x06

// 定义设备信息表字段(61850)
#define TABLE_DEVICEDESC			"devicedesc"


#endif