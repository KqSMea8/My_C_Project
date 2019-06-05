// settingenumdaolib.h: implement for the CSettEnumDao class.
#ifndef _SETTINGENUMDAOLIB_20131224_PENGSHIKANG_H_
#define _SETTINGENUMDAOLIB_20131224_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isettingenumdao.h"    // for ISettEnumDao

//DLL输出的接口对象引用
class CSettEnumDao : public CIntfObjPtrB<ISettEnumDao>
{
public:
	CSettEnumDao() : CIntfObjPtrB<ISettEnumDao>
		(SCADADAO_MODULE, SETTINGENUMDAO_CLASSID, SETTINGENUMDAO_INTFID) { }
};

#endif 