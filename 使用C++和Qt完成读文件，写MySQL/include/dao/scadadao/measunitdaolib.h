// measunitdaolib.h: implement for the CUnitDao class.
#ifndef _MEASUNITDAOLIB_20130311_PENGSHIKANG_H_
#define _MEASUNITDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/imeasunitdao.h"    // for IUnitDao

//DLL输出的接口对象引用
class CUnitDao : public CIntfObjPtrB<IUnitDao>
{
public:
	CUnitDao() : CIntfObjPtrB<IUnitDao>
		(SCADADAO_MODULE, MEASUNITDAO_CLASSID, MEASUNITDAO_INTFID) { }
};

#endif 