/*
* Copyright (c) 2007,��̼������޹�˾
* All rights reserved.
* 
* �ļ����ƣ�ivisionpluginviewimpl.h
* ժ    Ҫ�������ʾ������ͼ���ܽӿ�ʵ��ģ��
*
* �汾�ţ�1.0   ���ߣ��޿���  ������ڣ�2007��6��30��
*/
#ifndef _IVISIONPLUGINVIEWIMPL_H_
#define _IVISIONPLUGINVIEWIMPL_H_

#include "ivisionplugin.h"

/*
 *  �����ʾ������ͼ���ܽӿ�ʵ��ģ��(���Ǵ��ڱ�ʾ������ʵ��)
 */
template <class T>
class IVisionPluginViewImpl : public IVisionPluginView
{
public:
	//����
	void (Draw)( QPainter* pPainter, const QRect& rcBounds )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginView_Draw( pPainter, rcBounds );
	}
};

#endif	//_IVISIONPLUGINVIEWIMPL_H_