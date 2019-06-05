// analogdaolib.h: implement for the CAnalogDao class.
#ifndef _ANALOGDAOLIB_20130311_PENGSHIKANG_H_
#define _ANALOGDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/ianalogdao.h"    // for IAnalogDao

//DLL输出的接口对象引用
class CAnalogDao : public CIntfObjPtrB<IAnalogDao>
{
public:
	CAnalogDao() : CIntfObjPtrB<IAnalogDao>
		(SCADADAO_MODULE, ANALOGDAO_CLASSID, ANALOGDAO_INTFID) { }
};

#endif 