// acurvelmtdaolib.h: implement for the CAcurveLmtDao class.
#ifndef _ACURVELMTDAOLIB_20130310_PENGSHIKANG_H_
#define _ACURVELMTDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iacurvelmtdao.h"    // for IAbruptDao

//DLL输出的接口对象引用
class CACurveLmtDao : public CIntfObjPtrB<IACurveLmtDao>
{
public:
	CACurveLmtDao() : CIntfObjPtrB<IACurveLmtDao>
		(SCADADAO_MODULE, ACURVELMTDAO_CLASSID, ACURVELMTDAO_INTFID) { }
};

#endif 
