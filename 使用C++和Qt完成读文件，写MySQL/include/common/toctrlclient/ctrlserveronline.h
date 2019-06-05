//ctrlserveronline.h                             // for CCtrlServerOnline

#ifndef _CONTROLSERVERONLINE_PENGSHIKANG_2015_07_10_H_
#define _CONTROLSERVERONLINE_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                        // for CCtrlClientSender

//消息数据通过消息中心往其他服务程序发送
class CCtrlServerOnline : public CCtrlClientSender
{
public:
	CCtrlServerOnline() : CCtrlClientSender(true)
	{
		InitMessageHead(CControlMsg::GroupConnection, CControlMsg::SERVERONLINE, 0);
	}
};

#endif
