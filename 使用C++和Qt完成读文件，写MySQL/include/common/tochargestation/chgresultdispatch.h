//chgresultdispatch.h

#ifndef _CHARGESTATIONRESULTDISPATCH_PENGSHIKANG_2017_04_26_H_
#define _CHARGESTATIONRESULTDISPATCH_PENGSHIKANG_2017_04_26_H_

#include "chgmscdispatch.h"                      // for CChgMscDispatch

//��Ϣ����ͨ����Ϣ�������������������
class CChgResultDispatch : public CChgMscDispatch
{
public:
	// (BYTE)msgGroup | (BYTE)msgType
	// msgGroup = CControlMsg::GroupFiveDefense;
	CChgResultDispatch(bool toCenter=true) : CChgMscDispatch(toCenter)
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
