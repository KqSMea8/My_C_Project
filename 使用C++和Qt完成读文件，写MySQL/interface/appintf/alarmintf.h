/********************************************************************************
�ļ���:		AlarmIntf.h
��  ��:		����ͻ��˿ڱ����ӿ�
˵  ��:	
		1	����������ʽӿ�(IAlarmObject)
		2	�ͻ���ʵ�ֵı������ܽӿ�(IAlarmConsumer)
		3	�����������ӿ�(IAlarmTypeTree)
����޸����ڣ�2005-8-23
*********************************************************************************/
#ifndef _ALARMINTF__H_
#define _ALARMINTF__H_
#include "objsintf.h"

//����ӿ�ID
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

//���ӿͻ���������������쳣���� 2006/11/20
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
//����ȫ���澯����(ȫ��ȷ�ϡ�ȫ�����)����
#define ALARM_OPERATEALL				"operateall"

#define CLSID_CommonTypeInfo			"commonalarminfo"
#define CLSID_CommonType				"commonalarm"

#define CLSID_DataAnylse				"dataanylse"
#define CLSID_DataAnylseTypeInfo		"dataanylsetypeinfo"	

#define CLSID_IEDState					"iedstate"
#define CLSID_IEDStateTypeInfo			"iedstatetypeinfo"

//�������ʽӿ�
class IAlarmObject : public IICSUnknown
{
public:    
    //��ȡ������������
    virtual void GetTypeName(char* name, int size)=0;
	//��ȡ������������
	virtual void GetTypeDesc(char* type, int size)=0;
	//��ȡ����������������
    virtual void GetObjType(char* name, int size)=0;
	//��ȡ�������������(���ƶ�·��)
    virtual void GetObjName(char* name, int size)=0;
	//��ȡ��������ID
    virtual void GetObjID(int* id)=0;
	//��ȡ��������ȫ·��
	virtual void GetObjLogicalPath(char* obj, int size)=0;
	//��ȡ������ص��û���Ϣ
	virtual void GetUserDesc(char* user, int size)=0;
	//��ȡ������Ϣ
	virtual void GetActionDesc(char* act, int size)=0;
	//�õ����ݵĸ���
	virtual int GetDataNum()=0;
	//�õ�����
	virtual void GetData(double* data, int size)=0;
	//��ȡ����ʱ��
	virtual double GetTime()=0;
	//��ȡ��������
	virtual int GetLevel()=0;
	//��ȡ��������״̬
	virtual int GetOperate()=0;
	//��¡һ��AlarmObject�ӿ�
	virtual bool Clone(IAlarmObject** ppObj)=0;
	//����ϵ�л�
	virtual bool LocalSerialize(bool bLoad, IICSStream* pStream)=0;
	//Զ��ϵ�л�
	virtual bool RemoteSerialize(bool bLoad, IICSStream* pStream)=0;
	//��ȡ�������������
	virtual void GetObjNamePath(char* cPath, int nSize)=0;
public:
	static char* GetIntfName() {return IID_IAlarmObject;}; 
};

//���屨����չ�ӿ�
#define IID_IExAlarmObject "IExAlarmObject"

class IExAlarmObject : public IAlarmObject
{
public:
	//��ȡ����������ʱ��
	virtual double GetEmitTime() = 0;
	//��ȡ��վID
	virtual int GetStationID() = 0;
	//��ȡ���ID
	virtual int GetBayID() = 0;
	//��ȡҵ������ID, ֻ��ң�ű�λ�ͱ����¼���, ���౨����Ϊ0
	virtual int GetTaskTypeID() = 0;
	//��ȡ��������
	virtual void GetDescriptiom(char* description, int size) = 0;
	//��ȡ������־��־, ����Խ��Ϊ1, Խ�޻ָ�Ϊ0
	virtual int GetException() = 0;
	//��ȡ�������͵�Ψһ���ID
	virtual int GetAlarmTypeID() = 0;
public:
	static char* GetIntfName() {return IID_IExAlarmObject;};
};

//��ֵ��չ��������ָ��
typedef CQIPtr<IExAlarmObject> ExAlarmObject;

//�����ȡ��������Ψһ���ID��������
#define METHOD_GETALARMTYPEID "GetAlarmTypeID"

//�����ȡ��������Ψһ���ID�ĺ���ԭ��
typedef int (*GetAlarmTypeIDMethod)(IICSTypeInfo* pAlarmTypeInfo);

#define OBJNAME_LEN			32
#define OBJNAMEPATH_LEN		128
#define BOJLOGICALPATH_LEN	256
#define VOICEFILE_LEN		64
#define ACTIONCOMMENT_LEN	128

