//clientctrlresult.h

#ifndef _CLIENTCONTROLRESULT_PENGSHIKANG_2015_07_10_H_
#define _CLIENTCONTROLRESULT_PENGSHIKANG_2015_07_10_H_

#include "clientsender.h"                        // for CCtrlClientSender

//通过消息中心往控制客户端发送控制操作进度信息
class CClientCtrlResult : public CCtrlClientSender
{
public:
	CClientCtrlResult(bool toCenter=true) : CCtrlClientSender(toCenter)
	{
	};
	
	void SetProcessInfo(const char* sReceiver, const unsigned char* procInfo, int length)
	{
		SetReceiverName(sReceiver);
		SetMessagePointer(procInfo, length);
	}
};

#endif
