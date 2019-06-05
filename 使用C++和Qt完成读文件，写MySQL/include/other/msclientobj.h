// msclientobj.h: implement for the CMSClientObj class.
#ifndef _MSCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_
#define _MSCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"       // for CIntfObjPtr
#include "../../interface/imscclient.h" // for IMSCClient

#define MODULE_MSCCLIENT		"msclient"
#define METHOD_GETMSCCLIENT		"GetMSCClient"    /*IMSCClient* GetMSCClient(char* psModel, unsigned short CenterPort, 
														char* CenterIP, unsigned short CenterPort2, char* CenterIP2);*/
#define METHOD_REMOVEMSCCLIENT	"RemoveMSCClient" // void RemoveMSCClient(IMSCClient* pInterface);

//DLL����Ľӿڶ�������
class CMSClientObj : public CIntfObjPtr<IMSCClient>
{
public:
	CMSClientObj() : CIntfObjPtr<IMSCClient>(MODULE_MSCCLIENT) { }
	
	~CMSClientObj()
	{
		FreeIntf();
	}
	
	//��DLL��ȡ��Ϣ�ͻ�
	IMSCClient* GetMSCClient(char* psModel, unsigned short CenterPort, char* CenterIP, 
										unsigned short CenterPort2=0, char* CenterIP2=0)
	{
		if(m_pObj == 0)
			m_pObj = CreateObject(psModel, CenterPort, CenterIP, CenterPort2, CenterIP2);
		return m_pObj;
	}

	//��DLL��ȡ��Ϣ�ͻ�
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
	
	//�����ࣺ��DLL��ȡ��Ϣ�ͻ���
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
	
	//�����ࣺɾ����Ϣ�ͻ���
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

	static IMSCClient* CreateRegisteredMSCClient(IMSCClientCallBack* pCallBack, char* psModel, char* cliName, 
		unsigned short nModeType, long nMesTypeNum, unsigned short* pMesTypes)
	{
		CMSClientObj mscCliObj;
		IMSCClient* pObj = mscCliObj.CreateObject(psModel, 0, "0.0.0.0");
		if(pObj)
		{
			pObj->SetCallBackInterface(pCallBack);
			if(!pObj->LogIn(cliName, nModeType, nMesTypeNum, pMesTypes)) 
			{
				mscCliObj.FreeObject(&pObj);
			}
		}
		return pObj;
	}
	
	static void FreeMSCClient(IMSCClient** ppObj)
	{
		CMSClientObj mscCliObj;
		mscCliObj.FreeObject(ppObj);
	}
	
};
	
#endif 
