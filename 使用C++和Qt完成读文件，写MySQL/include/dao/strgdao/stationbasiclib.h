#ifndef _STATIONBASICDAOLIB_20190529_WX_H_
#define _STATIONBASICDAOLIB_20190529_WX_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/strgdao/istbasicdao.h"    // for IStbasicdao

//DLL输出的接口对象引用
class CStbasicDao : public CIntfObjPtrB<IStbasicdao>
{
public:
	CStbasicDao() : CIntfObjPtrB<IStbasicdao>
		(STRGDAO_MODULE, STBASICDAO_CLASSID, STBASICDAO_INTFID) { }
};

#endif 
