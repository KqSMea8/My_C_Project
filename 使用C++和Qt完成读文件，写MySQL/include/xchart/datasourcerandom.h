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
	QString expression;		//��̬���ʽ
	QStringList expVars;	//��̬���ʽ�еı����б�
	//���л�֧��
	friend QDataStream &operator<<( QDataStream &, const RandomRole & );
	friend QDataStream &operator>>( QDataStream &, RandomRole & );
};

//���л�֧��
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
	int m_internal;	//��ʱ���
	int m_count;	//ÿ��������������	
	QString m_bizObjGroup;	//Ҫʹ�õĶ��󼯺�����
	QMap<int,RandomRole> m_Field_Random;	//���ֶ��������ɹ���
	bool m_bCover;	//true:����������ԭ������ false: ׷�ӵ�����ԭ������ĩβ
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
	int m_iCur;			//�Ѿ���������������
	int m_timer;
	//��ȡ���������Զ���Ч��������������
	int m_timerAnimate;	//������ʱ��
	int m_nodesPerFrame;//ÿ�����뼸����
	int m_nFrames;		//�ܹ��ּ�������
	Q3PtrList<DataNode> m_dnList;//����������ݵ�
};


#endif	//_TRENDIMPL_DATASOURCE_RANDOM_H_INCLUDED_