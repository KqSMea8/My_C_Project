// transyddaolib.h: implement for the CTransydDao class.
#ifndef _TRANSYDDAOLIB_20140404_PENGSHIKANG_H_
#define _TRANSYDDAOLIB_20140404_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/itransyddao.h"   // for ITransydDao

//DLL输出的接口对象引用
class CTransydDao : public CIntfObjPtrB<ITransydDao>
{
public:
	CTransydDao() : CIntfObjPtrB<ITransydDao>
		(SCADADAO_MODULE, TRANSYDDAO_CLASSID, TRANSYDDAO_INTFID) { }
};

#endif 