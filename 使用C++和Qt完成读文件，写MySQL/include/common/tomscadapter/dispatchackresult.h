//dispatchackresult.h

#ifndef _DISPATCHACKRESULT_PENGSHIKANG_2015_07_07_H_
#define _DISPATCHACKRESULT_PENGSHIKANG_2015_07_07_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue

//消息数据通过消息中心往其他服务程序发送消息命令处理结果
class CDispatchAckResult : public CMscDatAgcSetvalue
{
public:
	CDispatchAckResult(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 6)
	{
		m_stream.SkipAfter(1, false);
		m_stream.WriteBYTE(CControlMsg::TASKRESULT);
	};
	
	void SetAckResult(short taskType, CControlMsg::MsgType msgRslt)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(taskType);
		m_stream.WriteInt(msgRslt);
	}
};

#endif
