//
//////////////////////////////////////////////////////////////////////

#ifndef _INTERFACECRTEXPCAL_H_
#define _INTERFACECRTEXPCAL_H_

#include "../../interface/irtexpcal.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CRtExpcal: public CIntfObjPtrB<IRtExpcal>
{
public:
	CRtExpcal() : CIntfObjPtrB<IRtExpcal>(
		DLL_RTEXPCAL, CID_RTEXPCAL, IID_RTEXPCAL) {}
};

#endif
