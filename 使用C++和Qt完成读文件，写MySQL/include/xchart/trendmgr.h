#ifndef _COORDAXIS_MANAGER_H_INCLUDED_
#define _COORDAXIS_MANAGER_H_INCLUDED_

#include "coordaxis.h"
#include "trend.h"
#include "label.h"

#include <qobject.h>
#include <qdatastream.h>
#include <q3ptrlist.h>
#include <qdatetime.h>
//Added by qt3to4:
#include <QPixmap>

/*
 *	曲线管理类
 *	维护一个曲线系统中的坐标轴列表
 *	维护一个曲线系统中的曲线(数据序列)列表
 *	维护一个曲线系统中的文本标题信息
 *	管理坐标轴/曲线/文本标题的绘制工作
 *	代理每个子对象对象和外部环境(Widget)之间的通信
 */
class GBAVisionObject;
class HMITRENDOBJ_EXPORT TrendManager : public QObject
{
	Q_OBJECT
public:
	typedef	enum LabelArea
	{
		ViewportArea,
			FrameArea
	};

	TrendManager(QObject* parent=0, const char* name=0);
	~TrendManager();

	GBAVisionObject* GetGBAV();

	//序列化支持
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendManager & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendManager & );

	//协调内部管理的坐标轴/标题/图例/曲线的一致性
	void Reajust();

	//窗口显示风格	
	void GetFrameMargins(int* left, int* top, int* right, int* bottom);
	void SetFrameMargins(int left, int top, int right, int bottom);
	void SetContentSize(int w, int h);
	void SetContentSize(const QSize& size);
	QSize GetContentSize();
	int GetInnerFrmStyle();
	int GetOuterFrmStyle();
	void SetInnerFrmStyle(int style);
	void SetOuterFrmStyle(int style);
	void SetInnerFrmColor(const QColor& clr);
	QColor GetInnerFrmColor();
	QColor GetFrameBgClr();
	QColor GetContentsBgClr();
	void SetFrameBgClr(const QColor& clr);
	void SetContentsBgClr(const QColor& clr);
	void SetContBgImgNull();
	void SetFrameBgImgNull();
	void SetContBgImg(const QPixmap& pixmap,bool tiled);
	void SetFrameBgImg(const QPixmap& pixmap,bool tiled);
	QPixmap* GetContBgImg(bool* tiled=0);
	QPixmap* GetFrameBgImg(bool* tiled=0);

	//曲线系统绘制
	void DrawSepcialLines(QPainter *p, int clipx, int clipy, int clipw, int cliph, bool front);
	void DrawGrids(QPainter *p, int clipx, int clipy, int clipw, int cliph, bool front);
	void DrawViewportLabels(QPainter *p, const QSize& viewSize, int clipx, int clipy, int clipw, int cliph);
	void DrawFrameLabels(QPainter *p, const QSize& frmSize);
	void DrawTrends(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	void DrawCoordAxises(QPainter *p, const QRect &diagram);

	//坐标轴维护
	CoordAxis* GetCoordAxis(const QString& name);
	Q3PtrList<CoordAxis> GetAxisList();
	void AddCoordAxis(CoordAxis* pAxis);
	CoordAxis* AddCoordAxis(const QString& name);
	bool RemoveCoordAxis(CoordAxis* axis);
	bool RemoveCoordAxis(const QString& name);
	void RemoveAllCoordAxis();
	
	//曲线维护
	QStringList GetTrendNames();
	Q3PtrList<Trend> GetTrendList();
	Trend* GetTrend(const QString& name);
	void AddTrend(Trend* pTrend);
	Trend* AddTrend(const QString& name);
	bool RemoveTrend(const QString& name);
	bool RemoveTrend(Trend* trend);
	void RemoveAllTrend();
	int MoveTrendOrder(Trend* trend, int steps);
	
	//图例
	Label* GetLegend();
	LabelArea GetLegendArea();
	void SetLegendArea(LabelArea area);
	//标题
	void SetTitleArea(LabelArea area);
	LabelArea GetTitleArea();
	Label* GetSubTitle();
	Label* GetMainTitle();

	//其他标签
	void AddLabel(Label* label,LabelArea area);
	Label* AddLabel(LabelArea area, const QString& text);

	//Tooltip和浮标
	bool GetTooltipAt(int x, int y, int radio, QMap<QPoint,QStringList>& labels);
	bool GetDataLabelsAtLine(const QPoint &pt, int lineDirect, QMap<QPoint,QStringList>& labels);
	
	//交互功能
	//移动、翻页、缩放
	bool MoveAxises(int xoffset,int yoffset,bool bMoveRounded);
	void MoveAxisTo(const QString& axis, double val);
	void Scale(double h, double v, const QPoint& pos);

signals:
	void ContentsInvalidate( int x, int y, int w, int h );
	void ContentsInvalidate();
	void FrameInvalidate();
	void MarginsChanged( int l, int t, int r, int b );
	void FrameBgChanged(const QColor&,const QPixmap&);
	void ContentsBgChanged(const QColor&,const QPixmap&);
	void InnerFrmStyleChanged(int);
	void OuterFrmStyleChanged(int);

protected slots:
	void AdjustAxisOnNewVal( CoordAxis* axis, double val, int role );
	void OnTrendMinMaxChanged(const TrendField&,const QVariant&);
	void InitAxisPostion(CoordAxis* axis);
	void InitAxisesPosition();
	void InitLegend();
protected:
	bool GetMinMaxOfAxis(CoordAxis* axis, double& min, double& max);
	virtual GBAVisionObject* CreateGBAVsnObj();
private:
	void GetAxisOrigRelToRect( CoordAxis* pAxis, const QRect& diagram, double& origX, double& origY );
private:
	//窗体属性
	struct WndProperty{
		int leftMargin;		//左边距
		int rightMargin;	//右边距
		int topMargin;		//上边距
		int bottomMargin;	//下边距
		QSize contSize;		//内容区大小
		QColor frmColor;	//边框区(坐标轴区)背景
		QColor contColor;	//内容区(曲线和网格)背景
		QPixmap frmBgimg;	//边框区(坐标轴区)背景图片
		bool	frmTiled;	//背景图片平铺(true)/拉伸(false)
		QPixmap contBgimg;	//内容区(曲线和网格)背景图片
		bool	contTiled;	//背景图片平铺(true)/拉伸(false)
		int innerFrmStyle;	//内容区(曲线和网格)边框风格
		QColor innerFrmColor;//边框区(坐标轴区)边框风格
		int outerFrmStyle;	//边框区(坐标轴区)边框风格
	}m_wndProp;

	Q3PtrList<CoordAxis> m_axisList;		//坐标轴列表
	Q3PtrList<Trend>		m_trendList;	//曲线列表
	Label*		m_legend;		//曲线图例
	LabelArea	m_legendArea;	//曲线图例所在区域
	Label*		m_mainTitle;	//曲线主标题
	Label*		m_subTitle;		//曲线主标题
	LabelArea	m_titleArea;//曲线标题所在区域
	Q3PtrList<Label>		m_frmLabels;	//边框区标签列表
	Q3PtrList<Label>		m_viewLabels;	//内容区标签列表
	QDateTime m_dtLastDrag;		//最后一次拖拽曲线视图的时间

	GBAVisionObject* m_pGBAVsnObj;
};


HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendManager & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendManager & );

#endif	//_COORDAXIS_MANAGER_H_INCLUDED_
