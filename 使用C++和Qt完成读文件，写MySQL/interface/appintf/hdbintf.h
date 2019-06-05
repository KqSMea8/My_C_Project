#ifndef __INTERFACE__H
#define __INTERFACE__H
#include "icsunknown.h"
#include "objsintf.h"

//查询类型
#define ANALOG_QUERY				"AnalogQuery"
#define ANALOG_QUERYINFO_ID			"ID"
#define ANALOG_QUERYINFO_STARTTIME	"StartTime"
#define ANALOG_QUERYINFO_ENDTIME	"EndTime"
#define ANALOG_QUERYINFO_POINTNUM	"PointNum"

#define ANALOGSTAT_QUERY				"AnalogStatQuery"
#define ANALOGSTAT_QUERYINFO_ID			"ID"
#define ANALOGSTAT_QUERYINFO_STARTTIME	"StartTime"
#define ANALOGSTAT_QUERYINFO_ENDTIME	"EndTime"
#define ANALOGSTAT_QUERYINFO_POINTNUM	"PointNum"

#define STATUS_QUERY				"StatusQuery"
#define STATUS_QUERYINFO_ID			"ID"
#define STATUS_QUERYINFO_STARTTIME	"StartTime"
#define STATUS_QUERYINFO_ENDTIME	"EndTime"

#define STATUSSTAT_QUERY				"StatusStatQuery"
#define STATUSSTAT_QUERYINFO_ID			"ID"
#define STATUSSTAT_QUERYINFO_STARTTIME	"StartTime"
#define STATUSSTAT_QUERYINFO_ENDTIME	"EndTime"

#define PULSE_QUERY					"PulseQuery"
#define PULSE_QUERYINFO_ID			"ID"
#define PULSE_QUERYINFO_STARTTIME	"StartTime"
#define PULSE_QUERYINFO_ENDTIME		"EndTime"
#define PULSE_QUERYINFO_POINTNUM	"PointNum"

#define PULSESTAT_QUERY					"PulseStatQuery"
#define PULSESTAT_QUERYINFO_ID			"ID"
#define PULSESTAT_QUERYINFO_STARTTIME	"StartTime"
#define PULSESTAT_QUERYINFO_ENDTIME		"EndTime"
#define PULSESTAT_QUERYINFO_POINTNUM	"PointNum"

#define ALARM_QUERY							"AlarmQuery"
#define ALARM_QUERYINFO_ALARMTYPECOUNT		"AlarmTypeCount"
#define ALARM_QUERYINFO_ALARMTYPE			"AlarmType"
#define ALARM_QUERYINFO_OBJTYPE				"ObjType"
#define ALARM_QUERYINFO_OBJID				"ObjID"
#define ALARM_QUERYINFO_STARTTIME			"StartTime"
#define ALARM_QUERYINFO_ENDTIME				"EndTime"
#define ALARM_QUERYINFO_FILTER				"Filter"
#define ALARM_QUERYINFO_OPERATOR			"Operator"
#define ALARM_QUERYINFO_RECFROM				"RecFrom"
#define ALARM_QUERYINFO_RECLEN				"RecLen"

#define FAULTINFO_QUERY					"FaultInfoQuery"
#define FAULTINFO_QUERYINFO_STARTTIME	"StartTime"
#define FAULTINFO_QUERYINFO_ENDTIME		"EndTime"

#define FAULTANALOG_QUERY						"FaultAnalogQuery"
#define FAULTANALOG_QUERYINFO_FAULTID			"FaultID"
#define FAULTANALOG_QUERYINFO_ANALOGIDCOUNT		"AnalogIDCount"
#define FAULTANALOG_QUERYINFO_ANALOGID			"AnalogID"
#define FAULTANALOG_QUERYINFO_STARTTIME			"StartTime"
#define FAULTANALOG_QUERYINFO_ENDTIME			"EndTime"


//错误返回码
#define QUERY_SUCCESS		0		//查询成功		
#define ACCESS_ERROR	   	-1		//数据库访问出错
#define NORECORD_ERROR		-2		//未查到相应记录
#define TIME_ERROR			-3		//时间条件出错
#define CONNECT_ERROR		-4		//数据库连接出错
#define NO_FIELD     		-5		//没有此字段

