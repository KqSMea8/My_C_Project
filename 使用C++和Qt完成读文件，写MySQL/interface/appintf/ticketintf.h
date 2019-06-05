#ifndef _TICKETINTF__H_
#define _TICKETINTF__H_

#include "../objsintf.h"

#define IID_IOp				"iop"
#define IID_IOpStep			"iopstep"
#define IID_ISTicket		IID_IOpStep
#define IID_ITicket			"iticket"
#define IID_ITicketObject	"iticketobject"
#define IID_ITicketXMLFile	"iticketxmlfile"

class IOpStep;
class IOP;
class ITicket;
class ITicketObject;
class ITicketXMLFile;

//定义间隔状态对象类名--由模块TaskObject创建
#define CLSID_BayState		"baystate"

//操作票对象以及操作票xmlfile由ticketobject模块创建
#define CLSID_TicketObject	"ticketobject"
#define CLSID_TicketXMLFile	"ticketxmlfile"

#define MODULE_TICKETOBJECT	"ticketobject"

//间隔对象纳入对象体现中
typedef ITaskObject IBayState;

//定义程序化操作类型(一次票;二次票;组合票)
typedef enum {TT_ONE, TT_SECOND, TT_COMPLEX}TicketType;

//定义操作票步骤
class IOpStep : public IICSUnknown
{
public:
	virtual int GetIndex() = 0;
	virtual bool IsSTicket() = 0;
	virtual void SetIOA(int ioa) = 0;
	virtual int GetIOA() = 0; 
	virtual void SetAddr(int addr) = 0;
	virtual int GetAddr() = 0;
	virtual void SetDesc(const char* desc) = 0;
	virtual void GetDesc(char* desc, int size) = 0;
};

//定义操作步骤--子操作票
typedef IOpStep ISTicket;

//操作步骤接口
class IOP : public IOpStep
{
public:
	virtual void SetCtrlVal(int val) = 0;
	virtual int GetCtrlVal() = 0;
	virtual int GetRelIOA() = 0;
	virtual void SetRelIOA(int ioa) = 0;
	virtual void SetRelVal(int val) = 0;
	virtual int GetRelVal() = 0;
	virtual void SetTimeOut(int sec) = 0;
	virtual int GetTimeOut() = 0;
	virtual void SetConfirm(bool b) = 0;
	virtual bool IsConfirm() = 0;
	virtual void SetSkip(bool b) = 0;
	virtual bool IsSkip() = 0;
	virtual void SetDirect(bool b) = 0;
	virtual bool IsDirect() = 0;
	virtual void SetInteval(int sec) = 0;
	virtual int GetInteval() = 0;
};

//操作票接口
class ITicket : public IICSUnknown
{
public:
	virtual TicketType GetType() = 0;
	virtual void SetType(TicketType t) = 0;
	virtual void SetIOA(int ioa) = 0;
	virtual int GetIOA() = 0;
	virtual void SetAddr(int addr) = 0;
	virtual int GetAddr() = 0;
	virtual void SetDesc(const char* desc) = 0;
	virtual void GetDesc(char* desc, int size) = 0;
	
	//增加步骤,如果调用加入的是sticket,则操作票自动转换类型为组合票
	//0 <= index < 操作步骤个数
	virtual bool AppendStep(int index, ISTicket** ppTicket) = 0;
	virtual bool AppendStep(int index, IOP** ppOP) = 0;

	//移动步骤
	virtual bool MoveUpStep(IOpStep* pOpStep) = 0;
	virtual bool MoveDownStep(IOpStep* pOpStep) = 0;

	//删除步骤
	virtual bool DelStep(int index) = 0;
	virtual bool DelStep(IOpStep* pOpStep) = 0;

	//枚举操作票步骤
	virtual void EnumSteps(IICSEnum** ppEnum) = 0;
	//获取操作票步骤
	virtual bool GetStep(int index, IOpStep** ppStep) = 0;
	virtual int GetStepCount() = 0;
};

//操作票对象接口---实时库中的操作票对象
class ITicketObject : public IICSRtdbObject
{
public:
	virtual int GetID() = 0;
	//装载操作票对象
	virtual bool LoadByIOA(ITaskObject* pIED, int ioa) = 0;
	virtual bool LoadByState(IBayState* src, IBayState* dst) = 0;
	//枚举操作票对象
	virtual bool GetTicketObjects(ITaskObject* pBay, ITicketObject** ppTicketObject) = 0;
	virtual void EnumTicketObjects(ITaskObject* pBay, IICSEnum** ppEnum) = 0;
	//设置获取间隔状态对象
	virtual bool SetBayState(IBayState* src, IBayState* dst) = 0;
	virtual bool GetBayState(IBayState** ppSrc, IBayState** ppDst) = 0;
	//设置/获取操作类型
	virtual void SetTicketType(TicketType tt) = 0;
	virtual TicketType GetTicketType() = 0;
	//设置/获取描述
	virtual void SetDesc(const char* desc) = 0;
	virtual void GetDesc(char* desc, int size) = 0;
	//创建操作票: 1,创建操作票对象 2再创建操作票
	virtual bool NewTicketObject(ITicketObject** ppTicketObject) = 0;
	virtual bool CreateTicket(ITicket** pTicket) = 0;
	//删除操作票对象
	virtual bool DelTicketObject() = 0;
};

//操作票存储接口
class ITicketXMLFile : public IICSUnknown
{
public:
	virtual bool LoadFromXML(const char* xml) = 0;
	virtual bool SaveToXML(const char* xml) = 0;
	virtual void AppendTicket(ITicket* pTicket) = 0;
	virtual bool DelTicket(int addr, int ioa) = 0;
	virtual bool GetTicket(int addr, int ioa, ITicket** ppTicket) = 0;
	virtual bool CreateTicket(int addr, int ioa, ITicket** ppTicket) = 0;
	virtual void RemoveAllTickets() = 0;
};

#endif