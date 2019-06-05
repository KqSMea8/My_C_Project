/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionpluginimpl.h
* ժ    Ҫ�������ʾ����������ܽӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _IVISIONPLUGINIMPL_H_
#define _IVISIONPLUGINIMPL_H_

#include "ivisionplugin.h"

/*
 *  �����ʾ����������ܽӿ�ʵ��ģ��
 */
template <class T>
class IVisionPluginImpl : public IVisionPlugin
{
public:
	//����������Ϣ
	QString (GetCLSID)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_GetCLSID();
	}
	QString (GetDesc)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_GetDesc();
	}
	QImage (GetIcon)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_GetIcon();
	}

	//����ͼ����Ϣ
	QString (GetToolTip)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_GetToolTip();
	}
	bool (HasWindow)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_HasWindow();
	}

	//���л�
	bool (Serialize)( QDataStream& ds, bool bSave=true )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_Serialize( ds, bSave );
	}

	//״̬��Ϣ
	void (SetRunState)( bool bRun=true )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPlugin_SetRunState( bRun );
	}
};

#endif	//_IVISIONPLUGINIMPL_H_