// sharedouble.h: interface for the CShareDouble class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SHAREDOUBLE_H__3F92F5E1_6F0F_PENGSHIKANG_20121206_D7FD607F4EDC__INCLUDED_
#define _SHAREDOUBLE_H__3F92F5E1_6F0F_PENGSHIKANG_20121206_D7FD607F4EDC__INCLUDED_

#include "statusbase.h"                          // for STATUSCODE_EXPORT
#include <qmutex.h>

class STATUSCODE_EXPORT CShareDouble  
{
public:
	CShareDouble();
	CShareDouble(double dValue);
	CShareDouble(CShareDouble& dValue);
	CShareDouble& operator=(double dValue);
	CShareDouble& operator=(CShareDouble& dValue);
	operator double();
	void SetValue(double dValue);
	double GetValue();

private:
	double m_value;
	QMutex m_mtxDbl;
	
};

#endif
