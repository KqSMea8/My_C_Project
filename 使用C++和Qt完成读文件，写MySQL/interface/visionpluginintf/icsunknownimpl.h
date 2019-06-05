#ifndef _ICSUNKNOWN_IMPL__H_
#define _ICSUNKNOWN_IMPL__H_
#include "../icsunknown.h"

#include <qmutex.h>
#include <qbytearray.h>
/*
IICSUnknownImpl:
(1) ʵ��IICSUnknown�ӿ�
(2) �ṩ�麯���������������ʵ�ֻ���ʵ�ֵĽӿ�(objQueryInterface)
(3) ֧�־ۺ�
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
    int m_iRef;                         //���ü���
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
    //�������IICSUnknown�ӿ�ʵ��
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