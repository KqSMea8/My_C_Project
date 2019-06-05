// icsdllobj.h: implement for the CICSDllObj class.

// ����˵�����û�ʹ�õĻ��࣬���ڼ�������������������ǽӿڶ��󣩵�DLL��
// ���ú�����void* GetActionPtr(const char* actionName);

#ifndef _CICSDLLOBJ_2007_12_03_PENGSHIKANG_H_
#define _CICSDLLOBJ_2007_12_03_PENGSHIKANG_H_

#include "dllfactory.h" // for CDllFactory and CICSIntfLib
#include <stdio.h>      // for printf()

//�������������DLLӦ�û���
class CICSDllObj
{
public:
	//�ж�DLL�Ƿ��ѳɹ�װ��
	bool DllIsLoaded()
	{
		return (CDllFactory::Instance()->GetDllLib(m_sDllName)!=0);
	}
	
protected:
	CICSDllObj(const char* dllName, bool bNeedInit=true)
	{
		m_sDllName = dllName;
		m_bNeedInit = bNeedInit;
	}
	
	virtual ~CICSDllObj()
	{
	}
	
	//��ȡDLL����Ĳ�������ָ�롣
	void* GetActionPtr(const char* actionName)
	{
		CICSIntfLib* pIntfLib = LoadDll();
		if(pIntfLib)
		{
			return pIntfLib->GetActionPtr(actionName);
		}
		return 0;
	}
	
	//�����ѳ�ʼ�����ԡ�//ΪOperateComps׼��
	void SetInitialized(bool bInited)
	{
		CICSIntfLib* pIntfLib = LoadDll();
		if(pIntfLib)
		{
			pIntfLib->m_bInited = bInited;
		}
	}
	
	//�Ƿ��ѳ�ʼ����
	bool IsInitialized()
	{
		CICSIntfLib* pIntfLib = LoadDll();
		if(pIntfLib)
		{
			return pIntfLib->m_bInited;
		}
		return false;
	}
	
	//ж��DLL��
	void UnloadDLL()
	{
		CDllFactory::Instance()->UnLoadDll(m_sDllName);
	}
	
	//װ��DLL
	CICSIntfLib* LoadDll()
	{
		if(strcmp(m_sDllName, "")==0) return 0;
		
		CICSIntfLib* pCurDll = 0;
		QMutexLocker(CDllFactory::Instance()->GetMutex());
		QMap<QString, CICSIntfLib*>* pDllMap = CDllFactory::Instance()->GetDllPool();
		if(pDllMap->find(m_sDllName) == pDllMap->end())
		{
			pCurDll = new CICSIntfLib(m_sDllName, pDllMap);
			if(pCurDll)
			{
				if(pCurDll->m_pDllLib)
				{
					if(m_bNeedInit) pCurDll->Initialize();
					pDllMap->insert(m_sDllName, pCurDll);
				}
				else
				{
					delete pCurDll;
					pCurDll = 0;
				}
			}
			else
			{
				printf("Commgr: MakeIntfLib(\'%s.dll\') is failure!\n", m_sDllName);
			}
		}
		else
		{
			pCurDll = (*pDllMap)[m_sDllName];
		}
		return pCurDll;
	}
	
private:
	const char* m_sDllName;
	bool m_bNeedInit;
	
};
	
#endif 
