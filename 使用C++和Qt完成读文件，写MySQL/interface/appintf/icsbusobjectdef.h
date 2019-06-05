#ifndef _ICSTASKBUS__H_
#define _ICSTASKBUS__H_

#include "../objsintf.h"
#include <qvariant.h>
#include <q3ptrlist.h>

/*
	icsbusobjectsģ��ʵ�֣�
	1����CLSID_BusTypeTree���ɴ������߶���������
	2�����������������ͣ��ɴ���ָ�����Ͷ���
	3���ɶ���ɲ�ѯ����������Ϣ�����ֶ�������Ϣ
	4������IICSRtdbObject����ʱ������Ϊ���߶�����ֶ�
*/


// ����ӿ����Ƴ���
#define IID_IICSBusObject		"IICSBusObject"
#define IID_IICSDynBusObject	"IICSDynBusObject"
#define IID_IICSMsgBusOrder		"IICSMsgBusOrder"
#define IID_IICSMsgBusSinker	"IICSMsgBusSinker"


// ����������Ƴ���
#define CLSID_BusObject			"busobject"
#define CLSID_DyncBusObject		"dyncbusobject"
// ע��busTypeTree����ʵ��IID_IICSTypeTree�ӿ�
#define CLSID_BusTypeTree		"bustypetree"
// ���������������������ͻ���/������
#define CLSID_ObjectSender		"messagesender"


// �������ģ������
#define MODULE_BUSOBJECTS		"icsbusobjects"
#define MODULE_MESSAGETR		"ICSMsgBusComps"


/*
	IICSBusObject: ҵ�����߶�����ʽӿ�
*/
class IICSBusObject : public IICSUnknown
{
public:
	// ��ȡ������Ϣ
	virtual bool GetTypeInfo(IICSTypeInfo** ppTypeInfo) = 0;
	// ��ȡ�ֶ��б�
	virtual bool GetFields(IICSEnum** ppEnum) = 0;

	// ��ȡ/�����ֶ�����
	virtual bool GetFieldValueByName(char* field, QVariant* var) = 0;
	virtual bool SetFieldValueByName(char* field, QVariant* var) = 0;

	virtual void AppendRecord() = 0;

	virtual bool First() = 0;
    virtual bool Last() = 0;
    virtual bool Next() = 0;
    virtual bool Prev() = 0;

    virtual bool IsEOF() = 0; 
    virtual bool IsBOF() = 0;


public:
	static char *GetIntfName()
	{
		return IID_IICSBusObject;
	};
};

// ����δ����Ƕ���Ӷ���!

/*
	IICSDynBusObject: ҵ�����߶�̬������ʽӿ�
*/
class IICSDynBusObject : public IICSBusObject
{
public:
	virtual bool AppendField(char* field, FIELDTYPE fldType, char* caption = 0) = 0;
	virtual bool RemoveField(char* field) = 0;
public:
	static char *GetIntfName()
	{
		return IID_IICSDynBusObject;
	};
};


/*
IICSMsgBusSinker: ҵ�����߽��������ʽӿ�
*/
class IICSMsgBusSinker : public IICSUnknown
{
public:
	enum ProcType{Server=1, Client, Unbeknown};	
	enum SERVER_ROLE
	{
		ROLE_UNKNOWN = 0,	//δ֪��ɫ
		ROLE_ENABLED,		// ���ý�ɫ: 1
		ROLE_STANDBY,		// ���ý�ɫ: 2
	};

	//���ü������Ƿ���˻��ǿͻ���1:����ˣ�2���ͻ��ˣ�
	virtual int GetMainProcType() = 0;
	
	// ��ȡ����������(ģ������),����Ϣ����ע��ʱʹ�� 
	virtual int GetLoginType() = 0;
	
	// ��ȡ����������(ģ����)������Ϣ����ע��ʱʹ�� 
	virtual char* GetLoginName() = 0;
	
	//��ȡע�����Ϣ���ͣ�����Ϣ����ע��ʱʹ�� 
	virtual int GetLoginMsgType() = 0;
	
	// �������ݶ������
	virtual void MsgReceived(IICSBusObject* busObj) = 0;
	virtual void MsgReceived(IICSEnum* busObjs) = 0;
	virtual void OnServerSwitch(int iMain) = 0;
	virtual void OnLogStaChange(long lResult) = 0;
public:
	static char *GetIntfName()
	{
		return IID_IICSMsgBusSinker;
	};
};

/*
IICSMsgBusOrder: ҵ���������������ʽӿ�
*/
class IICSMsgBusOrder : public IICSUnknown
{
public:
	typedef	enum PostType { BT_TOPARTNER = 0, BT_BYPARTTYPE=1, BT_BYMSGTYPE};
	
	//��Ϣ����IP��ַ����Ϊ�������뽫ip2��ΪNULL(0), port2��Ϊ0
	virtual void SetConnectIP(char* iP1, unsigned short port1, char* ip2, unsigned short port2) = 0;

	virtual void SetSinker( IICSMsgBusSinker* sinker) = 0;
	
	// ָ�����ͷ�ʽ��1������ָ��ģ�飻2������ģ�����ͷ��ͣ�3��������Ϣ���ͷ���
	virtual void SetPostType(int iPostType) = 0;
	
	// ���߶�����(ָ��������)��ѡ���ͷ�ʽΪ1ʱ��������ȷ���ý�����
	virtual void SetParter(char* parter) = 0;
	
	//ָ�������ߵ����ͣ�ѡ���ͷ�ʽΪ2ʱ��������ȷ���ý���������
	virtual void SetParterType(int partertype) = 0;
	
	virtual bool MsgPost(int tMsg, IICSBusObject* busObj) = 0;
	virtual bool MsgPost(int tMsg, IICSEnum* busObjs) = 0;
	
public:
	static char *GetIntfName()
	{
		return IID_IICSMsgBusOrder;
	};
};

typedef Q3PtrList<IICSMsgBusOrder> LISTBUSORDER;

// ��չ��������Ϣ���ڱ��ӿ��н��ж���


/*
#define _ALARM_MSGTYPE		1090
#define _ALARM_OPERATETYPE	1092

#define _ELECTRL_MSGTYPE	0x1080
#define _PREVENT_MSGTYPE	0x1081
#define _OPERATE_MSGTYPE 1190
#define _PROTECT_MSGTYPE 2290	
#define _SETTING_MSGTYPE 1290	
#define _TICKET_MSGTYPE 1300	
// AVC?
// VQC?
*/

#endif
