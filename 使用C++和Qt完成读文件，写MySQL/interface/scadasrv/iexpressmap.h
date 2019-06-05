// iexpressmap.h: interface for the IExpressMap class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IEXPRESSMAP_H__PENGSHIKANG_20120812__INCLUDED_
#define _IEXPRESSMAP_H__PENGSHIKANG_20120812__INCLUDED_

#include "exprmapdef.h"                          // for ExpPoint、ExpMap、ExpSet

class IExpressMap  
{
public:
	//生成表达式映射
	virtual bool MakeExpMap(int pos, const char* expr, ExpMap& expObj) = 0;
	//获得表达式测点参数的实时值字符串
	virtual bool GetValueString(const ExpPoint& prmPoint, char* sValue, int& quality) = 0;
};

#endif
