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

//������״̬��������--��ģ��TaskObject����
#define CLSID_BayState		"baystate"

//����Ʊ�����Լ�����Ʊxmlfile��ticketobjectģ�鴴��
#define CLSID_TicketObject	"ticketobject"
#define CLSID_TicketXMLFile	"ticketxmlfile"

#define MODULE_TICKETOBJECT	"ticketobject"

//��������������������
typedef ITaskObject IBayState;

//������򻯲�������(һ��Ʊ;����Ʊ;���Ʊ)
typedef enum {TT_ONE, TT_SECOND, TT_COMPLEX}TicketType;

//�������Ʊ����
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

//�����������--�Ӳ���Ʊ
typedef IOpStep ISTicket;

//��������ӿ�
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

//����Ʊ�ӿ�
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
	
	//���Ӳ���,������ü������sticket,�����Ʊ�Զ�ת������Ϊ���Ʊ
	//0 <= index < �����������
	virtual bool AppendStep(int index, ISTicket** ppTicket) = 0;
	virtual bool AppendStep(int index, IOP** ppOP) = 0;

	//�ƶ�����
	virtual bool MoveUpStep(IOpStep* pOpStep) = 0;
	virtual bool MoveDownStep(IOpStep* pOpStep) = 0;

	//ɾ������
	virtual bool DelStep(int index) = 0;
	virtual bool DelStep(IOpStep* pOpStep) = 0;

	//ö�ٲ���Ʊ����
	virtual void EnumSteps(IICSEnum** ppEnum) = 0;
	//��ȡ����Ʊ����
	virtual bool GetStep(int index, IOpStep** ppStep) = 0;
	virtual int GetStepCount() = 0;
};

//����Ʊ����ӿ�---ʵʱ���еĲ���Ʊ����
class ITicketObject : public IICSRtdbObject
{
public:
	virtual int GetID() = 0;
	//װ�ز���Ʊ����
	virtual bool LoadByIOA(ITaskObject* pIED, int ioa) = 0;
	virtual bool LoadByState(IBayState* src, IBayState* dst) = 0;
	//ö�ٲ���Ʊ����
	virtual bool GetTicketObjects(ITaskObject* pBay, ITicketObject** ppTicketObject) = 0;
	virtual void EnumTicketObjects(ITaskObject* pBay, IICSEnum** ppEnum) = 0;
	//���û�ȡ���״̬����
	virtual bool SetBayState(IBayState* src, IBayState* dst) = 0;
	virtual bool GetBayState(IBayState** ppSrc, IBayState** ppDst) = 0;
	//����/��ȡ��������
	virtual void SetTicketType(TicketType tt) = 0;
	virtual TicketType GetTicketType() = 0;
	//����/��ȡ����
	virtual void SetDesc(const char* desc) = 0;
	virtual void GetDesc(char* desc, int size) = 0;
	//��������Ʊ: 1,��������Ʊ���� 2�ٴ�������Ʊ
	virtual bool NewTicketObject(ITicketObject** ppTicketObject) = 0;
	virtual bool CreateTicket(ITicket** pTicket) = 0;
	//ɾ������Ʊ����
	virtual bool DelTicketObject() = 0;
};

//����Ʊ�洢�ӿ�
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