// intfobjptr.h: implement for the CIntfObjPtr<IntfObj> class.

// ����˵�����û�ʹ�õĻ��࣬���ڼ�������ӿڶ����DLL��
// ���ú�����IntfClass* Self();
//           IntfClass* operator->();
// �������أ�IntfClass* CreateObject(void* pParams[]=0);
//           void FreeObject(IntfClass** ppObj);
//           ~CChildIntfObjPtr();

#ifndef _INTFOBJPTR_2007_11_23_PENGSHIKANG_H_
#define _INTFOBJPTR_2007_11_23_PENGSHIKANG_H_

#include "icsdllobj.h"  // for CDllFactory and CICSDllObj

//����ӿڶ����DLLӦ�û���
template <class IntfClass>
class CIntfObjPtr : public CICSDllObj
{
public:
	//����Ĺ���������
	//bool DllIsLoaded(); //�ж�DLL�Ƿ��ѳɹ�װ��
	
	//�õ��ӿڶ���
	IntfClass* Self() { return m_pObj; }
	//���ء�->������
	IntfClass* operator->() { return m_pObj; }
	//���ء�&������
	IntfClass** operator&() { return &m_pObj; }

	//����һ���µ�DLL����ӿ������ָ�롣
	virtual IntfClass* CreateObject(void* pParams[]=0) = 0;

	//�ͷ�DLL����ӿ������ָ�롣
	virtual void FreeObject(IntfClass** ppObj) = 0;
	
protected:
	CIntfObjPtr(const char* dllName, bool bNeedInit=true) : CICSDllObj(dllName, bNeedInit)
	{
		m_pObj = 0;
	}
	
	//�����������������
	virtual ~CIntfObjPtr()
	{
		//FreeIntf(); //���������øú���
	}
	
	virtual void FreeIntf()
	{
		if(m_pObj) FreeObject(&m_pObj);
	}

	CIntfObjPtr(const CIntfObjPtr&);
	CIntfObjPtr& operator=(const CIntfObjPtr&);
	CIntfObjPtr& operator*();
	
	//�����˽�г�Ա
	//const char* m_sDllName;
	//bool m_bNeedInit;
	IntfClass* m_pObj;

};
	
#endif 
