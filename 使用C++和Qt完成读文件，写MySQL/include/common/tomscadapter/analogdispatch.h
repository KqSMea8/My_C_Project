//analogdispatch.h

#ifndef _ANALOGDATADISPATCH_PENGSHIKANG_2009_10_22_H_
#define _ANALOGDATADISPATCH_PENGSHIKANG_2009_10_22_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//���ͨ��intersite���̨���ݴ��������ң������
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
