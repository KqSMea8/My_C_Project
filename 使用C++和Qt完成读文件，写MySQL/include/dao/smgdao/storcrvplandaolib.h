// storcrvplandaolib.h: implement for the CStorCurvePlanDao class.
#ifndef _STORCRVPLANDAOLIB_20130311_ZHANGPENG_H_
#define _STORCRVPLANDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/istorcrvplandao.h"// for IStorCurvePlanDao

//DLL输出的接口对象引用
class CStorCurvePlanDao : public CIntfObjPtrB<IStorCurvePlanDao>
{
public:
	CStorCurvePlanDao() : CIntfObjPtrB<IStorCurvePlanDao>
		(SMGDAO_MODULE, STORCURVEPLANDAO_CLASSID, STORCURVEPLANDAO_INTFID) { }
};

#endif
