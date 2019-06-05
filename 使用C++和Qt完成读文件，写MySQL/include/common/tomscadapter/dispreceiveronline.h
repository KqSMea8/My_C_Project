//dispreceiveronline.h

#ifndef _DISPATCHRECEIVERONLINE_PENGSHIKANG_2015_07_17_H_
#define _DISPATCHRECEIVERONLINE_PENGSHIKANG_2015_07_17_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue
#include "../../../interface/scadasrv/dispatchtaskdata.h"  // for DispatchTaskData

//总召消息数据通过消息中心发往调度端
class CDispReceiverOnline : public CMscDatAgcSetvalue
{
public:
	CDispReceiverOnline(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 2)
	{
		SetTaskValue();
	};

private:
	void SetTaskValue()
	{
		m_stream.SkipAfter(2, false);//30、10
		m_stream.WriteShort(0);//0--数据处理服务上线
	};
};

#endif
