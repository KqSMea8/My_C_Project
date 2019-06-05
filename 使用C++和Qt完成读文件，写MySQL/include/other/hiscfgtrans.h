//
//////////////////////////////////////////////////////////////////////

#ifndef _HISCFGTRANS_H_
#define _HISCFGTRANS_H_

#include "../../interface/ihiscfgtrans.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CHisCfgTrans: public CIntfObjPtrB<IHisCfgTrans>
{
public:
	CHisCfgTrans() : CIntfObjPtrB<IHisCfgTrans>(
		DLL_HISCFGTRANS, CID_HISCFGTRANS, IID_HISCFGTRANS) {}
};

#endif
