// dbaccesslib.h: implement for the CTaskIndexLib class.
#ifndef _DBACCESSLIB_2008_06_16_PENGSHIKANG_HH_
#define _DBACCESSLIB_2008_06_16_PENGSHIKANG_HH_

#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB
#include "../../interface/ibufftable.h" // for IGaiaObject、IGaiaTable
#include "../other/icssettingslib.h"    // for CICSSettings

//by zxp 20120919 增加当前运行态的处理
#include "currentcontext.h"
#include <QLibrary>

//end by zxp

class CDALibrary : public CIntfObjPtrB<IDALibrary>
{
public:
	CDALibrary(bool bNeedInit=false) : CIntfObjPtrB<IDALibrary>(
		MODULE_DBACCESS, bNeedInit, CLSID_DALibrary, IID_IDALibrary) { }

	CDALibrary(const DBCONFIG* pDbInfo, const char* procName=0) : CIntfObjPtrB<IDALibrary>(
		MODULE_DBACCESS, procName!=0, CLSID_DALibrary, IID_IDALibrary) 
	{
		this->m_pObj = CreateDALibrary(pDbInfo, procName);
	}
	
	//根据数据库配置信息创建一个新的接口对象
	IDALibrary* CreateDALibrary(const DBCONFIG* pDbInfo, const char* procName=0)
	{
		void* pParams[2];
		pParams[0] = (void*)pDbInfo;     //客户端模块标识
		pParams[1] = (void*)procName;       //用户指针
		return CreateObject(pParams);
	}
	
};

class CGaiaLibrary : public CIntfObjPtrB<IGaiaLibrary>
{
private:
public:
	CGaiaLibrary(const char* familyName) : CIntfObjPtrB<IGaiaLibrary>(
		MODULE_DBACCESS, false, CLSID_DALibrary, IID_IGaiaLibrary)
	{
		CICSSettings sets;
		IICSSettings* pSets = sets.Self();
		if(pSets)
		{
			CreateGaiaLibrary(pSets, familyName);
		}
	}

	//根据数据库配置信息创建一个新的接口对象
	IGaiaLibrary* CreateDALibrary(const DBCONFIG* pDbInfo)
	{
		void* pParams[2];
		pParams[0] = (void*)pDbInfo;     //客户端模块标识
		pParams[1] = 0; //(void*)procName; //用户指针
		return CreateObject(pParams);
	}

private:
	void MyStrcat(DBCONFIG& destStrCfg, const char* str1, const char* str2)
	{
		strcat(destStrCfg.hostAddr, str1);
		strcat(destStrCfg.hostAddr, str2);
	};

