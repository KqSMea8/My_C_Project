//ctrlserveronline.h                             // for CCtrlServerOnline

#ifndef _CONTROLSERVERONLINE_PENGSHIKANG_2015_07_10_H_
#define _CONTROLSERVERONLINE_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                        // for CCtrlClientSender

//��Ϣ����ͨ����Ϣ�������������������
class CCtrlServerOnline : public CCtrlClientSender
{
public:
	CCtrlServerOnline() : CCtrlClientSender(true)
	{
		InitMessageHead(CControlMsg::GroupConnection, CControlMsg::SERVERONLINE, 0);
	}
};

#endif
