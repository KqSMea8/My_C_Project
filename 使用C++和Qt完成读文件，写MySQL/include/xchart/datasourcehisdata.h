#ifndef __TRENDIMPL_DSHISDATA_H_INCLUDED__
#define __TRENDIMPL_DSHISDATA_H_INCLUDED__

#include "datasource.h"
#include "datanode.h"
//Added by qt3to4:
#include <Q3PtrList>

class DataNodeGBAV;
class TrendDataSourceRandom;
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendDataSourceHisData : public TrendDataSource
{
	Q_OBJECT
public:
	static double GetCalDateTime(double time_t, int dynamic, int offset=0);
	TrendDataSourceHisData(Trend* parent,const char* name);
	virtual GBAVisionObject* GetGBAV(){return m_gbavDs;};
	
	void UnInit();
	void Stop();
	void Start();
	void Init();
	bool Serialize( QDataStream& stream, bool bSerialize);
	GBAVisionObject* m_gbavDs;
	DataNodeGBAV* m_gbavDataNode;
	Q3PtrList<DataNode> m_dataNodes;
	TrendDataSourceRandom* ConvertToDSRandom();
};


#endif