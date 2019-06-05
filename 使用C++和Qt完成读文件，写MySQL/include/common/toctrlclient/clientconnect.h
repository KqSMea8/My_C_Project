//clientconnect.h

#ifndef _CONTROLCLIENTCONNECT_PENGSHIKANG_2015_07_10_H_
#define _CONTROLCLIENTCONNECT_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                   // for CCtrlClientSender

//通过消息中心往控制客户端发送连接状态信息
class CClientConnect : public CCtrlClientSender
{
public:
	CClientConnect(bool toCenter=true) : CCtrlClientSender(toCenter)
	{
		CMscDataSender::InitMessageHead(CControlMsg::GroupConnection, CControlMsg::TypeNone, 0);
	};
	
	void SetConnectState(const char* sReceiver, CControlMsg::MsgType connState)
	{
		SetReceiverName(sReceiver);
		m_stream.SkipAfter(1, false);
		m_stream.WriteBYTE(connState);
	}
};

#endif
