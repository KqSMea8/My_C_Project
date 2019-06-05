// scadaobjfactorylib.h: IScadaObjFactory loader
#ifndef _SCADAOBJFACTORYLIB_20080702
#define _SCADAOBJFACTORYLIB_20080702

#include "../commgr/intfobjptrb.h"     // for CIntfObjPtrB
#include "../../interface/scadalib/scadalib_factory.h"
#include "../../interface/scadalib/scadalib_defines.h"
//DLL输出的接口对象引用
class CScadaObjFactoryLib : public CIntfObjPtrB<IScadaObjFactory>
{
public:
	CScadaObjFactoryLib (bool bRTDBLocal)
		: CIntfObjPtrB<IScadaObjFactory>(MODULE_SCADALIB, false, CLSID_ISCADAOBJFACTORY, IID_ISCADAOBJFACTORY)
	{
		void* bPara[1];
		bPara[0] = &bRTDBLocal;
		m_pObj = CreateObject(bPara);		
	}
};
	
#endif 
