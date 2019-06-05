// vqcqsettingdaolib.h: implement for the CVqcQSettingDao class.
#ifndef _VQCQSETTINGDAOLIB_20130311_ZHANGPENG_H_
#define _VQCQSETTINGDAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcqsettingdao.h"// for IVqcQSettingDao

//DLL输出的接口对象引用
class CVqcQSettingDao : public CIntfObjPtrB<IVqcQSettingDao>
{
public:
	CVqcQSettingDao() : CIntfObjPtrB<IVqcQSettingDao>
		(SMGDAO_MODULE, VQCQSETTINGDAO_CLASSID, VQCQSETTINGDAO_INTFID) { }
};

#endif 
