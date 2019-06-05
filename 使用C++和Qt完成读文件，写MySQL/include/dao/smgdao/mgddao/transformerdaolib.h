// transformerdaolib.h: implement for the CTransformerDao class.
#ifndef _TRANSFORMERDAOLIB_20130310_PENGSHIKANG_H_
#define _TRANSFORMERDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/itransformerdao.h"// for ITransformerDao

//DLL输出的接口对象引用
class CTransformerDao : public CIntfObjPtrB<ITransformerDao>
{
public:
	CTransformerDao() : CIntfObjPtrB<ITransformerDao>
		(SMGDAO_MODULE, TRANSFORMERDAO_CLASSID, TRANSFORMERDAO_INTFID) { }
};

#endif 
