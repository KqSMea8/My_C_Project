/*
* Copyright (c) 2007,许继集团有限公司
* All rights reserved.
* 
* 文件名称：ivisionpluginviewimpl.h
* 摘    要：界面表示对象视图功能接口实现模板
*
* 版本号：1.0   作者：罗开明  完成日期：2007年6月30日
*/
#ifndef _IVISIONPLUGINVIEWIMPL_H_
#define _IVISIONPLUGINVIEWIMPL_H_

#include "ivisionplugin.h"

/*
 *  界面表示对象视图功能接口实现模板(仅非窗口表示对象须实现)
 */
template <class T>
class IVisionPluginViewImpl : public IVisionPluginView
{
public:
	//绘制
	void (Draw)( QPainter* pPainter, const QRect& rcBounds )
	{
		T* pT = static_cast<T*>(this);
		pT->IVisionPluginView_Draw( pPainter, rcBounds );
	}
};

#endif	//_IVISIONPLUGINVIEWIMPL_H_