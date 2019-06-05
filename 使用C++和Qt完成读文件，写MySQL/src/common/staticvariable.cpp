#include "staticvariable.h"
#include <string>

#ifdef _MSC_VER
#include <windows.h>
#else 
#include <unistd.h>	 //Unix
#endif

//��ʷ������
DB g_Model;
DB g_His1;
DB g_His2;

//���ݿ�����
QSqlDatabase g_pDB_His1;
//���ݿ�����
QSqlDatabase g_pDB_His2;
//���ÿ�����
QSqlDatabase g_pDB_Model;

QString g_dbdriver;

//����Ϊ��λ˯��һ��ʱ��
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