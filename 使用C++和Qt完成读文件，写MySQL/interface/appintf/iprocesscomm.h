#ifndef _IPROCESSCOMMINTERFACE_H__
#define _IPROCESSCOMMINTERFACE_H__

#define CLSID_MsgClient		"CLSIDMSGCLIENT"
#define CLSID_MsgServer		"CLSIDMSGSERVER"
#define IID_MsgClient		"IIDMSGCLIENT"
#define IID_MsgServer		"IIDMSGSERVER"
#define Module_ProComm		"processcomm"

#define  MSGPART_LEN 1024

//接收缓存默认的最大长度
#define RCVBUF_LENGTH    1024 
#define   MSCENTER_SEND_TIMEOUT                  1000   

#include "objsintf.h"

#include <qstring.h>

class IICSBusObject;

enum EConnectState { eColse = 0, eConnected };
class IMsgCallBack : public IICSUnknown
{
public:
	virtual void ReceiveMsg(const char* sPartner, IICSBusObject *pMsg) = 0;
	virtual void ConnectState(const char* sPartner, int nState) = 0;
};

class IMsgServer : public IICSUnknown
{
public:
	virtual bool Open(int nPort) = 0;
	virtual void PostMsg(const char* sPartner, IICSBusObject *pMsg) = 0;
	virtual void SetMsgCallBack(IMsgCallBack *pCallBack) = 0;
};

class IMsgClient : public IICSUnknown
{
public:
	virtual bool Connect(const QString& sHost, int nPoint) = 0;
	virtual bool PostMsg(IICSBusObject *pMsg) = 0;
	virtual void SetMsgCallBack(IMsgCallBack *pCallBack) = 0;
};

#endif