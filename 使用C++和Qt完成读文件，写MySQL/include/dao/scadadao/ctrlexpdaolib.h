// ctrlexpdaolib.h: implement for the CCtrlExpDao class.
#ifndef _CTRLEXPDAOLIB_20130310_PENGSHIKANG_H_
#define _CTRLEXPDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ictrlexpdao.h"    // for ICtrlExpDao

//DLL输出的接口对象引用
class CCtrlExpDao : public CIntfObjPtrB<ICtrlExpDao>
{
public:
	CCtrlExpDao() : CIntfObjPtrB<ICtrlExpDao>
		(SCADADAO_MODULE, CTRLEXPDAO_CLASSID, CTRLEXPDAO_INTFID) { }
};

#endif 
