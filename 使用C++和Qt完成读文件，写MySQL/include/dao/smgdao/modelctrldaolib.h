// modelctrldaolib.h: implement for the CModelCtrlDao class.
#ifndef _MODELCTRLDAOLIB_20131211_PENGSHIKANG_H_
#define _MODELCTRLDAOLIB_20131211_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/imodelctrldao.h"// for IModelCtrlDao

//DLL输出的接口对象引用
class CModelCtrlDao : public CIntfObjPtrB<IModelCtrlDao>
{
public:
	CModelCtrlDao() : CIntfObjPtrB<IModelCtrlDao>
		(SMGDAO_MODULE, MODELCTRLDAO_CLASSID, MODELCTRLDAO_INTFID) { }
};

#endif 
