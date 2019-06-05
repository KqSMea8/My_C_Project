#ifndef _TREND_DRAWER_SPLINE_H_INCLUDED_
#define _TREND_DRAWER_SPLINE_H_INCLUDED_

#include "trenddrawer.h"
#include "trenddrawer_dot.h"
//Added by qt3to4:
#include <QPixmap>
#include <Q3PointArray>

class GBAVisionObject;
/*
 *	平滑曲线绘制类
 */
class HMITRENDOBJ_EXPORT TrendDrawerSpline : public TrendDrawer
{
public:
	TrendDrawerSpline(Trend* pTrend, const char* name=0);
	~TrendDrawerSpline();

	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	QPixmap GetIcon( const QColor& bg );
	bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn );
	bool IntersectsWith( const QRect& rc );
	bool IntersectsWith( const QPoint& pt );

	GBAVisionObject* GetGBAV();
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
	void GetBezierPoints(const Q3PointArray& ptarr, Q3PointArray& ptarrBezier);
	void DrawSmoothLine(QPainter* p, const Q3PointArray& ptarr);
public:
	bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false );
	bool Serialize( QDataStream& stream, bool bSerialize);
	TrendDrawerDot::DotStyle GetDotStyle();
	void SetDotStyle(TrendDrawerDot::DotStyle style);
	QPen GetPen();
	void SetPen(const QPen& pen);
	int m_nXFieldID;	//X坐标对应的数据域ID
	int m_nYFieldID;	//Y坐标对应的数据域ID
private:
	QPen m_pen;			//曲线画笔属性
	TrendDrawerDot::DotStyle m_dot;		//数据点标记

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_SPLINE_H_INCLUDED_