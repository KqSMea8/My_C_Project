//prevntcmddispatch.h

#ifndef _PREVNTCMDDATADISPATCH_PENGSHIKANG_2009_10_22_H_
#define _PREVNTCMDDATADISPATCH_PENGSHIKANG_2009_10_22_H_

#include "mscdatadispatch.h"   // for CMscDataDispatch

//五防主机向监控下发解锁令
class CPrevntCmdDispatch : public CMscDataDispatch
{
public:
	CPrevntCmdDispatch() : CMscDataDispatch(false)
	{
		//int(id) | int(bLock) | double(timestamp)
		InitMessageHead(CControlMsg::PREVNTCMD, sizeof(int)*2 + sizeof(double));
	};
	
	void SetPrevntCmdInfo(int nSttsID, bool bLockState, double dActTime)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nSttsID);
		m_stream.WriteInt((bLockState ? 1 : 0));
		m_stream.WriteDouble(dActTime);
	}

};

#endif
