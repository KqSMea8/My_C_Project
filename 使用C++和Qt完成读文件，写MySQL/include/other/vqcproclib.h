// vqcproclib.h: implement for the CVqcProcLib class.
#ifndef _VQCPROCLIB_20150323_PENGSHIKANG_H_
#define _VQCPROCLIB_20150323_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/smgsrv/ivqcproc.h"     // for IVqcProc

class IScadaDao;
class ISmgDao;
class IEquipCtrlMgr;

//(1)单个发电机控制管理
class CVqcProcLib : public CIntfObjPtrB<IVqcProc>
{
public:
	CVqcProcLib(IScadaDao* pScadaDao, ISmgDao* pSmgDao, IEquipCtrlMgr* pEquipCtrlor, bool (*funcCanWrite)()) 
		: CIntfObjPtrB<IVqcProc>(VOLTAGECONTROL_MODULE, false, VOLTAGECONTROL_CLASSID, VOLTAGECONTROL_INTFID)
	{
		void* pParams[4];
		pParams[0] = (void*)pScadaDao;
		pParams[1] = (void*)pSmgDao;
		pParams[2] = (void*)pEquipCtrlor;
		pParams[3] = (void*)funcCanWrite;
		this->m_pObj = this->CreateObject(pParams);
	}
};

#endif 