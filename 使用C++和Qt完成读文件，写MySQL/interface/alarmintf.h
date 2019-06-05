//************************************************************************/
//*  �޸�����:
//*  2009-02-19:  ���ӽӿ�, ���ر���������Ϣ(Attachment). [zn]
//************************************************************************/

#ifndef __ALARM_INTF_H_INCLUDED__
#define __ALARM_INTF_H_INCLUDED__

#include <string>
#include <list>
#include <map>
#include "icsunknown.h"
#include "qiptr.h"
#include "icsvalue.h"


/* constants definition */

#define MODULE_ALARMCLIENT		"alarmclient"

#define IID_IAlarmEventBase		"ialarmeventbase"
#define IID_IAlarmEvent			"ialarmevent"
#define CLSID_AlarmEventBase	"alarmeventbase"

#define IID_IAlarmConsumer		"ialarmconsumer"
#define IID_IAlarmTrans			"ialarmtrans"
#define CLSID_AlarmTrans		"alarmtrans"


/* �������� */
typedef struct 
{
	std::string pname; //����
	icsvariant  pvalue;//ֵ
	int			punit; //������λ��ʶ��
	int			pid;   //������ʶ��:�ɱ���ģ�鴦�����
	bool		psave; //�Ƿ�洢:�ɱ���ģ�鴦�����
} AlarmParam;


/* ȷ�ϱ�־ */
typedef enum { ALARM_UNACK = 0, ALARM_ACKED } ALARM_ACK_STATE;


/* ������������ */
typedef enum 
{	ALARM_AUTO_ACK = 0x0001,  /* �Զ�ȷ�� */
	ALARM_HIS_STORE= 0x0002,  /* ��ʷ�洢 */
	ALARM_SHOW_WIN = 0x0004,  /* �ϱ����� */
	ALARM_POP_PAGE = 0x0008,  /* �ƻ��� */
	ALARM_SOUND	   = 0x0010,  /* �������� */
	ALARM_EMAIL	   = 0x0020,  /* ���ʼ� */
	ALARM_MESSAGE  = 0x0040,  /* ���ű��� */
	ALARM_PRINT	   = 0x0080,  /* ��ӡ���� */
	ALARM_BELL	   = 0x0100,  /* ���屨�� */
	ALARM_SIREN	   = 0x0200   /* ��ѱ��� */ 
} ALARM_ACT;

//class CStreamAccess;

/* Ͷ�ݱ���ʱ��ʹ�ñ��ӿ�, ������屨����Ϣ */
class IAlarmEventBase : public IICSUnknown
{
public:
	virtual int		GetAlarmId()=0;   //��������id: ����Ϊ��
	virtual double	GetAlarmTime()=0; //�ն����ͱ���ʱ��: ����Ϊ��
 
	virtual int		GetObjectId()=0;  //ҵ�����id: eventʱȡϵͳ��ʶ,alarmʱ����Ϊ��
	virtual void	GetObjectType(char* ptype, int size)=0; //ҵ�����������
	virtual void	GetObjectDesc(char* pdesc, int size)=0;
	virtual void	GetObjectPath(char* ppath, int size)=0;
	virtual void	GetUserId(char* puid, int size)=0;
	virtual void	GetUserName(char* puname, int size)=0;
	virtual void	GetPageName(char* pname, int size)=0;
	virtual std::list<std::string> GetVoiceNames()=0;
	virtual std::list<AlarmParam>  GetParams()=0;
	virtual int		GetAlarmActs()=0;	//�澯�����б�: ΪALARM_ACT���͵�ֵ�������
	virtual void	GetAttachment(char* pattach, int size) = 0; //������Ϣ, ��SOE����
	
	virtual void	SetAlarmId(int alarmid)=0;  //��������id: ����Ϊ��
	virtual void	SetAlarmTime(double dt)=0;  //�ն����ͱ���ʱ��: ����Ϊ��
	virtual void	SetObjectId(int objectid)=0;//ҵ�����id: eventʱȡϵͳ��ʶ,alarmʱ����Ϊ��
	virtual void	SetObjectType(const char* ptype)=0;//ҵ�����������
	virtual void	SetObjectDesc(const char* pdesc)=0;//ҵ�����������Ϣ
	virtual void	SetObjectPath(const char* ppath)=0;//ҵ�����·��
	virtual void	SetUserId(const char* puid)=0;     //����/ȷ�����˺�, �Զ�ȷ��ȡ�մ�
	virtual void	SetUserName(const char* puname)=0; //����/ȷ��������: ���¼���state=ALARM_ACKED�ı�����Ч
	virtual void	SetPageName(const char* pname)=0;  //ҳ���ļ�����
	virtual void	SetVoiceNames(const std::list<std::string>& voicenames)=0;//�����ļ��б�
	virtual void	SetParams(const std::list<AlarmParam>& params)=0;		  //���������б�
	virtual void	SetAlarmActs(int alarmacts)=0;     //�澯�����б�: ΪALARM_ACT���͵�ֵ�������
	virtual void	SetAttachment(const char* pattach) = 0; //������Ϣ, ��SOE����
	//virtual bool	Load(CStreamAccess* pStream) = 0;
	//virtual bool	Save(CStreamAccess* pStream) = 0;

public:
	static char* GetIntfName() { return IID_IAlarmEventBase; } 

