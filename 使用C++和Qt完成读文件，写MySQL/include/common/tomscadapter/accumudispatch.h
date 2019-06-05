//accumudispatch.h

#ifndef _ACCUMUDATADISPATCH_PENGSHIKANG_2011_02_25_H_
#define _ACCUMUDATADISPATCH_PENGSHIKANG_2011_02_25_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防通过intersite向后台数据处理服务发送遥脉数据
class CAccumuDispatch : public CMscDataDispatch
{
public:
	CAccumuDispatch(bool toCenter=true) : CMscDataDispatch(toCenter)
	{
		//int(id) | double(value) | double(timestamp)
		InitMessageHead(CControlMsg::ACCUMU, sizeof(int) + sizeof(double)*2);
	}
	
	void SetAccumuInfo(int nID, double dValue, double dActTime)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.WriteDouble(dValue);
		m_stream.WriteDouble( dActTime);
	}
	
};

#endif
