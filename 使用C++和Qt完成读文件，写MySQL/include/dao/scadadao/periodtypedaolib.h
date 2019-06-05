// periodtypedaolib.h: implement for the CPeriodTypeDao class.
#ifndef _PERIODTYPEDAOLIB_20130311_PENGSHIKANG_H_
#define _PERIODTYPEDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/iperiodtypedao.h"// for IPeriodTypeDao

//DLL输出的接口对象引用
class CPeriodTypeDao : public CIntfObjPtrB<IPeriodTypeDao>
{
public:
	CPeriodTypeDao() : CIntfObjPtrB<IPeriodTypeDao>
		(SCADADAO_MODULE, PERIODTYPEDAO_CLASSID, PERIODTYPEDAO_INTFID) { }
};

#endif 