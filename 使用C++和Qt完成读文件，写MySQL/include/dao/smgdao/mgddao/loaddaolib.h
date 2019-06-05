// loaddaolib.h: implement for the CLoadDao class.
#ifndef _LOADDAOLIB_20130310_PENGSHIKANG_H_
#define _LOADDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/iloaddao.h"// for ILoadDao

//DLL输出的接口对象引用
class CLoadDao : public CIntfObjPtrB<ILoadDao>
{
public:
	CLoadDao() : CIntfObjPtrB<ILoadDao>
		(SMGDAO_MODULE, LOADDAO_CLASSID, LOADDAO_INTFID) { }
};

#endif 
