// vqcstradaolib.h: implement for the CVqcStraDao class.
#ifndef _VQCSTRADAOLIB_20130311_ZHANGPENG_H_
#define _VQCSTRADAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcstradao.h"// for IVqcStraDao

//DLL输出的接口对象引用
class CVqcStraDao : public CIntfObjPtrB<IVqcStraDao>
{
public:
	CVqcStraDao() : CIntfObjPtrB<IVqcStraDao>
		(SMGDAO_MODULE, VQCSTRADAO_CLASSID, VQCSTRADAO_INTFID) { }
};

#endif
