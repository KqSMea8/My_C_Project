// vqcsettingdaolib.h: implement for the CVqcSettingDao class.
#ifndef _VQCSETTINGDAOLIB_20130311_ZHANGPENG_H_
#define _VQCSETTINGDAOLIB_20130311_ZHANGPENG_H_

#include "../../../commgr/intfobjptrb.h"         // for CIntfObjPtrB
#include "../../../../interface/dao/smgdao/vqcdao/ivqcsettingdao.h"// for IVqcSettingDao

//DLL输出的接口对象引用
class CVqcSettingDao : public CIntfObjPtrB<IVqcSettingDao>
{
public:
	CVqcSettingDao() : CIntfObjPtrB<IVqcSettingDao>
		(SMGDAO_MODULE, VQCSETTINGDAO_CLASSID, VQCSETTINGDAO_INTFID) { }
};

#endif 
