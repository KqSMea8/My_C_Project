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

	//����Դ��ʼ��/����/ֹͣ/����ʼ��
	void Init();
	void Start();
	void Stop();
	void UnInit();
	
	//����Դά��
	int MoveDataSourceOrder(TrendDataSource *trend, int steps);
	void RemoveDS(TrendDataSource* source);
	void RemoveDS(const QString& name);
	TrendDataSource* AddDS(const QString& name, Trend* pTrend, TrendDataSource::DataSourceType type);
	TrendDataSource* GetDS(const QString& name);
	Q3PtrList<TrendDataSource> GetDSList();
	TrendManager* GetTrendMgr();

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataSourceManager & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataSourceManager & );

protected:
private:
	TrendManager* m_trendMgr;			//�����������ĵ�
	Q3PtrList<TrendDataSource> m_Sources;	//����Դ�б�
	GBAVisionObject* m_vDSMgr;
signals:
	void DSAdded( TrendDataSource* ds );
	void DSRemoved( TrendDataSource* ds );
};

//���л�֧��
HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const DataSourceManager & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, DataSourceManager & );

#endif	//_TRENDIMPL_DATASOURCE_MANAGER_H_INCUDED_H_