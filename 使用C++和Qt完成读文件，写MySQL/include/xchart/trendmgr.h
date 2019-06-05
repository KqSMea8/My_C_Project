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
 *	���߹�����
 *	ά��һ������ϵͳ�е��������б�
 *	ά��һ������ϵͳ�е�����(��������)�б�
 *	ά��һ������ϵͳ�е��ı�������Ϣ
 *	����������/����/�ı�����Ļ��ƹ���
 *	����ÿ���Ӷ��������ⲿ����(Widget)֮���ͨ��
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

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendManager & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendManager & );

	//Э���ڲ������������/����/ͼ��/���ߵ�һ����
	void Reajust();

	//������ʾ���	
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

	//����ϵͳ����
	void DrawSepcialLines(QPainter *p, int clipx, int clipy, int clipw, int cliph, bool front);
	void DrawGrids(QPainter *p, int clipx, int clipy, int clipw, int cliph, bool front);
	void DrawViewportLabels(QPainter *p, const QSize& viewSize, int clipx, int clipy, int clipw, int cliph);
	void DrawFrameLabels(QPainter *p, const QSize& frmSize);
	void DrawTrends(QPainter *p, int clipx, int clipy, int clipw, int cliph);
	void DrawCoordAxises(QPainter *p, const QRect &diagram);

	//������ά��
	CoordAxis* GetCoordAxis(const QString& name);
	Q3PtrList<CoordAxis> GetAxisList();
	void AddCoordAxis(CoordAxis* pAxis);
	CoordAxis* AddCoordAxis(const QString& name);
	bool RemoveCoordAxis(CoordAxis* axis);
	bool RemoveCoordAxis(const QString& name);
	void RemoveAllCoordAxis();
	
	//����ά��
	QStringList GetTrendNames();
	Q3PtrList<Trend> GetTrendList();
	Trend* GetTrend(const QString& name);
	void AddTrend(Trend* pTrend);
	Trend* AddTrend(const QString& name);
	bool RemoveTrend(const QString& name);
	bool RemoveTrend(Trend* trend);
	void RemoveAllTrend();
	int MoveTrendOrder(Trend* trend, int steps);
	
	//ͼ��
	Label* GetLegend();
	LabelArea GetLegendArea();
	void SetLegendArea(LabelArea area);
	//����
	void SetTitleArea(LabelArea area);
	LabelArea GetTitleArea();
	Label* GetSubTitle();
	Label* GetMainTitle();

	//������ǩ
	void AddLabel(Label* label,LabelArea area);
	Label* AddLabel(LabelArea area, const QString& text);

	//Tooltip�͸���
	bool GetTooltipAt(int x, int y, int radio, QMap<QPoint,QStringList>& labels);
	bool GetDataLabelsAtLine(const QPoint &pt, int lineDirect, QMap<QPoint,QStringList>& labels);
	
	//��������
	//�ƶ�����ҳ������
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
	//��������
	struct WndProperty{
		int leftMargin;		//��߾�
		int rightMargin;	//�ұ߾�
		int topMargin;		//�ϱ߾�
		int bottomMargin;	//�±߾�
		QSize contSize;		//��������С
		QColor frmColor;	//�߿���(��������)����
		QColor contColor;	//������(���ߺ�����)����
		QPixmap frmBgimg;	//�߿���(��������)����ͼƬ
		bool	frmTiled;	//����ͼƬƽ��(true)/����(false)
		QPixmap contBgimg;	//������(���ߺ�����)����ͼƬ
		bool	contTiled;	//����ͼƬƽ��(true)/����(false)
		int innerFrmStyle;	//������(���ߺ�����)�߿���
		QColor innerFrmColor;//�߿���(��������)�߿���
		int outerFrmStyle;	//�߿���(��������)�߿���
	}m_wndProp;

	Q3PtrList<CoordAxis> m_axisList;		//�������б�
	Q3PtrList<Trend>		m_trendList;	//�����б�
	Label*		m_legend;		//����ͼ��
	LabelArea	m_legendArea;	//����ͼ����������
	Label*		m_mainTitle;	//����������
	Label*		m_subTitle;		//����������
	LabelArea	m_titleArea;//���߱�����������
	Q3PtrList<Label>		m_frmLabels;	//�߿�����ǩ�б�
	Q3PtrList<Label>		m_viewLabels;	//��������ǩ�б�
	QDateTime m_dtLastDrag;		//���һ����ק������ͼ��ʱ��

	GBAVisionObject* m_pGBAVsnObj;
};


HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const TrendManager & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, TrendManager & );

#endif	//_COORDAXIS_MANAGER_H_INCLUDED_
