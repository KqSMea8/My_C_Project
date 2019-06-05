//hissavestatus.h

#ifndef _HISSAVESTATUSVALUE_PENGSHIKANG_2017_06_27_H_
#define _HISSAVESTATUSVALUE_PENGSHIKANG_2017_06_27_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//消息数据通过消息中心往其他服务程序发送整型定值（压板）
class CHisSaveStatus : public CMscDataHisSave
{
public:
	CHisSaveStatus(bool toCenter=true) : CMscDataHisSave(toCenter)
	{
		CMscDataHisSave::InitMessageHead(CControlMsg::StatusChange, 2 + 2 * sizeof(double) + 4 * sizeof(int) );
	};
	
	void SetStatusValue(int statusId, int curValue, double curTime, int lastValue, double lastTime, int faultNum)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(statusId);
		m_stream.WriteInt(curValue);
		m_stream.WriteDouble(curTime);
		m_stream.WriteInt(lastValue);
		m_stream.WriteDouble(lastTime);
		m_stream.WriteInt(faultNum);
	}
};

#endif
