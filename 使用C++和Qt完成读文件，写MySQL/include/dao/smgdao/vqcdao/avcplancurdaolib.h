// avcplancurdaolib.h: implement for the CAvcPlanCurDao class.
#ifndef _AVCPLANCURDAOLIB_ZHANGFEIFEI_20150821_H_
#define _AVCPLANCURDAOLIB_ZHANGFEIFEI_20150821_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/iavcplancurdao.h"// for IAvcPlanCurDao

//DLL输出的接口对象引用
class CAvcPlanCurDao : public CIntfObjPtrB<IAvcPlanCurDao>
{
public:
	CAvcPlanCurDao() : CIntfObjPtrB<IAvcPlanCurDao>
		(SMGDAO_MODULE, AVCPLANCURDAO_CLASSID, AVCPLANCURDAO_INTFID) { }
};

#endif 
