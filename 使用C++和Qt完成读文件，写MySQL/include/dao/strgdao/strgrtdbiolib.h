
#ifndef _STRGRTDBIOLIB_WX_20190529_H_
#define _STRGRTDBIOLIB_WX_20190529_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/idalibraryio.h" // for IDALibraryIO

#define STRGDAO_MODULE             "strgdao"

//DLL输出的接口对象引用
class CStrgRtdbIO : public CIntfObjPtrB<IDALibraryIO>
{
public:
	CStrgRtdbIO() : CIntfObjPtrB<IDALibraryIO>
		(STRGDAO_MODULE, DALIBRARYIO_CLASSID, DALIBRARYIO_INTFID) { }
};

#endif 
