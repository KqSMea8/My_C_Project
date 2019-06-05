//
//////////////////////////////////////////////////////////////////////

#ifndef _EXPRESSCALCU_H_
#define _EXPRESSCALCU_H_

#include "../../interface/iexpresscalcu.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CExpressCalcu: public CIntfObjPtrB<IExpressCalcu>
{
public:
	CExpressCalcu() : CIntfObjPtrB<IExpressCalcu>(
		DLL_EXPRESSCALCU, CID_EXPRESSCALCU, IID_EXPRESSCALCU) {}
};

#endif