	//20180628 clw add
	virtual double	GetCreateTime()=0; //��̨��������ʱ��
	virtual void	SetCreateTime(double dt)=0;  //��̨��������ʱ��
};


/* ���ձ���ʱʹ�ñ��ӿ�.
 * 
 * ע: (��������id, ����ʱ��, ҵ�����id)��ȷ��Ψһһ��������Ϣ.
 */
class IAlarmEvent : public IAlarmEventBase
{
public:
	virtual void	GetDesc(char* pdesc, int size)=0;//����������
	virtual int		GetClassId()=0;		//��������id
	virtual void	GetClassName(char* pclass, int size)=0;//��������
	virtual int		GetLevelId()=0;		//��������id
	virtual void	GetLevelName(char* plevel, int size)=0;//��������
	virtual int		GetAttributeId()=0; //��������id
	virtual void	GetAttributeName(char* pattr, int size)=0;//��������:�¹ʡ�Ԥ�桢������������
	virtual std::map<int, std::string> GetGroupTypes()=0;	  //�澯��������(id, ����)�б�

	virtual ALARM_ACK_STATE GetAckState()=0;			    //�Ƿ�ȷ�ϱ�־
	virtual double	GetAckTime()=0;						    //ȷ��ʱ��: state=ALARM_ACKEDʱ��Ч

	virtual int		GetPriority()=0;	//�����������ȼ�
	virtual void	GetHisTable(char* ptable, int size)=0;  //��ʷ�洢����
	virtual void	GetParamTable(char* ptable, int size)=0;//������ʷ�洢����
	virtual int		GetVoiceTimes()=0;				  //����ѭ�����Ŵ���
	virtual std::list<std::string> GetEmails()=0;	  //�����ʼ��б�
	virtual std::list<std::string> GetMsgPhones()=0;  //���ź����б�

public:
	static char* GetIntfName() { return IID_IAlarmEvent; }

//	virtual double  GetCreateTime()=0; //��̨��������ʱ�� 
};


/* ���ձ���ʱҪʵ�ֱ��ӿ� */
class IAlarmConsumer : public IICSUnknown
{
public:
	virtual void GetConsumerName(char* pname, int size)=0;//�����ߵ���������
	virtual int  GetLowerLevel()=0;//��Ҫ���ձ���������
	virtual int  GetUpperLevel()=0;//��Ҫ���ձ���������
	virtual void OnAlarmComing(IAlarmEvent* palarm)=0;//�����յ�һ������ʱʹ��
	virtual void OnAlarmAcking(IAlarmEvent* palarm, const char* puser, double dt)=0;//����ȷ��ʱ����
	virtual void OnAlarmClear(IAlarmEvent* palarm, const char* puser, double dt)=0;//�������ʱ����
	virtual void OnAckAll(const char* puser, double dt)=0;//����ȷ��ȫ��ʱ����
	virtual void OnClearAll(const char* puser, double dt)=0;//�������ȫ��ʱ����

public:
	static char* GetIntfName() { return IID_IAlarmConsumer; } 
};


class IAlarmTrans : public IICSUnknown
{
public:
	virtual void PostAlarm(IAlarmEventBase* palarmbase)=0;			  //Ͷ��һ������
	virtual void AckAlarm(IAlarmEvent* palarm, const char* puser)=0;  //ȷ��һ������
	virtual void ClearAlarm(IAlarmEvent* palarm, const char* puser)=0;//���һ������
	virtual void AckAllAlarm(const char* puser)=0;  //ȷ��ȫ������
	virtual void ClearAllAlarm(const char* puser)=0;//���ȫ������
	virtual bool RegisterConsumer(IAlarmConsumer* pconsumer)=0;	 //ע�ᱨ���ͻ���
	virtual void UnRegisterConsumer(IAlarmConsumer* pconsumer)=0;//��ע�ᱨ���ͻ���

public:
	static char* GetIntfName() { return IID_IAlarmTrans; } 
};


//��������ָ��
typedef CQIPtr<IAlarmEventBase>		AlarmEventBase;
typedef CQIPtr<IAlarmEvent>			AlarmEvent;
typedef CQIPtr<IAlarmConsumer>		AlarmConsumer;
typedef CQIPtr<IAlarmTrans>			AlarmTrans;

//���崴�������������Լ���������
typedef bool (*Alarm_GetClassObjectMethod)(const char *classname, IICSUnknown** ppUnk);
typedef bool (*Alarm_InitializeMethod)();
typedef bool (*Alarm_UninitializeMethod)();

#define ALARM_METHOD_GETCLASSOBJECT	"GetClassObject"
#define ALARM_METHOD_INITIALIZE		"Initialize"
#define ALARM_METHOD_UNINITIALZIE	"Uninitialize"


#endif  /* __ALARM_INTF_H_INCLUDED__ */
