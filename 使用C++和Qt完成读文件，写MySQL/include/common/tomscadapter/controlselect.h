//controlselect.h

#ifndef _CONTROLINFOSELECT_PENGSHIKANG_2011_08_09_H_
#define _CONTROLINFOSELECT_PENGSHIKANG_2011_08_09_H_

#include "mscdatacontrol.h"                      // for CMscDataControl

//五防向遥测数据处理服务发送人工置位信号
class CControlSelect : public CMscDataControl
{
public:
	CControlSelect(bool toCenter=false) : CMscDataControl(toCenter)
	{
		//(收/发)执行或撤销  uchar(eorc) : size=2 
		InitMessageHead(CControlMsg::ExecuteOrCancel, 2);
	}
	
	void SetExecuteFlag(unsigned char bExec)//(1)
	{
		m_stream.WriteBYTE(bExec);
	}
	
	void SetControlSelectInfo(unsigned char bExec)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteBYTE(bExec);
	}
	
};

#endif
