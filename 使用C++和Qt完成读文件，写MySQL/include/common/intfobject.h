// intfobject.h: interface for the CIntfObject class.

#ifndef _INTFOBJECT_2007_03_14_PENGSHIKANG_H_
#define _INTFOBJECT_2007_03_14_PENGSHIKANG_H_

#include "../commgr/icsunknown.h" // for IICSUnknown
#include "../commgr/exportdef.h"  // for DLL_EXPORT
#include <qmutex.h>

//[ģ������ƽӿڹ淶]-ʵ��IUnknown�ӿڵ���(����׼ʵ��)
class DLL_EXPORT CIntfObject: virtual public IICSUnknown  	///�ӿ�ʵ����--IICSUnknown
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
		int iRef = m_pOuter ? m_pOuter->Release() : ObjRelease();///�ӿ���������1
		if(iRef == 0)
		{
			m_pOuter = 0; // ��ֹ��delete this��ʱ�ٴε��á�m_pOuter->Release()��
			delete this;
		}
		return iRef;
	};
	
protected:
	//ֻ�е�m_pOuter == 0ʱ���Ż��������ķ�������
	virtual bool ObjQueryInterface(const char* InterfaceName, void** ppUnknown) // ���������д�ú�������
	{
		*ppUnknown = 0;
		if(IsEqual(InterfaceName, IID_IICSUnknown))
		{
			*ppUnknown = (IICSUnknown*)this;
			AddRef();
		}
		return (*ppUnknown != 0);
	};
	
	virtual int ObjAddRef() // ����ΪΨһʵ��ʱ���Ż���д�ú���Ϊ��return 1;����
	{
		QMutexLocker locker(&m_Mutex);
		return ++m_iRef;
	};
	
	virtual int ObjRelease() // ����ΪΨһʵ��ʱ���Ż���д�ú���Ϊ��return 1;����
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
