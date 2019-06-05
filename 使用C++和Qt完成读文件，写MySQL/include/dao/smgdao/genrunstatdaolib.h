// genrunstatdaolib.h: implement for the CGenRunStatDao class.
#ifndef _GENRUNSTATISTICSDAOLIB_20150720_PENGSHIKANG_H_
#define _GENRUNSTATISTICSDAOLIB_20150720_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/igeneratorstatdao.h"// for IGeneratorStatDao

//DLL输出的接口对象引用
class CGenRunStatDao : public CIntfObjPtrB<IGeneratorStatDao>
{
public:
	CGenRunStatDao() : CIntfObjPtrB<IGeneratorStatDao>
		(SMGDAO_MODULE, GENERATORSTATDAO_CLASSID, GENERATORSTATDAO_INTFID) { }
};

#endif
