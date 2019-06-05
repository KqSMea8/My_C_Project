#ifndef _TREND_DRAWER_PIE_H_INCLUDED_H
#define _TREND_DRAWER_PIE_H_INCLUDED_H

#include "trenddrawer.h"
//Added by qt3to4:
#include <QPixmap>
/*
 *	棒图
*/
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendDrawerPie : public TrendDrawer
{
public:
	enum PieStyleFlag{
		Ellipse = 0x1,
		Use3D = 0x2,
		BreakDown = 0x4
	};
	enum PieLabelFlag
	{
		ShowName = 0x1,
		ShowPercent = 0x2,
		ShowValue = 0x4
	};
	TrendDrawerPie(Trend* pTrend, const char* name=0);
	~TrendDrawerPie();

	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);

	QPixmap GetIcon( const QColor& bg );
	int GetIconCount();
	bool GetIcon( QPixmap& icon, QString& desc, const QColor& bg, int index );
	bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false );
	bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn );
	bool IntersectsWith( const QRect& rc );
	bool IntersectsWith( const QPoint& pt );
	bool Serialize( QDataStream& stream, bool bSerialize);

	GBAVisionObject* GetGBAV();

	int GetPieStyle();
	void SetPieStyle(int style);
	int GetLabelStyle();
	void SetLabelStyle(int style);

	int m_nValFieldID;	//X坐标对应的数据域ID
	int m_nNameFieldID;	//Y坐标对应的数据域ID
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
	QRect GetTextRectHint( const QRect& rect, int angle, int wise );
	QPoint GetPointFromAngle(const QRect& ellipse, double angle);
	QString GetLabelOf( const QString& name, double val, double valSub );
	QColor GetPieColor( int count,int i );
private:
	int m_style;
	int m_label;

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_PIE_H_INCLUDED_H