/*
������ٱ����Ľṹ:��������(soeact)�Լ�ң�ű�λ(statusswitch)
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
 
/*���������Լ�ң�ű�λ��������ʵ���˸ýӿ�
����ýӿڵ�Ŀ���Ǳ���ʹ�ñ�������ʵ�ֵ�IICSRtdbObject���з��ʱ���������(Ч�ʵ�)
*/
class IBufAlarmObject : public IAlarmObject
{
public:
	virtual void SetBufAlarm(const BUFALARM* alarm) = 0;
	//���alarm->pObject��ȡ�ɹ�(��Ϊ��),��ȡ����Ҫ�ͷŻ�õĶ���(alamr->pObject->Release())
	virtual void GetBufAlarm(BUFALARM* alarm) = 0;
};

//�������ܽӿ�
class IAlarmConsumer : public IICSUnknown
{
public:
	//�����ߵ���������
	virtual void GetConsumerName(char* name, int size)=0;

	//��Ҫ���ձ���������
	virtual int GetLowerLevel()=0;

	//��Ҫ���ձ���������
	virtual int GetUpperLevel()=0;

	//�����յ�һ������ʱʹ��
	virtual void OnAlarmComing(IAlarmObject* pAlarmObject)=0;

	//����ȷ��ʱ����
	virtual void OnAlarmAcking(IAlarmObject* pAlarmObject, IUserObject* pUser)=0;

	//�������ʱ����
	virtual void OnAlarmClear(IAlarmObject* pAlarmObject, IUserObject* pUser)=0;

public:
	static char* GetIntfName() {return IID_IAlarmConsumer;}; 
};

#define IID_IExAlarmConsumer	"IExAlarmConsumer"

//������չ�������ѽӿ�
class IExAlarmConsumer : public IAlarmConsumer
{
public:
	//��������ȷ��
	virtual void OnAlarmAckingByType(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser) = 0;
	
	//�����������
	virtual void OnAlarmClearByType(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser) = 0;
public:
	static char* GetIntfName() {return IID_IExAlarmConsumer;}; 
};

typedef CQIPtr<IExAlarmConsumer> ExAlarmConsumer;

//�����������ӿ�
class IAlarmTypeTree : public IICSUnknown
{
public:
	virtual	bool GetObjAlarmType(char* objtype, IICSEnum** ppEnum)=0;
	virtual int GetAlarmTypeID(IICSTypeInfo* pAlarmTypeInfo) = 0;
public:
	static char* GetIntfName() {return IID_IAlarmTypeTree;}
};

//���屨������ģ������
#define MODULE_ALARMOBJECTS "ICSAlarmObjects"

//����ͻ��˱���ģ������
#define MODULE_ALARMCLIENT	"AlarmClient"
#define MODULE_ALARMSERVER	"AlarmService"

//���干���MODULE_ALARMCLIENT��������������
#define METHOD_POSTALARM "PostAlarm"
#define METHOD_ACKALARM "AckAlarmObject"
#define METHOD_CLEARALARM "ClearAlarmObject"
#define METHOD_REGISTERALARM "RegisterConsumer"
#define METHOD_UNREGISTERALARM "UnregisterConsumer"
#define METHOD_REGISTLOCAL		"RegisterLocal"

//���尴������ȷ������ӿں���
#define METHOD_ACKALARMBYTYPE		"AckAlarmByType"
#define METHOD_CLEARALARMBYTYPE		"ClearAlarmByType"

typedef bool (*AckAlarmByTypeMethod)(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser);

typedef bool (*ClearAlarmByTypeMethod)(const char* alarmtype, const char* objtype, int objid, IUserObject* pUser);

/*
��˵  ����	1,����ע�ᱨ�����յĺ���ָ������
			2,�ú����ɹ����MODULE_ALARMCLIENT����,������к�����ΪREGISTERALARM
*/
typedef bool (*RegisterConsumerMethod)(IAlarmConsumer* consumer);

/*
��˵  ����	1,����ע���������յĺ���ָ������
			2,�ú����ɹ����MODULE_ALARMCLIENT����,������к�����ΪUNREGISTERALARM
*/
typedef void (*UnregisterConsumerMehtod)(IAlarmConsumer* consumer);

typedef bool (*PostAlarmMethod)(IAlarmObject* alarm);
typedef bool (*AckAlarmMethod)(IAlarmObject* alacrm, IUserObject* pUser);
typedef bool (*ClearAlarmMethod)(IAlarmObject* alarm, IUserObject* pUser);

//��������ָ��
typedef CQIPtr<IAlarmObject> AlarmObject;
typedef CQIPtr<IAlarmConsumer> AlarmConsumer;
typedef CQIPtr<IAlarmTypeTree> AlarmTypeTree;

#endif
