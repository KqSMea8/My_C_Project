//dispatchintvalue.h

#ifndef _DISPATCHINTSETVALUE_PENGSHIKANG_2015_07_07_H_
#define _DISPATCHINTSETVALUE_PENGSHIKANG_2015_07_07_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue

//消息数据通过消息中心往其他服务程序发送整型定值（压板）
class CDispatchIntValue : public CMscDatAgcSetvalue
{
public:
	CDispatchIntValue(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 6)
	{
	};
	
	void SetTaskValue(short taskType, int dataValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(taskType);
		m_stream.WriteInt(dataValue);
	}
};

#endif
