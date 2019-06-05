//analogdispatch.h

#ifndef _ANALOGDATADISPATCH_PENGSHIKANG_2009_10_22_H_
#define _ANALOGDATADISPATCH_PENGSHIKANG_2009_10_22_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防通过intersite向后台数据处理服务发送遥测数据
class CAnalogDispatch : public CMscDataDispatch
{
public:
	CAnalogDispatch(bool toCenter=true) : CMscDataDispatch(toCenter)
	{
		//int(id) | double(value) | int(CAUSE) | double(timestamp)
		InitMessageHead(CControlMsg::ANALOG, (sizeof(int) + sizeof(double)) * 2);
	}
	
	void SetAnalogInfo(int nID, double dValue, double dActTime)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.WriteDouble(dValue);
		m_stream.SkipAfter(sizeof(int));//int(CAUSE)
		m_stream.WriteDouble(dActTime);
	}
	
};

#endif
