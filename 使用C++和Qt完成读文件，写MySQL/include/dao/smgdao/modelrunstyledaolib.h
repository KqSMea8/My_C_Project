// modelrunstyledaolib.h: implement for the CModelRunStyleDao class.
#ifndef _MODELRUNSTYLEDAOLIB_20131211_PENGSHIKANG_H_
#define _MODELRUNSTYLEDAOLIB_20131211_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/imodelrunstyledao.h"// for IModelRunStyleDao

//DLL输出的接口对象引用
class CModelRunStyleDao : public CIntfObjPtrB<IModelRunStyleDao>
{
public:
	CModelRunStyleDao() : CIntfObjPtrB<IModelRunStyleDao>
		(SMGDAO_MODULE, MODELRUNSTYLEDAO_CLASSID, MODELRUNSTYLEDAO_INTFID) { }
};

#endif 
