// intfobjptra.h: implement for the CIntfObjPtrA<IntfObj> class.

// 功能说明：用户使用的基类，用于加载输出标准组件A对象的DLL。标准组件A对象的
//           DLL采用“GetClassObject(char*, IICSUnknown**)”得到DLL内部的实现类。
// 常用函数：IntfClass* Self();
//           IntfClass* operator->();
//           IntfClass* CreateObject();
//           void FreeObject(IntfClass** ppObj);
// 子类继承：CIntfObjPtrA(const char* dllName, const char* dllCID, 
//               const char* dllIID, bool bMakeIntf=true, bool bNeedInit=true);

#ifndef _INTFOBJPTRA_2007_12_02_PENGSHIKANG_H_
#define _INTFOBJPTRA_2007_12_02_PENGSHIKANG_H_

#include "intfobjptr1.h"  // for CIntfObjPtr1

#define METHOD_GETCLASSOBJECT		"GetClassObject"    //bool GetClassObject(char*, IICSUnknown**);

//输出标准组件A对象的DLL应用基类
template <class IntfClass>
class CIntfObjPtrA : public CIntfObjPtr1<IntfClass>
{
public:
	//父类的公共函数：
	//bool DllIsLoaded();     // 判断DLL是否已成功装载
	//IntfClass* Self();      // 得到接口对象
	//IntfClass* operator->();// 重载“->”操作
	//IntfClass** operator&();// 重载“&”操作
	//void SetDllObjType(const char* dllCID); //设置DLL内部的实现类对象的类型标识符。
	//void SetIntfObjType(const char* dllIID);//设置DLL输出接口类对象的类型标识符。
	//创建一个新的DLL输出接口类对象指针。
	//IntfClass* CreateObject(const char* dllCID, const char* dllIID);
	//IntfClass* CreateObject(const char* dllIID);
	//IntfClass* CreateObject();
	//释放DLL输出接口类对象指针。
	//void FreeObject(IntfClass** ppObj);

	//得到DLL内部的实现类对象。
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
	//父类的私有成员
	//const char* m_sDllName;
	//bool m_bNeedInit;
	//char* m_sDllCID;
	//char* m_sDllIID;
	//父类的保护成员
	//IntfClass* m_pObj;
	typedef bool (*CreateMethod)(char*, IICSUnknown**);
	CreateMethod m_pCreateObject;
	
};
	
#endif 
