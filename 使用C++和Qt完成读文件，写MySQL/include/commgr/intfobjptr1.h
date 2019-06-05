// intfobjptr1.h: implement for the CIntfObjPtr1<IntfObj> class.

// 功能说明：用户使用的基类，用于加载输出标准组件（接口）对象的DLL。
//           标准组件对象采用引用计数方式来使用接口，该接口从IICSUnknown
//           类派生而来，拥有QueryInterface()、AddRef()、Release()等方法。
// 常用函数：IntfClass* Self();
//           IntfClass* operator->();
//           IntfClass* CreateObject(void* pParams[]=0);
//           void FreeObject(IntfClass** ppObj);
// 子类重载：IICSUnknown* CreateDllObj(const char* dllCID, void* pParams[]=0);

#ifndef _INTFOBJPTR1_2009_03_03_PENGSHIKANG_H_
#define _INTFOBJPTR1_2009_03_03_PENGSHIKANG_H_

#include <stdlib.h>     // for malloc()、free()
#include "intfobjptr.h" // for CIntfObjPtr
#include "icsunknown.h" // for IICSUnknown

//输出标准组件形式的接口对象的DLL应用基类
template <class IntfClass>
class CIntfObjPtr1 : public CIntfObjPtr<IntfClass>
{
public:
	//父类的公共函数：
	//bool DllIsLoaded();     // 判断DLL是否已成功装载
	//IntfClass* Self();      // 得到接口对象
	//IntfClass* operator->();// 重载“->”操作
	//IntfClass** operator&();// 重载“&”操作

	//得到DLL内部的实现类对象。
	virtual IICSUnknown* CreateDllObj(const char* dllCID, void* pParams[]=0) = 0;

	//创建一个新的DLL输出接口类对象指针。
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
	
	//创建一个新的DLL输出接口类对象指针。
	virtual IntfClass* CreateObject(const char* dllIID, void* pParams[]=0) 
	{
		return CreateObject(m_sDllCID, dllIID, pParams);
	}
	
	//处理父类：创建一个新的DLL输出接口类对象指针。
	virtual IntfClass* CreateObject(void* pParams[]=0)
	{
		return CreateObject(m_sDllCID, m_sDllIID, pParams);
	}
	
	//处理父类：释放DLL输出接口类对象指针。
	virtual void FreeObject(IntfClass** ppObj)
	{
		if(ppObj && *ppObj)
		{
			((IICSUnknown*)*ppObj)->Release();
			*ppObj = 0;
		}
	}
	
	//设置DLL内部的实现类对象的类型标识符。
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
	
	//设置DLL输出接口类对象的类型标识符。
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
	//父类的私有成员
	//const char* m_sDllName;
	//bool m_bNeedInit;
	//父类的保护成员
	//IntfClass* m_pObj;
	char* m_sDllCID;
	char* m_sDllIID;
};
	
#endif 