//告警类型定义
#define ANALOG_ALARM		1	    //模拟量告警
#define STATUS_ALARM		2		//开关量告警
#define PULSE_ALARM			3		//电度量告警
#define SOE_ALARM			4		//SOE量告警
#define CONTROL_ALARM		5		//遥控操作告警
#define COMM_ALARM			6		//通信事件告警
#define SYSTEM_ALARM		7		//系统事件告警

//对象类型
#define	STATION				1		// 站告警对象：		包含在该站下所有的遥测、遥信、遥控、SOE告警
#define	BAY					2		// 间隔告警对象：	包含在该间隔下所有的遥测、遥信、遥控、SOE告警
#define	IED					3		// 装置告警对象：	包含在该装置下所有的遥测、遥信、遥控、SOE告警
#define	ANALOG				4		// 模拟量告警对象： 包含该遥测的所有告警
#define	STATUS				5		// 状态量告警对象：	包含该遥信的所有告警
#define	OPEREVENT			6		// 操作告警对象：	包含该操作的所有告警
#define	CONTROL				7		// 控制量告警对象： 包含该遥控量的所有告警
#define	SETTING				8		// 定值告警对象：	包含该定值的所有告警
#define	SOEALARM			9		// SOE告警对象：	包含该SOE的所有告警
#define	COMEVENT			10		// 通讯告警对象：	包含该通讯对象的所有告警
#define	SYSEVENT			11		// 系统告警对象：	包含节点、用户登录退出、通讯等所有告警
#define	NODE				12		// 节点告警对象
#define	USER				13		// 用户登录退出告警对象

//类型定义：
//模拟量：
#define	ANALOG_UUP_LIMIT		1			// 越上上限；
#define	ANALOG_UP_LIMIT			2			// 越上限；
#define	ANALOG_DOWN_LIMIT		3			// 越下限；
#define	ANALOG_DDOWN_LIMIT		4			// 越下下限；
#define	ANALOG_RE_UUP_LIMIT		5			// 越上上限恢复；
#define	ANALOG_RE_UP_LIMIT		6			// 越上限恢复；
#define	ANALOG_RE_DOWN_LIMIT	7			// 越下限恢复；
#define	ANALOG_RE_DDOWN_LIMIT	8			// 越下下限恢复
#define	ANALOG_GRADE_ALARM		9			// 梯度报警
#define	ANALOG_RE_GRADE_ALARM	10			// 梯度报警恢复

//开关量：
#define	STATUS_CHANGE			21			// 变位；
//操作事件
#define	PULSE_MAN_SET			31			// 人工置数；
#define	PULSE_RE_MAN_SET		32			// 取消人工置数；
#define	PULSE_SET_USE			33			// 测点投入；
#define	PULSE_SET_UNUSE			34			//测点退出；
//SOE事件：
#define	SOE_SINGLE				41			// 单点遥信SOE；
#define	SOE_DOUBLE				42			// 双点遥信SOE；
#define	SOE_SINGLE_EVENT		43			// 单个保护事件SOE；
#define	SOE_GROUP_START_EVENT	44			// 保护成组启动事件SOE；
#define	SOE_GROUP_OUT_EVENT		45			// 保护成组输出事件SOE；
#define	SOE_PRO_EVENT			46			// 保护事件；
#define	SOE_PRO_ALRM			47			// 保护告警
//遥控事件：
#define	CTRL_WF_CHECK			51			// 五防检查；
#define	CTRL_SELET_ORDER		52			// 选择令；
#define	CTRL_OPER_ORDER			53			// 执行令；
#define	CTRL_CHECK				54			// 遥控校验；
#define	CTRL_CANCEL				55			// 遥控取消
#define	CTRL_END				56			// 遥控结束
#define	CTRL_LOCK				57			// 五防闭锁
#define	CTRL_TIMEOUT			58			// 五防超时
#define	CTRL_WF_MISMATCH		59			// 五防对象与遥控对象不匹配
#define	CTRL_WF_PASS			60			// 五防通过
//通讯状态：
#define	IED_COM_INTERRUPT		71			// 装置通讯中断；
#define	IED_COM_RESET			72			// 装置通讯恢复；
#define CHANNEL_GROUP_INTERRUPT 73          // 通道组通讯中断；
#define CHANNEL_GROUP_RESET     74          // 通道组通讯恢复；
#define CHANNEL_INTERRUPT		75          // 通道通讯中断；
#define CHANNEL_RESET			76          // 通道通讯恢复；
#define CHANNEL_SWITCH_BACK		77          // 通道主备切换（主->备）；
#define CHANNEL_SWITCH_MAIN		78          // 通道主备切换（备->主）；
#define	NODE_COM_INTERRUPT		79			// 节点通讯中断；
#define	NODE_COM_RESET			80			// 节点通讯恢复
#define	NODE_SWITCH_BACK		81			// 节点主备切换（主->备）；
#define	NODE_SWITCH_MAIN		82			// 节点主备切换（备->主）；