	bool CreateGaiaLibrary(IICSSettings* pSets, const char* familyName)
	{
		DBCONFIG dbInfo;
		dbInfo.libType = LT_RTGAIA;
		dbInfo.userName[0] = 0;
		dbInfo.password[0] = 0;
		dbInfo.hostAddr[0] = 0;

		//QLibrary myLib("currentcontext");
		//MyGetCurrentContextString myGetCurrentContextString = (MyGetCurrentContextString) myLib.resolve("GetCurrentContextString");

		bool isRemote = pSets->ItemReadBool("plat_sys/rtdbproxy/rtdbremote");
		if(isRemote)
		{
			char sIP11[16], sIP12[16], sIP21[16], sIP22[16];
			if(pSets->ItemReadString("plat_global/server1/ip1", sIP11, 16) && sIP11[0])
			{
				MyStrcat(dbInfo, "Host1=", sIP11);
				if(pSets->ItemReadString("plat_global/server1/ip2", sIP12, 16) && sIP12[0])
				{
					MyStrcat(dbInfo, ",", sIP12);
				}
				if(pSets->ItemReadString("plat_global/server2/ip1", sIP21, 16) && sIP21[0])
				{
					MyStrcat(dbInfo, ";Host2=", sIP21);
					if(pSets->ItemReadString("plat_global/server2/ip2", sIP22, 16) && sIP22[0])
					{
						MyStrcat(dbInfo, ",", sIP22);
					}
				}
			}
		}
		else
		{
			strcpy(dbInfo.hostAddr, "");
		}
		printf("isRemote=%d，dbInfo.hostAddr='%s' \n", isRemote, dbInfo.hostAddr);

		pSets->ItemReadString("plat_global/database/rtdb/schema/dbname", dbInfo.librName, 32);//dbInfo.librName
		dbInfo.librName[31] = '\0';

		this->m_pObj = CreateDALibrary(&dbInfo);
		if(this->m_pObj == 0)
		{
			printf("create rtdb database fail! \n");
			return false;
		}

		char sApp[16], sFam[16], sMisc[48], sPort[64];
		pSets->ItemReadString("plat_global/database/rtdb/schema/appname", sApp, 16);
		sApp[15] = '\0';
		/*if(myGetCurrentContextString)
		{
			sprintf(sFam, "%s", myGetCurrentContextString());
		}
		else*/
		{
			strncpy(sFam, familyName, 16);
		}
		sFam[15] = '\0';
		sprintf(sMisc, "App=%s;fam=%s", sFam/*sApp*/, sFam);

		if(isRemote)
		{
			char sReq[16], sSokt[16];
			strcpy(sReq, "2");
			pSets->ItemReadString("plat_sys/rtdbproxy/port", sSokt, 16);
			sSokt[15] = '\0';
			sprintf(sPort, "RequiredServer=%s;Socket=%s", sReq, sSokt);
		}
		else
		{
			sPort[0] = 0;
		}

		//printf("-------------- %s %s ------------------ \n", sMisc, sPort);
		this->m_pObj->SetGaiaParams(sMisc, sPort, isRemote);
		if(!this->m_pObj->Open())
		{
			printf("Open rtdb database fail! \n");
			this->m_pObj->Release();
			this->m_pObj = 0;
			return false;
		}

		return true;
	}

};

/*
//访问远程实时库的代码示例如下：
// 	DBCONFIG dbInfo;
// 	dbInfo.libType = LT_RTGAIA;
// 	strcpy(dbInfo.librName, "scada");
// 	strcpy(dbInfo.userName, "");
// 	strcpy(dbInfo.password, "");
// 	strcpy(dbInfo.hostAddr, "=10.10.10.5;10.10.10.6");
// 	CDALibrary db(&dbInfo);
// 	IGaiaLibrary* pGDB = 0;
// 	db->QueryInterface(IID_IGaiaLibrary, (void**)&pGDB);
// 	if(pGDB)
// 	{
// 		char sMisc[48], sPort[16];
// 		sprintf(sMisc, "App=scada;fam=scada");
// 		sprintf(sPort, "RequiredServer=2;Socket=8040");
// 		pGDB->SetGaiaParams(sMisc, sPort, false);
// 		pGDB->Release();
// 	}
// 	IDALibrary* pDB = db.Self();
// 	if(pDB) pDB->Open();
*/

