/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionplugin.h
* ժ    Ҫ�������ʾ�����ܽӿڶ���
*
* �汾�ţ�1.1   ���ߣ��޿���  ������ڣ�2007��6��30��
* 
* �汾�ţ�1.0   ���ߣ�������  ������ڣ�2005��7��20��
*/
#ifndef _IVISIONPLUGIN_H_
#define _IVISIONPLUGIN_H_

#include "../icsunknown.h"
#include "../generalintf.h"
#include "../qiptr.h"

#define IID_IVisionPlugin			"ivisionplugin"
#define IID_IVisionPluginDesign		"ivisionplugindesign"
#define IID_IVisionPluginWindow		"ivisionpluginwindow"
#define IID_IVisionPluginView		"ivisionpluginview"
#define IID_IVisionPluginRuntime	"ivisionpluginruntime"

#include <qobject.h>
#include <qstring.h>
#include <qimage.h>
#include <qdatastream.h>
#include <qsize.h>
#include <qstringlist.h>
#include <qcursor.h>
#include <qpoint.h>
#include <qrect.h>
#include <qmap.h>
#include <qvariant.h>
#include <qwidget.h>
//Added by qt3to4:
#include <Q3PointArray>

/*
 *  �����ʾ����������ܽӿ�
 */
class IVisionPlugin : virtual public IICSUnknown
{
public:
	//����������Ϣ
	virtual QString GetCLSID() = 0;
	virtual QString GetDesc() = 0;
	virtual QImage GetIcon() = 0;

	//����ͼ����Ϣ
	virtual QString GetToolTip() = 0;
	virtual bool HasWindow() = 0;

	//���л�
	virtual bool Serialize( QDataStream& ds, bool bSave=true ) = 0;

	//״̬��Ϣ
	virtual void SetRunState( bool bRun=true ) = 0;
};

/*
 *  �����ʾ������ӻ����֧�ֹ��ܽӿ�
 */
class IVisionPluginDesign : virtual public IICSUnknown
{
public:
	//Dispatch��չ֧��(���Ա༭��)
	virtual bool GetDispatch( QObject** ppDispatch ) = 0;

	//��λ�����֧��(�Ҽ��༭�˵������˫��)
	virtual QStringList EnumVerbs() = 0;
	virtual QStringList EnumSubVerbs( const QString& strParent ) = 0;
	virtual QString GetVerbDesc( const QString& str ) = 0;
	virtual QString GetDefaultVerb() = 0;
	virtual bool DoVerb( const QString& strVerb ) = 0;

	//���ӻ��༭֧��(������,ͼ�α任�Ȳ���)
	virtual bool IsSolidShape() = 0;
	virtual bool IsSolidScale() = 0;
	virtual bool IsEnableBound() = 0;
	virtual QSize GetInitSize() = 0;
	virtual Q3PointArray* GetPointArray() = 0;
	virtual Q3PointArray* GetHandleArray() = 0;
	virtual bool GetRegion( QRegion& rgn ) = 0;
	virtual void SetBoundRect( const QRect& rc ) = 0;
	virtual bool AddPoint( const QPoint& ptRef ) = 0;
	virtual void MoveHandleTo( int nIndex, const QPoint& ptRef ) = 0;

	//������̬֧��
	virtual QMap<QString,QVariant> GetParams() = 0;
};

/*
 *  �����ʾ���󴰿ڹ��ܽӿ�(���д��ڱ�ʾ������ʵ��)
 */
class IVisionPluginWindow : virtual public IICSUnknown
{
public:
	//���ڻ�������
	virtual QWidget* GetWindow() = 0;
	virtual void OnCreate( QWidget* pParentWnd ) = 0;
	virtual void OnDestroy() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void Move( const QPoint& offset ) = 0;
	virtual void Resize(int w, int h) = 0;

	//SVG����
	virtual bool ExportSVGFile( const QString& svgFile, const QString& imgRelPath ) = 0;
	//IMG����
	virtual bool ExportIMGFile( const QString& imgFile, const QString& format, int quality = -1 ) = 0;
};

/*
 *  �����ʾ������ͼ���ܽӿ�
 */
class IVisionPluginView : virtual public IICSUnknown
{
public:
	//����
	virtual void Draw( QPainter* pPainter, const QRect& rcBounds ) = 0;
};

/*
 *  �����ʾ��������ʱ���ܽӿ�
 */
class GBAVisionObject;
class IVisionPluginRuntime : virtual public IICSUnknown
{
public:
	//Dispatch��չ֧��(�ű����֧��)
	virtual bool GetDispatch( QObject** ppDispatch ) = 0;
	virtual GBAVisionObject* GetGBAV() = 0;

	//��λ����֧��(�Ҽ������˵������˫��)
	virtual QStringList EnumVerbs() = 0;
	virtual QStringList EnumSubVerbs( const QString& strParent ) = 0;
	virtual QString GetVerbDesc( const QString& str ) = 0;
	virtual QString GetDefaultVerb() = 0;
	virtual bool DoVerb( const QString& strVerb ) = 0;

	//��꽻��֧��
	virtual void OnMouseEnter( const QPoint& point ) = 0;
	virtual void OnMouseMove( const QPoint& point ) = 0;
	virtual void OnMouseLeave( const QPoint& point ) = 0;
	virtual void OnLBDown( const QPoint& point ) = 0;
	virtual void OnLBUp( const QPoint& point ) = 0;
	virtual void OnLBClick( const QPoint& point ) = 0;
	virtual void OnLBDblClick( const QPoint& point ) = 0;
	virtual void OnRBDwon( const QPoint& point ) = 0;	
	virtual void OnRBUp( const QPoint& point ) = 0;
	virtual void OnRBClick( const QPoint& point ) = 0;
	virtual void OnRBDblClick( const QPoint& point ) = 0;

	//����ʱ����
	virtual bool Initialize() = 0;
	virtual bool Start() = 0;
	virtual bool Pause() = 0;
	virtual bool Resume() = 0;
	virtual bool Stop() = 0;
	virtual bool UnInitialize() = 0;

	//�����ύ
	virtual void Update( int nIndex, const QVariant& val ) = 0;
	virtual void Update( const QString& param, const QVariant& val ) = 0;
	virtual void Update( const QMap<QString,QVariant>vals ) = 0;
	virtual void Update() = 0;	//��ʾ�����ڲ�����
	virtual bool Commit() = 0;	//��ʾ�����ڲ�����
};

#pragma   warning(disable:4250)

/*����ӿڵ�����ָ��*/
typedef CQIPtr<IVisionPlugin> VisionPlugin;
typedef CQIPtr<IVisionPluginDesign> VisionPluginDesign;
typedef CQIPtr<IVisionPluginWindow> VisionPluginWindow;
typedef CQIPtr<IVisionPluginView> VisionPluginView;
typedef CQIPtr<IVisionPluginRuntime> VisionPluginRuntime;

#endif	//_IVISIONPLUGIN_H_