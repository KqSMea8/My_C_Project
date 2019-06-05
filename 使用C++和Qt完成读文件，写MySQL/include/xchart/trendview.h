#ifndef _HMI_TRENDVIEW_H_
#define _HMI_TRENDVIEW_H_

#include <q3scrollview.h>
#include <q3pointarray.h>
#include <qimage.h>
//Added by qt3to4:
#include <QPixmap>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QContextMenuEvent>

#include "trendobjectexpdef.h"

#include "trendproject.h"
#include "trendmgr.h"

class CoordAxis;
class TrendViewTooltip;
class HMITRENDOBJ_EXPORT TrendView : public Q3ScrollView
{
	Q_OBJECT
public:
	TrendView( QWidget * parent = 0, const char * name = 0 );
	//边框区大小
	void GetFrameMargins(int* left, int* top, int* right, int* bottom);
	int GetLeftMargin();
	int GetRightMargin();
	int GetTopMargin();
	int GetBottomMargin();
	//边框区和内容区背景颜色
	QColor GetContentsBgClr();
	QColor GetFrameBgClr();

	//曲线管理单元
	TrendProject* GetTrendProject();
	TrendManager* GetTrendManager();

	//SVG输出
	bool SaveToSVGFile(const QString& svgFile, const QString& imgRelPath);
	bool SaveToIMGFile(const QString& imgFile, const char* format, int quality = -1);
	
protected:
	int GetDobberMarkRect(const QString& strVal, CoordAxis* axis, int x, int y, QPainter* p, QRect& rc);
	void DrawDobberAxisMark( QPainter* pntrFrm,int x, int y);
	void DrawDobberCrsLineAndLabel( QPainter* pntrView,int x, int y);
	void DrawDobberTrendMark( QPainter* pntrView,int x, int y);
	void contentsMouseDoubleClickEvent ( QMouseEvent * e );
	void contentsMouseMoveEvent ( QMouseEvent * e );
	void contentsMousePressEvent ( QMouseEvent * e );
	void contentsMouseReleaseEvent ( QMouseEvent * e );
	void contentsContextMenuEvent ( QContextMenuEvent * e );
	void viewportResizeEvent ( QResizeEvent * e);
	bool eventFilter( QObject *, QEvent *e );
	void viewportPaintEvent( QPaintEvent* pe );
	void drawFrame ( QPainter * p );
	void drawContents ( QPainter * p, int clipx, int clipy, int clipw, int cliph );
	void DrawFrameBg(QPainter *p);
	void DrawContBg(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	void DrawInnerFrame(QPainter* p);
public slots:
	void ReloadSettings();
	void SetFrameMargins(int left, int top, int right, int bottom);
	void SetInnerFrmStyle(int style);
	void SetOuterFrmStyle(int style);
	void SetContentsBg(const QColor& clr,const QPixmap& pixmap);
	void SetFrameBg(const QColor& clr,const QPixmap& pixmap);
	void OnTrendContentsInvalidate(int x, int y, int w, int h);
	void OnTrendContentsInvalidate();
	void OnTrendFrameInvalidate();
	void OnMaybeTip(const QPoint& pos);
private:
	TrendViewTooltip* m_pTooltip;
	TrendProject* m_trendPrj;
	TrendManager* m_pTrendMgr;
	int	m_innerFrmStyle;
	QImage m_FrmBgImg;
	QImage m_ContBgImg;
	//0 : 不绘制游标 1 : 仅绘制交叉线和坐标轴游标
	//2: 绘制竖直交点 3: 绘制水平交点
	int m_mousestate;
	QPoint m_lastMove;
	QPoint m_startMove;

	int m_nDrawDobber;
	
// 	QMap<int,QRect> lastAxis_Rect;	//上次被覆盖的矩形区域
// 	QMap<int,QImage> lastAxis_Image;	//上次被覆盖的位图拷贝
// 	QMap<int,QRect> lastLbl_Rect;	//上次被覆盖的矩形区域
// 	QMap<int,QImage> lastLbl_Image;	//上次被覆盖的位图拷贝
};

#endif	//_HMI_TRENDVIEW_H_