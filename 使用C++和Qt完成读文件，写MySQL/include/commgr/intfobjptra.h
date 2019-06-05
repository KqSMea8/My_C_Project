// intfobjptra.h: implement for the CIntfObjPtrA<IntfObj> class.

// ����˵�����û�ʹ�õĻ��࣬���ڼ��������׼���A�����DLL����׼���A�����
//           DLL���á�GetClassObject(char*, IICSUnknown**)���õ�DLL�ڲ���ʵ���ࡣ
// ���ú�����IntfClass* Self();
//           IntfClass* operator->();
//           IntfClass* CreateObject();
//           void FreeObject(IntfClass** ppObj);
// ����̳У�CIntfObjPtrA(const char* dllName, const char* dllCID, 
//               const char* dllIID, bool bMakeIntf=true, bool bNeedInit=true);

#ifndef _INTFOBJPTRA_2007_12_02_PENGSHIKANG_H_
#define _INTFOBJPTRA_2007_12_02_PENGSHIKANG_H_

#include "intfobjptr1.h"  // for CIntfObjPtr1

#define METHOD_GETCLASSOBJECT		"GetClassObject"    //bool GetClassObject(char*, IICSUnknown**);

//�����׼���A�����DLLӦ�û���
template <class IntfClass>
class CIntfObjPtrA : public CIntfObjPtr1<IntfClass>
{
public:
	//����Ĺ���������
	//bool DllIsLoaded();     // �ж�DLL�Ƿ��ѳɹ�װ��
	//IntfClass* Self();      // �õ��ӿڶ���
	//IntfClass* operator->();// ���ء�->������
	//IntfClass** operator&();// ���ء�&������
	//void SetDllObjType(const char* dllCID); //����DLL�ڲ���ʵ�����������ͱ�ʶ����
	//void SetIntfObjType(const char* dllIID);//����DLL����ӿ����������ͱ�ʶ����
	//����һ���µ�DLL����ӿ������ָ�롣
	//IntfClass* CreateObject(const char* dllCID, const char* dllIID);
	//IntfClass* CreateObject(const char* dllIID);
	//IntfClass* CreateObject();
	//�ͷ�DLL����ӿ������ָ�롣
	//void FreeObject(IntfClass** ppObj);

	//�õ�DLL�ڲ���ʵ�������
	virtual IICSUnknown* CreateDllObj(const char* dllCID, void*[]=0)
	{
		IICSUnknown* pDllObj = 0;
		if(m_pCreateObject && dllCID && dllCID[0])
		{
			char* cDllCID = (char*)dllCID;
			(*m_pCreateObject)(cDllCID, &pDllObj);
		}
		return pDllObj;
	}

	CIntfObjPtrA(const char* dllName, bool bNeedInit=true)
		: CIntfObjPtr1<IntfClass>(dllName, bNeedInit)
	{
		m_pCreateObject = (CreateMethod)CIntfObjPtr1<IntfClass>::GetActionPtr(METHOD_GETCLASSOBJECT);
	}
	
	CIntfObjPtrA(const char* dllName, const char* dllCID, const char* dllIID, bool bMakeIntf=true, bool bNeedInit=true)
		: CIntfObjPtr1<IntfClass>(dllName, dllCID, dllIID, bNeedInit)
	{
		m_pCreateObject = (CreateMethod)CIntfObjPtr1<IntfClass>::GetActionPtr(METHOD_GETCLASSOBJECT);
		if(bMakeIntf) this->m_pObj = CIntfObjPtr1<IntfClass>::CreateObject(dllCID, dllIID);
	}
	
private:
	//�����˽�г�Ա
	//const char* m_sDllName;
	//bool m_bNeedInit;
	//char* m_sDllCID;
	//char* m_sDllIID;
	//����ı�����Ա
	//IntfClass* m_pObj;
	typedef bool (*CreateMethod)(char*, IICSUnknown**);
	CreateMethod m_pCreateObject;
	
};
	
#endif 
