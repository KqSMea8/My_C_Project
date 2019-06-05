// exchcrvplandaolib.h: implement for the CExchCurvePlanDao class.
#ifndef _EXCHCURVEPLANDAOLIB_20130311_ZHANGPENG_H_
#define _EXCHCURVEPLANDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/iexchcrvplandao.h"// for IExchCurvePlanDao

//DLL输出的接口对象引用
class CExchCurvePlanDao : public CIntfObjPtrB<IExchCurvePlanDao>
{
public:
	CExchCurvePlanDao() : CIntfObjPtrB<IExchCurvePlanDao>
		(SMGDAO_MODULE, EXCHCURVEPLANDAO_CLASSID, EXCHCURVEPLANDAO_INTFID) { }
};

#endif
