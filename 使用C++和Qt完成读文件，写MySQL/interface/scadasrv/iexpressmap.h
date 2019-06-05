// iexpressmap.h: interface for the IExpressMap class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IEXPRESSMAP_H__PENGSHIKANG_20120812__INCLUDED_
#define _IEXPRESSMAP_H__PENGSHIKANG_20120812__INCLUDED_

#include "exprmapdef.h"                          // for ExpPoint��ExpMap��ExpSet

class IExpressMap  
{
public:
	//���ɱ��ʽӳ��
	virtual bool MakeExpMap(int pos, const char* expr, ExpMap& expObj) = 0;
	//��ñ��ʽ��������ʵʱֵ�ַ���
	virtual bool GetValueString(const ExpPoint& prmPoint, char* sValue, int& quality) = 0;
};

#endif
