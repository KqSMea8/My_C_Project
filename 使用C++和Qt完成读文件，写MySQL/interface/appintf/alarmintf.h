/********************************************************************************
文件名:		AlarmIntf.h
功  能:		定义客户端口报警接口
说  明:	
		1	报警对象访问接口(IAlarmObject)
		2	客户端实现的报警接受接口(IAlarmConsumer)
		3	报警类型树接口(IAlarmTypeTree)
最后修改日期：2005-8-23
*********************************************************************************/
#ifndef _ALARMINTF__H_
#define _ALARMINTF__H_
#include "objsintf.h"

//定义接口ID
#define IID_IAlarmObject    "IAlarmObject"
#define IID_IAlarmConsumer  "IAlarmConsumer"
#define IID_IAlarmTypeTree  "IAlarmTypeTree"

#define IID_IBufAlarmObject		"IBufAlarmObject"

#define CLSID_AlarmTypeTree "alarmtypetree"

#define CLSID_AnalogGrade       "analoggrade"
#define CLSID_AnalogUupper      "analoguuper"
#define CLSID_AnalogUpper       "analogupper"
#define CLSID_AnalogLower       "analoglower"
#define CLSID_AnalogLlower      "analogllower"
#define CLSID_AnalogManualset   "analogmanualset"
#define CLSID_AnalogProb        "analogprob"
#define CLSID_StatusSwitch      "statusswitch"
#define CLSID_StatusManualset   "statusmanualset"
#define CLSID_StatusProb        "statusprob"
#define CLSID_SOEAct            "soeact"
#define CLSID_SOEReport         "soereport"
#define CLSID_PulseManualset    "pulsemanualset"
#define CLSID_PulseProb         "pulseprob"
#define CLSID_IEDComm           "iedcomm"
#define CLSID_IEDRepair         "iedrepair"
#define CLSID_NodeComm          "nodecomm"
#define CLSID_NodeEvent			"nodeevent"
#define CLSID_NodeEventTypeInfo	"nodeventtypeinfo"
#define CLSID_SmartAlarm		"smartalarm"
#define CLSID_SmartAlarmTypeInfo "smartalarmtypeinfo"

//2011-2-16 zqx add ied substitude alarmtype.
#define CLSID_AnalogSubstituded   "analogsubstituded"
#define CLSID_StatusSubstituded   "statussubstituded"
#define CLSID_PulseSubstituded    "pulsesubstituded"
#define CLSID_AnalogubstitudedTypeInfo   "analogsubstitudedtypeinfo"
#define CLSID_PulseSubstitudedTypeInfo   "pulsesubstitudedtypeinfo"
#define CLSID_StatusSubstitudedTypeInfo   "statusubstitudedtypeinfo"
#define CLSID_ServerSwitch      "serverswitch"
#define CLSID_ManualSwitchServer "manualswitchserver"
#define CLSID_ChnlComm          "chnlcomm"
#define CLSID_ChnlSwitch        "chnlswitch"
#define CLSID_ChnlgrpComm       "chnlgrpcomm"
#define CLSID_UserLog           "userlog"
#define CLSID_StartPrevent      "startprevent"
#define CLSID_LogicalSet		"logicalset"
#define CLSID_ControlSelect     "controlselect"
#define CLSID_ControlExecute    "controlexecute"
#define CLSID_ControlCancel     "controlcancel"
#define CLSID_ControlPrevent    "controlprevent"
#define CLSID_PreventControl	"preventcontrol"
#define CLSID_BayRepair			"bayrepair"
#define CLSID_IEDLock			"iedlock"
#define CLSID_IEDEvent			"iedevent"
#define CLSID_BayLock			"baylock"
#define CLSID_StationLock		"stationlock"
#define CLSID_StationRunDay		"stationrunday"
#define CLSID_GPSStatus			"gpsstatus"
#define CLSID_GroupControl		"groupcontrol"

//增加客户端与服务器连接异常报警 2006/11/20
#define CLSID_ServerConn		"serverconn"
#define CLSID_ServerConnTypeInfo		"serverconntypeinfo"
#define CLSID_SeqControl			"seqcontrol"	
#define CLSID_SimulatorOperare		"simulatoroperare"
#define CLSID_SimulatorOperareTypeInfo "simulatoroperaretypeinfo"		

