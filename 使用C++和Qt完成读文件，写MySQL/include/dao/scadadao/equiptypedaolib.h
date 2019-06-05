// equiptypedaolib.h: implement for the CEquipTypeDao class.
#ifndef _EQUIPTYPEDAOLIB_20130310_PENGSHIKANG_H_
#define _EQUIPTYPEDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iequiptypedao.h"    // for IEquipTypeDao

//DLL����Ľӿڶ�������
class CEquipTypeDao : public CIntfObjPtrB<IEquipTypeDao>
{
public:
	CEquipTypeDao() : CIntfObjPtrB<IEquipTypeDao>
		(SCADADAO_MODULE, EQUIPTYPEDAO_CLASSID, EQUIPTYPEDAO_INTFID) { }
};

#endif 
