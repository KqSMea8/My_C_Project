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
 * 主机信息实用类
 */
class SGLocalHostInfo
{
public:
	//获得本计算机名称
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
	
	//获得本进程ID
	static int GetCurrentProcessID()
	{
#ifdef _MSC_VER
		return GetCurrentProcessId();
#else
		return getpid();
#endif
	}
	
	//获得机器名＋进程ID
	static void GetModelName(char* model)						//格式："机器名-进程ID"
	{
		char machine[ICS_MACHINENAME_MAX];
		GetLocalMachine(machine);
		sprintf(model, "%s-%d", machine, GetCurrentProcessID());
	}
	
	//获得机器名＋进程ID＋附加部分
	static void GetPartName(const char* part, char* name)		//$name = $ModelName_$part
	{
		char model[32];
		GetModelName(model);
		sprintf(name, "%s_%s", model, part);
	}
	
	//获取当前进程名
	static void GetCurrentProcessName(char* name)
	{
#ifdef _MSC_VER
		char szFullPath[MAX_PATH];
		::GetModuleFileNameA(NULL, szFullPath, MAX_PATH);
		std::string strPSName(szFullPath);
		int iBegin =  strPSName.rfind("\\", strPSName.length());
		int iEnd = strPSName.rfind(".", strPSName.length());
		strcpy(name, strPSName.substr(iBegin+1, iEnd - iBegin - 1).c_str()); //返回进程名，不包含字符串".exe"
#else 
		//unix version
#endif
	}
	
	//创建进程间互斥锁
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
	
	//释放进程间互斥锁资源
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