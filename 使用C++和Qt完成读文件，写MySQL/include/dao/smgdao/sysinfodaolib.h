// sysinfodaolib.h: implement for the CSysInfoDao class.
#ifndef _SYSINFODAOLIB_20130311_ZHANGPENG_H_
#define _SYSINFODAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/isysinfodao.h"// for ISysInfoDao

//DLL����Ľӿڶ�������
class CSysInfoDao : public CIntfObjPtrB<ISysInfoDao>
{
public:
	CSysInfoDao() : CIntfObjPtrB<ISysInfoDao>
		(SMGDAO_MODULE, SYSINFODAO_CLASSID, SYSINFODAO_INTFID) { }
};

#endif
