// micgridstatdaolib.h: implement for the CMicgridStatDao class.
#ifndef _MICGRIDSTATISTICSDAOLIB_20160926_PENGSHIKANG_H_
#define _MICGRIDSTATISTICSDAOLIB_20160926_PENGSHIKANG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/imicgridstatdao.h" // for IMicgridStatDao

//DLL输出的接口对象引用
class CMicgridStatDao : public CIntfObjPtrB<IMicgridStatDao>
{
public:
	CMicgridStatDao() : CIntfObjPtrB<IMicgridStatDao>
		(SMGDAO_MODULE, CMICGRIDSTATDAO_CLASSID, CMICGRIDSTATDAO_INTFID) { }
};

#endif 
