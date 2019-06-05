// csfclientobj.h: implement for the CCSFClientObj class.
#ifndef _CSFCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_
#define _CSFCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"           // for CIntfObjPtr
#include "../../interface/csf/csfappinter.h"// for ICSF_Appinter_Interface
#include "../../include/objectbase/writedailylog.h" // for WriteDailyLog()��g_fileName

#define MODULE_CSFCLIENT		"appinter"
#define METHOD_GETCSFCLIENT		"GetCSFUnknown" // ICSFUnknown* GetCSFUnknown();

//DLL����Ľӿڶ�������
class CCSFClientObj : public CIntfObjPtr<ICSF_APP_Interface>
{
public:
	CCSFClientObj() 
		: CIntfObjPtr<ICSF_APP_Interface>(MODULE_CSFCLIENT, false) { }
	
	CCSFClientObj(int nAppId, ICSF_APP_CallBackInterface* pBackIntf) 
		: CIntfObjPtr<ICSF_APP_Interface>(MODULE_CSFCLIENT, false)
	{
		this->m_pObj = CreateObject(nAppId, pBackIntf);
	}
	
	virtual ~CCSFClientObj()
	{
		FreeIntf();
	}
	
protected:
	//�õ�DLL�ڲ���ʵ�������
	ICSFUnknown* CreateDllObj()
	{
		typedef ICSFUnknown* (*GetCSFClientMethod)();
		GetCSFClientMethod DoGetCsfClient = (GetCSFClientMethod)GetActionPtr(METHOD_GETCSFCLIENT);
		if(DoGetCsfClient)
		{
			return DoGetCsfClient();
		}
		else
		{
			WriteDailyLog(true, "1.�������ʧ�ܣ�appinter.dll���Ҳ�����������GetCSFUnknown()��");
			return 0;
		}
	}

	//����һ���µ�DLL����ӿ������ָ�롣
	ICSF_APP_Interface* CreateObject(int nAppId, ICSF_APP_CallBackInterface* pBackIntf)
	{
		ICSF_APP_Interface* pObj = 0;
		ICSFUnknown* pICSFUnknown = CreateDllObj();
		if(pICSFUnknown)
			pICSFUnknown->QueryInterface("ICSF_APP_Interface", (void**)&pObj);
		else
			WriteDailyLog(true, "2.�������ʧ�ܣ�ִ��appinter.dll��GetCSFUnknown()�������ؿ�ICSFUnknownָ�롣");

		if(pObj && pBackIntf)
		{
			pObj->Advise(pBackIntf);//���ûص��ӿ�
			long nInitRet = pObj->Initialize(nAppId);
			if(nInitRet == 0)//�����̳߳ɹ�
			{
				printf("appinter Initialize() success!");
				pObj->SetAppWorkState(0); //added by hkq 20080916��modify by psk 20150116
			}
			else
			{
				WriteDailyLog(true, "4.�������ʧ�ܣ�ִ��ICSF_APP_Interface* pObjָ���Initialize(%d)��������ֵΪ%d������ֵΪ0����", nAppId, nInitRet);
				pObj = 0;
			}
		}
		else
		{
			WriteDailyLog(true, "3.�������ʧ�ܣ�ִ��ICSFUnknownָ���QueryInterface(\"ICSF_APP_Interface\", (void**)&pObj)���������ز���pObjΪ��ָ�롣");
		}
		return pObj;
	}
	
	//�����ࣺ����һ���µ�DLL����ӿ������ָ�롣
	virtual ICSF_APP_Interface* CreateObject(void* pParams[]=0)
	{
		if(!pParams || !pParams[0]) return 0;
		int nAppId = *(int*)pParams[0];
		ICSF_APP_CallBackInterface* pBackIntf = (ICSF_APP_CallBackInterface*)pParams[1];
		return CreateObject(nAppId, pBackIntf);
	}
	
	//�����ࣺ�ͷ�DLL����ӿ������ָ�롣
	virtual void FreeObject(ICSF_APP_Interface** ppObj)
	{
		if(ppObj && *ppObj)
		{
			(*ppObj)->Finalize();
			*ppObj = 0;
		}
	}
	
};
	
#endif 
