//avcagcsender.h                                 // for CAgcAvcSender

#ifndef _AVCAGCSENDER_PENGSHIKANG_2015_11_12_H_
#define _AVCAGCSENDER_PENGSHIKANG_2015_11_12_H_

#include "../../../interface/imscclient.h"       // for IMSCClient
#include "../../../interface/msc_res.h"          // for MSC_PTYPE、FD_MSC_MSGT
#include "../../objectbase/datetime.h"           // for CDateTime
#include "../msgtypedef.h"                       // for CControlMsg
#include "../streamaccess.h"                     // for CStreamAccess
#include <string.h>

//消息数据通过消息中心往其他服务程序发送
class CAgcAvcSender
{
public:
	CAgcAvcSender(bool toCenter, MSC_MSGT msgClass, IMSCClient* pMscClient)
	{
		if(toCenter)
			m_nReceiverType = static_cast<long>(MSC_PTYPE_STRATEGYSHOW);//agc/avc
		else
			m_nReceiverType = static_cast<long>(MSC_PTYPE_DATAPROC);//smgserver
		
		m_msg.nType = (unsigned short)msgClass;
		m_msg.nLevel = 1;
		m_msg.nLength = 0;
		m_msg.pBuf = 0;
		m_pMscClient = pMscClient;
	}
	
	virtual ~CAgcAvcSender()
	{
		if(m_msg.pBuf) delete []m_msg.pBuf;
	}

	void SendInfo(const char* content)
	{
		SetInfo(content);
		Send();
	}
	
protected:
	void InitMessageHead(CControlMsg::MsgGroup msgGroup, long msgLen)
	{
		m_msg.nLength = msgLen + 1;
		m_msg.pBuf = new unsigned char[m_msg.nLength];
		memset(m_msg.pBuf, 0, m_msg.nLength);
		m_stream.SetBuffer(m_msg.pBuf);
		m_stream.WriteBYTE(msgGroup);
	}

	void SetInfo(const char* content)
	{
		m_stream.SkipAfter(1, false);
		double curTime = (double)CDateTime::GetCurrentDateTime();
		m_stream.WriteDouble(curTime);
		m_stream.WriteString(content);
	}

	bool Send()
	{
		if(!m_msg.pBuf) return false;
		return m_pMscClient && m_pMscClient->Post(&m_msg, By_PartType, m_nReceiverType, 10000);
	}

protected:
	CStreamAccess m_stream;
	IMSCClient* m_pMscClient;

private:
	TMSCMES m_msg;
	long m_nReceiverType;
};

#endif
