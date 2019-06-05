// smicgriddaolib.h: implement for the CSMicgridDao class.
#ifndef _SMICGRIDDAOLIB_20130310_PENGSHIKANG_H_
#define _SMICGRIDDAOLIB_20130310_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/mgddao/ismicgriddao.h"// for ISMicgridDao

//DLL输出的接口对象引用
class CSMicgridDao : public CIntfObjPtrB<ISMicgridDao>
{
public:
	CSMicgridDao() : CIntfObjPtrB<ISMicgridDao>
		(SMGDAO_MODULE, CSMICGRIDDAO_CLASSID, CSMICGRIDDAO_INTFID) { }
};

#endif 
