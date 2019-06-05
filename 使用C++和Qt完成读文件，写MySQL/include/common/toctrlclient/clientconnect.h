//clientconnect.h

#ifndef _CONTROLCLIENTCONNECT_PENGSHIKANG_2015_07_10_H_
#define _CONTROLCLIENTCONNECT_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                   // for CCtrlClientSender

//ͨ����Ϣ���������ƿͻ��˷�������״̬��Ϣ
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
