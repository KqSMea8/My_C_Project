#ifndef _HMI_TREND_COORDAXIS_H_
#define _HMI_TREND_COORDAXIS_H_

#include "trendobjectexpdef.h"
#include "datavaluetype.h"
#include "coordaxisdisplay.h"

#include <qobject.h>
#include <qpoint.h>
#include <qpainter.h>
#include <q3valuelist.h>
#include <qmap.h> 
/*
 *	CoordAxis : ��������
 *	���������ݶ���
 *	�͸���������������ݺ���Ļ����֮��Ļ���ת��
 *	��������ͼ���Զ���
 *	���������
 *	�������ƶ�/����
 *	//TO DO : �Ƿ� m_m_posOrigin�Լ�PositionOfVal()��QPoint��Ϊlong(ֻ�����ض������λ��)
 */
class GBAVisionObject;
class HMITRENDOBJ_EXPORT SpecialMarkLine
{
public:
	QString name;
	QPen pen;
	double value;
	bool bShow;
};

class TrendManager;

class HMITRENDOBJ_EXPORT CoordAxis : public QObject
{
	Q_OBJECT
public:
	//�����᷽��
	enum Direction {
		Left  = 0,	//  <------
		Right,		//	------>
		Up,			//	^
		Down,		//	v
    };

	//ͣ��λ��
	enum DockArea {
		LeftArea = 0,
		RightArea,
		TopArea,
		BottomArea
	};
	
	//�ɼ���ʼֵ��̬����
	enum StartValDynamic
	{
		StaticVal = 0,
		CurPrimMark,
		CurSecMark,
		CurYear,
		CurMonth,
		CurWeek,
		CurDay,
		CurHour,
		CurMin
	};
	
	//����/����
	CoordAxis(TrendManager* trendManager);
	CoordAxis(TrendManager* trendManager, QString name, DataValueType::ValueType valType, Direction d, double primmask, double secmask, double pixelsPerUnit);
	~CoordAxis();

	//���л�֧��
	friend HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxis & );
	friend HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxis & );

	GBAVisionObject* GetGBAV();

	//����
	void Draw(QPainter* p, double origX, double origY, int clipx, int clipy, int clipw, int cliph);
	//���ƴ���ָ��
	CoordAxisDisplay* Displayer();

	//�����������úͶ�ȡ
	QString GetName();
	void SetName(const QString& name);
	QString GetCaption();
	void SetCaption(const QString& caption);
	QString GetUnit();
	void SetUnit(const QString& unit);
	Direction GetDirection();
	void SetDirection(Direction d);
	bool IsVertical();
	bool IsHorizontal();
	DockArea GetDockArea();
	void SetDockArea( DockArea area );
	DataValueType GetValType();
	void SetValType( const DataValueType& type );

	double GetThdMark();
	double GetSecMark();
	double GetPrimMark();
	void SetMarkSize(double prim,double second,double third);

	//����ֵ��Χ����
	double GetVisibleBegin();
	double GetVisibleRange();
	StartValDynamic GetStartValDynamic();
	void SetStartValDynamic( StartValDynamic dynamic );
	void SetVisibleRange(double range);
	void SetVisibleBegin(double val);
	void GetValueRange(double& min,double&max);
	void SetValueRange(double min, double max);
	double GetAutoAjustRange();
	bool IsAutoAjustBegin();
	bool IsAutoAjustEnd();
	void SetAutoAjust(bool bBegin,bool bEnd,double fMinRange);

	//����ֵ����Ļ����Ķ�Ӧ��ϵ
	double GetPixelsPerUnit();
	void SetPixelsPerUnit(double d);
	double GetOriginPos();
	void SetOriginPos(double pos);
	void MoveValTo(double val, double pos);
	void MoveBy(double offset);
	double GetScale();
	void Scale(double scale);

	//������ֵ���ݺ���Ļ����ת��
	double PositionOfVal( double val);
	double ValOfPosition( double pos);
	double ValOfPosition( const QPoint& pos);
	double NearestThdMark(double val);
	double NearestSecMark(double val);
	double NearestPrimMark(double val);
	double NearestThdMarkBefore(double val);
	double NearestThdMarkAfter(double val);
	double NearestSecMarkBefore(double val);
	double NearestSecMarkAfter(double val);
	double NearestPrimMarkBefore(double val);
	double NearestPrimMarkAfter(double val);
	double NextThdMark(double curThdMark);
	double NextSecMark(double curSecMark);
	double NextPrimMark(double curPrimMark);
	void GetMarkValuesBetween(double valStart, double valEnd, Q3ValueList<double>& primMarks, Q3ValueList<double>& secMarks, Q3ValueList<double>& thrdMarks);
	
	static void AutoCalVisibleRange(double valMin, double valMax, double& rangeMin, double& rangeMax, double fMinRange);
	
	void SetLineProperty( const QString& sKey, const QString& sProperty, QVariant var );
	QMap<QString, SpecialMarkLine> specialLinesMap;

	TrendManager* GetTrendManager() { return m_trendMgr; }

signals:
	void ViewChanged();		
	void FrameInvalidate();
protected:
	double NextMark(double  curMark, double markSize);
	double NearestMark(double val,double markSize);
	double NearestMarkAfter(double val,double markSize);
	double NearestMarkBefore(double val,double markSize);
protected:

private:
	CoordAxisDisplay* m_display;	//��������ƴ���

	QString m_strName;			//����������
	QString m_strCaption;		// ����
	QString m_strUnit;			//�����ᵥλ
	DockArea m_dockArea;		//������ͣ������
	Direction m_direct;			//�����᷽��
	DataValueType m_VType;

	double m_fMinVal;			//���ֵ
	double m_fMaxVal;			//��Сֵ
	double m_fPrimMark;			//ÿ�����̶��߶�Ӧ�ĵ�λ��
	double m_fSecMark;			//ÿ�����̶��߶�Ӧ�ĵ�λ��
	double m_fThdMark;			//ÿ�����̶��߶�Ӧ�ĵ�λ��

	double m_fVisibleBegin;			//Ĭ����ʾ����ʼֵ
	StartValDynamic	m_startDynamic;	//��ʾ����ʼֵ��̬����
	//Ĭ�ϵĿɼ��Ĺ���ֵ���
	//���ڴ�С�ı�ʱ���Զ�����m_fPixelsPerUnit�Ա�֤����ʾ�ÿ�ȷ�Χ�Ĺ���ֵ����
	//�����ֵ<=0����Ը�ֵ�����Ǹ��ݴ��ڴ�С��m_fPixelsPerUnit�������ƿ��
	double m_fVisibleRange;
	double m_fPixelsPerUnit;	//ÿ�����굥λ��Ӧ��������
	double m_posOrigin;			//����ԭ��(����ֵ0��)����Ļ����ƽ���ϵ�λ��
	bool   m_bAutoAjustBegin;		//�Ƿ��Զ�����������ɼ���Χ
	bool   m_bAutoAjustEnd;		//�Ƿ��Զ�����������ɼ���Χ
	double m_fMinAutoRange;		//�Զ�����������ɼ���Χ����Сֵ

	double m_fScale;			//������ʾ����
	double m_orgPMark;
	double m_orgSMark;
	double m_orgTMark;

	GBAVisionObject* m_pGBAVsnObj;

	TrendManager* m_trendMgr;

	friend class CoordAxisDisplay;
};

HMITRENDOBJ_EXPORT QDataStream &operator<<( QDataStream &, const CoordAxis & );
HMITRENDOBJ_EXPORT QDataStream &operator>>( QDataStream &, CoordAxis & );

#endif	//_HMI_TREND_COORDAXIS_H_