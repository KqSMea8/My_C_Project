// timertypedaolib.h: implement for the CTimerTypeDao class.
#ifndef _TIMERTYPEDAOLIB_20130311_PENGSHIKANG_H_
#define _TIMERTYPEDAOLIB_20130311_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/itimertypedao.h"    // for ITimerTypeDao

//DLL输出的接口对象引用
class CTimerTypeDao : public CIntfObjPtrB<ITimerTypeDao>
{
public:
	CTimerTypeDao() : CIntfObjPtrB<ITimerTypeDao>
		(SCADADAO_MODULE, TIMERTYPEDAO_CLASSID, TIMERTYPEDAO_INTFID) { }
};

#endif 