//mscdatagcsetvalue.h

#ifndef _MSCDATAAGCSETVALUE_PENGSHIKANG_2015_07_07_H_
#define _MSCDATAAGCSETVALUE_PENGSHIKANG_2015_07_07_H_

#include "mscdatasender.h"                       // for CMscDataSender

//消息数据通过消息中心往其他服务程序发送AGC定值与压板数据
class CMscDatAgcSetvalue : public CMscDataSender
{
public:
	CMscDatAgcSetvalue(bool toCenter, int msgLen) : CMscDataSender(toCenter, (toCenter?SEND_CURVE_MSGT:RECV_CURVE_MSGT))
	{
		CMscDataSender::InitMessageHead( CControlMsg::GroupDispatch, 
			(toCenter ? CControlMsg::TASKSEND : CControlMsg::TASKRECV), msgLen );
	};
};

#endif
