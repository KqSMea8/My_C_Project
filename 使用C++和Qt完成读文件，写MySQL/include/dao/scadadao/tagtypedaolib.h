// tagtypedaolib.h: implement for the CTagTypeDao class.
#ifndef _TAGTYPEDAOLIB_20130311_PENGSHIKANG_H_
#define _TAGTYPEDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/itagtypedao.h"    // for ITagTypeDao

//DLL输出的接口对象引用
class CTagTypeDao : public CIntfObjPtrB<ITagTypeDao>
{
public:
	CTagTypeDao() : CIntfObjPtrB<ITagTypeDao>
		(SCADADAO_MODULE, TAGTYPEDAO_CLASSID, TAGTYPEDAO_INTFID) { }
};

#endif 