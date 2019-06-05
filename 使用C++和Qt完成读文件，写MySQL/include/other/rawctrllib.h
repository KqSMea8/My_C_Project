// rawctrllib.h: IRawCtrl loader
#ifndef RAWCTRLLIB_H
#define RAWCTRLLIB_H

#include "../commgr/intfobjptra.h"     // for CIntfObjPtrA
#include "../../interface/scadactrl/irawctrl.h"
#include "../../interface/scadactrl/scadactrl_defines.h"

//DLL输出的接口对象引用
class CRAWCtrlLib : public CIntfObjPtrA<IRawCtrl>
{
public:
	CRAWCtrlLib() : CIntfObjPtrA<IRawCtrl>
		(MODULE_SCADACTRLCLIENT, CLSID_IRAWCTRL, IID_IRAWCTRL) { }
};
	
#endif /* RAWCTRLLIB_H */
