// statusvaldaolib.h: implement for the CStatusValDao class.
#ifndef _STATUSVALDAOLIB_20130311_PENGSHIKANG_H_
#define _STATUSVALDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/istatusvaldao.h"    // for IStatusValDao

//DLL输出的接口对象引用
class CStatusValDao : public CIntfObjPtrB<IStatusValDao>
{
public:
	CStatusValDao() : CIntfObjPtrB<IStatusValDao>
		(SCADADAO_MODULE, STATUSVALDAO_CLASSID, STATUSVALDAO_INTFID) { }
};

#endif 