// alarmtypedaolib.h: implement for the CAlmTypDao class.
#ifndef _ALARMTYPEDAOLIB_20130310_PENGSHIKANG_H_
#define _ALARMTYPEDAOLIB_20130310_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ialarmtypedao.h"    // for IAlmTypDao

//DLL输出的接口对象引用
class CAlmTypDao : public CIntfObjPtrB<IAlmTypDao>
{
public:
	CAlmTypDao() : CIntfObjPtrB<IAlmTypDao>
		(SCADADAO_MODULE, ALMTYPDAO_CLASSID, ALMTYPDAO_INTFID) { }
};

#endif 