/*class CGdbLibrary : public CIntfObjPtrB<IGaiaLibrary>
// {
// public:
// 	CGdbLibrary() 
// 		: CIntfObjPtrB<IGaiaLibrary>(MODULE_DBACCESS)
// 	{
// 		DBCONFIG dbInfo;
// 		dbInfo.libType = LT_RTGDB;
// 		dbInfo.userName[0] = 0;
// 		dbInfo.password[0] = 0;
// 		dbInfo.hostAddr[0] = 0;
// 		CICSSettings sets;
// 		IICSSettings* pSets = sets.Self();
// 		//pSets->ItemReadString("plat_global/database/rtdb/schema/dbname", dbInfo.librName, 32);
// 		sprintf(dbInfo.librName, "ics8000");
// 		this->m_pObj = CreateDALibrary(&dbInfo);
// 		if(this->m_pObj)
// 		{
// 			char sApp[16], sFam[16], sMisc[48];
// 			//pSets->ItemReadString("plat_global/database/rtdb/schema/appname", sApp, 32);
// 			//pSets->ItemReadString("plat_global/database/rtdb/schema/familyname", sFam, 32);
// 			sprintf(sApp, "ics8000");
// 			sprintf(sFam, "xuji");
// 			
// 			sprintf(sMisc, "App=%s;fam=%s", sApp, sFam);
// 			this->m_pObj->SetGaiaParams(sMisc);
// 			if(!this->m_pObj->Open())
// 			{
// 				printf("Open gaia database fail! \n");
// 				this->m_pObj->Release();
// 				this->m_pObj = 0;
// 			}
// 		}
// 	}
// 	
// 	//根据数据库配置信息创建一个新的接口对象
// 	IGaiaLibrary* CreateDALibrary(const DBCONFIG* pDbInfo)
// 	{
// 		void* pParams[1];
// 		pParams[0] = (void*)pDbInfo;     //客户端模块标识
// 		return (IGaiaLibrary*)CreateObject(CLSID_DALibrary, IID_IGdbLibrary, pParams);
// 	}
	
};*/

class CDARecords : public CIntfObjPtrB<IDARecords>
{
public:
	CDARecords() : CIntfObjPtrB<IDARecords>(
		MODULE_DBACCESS, false, CLSID_DARecords, IID_IDARecords) { }
	
	CDARecords(IDALibrary* pLibrary) : CIntfObjPtrB<IDARecords>(
		MODULE_DBACCESS, CLSID_DARecords, IID_IDARecords, (void**)&pLibrary, false) { }
};

class CDAQuery : public CIntfObjPtrB<IDAQuery>
{
public:
	CDAQuery() : CIntfObjPtrB<IDAQuery>(
		MODULE_DBACCESS, false, CLSID_DAQuery, IID_IDAQuery) { }
	
	CDAQuery(IDALibrary* pLibrary) : CIntfObjPtrB<IDAQuery>(
		MODULE_DBACCESS, CLSID_DAQuery, IID_IDAQuery, (void**)&pLibrary, false) { }
};

class CDATable : public CIntfObjPtrB<IDATable>
{
public:
	CDATable() : CIntfObjPtrB<IDATable>(
		MODULE_DBACCESS, false, CLSID_DATable, IID_IDATable) { }
	
	CDATable(IDALibrary* pLibrary, bool bSynchro=true) : CIntfObjPtrB<IDATable>(
		MODULE_DBACCESS, false, CLSID_DATable, IID_IDATable) 
	{
		this->m_pObj = CreateDATable(pLibrary, bSynchro);
	}
	
	//创建一个新的接口对象
	IDATable* CreateDATable(IDALibrary* pLibrary, bool bSynchro=true)
	{
		void* pParams[2];
		pParams[0] = (void*)pLibrary;     //客户端模块标识
		pParams[1] = (void*)&bSynchro;       //用户指针
		return CreateObject(pParams);
	}
};

class CGaiaTable : public CIntfObjPtrB<IGaiaTable>
{
public:
	CGaiaTable() : CIntfObjPtrB<IGaiaTable>(
		MODULE_DBACCESS, false, CLSID_GaiaTable, IID_IGaiaTable) { }
	
	CGaiaTable(IDALibrary* pLibrary, const char* tableName) : CIntfObjPtrB<IGaiaTable>(
		MODULE_DBACCESS, false, CLSID_GaiaTable, IID_IGaiaTable) 
	{
		this->m_pObj = CreateGaiaTable(pLibrary, tableName);
	}
	
	//创建一个新的接口对象
	IGaiaTable* CreateGaiaTable(IDALibrary* pLibrary, const char* tableName)
	{
		void* pParams[2];
		pParams[0] = (void*)pLibrary;     //客户端模块标识
		pParams[1] = (void*)tableName;       //用户指针
		return CreateObject(pParams);
	}
};

#endif 
