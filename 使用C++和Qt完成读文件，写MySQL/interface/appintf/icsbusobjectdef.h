#ifndef _ICSTASKBUS__H_
#define _ICSTASKBUS__H_

#include "../objsintf.h"
#include <qvariant.h>
#include <q3ptrlist.h>

/*
	icsbusobjects模块实现：
	1，由CLSID_BusTypeTree，可创建总线对象类型树
	2，由类型树描述类型，可创建指定类型对象
	3，由对象可查询对象类型信息及其字段类型信息
	4，传输IICSRtdbObject对象时，可作为总线对象的字段
*/


// 定义接口名称常量
#define IID_IICSBusObject		"IICSBusObject"
#define IID_IICSDynBusObject	"IICSDynBusObject"
#define IID_IICSMsgBusOrder		"IICSMsgBusOrder"
#define IID_IICSMsgBusSinker	"IICSMsgBusSinker"


// 定义对象名称常量
#define CLSID_BusObject			"busobject"
#define CLSID_DyncBusObject		"dyncbusobject"
// 注：busTypeTree对象实现IID_IICSTypeTree接口
#define CLSID_BusTypeTree		"bustypetree"
// 创建总线命令器参数：客户端/服务器
#define CLSID_ObjectSender		"messagesender"


// 定义对象模块名称
#define MODULE_BUSOBJECTS		"icsbusobjects"
#define MODULE_MESSAGETR		"ICSMsgBusComps"


/*
	IICSBusObject: 业务总线对象访问接口
*/
class IICSBusObject : public IICSUnknown
{
public:
	// 获取类型信息
	virtual bool GetTypeInfo(IICSTypeInfo** ppTypeInfo) = 0;
	// 获取字段列表
	virtual bool GetFields(IICSEnum** ppEnum) = 0;

	// 获取/设置字段属性
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

// 对象未考虑嵌套子对象!

/*
	IICSDynBusObject: 业务总线动态对象访问接口
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
IICSMsgBusSinker: 业务总线接收器访问接口
*/
class IICSMsgBusSinker : public IICSUnknown
{
public:
	enum ProcType{Server=1, Client, Unbeknown};	
	enum SERVER_ROLE
	{
		ROLE_UNKNOWN = 0,	//未知角色
		ROLE_ENABLED,		// 主用角色: 1
		ROLE_STANDBY,		// 备用角色: 2
	};

	//设置加载者是服务端还是客户端1:服务端；2：客户端；
	virtual int GetMainProcType() = 0;
	
	// 获取接收器类型(模块类型),向消息中心注册时使用 
	virtual int GetLoginType() = 0;
	
	// 获取接收器名称(模块名)，向消息中心注册时使用 
	virtual char* GetLoginName() = 0;
	
	//获取注册的消息类型，向消息中心注册时使用 
	virtual int GetLoginMsgType() = 0;
	
	// 总线数据对象接收
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
IICSMsgBusOrder: 业务总线命令器访问接口
*/
class IICSMsgBusOrder : public IICSUnknown
{
public:
	typedef	enum PostType { BT_TOPARTNER = 0, BT_BYPARTTYPE=1, BT_BYMSGTYPE};
	
	//消息中心IP地址，若为单网，请将ip2设为NULL(0), port2设为0
	virtual void SetConnectIP(char* iP1, unsigned short port1, char* ip2, unsigned short port2) = 0;

	virtual void SetSinker( IICSMsgBusSinker* sinker) = 0;
	
	// 指定发送方式：1，发给指定模块；2，按照模块类型发送；3，按照消息类型发送
	virtual void SetPostType(int iPostType) = 0;
	
	// 总线对象发送(指定接收者)，选择发送方式为1时，必须正确设置接收者
	virtual void SetParter(char* parter) = 0;
	
	//指定接收者得类型，选择发送方式为2时，必须正确设置接收者类型
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

// 扩展的类型信息，在本接口中进行定义


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
