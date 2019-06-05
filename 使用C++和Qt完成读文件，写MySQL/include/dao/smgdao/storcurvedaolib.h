// storcurvedaolib.h: implement for the CStorCurveDao class.
#ifndef _STORCURVEDAOLIB_20130311_ZHANGPENG_H_
#define _STORCURVEDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/istorcurvedao.h"// for IStorCurveDao

//DLL输出的接口对象引用
class CStorCurveDao : public CIntfObjPtrB<IStorCurveDao>
{
public:
	CStorCurveDao() : CIntfObjPtrB<IStorCurveDao>
		(SMGDAO_MODULE, STORCURVEDAO_CLASSID, STORCURVEDAO_INTFID) { }
};

#endif
