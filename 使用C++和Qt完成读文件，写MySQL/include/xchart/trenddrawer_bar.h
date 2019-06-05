#ifndef _TREND_DRAWER_BAR_H_INCLUDED_H
#define _TREND_DRAWER_BAR_H_INCLUDED_H

#include "trenddrawer.h"
//Added by qt3to4:
#include <QPixmap>
/*
 *	棒图
*/
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendDrawerBar : public TrendDrawer
{
public:
	enum BarStyle{
		Flat = 0,
		Rect3D,
		Round3D
	};
	TrendDrawerBar(Trend* pTrend, const char* name=0);
	~TrendDrawerBar();

	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	QPixmap GetIcon( const QColor& bg );
	bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false );
	bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn );
	bool IntersectsWith( const QRect& rc );
	bool IntersectsWith( const QPoint& pt );
	bool Serialize( QDataStream& stream, bool bSerialize);

	GBAVisionObject* GetGBAV();

	BarStyle GetBarStyle();
	void SetBarStyle(BarStyle style);
	QPen GetPen();
	void SetPen(const QPen& pen);
	void SetBrush(const QBrush& brush);
	QBrush GetBrush();
	int GetWidth();
	void SetWidth(int width);
	int GetOffset();
	void SetOffset(int offset);

	int m_nXFieldID;	//X坐标对应的数据域ID
	int m_nYFieldID;	//Y坐标对应的数据域ID
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
private:
	QPen m_pen;
	QBrush m_brush;
	BarStyle m_style;
	int m_width;
	int m_offset;

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_BAR_H_INCLUDED_H