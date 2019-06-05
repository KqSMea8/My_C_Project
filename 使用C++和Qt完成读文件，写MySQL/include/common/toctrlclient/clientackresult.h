//clientackresult.h

#ifndef _CONTROLCLIENTACKRESULT_PENGSHIKANG_2015_07_10_H_
#define _CONTROLCLIENTACKRESULT_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                        // for CCtrlClientSender

//消息数据通过消息中心往其他服务程序发送
class CClientAckResult : public CCtrlClientSender
{
public:
	CClientAckResult(bool toCenter=true) : CCtrlClientSender(toCenter)
	{
		InitMessageHead(CControlMsg::GroupDispatch, CControlMsg::TASKRESULT, 6);
	};

	void SetAckResult(const char* sReceiver, short taskType, CControlMsg::MsgType msgRslt)
	{
		SetReceiverName(sReceiver);
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(taskType);
		m_stream.WriteInt(msgRslt);
	}
};

#endif
