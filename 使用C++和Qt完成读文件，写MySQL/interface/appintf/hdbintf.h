#ifndef __INTERFACE__H
#define __INTERFACE__H
#include "icsunknown.h"
#include "objsintf.h"

//��ѯ����
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


//���󷵻���
#define QUERY_SUCCESS		0		//��ѯ�ɹ�		
#define ACCESS_ERROR	   	-1		//���ݿ���ʳ���
#define NORECORD_ERROR		-2		//δ�鵽��Ӧ��¼
#define TIME_ERROR			-3		//ʱ����������
#define CONNECT_ERROR		-4		//���ݿ����ӳ���
#define NO_FIELD     		-5		//û�д��ֶ�

//�澯���Ͷ���
#define ANALOG_ALARM		1	    //ģ�����澯
#define STATUS_ALARM		2		//�������澯
#define PULSE_ALARM			3		//������澯
#define SOE_ALARM			4		//SOE���澯
#define CONTROL_ALARM		5		//ң�ز����澯
#define COMM_ALARM			6		//ͨ���¼��澯
#define SYSTEM_ALARM		7		//ϵͳ�¼��澯

//��������
#define	STATION				1		// վ�澯����		�����ڸ�վ�����е�ң�⡢ң�š�ң�ء�SOE�澯
#define	BAY					2		// ����澯����	�����ڸü�������е�ң�⡢ң�š�ң�ء�SOE�澯
#define	IED					3		// װ�ø澯����	�����ڸ�װ�������е�ң�⡢ң�š�ң�ء�SOE�澯
#define	ANALOG				4		// ģ�����澯���� ������ң������и澯
#define	STATUS				5		// ״̬���澯����	������ң�ŵ����и澯
#define	OPEREVENT			6		// �����澯����	�����ò��������и澯
#define	CONTROL				7		// �������澯���� ������ң���������и澯
#define	SETTING				8		// ��ֵ�澯����	�����ö�ֵ�����и澯
#define	SOEALARM			9		// SOE�澯����	������SOE�����и澯
#define	COMEVENT			10		// ͨѶ�澯����	������ͨѶ��������и澯
#define	SYSEVENT			11		// ϵͳ�澯����	�����ڵ㡢�û���¼�˳���ͨѶ�����и澯
#define	NODE				12		// �ڵ�澯����
#define	USER				13		// �û���¼�˳��澯����

//���Ͷ��壺
//ģ������
#define	ANALOG_UUP_LIMIT		1			// Խ�����ޣ�
#define	ANALOG_UP_LIMIT			2			// Խ���ޣ�
#define	ANALOG_DOWN_LIMIT		3			// Խ���ޣ�
#define	ANALOG_DDOWN_LIMIT		4			// Խ�����ޣ�
#define	ANALOG_RE_UUP_LIMIT		5			// Խ�����޻ָ���
#define	ANALOG_RE_UP_LIMIT		6			// Խ���޻ָ���
#define	ANALOG_RE_DOWN_LIMIT	7			// Խ���޻ָ���
#define	ANALOG_RE_DDOWN_LIMIT	8			// Խ�����޻ָ�
#define	ANALOG_GRADE_ALARM		9			// �ݶȱ���
#define	ANALOG_RE_GRADE_ALARM	10			// �ݶȱ����ָ�

//��������
#define	STATUS_CHANGE			21			// ��λ��
//�����¼�
#define	PULSE_MAN_SET			31			// �˹�������
#define	PULSE_RE_MAN_SET		32			// ȡ���˹�������
#define	PULSE_SET_USE			33			// ���Ͷ�룻
#define	PULSE_SET_UNUSE			34			//����˳���
//SOE�¼���
#define	SOE_SINGLE				41			// ����ң��SOE��
#define	SOE_DOUBLE				42			// ˫��ң��SOE��
#define	SOE_SINGLE_EVENT		43			// ���������¼�SOE��
#define	SOE_GROUP_START_EVENT	44			// �������������¼�SOE��
#define	SOE_GROUP_OUT_EVENT		45			// ������������¼�SOE��
#define	SOE_PRO_EVENT			46			// �����¼���
#define	SOE_PRO_ALRM			47			// �����澯
//ң���¼���
#define	CTRL_WF_CHECK			51			// �����飻
#define	CTRL_SELET_ORDER		52			// ѡ���
#define	CTRL_OPER_ORDER			53			// ִ���
#define	CTRL_CHECK				54			// ң��У�飻
#define	CTRL_CANCEL				55			// ң��ȡ��
#define	CTRL_END				56			// ң�ؽ���
#define	CTRL_LOCK				57			// �������
#define	CTRL_TIMEOUT			58			// �����ʱ
#define	CTRL_WF_MISMATCH		59			// ���������ң�ض���ƥ��
#define	CTRL_WF_PASS			60			// ���ͨ��
//ͨѶ״̬��
#define	IED_COM_INTERRUPT		71			// װ��ͨѶ�жϣ�
#define	IED_COM_RESET			72			// װ��ͨѶ�ָ���
#define CHANNEL_GROUP_INTERRUPT 73          // ͨ����ͨѶ�жϣ�
#define CHANNEL_GROUP_RESET     74          // ͨ����ͨѶ�ָ���
#define CHANNEL_INTERRUPT		75          // ͨ��ͨѶ�жϣ�
#define CHANNEL_RESET			76          // ͨ��ͨѶ�ָ���
#define CHANNEL_SWITCH_BACK		77          // ͨ�������л�����->������
#define CHANNEL_SWITCH_MAIN		78          // ͨ�������л�����->������
#define	NODE_COM_INTERRUPT		79			// �ڵ�ͨѶ�жϣ�
#define	NODE_COM_RESET			80			// �ڵ�ͨѶ�ָ�
#define	NODE_SWITCH_BACK		81			// �ڵ������л�����->������
#define	NODE_SWITCH_MAIN		82			// �ڵ������л�����->������

