// csfclientobj.h: implement for the CCSFClientObj class.
#ifndef _CSFCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_
#define _CSFCCLIENTOBJ_2007_12_04_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"           // for CIntfObjPtr
#include "../../interface/csf/csfappinter.h"// for ICSF_Appinter_Interface
#include "../../include/objectbase/writedailylog.h" // for WriteDailyLog()、g_fileName

#define MODULE_CSFCLIENT		"appinter"
#define METHOD_GETCSFCLIENT		"GetCSFUnknown" // ICSFUnknown* GetCSFUnknown();

//DLL输出的接口对象引用
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
	//得到DLL内部的实现类对象。
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
			WriteDailyLog(true, "1.软件运行失败！appinter.dll中找不到导出函数GetCSFUnknown()。");
			return 0;
		}
	}

	//创建一个新的DLL输出接口类对象指针。
	ICSF_APP_Interface* CreateObject(int nAppId, ICSF_APP_CallBackInterface* pBackIntf)
	{
		ICSF_APP_Interface* pObj = 0;
		ICSFUnknown* pICSFUnknown = CreateDllObj();
		if(pICSFUnknown)
			pICSFUnknown->QueryInterface("ICSF_APP_Interface", (void**)&pObj);
		else
			WriteDailyLog(true, "2.软件运行失败！执行appinter.dll的GetCSFUnknown()函数返回空ICSFUnknown指针。");

		if(pObj && pBackIntf)
		{
			pObj->Advise(pBackIntf);//设置回调接口
			long nInitRet = pObj->Initialize(nAppId);
			if(nInitRet == 0)//启动线程成功
			{
				printf("appinter Initialize() success!");
				pObj->SetAppWorkState(0); //added by hkq 20080916；modify by psk 20150116
			}
			else
			{
				WriteDailyLog(true, "4.软件运行失败！执行ICSF_APP_Interface* pObj指针的Initialize(%d)函数返回值为%d（正常值为0）。", nAppId, nInitRet);
				pObj = 0;
			}
		}
		else
		{
			WriteDailyLog(true, "3.软件运行失败！执行ICSFUnknown指针的QueryInterface(\"ICSF_APP_Interface\", (void**)&pObj)函数，返回参数pObj为空指针。");
		}
		return pObj;
	}
	
	//处理父类：创建一个新的DLL输出接口类对象指针。
	virtual ICSF_APP_Interface* CreateObject(void* pParams[]=0)
	{
		if(!pParams || !pParams[0]) return 0;
		int nAppId = *(int*)pParams[0];
		ICSF_APP_CallBackInterface* pBackIntf = (ICSF_APP_CallBackInterface*)pParams[1];
		return CreateObject(nAppId, pBackIntf);
	}
	
	//处理父类：释放DLL输出接口类对象指针。
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
