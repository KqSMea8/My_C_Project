#ifndef TREND_LABEL_H_INCLUDED
#define TREND_LABEL_H_INCLUDED

#include "coordaxis.h"

#include <qstring.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qsize.h>
#include <qfont.h>
#include <qpen.h>
#include <qbrush.h>
#include <q3ptrlist.h>

class LabelItem
{
public:
	LabelItem();
	LabelItem(const QString& text);
	LabelItem(const QPixmap& pixmap);
	LabelItem(const QString& text, const QPixmap& pixmap);
	QString m_text;
	QPixmap m_pixmap;
};

/*
 *	文本标签类
 *
 *	关于标签对齐方式:
 *	m_HAlign		m_HOffset		m_HAxis				意义
 *	----------------------------------------------------------------
 *	左/右			左/右像素边距	NULL				左/右边距固定
 *	Justify			工程值			工程坐标轴			对齐的坐标值固定
 *	HCenter			(忽略)			NULL				自动水平居中对齐

 *	m_VAlign		m_VOffset		m_VAxis				意义
 *	----------------------------------------------------------------
 *	上/下			上/下像素边距	NULL				上/下边距固定
 *	Justify			工程值			工程坐标轴			对齐的坐标值固定
 *	VCenter			(忽略)			NULL				自动垂直居中对齐
 */
class TrendManager;
class HMITRENDOBJ_EXPORT Label
{
public:
	void InsertItems(const QStringList& strList);
	typedef enum Arrangement
	{
		LeftToRight,
		TopToBottom
	};
	//构造/析构
	Label(TrendManager* trendmgr);
	Label(TrendManager* trendmgr,const QPixmap& pixmap,const QString& text);
	Label(TrendManager* trendmgr,const QPixmap& pixmap);
	Label(TrendManager* trendmgr,const QString& text);

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Label & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Label & );

	//绘制
	void Draw(QPainter *p, const QSize& viewSize, int clipx, int clipy, int clipw, int cliph);

	//可见属性
	void SetVisible(bool visible);
	bool IsVisible();

	//停靠位置设置和读取
	void SetDockHCenter();
	void SetDockRight(int margin=5);
	void SetDockLeft(int margin=5);
	void SetDockVCenter();
	void SetDockTop(int margin=5);
	void SetDockBottom(int margin=5);
	void SetDockCenter();
	void SetDockVAdhereTo( CoordAxis* axis, double val );
	void SetDockHAdhereTo( CoordAxis* axis, double val );
	Qt::AlignmentFlag GetDockHMode(double* MarginOrVal, CoordAxis** ppAxis);
	Qt::AlignmentFlag GetDockVMode(double* MarginOrVal, CoordAxis** ppAxis);

	//大小模式设置和读取
	bool GetSizeMode(QSize& size);
	void SetSizeMode(bool fixsize,const QSize& size);
	void SetSizeMode(bool fixsize,int w, int h);
	//背景框风格和背景图片
	QPixmap GetBgPixmap(bool* tile);
	void GetBgRect(QPen& pen, QBrush& brush);
	void SetBgPixmapNull();
	void SetBgPixmap(const QPixmap& pixmap, bool tiled=false);
	void SetBgRect(const QPen& pen, const QBrush& brush);
	
	//排列方式/文本方向
	Arrangement GetArrangement();
	void SetArrangement(Arrangement arrange);
	void SetTextDirect(Arrangement arrange);
	Arrangement GetTextDirect();
	bool IsIconFirst();
	void SetIconFirst(bool b);

	//边距和间距
	int GetSpace();
	void SetSpace(int space);
	void GetMargins(int& t, int& l, int& b, int& r);
	void SetMargins(int t, int l, int b, int r);

	//文本字体/颜色/对齐
	void GetTextStyle(QFont &font, QColor &color);
	void SetTextStyle(const QFont& font, const QColor& color);
	int GetTextAlignment();
	void SetTextAlignment(int tf);

	//文本条目添加删除
	int GetItemCount();
	void ClearItems();
	void InsertItem(const QPixmap& pixmap, const QString& text);
	void InsertItem(const QString& text);
	void InsertItem(const QPixmap& pixmap);
	QPixmap* GetItemPixmap(int i);
	QString GetItemText(int i);
	
	QSize GetBackgroundSize();
	QRect GetBackgroundRect(const QSize& szBg,const QSize& szView);
protected:
	void DrawLabelItem( QPainter* p, const QPoint& pt, const QRect& bgRect, const QString& text, const QPixmap* pixmap );
	void DrawLabelItems(QPainter *p, const QRect &rect);
	void DrawBackground(QPainter *p, const QRect& rect);
	QSize GetItemSize(const QString& text, const QPixmap* pixmap);
private:
	TrendManager* m_owner;
	bool	m_bVisible;		//是否可见
	Qt::AlignmentFlag m_HAlign;	//水平位置
	Qt::AlignmentFlag m_VAlign;	//垂直位置
	CoordAxis*	m_pHAxis;			//水平对应的坐标轴(m_HAlign==Justify时)
	CoordAxis*	m_pVAxis;			//垂直对应的坐标轴(m_VAlign==Justify时)
	double	m_HOffset;				//水平边距
	double	m_VOffset;				//垂直边距

	QSize	m_bgSize;		//背景框大小
	QPen	m_bgPen;		//背景框画笔
	QBrush	m_bgBrush;		//背景框画刷
	QPixmap	m_bgPixmap;		//背景图片
	bool	m_bTileBgImg;	//true:平铺背景图片 false:拉伸

	QColor	m_textColor;		//文本颜色
	QFont	m_textFont;			//标签字体
	
	Q3PtrList<LabelItem>	m_labelItems;	//标签项列表
	int				m_marginT;		//标签边距
	int				m_marginL;		//标签边距
	int				m_marginB;		//标签边距
	int				m_marginR;		//标签边距
	int				m_space;		//标签项内部间距（标签项之间 以及 标签项的图标和文本之间)
	Arrangement		m_arrange;		//标签项排列方式
	bool			m_bIconFirst;	//true:图标在文字之前 false:图标在文字之后
	Arrangement		m_textDirection;//标签文本的文字方向
	int m_textAlign;	//标签文本的对齐方式Qt::AlignmentFlags
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Label & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Label & );

#endif	//TREND_LABEL_H_INCLUDED