/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionplugindesignimpl.h
* 摘    要：界面表示对象可视化设计支持功能接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _IVISIONPLUGINDESIGNIMPL_H_
#define _IVISIONPLUGINDESIGNIMPL_H_

#include "ivisionplugin.h"
//Added by qt3to4:
#include <Q3PointArray>

/*
 *  界面表示对象可视化设计支持功能接口实现模板
 */
template <class T>
class IVisionPluginDesignImpl : public IVisionPluginDesign
{
public:
	//Dispatch扩展支持(属性编辑器)
	bool (GetDispatch)( QObject** ppDispatch )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetDispatch( ppDispatch );
	}

	//在位激活交互支持(右键编辑菜单及鼠标双击)
	QStringList (EnumVerbs)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_EnumVerbs();
	}
	QStringList (EnumSubVerbs)( const QString& strParent )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_EnumSubVerbs( strParent );
	}
	QString (GetVerbDesc)( const QString& str )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetVerbDesc( str );
	}
	QString (GetDefaultVerb)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetDefaultVerb();
	}
	bool (DoVerb)( const QString& strVerb )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_DoVerb( strVerb );
	}

	//可视化编辑支持(鼠标调节,图形变换等操作)
	bool (IsSolidShape)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_IsSolidShape();
	}
	virtual bool IsSolidScale()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_IsSolidScale();
	}
	virtual bool IsEnableBound()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_IsEnableBound();
	}
	virtual QSize GetInitSize()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetInitSize();
	}
	virtual Q3PointArray* GetPointArray()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetPointArray();
	}
	virtual Q3PointArray* GetHandleArray()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetHandleArray();
	}
	virtual bool GetRegion( QRegion& rgn )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetRegion( rgn );
	}
	virtual void SetBoundRect( const QRect& rc )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginDesign_SetBoundRect( rc );
	}
	virtual bool AddPoint( const QPoint& ptRef )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_AddPoint( ptRef );
	}
	virtual void MoveHandleTo( int nIndex, const QPoint& ptRef )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginDesign_MoveHandleTo( nIndex, ptRef );
	}

	//数据组态支持
	QMap<QString,QVariant> (GetParams)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetParams();
	}
};

#endif	//_IVISIONPLUGINDESIGNIMPL_H_