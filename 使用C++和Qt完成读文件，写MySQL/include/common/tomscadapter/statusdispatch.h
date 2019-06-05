//statusdispatch.h

#ifndef _STATUSDATADISPATCH_PENGSHIKANG_2009_10_22_H_
#define _STATUSDATADISPATCH_PENGSHIKANG_2009_10_22_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防通过intersite向后台数据处理服务发送遥信数据
class CStatusDispatch : public CMscDataDispatch
{
public:
	CStatusDispatch(bool toCenter=true) : CMscDataDispatch(toCenter)
	{
		//int(id) | int(dblpoint) | int(value) | int(quality) | int(CAUSE) | double(timestamp)
		InitMessageHead(CControlMsg::STATUS, sizeof(int)*5 + sizeof(double));
	}
	
	void SetStatusInfo(int nID, int nValue, int nQuality, double dActTime)//(1)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.SkipAfter(sizeof(int));//int(dblpoint)
		m_stream.WriteInt(nValue);
		m_stream.WriteInt(nQuality);
		m_stream.SkipAfter(sizeof(int));//int(CAUSE)
		m_stream.WriteDouble(dActTime);
	}
	
};

#endif
