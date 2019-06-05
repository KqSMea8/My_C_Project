// vqcparamdaolib.h: implement for the CVqcParamDao class.
#ifndef _VQCPARAMDAOLIB_20130311_ZHANGPENG_H_
#define _VQCPARAMDAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcparamdao.h"// for IVqcParamDao

//DLL输出的接口对象引用
class CVqcParamDao : public CIntfObjPtrB<IVqcParamDao>
{
public:
	CVqcParamDao() : CIntfObjPtrB<IVqcParamDao>
		(SMGDAO_MODULE, VQCPARAMDAO_CLASSID, VQCPARAMDAO_INTFID) { }
};

#endif 
