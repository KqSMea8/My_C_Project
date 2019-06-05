// equipctrllib.h: implement for the CMultSrcDao class.
#ifndef _MULTSRCDAOLIB_20130311_PENGSHIKANG_H_
#define _MULTSRCDAOLIB_20130311_PENGSHIKANG_H_

#define EQUIPCONTROL_MODULE      "equipctrl"

#include "../commgr/intfobjptrb.h"               // for CIntfObjPtrB
#include "../../interface/smgsrv/iageneratormgr.h"// for IAGeneratorMgr
#include "../../interface/smgsrv/igeneratormgr.h"// for IGeneratorMgr
#include "../../interface/smgsrv/istoragemgr.h"  // for IStorageMgr
#include "../../interface/smgsrv/iastoragemgr.h" // for IAStorageMgr
#include "../../interface/smgsrv/iloadmgr.h"     // for ILoadMgr
#include "../../interface/smgsrv/ireactcompmgr.h"// for IReactCompMgr
#include "../../interface/smgsrv/itransformermgr.h"// for ITransformerMgr
#include "../../interface/smgsrv/igroupctrlmgr.h" // for IGroupCtrlMgr

class IMSCClient;
class IActionAlarm;
class IAutoCtrl;
class IScadaDao;
class ISmgDao;

//(1)单个发电机控制管理
class CAGeneratorMgr : public CIntfObjPtrB<IAGeneratorMgr>
{
public:
	CAGeneratorMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl, bool (*funcCanWrite)()) 
		: CIntfObjPtrB<IAGeneratorMgr>(EQUIPCONTROL_MODULE, false, AGENERATORMANAGER_CLASSID, AGENERATORMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = (void*)funcCanWrite;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(2)一组发电机控制管理
class CGeneratorMgr : public CIntfObjPtrB<IGeneratorMgr>
{
public:
	CGeneratorMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl, bool (*funcCanWrite)(), bool (*funcIsWGener)(int)) 
		: CIntfObjPtrB<IGeneratorMgr>(EQUIPCONTROL_MODULE, false, GENERATORMANAGER_CLASSID, GENERATORMANAGER_INTFID)
	{
		void* pParams[8];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = (void*)funcCanWrite;
		pParams[6] = (void*)funcIsWGener;
		pParams[7] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(3)单个储能装置控制管理
class CAStorageMgr : public CIntfObjPtrB<IAStorageMgr>
{
public:
	CAStorageMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl) 
		: CIntfObjPtrB<IAStorageMgr>(EQUIPCONTROL_MODULE, false, ASTORAGEMANAGER_CLASSID, ASTORAGEMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(4)一组储能装置控制管理
class CStorageMgr : public CIntfObjPtrB<IStorageMgr>
{
public:
	CStorageMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl) 
		: CIntfObjPtrB<IStorageMgr>(EQUIPCONTROL_MODULE, false, STORAGEMANAGER_CLASSID, STORAGEMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(5)一组负载设备控制管理
class CLoadMgr : public CIntfObjPtrB<ILoadMgr>
{
public:
	CLoadMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl, bool (*funcCanWrite)()) 
		: CIntfObjPtrB<ILoadMgr>(EQUIPCONTROL_MODULE, false, LOADMANAGER_CLASSID, LOADMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = (void*)funcCanWrite;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(6)一组无功补偿装置控制管理
class CReactCompMgr : public CIntfObjPtrB<IReactCompMgr>
{
public:
	CReactCompMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl) 
		: CIntfObjPtrB<IReactCompMgr>(EQUIPCONTROL_MODULE, false, REACTCOMPMANAGER_CLASSID, REACTCOMPMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(7)一组变压器控制管理
class CTransformerMgr : public CIntfObjPtrB<ITransformerMgr>
{
public:
	CTransformerMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, IScadaDao* pScadaDao, ISmgDao* pSmgDao, IAutoCtrl* pAutoCtrl) 
		: CIntfObjPtrB<ITransformerMgr>(EQUIPCONTROL_MODULE, false, TRANSFORMERMANAGER_CLASSID, TRANSFORMERMANAGER_INTFID)
	{
		void* pParams[6];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = (void*)pScadaDao;
		pParams[4] = (void*)pAutoCtrl;
		pParams[5] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};

//(8)一组同类的设备同时进行控制的管理
class CGroupCtrlMgr : public CIntfObjPtrB<IGroupCtrlMgr>
{
public:
	CGroupCtrlMgr(IMSCClient* pMscClient, IActionAlarm* pAlarm, ISmgDao* pSmgDao) 
		: CIntfObjPtrB<IGroupCtrlMgr>(EQUIPCONTROL_MODULE, false, GROUPCTRLMANAGER_CLASSID, GROUPCTRLMANAGER_INTFID)
	{
		void* pParams[4];
		pParams[0] = (void*)pMscClient;
		pParams[1] = (void*)pAlarm;
		pParams[2] = (void*)pSmgDao;
		pParams[3] = 0;
		this->m_pObj = this->CreateObject(pParams);
	}
};


#endif 