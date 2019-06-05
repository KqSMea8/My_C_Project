//hissavesql.h

#ifndef _HISSAVE_SQL_ZHANGMENG_2018_10_18_H_
#define _HISSAVE_SQL_ZHANGMENG_2018_10_18_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//消息数据通过消息中心往其他服务程序 发送SQL语句（调度远方数据变化）
class CHisSaveSQL : public CMscDataHisSave
{
public:
	CHisSaveSQL(bool toCenter=true) : CMscDataHisSave(toCenter)
	{
		CMscDataHisSave::InitMessageHead(CControlMsg::RemoteValChange, 280 );
	};
	
	void SetTaskValue(const char* strValue)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteString(strValue);
	}
};

#endif
