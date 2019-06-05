// icsintflib.h: implement for the CICSIntfLib class.

#ifndef _ICSINTFLIB_2007_11_23_PENGSHIKANG_H_
#define _ICSINTFLIB_2007_11_23_PENGSHIKANG_H_

#include <qmap.h>       // for QMap
#include <qlibrary.h>   // for QLibrary
#include <stdio.h>      // for printf()

#define METHOD_SETDLLPOOL			"SetDllPool"        //void SetDllPool(QMap<QString, CICSIntfLib*>*);
#define METHOD_INITIALIZE			"Initialize"        //bool Initialize();
#define METHOD_UNINITIALZIE			"Uninitialize"      //bool Uninitialize();

//ʵ�ֽӿ����DLL�������
class CICSIntfLib
{
public:
	virtual ~CICSIntfLib()
	{
		UnloadDLL();
	}
	
protected:
	CICSIntfLib()
	{
		m_pDllLib = 0;
		m_bInited = false;
	}

	//���캯�����������������������
	CICSIntfLib(const char* dllName, QMap<QString, CICSIntfLib*>* pDllMap)
	{
		m_pDllLib = 0;
		LoadDLL(dllName, pDllMap);
	}
	
	CICSIntfLib(const CICSIntfLib&);
	CICSIntfLib& operator =(const CICSIntfLib&);
	CICSIntfLib& operator *();

private:
	//װ��DLL��
	virtual bool LoadDLL(const char* dllName, QMap<QString, CICSIntfLib*>* pDllMap)
	{
		UnloadDLL();
		m_pDllLib = new QLibrary(dllName);
		if(m_pDllLib)
		{
			m_pDllLib->setAutoUnload(false);
			if(m_pDllLib->load())
			{
				typedef void (*SetDllPoolAction)(QMap<QString, CICSIntfLib*>*);
				SetDllPoolAction DoSetDllPool = (SetDllPoolAction)m_pDllLib->resolve(METHOD_SETDLLPOOL);
				if(DoSetDllPool) (*DoSetDllPool)(pDllMap);
				printf("Commgr: QLibrary::load( \'%s.dll\' ) is success.\n", dllName);
				return true;
			}
			else
			{
				delete m_pDllLib;
				m_pDllLib = 0;
				printf("Commgr: QLibrary::load( \'%s.dll\' ) is failure!\n", dllName);
				return false;
			}
		}
		else
		{
			printf("Commgr: new QLibrary( \'%s.dll\' ) is failure!\n", dllName);
			return false;
		}
	}

	//ж��DLL
	void UnloadDLL()
	{
		if(m_pDllLib)
		{
			Uninitialize();
			m_pDllLib->unload();
			delete m_pDllLib;
			m_pDllLib = 0;
		}
		m_bInited = false;
	}
	
	//��ȡDLL����Ĳ�������ָ��
	void* GetActionPtr(const char* actionName)
	{
		if(m_pDllLib)
		{
			return m_pDllLib->resolve(actionName);
		}
		return 0;
	}
	
	//ִ��DLL�ĳ�ʼ��������[ֻ���ڳ�ʼ���ɹ���ſ��Խ��з���ʼ��]
	bool Initialize()
	{
		typedef bool (*InitializeAction)();
		InitializeAction DoInitialize = (InitializeAction)GetActionPtr(METHOD_INITIALIZE);
		if(DoInitialize)
		{
			m_bInited = (*DoInitialize)();
			return m_bInited;
		}
		else
		{
			m_bInited = false;
			return true;
		}
	}
	
	//ִ��DLL�ķ���ʼ��������[��һ�γ�ʼ���ɹ��󣬷���ʼ��ֻ��ִ��һ��]
	bool Uninitialize()
	{
		if(m_bInited)
		{
			typedef bool (*UninitializeAction)();
			UninitializeAction DoUninitialize = (UninitializeAction)GetActionPtr(METHOD_UNINITIALZIE);
			if(DoUninitialize)
			{
				bool bUninited = (*DoUninitialize)();
				m_bInited = !bUninited;
				return bUninited;
			}
		}
		return true;
	}
	
protected:
	QLibrary* m_pDllLib;
	
private:
	friend class CICSDllObj;
	bool m_bInited;
	
};

#endif 
