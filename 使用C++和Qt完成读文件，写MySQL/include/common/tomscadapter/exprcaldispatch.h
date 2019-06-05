//exprcaldispatch.h

#ifndef _EXPRCALDISPATCH_PENGSHIKANG_2011_07_29_H_
#define _EXPRCALDISPATCH_PENGSHIKANG_2011_07_29_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防向遥测数据处理服务发送人工置位信号
class CExprcalDispatch : public CMscDataDispatch
{
public:
	CExprcalDispatch(bool toCenter) : CMscDataDispatch(toCenter)
	{
		//int(id) | double(value) | double(timestamp)
		InitMessageHead(CControlMsg::EXPRCAL, sizeof(int) + sizeof(double)*2);
	}
	
	void SetExprcalInfo(int nID, double dValue, double dActTime)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.WriteDouble(dValue);
		m_stream.WriteDouble(dActTime);
	}
	
};

#endif
