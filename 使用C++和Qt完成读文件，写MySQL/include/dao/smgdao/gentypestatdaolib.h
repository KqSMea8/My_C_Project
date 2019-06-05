// gentypestatdaolib.h: implement for the CGenTypeStatDao class.
#ifndef _GENTYPESTATDAOLIB_20130311_ZHANGPENG_H_
#define _GENTYPESTATDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/igentypestatdao.h"// for IGenStatDao

//DLL输出的接口对象引用
class CGenTypeStatDao : public CIntfObjPtrB<IGenStatDao>
{
public:
	CGenTypeStatDao() : CIntfObjPtrB<IGenStatDao>
		(SMGDAO_MODULE, GENSTATDAO_CLASSID, GENSTATDAO_INTFID) { }
};

#endif
