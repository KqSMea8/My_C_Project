// shareqstring.h: interface for the CShareQString class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SHAREQSTRING_H__3F92F5E1_6F0F_PENGSHIKANG_20121207_D7FD607F4EDC__INCLUDED_
#define _SHAREQSTRING_H__3F92F5E1_6F0F_PENGSHIKANG_20121207_D7FD607F4EDC__INCLUDED_

#include "statusbase.h"                          // for STATUSCODE_EXPORT
#include <qstring.h>
#include <qmutex.h>

class STATUSCODE_EXPORT CShareQString  
{
public:
	CShareQString();
	CShareQString(const char* sValue);
	CShareQString(CShareQString& ssValue);
	CShareQString& operator=(const char* sValue);
	CShareQString& operator=(CShareQString& ssValue);
	operator const char*();
	void SetValue(const char* sValue);
	const QString& GetValue();

private:
	QString m_value;
	QMutex m_mtxStr;
	
};

#endif
