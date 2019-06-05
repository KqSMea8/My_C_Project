#ifndef _TREND_DRAWER_CURVE_H_INCLUDED_
#define _TREND_DRAWER_CURVE_H_INCLUDED_

#include "trenddrawer.h"
#include "trenddrawer_dot.h"
//Added by qt3to4:
#include <QPixmap>

class GBAVisionObject;
/*
 *	折线模式绘制类
 */
class HMITRENDOBJ_EXPORT TrendDrawerCurve : public TrendDrawer
{
public:
	TrendDrawerCurve(Trend* pTrend, const char* name=0);
	~TrendDrawerCurve();

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
	void SetAreaMode(int area);
	int GetAreaMode();
	int m_nXFieldID;	//X坐标对应的数据域ID
	int m_nYFieldID;	//Y坐标对应的数据域ID
private:
	QPen m_pen;			//曲线画笔属性
	TrendDrawerDot::DotStyle m_dot;		//数据点标记
	int m_nAreaMode;		//面积曲线设置 -1 非面积曲线 -2 水平面积曲线 -3 垂直面积 0,1,2 以字段0的值做面积下边缘

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_CURVE_H_INCLUDED_