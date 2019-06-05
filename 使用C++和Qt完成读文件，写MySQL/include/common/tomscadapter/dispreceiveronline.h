//dispreceiveronline.h

#ifndef _DISPATCHRECEIVERONLINE_PENGSHIKANG_2015_07_17_H_
#define _DISPATCHRECEIVERONLINE_PENGSHIKANG_2015_07_17_H_

#include "mscdatagcsetvalue.h"                   // for CMscDatAgcSetvalue
#include "../../../interface/scadasrv/dispatchtaskdata.h"  // for DispatchTaskData

//������Ϣ����ͨ����Ϣ���ķ������ȶ�
class CDispReceiverOnline : public CMscDatAgcSetvalue
{
public:
	CDispReceiverOnline(bool toCenter=true) : CMscDatAgcSetvalue(toCenter, 2)
	{
		SetTaskValue();
	};

private:
	void SetTaskValue()
	{
		m_stream.SkipAfter(2, false);//30��10
		m_stream.WriteShort(0);//0--���ݴ����������
	};
};

#endif
