//imystatuscode.h

#ifndef __IMYSTATUSCODE_REGISTCODECHECK_PENGSHIKANG_20131106_H__
#define __IMYSTATUSCODE_REGISTCODECHECK_PENGSHIKANG_20131106_H__

#include "icsunknown.h"              // for IICSUnknown
#include <qstring.h>

#define DLL_MYSTATUSCODE           "proofregcode"
#define CID_MYSTATUSCODE           "cmystatuscode"
#define IID_MYSTATUSCODE           "imystatuscode"

class IMyStatusCode : virtual public IICSUnknown
{
public:
	//(1)��ʼ��Ӧ�����
	virtual bool InitApplication(const char* projName, const char* applName = 0) = 0;
	//(2)����Ӧ�����������Ѿ�ע�ᣬ����true��������bInput==true�򵯳�ע���
	virtual bool IntoApplication(bool bInput = false) = 0;
	//(3)��ȡ�����Ļ����롣
	virtual bool GetMachineCode(char* macCode) = 0;
	//(4)�����û��롣
	virtual void SetUserCode(const char* userCode) = 0;
	//(5)��ȡ�û��롣
	virtual const QString& GetUserCode() = 0;
	//(6)��ȡ������MAC��ַ��
	//virtual int GetMacAddress(unsigned char macAddr[128]) = 0;
};

#endif
