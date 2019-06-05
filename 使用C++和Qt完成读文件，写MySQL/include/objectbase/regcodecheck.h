//regcodecheck.h

#ifndef __REGISTCODECHECK_PENGSHIKANG_20121206_H__
#define __REGISTCODECHECK_PENGSHIKANG_20121206_H__

#include "../other/icssettingslib.h"             // for CICSSettings
#include "statuscheck.h"                         // for InitStatus()、IntoStatus()
#include "objectcheck.h"                         // for InitProject()、IntoProject()

#ifdef _MSC_VER
	#include <windows.h>	
#else
	#include <stdio.h>
	#include <stdlib.h>
	#include <dlfcn.h>
	#include <unistd.h>
#endif

//获得本进程名称
inline QString GetMyProcessName()
{
	char procName[256];
#ifdef _MSC_VER
	TCHAR tchrPath[256];
	char filePath[256];
	::GetModuleFileName(0, tchrPath, 256);
	wcstombs(filePath, (wchar_t*)tchrPath, 256);
	char* fileName = strrchr(filePath, '\\') + strlen("\\");
	int len = strchr(fileName, '.') - fileName;
	strncpy(procName, fileName, len);
	procName[len] = '\0';
#else
	char procInfo[64], chPath[256];
	sprintf(procInfo, "/proc/%d/exe", getpid());
	int count = readlink(procInfo, chPath, 256);
	if(count >= 0 && count < 256)
	{
		char * cTem = strrchr(chPath, '/');
		if(cTem) strcpy(procName, ++cTem);
		else strcpy(procName, chPath);
	}
#endif
	printf("当前进程名：%s \n", procName);
	return QString(procName);
};

//获得本项目名称
inline bool ReadProjectName(char* projName)
{
	CICSSettings setts;
	IICSSettings* pSets = setts.Self();
	if(!pSets) return false;

	char** appNames; 
	char** appValues;
	int appCount = 0;
	pSets->GetItemList("plat_global/appsystem", appNames, appValues, appCount);
	if(appCount > 0)
	{
		strcpy(projName, appNames[0]);
		return true;
	}
	return false;
};

//获得本注册名称
inline const QString GetRegistName(const char* appName, const char* userCode)
{
	int len0 = strlen(appName);
	int len1 = strlen(userCode);
	int len2 = QMAX(9, len1);
	if(len0 <= 0 || len1 <= 0)
	{
		return "error_null_key";
	}

	unsigned char strKey[9] = { '\0' };
	for(int i = 0; i < len2; ++i)
	{
		strKey[i%9] = strKey[i%9] ^ appName[i%len0] ^ userCode[i%len1];
	}

	return QString("%1%2%3%4%5%6%7%8%9")
		.arg(strKey[0], 2, 36)
		.arg(strKey[1], 2, 36)
		.arg(strKey[2], 2, 36)
		.arg(strKey[3], 2, 36)
		.arg(strKey[4], 2, 36)
		.arg(strKey[5], 2, 36)
		.arg(strKey[6], 2, 36)
		.arg(strKey[7], 2, 36)
		.arg(strKey[8], 2, 36)
		.replace(' ', '#');
}

//获得本对象库名称
inline const QString GetObjectName(const char* appName, const char* userCode)
{
#ifdef _MSC_VER
	return GetRegistName(appName, userCode);
#else
	return QString(userCode).append(", ").append(appName).append("_objectbase is not proofed by register_code!");
#endif
}

//验证注册软件是否正确
inline bool IsCorrectChecklib(const char* appName, const char* userCode)
{
	char projName[32] = "smg8000";//{ 0 };
	if(!ReadProjectName(projName)) return false;
	InitStatus(projName, appName);
	SetRegisterUser(userCode);
	QString regName = GetRegisterUser();
	QString makName = GetRegistName(appName, userCode);
	return (makName == regName);
}

//验证对象基类软件是否正确
inline bool IsCorrectObjectlib(const char* appName, const char* userCode)
{
	if(!InitProject()) return false;
	SetObjectbaseUser(userCode);
	QString regName = GetObjectbaseUser();
	QString makName = GetObjectName(appName, userCode);
	return (makName == regName);
}

#endif
