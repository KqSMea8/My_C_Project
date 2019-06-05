// avcsetplandaolib.h: implement for the CAvcSetPlanDao class.
#ifndef _AVCSETPLANDAOLIB_ZHANGFEIFEI_20150821_H_
#define _AVCSETPLANDAOLIB_ZHANGFEIFEI_20150821_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/iavcsetplandao.h"// for IAvcSetPlanDao

//DLL����Ľӿڶ�������
class CAvcSetPlanDao : public CIntfObjPtrB<IAvcSetPlanDao>
{
public:
	CAvcSetPlanDao() : CIntfObjPtrB<IAvcSetPlanDao>
		(SMGDAO_MODULE, AVCSETPLANDAO_CLASSID, AVCSETPLANDAO_INTFID) { }
};

#endif 
