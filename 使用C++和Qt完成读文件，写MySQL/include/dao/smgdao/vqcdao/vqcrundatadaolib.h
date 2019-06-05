// vqcrundatadaolib.h: implement for the CVqcRunDataDao class.
#ifndef _VQCRUNDATADAOLIB_20130311_ZHANGPENG_H_
#define _VQCRUNDATADAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcrundatadao.h"// for IVqcRunDataDao

//DLL输出的接口对象引用
class CVqcRunDataDao : public CIntfObjPtrB<IVqcRunDataDao>
{
public:
	CVqcRunDataDao() : CIntfObjPtrB<IVqcRunDataDao>
		(SMGDAO_MODULE, VQCRUNDATADAO_CLASSID, VQCRUNDATADAO_INTFID) { }
};

#endif 
