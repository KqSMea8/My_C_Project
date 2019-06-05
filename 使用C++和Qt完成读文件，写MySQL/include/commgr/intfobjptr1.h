// intfobjptr1.h: implement for the CIntfObjPtr1<IntfObj> class.

// ����˵�����û�ʹ�õĻ��࣬���ڼ��������׼������ӿڣ������DLL��
//           ��׼�������������ü�����ʽ��ʹ�ýӿڣ��ýӿڴ�IICSUnknown
//           ������������ӵ��QueryInterface()��AddRef()��Release()�ȷ�����
// ���ú�����IntfClass* Self();
//           IntfClass* operator->();
//           IntfClass* CreateObject(void* pParams[]=0);
//           void FreeObject(IntfClass** ppObj);
// �������أ�IICSUnknown* CreateDllObj(const char* dllCID, void* pParams[]=0);

#ifndef _INTFOBJPTR1_2009_03_03_PENGSHIKANG_H_
#define _INTFOBJPTR1_2009_03_03_PENGSHIKANG_H_

#include <stdlib.h>     // for malloc()��free()
#include "intfobjptr.h" // for CIntfObjPtr
#include "icsunknown.h" // for IICSUnknown

//�����׼�����ʽ�Ľӿڶ����DLLӦ�û���
template <class IntfClass>
class CIntfObjPtr1 : public CIntfObjPtr<IntfClass>
{
public:
	//����Ĺ���������
	//bool DllIsLoaded();     // �ж�DLL�Ƿ��ѳɹ�װ��
	//IntfClass* Self();      // �õ��ӿڶ���
	//IntfClass* operator->();// ���ء�->������
	//IntfClass** operator&();// ���ء�&������

	//�õ�DLL�ڲ���ʵ�������
	virtual IICSUnknown* CreateDllObj(const char* dllCID, void* pParams[]=0) = 0;

	//����һ���µ�DLL����ӿ������ָ�롣
	virtual IntfClass* CreateObject(const char* dllCID, const char* dllIID, void* pParams[]=0) 
	{
		void* pIntfObj = 0;
		IICSUnknown* pDllObj = CreateDllObj(dllCID, pParams);
		if(pDllObj)// new 
		{
			if(dllIID && dllIID[0])
			{
				char* cDllIID = (char*)dllIID;
				pDllObj->QueryInterface(cDllIID, &pIntfObj); // add one
			}
			pDllObj->Release(); // minus one
		}
		return (IntfClass*)pIntfObj;
	}
	
	//����һ���µ�DLL����ӿ������ָ�롣
	virtual IntfClass* CreateObject(const char* dllIID, void* pParams[]=0) 
	{
		return CreateObject(m_sDllCID, dllIID, pParams);
	}
	
	//�����ࣺ����һ���µ�DLL����ӿ������ָ�롣
	virtual IntfClass* CreateObject(void* pParams[]=0)
	{
		return CreateObject(m_sDllCID, m_sDllIID, pParams);
	}
	
	//�����ࣺ�ͷ�DLL����ӿ������ָ�롣
	virtual void FreeObject(IntfClass** ppObj)
	{
		if(ppObj && *ppObj)
		{
			((IICSUnknown*)*ppObj)->Release();
			*ppObj = 0;
		}
	}
	
	//����DLL�ڲ���ʵ�����������ͱ�ʶ����
	void SetDllObjType(const char* dllCID)
	{
		if(m_sDllCID)
		{
			free(m_sDllCID);
			m_sDllCID = 0;
		}
		if(dllCID)
		{
			int len = strlen(dllCID);
			m_sDllCID = (char*)malloc(len+1);
			strcpy(m_sDllCID, dllCID);
			m_sDllCID[len] = 0;
		}
	}
	
	//����DLL����ӿ����������ͱ�ʶ����
	void SetIntfObjType(const char* dllIID)
	{
		if(m_sDllIID)
		{
			free(m_sDllIID);
			m_sDllIID = 0;
		}
		if(dllIID)
		{
			int len = strlen(dllIID);
			m_sDllIID = (char*)malloc(len+1);
			strcpy(m_sDllIID, dllIID);
			m_sDllIID[len] = 0;
		}
	}
	
protected:
	CIntfObjPtr1(const char* dllName, bool bNeedInit=true) 
		: CIntfObjPtr<IntfClass>(dllName, bNeedInit)
	{
		m_sDllCID = 0;
		m_sDllIID = 0;
	};
	
	CIntfObjPtr1(const char* dllName, const char* dllCID, const char* dllIID, bool bNeedInit=true)
		: CIntfObjPtr<IntfClass>(dllName, bNeedInit)
	{
		m_sDllCID = 0;
		m_sDllIID = 0;
		SetDllObjType(dllCID);
		SetIntfObjType(dllIID);
	}
	
	virtual ~CIntfObjPtr1()
	{
		if(m_sDllCID) free(m_sDllCID);
		if(m_sDllIID) free(m_sDllIID);
		CIntfObjPtr<IntfClass>::FreeIntf();
	}
	
	CIntfObjPtr1(const CIntfObjPtr1&);
	CIntfObjPtr1& operator=(const CIntfObjPtr1&);
	CIntfObjPtr1& operator*();

private:
	//�����˽�г�Ա
	//const char* m_sDllName;
	//bool m_bNeedInit;
	//����ı�����Ա
	//IntfClass* m_pObj;
	char* m_sDllCID;
	char* m_sDllIID;
};
	
#endif 