#define CLSID_AnalogGradeTypeInfo       "analoggradetypeinfo"
#define CLSID_AnalogUupperTypeInfo      "analoguupertypeinfo"
#define CLSID_AnalogUpperTypeInfo       "analoguppertypeinfo"
#define CLSID_AnalogLowerTypeInfo       "analoglowertypeinfo"
#define CLSID_AnalogLlowerTypeInfo      "analogllowertypeinfo"
#define CLSID_AnalogManualsetTypeInfo   "analogmanualsettypeinfo"
#define CLSID_AnalogProbTypeInfo        "analogprobtypeinfo"
#define CLSID_StatusSwitchTypeInfo      "statusswitchtypeinfo"
#define CLSID_StatusManualsetTypeInfo   "statusmanualsettypeinfo"
#define CLSID_StatusProbTypeInfo        "statusprobtypeinfo"
#define CLSID_SOEActTypeInfo            "soeacttypeinfo"
#define CLSID_SOEReportTypeInfo         "soereporttypeinfo"
#define CLSID_PulseManualsetTypeInfo    "pulsemanualsettypeinfo"
#define CLSID_PulseProbTypeInfo         "pulseprobtypeinfo"
#define CLSID_IEDCommTypeInfo           "iedcommtypeinfo"
#define CLSID_IEDEventTypeInfo			"iedeventtypeinfo"
#define CLSID_IEDRepairTypeInfo         "iedrepairtypeinfo"
#define CLSID_NodeCommTypeInfo          "nodecommtypeinfo"
#define CLSID_ServerSwitchTypeInfo      "serverswitchtypeinfo"
#define CLSID_ManualSwitchServerTypeInfo "manualswitchservertypeinfo"
#define CLSID_ChnlCommTypeInfo          "chnlcommtypeinfo"
#define CLSID_ChnlSwitchTypeInfo        "chnlswitchtypeinfo"
#define CLSID_ChnlgrpCommTypeInfo       "chnlgrpcommtypeinfo"
#define CLSID_UserLogTypeInfo           "userlogtypeinfo"
#define CLSID_StartPreventTypeInfo      "startpreventtypeinfo"
#define CLSID_LogicalSetTypeInfo		"logicalsettypeinfo"
#define CLSID_ControlSelectTypeInfo     "controlselecttypeinfo"
#define CLSID_ControlExecuteTypeInfo    "controlexecutetypeinfo"
#define CLSID_ControlCancelTypeInfo     "controlcanceltypeinfo"
#define CLSID_ControlPreventTypeInfo    "controlpreventtypeinfo"
#define CLSID_PreventControlTypeInfo	"preventcontroltypeinfo"
#define CLSID_BayRepairTypeInfo			"bayrepairtypeinfo"
#define CLSID_IEDLockTypeInfo			"iedlocktypeinfo"
#define CLSID_BayLockTypeInfo			"baylocktypeinfo"
#define CLSID_StationLockTypeInfo		"stationlocktypeinfo"
#define CLSID_StationRunDayTypeInfo		"stationrundaytypeinfo"
#define CLSID_GPSStatusTypeInfo			"gpsstatustypeinfo"
#define CLSID_GroupControlTypeInfo		"groupcontroltypeinfo"
#define CLISD_SeqControlTypeInfo		"seqcontroltypeinfo"

#define CLSID_CvtAbnormal				"cvqabnormal"
#define CLSID_CvtAbnormalTypeInfo		"cvqabnormaltypeinfo"

#define CLSID_FileData					"filedata"
#define CLSID_FileDataTypeInfo			"filedatatypeinfo"

#define CLSID_FaultAlarm				"faultalarm"
#define CLSID_AlarmAlarm				"alarmalarm"

#define CLSID_ReAlarm					"realarm"
#define CLSID_ReAlarmTypeInfo			"realarmtypeinfo"

#define CLSID_VQCAlarm					"vqcalarm"
#define CLSID_VQCAlarmTypeInfo			"vqcalarmtypeinfo"

#define CLSID_RepairAlarm				"repairalarm"
#define CLSID_RepairAlarmTypeInfo		"repairalarmtypeinfo"

#define CLSID_SELFTEST					"selftest"
//增加全部告警操作(全部确认、全部清除)类型
#define ALARM_OPERATEALL				"operateall"

