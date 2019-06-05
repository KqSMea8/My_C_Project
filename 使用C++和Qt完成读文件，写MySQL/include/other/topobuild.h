// topobuild.h: interface for the g_MakeGuidDll、CMakeGuid class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _TOPOMODELBUILD_H_2008_09_28_PENGSHIKANG_INCLUDED_
#define _TOPOMODELBUILD_H_2008_09_28_PENGSHIKANG_INCLUDED_

#include "../../interface/itopomodel.h"  // for IBulidTopoModel
#include "../commgr/intfobjptrb.h"       // for CIntfObjPtrB<IntfObj>
#include "../basiclib/dbaccesslib.h"
//#include "icssettingslib.h"            // for CICSSettings

class IDALibrary;

class CTopoBuild : public CIntfObjPtrB<IBulidTopoModel>
{
public:
	CTopoBuild(DBCONFIG* pDbInfo=0, const char* miscParams=0, const char* portParams=0) 
		: CIntfObjPtrB<IBulidTopoModel>(DLL_TOPOMODELBUILD)
	{
		if(pDbInfo == 0)
		{
			//CICSSettings sets;
			//IICSSettings* pSets = sets.Self();
			//pSets->ItemReadString("plat_global/database/rtdb/schema/dbname", m_dbInfo.librName, 32);
			//pSets->ItemReadString("plat_global/database/rtdb/schema/username", m_dbInfo.userName, 32);
			//pSets->ItemReadString("plat_global/database/rtdb/schema/password", m_dbInfo.password, 32);
			m_dbInfo.libType = LT_ORACLE;
			strcpy(m_dbInfo.librName, "orcl17");
			strcpy(m_dbInfo.userName, "cbz8601");
			strcpy(m_dbInfo.password, "cbz8601");
			strcpy(m_dbInfo.hostAddr, "");
		}
		else
		{
			m_dbInfo = *pDbInfo;
		}
		if(miscParams) strcpy(m_miscParams, miscParams);
		else strcpy(m_miscParams, "");
		if(portParams) strcpy(m_portParams, portParams);
		else strcpy(m_portParams, "");
		this->m_pObj = CreateBulidTopoModel(&m_dbInfo, m_miscParams, m_portParams);
	}

	//创建一个新的接口对象
	IBulidTopoModel* CreateBulidTopoModel(DBCONFIG* pDbInfo=0, char* miscParams=0, char* portParams=0)
	{
		void* pParams[3];
		if(pDbInfo == 0)
		{
			pParams[0] = (void*)&m_dbInfo;
			pParams[1] = (void*)m_miscParams;
			pParams[2] = (void*)m_portParams;
		}
		else
		{
			pParams[0] = (void*)pDbInfo;
			pParams[1] = (void*)miscParams;
			pParams[2] = (void*)portParams;
		}
		return (IBulidTopoModel*)CreateObject(CID_TOPOMODELBUILD, IID_TOPOMODELBUILD, pParams);
	}

private:
	DBCONFIG m_dbInfo;
	char m_miscParams[64], m_portParams[64];

};

#endif
