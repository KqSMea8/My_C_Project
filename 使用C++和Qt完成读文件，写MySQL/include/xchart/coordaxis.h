#ifndef _HMI_TREND_COORDAXIS_H_
#define _HMI_TREND_COORDAXIS_H_

#include "trendobjectexpdef.h"
#include "datavaluetype.h"
#include "coordaxisdisplay.h"

#include <qobject.h>
#include <qpoint.h>
#include <qpainter.h>
#include <q3valuelist.h>
#include <qmap.h> 
/*
 *	CoordAxis : 坐标轴类
 *	坐标轴数据定义
 *	和该坐标轴关联的数据和屏幕坐标之间的互相转换
 *	坐标轴视图属性定义
 *	坐标轴绘制
 *	坐标轴移动/缩放
 *	//TO DO : 是否将 m_m_posOrigin以及PositionOfVal()由QPoint改为long(只关心特定方向的位置)
 */
class GBAVisionObject;
class HMITRENDOBJ_EXPORT SpecialMarkLine
{
public:
	QString name;
	QPen pen;
	double value;
	bool bShow;
};

class TrendManager;

class HMITRENDOBJ_EXPORT CoordAxis : public QObject
{
	Q_OBJECT
public:
	//坐标轴方向
	enum Direction {
		Left  = 0,	//  <------
		Right,		//	------>
		Up,			//	^
		Down,		//	v
    };

	//停靠位置
	enum DockArea {
		LeftArea = 0,
		RightArea,
		TopArea,
		BottomArea
	};
	
	//可见起始值动态定义
	enum StartValDynamic
	{
		StaticVal = 0,
		CurPrimMark,
		CurSecMark,
		CurYear,
		CurMonth,
		CurWeek,
		CurDay,
		CurHour,
		CurMin
	};
	
	//构造/析构
	CoordAxis(TrendManager* trendManager);
	CoordAxis(TrendManager* trendManager, QString name, DataValueType::ValueType valType, Direction d, double primmask, double secmask, double pixelsPerUnit);
	~CoordAxis();

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxis & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxis & );

	GBAVisionObject* GetGBAV();

	//绘制
	void Draw(QPainter* p, double origX, double origY, int clipx, int clipy, int clipw, int cliph);
	//绘制代理指针
	CoordAxisDisplay* Displayer();

	//基本属性设置和读取
	QString GetName();
	void SetName(const QString& name);
	QString GetCaption();
	void SetCaption(const QString& caption);
	QString GetUnit();
	void SetUnit(const QString& unit);
	Direction GetDirection();
	void SetDirection(Direction d);
	bool IsVertical();
	bool IsHorizontal();
	DockArea GetDockArea();
	void SetDockArea( DockArea area );
	DataValueType GetValType();
	void SetValType( const DataValueType& type );

	double GetThdMark();
	double GetSecMark();
	double GetPrimMark();
	void SetMarkSize(double prim,double second,double third);

	//工程值范围设置
	double GetVisibleBegin();
	double GetVisibleRange();
	StartValDynamic GetStartValDynamic();
	void SetStartValDynamic( StartValDynamic dynamic );
	void SetVisibleRange(double range);
	void SetVisibleBegin(double val);
	void GetValueRange(double& min,double&max);
	void SetValueRange(double min, double max);
	double GetAutoAjustRange();
	bool IsAutoAjustBegin();
	bool IsAutoAjustEnd();
	void SetAutoAjust(bool bBegin,bool bEnd,double fMinRange);

	//坐标值和屏幕坐标的对应关系
	double GetPixelsPerUnit();
	void SetPixelsPerUnit(double d);
	double GetOriginPos();
	void SetOriginPos(double pos);
	void MoveValTo(double val, double pos);
	void MoveBy(double offset);
	double GetScale();
	void Scale(double scale);

	//坐标轴值数据和屏幕坐标转换
	double PositionOfVal( double val);
	double ValOfPosition( double pos);
	double ValOfPosition( const QPoint& pos);
	double NearestThdMark(double val);
	double NearestSecMark(double val);
	double NearestPrimMark(double val);
	double NearestThdMarkBefore(double val);
	double NearestThdMarkAfter(double val);
	double NearestSecMarkBefore(double val);
	double NearestSecMarkAfter(double val);
	double NearestPrimMarkBefore(double val);
	double NearestPrimMarkAfter(double val);
	double NextThdMark(double curThdMark);
	double NextSecMark(double curSecMark);
	double NextPrimMark(double curPrimMark);
	void GetMarkValuesBetween(double valStart, double valEnd, Q3ValueList<double>& primMarks, Q3ValueList<double>& secMarks, Q3ValueList<double>& thrdMarks);
	
	static void AutoCalVisibleRange(double valMin, double valMax, double& rangeMin, double& rangeMax, double fMinRange);
	
	void SetLineProperty( const QString& sKey, const QString& sProperty, QVariant var );
	QMap<QString, SpecialMarkLine> specialLinesMap;

	TrendManager* GetTrendManager() { return m_trendMgr; }

signals:
	void ViewChanged();		
	void FrameInvalidate();
protected:
	double NextMark(double  curMark, double markSize);
	double NearestMark(double val,double markSize);
	double NearestMarkAfter(double val,double markSize);
	double NearestMarkBefore(double val,double markSize);
protected:

private:
	CoordAxisDisplay* m_display;	//坐标轴绘制代理

	QString m_strName;			//坐标轴名称
	QString m_strCaption;		// 标题
	QString m_strUnit;			//坐标轴单位
	DockArea m_dockArea;		//坐标轴停靠区域
	Direction m_direct;			//坐标轴方向
	DataValueType m_VType;

	double m_fMinVal;			//最大值
	double m_fMaxVal;			//最小值
	double m_fPrimMark;			//每个主刻度线对应的单位数
	double m_fSecMark;			//每个辅刻度线对应的单位数
	double m_fThdMark;			//每个辅刻度线对应的单位数

	double m_fVisibleBegin;			//默认显示的起始值
	StartValDynamic	m_startDynamic;	//显示的起始值动态定义
	//默认的可见的工程值跨度
	//窗口大小改变时，自动调节m_fPixelsPerUnit以保证能显示该跨度范围的工程值数据
	//如果该值<=0则忽略该值，而是根据窗口大小和m_fPixelsPerUnit决定绘制跨度
	double m_fVisibleRange;
	double m_fPixelsPerUnit;	//每个坐标单位对应的像素数
	double m_posOrigin;			//坐标原点(工程值0点)在屏幕坐标平面上的位置
	bool   m_bAutoAjustBegin;		//是否自动调整坐标轴可见范围
	bool   m_bAutoAjustEnd;		//是否自动调整坐标轴可见范围
	double m_fMinAutoRange;		//自动调整坐标轴可见范围的最小值

	double m_fScale;			//缩放显示比例
	double m_orgPMark;
	double m_orgSMark;
	double m_orgTMark;

	GBAVisionObject* m_pGBAVsnObj;

	TrendManager* m_trendMgr;

	friend class CoordAxisDisplay;
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxis & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxis & );

#endif	//_HMI_TREND_COORDAXIS_H_