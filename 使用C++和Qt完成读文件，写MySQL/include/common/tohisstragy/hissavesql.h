//hissavesql.h

#ifndef _HISSAVE_SQL_ZHANGMENG_2018_10_18_H_
#define _HISSAVE_SQL_ZHANGMENG_2018_10_18_H_

#include "mscdatahissave.h"                      // for CMscDataHisSave

//��Ϣ����ͨ����Ϣ����������������� ����SQL��䣨����Զ�����ݱ仯��
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
