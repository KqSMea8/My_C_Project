// statusdaolib.h: implement for the CStatusDao class.
#ifndef _STATUSDAOLIB_20130311_PENGSHIKANG_H_
#define _STATUSDAOLIB_20130311_PENGSHIKANG_H_

#include "../../../commgr/intfobjptrb.h"       // for CIntfObjPtrB
#include "../../../../interface/dao/scadadao/csfdao/istatusdao.h"    // for IStatusDao

class IStatusValDao;

//DLL输出的接口对象引用
class CStatusDao : public CIntfObjPtrB<IStatusDao>
{
public:
	CStatusDao(IStatusValDao* pStatusVal) : CIntfObjPtrB<IStatusDao>
		(SCADADAO_MODULE, STATUSDAO_CLASSID, STATUSDAO_INTFID, (void**)&pStatusVal) { }
};

#endif 