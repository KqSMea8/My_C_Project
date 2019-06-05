//mscdatahissave.h

#ifndef _MSCDATAHISSAVE_PENGSHIKANG_2015_07_09_H_
#define _MSCDATAHISSAVE_PENGSHIKANG_2015_07_09_H_

#include "hissavesender.h"                       // for CHisSaveSender

//消息数据通过消息中心往其他服务程序发送
class CMscDataHisSave : public CHisSaveSender
{
public:
	CMscDataHisSave(bool toCenter) : CHisSaveSender(toCenter, EVENT_MSGT){ };
	
protected:
	void InitMessageHead(CControlMsg::MsgType msgType, long msgLen)
	{
		CHisSaveSender::InitMessageHead(CControlMsg::GroupHistorySave, msgType, msgLen);
	}
};

#endif
