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
	//(1)初始化应用软件
	virtual bool InitApplication(const char* projName, const char* applName = 0) = 0;
	//(2)进入应用软件。如果已经注册，返回true。否则，若bInput==true则弹出注册框。
	virtual bool IntoApplication(bool bInput = false) = 0;
	//(3)获取本机的机器码。
	virtual bool GetMachineCode(char* macCode) = 0;
	//(4)设置用户码。
	virtual void SetUserCode(const char* userCode) = 0;
	//(5)获取用户码。
	virtual const QString& GetUserCode() = 0;
	//(6)获取本机的MAC地址。
	//virtual int GetMacAddress(unsigned char macAddr[128]) = 0;
};

#endif
