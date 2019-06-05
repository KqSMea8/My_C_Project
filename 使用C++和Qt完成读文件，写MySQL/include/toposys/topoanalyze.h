// topoanalyze.h: interface for the CTopoMath class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _TOPOANALYZE_H_20120625_PENGSHIKANG_INCLUDED_
#define _TOPOANALYZE_H_20120625_PENGSHIKANG_INCLUDED_

#include "../../interface/toposys/itopologic.h"  // for ITopologic
#include "../commgr/intfobjptra.h"      // for CIntfObjPtrA<IntfObj>

class CTopoAnalyze : public CIntfObjPtrA<ITopologic>
{
public:
	CTopoAnalyze() : CIntfObjPtrA<ITopologic>(
		MODULE_TOPOLOGIC, CLSID_TOPOLOGIC, IID_TOPOLOGIC) {}
};

#endif
