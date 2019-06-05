//hissaveintvalue.h

#ifndef _HISSAVEINTVALUE_PENGSHIKANG_2015_07_09_H_
#define _HISSAVEINTVALUE_PENGSHIKANG_2015_07_09_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//��Ϣ����ͨ����Ϣ����������������������Ͷ�ֵ��ѹ�壩
class CHisSaveIntValue : public CMscDataHisSave
{
public:
	CHisSaveIntValue(bool toCenter=true) : CMscDataHisSave(toCenter)
	{
		CMscDataHisSave::InitMessageHead(CControlMsg::DispatchSwitch, 2 + sizeof(int) );
	};
	
	void SetTaskValue(short taskType, int dataValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(taskType);
		m_stream.WriteInt(dataValue);
	}
};

#endif
