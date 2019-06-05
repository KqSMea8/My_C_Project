// batstationdaolib.h: implement for the CBatStatiobDao class.
#ifndef _BATSTATIONDAOLIB_20180708_PENGSHIKANG_H_
#define _BATSTATIONDAOLIB_20180708_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ibatstationdao.h"// for IBatStationDao

//DLL输出的接口对象引用
class CBatStatiobDao : public CIntfObjPtrB<IBatStationDao>
{
public:
	CBatStatiobDao() : CIntfObjPtrB<IBatStationDao>
		(SMGDAO_MODULE, BATSTATIONDAO_CLASSID, BATSTATIONDAO_INTFID) { }
};

#endif
