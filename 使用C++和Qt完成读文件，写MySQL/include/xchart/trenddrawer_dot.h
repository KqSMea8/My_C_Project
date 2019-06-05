#ifndef _TREND_DRAWER_DOT_H_INCLUDED_
#define _TREND_DRAWER_DOT_H_INCLUDED_

#include "trenddrawer.h"
//Added by qt3to4:
#include <QPixmap>
#include <Q3PointArray>

class GBAVisionObject;
/*
 *	����ģʽ������
 */
class HMITRENDOBJ_EXPORT TrendDrawerDot : public TrendDrawer
{
public:
	typedef enum DotStyle
	{
		NoDot = 0,
		Plus,			//��
		Cross,			//��
		Circle,			//��
		CircleSld,		//��
		Square,			//��
		SquareSld,		//��
		Diamond,		//��
		DiamondSld,		//��
		TriangleUp,		//��
		TriangleUpSld,	//��
		TriangleDown,	//��
		TriangleDownSld,//��
		Pentacle,		//��
		PentacleSld		//��

	};
	TrendDrawerDot(Trend* pTrend,const char* name=0);
	~TrendDrawerDot();

	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	QPixmap GetIcon( const QColor& bg );
	bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn );
	bool IntersectsWith( const QRect& rc );
	bool IntersectsWith( const QPoint& pt );

	GBAVisionObject* GetGBAV();
protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
public:
	static void DrawDot(QPainter* p, const QPoint& pos, DotStyle style, const QColor& clr, int size);
	static void DrawDots(QPainter* p, const Q3PointArray& arr, DotStyle style, const QColor& clr, int size);
public:
	bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false );
	bool Serialize( QDataStream& stream, bool bSerialize);
	DotStyle GetDotStyle();
	int GetDotSize();
	void SetDotSize(int size);
	void SetDotStyle(DotStyle style);
	QColor GetDotColor();
	void SetDotColor(const QColor& color);
	int m_nXFieldID;	//X�����Ӧ��������ID
	int m_nYFieldID;	//Y�����Ӧ��������ID
private:
	QColor m_clr;		//������ɫ
	DotStyle m_dot;		//���ݵ�������
	int m_size;			//���ݵ��Ǵ�С

private:
	GBAVisionObject* m_pGBAVsnObj;
};

#endif	//_TREND_DRAWER_DOT_H_INCLUDED_