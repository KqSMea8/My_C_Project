//************************************************************************/
//*  修改履历:
//*  2009-02-19:  增加接口, 返回报警附加信息(Attachment). [zn]
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


/* 报警参数 */
typedef struct 
{
	std::string pname; //名称
	icsvariant  pvalue;//值
	int			punit; //度量单位标识符
	int			pid;   //参数标识符:由报警模块处理产生
	bool		psave; //是否存储:由报警模块处理产生
} AlarmParam;


/* 确认标志 */
typedef enum { ALARM_UNACK = 0, ALARM_ACKED } ALARM_ACK_STATE;


/* 报警动作定义 */
typedef enum 
{	ALARM_AUTO_ACK = 0x0001,  /* 自动确认 */
	ALARM_HIS_STORE= 0x0002,  /* 历史存储 */
	ALARM_SHOW_WIN = 0x0004,  /* 上报警窗 */
	ALARM_POP_PAGE = 0x0008,  /* 推画面 */
	ALARM_SOUND	   = 0x0010,  /* 语音报警 */
	ALARM_EMAIL	   = 0x0020,  /* 发邮件 */
	ALARM_MESSAGE  = 0x0040,  /* 短信报警 */
	ALARM_PRINT	   = 0x0080,  /* 打印报警 */
	ALARM_BELL	   = 0x0100,  /* 电铃报警 */
	ALARM_SIREN	   = 0x0200   /* 电笛报警 */ 
} ALARM_ACT;

//class CStreamAccess;

/* 投递报警时需使用本接口, 填入具体报警信息 */
class IAlarmEventBase : public IICSUnknown
{
public:
	virtual int		GetAlarmId()=0;   //报警配置id: 不能为空
	virtual double	GetAlarmTime()=0; //终端上送报警时间: 不能为空
 
	virtual int		GetObjectId()=0;  //业务对象id: event时取系统标识,alarm时不能为空
	virtual void	GetObjectType(char* ptype, int size)=0; //业务对象类型名
	virtual void	GetObjectDesc(char* pdesc, int size)=0;
	virtual void	GetObjectPath(char* ppath, int size)=0;
	virtual void	GetUserId(char* puid, int size)=0;
	virtual void	GetUserName(char* puname, int size)=0;
	virtual void	GetPageName(char* pname, int size)=0;
	virtual std::list<std::string> GetVoiceNames()=0;
	virtual std::list<AlarmParam>  GetParams()=0;
	virtual int		GetAlarmActs()=0;	//告警动作列表: 为ALARM_ACT类型的值或其组合
	virtual void	GetAttachment(char* pattach, int size) = 0; //附加信息, 如SOE报告
	
	virtual void	SetAlarmId(int alarmid)=0;  //报警配置id: 不能为空
	virtual void	SetAlarmTime(double dt)=0;  //终端上送报警时间: 不能为空
	virtual void	SetObjectId(int objectid)=0;//业务对象id: event时取系统标识,alarm时不能为空
	virtual void	SetObjectType(const char* ptype)=0;//业务对象类型名
	virtual void	SetObjectDesc(const char* pdesc)=0;//业务对象描述信息
	virtual void	SetObjectPath(const char* ppath)=0;//业务对象路径
	virtual void	SetUserId(const char* puid)=0;     //操作/确认人账号, 自动确认取空串
	virtual void	SetUserName(const char* puname)=0; //操作/确认人名称: 对事件或state=ALARM_ACKED的报警有效
	virtual void	SetPageName(const char* pname)=0;  //页面文件名称
	virtual void	SetVoiceNames(const std::list<std::string>& voicenames)=0;//语音文件列表
	virtual void	SetParams(const std::list<AlarmParam>& params)=0;		  //报警参数列表
	virtual void	SetAlarmActs(int alarmacts)=0;     //告警动作列表: 为ALARM_ACT类型的值或其组合
	virtual void	SetAttachment(const char* pattach) = 0; //附加信息, 如SOE报告
	//virtual bool	Load(CStreamAccess* pStream) = 0;
	//virtual bool	Save(CStreamAccess* pStream) = 0;

public:
	static char* GetIntfName() { return IID_IAlarmEventBase; } 

	//20180628 clw add
	virtual double	GetCreateTime()=0; //后台产生报警时间
	virtual void	SetCreateTime(double dt)=0;  //后台产生报警时间
};