#define CLSID_CommonTypeInfo			"commonalarminfo"
#define CLSID_CommonType				"commonalarm"

#define CLSID_DataAnylse				"dataanylse"
#define CLSID_DataAnylseTypeInfo		"dataanylsetypeinfo"	

#define CLSID_IEDState					"iedstate"
#define CLSID_IEDStateTypeInfo			"iedstatetypeinfo"

//报警访问接口
class IAlarmObject : public IICSUnknown
{
public:    
    //获取报警类型名称
    virtual void GetTypeName(char* name, int size)=0;
	//获取报警类型描述
	virtual void GetTypeDesc(char* type, int size)=0;
	//获取报警对象类型名称
    virtual void GetObjType(char* name, int size)=0;
	//获取报警对象短名称(名称短路径)
    virtual void GetObjName(char* name, int size)=0;
	//获取报警对象ID
    virtual void GetObjID(int* id)=0;
	//获取报警对象全路径
	virtual void GetObjLogicalPath(char* obj, int size)=0;
	//获取报警相关的用户信息
	virtual void GetUserDesc(char* user, int size)=0;
	//获取动作信息
	virtual void GetActionDesc(char* act, int size)=0;
	//得到数据的个数
	virtual int GetDataNum()=0;
	//得到数据
	virtual void GetData(double* data, int size)=0;
	//获取报警时间
	virtual double GetTime()=0;
	//获取报警级别
	virtual int GetLevel()=0;
	//获取报警操作状态
	virtual int GetOperate()=0;
	//克隆一个AlarmObject接口
	virtual bool Clone(IAlarmObject** ppObj)=0;
	//本地系列化
	virtual bool LocalSerialize(bool bLoad, IICSStream* pStream)=0;
	//远方系列化
	virtual bool RemoteSerialize(bool bLoad, IICSStream* pStream)=0;
	//获取报警对象短名称
	virtual void GetObjNamePath(char* cPath, int nSize)=0;
public:
	static char* GetIntfName() {return IID_IAlarmObject;}; 
};

//定义报警扩展接口
#define IID_IExAlarmObject "IExAlarmObject"

class IExAlarmObject : public IAlarmObject
{
public:
	//获取报警产生的时间
	virtual double GetEmitTime() = 0;
	//获取厂站ID
	virtual int GetStationID() = 0;
	//获取间隔ID
	virtual int GetBayID() = 0;
	//获取业务类型ID, 只有遥信变位和保护事件有, 其余报警均为0
	virtual int GetTaskTypeID() = 0;
	//获取报警描述
	virtual void GetDescriptiom(char* description, int size) = 0;
	//获取动作标志标志, 例如越限为1, 越限恢复为0
	virtual int GetException() = 0;
	//获取报警类型的唯一标记ID
	virtual int GetAlarmTypeID() = 0;
public:
	static char* GetIntfName() {return IID_IExAlarmObject;};
};

//定值扩展报警智能指针
typedef CQIPtr<IExAlarmObject> ExAlarmObject;

//定义获取报警类型唯一标记ID函数名称
#define METHOD_GETALARMTYPEID "GetAlarmTypeID"

//定义获取报警类型唯一标记ID的函数原型
typedef int (*GetAlarmTypeIDMethod)(IICSTypeInfo* pAlarmTypeInfo);

#define OBJNAME_LEN			32
#define OBJNAMEPATH_LEN		128
#define BOJLOGICALPATH_LEN	256
#define VOICEFILE_LEN		64
#define ACTIONCOMMENT_LEN	128

/*
定义快速报警的结构:保护动作(soeact)以及遥信变位(statusswitch)
*/
struct BUFALARM
{
	char ObjName[OBJNAME_LEN];
	char ObjNamePath[OBJNAMEPATH_LEN];
	char ObjLogicalPath[BOJLOGICALPATH_LEN];
	char VoiceFile[VOICEFILE_LEN];
	char ActionComment[ACTIONCOMMENT_LEN];
	int  Value;
	int	 Level;
	int  Exception;
	double Time;
	int Action;
	int Operate;
	int ObjID;
	int Type;
	int AlarmTypeID;
	ITaskObject* pObject;
};
 
