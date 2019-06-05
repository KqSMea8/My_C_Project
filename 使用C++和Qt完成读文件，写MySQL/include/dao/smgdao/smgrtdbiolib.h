// smgrtdbiolib.h: implement for the CSmgRtdbIO class.
#ifndef _SMGRTDBIOLIB_PENGSHIKANG_20131206_H_
#define _SMGRTDBIOLIB_PENGSHIKANG_20131206_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/idalibraryio.h" // for IDALibraryIO

#define SMGDAO_MODULE             "smgdao"

//DLL输出的接口对象引用
class CSmgRtdbIO : public CIntfObjPtrB<IDALibraryIO>
{
public:
	CSmgRtdbIO() : CIntfObjPtrB<IDALibraryIO>
		(SMGDAO_MODULE, DALIBRARYIO_CLASSID, DALIBRARYIO_INTFID) { }
};

#endif 
