// busconndaolib.h: implement for the CBusConnDao class.
#ifndef _BUSCONNDAOLIB_20130311_ZHANGPENG_H_
#define _BUSCONNDAOLIB_20130311_ZHANGPENG_H_

#include "../../commgr/intfobjptrb.h"            // for CIntfObjPtrB
#include "../../../interface/dao/smgdao/ibusconndao.h"// for IBusConnDao

class IStatusDao;
class IBusDao;

//DLL输出的接口对象引用
class CBusConnDao : public CIntfObjPtrB<IBusConnDao>
{
public:
	CBusConnDao(IStatusDao* pStatus, IBusDao* pBus) : CIntfObjPtrB<IBusConnDao>
		(SMGDAO_MODULE, BUSCONNDAO_CLASSID, BUSCONNDAO_INTFID)
	{
		void* m_pParams[2];
		m_pParams[0] = (void*)pStatus;
		m_pParams[1] = (void*)pBus;
		m_pObj = CreateObject(m_pParams);
	}
};

#endif
