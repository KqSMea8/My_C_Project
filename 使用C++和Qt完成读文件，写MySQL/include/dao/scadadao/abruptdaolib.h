// abruptdaolib.h: implement for the CAbruptDao class.
#ifndef _ABRUPTDAOLIB_20130310_PENGSHIKANG_H_
#define _ABRUPTDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iabruptdao.h"    // for IAbruptDao

//DLL输出的接口对象引用
class CAbruptDao : public CIntfObjPtrB<IAbruptDao>
{
public:
	CAbruptDao() : CIntfObjPtrB<IAbruptDao>
		(SCADADAO_MODULE, ABRUPTDAO_CLASSID, ABRUPTDAO_INTFID) { }
};

#endif 
