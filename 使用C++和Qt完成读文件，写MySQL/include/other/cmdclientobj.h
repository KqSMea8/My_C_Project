// cmdclientobj.h: implement for the CCmdClientObj class.
#ifndef _CMDCLIENTOBJ_2008_10_10
#define _CMDCLIENTOBJ_2008_10_10

#include "../commgr/intfobjptr.h"       // for CIntfObjPtr
#include "../../interface/imscclient.h" // for IMSCClient

#define MODULE_CMDCLIENT		"cmdclient"
#define METHOD_GETMSCCLIENT		"GetMSCClient"    /*IMSCClient* GetMSCClient(char* psModel, unsigned short CenterPort, 
														char* CenterIP, unsigned short CenterPort2, char* CenterIP2);*/
#define METHOD_REMOVEMSCCLIENT	"RemoveMSCClient" // void RemoveMSCClient(IMSCClient* pInterface);

//DLL输出的接口对象引用
class CCmdClientObj : public CIntfObjPtr<IMSCClient>
{
public:
	CCmdClientObj() : CIntfObjPtr<IMSCClient>(MODULE_CMDCLIENT) { }
	
	~CCmdClientObj()
	{
		FreeIntf();
	}
	
	//从DLL获取消息客户
	IMSCClient* GetMSCClient(char* psModel, unsigned short CenterPort, char* CenterIP, 
										unsigned short CenterPort2=0, char* CenterIP2=0)
	{
		if(m_pObj == 0)
			m_pObj = CreateObject(psModel, CenterPort, CenterIP, CenterPort2, CenterIP2);
		return m_pObj;
	}

	//从DLL获取消息客户
	IMSCClient* CreateObject(char* psModel, unsigned short CenterPort, char* CenterIP, 
										unsigned short CenterPort2=0, char* CenterIP2=0)
	{
		typedef IMSCClient* (*GetMSCClientMethod)(char*, unsigned short, char*, unsigned short, char*);
		GetMSCClientMethod DoGetMscClient = (GetMSCClientMethod)GetActionPtr(METHOD_GETMSCCLIENT);
		if(DoGetMscClient)
			return DoGetMscClient(psModel, CenterPort, CenterIP, CenterPort2, CenterIP2);
		else
			return 0;
	}
	
	//处理父类：从DLL获取消息客户。
	virtual IMSCClient* CreateObject(void* pParams[]=0)
	{
		if(!pParams || !pParams[0]) return 0;
		char* psModel = (char*)pParams[0];
		unsigned short CenterPort = *(unsigned short*)pParams[1];
		char* CenterIP = (char*)pParams[2];
		unsigned short CenterPort2 = *(unsigned short*)pParams[3];
		char* CenterIP2 = (char*)pParams[4];
		return CreateObject(psModel, CenterPort, CenterIP, CenterPort2, CenterIP2);
	}
	
	//处理父类：删除消息客户。
	virtual void FreeObject(IMSCClient** ppObj)
	{
		if(ppObj && *ppObj)
		{
			(*ppObj)->LogOut();
			typedef void (*EraseMSCClientMethod)(IMSCClient*);
			EraseMSCClientMethod DoRemoveMSCClient = (EraseMSCClientMethod)GetActionPtr(METHOD_REMOVEMSCCLIENT);
			if(DoRemoveMSCClient) DoRemoveMSCClient(*ppObj);
			*ppObj = 0;
		}
	}
	
};
	
#endif 
