// anlgstatdaolib.h: implement for the CAnlgStatDao class.
#ifndef _ANLGSTATDAOLIB_20130310_PENGSHIKANG_H_
#define _ANLGSTATDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/ianlgstatdao.h"    // for IAnlgStatDao

//DLL输出的接口对象引用
class CAnlgStatDao : public CIntfObjPtrB<IAnlgStatDao>
{
public:
	CAnlgStatDao(IAnalogDao* pAnalog) : CIntfObjPtrB<IAnlgStatDao>
		(SCADADAO_MODULE, ANLGSTATDAO_CLASSID, ANLGSTATDAO_INTFID, (void**)&pAnalog) { }
};

#endif 
