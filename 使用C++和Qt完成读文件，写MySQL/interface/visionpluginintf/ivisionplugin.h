/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionplugin.h
* 摘    要：界面表示对象功能接口定义
*
* 版本号：1.1   作者：罗开明  完成日期：2007年6月30日
* 
* 版本号：1.0   作者：刘铁刚  完成日期：2005年7月20日
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
 *  界面表示对象基本功能接口
 */
class IVisionPlugin : virtual public IICSUnknown
{
public:
	//基本描述信息
	virtual QString GetCLSID() = 0;
	virtual QString GetDesc() = 0;
	virtual QImage GetIcon() = 0;

	//基本图形信息
	virtual QString GetToolTip() = 0;
	virtual bool HasWindow() = 0;

	//序列化
	virtual bool Serialize( QDataStream& ds, bool bSave=true ) = 0;

	//状态信息
	virtual void SetRunState( bool bRun=true ) = 0;
};

/*
 *  界面表示对象可视化设计支持功能接口
 */
class IVisionPluginDesign : virtual public IICSUnknown
{
public:
	//Dispatch扩展支持(属性编辑器)
	virtual bool GetDispatch( QObject** ppDispatch ) = 0;

	//在位激活交互支持(右键编辑菜单及鼠标双击)
	virtual QStringList EnumVerbs() = 0;
	virtual QStringList EnumSubVerbs( const QString& strParent ) = 0;
	virtual QString GetVerbDesc( const QString& str ) = 0;
	virtual QString GetDefaultVerb() = 0;
	virtual bool DoVerb( const QString& strVerb ) = 0;

	//可视化编辑支持(鼠标调节,图形变换等操作)
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

	//数据组态支持
	virtual QMap<QString,QVariant> GetParams() = 0;
};

/*
 *  界面表示对象窗口功能接口(仅有窗口表示对象须实现)
 */
class IVisionPluginWindow : virtual public IICSUnknown
{
public:
	//窗口基本功能
	virtual QWidget* GetWindow() = 0;
	virtual void OnCreate( QWidget* pParentWnd ) = 0;
	virtual void OnDestroy() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	virtual void Move( const QPoint& offset ) = 0;
	virtual void Resize(int w, int h) = 0;

	//SVG导出
	virtual bool ExportSVGFile( const QString& svgFile, const QString& imgRelPath ) = 0;
	//IMG导出
	virtual bool ExportIMGFile( const QString& imgFile, const QString& format, int quality = -1 ) = 0;
};

/*
 *  界面表示对象视图功能接口
 */
class IVisionPluginView : virtual public IICSUnknown
{
public:
	//绘制
	virtual void Draw( QPainter* pPainter, const QRect& rcBounds ) = 0;
};

/*
 *  界面表示对象运行时功能接口
 */
class GBAVisionObject;
class IVisionPluginRuntime : virtual public IICSUnknown
{
public:
	//Dispatch扩展支持(脚本设计支持)
	virtual bool GetDispatch( QObject** ppDispatch ) = 0;
	virtual GBAVisionObject* GetGBAV() = 0;

	//在位交互支持(右键操作菜单及鼠标双击)
	virtual QStringList EnumVerbs() = 0;
	virtual QStringList EnumSubVerbs( const QString& strParent ) = 0;
	virtual QString GetVerbDesc( const QString& str ) = 0;
	virtual QString GetDefaultVerb() = 0;
	virtual bool DoVerb( const QString& strVerb ) = 0;

	//鼠标交互支持
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

	//运行时控制
	virtual bool Initialize() = 0;
	virtual bool Start() = 0;
	virtual bool Pause() = 0;
	virtual bool Resume() = 0;
	virtual bool Stop() = 0;
	virtual bool UnInitialize() = 0;

	//更新提交
	virtual void Update( int nIndex, const QVariant& val ) = 0;
	virtual void Update( const QString& param, const QVariant& val ) = 0;
	virtual void Update( const QMap<QString,QVariant>vals ) = 0;
	virtual void Update() = 0;	//表示对象内部处理
	virtual bool Commit() = 0;	//表示对象内部处理
};

#pragma   warning(disable:4250)

/*定义接口的智能指针*/
typedef CQIPtr<IVisionPlugin> VisionPlugin;
typedef CQIPtr<IVisionPluginDesign> VisionPluginDesign;
typedef CQIPtr<IVisionPluginWindow> VisionPluginWindow;
typedef CQIPtr<IVisionPluginView> VisionPluginView;
typedef CQIPtr<IVisionPluginRuntime> VisionPluginRuntime;

#endif	//_IVISIONPLUGIN_H_