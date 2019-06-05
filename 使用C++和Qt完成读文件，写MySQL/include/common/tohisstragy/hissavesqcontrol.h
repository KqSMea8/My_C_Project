//hissavesqcontrol.h

#ifndef _HISSAVESQCONTROL_PENGSHIKANG_2015_07_09_H_
#define _HISSAVESQCONTROL_PENGSHIKANG_2015_07_09_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//��Ϣ����ͨ����Ϣ����������������������Ͷ�ֵ��ѹ�壩
class CHisSaveSqcontrol : public CMscDataHisSave
{
public:
	CHisSaveSqcontrol(bool toCenter=true) : CMscDataHisSave(toCenter)
	{
		CMscDataHisSave::InitMessageHead(CControlMsg::SeqCtrlResult, 280 );
	};
	
	void SetTaskValue(int sctrlId, unsigned char flag, const char* content)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(sctrlId);
		m_stream.WriteBYTE(flag);
		m_stream.WriteString(content);
	}
};

#endif
