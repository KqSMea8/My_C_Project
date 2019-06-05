//chgmscdispatch.h

#ifndef _CHARGESTATIONMESSAGEDISPATCH_PENGSHIKANG_2017_04_26_H_
#define _CHARGESTATIONMESSAGEDISPATCH_PENGSHIKANG_2017_04_26_H_

#include "chgmscsender.h"                       // for CChgMscSender

//消息数据通过消息中心往其他服务程序发送
class CChgMscDispatch : public CChgMscSender
{
public:
	CChgMscDispatch(bool toCenter) : CChgMscSender(toCenter, FD_MSC_MSGT){ };
	
protected:
	void InitMessageHead(CControlMsg::MsgType msgType, long msgLen)
	{
		CChgMscSender::InitMessageHead(CControlMsg::GroupDispatch, msgType, msgLen);
	}
};

#endif
