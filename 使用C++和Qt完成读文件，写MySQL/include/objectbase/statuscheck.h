//include "statuscheck.h"

#ifndef _STATUSCHECK_FUNCTION_PENGSHIKANG_20131107_H_
#define _STATUSCHECK_FUNCTION_PENGSHIKANG_20131107_H_

#include "statusbase.h" // for STATUSCODE_EXPORT
#include <qstring.h>

//(1)��ʼ��Ӧ�������
bool STATUSCODE_EXPORT InitStatus(const char* projName, const char* applName);
//(2)����Ӧ�����������Ѿ�ע�ᣬ����true��������bInput==true�򵯳�ע���
bool STATUSCODE_EXPORT IntoStatus(bool bInput=false);
//(3)��ȡ�����Ļ����롣
bool STATUSCODE_EXPORT GetMachineCode(char* macCode);
//(4)�����û��롣
void STATUSCODE_EXPORT SetRegisterUser(const char* userCode);
//(5)��ȡ�û��롣
const QString STATUSCODE_EXPORT GetRegisterUser();
//(6)��ñ���������
void STATUSCODE_EXPORT GetApplicationNameMs(char* applName);
//(7)��֤Ӧ�ó����ע����
bool STATUSCODE_EXPORT CheckAppRegCode(const char* product, const char* strSn, const char* strKey);

#endif
