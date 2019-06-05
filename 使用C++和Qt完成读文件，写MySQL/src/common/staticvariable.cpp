#include "staticvariable.h"
#include <string>

#ifdef _MSC_VER
#include <windows.h>
#else 
#include <unistd.h>	 //Unix
#endif

//历史库配置
DB g_Model;
DB g_His1;
DB g_His2;

//数据库连接
QSqlDatabase g_pDB_His1;
//数据库连接
QSqlDatabase g_pDB_His2;
//配置库连接
QSqlDatabase g_pDB_Model;

QString g_dbdriver;

//以秒为单位睡眠一段时间
void SleepInSecond(int sec)
{
#ifdef _MSC_VER
	Sleep(sec*1000);
#else 
	sleep(sec);	 //Unix 1 millisecond
#endif
};

SysConfig g_sysModel;

bool g_bIsDebug;