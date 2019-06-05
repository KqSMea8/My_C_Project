/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionpluginruntimeimpl.h
* 摘    要：界面表示对象运行时功能接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _IVISIONPLUGINRUNTIMEIMPL_H_
#define _IVISIONPLUGINRUNTIMEIMPL_H_

#include "ivisionplugin.h"

/*
 *  界面表示对象运行时功能接口实现模板
 */
template <class T>
class IVisionPluginRuntimeImpl : public IVisionPluginRuntime
{
public:
	//Dispatch扩展支持(脚本设计支持)
	bool (GetDispatch)( QObject** ppDispatch )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_GetDispatch( ppDispatch );
	}

	GBAVisionObject* (GetGBAV)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_GetGBAV();
	}

	//在位交互支持(右键操作菜单及鼠标双击)
	QStringList (EnumVerbs)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_EnumVerbs();
	}
	QStringList (EnumSubVerbs)( const QString& strParent )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_EnumSubVerbs( strParent );
	}
	QString (GetVerbDesc)( const QString& str )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_GetVerbDesc( str );
	}
	QString (GetDefaultVerb)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_GetDefaultVerb();
	}
	bool (DoVerb)( const QString& strVerb )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_DoVerb( strVerb );
	}

	//鼠标交互支持
	void (OnMouseEnter)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnMouseEnter( point );
	}
	void (OnMouseMove)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnMouseMove( point );
	}
	void (OnMouseLeave)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnMouseLeave( point );
	}
	void (OnLBDown)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnLBDown( point );
	}
	void (OnLBUp)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnLBUp( point );
	}
	void (OnLBClick)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnLBClick( point );
	}
	void (OnLBDblClick)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnLBDblClick( point );
	}
	void (OnRBDwon)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnRBDwon( point );
	}
	void (OnRBUp)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnRBUp( point );
	}
	void (OnRBClick)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnRBClick( point );
	}
	void (OnRBDblClick)( const QPoint& point )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_OnRBDblClick( point );
	}

	//运行时控制
	bool (Initialize)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Initialize();
	}
	bool (Start)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Start();
	}
	bool (Pause)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Pause();
	}
	bool (Resume)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Resume();
	}
	bool (Stop)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Stop();
	}
	bool (UnInitialize)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_UnInitialize();
	}

	//更新提交
	void (Update)( int nIndex, const QVariant& val )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_Update( nIndex, val );
	}
	void (Update)( const QString& param, const QVariant& val )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_Update( param, val );
	}
	void (Update)( const QMap<QString,QVariant>vals )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_Update( vals );
	}
	void (Update)()
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginRuntime_Update();
	}
	bool (Commit)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginRuntime_Commit();
	}
};

#endif	//_IVISIONPLUGINRUNTIMEIMPL_H_