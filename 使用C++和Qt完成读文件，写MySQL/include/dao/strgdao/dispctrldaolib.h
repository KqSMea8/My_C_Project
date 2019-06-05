#ifndef _DISPCTRLDAOLIB_20190529_WX_H_
#define _DISPCTRLDAOLIB_20190529_WX_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/strgdao/idispctrldao.h"    // for IStrgstdao

//DLL输出的接口对象引用
class CDisctrlDao : public CIntfObjPtrB<IDispctrldao>
{
public:
	CDisctrlDao() : CIntfObjPtrB<IDispctrldao>
		(STRGDAO_MODULE, DISPCTRLDAO_CLASSID, DISPCTRLDAO_INTFID) { }
};

#endif 
