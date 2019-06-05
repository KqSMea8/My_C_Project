// bayareadaolib.h: implement for the CBayAreaDao class.
#ifndef _BAYAREADAOLIB_20140120_PENGSHIKANG_H_
#define _BAYAREADAOLIB_20140120_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/scadadao/ibayareadao.h"   // for IBayAreaDao

//DLL输出的接口对象引用
class CBayAreaDao : public CIntfObjPtrB<IBayAreaDao>
{
public:
	CBayAreaDao() : CIntfObjPtrB<IBayAreaDao>
		(SCADADAO_MODULE, BAYAREADAO_CLASSID, BAYAREADAO_INTFID) { }
};

#endif 
