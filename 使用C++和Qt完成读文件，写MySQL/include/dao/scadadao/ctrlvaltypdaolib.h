// ctrlvaltypdaolib.h: implement for the CCtrlValTypDao class.
#ifndef _CTRLVALTYPDAOLIB_20130310_PENGSHIKANG_H_
#define _CTRLVALTYPDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ictrlvaltypdao.h"    // for ICtrlValTypDao

//DLL输出的接口对象引用
class CCtrlValTypDao : public CIntfObjPtrB<ICtrlValTypDao>
{
public:
	CCtrlValTypDao() : CIntfObjPtrB<ICtrlValTypDao>
		(SCADADAO_MODULE, CTRLVALTYPDAO_CLASSID, CTRLVALTYPDAO_INTFID) { }
};

#endif 
