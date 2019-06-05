#ifndef _TRENDOBJ_TREND_H_INCLUDED_
#define _TRENDOBJ_TREND_H_INCLUDED_

#include "trendobjectexpdef.h"
#include "coordaxis.h"
#include "datanode.h"
#include "trenddisplay.h"
#include "datavaluetype.h"

#include <q3ptrdict.h>
#include <q3valuevector.h>
#include <qmutex.h>
//Added by qt3to4:
#include <Q3PtrList>

/*
 *	��������������
 *
 *	ά������������Ϣ
 *		�����е����ݵ��м���������
 *		ÿ������������������Ϣ
 *		ÿ���������Ӧ����һ��������
 *	�������ݵ����
 *		������ݵ�(��ӵ���ǰ/���/ָ��λ��)
 *		������ݵ�
 *		ɾ��(��һ�������һ����ָ��λ��)���ݵ�
 *		�õ�ָ��λ�����ݵ�
 */
enum ActOnNewData{
	DoNothing = 0,
	Automatic,
	MoveBeginIfOut,
	MoveEndIfOut,
	MoveCenterIfOut,
	MoveBegin,
	MoveEnd,
	MoveCenter,
	ToTheYearIfOut,
	ToTheMonthIfOut,
	ToTheWeekIfOut,
	ToTheDayIfOut,
	ToTheHourIfOut,
	ToTheMinIfOut
};
class TrendField
{
public:
	TrendField(){ dataType = DataValueType::VTNumber; axis = 0; actOnNew = DoNothing;}
	DataValueType dataType;	//������������Ϣ
	CoordAxis* axis;		//�������Ӧ��������ָ��
	int actOnNew;			//��������ʱ����Ϊ 0:����Ϊ 1:�Զ����� 2:�Ƶ���ʼ 3�Ƶ����
};

typedef Q3PtrList<DataNode> DataNodeList;

class TrendManager;
class GBAVisionObject;
class HMITRENDOBJ_EXPORT Trend : public QObject
{
	Q_OBJECT
public:
	int GetDataListCapability();
	void SetDataListCapability(int n);
	void UnlockDataList();
	void LockDataList();
	//����/����
	Trend(TrendManager* trendmgr, const char* name=0);
	~Trend();
	QString GetName();
	void SetName(const QString& name);

	GBAVisionObject* GetGBAV() const;
	TrendManager* GetTrendManager();

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Trend & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Trend & );

	//�����Լ����ƴ���ָ��
	TrendDisplay* Displayer();
	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);

	
	//���ݽڵ���ɽṹά��
	int GetDataFieldCount();
	void RemoveDataField(int index);
	int AddDataField( const DataValueType& dataType, CoordAxis* axis, int actOnNew );
	bool SetDataField( int index, const DataValueType& dataType, CoordAxis* axis, int actOnNew );
	CoordAxis* GetDataFieldAxis(int index);
	DataValueType GetDataFieldType(int index);
	ActOnNewData GetDataFieldActonnew(int index);
	bool GetDataFieldMinMax(int index, double& min, double& max);

	//���ݽڵ�ֵ����Ļ�����Լ��ַ������ֵ�ת��
	long GetPixelsOfMinVal(int field);
	long GetPixelsOfNodeField(const DataNode &node, int field);
	QString GetStringOfNodeField(const DataNode& node, int field);
	double GetDoubleOfNodeField(const DataNode& node, int field);

	//���ݽڵ����/ɾ��/��ȡ
	void ClearData();
	void PreappendData(DataNode* node);
	void AppendData(DataNode* node);
	void AppendData( const DataNode& node );
	void AppendData(Q3PtrList<DataNode>& nodeList);
	DataNodeList GetDataList();
signals:
	void DataChanged(DataNode*);			//���ݵ�ı�
	void MinValChanged( const TrendField&, const QVariant& );//ĳһ�����ϼ�Сֵ�ı�ʱ
	void MaxValChanged( const TrendField&, const QVariant& );//ĳһ�����ϼ���ֵ�ı�ʱ
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
	void UpdateMinMaxValue(DataNode *node);
	void UpdateMinMaxValue(Q3PtrList<DataNode>& nodeList);
private:
	TrendManager* m_owner;
	Q3ValueVector<TrendField> m_fields;		//������������Ϣ����
	QMap<int,double> m_minVals;
	QMap<int,double> m_maxVals;
	DataNodeList m_dataList;	//���ݵ�����
	TrendDisplay* m_display;	//���ƴ���
	QString	m_name;				//��������
	QMutex m_mtxdataList;
	friend class TrendDisplay;
	int m_nCapability;

	GBAVisionObject* m_pGBAVsnObj;
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Trend & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Trend & );

#endif	//_TRENDOBJ_TREND_H_INCLUDED_