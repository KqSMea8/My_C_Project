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
 *	���߻��ƹ�����
 *	���������߻��ƹ�����Ľӿ�
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

	//����������ͼ���
	static TrendDrawer* CreateDrawer( DrawerType type, Trend* pTrend);
	static bool SaveToData( TrendDrawer* drawer, QByteArray &ba );
	static TrendDrawer* LoadFromData(const QByteArray& ba,Trend* pTrend);
	
	GBAVisionObject* GetGBAV();

	//��������
	DrawerType GetType();
	QString GetTypeName();
	Trend* GetOwnerTrend();
	QString GetName();
	void SetName(const QString& name);
	QString GetDesc();
	void SetDesc(const QString& desc);
	void SetVisible(bool visible);
	bool IsVisible();
	//���л�
	virtual bool Serialize( QDataStream& stream, bool bSerialize);
	//��������
	virtual void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph) = 0;
	//��Ļ����pt�Ƿ��������ཻ
	virtual bool IntersectsWith( const QPoint& pt ) = 0;
	//��Ļ����rc�Ƿ��������ཻ
	virtual bool IntersectsWith( const QRect& rc ) = 0;
	//��Ļ����pt������������ֵ���Լ�ֵ���ȷ��λ��
	virtual bool GetDateNodeAt( QPoint& pt, int radio, DataNode& dn ) = 0;
	//����pt��ֱ�������ߵĽ��㴦Ҫ��ʾ�Ķ�̬�ı���ǩ lineDirect: 0 pt����  1 ��ֱ�� 2 ˮƽ�� 3ʮ�ֽ�����
	virtual bool GetDataLabelsAtLine( const QPoint& pt, int lineDirect, QMap<QPoint,QStringList>& labels, bool bRealNodeOnly = false ) = 0;
	//�õ�������ͼ��ͼ��ͼ��
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
	//��������ͼ��ʾ��ͼ��ı䣬��Ҫ����ͼ��
	void IconChanged();
	//��������ͼ����ͼ���ָı䣬��Ҫ���»���
	void ViewChanged(int x, int y, int w, int h);
	void ViewChanged();
	//�ɼ����Ըı�
	void VisibleChanged();

private:
	GBAVisionObject* m_pGBAVsnObj;
};

HMITRENDOBJ_EXPORT bool operator<( const QPoint&, const QPoint& );

#endif	//_TREND_DRAWER_H_INCLUDED_