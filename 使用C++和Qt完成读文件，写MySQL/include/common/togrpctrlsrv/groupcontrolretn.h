//groupcontrolretn.h                             // for CGroupControlRetn

#ifndef _GROUPCONTROLRETURN_PENGSHIKANG_2015_07_24_H_
#define _GROUPCONTROLRETURN_PENGSHIKANG_2015_07_24_H_

#include "grpctrldatasender.h"                   // for CGrpCtrlDataSender

//消息数据通过消息中心往其他服务程序发送实数型定值（功率定值）
class CGroupControlRetn : public CGrpCtrlDataSender
{
public:
	CGroupControlRetn(bool toDevice=false) : CGrpCtrlDataSender(toDevice, GRPCTRL_MSC_MSGT)
	{
		InitMessageHead(CControlMsg::GroupAllControl, CControlMsg::GRPCTRLRESULT, 6);
	};
	
	void SetControlResult(short ctrlKind, float ctrlRslt)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(ctrlKind);
		m_stream.WriteInt(ctrlRslt);
	}
};

#endif
