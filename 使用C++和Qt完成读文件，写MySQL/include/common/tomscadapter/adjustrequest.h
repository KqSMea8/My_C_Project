//controladjust.h

#ifndef _CONTROLINFORADJUST_PENGSHIKANG_2013_10_15_H_
#define _CONTROLINFORADJUST_PENGSHIKANG_2013_10_15_H_

#include "mscdatacontrol.h"                      // for CMscDataControl

//五防向遥测数据处理服务发送人工置位信号
class CControlAdjust : public CMscDataControl
{
public:
	CControlAdjust(bool toCenter=false) : CMscDataControl(toCenter)
	{
		/* int(ctrlID) | double(ctrlValue) | uchar(bAuto): size=14 */
		InitMessageHead(CControlMsg::RequestForAdjust, 14);
	}
	
	void SetAdjustInfo(int nID, double dValue, BYTE bValue)//(1)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);
		m_stream.WriteDouble(dValue);
		m_stream.WriteBYTE(bValue);
	}
	
};

#endif
