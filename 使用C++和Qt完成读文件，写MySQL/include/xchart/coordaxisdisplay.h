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
 *	��������ƴ�����
 *	��������Ʋ�������
 *	���������
 */
class HMITRENDOBJ_EXPORT CoordAxisDisplay
{
public:
	enum GridMode{
		NoGrid,		//��
		PrimGrid,	//���������̶�����
		AllGrid,	//����������������������
		PAndSGrid	//�������������̶�����
	};

	//���л�֧��
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

	QPen	m_penLine;			//�������߻���
	int		m_nMarkLength;		//���̶��߳���
	bool	m_bShowLine;		//����������/�̶����Ƿ�ɼ�
	QColor	m_clrText;			//�ı���ɫ

	bool	m_bShowCaption;		//���������(���Ƶ�λ)�Ƿ�ɼ�
	QFont	m_fontCaption;		//��������
	int		m_captionAlign;		//�����ı����뷽ʽ(Qt::AlignmentFlags)
	int		m_captionOffset;	//�����ı���������ľ���


	double	m_fTxtRotate;			//�̶��ı���ת�Ƕ�
	QFont	m_fontMarkText;			//�̶��ı�����
	bool	m_bShowPMarkText;		//���̶����ı��Ƿ�ɼ�
	DataValueType	m_pmarkFormat;	//���̶����ı���ʽ
	bool	m_bShowSMarkText;		//�����̶��ı��Ƿ�ɼ�
	DataValueType	m_smarkFormat;	//�����̶����ı���ʽ
	bool	m_bShowTMarkText;		//�����̶��ı��Ƿ�ɼ�
	DataValueType	m_tmarkFormat;	//�����̶����ı���ʽ

	GridMode	m_gridMode;		//��������ʾ����
	bool		m_gridFront;	//�������������ϲ�
	QPen	m_gridPPen;			//�����񻭱�
	QPen	m_gridSPen;			//�������񻭱�
	QPen	m_gridTPen;			//�������񻭱�
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxisDisplay & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxisDisplay & );

#endif	//_COORDAXISDRAW_H_INCLUDED_