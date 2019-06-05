/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionpluginwindowimpl.h
* 摘    要：界面表示对象窗口功能接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _IVISIONPLUGINWINDOWIMPL_H_
#define _IVISIONPLUGINWINDOWIMPL_H_

#include "ivisionplugin.h"

/*
 *  界面表示对象窗口功能接口实现模板(仅有窗口表示对象须实现)
 */
template <class T>
class IVisionPluginWindowImpl : public IVisionPluginWindow
{
public:
	//窗口基本功能
	QWidget* (GetWindow)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginWindow_GetWindow();
	}
	void (OnCreate)( QWidget* pParentWnd )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_OnCreate( pParentWnd );
	}
	void (OnDestroy)()
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_OnDestroy();
	}
	void (Show)()
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_Show();
	}
	void (Hide)()
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_Hide();
	}
	void (Move)( const QPoint& offset )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_Move( offset );
	}
	void (Resize)(int w, int h)
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginWindow_Resize( w, h );
	}

	//SVG导出
	bool (ExportSVGFile)( const QString& svgFile, const QString& imgRelPath )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginWindow_ExportSVGFile( svgFile, imgRelPath );
	}
	//IMG导出
	bool (ExportIMGFile)( const QString& imgFile, const QString& format, int quality = -1 )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginWindow_ExportIMGFile( imgFile, format, quality );
	}
};

#endif	//_IVISIONPLUGINWINDOWIMPL_H_