// onlinemodel.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _MANUALFT_H_
#define _MANUALFT_H_

#include "../../interface/imanualftrigger.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class CManualFt: public CIntfObjPtrB<IManualFtrigger>
{
public:
	CManualFt() : CIntfObjPtrB<IManualFtrigger>(
		DLL_MANUALFTRIGGER, CID_MANUALFTRIGGER, IID_MANUALFTRIGGER) {}
};

#endif
