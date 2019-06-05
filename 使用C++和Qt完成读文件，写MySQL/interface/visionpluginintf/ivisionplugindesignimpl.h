/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionplugindesignimpl.h
* ժ    Ҫ�������ʾ������ӻ����֧�ֹ��ܽӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _IVISIONPLUGINDESIGNIMPL_H_
#define _IVISIONPLUGINDESIGNIMPL_H_

#include "ivisionplugin.h"
//Added by qt3to4:
#include <Q3PointArray>

/*
 *  �����ʾ������ӻ����֧�ֹ��ܽӿ�ʵ��ģ��
 */
template <class T>
class IVisionPluginDesignImpl : public IVisionPluginDesign
{
public:
	//Dispatch��չ֧��(���Ա༭��)
	bool (GetDispatch)( QObject** ppDispatch )
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetDispatch( ppDispatch );
	}

	//��λ�����֧��(�Ҽ��༭�˵������˫��)
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

	//���ӻ��༭֧��(������,ͼ�α任�Ȳ���)
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

	//������̬֧��
	QMap<QString,QVariant> (GetParams)()
	{
		T* pT = static_cast<T*>(this);
		return pT->IVisionPluginDesign_GetParams();
	}
};

#endif	//_IVISIONPLUGINDESIGNIMPL_H_