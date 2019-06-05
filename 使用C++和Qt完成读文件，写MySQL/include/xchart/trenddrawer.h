#ifndef _TREND_DRAWER_H_INCLUDED_
#define _TREND_DRAWER_H_INCLUDED_

#include <qobject.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qcolor.h>
#include <qnamespace.h>

#include "datanode.h"

class Trend;
class GBAVisionObject;

/*
 *	曲线绘制工具类
 *	定义了曲线绘制工具类的接口
 *	
 */
class HMITRENDOBJ_EXPORT TrendDrawer	: public QObject
{
	Q_OBJECT
public:
	typedef enum DrawerType
	{
		Dot = 0,
		Curve,
		Spline,
		RightAngle,
		Line,
		Bar,
		Bar3D,
		ImageBar,
		Ellipse,
		Arc,
		Pie
	};

	TrendDrawer(Trend* pTrend,DrawerType type, const QString& typeName, const char* name);
	~TrendDrawer();

	//创建、保存和加载
	static TrendDrawer* CreateDrawer( DrawerType type, Trend* pTrend);
	static bool SaveToData( TrendDrawer* drawer, QByteArray &ba );
	static TrendDrawer* LoadFromData(const QByteArray& ba,Trend* pTrend);
	
	GBAVisionObject* GetGBAV();

	//基本函数
	DrawerType GetType();
	QString GetTypeName();
	Trend* GetOwnerTrend();
	QString GetName();
	void SetName(const QString& name);
	QString GetDesc();
	void SetDesc(const QString& desc);
	void SetVisible(bool visible);
	bool IsVisible();
	//序列化
	virtual bool Serialize( QDataStream& stream, bool bSerialize);
	//绘制曲线
	virtual void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph) = 0;
	//屏幕坐标pt是否与曲线相交
	virtual bool IntersectsWith( const QPoint& pt ) = 0;
	//屏幕区域rc是否与曲线相交
	virtual bool IntersectsWith( const QRect& rc ) = 0;
	//屏幕坐标pt附近处的曲线值点以及值点的确切位置
	virtual bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn ) = 0;
	//经过pt的直线与曲线的交点处要显示的动态文本标签 lineDirect: 0 pt附近  1 垂直线 2 水平线 3十字交叉线
	virtual bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false ) = 0;
	//得到曲线视图的图例图标
	virtual int GetIconCount();
	virtual bool GetIcon( QPixmap& icon, QString& desc, const QColor& bg, int index );
	virtual QPixmap GetIcon( const QColor& bg )	= 0;

protected:
	virtual GBAVisionObject* CreateGBAVsnObj();
	Trend* m_pTrend;
	DrawerType m_type;
	QString m_typeName;
	QString m_name;
	QString m_desc;
	bool m_bVisible;
signals:
	//该曲线视图的示例图标改变，需要更新图例
	void IconChanged();
	//该曲线视图的视图表现改变，需要重新绘制
	void ViewChanged(int x, int y, int w, int h);
	void ViewChanged();
	//可见属性改变
	void VisibleChanged();

private:
	GBAVisionObject* m_pGBAVsnObj;
};

HMITRENDOBJ_EXPORT bool operator<( const QPoint&, const QPoint& );

#endif	//_TREND_DRAWER_H_INCLUDED_