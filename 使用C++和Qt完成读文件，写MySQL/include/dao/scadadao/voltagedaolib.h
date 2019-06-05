// voltagedaolib.h: implement for the CAbruptDao class.
#ifndef _VOLTAGEDAOLIB_20130311_PENGSHIKANG_H_
#define _VOLTAGEDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ivoltagedao.h"    // for IVoltageDao

//DLL输出的接口对象引用
class CVoltageDao : public CIntfObjPtrB<IVoltageDao>
{
public:
	CVoltageDao() : CIntfObjPtrB<IVoltageDao>
		(SCADADAO_MODULE, VOLTAGEDAO_CLASSID, VOLTAGEDAO_INTFID) { }
};

#endif 