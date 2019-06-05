/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionpluginruntimeimpl.h
* ժ    Ҫ�������ʾ��������ʱ���ܽӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _IVISIONPLUGINRUNTIMEIMPL_H_
#define _IVISIONPLUGINRUNTIMEIMPL_H_

#include "ivisionplugin.h"

/*
 *  �����ʾ��������ʱ���ܽӿ�ʵ��ģ��
 */
template <class T>
class IVisionPluginRuntimeImpl : public IVisionPluginRuntime
{
public:
	//Dispatch��չ֧��(�ű����֧��)
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

	//��λ����֧��(�Ҽ������˵������˫��)
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

	//��꽻��֧��
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

	//����ʱ����
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

	//�����ύ
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