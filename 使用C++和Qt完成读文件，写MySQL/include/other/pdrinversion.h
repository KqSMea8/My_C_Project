//
//////////////////////////////////////////////////////////////////////

#ifndef _PDRINVERSION_H_
#define _PDRINVERSION_H_

#include "../../interface/ipdrinversion.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CPdrInversion: public CIntfObjPtrB<IPdrInversion>
{
public:
	CPdrInversion() : CIntfObjPtrB<IPdrInversion>(
		DLL_PDRINVERSION, CID_PDRINVERSION, IID_PDRINVERSION) {}
};

#endif
