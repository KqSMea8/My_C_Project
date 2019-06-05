// busdaolib.h: implement for the CBusDao class.
#ifndef _BUSDAOLIB_20130310_PENGSHIKANG_H_
#define _BUSDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/ibusdao.h"// for IBusDao

//DLL输出的接口对象引用
class CBusDao : public CIntfObjPtrB<IBusDao>
{
public:
	CBusDao() : CIntfObjPtrB<IBusDao>
		(SMGDAO_MODULE, BUSDAO_CLASSID, BUSDAO_INTFID) { }
};

#endif 
