//mscdataavcproc.h

#ifndef _MSCDATAAVCPROC_PENGSHIKANG_2015_11_12_H_
#define _MSCDATAAVCPROC_PENGSHIKANG_2015_11_12_H_

#include "agcavcsender.h"                        // for CAgcAvcSender

//消息数据通过消息中心往其他服务程序发送
class CMscDataAvcProc : public CAgcAvcSender
{
public:
	CMscDataAvcProc(IMSCClient* pMscClient, bool toCenter=true) : CAgcAvcSender(toCenter, AUTO_CTRL_MSGT, pMscClient)
	{
		InitMessageHead(CControlMsg::GroupStrategyAVC, 265);
	};
};

#endif
