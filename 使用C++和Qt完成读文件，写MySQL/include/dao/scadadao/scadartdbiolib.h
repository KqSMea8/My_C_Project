// scadartdbiolib.h: implement for the CScadaRtdbIO class.
#ifndef _SCADARTDBIOLIB_PENGSHIKANG_20131206_H_
#define _SCADARTDBIOLIB_PENGSHIKANG_20131206_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/idalibraryio.h" // for IDALibraryIO

#define SCADADAO_MODULE             "scadadao"

//DLL输出的接口对象引用
class CScadaRtdbIO : public CIntfObjPtrB<IDALibraryIO>
{
public:
	CScadaRtdbIO() : CIntfObjPtrB<IDALibraryIO>
		(SCADADAO_MODULE, DALIBRARYIO_CLASSID, DALIBRARYIO_INTFID) { }
};

#endif 
