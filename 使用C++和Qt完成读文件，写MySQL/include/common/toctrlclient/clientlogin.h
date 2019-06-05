//clientlogin.h

#ifndef _CONTROLCLIENTLOGIN_PENGSHIKANG_2015_07_10_H_
#define _CONTROLCLIENTLOGIN_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                   // for CCtrlClientSender

//通过消息中心往控制客户端发送登录信息
class CClientLogin : public CCtrlClientSender
{
public:
	CClientLogin(bool toCenter=true) : CCtrlClientSender(toCenter)
	{
		InitMessageHead(CControlMsg::GroupConnection, CControlMsg::LOGINSUCCESS, 260);
	};
	
	void SetLoginInfo(const char* sReceiver, int serviceId)
	{
		SetReceiverName(sReceiver);
		m_stream.SkipAfter(2, false);
		m_stream.WriteString(sReceiver);
		m_stream.WriteInt(serviceId);
	}
};

#endif
