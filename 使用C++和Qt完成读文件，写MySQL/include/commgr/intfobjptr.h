// intfobjptr.h: implement for the CIntfObjPtr<IntfObj> class.

// 功能说明：用户使用的基类，用于加载输出接口对象的DLL。
// 常用函数：IntfClass* Self();
//           IntfClass* operator->();
// 子类重载：IntfClass* CreateObject(void* pParams[]=0);
//           void FreeObject(IntfClass** ppObj);
//           ~CChildIntfObjPtr();

#ifndef _INTFOBJPTR_2007_11_23_PENGSHIKANG_H_
#define _INTFOBJPTR_2007_11_23_PENGSHIKANG_H_

#include "icsdllobj.h"  // for CDllFactory and CICSDllObj

//输出接口对象的DLL应用基类
template <class IntfClass>
class CIntfObjPtr : public CICSDllObj
{
public:
	//父类的公共函数：
	//bool DllIsLoaded(); //判断DLL是否已成功装载
	
	//得到接口对象
	IntfClass* Self() { return m_pObj; }
	//重载“->”操作
	IntfClass* operator->() { return m_pObj; }
	//重载“&”操作
	IntfClass** operator&() { return &m_pObj; }

	//创建一个新的DLL输出接口类对象指针。
	virtual IntfClass* CreateObject(void* pParams[]=0) = 0;

	//释放DLL输出接口类对象指针。
	virtual void FreeObject(IntfClass** ppObj) = 0;
	
protected:
	CIntfObjPtr(const char* dllName, bool bNeedInit=true) : CICSDllObj(dllName, bNeedInit)
	{
		m_pObj = 0;
	}
	
	//子类必须重载它！！
	virtual ~CIntfObjPtr()
	{
		//FreeIntf(); //子类必须调用该函数
	}
	
	virtual void FreeIntf()
	{
		if(m_pObj) FreeObject(&m_pObj);
	}

	CIntfObjPtr(const CIntfObjPtr&);
	CIntfObjPtr& operator=(const CIntfObjPtr&);
	CIntfObjPtr& operator*();
	
	//父类的私有成员
	//const char* m_sDllName;
	//bool m_bNeedInit;
	IntfClass* m_pObj;

};
	
#endif 
