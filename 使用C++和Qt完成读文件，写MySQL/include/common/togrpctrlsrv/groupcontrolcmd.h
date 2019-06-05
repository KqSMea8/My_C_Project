//groupcontrolcmd.h                              // for CGroupControlCmd

#ifndef _GROUPCONTROLCOMMAND_PENGSHIKANG_2015_07_24_H_
#define _GROUPCONTROLCOMMAND_PENGSHIKANG_2015_07_24_H_

#include "grpctrldatasender.h"                   // for CGrpCtrlDataSender

//��Ϣ����ͨ����Ϣ�������������������ʵ���Ͷ�ֵ�����ʶ�ֵ��
class CGroupControlCmd : public CGrpCtrlDataSender
{
public:
	CGroupControlCmd(bool toDevice=true) : CGrpCtrlDataSender(toDevice, GRPCTRL_MSC_MSGT)
	{
		InitMessageHead(CControlMsg::GroupAllControl, CControlMsg::GROUPCTRL, 6);
	};
	
	void SetControlValue(short ctrlKind, float ctrlValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(ctrlKind);
		m_stream.WriteFloat(ctrlValue);
	}
};

#endif
