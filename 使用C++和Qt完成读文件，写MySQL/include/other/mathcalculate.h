// mathcalculate.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _CMATHCALCULATE_H_
#define _CMATHCALCULATE_H_

#include "../../interface/imathcalculate.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CMathCalculate: public CIntfObjPtrB<IMathCalculate>
{
public:
	CMathCalculate() : CIntfObjPtrB<IMathCalculate>(
		DLL_MATHCALCULATE, CID_MATHCALCULATE, IID_MATHCALCULATE) {}
};

#endif
