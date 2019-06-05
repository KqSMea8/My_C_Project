// anlgprdlmtdaolib.h: implement for the CAPrdLmtDao class.
#ifndef _ANALOGPEROIDLIMITDAOLIB_20130310_PENGSHIKANG_H_
#define _ANALOGPEROIDLIMITDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ianlgprdlmtdao.h"    // for IAPrdLmtDao

//DLL输出的接口对象引用
class CAPrdLmtDao : public CIntfObjPtrB<IAPrdLmtDao>
{
public:
	CAPrdLmtDao() : CIntfObjPtrB<IAPrdLmtDao>
		(SCADADAO_MODULE, APRDLMTDAO_CLASSID, APRDLMTDAO_INTFID) { }
};

#endif 
