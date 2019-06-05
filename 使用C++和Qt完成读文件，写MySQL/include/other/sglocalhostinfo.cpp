#include "sglocalhostinfo.h"
#include <stdio.h>
#include <string>
#include <Qt>

#ifdef _MSC_VER
	#include <windows.h>
#else
	#include <stdlib.h>
	#include <dlfcn.h>
	#include <unistd.h>
#endif

#define ICS_MACHINENAME_MAX 64

SGLocalHostInfo* SGLocalHostInfo::m_pInstance = 0;

SGLocalHostInfo* SGLocalHostInfo::Instance()
{
	if(0 == m_pInstance) {
		m_pInstance = new SGLocalHostInfo();
	}
	return m_pInstance;
}

SGLocalHostInfo::SGLocalHostInfo()
{
//
}

SGLocalHostInfo::~SGLocalHostInfo()
{
	if(m_pInstance) {
		delete m_pInstance;
		m_pInstance = 0;
	}
}
/*
	[��  ��]	��ñ����������
	[˵  ��]				
*/	
void SGLocalHostInfo::GetLocalMachine(char* name)
{
	bool bGet = false;

	if(!bGet)
	{
#ifdef _MSC_VER
		DWORD size = ICS_MACHINENAME_MAX;
		GetComputerNameA(name, &size);
#else
		gethostname(name, ICS_MACHINENAME_MAX);
#endif
	}
}

/*
	[��  ��]	��ñ�����ID
	[˵  ��]					
*/	
int SGLocalHostInfo::GetCurrentProcessID()
{
#ifdef _MSC_VER
	return GetCurrentProcessId();
#else
	return getpid();
#endif
}

/*
	[��  ��]	��û�����������ID
	[˵  ��]					
*/	
void SGLocalHostInfo::GetModelName(char* model)
{
	char machine[ICS_MACHINENAME_MAX];
	GetLocalMachine(machine);
	sprintf(model, "%s-%d", machine, GetCurrentProcessID());
}

/*
	[��  ��]	
	[˵  ��]					
*/	
void SGLocalHostInfo::GetPartName(const char* part, char* name)
{
	char model[32];
	GetModelName(model);
	sprintf(name, "%s_%s", model, part);
}

//��ȡ��ǰ������
void SGLocalHostInfo::GetCurrentProcessName(char* name)
{
#ifdef _MSC_VER
	char szFullPath[MAX_PATH];
	::GetModuleFileNameA(NULL, szFullPath, MAX_PATH);
	std::string strPSName(szFullPath);
	int iBegin =  strPSName.rfind("\\", strPSName.length());
	int iEnd = strPSName.rfind(".", strPSName.length());
	strcpy(name, strPSName.substr(iBegin+1, iEnd - iBegin - 1).c_str()); //���ؽ��������������ַ���".exe"
#else 
	//unix version
#endif

}

//�������̼以����
bool SGLocalHostInfo::CreateInterProcMutex(const char* procname, void** ppMtx)
{
#ifdef _MSC_VER
	Qt::HANDLE hMutex = CreateMutexA(0, false, procname);
	if(NULL == hMutex) {
		return false;
	}
	else if( ERROR_ALREADY_EXISTS == GetLastError() )
	{
		CloseHandle(hMutex);
		return false;
	}
	else { 
		*ppMtx = (void*)hMutex;
		return true;
	}
#else 
	//unix version
	return false;
#endif
}

//�ͷŽ��̼以������Դ
void SGLocalHostInfo::ReleaseInterProcMutex(void* pMtx)
{
#ifdef _MSC_VER
	if(!pMtx) return;
	else {
		Qt::HANDLE hMutex = (Qt::HANDLE)pMtx;
		CloseHandle(hMutex);
	}
#else 
	//unix version
#endif
}