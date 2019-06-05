#ifndef _TREND_TRENDDISPLAY_H_INCLUDED_
#define _TREND_TRENDDISPLAY_H_INCLUDED_

#include "trenddrawer.h"

#include <qpainter.h>
#include <q3ptrlist.h>
#include <qmap.h>

class Trend;

/*
 *	���߻��ƴ�����
 *	���߻��Ʋ�������
 *	���߻��ƻ���
 */
class HMITRENDOBJ_EXPORT TrendDisplay : public QObject
{
	Q_OBJECT
public:
	TrendDisplay(Trend* pOwner,const char* name=0);

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendDisplay & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendDisplay & );

	QStringList GetTrendDrawerNames();
	TrendDrawer* GetTrendDrawer(const QString& name);
	void RemoveTrendDrawer(const QString& name);
	Q3PtrList<TrendDrawer> GetTrendDrawers();
	TrendDrawer* AddTrendDrawer(TrendDrawer::DrawerType type, const QString& name, const QString& desc);
	bool AddTrendDrawer(TrendDrawer* drawer);
	int MoveDrawerOrder(TrendDrawer* drawer, int steps);
	void Draw(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	void SetVisible(bool visible);
	bool IsVisible();
protected:
private:
	Trend* m_pOwner;
	Q3PtrList<TrendDrawer> m_trendViews;	//������ͼ�б�
	bool	m_bVisible;
signals:
	//�����ߵ�ʾ��ͼ��ı䣬��Ҫ����ͼ��
	void IconChanged();
	//������ĳ����ͼ����ͼ���ָı䣬��Ҫ���»���
	void ViewChanged(int x, int y, int w, int h);
	void ViewChanged();
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendDisplay & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendDisplay & );

#endif	//_TREND_TRENDDISPLAY_H_INCLUDED_