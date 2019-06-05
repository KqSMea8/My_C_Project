//chgmscender.h                                  // for CChgMscSender

#ifndef _CHARGESTATIONMESSAGESENDER_PENGSHIKANG_2017_04_26_H_
#define _CHARGESTATIONMESSAGESENDER_PENGSHIKANG_2017_04_26_H_

#include "../../../interface/imscclient.h"       // for IMSCClient
#include "../../../interface/msc_res.h"          // for MSC_PTYPE、FD_MSC_MSGT
#include "../msgtypedef.h"                       // for CControlMsg
#include "../streamaccess.h"                     // for CStreamAccess
#include <string.h>

//消息数据通过消息中心往其他服务程序发送
class CChgMscSender
{
public:
	CChgMscSender(bool toCenter, MSC_MSGT msgClass)
	{
		if(toCenter)
			m_nReceiverType = static_cast<long>(MSC_PTYPE_TESTMODULE);//汽车充电站
		else
			m_nReceiverType = static_cast<long>(MSC_PTYPE_DATAPROC);//smgserver
		
		m_msg.nType = (unsigned short)msgClass;
		m_msg.nLevel = 1;
		m_msg.nLength = 0;
		m_msg.pBuf = 0;
	}
	
	virtual ~CChgMscSender()
	{
		if(m_msg.pBuf) delete []m_msg.pBuf;
	}
	
	bool Send(IMSCClient* pMscClient)
	{
		if(!pMscClient || !m_msg.pBuf) return false;
		return pMscClient->Post(&m_msg, By_PartType, m_nReceiverType, 10000);//psk 待改造
	}
	
protected:
	void InitMessageHead(CControlMsg::MsgGroup msgGroup, CControlMsg::MsgType msgType, long msgLen)
	{
		m_msgLen = msgLen + 2;
		m_msg.nLength = m_msgLen;
		m_msg.pBuf = new unsigned char[m_msgLen];
		memset(m_msg.pBuf, 0, m_msg.nLength);
		m_stream.SetBuffer(m_msg.pBuf);
		m_stream.WriteBYTE(msgGroup);
		m_stream.WriteBYTE(msgType);
	}

	bool SetMessageLength(long msgLen)
	{
		if(msgLen <= m_msgLen)
		{
			m_msg.nLength = m_msgLen;
			return true;
		}
		return false;
	}

protected:
	CStreamAccess m_stream;

private:
	TMSCMES m_msg;
	long m_msgLen;
	long m_nReceiverType;
};

#endif
