//include "objectcheck.h"

#ifndef _CODECHECK_FUNCTION_PENGSHIKANG_20131107_H_
#define _CODECHECK_FUNCTION_PENGSHIKANG_20131107_H_

#include "objectbase.h" // for OBJECTBASE_EXPORT
#include <qstring.h>

//(1)初始化应用软件。
bool OBJECTBASE_EXPORT InitProject();
//(2)进入应用软件。如果已经注册，返回true。否则，若bInput==true则弹出注册框。
bool OBJECTBASE_EXPORT IntoProject(bool bInput=false);
//(4)设置用户码。
void OBJECTBASE_EXPORT SetObjectbaseUser(const char* userCode);
//(5)获取用户码。
const QString OBJECTBASE_EXPORT GetObjectbaseUser();

#endif
