// exprcaldaolib.h: implement for the CExprCalDao class.
#ifndef _EXPRCALDAOLIB_20130310_PENGSHIKANG_H_
#define _EXPRCALDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iexprcaldao.h"    // for IExprCalDao

//DLL输出的接口对象引用
class CExprCalDao : public CIntfObjPtrB<IExprCalDao>
{
public:
	CExprCalDao(IExpressMap* pExprMap) : CIntfObjPtrB<IExprCalDao>
		(SCADADAO_MODULE, EXPRCALDAO_CLASSID, EXPRCALDAO_INTFID, (void**)&pExprMap) { }
};

#endif 
