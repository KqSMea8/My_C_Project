//prevntretdispatch.h

#ifndef _PREVNTRETDATADISPATCH_PENGSHIKANG_2009_10_22_H_
#define _PREVNTRETDATADISPATCH_PENGSHIKANG_2009_10_22_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//监控请求五防主机解锁结果返回情况
class CPrevntRetDispatch : public CMscDataDispatch
{
public:
	CPrevntRetDispatch() : CMscDataDispatch(false)
	{
		//int(id) | int(bSuccess) | double(timestamp)
		InitMessageHead(CControlMsg::PREVNTRET, sizeof(int)*2 + sizeof(double));
	};
	
	void SetPrevntRetInfo(int nSttsID, bool bSuccess, double dActTime)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nSttsID);
		m_stream.WriteInt(bSuccess ? 1 : 0);
		m_stream.WriteDouble(dActTime);
	}
	
};

#endif
