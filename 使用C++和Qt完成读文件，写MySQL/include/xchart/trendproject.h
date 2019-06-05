#ifndef _HMI_TREND_PROJECT_H_INCLUDED_
#define _HMI_TREND_PROJECT_H_INCLUDED_

#include "trendobjectexpdef.h"

#include <qobject.h>
#include <qwidget.h>
#include <qdatetime.h>

class TrendManager;
class TrendView;
class DataSourceManager;
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendProject : public QObject
{
	Q_OBJECT
public:
	GBAVisionObject* GetGBAV(){return m_vTrendProj;};
	void Stop();
	void Start();
	void Uninitialize();
	void Initialize();
	bool LoadFromData(const QByteArray& data);
	bool SaveToData( QByteArray& data );
	TrendProject(QWidget* parent=0, const char* name = 0);
	virtual ~TrendProject();
	DataSourceManager* GetDSManager();
	TrendManager* GetTrendManager();
private:
	bool saveInternal(QDataStream* strm);
	bool loadInternal(QDataStream* strm);
	TrendManager* m_doc;		//曲线文档
	DataSourceManager* m_dsMgr;	//曲线数据源管理
	
	GBAVisionObject* m_vTrendProj;
};

#endif	//_HMI_TREND_PROJECT_H_INCLUDED_