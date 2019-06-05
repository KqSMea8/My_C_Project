//mscdatadispatch.h

#ifndef _MSCDATADISPATCH_PENGSHIKANG_2009_09_23_H_
#define _MSCDATADISPATCH_PENGSHIKANG_2009_09_23_H_

#include "mscdatasender.h"                       // for CMscDataSender

//消息数据通过消息中心往其他服务程序发送
class CMscDataDispatch : public CMscDataSender
{
public:
	CMscDataDispatch(bool toCenter) : CMscDataSender(toCenter, FD_MSC_MSGT){ };
	
protected:
	void InitMessageHead(CControlMsg::MsgType msgType, long msgLen)
	{
		CMscDataSender::InitMessageHead(CControlMsg::GroupFiveDefense, msgType, msgLen);
	}
};

#endif
