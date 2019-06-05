// vqcstratypedaolib.h: implement for the CVqcStraTypeDao class.
#ifndef _VQCSTRATYPEDAOLIB_20160819_PENGSHIKANG_H_
#define _VQCSTRATYPEDAOLIB_20160819_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcstratypedao.h" // for IVqcStraTypeDao

//DLL输出的接口对象引用
class CVqcStraTypeDao : public CIntfObjPtrB<IVqcStraTypeDao>
{
public:
	CVqcStraTypeDao() : CIntfObjPtrB<IVqcStraTypeDao>
		(SMGDAO_MODULE, VQCSTRATYPEDAO_CLASSID, VQCSTRATYPEDAO_INTFID) { }
};

#endif
