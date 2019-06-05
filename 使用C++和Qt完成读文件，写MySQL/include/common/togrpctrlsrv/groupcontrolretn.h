//groupcontrolretn.h                             // for CGroupControlRetn

#ifndef _GROUPCONTROLRETURN_PENGSHIKANG_2015_07_24_H_
#define _GROUPCONTROLRETURN_PENGSHIKANG_2015_07_24_H_

#include "grpctrldatasender.h"                   // for CGrpCtrlDataSender

//��Ϣ����ͨ����Ϣ�������������������ʵ���Ͷ�ֵ�����ʶ�ֵ��
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
