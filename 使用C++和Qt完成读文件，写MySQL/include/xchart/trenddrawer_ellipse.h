#ifndef _TREND_DRAWER_ELLIPSE_H_INCLUDED_
#define _TREND_DRAWER_ELLIPSE_H_INCLUDED_

#include "trenddrawer.h"
#include "trenddrawer_dot.h"
//Added by qt3to4:
#include <QPixmap>

class GBAVisionObject;
/*
 *	折线模式绘制类
 */
class HMITRENDOBJ_EXPORT TrendDrawerEllipse : public TrendDrawer
{
public:
	TrendDrawerEllipse(Trend* pTrend, const char* name=0);
	~TrendDrawerEllipse();

	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	QPixmap GetIcon( const QColor& bg );
	bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn );
	bool IntersectsWith( const QRect& rc );
	bool IntersectsWith( const QPoint& pt );

	GBAVisionObject* GetGBAV();
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
public:
	bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false );
	bool Serialize( QDataStream& stream, bool bSerialize);
	TrendDrawerDot::DotStyle GetDotStyle();
	void SetDotStyle(TrendDrawerDot::DotStyle style);
	QPen GetPen();
	void SetPen(const QPen& pen);
	void SetBrush(const QBrush& brush);
	QBrush GetBrush();
	int m_nXFieldID;	//X坐标对应的数据域ID
	int m_nYFieldID;	//Y坐标对应的数据域ID
private:
	QPen m_pen;			//曲线画笔属性
	QBrush m_brush;
	TrendDrawerDot::DotStyle m_dot;		//数据点标记

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_ELLIPSE_H_INCLUDED_