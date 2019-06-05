// objectbaselib.h: implement for the CRegCodeLib class.
#ifndef _OBJECTBASE_REGISTCODELIB_2011_09_19_PENGSHIKANG_H_
#define _OBJECTBASE_REGISTCODELIB_2011_09_19_PENGSHIKANG_H_

#include "../commgr/intfobjptra.h"               // for CIntfObjPtrA
#include "../../interface/imystatuscode.h"       // for IMyStatusCode
#include "../../interface/generalintf.h"         // for IICSEnum¡¢IICSStream

class CStatusCodeLib : public CIntfObjPtrA<IMyStatusCode>
{
public:
	CStatusCodeLib() : CIntfObjPtrA<IMyStatusCode>(DLL_MYSTATUSCODE, CID_MYSTATUSCODE, IID_MYSTATUSCODE)
	{
		m_pObj = CreateObject(CID_MYSTATUSCODE, IID_MYSTATUSCODE);
	}
};

class CICSEnumLib : public CIntfObjPtrA<IICSEnum>
{
public:
	CICSEnumLib() : CIntfObjPtrA<IICSEnum>(DLL_OBJECTBASE, CLSID_IICSEnum, IID_IICSEnum)
	{
		m_pObj = CreateObject(CLSID_IICSEnum, IID_IICSEnum);
	}
};

class CICSStreamLib : public CIntfObjPtrA<IICSStream>
{
public:
	CICSStreamLib() : CIntfObjPtrA<IICSStream>(DLL_OBJECTBASE, CLSID_ICSStream, IID_IICSStream)
	{
		m_pObj = CreateObject(CLSID_ICSStream, IID_IICSStream);
	}
};

#endif 
