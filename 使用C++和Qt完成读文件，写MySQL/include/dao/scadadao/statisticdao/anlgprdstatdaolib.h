// anlgprdstatdaolib.h: implement for the CAnlgPrdStatDao class.
#ifndef _ANLGPRDSTATDAOLIB_20130310_PENGSHIKANG_H_
#define _ANLGPRDSTATDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/statisticdao/ianlgprdstatdao.h"    // for IAnlgPrdStatDao

//DLL输出的接口对象引用
class CAnlgPrdStatDao : public CIntfObjPtrB<IAnlgPrdStatDao>
{
public:
	CAnlgPrdStatDao() : CIntfObjPtrB<IAnlgPrdStatDao>
		(SCADADAO_MODULE, ANLGPRDSTATDAO_CLASSID, ANLGPRDSTATDAO_INTFID) { }
};

#endif 
