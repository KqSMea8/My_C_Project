// makeguid.h: interface for the g_MakeGuidDll¡¢CMakeGuid class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _MakeGuidCAL_H_2007_05_11_PENGSHIKANG_INCLUDED_
#define _MakeGuidCAL_H_2007_05_11_PENGSHIKANG_INCLUDED_

#include "../../interface/imakeguid.h"  // for IMakeGuid
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CMakeGuid : public CIntfObjPtrB<IMakeGuid>
{
public:
	CMakeGuid() : CIntfObjPtrB<IMakeGuid>(
		DLL_MAKEGUID, CID_XJMAKEGUID, IID_XJMAKEGUID) {}
};

#endif
