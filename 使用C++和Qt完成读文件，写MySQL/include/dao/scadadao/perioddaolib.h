// perioddaolib.h: implement for the CPeriodDao class.
#ifndef _PERIODDAOLIB_20130311_PENGSHIKANG_H_
#define _PERIODDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iperioddao.h"    // for IPeriodDao

//DLL输出的接口对象引用
class CPeriodDao : public CIntfObjPtrB<IPeriodDao>
{
public:
	CPeriodDao() : CIntfObjPtrB<IPeriodDao>
		(SCADADAO_MODULE, PERIODDAO_CLASSID, PERIODDAO_INTFID) { }
};

#endif 