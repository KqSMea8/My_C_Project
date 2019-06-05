// vqcsettypedaolib.h: implement for the CVqcSetTypeDao class.
#ifndef _VQCSETTYPEDAOLIB_20130311_ZHANGPENG_H_
#define _VQCSETTYPEDAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcsettypedao.h"// for IVqcSetTypeDao

//DLL输出的接口对象引用
class CVqcSetTypeDao : public CIntfObjPtrB<IVqcSetTypeDao>
{
public:
	CVqcSetTypeDao() : CIntfObjPtrB<IVqcSetTypeDao>
		(SMGDAO_MODULE, VQCSETTYPEDAO_CLASSID, VQCSETTYPEDAO_INTFID) { }
};

#endif
