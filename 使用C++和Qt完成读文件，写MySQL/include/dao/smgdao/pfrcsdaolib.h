// pfrcsdaolib.h: implement for the CPForcastDao class.
#ifndef _PFORCASTDAOLIB_SUNRUI_20130528_H_
#define _PFORCASTDAOLIB_SUNRUI_20130528_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ipfrcsdao.h"// for IPForcastDao

//DLL输出的接口对象引用
class CPForcastDao : public CIntfObjPtrB<IPForcastDao>
{
public:
	CPForcastDao() : CIntfObjPtrB<IPForcastDao>
		(SMGDAO_MODULE, PFORCASTDAO_CLASSID, PFORCASTDAO_INTFID) { }
};

#endif 
