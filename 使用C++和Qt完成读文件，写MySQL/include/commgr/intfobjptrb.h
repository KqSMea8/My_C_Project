// intfobjptrb.h: implement for the CIntfObjPtrB<IntfObj> class.

// ����˵�����û�ʹ�õĻ��࣬���ڼ��������׼���B�����DLL����׼���B�����
//           DLL���á�GetNewClassObject(const char*, IICSUnknown**, void**)��
//           �õ�DLL�ڲ���ʵ���ࡣ
// ���ú�����IntfClass* Self();
//           IntfClass* operator->();
//           IntfClass* CreateObject(void* pParams[]=0);
//           void FreeObject(IntfClass** ppObj);
// ����̳У�1���������ӿڶ�����Ҫ��ֻ��Ҫһ���������ʱ��һ��̳��ڣ�
//           CIntfObjPtrB(const char* dllName, const char* dllCID, 
//               const char* dllIID, void* pParams[]=0, bool bNeedInit=true);
//           2���������ӿڶ�����Ҫ�����������������ʱ��һ��̳��ڣ�
//           CIntfObjPtrB(const char* dllName, bool bNeedInit, 
//               const char* dllCID, const char* dllIID);

#ifndef _INTFOBJPTRB_2007_12_02_PENGSHIKANG_H_
#define _INTFOBJPTRB_2007_12_02_PENGSHIKANG_H_

#include "intfobjptr1.h"  // for CIntfObjPtr1

#define METHOD_GETNEWCLASSOBJECT	"GetNewClassObject" //bool GetNewClassObject(const char*, IICSUnknown**, void**);

//�����׼���B�����DLLӦ�û���
template <class IntfClass>
class CIntfObjPtrB : public CIntfObjPtr1<IntfClass>
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
	//IntfClass* CreateObject(const char* dllCID, const char* dllIID, void* pParams[]=0);
	//IntfClass* CreateObject(const char* dllIID, void* pParams[]=0) ;
	//IntfClass* CreateObject(void* pParams[]=0);
	//�ͷ�DLL����ӿ������ָ�롣
	//void FreeObject(IntfClass** ppObj);

	//�õ�DLL�ڲ���ʵ�������
	virtual IICSUnknown* CreateDllObj(const char* dllCID, void* pParams[]=0)
	{
		IICSUnknown* pDllObj = 0;
		if(m_pCreateObject && dllCID && dllCID[0])
		{
			char* cDllCID = (char*)dllCID;
			(*m_pCreateObject)(cDllCID, &pDllObj, pParams);
		}
		return pDllObj;
	}

	CIntfObjPtrB(const char* dllName, bool bNeedInit=true) 
		: CIntfObjPtr1<IntfClass>(dllName, bNeedInit)
	{
		m_pCreateObject = (CreateMethod)GetActionPtr(METHOD_GETNEWCLASSOBJECT);
	}
	
	CIntfObjPtrB(const char* dllName, bool bNeedInit, const char* dllCID, const char* dllIID)
		: CIntfObjPtr1<IntfClass>(dllName, dllCID, dllIID, bNeedInit)
	{
		m_pCreateObject = (CreateMethod)GetActionPtr(METHOD_GETNEWCLASSOBJECT);
	}
	
	CIntfObjPtrB(const char* dllName, const char* dllCID, const char* dllIID, void* pParams[]=0, bool bNeedInit=true)
		: CIntfObjPtr1<IntfClass>(dllName, dllCID, dllIID, bNeedInit)
	{
		m_pCreateObject = (CreateMethod)GetActionPtr(METHOD_GETNEWCLASSOBJECT);
		this->m_pObj = CreateObject(dllCID, dllIID, pParams);
	}
	
private:
	//�����˽�г�Ա
	//const char* m_sDllName;
	//bool m_bNeedInit;
	//char* m_sDllCID;
	//char* m_sDllIID;
	//����ı�����Ա
	//IntfClass* m_pObj;
	typedef bool (*CreateMethod)(const char*, IICSUnknown**, void**);
	CreateMethod m_pCreateObject;
	
};
	
#endif 
