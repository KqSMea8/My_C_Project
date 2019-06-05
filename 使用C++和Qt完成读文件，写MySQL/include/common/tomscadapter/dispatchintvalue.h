//dispatchintvalue.h

#ifndef _DISPATCHINTSETVALUE_PENGSHIKANG_2015_07_07_H_
#define _DISPATCHINTSETVALUE_PENGSHIKANG_2015_07_07_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue

//��Ϣ����ͨ����Ϣ����������������������Ͷ�ֵ��ѹ�壩
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
