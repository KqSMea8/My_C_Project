//include "statuscheck.h"

#ifndef _STATUSCHECK_FUNCTION_PENGSHIKANG_20131107_H_
#define _STATUSCHECK_FUNCTION_PENGSHIKANG_20131107_H_

#include "statusbase.h" // for STATUSCODE_EXPORT
#include <qstring.h>

//(1)初始化应用软件。
bool STATUSCODE_EXPORT InitStatus(const char* projName, const char* applName);
//(2)进入应用软件。如果已经注册，返回true。否则，若bInput==true则弹出注册框。
bool STATUSCODE_EXPORT IntoStatus(bool bInput=false);
//(3)获取本机的机器码。
bool STATUSCODE_EXPORT GetMachineCode(char* macCode);
//(4)设置用户码。
void STATUSCODE_EXPORT SetRegisterUser(const char* userCode);
//(5)获取用户码。
const QString STATUSCODE_EXPORT GetRegisterUser();
//(6)获得本进程名称
void STATUSCODE_EXPORT GetApplicationNameMs(char* applName);
//(7)验证应用程序的注册码
bool STATUSCODE_EXPORT CheckAppRegCode(const char* product, const char* strSn, const char* strKey);

#endif
