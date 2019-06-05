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
 *	曲线数据序列类
 *
 *	维护曲线配置信息
 *		曲线中的数据点有几个数据域
 *		每个数据域数据类型信息
 *		每个数据域对应到哪一个坐标轴
 *	曲线数据点管理
 *		添加数据点(添加到最前/最后/指定位置)
 *		清空数据点
 *		删除(第一个，最后一个，指定位置)数据点
 *		得到指定位置数据点
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
	DataValueType dataType;	//数据域类型信息
	CoordAxis* axis;		//数据域对应的坐标轴指针
	int actOnNew;			//有新数据时的作为 0:无作为 1:自动处理 2:移到开始 3移到最后
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
	//构造/析构
	Trend(TrendManager* trendmgr, const char* name=0);
	~Trend();
	QString GetName();
	void SetName(const QString& name);

	GBAVisionObject* GetGBAV() const;
	TrendManager* GetTrendManager();

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Trend & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Trend & );

	//绘制以及绘制代理指针
	TrendDisplay* Displayer();
	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);

	
	//数据节点组成结构维护
	int GetDataFieldCount();
	void RemoveDataField(int index);
	int AddDataField( const DataValueType& dataType, CoordAxis* axis, int actOnNew );
	bool SetDataField( int index, const DataValueType& dataType, CoordAxis* axis, int actOnNew );
	CoordAxis* GetDataFieldAxis(int index);
	DataValueType GetDataFieldType(int index);
	ActOnNewData GetDataFieldActonnew(int index);
	bool GetDataFieldMinMax(int index, double& min, double& max);

	//数据节点值到屏幕坐标以及字符串表现的转换
	long GetPixelsOfMinVal(int field);
	long GetPixelsOfNodeField(const DataNode &node, int field);
	QString GetStringOfNodeField(const DataNode& node, int field);
	double GetDoubleOfNodeField(const DataNode& node, int field);

	//数据节点添加/删除/读取
	void ClearData();
	void PreappendData(DataNode* node);
	void AppendData(DataNode* node);
	void AppendData( const DataNode& node );
	void AppendData(Q3PtrList<DataNode>& nodeList);
	DataNodeList GetDataList();
signals:
	void DataChanged(DataNode*);			//数据点改变
	void MinValChanged( const TrendField&, const QVariant& );//某一坐标上极小值改变时
	void MaxValChanged( const TrendField&, const QVariant& );//某一坐标上极大值改变时
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
	void UpdateMinMaxValue(DataNode *node);
	void UpdateMinMaxValue(Q3PtrList<DataNode>& nodeList);
private:
	TrendManager* m_owner;
	Q3ValueVector<TrendField> m_fields;		//曲线数据域信息数组
	QMap<int,double> m_minVals;
	QMap<int,double> m_maxVals;
	DataNodeList m_dataList;	//数据点链表
	TrendDisplay* m_display;	//绘制代理
	QString	m_name;				//曲线名称
	QMutex m_mtxdataList;
	friend class TrendDisplay;
	int m_nCapability;

	GBAVisionObject* m_pGBAVsnObj;
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Trend & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Trend & );

#endif	//_TRENDOBJ_TREND_H_INCLUDED_