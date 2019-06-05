//mscdatagcsetvalue.h

#ifndef _MSCDATAAGCSETVALUE_PENGSHIKANG_2015_07_07_H_
#define _MSCDATAAGCSETVALUE_PENGSHIKANG_2015_07_07_H_

#include "mscdatasender.h"                       // for CMscDataSender

//��Ϣ����ͨ����Ϣ�������������������AGC��ֵ��ѹ������
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
