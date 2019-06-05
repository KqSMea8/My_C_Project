// accumudaolib.h: implement for the CAccumuDao class.
#ifndef _ACCUMUDAOLIB_20130311_PENGSHIKANG_H_
#define _ACCUMUDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/iaccumudao.h"    // for IAccumuDao

//DLL输出的接口对象引用
class CAccumuDao : public CIntfObjPtrB<IAccumuDao>
{
public:
	CAccumuDao() : CIntfObjPtrB<IAccumuDao>
		(SCADADAO_MODULE, ACCUMUDAO_CLASSID, ACCUMUDAO_INTFID) { }
};

#endif 