// shareint.h: interface for the CShareInt class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SHAREINT_H__3F92F5E1_6F0F_PENGSHIKANG_20131108_D7FD607F4EDC__INCLUDED_
#define _SHAREINT_H__3F92F5E1_6F0F_PENGSHIKANG_20131108_D7FD607F4EDC__INCLUDED_

#include "statusbase.h"                          // for STATUSCODE_EXPORT
#include <qmutex.h>

class STATUSCODE_EXPORT CShareInt  
{
public:
	CShareInt();
	CShareInt(int nValue);
	CShareInt(CShareInt& nValue);
	CShareInt& operator=(int nValue);
	CShareInt& operator=(CShareInt& nValue);
	CShareInt& operator++();
	CShareInt& operator--();
	CShareInt& operator+=(int nValue);
	CShareInt& operator+=(CShareInt& nValue);
	CShareInt& operator-=(int nValue);
	CShareInt& operator-=(CShareInt& nValue);
	operator int();
	void SetValue(int nValue);
	int GetValue();

private:
	int m_value;
	QMutex m_mtxInt;
	
};

#endif
