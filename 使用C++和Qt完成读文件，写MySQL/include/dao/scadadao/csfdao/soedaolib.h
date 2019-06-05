// soelib.h: implement for the CSoeDao class.
#ifndef _SOEDAOLIB_20130311_PENGSHIKANG_H_
#define _SOEDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/isoedao.h"    // for ISoeDao

//DLL输出的接口对象引用
class CSoeDao : public CIntfObjPtrB<ISoeDao>
{
public:
	CSoeDao() : CIntfObjPtrB<ISoeDao>
		(SCADADAO_MODULE, SOEDAO_CLASSID, SOEDAO_INTFID) { }
};

#endif 