// imakeguid.h
#ifndef __IXJMAKEGUID_2007_05_11_PENGSHIKANG_H__
#define __IXJMAKEGUID_2007_05_11_PENGSHIKANG_H__

#include "icsunknown.h" // for IICSUnknown

#define DLL_MAKEGUID           "makeguid"
#define CID_XJMAKEGUID         "icsmakeguid"
#define IID_XJMAKEGUID         "iicsmakeguid"

class IMakeGuid : public IICSUnknown
{
public:
	//µÃµ½GUID
	virtual void CreateGuid(char* guid) = 0;

};

#endif