//系统事件：
#define	USER_LOGIN				91			// 用户登录；
#define	USER_LOGOUT				92			// 用户退出；
#define	BAY_RUN					93			// 间隔运行；（Event_NodeID表示间隔ID）
#define	BAY_CHECK				94			// 间隔检修；（Event_NodeID表示间隔ID）
#define	IED_UNUSER				95			// 装置挂牌；（Event_NodeID表示装置ID）
#define	IED_USER				96			// 装置摘牌；（Event_NodeID表示装置ID）
#define	BAY_LOCK				97			// 间隔闭锁；（Event_NodeID表示间隔ID）
#define	BAY_UNLOCK				98			// 间隔开锁；（Event_NodeID表示间隔ID）
#define	IED_LOCK				99			// 装置闭锁；（Event_NodeID表示装置ID）
#define	IED_UNLOCK				100			// 装置开锁；（Event_NodeID表示装置ID）
#define	GROUNDING				101			// 小电流接地；
#define	NODE_LOGIN				102			// 节点登录；（Event_NodeID表示节点ID）
#define	NODE_LOGOUT				103			// 节点退出；（Event_NodeID表示节点ID）
#define	NODE_WF_RUN				104			// 启动五防；（Event_NodeID表示节点ID）
#define	NODE_WF_END				105			// 关闭五防；（Event_NodeID表示节点ID）
#define	NODE_VQC_RUN			106			// VQC；
#define	NODE_GPS_RUN			107			// GPS
#define	NODE_SWITCH_BACK_MENU	108			// 手动切换（主->备）；（Event_NodeID表示新主服务器节点ID，Event_OperatorID表示旧主服务器节点ID）
#define	NODE_SWITCH_MAIN_MENU	109			// 手动切换（备->主）；（Event_NodeID表示新主服务器节点ID）
#define	BAY_DESIGN				110			// 间隔规划；（Event_NodeID表示间隔ID）
#define	IED_DESIGN				111			// 装置规划；（Event_NodeID表示间隔ID）

#define ANALOG_REPORT_ID 0
#define ANALOG_REPORT_Value 1
#define ANALOG_REPORT_ValueType 2
#define ANALOG_REPORT_Datetime 3

#define ALARM_ObjType 0
#define ALARM_ObjID 1
#define ALARM_ObjName 2
#define ALARM_AlarmTypeID 3
#define ALARM_AlarmType 4
#define ALARM_AlarmTime 5
#define ALARM_AlarmValue 6
#define ALARM_AlarmResult 7
#define ALARM_OperationID 8
#define ALARM_OperationMan 9
#define ALARM_Description 10
#define ALARM_SubTypeID 11

#define FAULTINFO_FaultID 0
#define FAULTINFO_FaultComment 1
#define FAULTINFO_StationID 2
#define FAULTINFO_FaultBayID 3
#define FAULTINFO_FaultTime 4
#define FAULTINFO_FaultTimeD 5
#define FAULTINFO_FaultSpace 6
#define FAULTINFO_BeforeFrameCount 7
#define FAULTINFO_AfterFrameCount 8

#define FAULTANALOG_FaultID 0
#define FAULTANALOG_AnalogID 1
#define FAULTANALOG_RecordBayID 2
#define FAULTANALOG_Subscript 3
#define FAULTANALOG_AnalogValue 4

