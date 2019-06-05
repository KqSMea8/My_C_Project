// soevaldaolib.h: implement for the CSoeValDao class.
#ifndef _SOEVALDAOLIB_20130311_PENGSHIKANG_H_
#define _SOEVALDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/isoevaldao.h"    // for ISoeValDao

//DLL输出的接口对象引用
class CSoeValDao : public CIntfObjPtrB<ISoeValDao>
{
public:
	CSoeValDao() : CIntfObjPtrB<ISoeValDao>
		(SCADADAO_MODULE, SOEVALDAO_CLASSID, SOEVALDAO_INTFID) { }
};

#endif 