// generatordaolib.h: implement for the CGeneratorDao class.
#ifndef _GENERATORDAOLIB_20130310_PENGSHIKANG_H_
#define _GENERATORDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/igeneratordao.h"// for IGeneratorDao

//DLL输出的接口对象引用
class CGeneratorDao : public CIntfObjPtrB<IGeneratorDao>
{
public:
	CGeneratorDao() : CIntfObjPtrB<IGeneratorDao>
		(SMGDAO_MODULE, GENERATORDAO_CLASSID, GENERATORDAO_INTFID) { }
};

#endif 
