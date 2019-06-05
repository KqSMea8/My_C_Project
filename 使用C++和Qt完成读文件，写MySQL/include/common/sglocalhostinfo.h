#ifndef __SGLOCALHOSTINFO_H_20080428 
#define __SGLOCALHOSTINFO_H_20080428

#include <stdio.h>
#include <string>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <stdlib.h>
#include <dlfcn.h>
#include <unistd.h>
#endif

#define ICS_MACHINENAME_MAX 64

/*
 * ������Ϣʵ����
 */
class SGLocalHostInfo
{
public:
	//��ñ����������
	static void GetLocalMachine(char* name)
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
	
	//��ñ�����ID
	static int GetCurrentProcessID()
	{
#ifdef _MSC_VER
		return GetCurrentProcessId();
#else
		return getpid();
#endif
	}
	
	//��û�����������ID
	static void GetModelName(char* model)						//��ʽ��"������-����ID"
	{
		char machine[ICS_MACHINENAME_MAX];
		GetLocalMachine(machine);
		sprintf(model, "%s-%d", machine, GetCurrentProcessID());
	}
	
	//��û�����������ID�����Ӳ���
	static void GetPartName(const char* part, char* name)		//$name = $ModelName_$part
	{
		char model[32];
		GetModelName(model);
		sprintf(name, "%s_%s", model, part);
	}
	
	//��ȡ��ǰ������
	static void GetCurrentProcessName(char* name)
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
	static bool CreateInterProcMutex(const char* procname, void** ppMtx)	
	{
#ifdef _MSC_VER
		HANDLE hMutex = CreateMutexA(0, false, procname);
		if(NULL == hMutex)
		{
			return false;
		}
		else if( ERROR_ALREADY_EXISTS == GetLastError() )
		{
			CloseHandle(hMutex);
			return false;
		}
		else
		{ 
			*ppMtx = (void*)hMutex;
			return true;
		}
#else 
		//unix version
		return false;
#endif
	}
	
	//�ͷŽ��̼以������Դ
	static void ReleaseInterProcMutex(void* pMtx)							
	{
#ifdef _MSC_VER
		if(!pMtx) return;
		else {
			HANDLE hMutex = (HANDLE)pMtx;
			CloseHandle(hMutex);
		}
#else 
		//unix version
#endif
	}

};

#endif