/*保护动作以及遥信变位报警对象实现了该接口
定义该接口的目的是避免使用报警对象实现的IICSRtdbObject进行访问报警的属性(效率低)
*/
class IBufAlarmObject : public IAlarmObject
{
public:
	virtual void SetBufAlarm(const BUFALARM* alarm) = 0;
	//如果alarm->pObject获取成功(不为空),获取后需要释放获得的对象(alamr->pObject->Release())
	virtual void GetBufAlarm(BUFALARM* alarm) = 0;
};

//报警接受接口
class IAlarmConsumer : public IICSUnknown
{
public:
	//消费者的名字描述
	virtual void GetConsumerName(char* name, int size)=0;

	//所要接收报警的下限
	virtual int GetLowerLevel()=0;

	//所要接收报警的上限
	virtual int GetUpperLevel()=0;

	//当接收到一个报警时使用
	virtual void OnAlarmComing(IAlarmObject* pAlarmObject)=0;

	//报警确认时调用
	virtual void OnAlarmAcking(IAlarmObject* pAlarmObject, IUserObject* pUser)=0;

	//报警清除时调用
	virtual void OnAlarmClear(IAlarmObject* pAlarmObject, IUserObject* pUser)=0;

public:
	static char* GetIntfName() {return IID_IAlarmConsumer;}; 
};

#define IID_IExAlarmConsumer	"IExAlarmConsumer"

//定义扩展报警消费接口
class IExAlarmConsumer : public IAlarmConsumer
{
public:
	//按照类型确认
	virtual void OnAlarmAckingByType(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser) = 0;
	
	//按照类型清除
	virtual void OnAlarmClearByType(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser) = 0;
public:
	static char* GetIntfName() {return IID_IExAlarmConsumer;}; 
};

typedef CQIPtr<IExAlarmConsumer> ExAlarmConsumer;

//报警类型树接口
class IAlarmTypeTree : public IICSUnknown
{
public:
	virtual	bool GetObjAlarmType(char* objtype, IICSEnum** ppEnum)=0;
	virtual int GetAlarmTypeID(IICSTypeInfo* pAlarmTypeInfo) = 0;
public:
	static char* GetIntfName() {return IID_IAlarmTypeTree;}
};

//定义报警对象模块名称
#define MODULE_ALARMOBJECTS "ICSAlarmObjects"

//定义客户端报警模块名称
#define MODULE_ALARMCLIENT	"AlarmClient"
#define MODULE_ALARMSERVER	"AlarmService"

//定义共享库MODULE_ALARMCLIENT导出函数的名称
#define METHOD_POSTALARM "PostAlarm"
#define METHOD_ACKALARM "AckAlarmObject"
#define METHOD_CLEARALARM "ClearAlarmObject"
#define METHOD_REGISTERALARM "RegisterConsumer"
#define METHOD_UNREGISTERALARM "UnregisterConsumer"
#define METHOD_REGISTLOCAL		"RegisterLocal"

//定义按照类型确认清除接口函数
#define METHOD_ACKALARMBYTYPE		"AckAlarmByType"
#define METHOD_CLEARALARMBYTYPE		"ClearAlarmByType"

typedef bool (*AckAlarmByTypeMethod)(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser);

typedef bool (*ClearAlarmByTypeMethod)(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser);

/*
【说  明】	1,定义注册报警接收的函数指针类型
			2,该函数由共享库MODULE_ALARMCLIENT导出,共享库中函数名为REGISTERALARM
*/
typedef bool (*RegisterConsumerMethod)(IAlarmConsumer* consumer);

/*
【说  明】	1,定义注消报警接收的函数指针类型
			2,该函数由共享库MODULE_ALARMCLIENT导出,共享库中函数名为UNREGISTERALARM
*/
typedef void (*UnregisterConsumerMehtod)(IAlarmConsumer* consumer);

typedef bool (*PostAlarmMethod)(IAlarmObject* alarm);
typedef bool (*AckAlarmMethod)(IAlarmObject* alacrm, IUserObject* pUser);
typedef bool (*ClearAlarmMethod)(IAlarmObject* alarm, IUserObject* pUser);

//定义智能指针
typedef CQIPtr<IAlarmObject> AlarmObject;
typedef CQIPtr<IAlarmConsumer> AlarmConsumer;
typedef CQIPtr<IAlarmTypeTree> AlarmTypeTree;

#endif