/* 接收报警时使用本接口.
 * 
 * 注: (报警配置id, 报警时间, 业务对象id)可确定唯一一条报警信息.
 */
class IAlarmEvent : public IAlarmEventBase
{
public:
	virtual void	GetDesc(char* pdesc, int size)=0;//报警描述串
	virtual int		GetClassId()=0;		//报警类型id
	virtual void	GetClassName(char* pclass, int size)=0;//报警类型
	virtual int		GetLevelId()=0;		//报警级别id
	virtual void	GetLevelName(char* plevel, int size)=0;//报警级别
	virtual int		GetAttributeId()=0; //报警属性id
	virtual void	GetAttributeName(char* pattr, int size)=0;//报警属性:事故、预告、操作、其他等
	virtual std::map<int, std::string> GetGroupTypes()=0;	  //告警分组类型(id, 名称)列表

	virtual ALARM_ACK_STATE GetAckState()=0;			    //是否确认标志
	virtual double	GetAckTime()=0;						    //确认时间: state=ALARM_ACKED时有效

	virtual int		GetPriority()=0;	//报警处理优先级
	virtual void	GetHisTable(char* ptable, int size)=0;  //历史存储表名
	virtual void	GetParamTable(char* ptable, int size)=0;//参数历史存储表名
	virtual int		GetVoiceTimes()=0;				  //语音循环播放次数
	virtual std::list<std::string> GetEmails()=0;	  //电子邮件列表
	virtual std::list<std::string> GetMsgPhones()=0;  //短信号码列表

public:
	static char* GetIntfName() { return IID_IAlarmEvent; }

//	virtual double  GetCreateTime()=0; //后台产生报警时间 
};


/* 接收报警时要实现本接口 */
class IAlarmConsumer : public IICSUnknown
{
public:
	virtual void GetConsumerName(char* pname, int size)=0;//消费者的名字描述
	virtual int  GetLowerLevel()=0;//所要接收报警的下限
	virtual int  GetUpperLevel()=0;//所要接收报警的上限
	virtual void OnAlarmComing(IAlarmEvent* palarm)=0;//当接收到一个报警时使用
	virtual void OnAlarmAcking(IAlarmEvent* palarm, const char* puser, double dt)=0;//报警确认时调用
	virtual void OnAlarmClear(IAlarmEvent* palarm, const char* puser, double dt)=0;//报警清除时调用
	virtual void OnAckAll(const char* puser, double dt)=0;//报警确认全部时调用
	virtual void OnClearAll(const char* puser, double dt)=0;//报警清除全部时调用

public:
	static char* GetIntfName() { return IID_IAlarmConsumer; } 
};


class IAlarmTrans : public IICSUnknown
{
public:
	virtual void PostAlarm(IAlarmEventBase* palarmbase)=0;			  //投递一条报警
	virtual void AckAlarm(IAlarmEvent* palarm, const char* puser)=0;  //确认一条报警
	virtual void ClearAlarm(IAlarmEvent* palarm, const char* puser)=0;//清除一条报警
	virtual void AckAllAlarm(const char* puser)=0;  //确认全部报警
	virtual void ClearAllAlarm(const char* puser)=0;//清除全部报警
	virtual bool RegisterConsumer(IAlarmConsumer* pconsumer)=0;	 //注册报警客户端
	virtual void UnRegisterConsumer(IAlarmConsumer* pconsumer)=0;//反注册报警客户端

public:
	static char* GetIntfName() { return IID_IAlarmTrans; } 
};


//定义智能指针
typedef CQIPtr<IAlarmEventBase>		AlarmEventBase;
typedef CQIPtr<IAlarmEvent>			AlarmEvent;
typedef CQIPtr<IAlarmConsumer>		AlarmConsumer;
typedef CQIPtr<IAlarmTrans>			AlarmTrans;

//定义创建对象函数类型以及函数名称
typedef bool (*Alarm_GetClassObjectMethod)(const char *classname, IICSUnknown** ppUnk);
typedef bool (*Alarm_InitializeMethod)();
typedef bool (*Alarm_UninitializeMethod)();

#define ALARM_METHOD_GETCLASSOBJECT	"GetClassObject"
#define ALARM_METHOD_INITIALIZE		"Initialize"
#define ALARM_METHOD_UNINITIALZIE	"Uninitialize"


#endif  /* __ALARM_INTF_H_INCLUDED__ */
