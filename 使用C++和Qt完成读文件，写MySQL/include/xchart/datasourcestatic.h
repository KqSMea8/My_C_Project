#ifndef _TRENDIMPL_DATASOURCE_STATIC_H_INCLUDED_
#define _TRENDIMPL_DATASOURCE_STATIC_H_INCLUDED_

#include "datasource.h"
#include "trend.h"

class HMITRENDOBJ_EXPORT TrendDataSourceStatic : public TrendDataSource
{
public:
	void Init();
	bool Serialize( QDataStream& stream, bool bSerialize);
	TrendDataSourceStatic(Trend* parent,const char* name);
	DataNodeList m_dataList;	//数据点链表
protected:
private:
};

#endif	//_TRENDIMPL_DATASOURCE_STATIC_H_INCLUDED_