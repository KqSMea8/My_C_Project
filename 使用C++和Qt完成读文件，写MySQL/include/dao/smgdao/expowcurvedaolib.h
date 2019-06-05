// expowcurvedaolib.h: implement for the CExPowCurveDao class.
#ifndef _EXPOWCURVEDAOLIB_20130311_ZHANGPENG_H_
#define _EXPOWCURVEDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/iexpowcurvedao.h"// for IExPowCurveDao

//DLL输出的接口对象引用
class CExPowCurveDao : public CIntfObjPtrB<IExPowCurveDao>
{
public:
	CExPowCurveDao() : CIntfObjPtrB<IExPowCurveDao>
		(SMGDAO_MODULE, EXPOWCURVEDAO_CLASSID, EXPOWCURVEDAO_INTFID) { }
};

#endif
