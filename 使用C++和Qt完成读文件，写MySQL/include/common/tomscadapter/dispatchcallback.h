//dispatchcallback.h

#ifndef _DISPATCHCALLBACK_PENGSHIKANG_2015_07_13_H_
#define _DISPATCHCALLBACK_PENGSHIKANG_2015_07_13_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue
#include "../../../interface/scadasrv/dispatchtaskdata.h"  // for DispatchTaskData

//总召消息数据通过消息中心发往调度端
class CDispatchCallBack : public CMscDatAgcSetvalue
{
public:
	CDispatchCallBack(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 256)
	{
	};
	
	void SetTaskValue(short dataCount, DispatchTaskData* taskDatas)
	{
		DispatchTaskData* pTaskObj;
		m_stream.SkipAfter(2, false);//30、10
		m_stream.WriteShort(100);//100
		m_stream.WriteShort(dataCount);
		for (int i = 0; i < dataCount; ++i)
		{
			pTaskObj = taskDatas + i;
			m_stream.WriteShort(pTaskObj->taskType);
			switch(pTaskObj->dataType)
			{
			case ft_byte:
				m_stream.WriteBYTE(pTaskObj->dataValue.b);
				break;
			case ft_short:
				m_stream.WriteShort(pTaskObj->dataValue.s);
				break;
			case ft_int:
				m_stream.WriteInt(pTaskObj->dataValue.i);
				break;
			case ft_float:
				m_stream.WriteFloat(pTaskObj->dataValue.f);
				break;
			case ft_double:
				m_stream.WriteDouble(pTaskObj->dataValue.d);
				break;
			case ft_string:
				m_stream.WriteString(pTaskObj->dataValue.str);
				break;
			default:
				m_stream.WriteInt(pTaskObj->dataValue.i);
				break;
			}
		}
		SetMessageLength(m_stream.GetLength());
	}
};

#endif
