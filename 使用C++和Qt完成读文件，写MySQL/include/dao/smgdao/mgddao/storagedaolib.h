// storagedaolib.h: implement for the CStorageDao class.
#ifndef _STORAGEDAOLIB_20130310_PENGSHIKANG_H_
#define _STORAGEDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/istoragedao.h"// for IStorageDao

//DLL输出的接口对象引用
class CStorageDao : public CIntfObjPtrB<IStorageDao>
{
public:
	CStorageDao() : CIntfObjPtrB<IStorageDao>
		(SMGDAO_MODULE, STORAGEDAO_CLASSID, STORAGEDAO_INTFID) { }
};

#endif 
