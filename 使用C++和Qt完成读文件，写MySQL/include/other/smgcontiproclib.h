// smgcontiproclib.h: implement for the CSmgContiProcLib class.
#ifndef _SMGONTINENTPROCESSLIB_20150410_PENGSHIKANG_H_
#define _SMGONTINENTPROCESSLIB_20150410_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/smgsrv/icontrolstrategy.h"// for IControlStrategy

class IScadaDao;
class ISmgDao;
class IEquipCtrlMgr;

//(1)单个发电机控制管理
class CSmgContiProcLib : public CIntfObjPtrB<IControlStrategy>
{
public:
	CSmgContiProcLib(IScadaDao* pScadaDao, ISmgDao* pSmgDao, IEquipCtrlMgr* pEquipCtrlor, bool (*funcCanWrite)()) 
		: CIntfObjPtrB<IControlStrategy>(SMGCONTINENTPROCESS_MODULE, false, SMGCONTINENTPROCESS_CLASSID, SMGCONTINENTPROCESS_INTFID)
	{
		void* pParams[4];
		memset(pParams, 0, sizeof(pParams));
		pParams[0] = (void*)pScadaDao;
		pParams[1] = (void*)pSmgDao;
		pParams[2] = (void*)pEquipCtrlor;
		pParams[3] = (void*)funcCanWrite;
		this->m_pObj = this->CreateObject(pParams);
	}
};

#endif 