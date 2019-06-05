// bussclmncfgdaolib.h: implement for the CBussClmnCfgDao class.
#ifndef _BUSSCLMNCFGDAOLIB_PENGSHIKANG_20160503_H_
#define _BUSSCLMNCFGDAOLIB_PENGSHIKANG_20160503_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ibussclmncfgdao.h"// for IBussClmnCfgDao

//DLL输出的接口对象引用
class CBussClmnCfgDao : public CIntfObjPtrB<IBussClmnCfgDao>
{
public:
	CBussClmnCfgDao() : CIntfObjPtrB<IBussClmnCfgDao>
		(SMGDAO_MODULE, BUSSCLMNCFGDAO_CLASSID, BUSSCLMNCFGDAO_INTFID) { }
};

#endif 
