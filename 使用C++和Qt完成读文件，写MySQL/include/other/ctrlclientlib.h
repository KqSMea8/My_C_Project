// ctrlclientlib.h: IControlFactory loader
#ifndef _CTRLCLIENTLIB_20080722
#define _CTRLCLIENTLIB_20080722

#include "../commgr/intfobjptrb.h"     // for CIntfObjPtrB
#include "../../interface/scadactrl/scadactrl_defines.h"
#include "../../interface/scadactrl/ctrlfactoryintf.h"
#include "../../interface/scadactrl/irawctrl.h"
#include "../../interface/imscclient.h"

//DLL输出的接口对象引用
class CCtrlClientLib : public CIntfObjPtrB<IControlFactory>
{
public:
	CCtrlClientLib() : CIntfObjPtrB<IControlFactory>
		(MODULE_SCADACTRLCLIENT, CLSID_IControlFactory, IID_IControlFactory) { }
};
	
class CRawCtrlClientLib : public CIntfObjPtrB<IRawCtrl>
{
public:
	CRawCtrlClientLib(IMSCClient* pMscClient = 0) : CIntfObjPtrB<IRawCtrl>
		(MODULE_SCADACTRLCLIENT, CLSID_IRAWCTRL, IID_IRAWCTRL)
	{ 
		void* pParams[1];
		pParams[0] = (void*)pMscClient;

		this->m_pObj = this->CreateObject(pParams);
}
};

#endif 
