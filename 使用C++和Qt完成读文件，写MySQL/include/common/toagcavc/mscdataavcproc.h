//mscdataavcproc.h

#ifndef _MSCDATAAVCPROC_PENGSHIKANG_2015_11_12_H_
#define _MSCDATAAVCPROC_PENGSHIKANG_2015_11_12_H_

#include "agcavcsender.h"                        // for CAgcAvcSender

//��Ϣ����ͨ����Ϣ�������������������
class CMscDataAvcProc : public CAgcAvcSender
{
public:
	CMscDataAvcProc(IMSCClient* pMscClient, bool toCenter=true) : CAgcAvcSender(toCenter, AUTO_CTRL_MSGT, pMscClient)
	{
		InitMessageHead(CControlMsg::GroupStrategyAVC, 265);
	};
};

#endif
