#ifndef _TRENDIMPL_DATA_SOURCE_H_INCLUDED_
#define _TRENDIMPL_DATA_SOURCE_H_INCLUDED_

#include <qobject.h>
#include <qpixmap.h>
#include "trendobjectexpdef.h"

/*
 *	曲线数据源基类
 */

class Trend;
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendDataSource : public QObject
{
public:
	QString GetName();
	void SetName(const QString& name);
	enum DataSourceType{
		StaticData,
			RealTimeData,
			HistoryDB
	};
	DataSourceType GetType();
	Trend* GetTrend();
	virtual void Init();
	virtual void Stop();
	virtual void Start();
	virtual void UnInit();
	//序列化
	virtual bool Serialize( QDataStream& stream, bool bSerialize) = 0;
	TrendDataSource(DataSourceType type, Trend* parent, const char* name = 0);
	virtual GBAVisionObject* GetGBAV(){return 0;};
	
	static bool SaveToData( TrendDataSource* drawer, QByteArray &ba );
	static TrendDataSource* LoadFromData(const QByteArray& ba,Trend* pTrend);
	static TrendDataSource* CreateDataSource( DataSourceType type, Trend* pTrend, const char* name=0);
	
protected:
	Trend* m_pTrend; 
	DataSourceType m_type;
	QString m_name;
private: 
};
 
#endif	//_TRENDIMPL_DATA_SOURCE_H_INCLUDED_