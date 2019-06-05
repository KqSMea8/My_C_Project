// datareceivelib.h: implement for the CDataReceiveLib class.
#ifndef _DATARECEIVELIB_20150518_PENGSHIKANG_H_
#define _DATARECEIVELIB_20150518_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/scadasrv/idatareceive.h"// for IDataReceive

class IScadaDao;
class ISmgDao;
class ICheckOnlineUpdate;
class IActionAlarm;

class CDataReceiveLib : public CIntfObjPtrB<IDataReceive>
{
public:
	CDataReceiveLib(IScadaDao* pScadaDao, ISmgDao* pSmgDao, ICheckOnlineUpdate* pCheckOnline, IActionAlarm* pActionAlarm) 
		: CIntfObjPtrB<IDataReceive>("datadispatch", false, DATARECEIVE_CLASSID, DATARECEIVE_INTFID)
	{
		void* pParams[4];
		pParams[0] = (void*)pScadaDao;
		pParams[1] = (void*)pSmgDao;
		pParams[2] = (void*)pCheckOnline;
		pParams[3] = (void*)pActionAlarm;
		this->m_pObj = this->CreateObject(pParams);
	}
};

#endif 