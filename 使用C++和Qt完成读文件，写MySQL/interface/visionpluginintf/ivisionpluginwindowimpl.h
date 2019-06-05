/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionpluginwindowimpl.h
* ժ    Ҫ�������ʾ���󴰿ڹ��ܽӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _IVISIONPLUGINWINDOWIMPL_H_
#define _IVISIONPLUGINWINDOWIMPL_H_

#include "ivisionplugin.h"

/*
 *  �����ʾ���󴰿ڹ��ܽӿ�ʵ��ģ��(���д��ڱ�ʾ������ʵ��)
 */
template <class T>
class IVisionPluginWindowImpl : public IVisionPluginWindow
{
public:
	//���ڻ�������
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

	//SVG����
	bool (ExportSVGFile)( const QString& svgFile, const QString& imgRelPath )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginWindow_ExportSVGFile( svgFile, imgRelPath );
	}
	//IMG����
	bool (ExportIMGFile)( const QString& imgFile, const QString& format, int quality = -1 )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginWindow_ExportIMGFile( imgFile, format, quality );
	}
};

#endif	//_IVISIONPLUGINWINDOWIMPL_H_