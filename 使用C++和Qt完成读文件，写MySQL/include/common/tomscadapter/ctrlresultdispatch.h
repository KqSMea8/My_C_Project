//ctrlresultdispatch.h

#ifndef _CONTROLINFORESULTDISPATCH_PENGSHIKANG_2011_08_18_H_
#define _CONTROLINFORESULTDISPATCH_PENGSHIKANG_2011_08_18_H_

#include "mscdatadispatch.h"                     // for CMscDataDispatch

//��Ϣ����ͨ����Ϣ�������������������
class CCtrlResultDispatch : public CMscDataDispatch
{
public:
	// (BYTE)msgGroup | (BYTE)msgType
	// msgGroup = CControlMsg::GroupFiveDefense;
	CCtrlResultDispatch(bool toCenter=true) : CMscDataDispatch(toCenter)
	{
		InitMessageHead(CControlMsg::TypeNone, 0);
	};
	
	void SetCtrlResultInfo(CControlMsg::MsgType msgType)
	{
		m_stream.SkipAfter(1, false);
		m_stream.WriteBYTE(msgType);
	}
	
};

#endif