#define PULSE_REPORT_ID 0
#define PULSE_REPORT_Datetime 1
#define PULSE_REPORT_PulseCurValue 2
#define PULSE_REPORT_ValueType 3

#define ANALOG_STAT_ID 0
#define ANALOG_STAT_Datetime 1
#define ANALOG_STAT_MaxValue 2
#define ANALOG_STAT_MaxMoment 3
#define ANALOG_STAT_MinValue 4
#define ANALOG_STAT_MinMoment 5
#define ANALOG_STAT_MeanValue 6
#define ANALOG_STAT_OverUpperLimitCount 7
#define ANALOG_STAT_OverUpperLimitTime 8
#define ANALOG_STAT_OverUUpperLimitCount 9
#define ANALOG_STAT_OverUUpperLimitTime 10
#define ANALOG_STAT_UnderLowerLimitCount 11
#define ANALOG_STAT_UnderLowerLimitTime 12
#define ANALOG_STAT_UnderLLowerLimitCount 13
#define ANALOG_STAT_UnderLLowerLimitTime 14
#define ANALOG_STAT_PeakFieldRatio 15
#define ANALOG_STAT_PeakFieldTime 16
#define ANALOG_STAT_ValleyFieldRatio 17
#define ANALOG_STAT_ValleyFieldTime 18
#define ANALOG_STAT_TotalFieldRatio 19

#define STATUS_STAT_ID 0
#define STATUS_STAT_Datetime 1
#define STATUS_STAT_ChangeCount 2
#define STATUS_STAT_CloseCount 3
#define STATUS_STAT_CloseTime 4
#define STATUS_STAT_OpenCount 5
#define STATUS_STAT_OpenTime 6
#define STATUS_STAT_PeakCloseCount 7
#define STATUS_STAT_PeakCloseTime 8
#define STATUS_STAT_PeakOpenCount 9
#define STATUS_STAT_PeakOpenTime 10
#define STATUS_STAT_ValleyCloseCount 11
#define STATUS_STAT_ValleyCloseTime 12
#define STATUS_STAT_ValleyOpenCount 13
#define STATUS_STAT_ValleyOpenTime 14
#define STATUS_STAT_CloseRatio 15
#define STATUS_STAT_OpenRatio 16
#define STATUS_STAT_PeakCloseRatio 17
#define STATUS_STAT_PeakOpenRatio 18
#define STATUS_STAT_ValleyCloseRatio 19
#define STATUS_STAT_ValleyOpenRatio 20
#define STATUS_STAT_FaultTripCount 21

#define PULSE_STAT_ID 0
#define PULSE_STAT_Datetime 1
#define PULSE_STAT_Value 2
#define PULSE_STAT_ValueType 3


#define MAX_HIS_DATA_COUNT 10000


typedef unsigned int uint;  //定义无符号整数
//返回值定义
#define OK                   0      //Get返回值正确，否则返回所需大小

#define IID_IICSHisAccess			"IICSHisAccess"
#define IID_IICSHisTypeTree			"IICSHisTypeTree"
#define IID_IICSQueryTypeTree       "IICSQueryTypeTree"

class IICSHisAccess : public IICSUnknown
{
public:
	virtual int GetRecordCount () = 0;			//取得记录数
	virtual void MoveFirst() = 0;				//移动到第一条记录
	virtual void MoveLast() = 0;				//移动到最后一条记录
	virtual bool MoveNext() = 0;				//移动到下一条
	virtual void MovePri () = 0;				//移动到上一条
	virtual void MoveTo(int nIndex) = 0;        //移动到指定记录
	//取得字段值
	virtual	int GetFieldValueByName(char* fieldname,  variant* value) = 0;
	//设置查询类型
    virtual void SetQueryType(char* strTypeName) = 0;
	//设置查询条件
	virtual bool SetQueryInfo(char* strFieldName, variant value) = 0;
	//查询
	virtual int Query() = 0;
	//设置字段值
	virtual	int SetFieldValueByName(char* idIn,uint timeIn,char* fieldname, variant* value) = 0;
	virtual	int GetFieldValueByIndex(int fieldindex,  variant* value) = 0;
	virtual int SetFieldValueByIndex(char* idIn,uint timeIn,int fieldindex, variant* value) = 0;
};

#endif 