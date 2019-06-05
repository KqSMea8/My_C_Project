#ifndef _ICSUNKNOWN_IMPL__H_
#define _ICSUNKNOWN_IMPL__H_
#include "../icsunknown.h"

#include <qmutex.h>
#include <qbytearray.h>
/*
IICSUnknownImpl:
(1) 实现IICSUnknown接口
(2) 提供虚函数以让派生类可以实现基类实现的接口(objQueryInterface)
(3) 支持聚合
*/
template <class T>
class IICSUnknownImpl: virtual public IICSUnknown  
{
public:
	IICSUnknownImpl(IICSUnknown *pOuter = 0)
	{
		m_iRef = 1;
		m_pOuter = pOuter;
	}
	virtual ~IICSUnknownImpl()
	{
	}
	virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown)
	{
		if (m_pOuter)
			return m_pOuter->QueryInterface(InterfaceName, ppUnknown);
		else
			return ObjQueryInterface(InterfaceName, ppUnknown);
	}
	virtual int AddRef()
	{       
		if (m_pOuter) 
			return m_pOuter->AddRef();
		else
			return ObjAddRef();
	}
	virtual int Release()
	{
		if (m_pOuter)
			return m_pOuter->Release();
		else
			return ObjRelease();
	}

protected:
    int m_iRef;                         //引用计数
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
    //对象本身的IICSUnknown接口实现
	virtual int ObjAddRef()
	{
		QMutexLocker lock(&m_Mutex);
		return ++m_iRef;   
	}
	virtual int ObjRelease()
	{ 
		m_Mutex.lock();
		int i = --m_iRef;
		m_Mutex.unlock();
		if (m_iRef == 0) delete this;     
		return i;   
	}
	virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown)
	{
		if ( qstrcmp( InterfaceName,IID_IICSUnknown ) == 0 )
		{
			*ppUnknown = (IICSUnknown *)this;
			AddRef();
			return true;
		}
		else return false;
	}
};

#endif 