#ifndef _STRGSTATIONDAOLIB_20190529_WX_H_
#define _STRGSTATIONDAOLIB_20190529_WX_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/strgdao/istrgstdao.h"    // for IStrgstdao

//DLL输出的接口对象引用
class CStrgStDao : public CIntfObjPtrB<IStrgstdao>
{
public:
	CStrgStDao() : CIntfObjPtrB<IStrgstdao>
		(STRGDAO_MODULE, STRGSTDAO_CLASSID, STRGSTDAO_INTFID) { }
};

#endif 
