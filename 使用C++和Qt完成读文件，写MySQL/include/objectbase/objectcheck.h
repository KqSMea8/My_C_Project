//include "objectcheck.h"

#ifndef _CODECHECK_FUNCTION_PENGSHIKANG_20131107_H_
#define _CODECHECK_FUNCTION_PENGSHIKANG_20131107_H_

#include "objectbase.h" // for OBJECTBASE_EXPORT
#include <qstring.h>

//(1)��ʼ��Ӧ�������
bool OBJECTBASE_EXPORT InitProject();
//(2)����Ӧ�����������Ѿ�ע�ᣬ����true��������bInput==true�򵯳�ע���
bool OBJECTBASE_EXPORT IntoProject(bool bInput=false);
//(4)�����û��롣
void OBJECTBASE_EXPORT SetObjectbaseUser(const char* userCode);
//(5)��ȡ�û��롣
const QString OBJECTBASE_EXPORT GetObjectbaseUser();

#endif
