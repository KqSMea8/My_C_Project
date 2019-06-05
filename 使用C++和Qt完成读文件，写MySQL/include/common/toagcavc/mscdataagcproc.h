//mscdataagcproc.h

#ifndef _MSCDATAAGCPROC_PENGSHIKANG_2015_11_12_H_
#define _MSCDATAAGCPROC_PENGSHIKANG_2015_11_12_H_

#include "agcavcsender.h"                        // for CAgcAvcSender

//��Ϣ����ͨ����Ϣ�������������������
class CMscDataAgcProc : public CAgcAvcSender
{
public:
	CMscDataAgcProc(IMSCClient* pMscClient, bool toCenter=true) : CAgcAvcSender(toCenter, AUTO_CTRL_MSGT, pMscClient)
	{
		InitMessageHead(CControlMsg::GroupStrategyAGC, 265);
	};
};

#endif
