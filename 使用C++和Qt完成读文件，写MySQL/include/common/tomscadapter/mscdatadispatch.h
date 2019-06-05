//mscdatadispatch.h

#ifndef _MSCDATADISPATCH_PENGSHIKANG_2009_09_23_H_
#define _MSCDATADISPATCH_PENGSHIKANG_2009_09_23_H_

#include "mscdatasender.h"                       // for CMscDataSender

//��Ϣ����ͨ����Ϣ�������������������
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
