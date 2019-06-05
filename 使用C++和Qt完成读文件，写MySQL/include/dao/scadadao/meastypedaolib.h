// imeastypedaolib.h: implement for the CMeasTypeDao class.
#ifndef _MEASTYPEDAOLIB_20130310_PENGSHIKANG_H_
#define _MEASTYPEDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/imeastypedao.h"    // for IMeasTypeDao

//DLL输出的接口对象引用
class CMeasTypeDao : public CIntfObjPtrB<IMeasTypeDao>
{
public:
	CMeasTypeDao() : CIntfObjPtrB<IMeasTypeDao>
		(SCADADAO_MODULE, MEASTYPEDAO_CLASSID, MEASTYPEDAO_INTFID) { }
};

#endif 
