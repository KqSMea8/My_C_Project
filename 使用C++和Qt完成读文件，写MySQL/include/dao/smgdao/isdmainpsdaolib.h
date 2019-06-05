// isdmainpsdaolib.h: implement for the CIsdmainpsDao class.
#ifndef _ISDMAINPSDAOLIB_20130311_ZHANGPENG_H_
#define _ISDMAINPSDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/iisdmainpsdao.h"// for IIsdmainpsDao

//DLL����Ľӿڶ�������
class CIsdmainpsDao : public CIntfObjPtrB<IIsdmainpsDao>
{
public:
	CIsdmainpsDao() : CIntfObjPtrB<IIsdmainpsDao>
		(SMGDAO_MODULE, ISDMAINPSDAO_CLASSID, ISDMAINPSDAO_INTFID) { }
};

#endif
