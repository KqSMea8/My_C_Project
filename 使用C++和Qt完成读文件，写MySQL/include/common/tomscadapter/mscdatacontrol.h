//mscdatacontrol.h

#ifndef _MSCDATACONTROL_PENGSHIKANG_2011_08_08_H_
#define _MSCDATACONTROL_PENGSHIKANG_2011_08_08_H_

#include "mscdatasender.h"                       // for CMscDataSender

//��Ϣ����ͨ����Ϣ�������������������
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
