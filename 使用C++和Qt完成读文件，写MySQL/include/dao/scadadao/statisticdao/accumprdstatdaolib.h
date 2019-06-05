// accumprdstatdaolib.h: implement for the CAccumPrdStatDao class.
#ifndef _ACCUMPRDSTATDAOLIB_20130310_PENGSHIKANG_H_
#define _ACCUMPRDSTATDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/iaccumprdstatdao.h"    // for IAccumPrdStatDao

//DLL输出的接口对象引用
class CAccumPrdStatDao : public CIntfObjPtrB<IAccumPrdStatDao>
{
public:
	CAccumPrdStatDao() : CIntfObjPtrB<IAccumPrdStatDao>
		(SCADADAO_MODULE, ACCUMPRDSTATDAO_CLASSID, ACCUMPRDSTATDAO_INTFID) { }
};

#endif 
