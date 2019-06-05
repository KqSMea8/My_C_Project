//controlrequest.h

#ifndef _CONTROLINFOREQUEST_PENGSHIKANG_2011_08_09_H_
#define _CONTROLINFOREQUEST_PENGSHIKANG_2011_08_09_H_

#include "mscdatacontrol.h"                      // for CMscDataControl

//五防向遥测数据处理服务发送人工置位信号
class CControlRequest : public CMscDataControl
{
public:
	CControlRequest(bool toCenter=false) : CMscDataControl(toCenter)
	{
		/* int(ctrlID) | int(ctrlValue) | uchar(bAuto) | uchar(bCtrlVal): size=10 */
		InitMessageHead(CControlMsg::RequestForCtrlVal, 10);
	}
	
	void SetControlRequInfo(int nID, int nValue, BYTE bAuto, BYTE bCtrlVal=1)//(1)
	{
		m_stream.SkipAfter(2, false);
		m_stream.WriteInt(nID);   //控制量ID
		m_stream.WriteInt(nValue);//控制的命令值或目标值
		m_stream.WriteBYTE(bAuto);//1----选控令成功时由后台直接下发执行令；0----选控令成功时由后台往调度端征求“执行或撤消”请求。
		m_stream.WriteBYTE(bCtrlVal);//1----参数nValue表示控制的命令值；   0----参数nValue表示控制关联测点的的目标值
	}
	
};

#endif
