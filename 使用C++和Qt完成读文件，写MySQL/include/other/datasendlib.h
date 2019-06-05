// datasendlib.h: implement for the CDataSendLib class.
#ifndef _DATASENDLIB_20150518_PENGSHIKANG_H_
#define _DATASENDLIB_20150518_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/scadasrv/idatasend.h"  // for IDataSend

class IScadaDao;
class ISmgDao;
class ICheckOnlineUpdate;

class CDataSendLib : public CIntfObjPtrB<IDataSend>
{
public:
	CDataSendLib(IMSCClient* pMscClient, bool isDebug) 
		: CIntfObjPtrB<IDataSend>("datadispatch", false, DATASEND_CLASSID, DATASEND_INTFID)
	{
		void* pParams[2];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)&isDebug;
		this->m_pObj = this->CreateObject(pParams);
	}
};

#endif 