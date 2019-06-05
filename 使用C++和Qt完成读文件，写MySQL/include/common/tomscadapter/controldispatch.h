//controldispatch.h

#ifndef _CONTROLDATADISPATCH_PENGSHIKANG_2010_09_19_H_
#define _CONTROLDATADISPATCH_PENGSHIKANG_2010_09_19_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防通过intersite向后台数据处理服务发送人工置位信号
class CControlDispatch : public CMscDataDispatch
{
public:
	CControlDispatch(bool toCenter=true) : CMscDataDispatch(toCenter)
	{
		//int(id) | int(dblpoint) | int(value)
		InitMessageHead(CControlMsg::ASK4PREVNT, sizeof(int)*3);
	}
	
	void SetControlDispInfo(int nID, bool bDblPoint, int nValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.WriteInt(bDblPoint ? 1 : 0);
		m_stream.WriteInt(nValue);
	}
	
};

#endif
