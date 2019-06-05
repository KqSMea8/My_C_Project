// equipmentdaolib.h: implement for the CEquipDao class.
#ifndef _EQUIPMENTDAOLIB_20130310_PENGSHIKANG_H_
#define _EQUIPMENTDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iequipmentdao.h"    // for IEquipDao

//DLL输出的接口对象引用
class CEquipDao : public CIntfObjPtrB<IEquipDao>
{
public:
	CEquipDao() : CIntfObjPtrB<IEquipDao>
		(SCADADAO_MODULE, EQUIPDAO_CLASSID, EQUIPDAO_INTFID) { }
};

#endif 
