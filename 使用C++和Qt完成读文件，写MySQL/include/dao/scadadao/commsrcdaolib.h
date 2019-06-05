// commsrcdaolib.h: implement for the CCommSrcDao class.
#ifndef _COMMSRCDAOLIB_20130310_PENGSHIKANG_H_
#define _COMMSRCDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/icommsrcdao.h"    // for ICommSrcDao

//DLL输出的接口对象引用
class CCommSrcDao : public CIntfObjPtrB<ICommSrcDao>
{
public:
	CCommSrcDao() : CIntfObjPtrB<ICommSrcDao>
		(SCADADAO_MODULE, COMMSRCDAO_CLASSID, COMMSRCDAO_INTFID) { }
};

#endif 
