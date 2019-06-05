#ifndef _DISTR__H_
#define _DISTR__H_

#include "../icsunknown.h"

#define IID_IICSMessageTr	"iicsmessagetr"
#define CLSID_MessageSender	"messagesender"


typedef enum ProcType{Server=1, Client, Unbeknown};	


class IICSMessageSinker: public IICSUnknown
{
public:
	virtual bool  OnMessageComing(char* mesg) = 0;
};

class IICSDisTr: public IICSUnknown
{
public:
	virtual void SetMainProcType(ProcType etype) = 0;
	virtual bool SendToClientMessage(char* mesg) = 0;
 	virtual bool SendDownMessage(char* mesg) = 0;
	virtual bool SendUpMessage(char* mesg) = 0;
	virtual bool RegisterSinker(IICSMessageSinker* pSinker) = 0;
	virtual void UnregisterSinker(IICSMessageSinker* pSinker) = 0;
};

#define MODULE_UIPMESSAGETR	"UIPMessageTr"
typedef bool (*GetClassObjectMethod)(char *classname, IICSUnknown** ppUnk);


#endif
