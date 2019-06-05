// icsconfiglib.h: interface for the CICSConfigLib class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ICSCONFIGLIB__H_
#define _ICSCONFIGLIB__H_

#include "../commgr/intfobjptra.h"     // for CIntfObjPtrA<IntfObj>
#include "../../interface/icsconfig.h" // for IICSConfigFile

class CICSConfigLib : public CIntfObjPtrA<IICSConfigSection> 
{
public:
	CICSConfigLib() : CIntfObjPtrA<IICSConfigSection>(MODULE_XMLCONFIG)
	{
		m_pObj = (IICSConfigSection*)CreateDllObj(CLSID_ICS8000CFG);
	}

	//创建一个新的接口对象
	bool CreateConfigFile(IICSConfigFile** ppFile, const char* filename="")
	{
		*ppFile = (IICSConfigFile*)CreateObject(CLSID_XMLConfigFile, IID_IICSConfigFile);
		if(*ppFile == 0) return false;
		(*ppFile)->LoadFromFile(filename);
		return true; 
	}
	
};

#endif
