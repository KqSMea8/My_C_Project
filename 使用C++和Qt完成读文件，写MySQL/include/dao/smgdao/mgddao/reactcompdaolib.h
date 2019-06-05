// reactcompdaolib.h: implement for the CReactCompDao class.
#ifndef _REACTIVECOMPOMENTDAOLIB_20130310_PENGSHIKANG_H_
#define _REACTIVECOMPOMENTDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/ireactcompdao.h"// for IReactCompDao

//DLL输出的接口对象引用
class CReactCompDao : public CIntfObjPtrB<IReactCompDao>
{
public:
	CReactCompDao() : CIntfObjPtrB<IReactCompDao>
		(SMGDAO_MODULE, REACTIVECOMPOMENTDAO_CLASSID, REACTIVECOMPOMENTDAO_INTFID) { }
};

#endif 
