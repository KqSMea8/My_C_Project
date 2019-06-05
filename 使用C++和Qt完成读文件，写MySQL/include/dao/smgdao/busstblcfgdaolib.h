// busstblcfgdaolib.h: implement for the CBussTblCfgDao class.
#ifndef _BUSSTBLCFGDAOLIB_PENGSHIKANG_20160503_H_
#define _BUSSTBLCFGDAOLIB_PENGSHIKANG_20160503_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ibusstblcfgdao.h"// for IBussTblCfgDao

class IBussClmnCfgDao;

//DLL输出的接口对象引用
class CBussTblCfgDao : public CIntfObjPtrB<IBussTblCfgDao>
{
public:
	CBussTblCfgDao(IBussClmnCfgDao* pBussClmnCfgDao) : CIntfObjPtrB<IBussTblCfgDao>
		(SMGDAO_MODULE, BUSSTBLCFGDAO_CLASSID, BUSSTBLCFGDAO_INTFID, (void**)&pBussClmnCfgDao) { }
};

#endif 
