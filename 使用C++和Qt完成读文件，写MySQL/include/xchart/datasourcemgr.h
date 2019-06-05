#ifndef _TRENDIMPL_DATASOURCE_MANAGER_H_INCUDED_H_
#define _TRENDIMPL_DATASOURCE_MANAGER_H_INCUDED_H_

#include "trendobjectexpdef.h"
#include "datasource.h"

#include <qobject.h>
#include <q3ptrlist.h>

class GBAVisionObject;
class TrendManager;
class HMITRENDOBJ_EXPORT DataSourceManager	: public QObject
{
	Q_OBJECT
public:
	~DataSourceManager();
	DataSourceManager(TrendManager* trendmgr, QObject* parent=0, const char* name=0 );
	GBAVisionObject* GetGBAV(){return m_vDSMgr;}

	//数据源初始化/运行/停止/反初始化
	void Init();
	void Start();
	void Stop();
	void UnInit();
	
	//数据源维护
	int MoveDataSourceOrder(TrendDataSource *trend, int steps);
	void RemoveDS(TrendDataSource* source);
	void RemoveDS(const QString& name);
	TrendDataSource* AddDS(const QString& name, Trend* pTrend, TrendDataSource::DataSourceType type);
	TrendDataSource* GetDS(const QString& name);
	Q3PtrList<TrendDataSource> GetDSList();
	TrendManager* GetTrendMgr();

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataSourceManager & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataSourceManager & );

protected:
private:
	TrendManager* m_trendMgr;			//关联的曲线文档
	Q3PtrList<TrendDataSource> m_Sources;	//数据源列表
	GBAVisionObject* m_vDSMgr;
signals:
	void DSAdded( TrendDataSource* ds );
	void DSRemoved( TrendDataSource* ds );
};

//序列化支持
HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataSourceManager & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataSourceManager & );

#endif	//_TRENDIMPL_DATASOURCE_MANAGER_H_INCUDED_H_