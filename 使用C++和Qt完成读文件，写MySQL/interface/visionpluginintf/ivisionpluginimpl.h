/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionpluginimpl.h
* 摘    要：界面表示对象基本功能接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _IVISIONPLUGINIMPL_H_
#define _IVISIONPLUGINIMPL_H_

#include "ivisionplugin.h"

/*
 *  界面表示对象基本功能接口实现模板
 */
template <class T>
class IVisionPluginImpl : public IVisionPlugin
{
public:
	//基本描述信息
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

	//基本图形信息
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

	//序列化
	bool (Serialize)( QDataStream& ds, bool bSave=true )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPlugin_Serialize( ds, bSave );
	}

	//状态信息
	void (SetRunState)( bool bRun=true )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPlugin_SetRunState( bRun );
	}
};

#endif	//_IVISIONPLUGINIMPL_H_