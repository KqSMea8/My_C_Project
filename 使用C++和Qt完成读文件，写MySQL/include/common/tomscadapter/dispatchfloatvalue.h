//dispatchfloatvalue.h

#ifndef _DISPATCHFLOATSETVALUE_PENGSHIKANG_2015_07_07_H_
#define _DISPATCHFLOATSETVALUE_PENGSHIKANG_2015_07_07_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue

//消息数据通过消息中心往其他服务程序发送实数型定值（功率定值）
class CDispatchFloatValue : public CMscDatAgcSetvalue
{
public:
	CDispatchFloatValue(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 6)
	{
	};
	
	void SetTaskValue(short taskType, float dataValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteShort(taskType);
		m_stream.WriteFloat(dataValue);
	}
};

#endif
