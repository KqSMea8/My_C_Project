//controlrequest.h

#ifndef _CONTROLINFOREQUEST_PENGSHIKANG_2011_08_09_H_
#define _CONTROLINFOREQUEST_PENGSHIKANG_2011_08_09_H_

#include "mscdatacontrol.h"                      // for CMscDataControl

//�����ң�����ݴ���������˹���λ�ź�
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
		m_stream.WriteInt(nID);   //������ID
		m_stream.WriteInt(nValue);//���Ƶ�����ֵ��Ŀ��ֵ
		m_stream.WriteBYTE(bAuto);//1----ѡ����ɹ�ʱ�ɺ�ֱ̨���·�ִ���0----ѡ����ɹ�ʱ�ɺ�̨�����ȶ�����ִ�л���������
		m_stream.WriteBYTE(bCtrlVal);//1----����nValue��ʾ���Ƶ�����ֵ��   0----����nValue��ʾ���ƹ������ĵ�Ŀ��ֵ
	}
	
};

#endif
