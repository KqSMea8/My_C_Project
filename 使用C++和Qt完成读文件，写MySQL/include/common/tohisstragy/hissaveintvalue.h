//hissaveintvalue.h

#ifndef _HISSAVEINTVALUE_PENGSHIKANG_2015_07_09_H_
#define _HISSAVEINTVALUE_PENGSHIKANG_2015_07_09_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//消息数据通过消息中心往其他服务程序发送整型定值（压板）
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
