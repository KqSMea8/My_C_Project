//mscdatacontrol.h

#ifndef _MSCDATACONTROL_PENGSHIKANG_2011_08_08_H_
#define _MSCDATACONTROL_PENGSHIKANG_2011_08_08_H_

#include "mscdatasender.h"                       // for CMscDataSender

//消息数据通过消息中心往其他服务程序发送
class CMscDataControl : public CMscDataSender
{
public:
	CMscDataControl(bool toCenter) : CMscDataSender(toCenter, CTRL_MSC_MSGT){ };
	
protected:
	void InitMessageHead(CControlMsg::MsgType msgType, long msgLen)
	{
		CMscDataSender::InitMessageHead(CControlMsg::GroupSCADAControl, msgType, msgLen);
	}
	
};

#endif
