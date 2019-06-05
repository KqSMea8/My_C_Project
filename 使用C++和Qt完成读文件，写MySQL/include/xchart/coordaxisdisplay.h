#ifndef _COORDAXISDRAW_H_INCLUDED_
#define _COORDAXISDRAW_H_INCLUDED_

#include "trendobjectexpdef.h"
#include "datavaluetype.h"

#include <qpen.h>
#include <qfont.h>
#include <qsize.h>
//Added by qt3to4:
#include <Q3ValueList>

class CoordAxis;

/*
 *	坐标轴绘制代理类
 *	坐标轴绘制参数设置
 *	坐标轴绘制
 */
class HMITRENDOBJ_EXPORT CoordAxisDisplay
{
public:
	enum GridMode{
		NoGrid,		//无
		PrimGrid,	//仅绘制主刻度网格
		AllGrid,	//绘制主、二级、三级网格
		PAndSGrid	//绘制主、二级刻度网格
	};

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxisDisplay & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxisDisplay & );

	virtual void Draw(QPainter* p, double origX, double origY, int clipx, int clipy, int clipw, int cliph);
	CoordAxisDisplay(CoordAxis* pOwner);
protected:
	void DrawOneSpecialLine(QPainter* p, int x, int y, int w, int h, double value, const QPen& pen);
	void DrawGridLines(QPainter* p, int x, int y, int w, int h, Q3ValueList<double>& vals, const QPen& pen);
	void DrawMarks(QPainter *painter, Q3ValueList<double> &vals, const QPoint &orgPt,
								 DataValueType& format, QFont &font,
								 int lineLen, const QPen &pen,
								 const bool bDrawMarkLine, bool bDrawMarkText);
	void DrawCaption(QPainter* p, int origX, int origY, double valStart, double valEnd );
	QPoint GetMarkDirect();
	virtual void DrawMarkText(QPainter* p, const QPoint& pos, const QString& str, QFont& font);
	void GetMinMaxValInRect(double& valStart, double& valEnd, double origPos, int clipx, int clipy, int clipw, int cliph );
private:
	CoordAxis* m_pOwner;
public:
	void DrawGrid(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	void DrawSepcialLine(QPainter *p, int clipx, int clipy, int clipw, int cliph);

	QPen	m_penLine;			//坐标轴线画笔
	int		m_nMarkLength;		//主刻度线长度
	bool	m_bShowLine;		//坐标轴主线/刻度线是否可见
	QColor	m_clrText;			//文本颜色

	bool	m_bShowCaption;		//坐标轴标题(名称单位)是否可见
	QFont	m_fontCaption;		//标题字体
	int		m_captionAlign;		//标题文本对齐方式(Qt::AlignmentFlags)
	int		m_captionOffset;	//标题文本和坐标轴的距离


	double	m_fTxtRotate;			//刻度文本旋转角度
	QFont	m_fontMarkText;			//刻度文本字体
	bool	m_bShowPMarkText;		//主刻度线文本是否可见
	DataValueType	m_pmarkFormat;	//主刻度线文本格式
	bool	m_bShowSMarkText;		//二级刻度文本是否可见
	DataValueType	m_smarkFormat;	//二级刻度线文本格式
	bool	m_bShowTMarkText;		//三级刻度文本是否可见
	DataValueType	m_tmarkFormat;	//三级刻度线文本格式

	GridMode	m_gridMode;		//网格线显示设置
	bool		m_gridFront;	//网格线在曲线上层
	QPen	m_gridPPen;			//主网格画笔
	QPen	m_gridSPen;			//二级网格画笔
	QPen	m_gridTPen;			//三级网格画笔
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxisDisplay & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxisDisplay & );

#endif	//_COORDAXISDRAW_H_INCLUDED_