
#ifndef _STREAMTOOL__H_
#define _STREAMTOOL__H_

#include <qstringlist.h>
//Added by qt3to4:
#include <Q3PtrList>

#include "icsvariant.h"
#include "icsstring.h"

class IICSStream;

class OBJECTBASE_EXPORT CStreamTool
{
public:
    CStreamTool(IICSStream *pStream);
    ~CStreamTool();
	
    CStreamTool& operator >>(bool& b);
    CStreamTool& operator >>(BYTE& b);
    CStreamTool& operator >>(short& s);
    CStreamTool& operator >>(int& i);
    CStreamTool& operator >>(float& f);
    CStreamTool& operator >>(double& d);
    CStreamTool& operator >>(char* p);
    CStreamTool& operator >>(QString& s);
	CStreamTool& operator >>(CICSString& s);
	CStreamTool& operator >>(IICSUnknown** ppunk);
    CStreamTool& operator >>(QStringList& strlist);
    CStreamTool& operator >>(Q3PtrList<CICSVariant>& vlist);
    CStreamTool& operator >>(icsarray& ary);
    CStreamTool& operator >>(icsvariant& v);
    CStreamTool& operator >>(CICSVariant& v);
	
    CStreamTool& operator <<(const bool b);
    CStreamTool& operator <<(const BYTE b);
    CStreamTool& operator <<(const short& s);
    CStreamTool& operator <<(const int& i);
    CStreamTool& operator <<(const float& f);
    CStreamTool& operator <<(const double& d);
    CStreamTool& operator <<(const char* p);
    CStreamTool& operator <<(const QString& s);
	CStreamTool& operator <<(const CICSString& s);	
	CStreamTool& operator <<(IICSUnknown* punk);
    CStreamTool& operator <<(const QStringList& strlist);
    CStreamTool& operator <<(const Q3PtrList<CICSVariant>& vlist);
    CStreamTool& operator <<(const icsarray& ary);
    CStreamTool& operator <<(const icsvariant& v);
    CStreamTool& operator <<(const CICSVariant& v);
	
private:
    IICSStream* m_pStream;
	inline void NtoH(BYTE* pDst, const BYTE* pSrc, size_t nSize);
	inline CStreamTool& GetData(BYTE* pData, size_t nSize);
	inline CStreamTool& SetData(const BYTE* pData, size_t nSize);
};

#endif
