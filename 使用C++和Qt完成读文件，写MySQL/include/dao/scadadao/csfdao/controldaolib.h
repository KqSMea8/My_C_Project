// controldaolib.h: implement for the CControlDao class.
#ifndef _CONTROLDAOLIB_20130311_PENGSHIKANG_H_
#define _CONTROLDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/icontroldao.h"    // for IControlDao

//DLL输出的接口对象引用
class CControlDao : public CIntfObjPtrB<IControlDao>
{
public:
	CControlDao() : CIntfObjPtrB<IControlDao>
		(SCADADAO_MODULE, CONTROLDAO_CLASSID, CONTROLDAO_INTFID) { }
};

#endif 