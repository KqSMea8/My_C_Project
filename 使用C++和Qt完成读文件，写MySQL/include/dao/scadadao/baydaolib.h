// baydaolib.h: implement for the CBayDao class.
#ifndef _BAYDAOLIB_20130310_PENGSHIKANG_H_
#define _BAYDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ibaydao.h"    // for IBayDao

//DLL输出的接口对象引用
class CBayDao : public CIntfObjPtrB<IBayDao>
{
public:
	CBayDao() : CIntfObjPtrB<IBayDao>
		(SCADADAO_MODULE, BAYDAO_CLASSID, BAYDAO_INTFID) { }
};

#endif 
