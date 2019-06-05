// voltadjcoefdaolib.h: implement for the CVoltAdjCoefDao class.
#ifndef _VOLTAGEADJUSTCOEFICIENTLIB_PENGSHIKANG_20170213_H_
#define _VOLTAGEADJUSTCOEFICIENTLIB_PENGSHIKANG_20170213_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ivoltadjcoefdao.h" // for IVoltAdjCoefDao

//DLL输出的接口对象引用
class CVoltAdjCoefDao : public CIntfObjPtrB<IVoltAdjCoefDao>
{
public:
	CVoltAdjCoefDao() : CIntfObjPtrB<IVoltAdjCoefDao>
		(SMGDAO_MODULE, VOLTADJCOEFDAO_CLASSID, VOLTADJCOEFDAO_INTFID) { }
};

#endif
