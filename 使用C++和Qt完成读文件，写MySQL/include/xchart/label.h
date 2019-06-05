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
 *	�ı���ǩ��
 *
 *	���ڱ�ǩ���뷽ʽ:
 *	m_HAlign		m_HOffset		m_HAxis				����
 *	----------------------------------------------------------------
 *	��/��			��/�����ر߾�	NULL				��/�ұ߾�̶�
 *	Justify			����ֵ			����������			���������ֵ�̶�
 *	HCenter			(����)			NULL				�Զ�ˮƽ���ж���

 *	m_VAlign		m_VOffset		m_VAxis				����
 *	----------------------------------------------------------------
 *	��/��			��/�����ر߾�	NULL				��/�±߾�̶�
 *	Justify			����ֵ			����������			���������ֵ�̶�
 *	VCenter			(����)			NULL				�Զ���ֱ���ж���
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
	//����/����
	Label(TrendManager* trendmgr);
	Label(TrendManager* trendmgr,const QPixmap& pixmap,const QString& text);
	Label(TrendManager* trendmgr,const QPixmap& pixmap);
	Label(TrendManager* trendmgr,const QString& text);

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Label & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Label & );

	//����
	void Draw(QPainter *p, const QSize& viewSize, int clipx, int clipy, int clipw, int cliph);

	//�ɼ�����
	void SetVisible(bool visible);
	bool IsVisible();

	//ͣ��λ�����úͶ�ȡ
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

	//��Сģʽ���úͶ�ȡ
	bool GetSizeMode(QSize& size);
	void SetSizeMode(bool fixsize,const QSize& size);
	void SetSizeMode(bool fixsize,int w, int h);
	//��������ͱ���ͼƬ
	QPixmap GetBgPixmap(bool* tile);
	void GetBgRect(QPen& pen, QBrush& brush);
	void SetBgPixmapNull();
	void SetBgPixmap(const QPixmap& pixmap, bool tiled=false);
	void SetBgRect(const QPen& pen, const QBrush& brush);
	
	//���з�ʽ/�ı�����
	Arrangement GetArrangement();
	void SetArrangement(Arrangement arrange);
	void SetTextDirect(Arrangement arrange);
	Arrangement GetTextDirect();
	bool IsIconFirst();
	void SetIconFirst(bool b);

	//�߾�ͼ��
	int GetSpace();
	void SetSpace(int space);
	void GetMargins(int& t, int& l, int& b, int& r);
	void SetMargins(int t, int l, int b, int r);

	//�ı�����/��ɫ/����
	void GetTextStyle(QFont &font, QColor &color);
	void SetTextStyle(const QFont& font, const QColor& color);
	int GetTextAlignment();
	void SetTextAlignment(int tf);

	//�ı���Ŀ���ɾ��
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
	bool	m_bVisible;		//�Ƿ�ɼ�
	Qt::AlignmentFlag m_HAlign;	//ˮƽλ��
	Qt::AlignmentFlag m_VAlign;	//��ֱλ��
	CoordAxis*	m_pHAxis;			//ˮƽ��Ӧ��������(m_HAlign==Justifyʱ)
	CoordAxis*	m_pVAxis;			//��ֱ��Ӧ��������(m_VAlign==Justifyʱ)
	double	m_HOffset;				//ˮƽ�߾�
	double	m_VOffset;				//��ֱ�߾�

	QSize	m_bgSize;		//�������С
	QPen	m_bgPen;		//�����򻭱�
	QBrush	m_bgBrush;		//������ˢ
	QPixmap	m_bgPixmap;		//����ͼƬ
	bool	m_bTileBgImg;	//true:ƽ�̱���ͼƬ false:����

	QColor	m_textColor;		//�ı���ɫ
	QFont	m_textFont;			//��ǩ����
	
	Q3PtrList<LabelItem>	m_labelItems;	//��ǩ���б�
	int				m_marginT;		//��ǩ�߾�
	int				m_marginL;		//��ǩ�߾�
	int				m_marginB;		//��ǩ�߾�
	int				m_marginR;		//��ǩ�߾�
	int				m_space;		//��ǩ���ڲ���ࣨ��ǩ��֮�� �Լ� ��ǩ���ͼ����ı�֮��)
	Arrangement		m_arrange;		//��ǩ�����з�ʽ
	bool			m_bIconFirst;	//true:ͼ��������֮ǰ false:ͼ��������֮��
	Arrangement		m_textDirection;//��ǩ�ı������ַ���
	int m_textAlign;	//��ǩ�ı��Ķ��뷽ʽQt::AlignmentFlags
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const Label & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, Label & );

#endif	//TREND_LABEL_H_INCLUDED