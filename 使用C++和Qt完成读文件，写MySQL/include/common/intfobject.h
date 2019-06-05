// intfobject.h: interface for the CIntfObject class.

#ifndef _INTFOBJECT_2007_03_14_PENGSHIKANG_H_
#define _INTFOBJECT_2007_03_14_PENGSHIKANG_H_

#include "../commgr/icsunknown.h" // for IICSUnknown
#include "../commgr/exportdef.h"  // for DLL_EXPORT
#include <qmutex.h>

//[模块二进制接口规范]-实现IUnknown接口的类(含标准实现)
class DLL_EXPORT CIntfObject: virtual public IICSUnknown  	///接口实现类--IICSUnknown
{
public:
	static bool IsEqual(const char* objName, const char* selfName)
	{
		int i = 0;
		while(objName[i]==selfName[i])
		{
			if(objName[i] == 0) return true;
			++i;
		}
		return false;
	}
	
	CIntfObject(IICSUnknown* pOuter=0) : m_iRef(1), m_pOuter(pOuter)
	{
		if(m_pOuter) m_pOuter->AddRef();
	};
	
	virtual ~CIntfObject()
	{
		if(m_pOuter) m_pOuter->Release();
	};
	
	bool QueryInterface(const char* InterfaceName, void** ppUnknown)
	{
		return ( m_pOuter 
			? m_pOuter->QueryInterface(InterfaceName, ppUnknown) 
			: ObjQueryInterface(InterfaceName, ppUnknown) );
	};

	int AddRef()
	{
		return m_pOuter ? m_pOuter->AddRef() : ObjAddRef();
	};

	int Release()
	{
		int iRef = m_pOuter ? m_pOuter->Release() : ObjRelease();///接口引用数减1
		if(iRef == 0)
		{
			m_pOuter = 0; // 防止“delete this”时再次调用“m_pOuter->Release()”
			delete this;
		}
		return iRef;
	};
	
protected:
	//只有当m_pOuter == 0时，才会调用下面的方法！！
	virtual bool ObjQueryInterface(const char* InterfaceName, void** ppUnknown) // 子类必须重写该函数！！
	{
		*ppUnknown = 0;
		if(IsEqual(InterfaceName, IID_IICSUnknown))
		{
			*ppUnknown = (IICSUnknown*)this;
			AddRef();
		}
		return (*ppUnknown != 0);
	};
	
	virtual int ObjAddRef() // 子类为唯一实体时，才会重写该函数为“return 1;”！
	{
		QMutexLocker locker(&m_Mutex);
		return ++m_iRef;
	};
	
	virtual int ObjRelease() // 子类为唯一实体时，才会重写该函数为“return 1;”！
	{ 
		QMutexLocker locker(&m_Mutex);
		return --m_iRef;
	};

private:
	int m_iRef;
	QMutex m_Mutex;
	IICSUnknown* m_pOuter;
};

#endif 
