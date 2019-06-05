#ifndef _TRENDIMPL_DATASOURCE_RANDOM_H_INCLUDED_
#define _TRENDIMPL_DATASOURCE_RANDOM_H_INCLUDED_

#include "datanode.h"
#include "datasource.h"
#include "timerthread.h"

#include <qtimer.h>
#include <qstringlist.h>
//Added by qt3to4:
#include <Q3ValueList>
#include <Q3PtrList>
#include <QMap>

class Trend;
class RandomRole
{
public:
	enum Type{
		CurTime,
		FixVal,
		Increase,
		Reincrease,
		Serial,
		RandVal,
		GBAExp
	};
	RandomRole(){
		type = FixVal;
		lower = upper = step = 0.0;
	}
	Type type;
	double lower;
	double upper;
	double step;
	Q3ValueList<double> valList;
	QString expression;		//组态表达式
	QStringList expVars;	//组态表达式中的变量列表
	//序列化支持
	friend QDataStream &operator<<( QDataStream &, const RandomRole & );
	friend QDataStream &operator>>( QDataStream &, RandomRole & );
};

//序列化支持
QDataStream &operator<<( QDataStream &, const RandomRole & );
QDataStream &operator>>( QDataStream &, RandomRole & );
class TrendDataSourceRandomGBAV;
class HMITRENDOBJ_EXPORT TrendDataSourceRandom : public TrendDataSource
{
	Q_OBJECT
public:
	void UnInit();
	void Stop();
	void Start();
	void Init();
	bool Serialize( QDataStream& stream, bool bSerialize);
	TrendDataSourceRandom(Trend* parent,const char* name);
	~TrendDataSourceRandom();
	virtual GBAVisionObject* GetGBAV();
	void OnThreadTimer(int id);
	TrendDataSourceRandomGBAV* m_gbavDs;
	int m_internal;	//定时间隔
	int m_count;	//每次生成数据条数	
	QString m_bizObjGroup;	//要使用的对象集合名称
	QMap<int,RandomRole> m_Field_Random;	//各字段数据生成规则
	bool m_bCover;	//true:覆盖曲线中原有数据 false: 追加到曲线原有数据末尾
	class XTimerThreadClient : public TimerThreadClient
	{
	public:
		TrendDataSourceRandom* m_parent;
		void OnTimer( int id)
		{
			m_parent->OnThreadTimer(id);
		};
	} m_xtimerclient;
protected slots:
	void GenerateAndAppend();
protected:
	//void timerEvent ( QTimerEvent * event );

private:
	int m_iCur;			//已经产生的数据条数
	int m_timer;
	//读取到的数据以动画效果分批加入曲线
	int m_timerAnimate;	//动画定时器
	int m_nodesPerFrame;//每批加入几个点
	int m_nFrames;		//总共分几批加入
	Q3PtrList<DataNode> m_dnList;//待加入的数据点
};


#endif	//_TRENDIMPL_DATASOURCE_RANDOM_H_INCLUDED_