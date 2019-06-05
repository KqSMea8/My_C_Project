// dummymapdaolib.h: implement for the CDummyCalDao class.
#ifndef _DUMMYMAPDAOLIB_20130310_PENGSHIKANG_H_
#define _DUMMYMAPDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/idummymapdao.h"    // for IDummyCalDao

//DLL输出的接口对象引用
class CDummyCalDao : public CIntfObjPtrB<IDummyCalDao>
{
public:
	CDummyCalDao(const char* tableName) : CIntfObjPtrB<IDummyCalDao>
		(SCADADAO_MODULE, DUMMYCALDAO_CLASSID, DUMMYCALDAO_INTFID, (void**)&tableName) { }
};

#endif 