//ϵͳ�¼���
#define	USER_LOGIN				91			// �û���¼��
#define	USER_LOGOUT				92			// �û��˳���
#define	BAY_RUN					93			// ������У���Event_NodeID��ʾ���ID��
#define	BAY_CHECK				94			// ������ޣ���Event_NodeID��ʾ���ID��
#define	IED_UNUSER				95			// װ�ù��ƣ���Event_NodeID��ʾװ��ID��
#define	IED_USER				96			// װ��ժ�ƣ���Event_NodeID��ʾװ��ID��
#define	BAY_LOCK				97			// �����������Event_NodeID��ʾ���ID��
#define	BAY_UNLOCK				98			// �����������Event_NodeID��ʾ���ID��
#define	IED_LOCK				99			// װ�ñ�������Event_NodeID��ʾװ��ID��
#define	IED_UNLOCK				100			// װ�ÿ�������Event_NodeID��ʾװ��ID��
#define	GROUNDING				101			// С�����ӵأ�
#define	NODE_LOGIN				102			// �ڵ��¼����Event_NodeID��ʾ�ڵ�ID��
#define	NODE_LOGOUT				103			// �ڵ��˳�����Event_NodeID��ʾ�ڵ�ID��
#define	NODE_WF_RUN				104			// �����������Event_NodeID��ʾ�ڵ�ID��
#define	NODE_WF_END				105			// �ر��������Event_NodeID��ʾ�ڵ�ID��
#define	NODE_VQC_RUN			106			// VQC��
#define	NODE_GPS_RUN			107			// GPS
#define	NODE_SWITCH_BACK_MENU	108			// �ֶ��л�����->��������Event_NodeID��ʾ�����������ڵ�ID��Event_OperatorID��ʾ�����������ڵ�ID��
#define	NODE_SWITCH_MAIN_MENU	109			// �ֶ��л�����->��������Event_NodeID��ʾ�����������ڵ�ID��
#define	BAY_DESIGN				110			// ����滮����Event_NodeID��ʾ���ID��
#define	IED_DESIGN				111			// װ�ù滮����Event_NodeID��ʾ���ID��

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


typedef unsigned int uint;  //�����޷�������
//����ֵ����
#define OK                   0      //Get����ֵ��ȷ�����򷵻������С

#define IID_IICSHisAccess			"IICSHisAccess"
#define IID_IICSHisTypeTree			"IICSHisTypeTree"
#define IID_IICSQueryTypeTree       "IICSQueryTypeTree"

class IICSHisAccess : public IICSUnknown
{
public:
	virtual int GetRecordCount () = 0;			//ȡ�ü�¼��
	virtual void MoveFirst() = 0;				//�ƶ�����һ����¼
	virtual void MoveLast() = 0;				//�ƶ������һ����¼
	virtual bool MoveNext() = 0;				//�ƶ�����һ��
	virtual void MovePri () = 0;				//�ƶ�����һ��
	virtual void MoveTo(int nIndex) = 0;        //�ƶ���ָ����¼
	//ȡ���ֶ�ֵ
	virtual	int GetFieldValueByName(char* fieldname,  variant* value) = 0;
	//���ò�ѯ����
    virtual void SetQueryType(char* strTypeName) = 0;
	//���ò�ѯ����
	virtual bool SetQueryInfo(char* strFieldName, variant value) = 0;
	//��ѯ
	virtual int Query() = 0;
	//�����ֶ�ֵ
	virtual	int SetFieldValueByName(char* idIn,uint timeIn,char* fieldname, variant* value) = 0;
	virtual	int GetFieldValueByIndex(int fieldindex,  variant* value) = 0;
	virtual int SetFieldValueByIndex(char* idIn,uint timeIn,int fieldindex, variant* value) = 0;
};

#endif 