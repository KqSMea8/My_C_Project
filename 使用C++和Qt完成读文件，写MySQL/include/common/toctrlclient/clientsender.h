//clientsender.h                                 // for CCtrlClientSender

#ifndef _CONTROLCLIENTSENDER_PENGSHIKANG_2015_07_10_H_
#define _CONTROLCLIENTSENDER_PENGSHIKANG_2015_07_10_H_

#include "../../../interface/imscclient.h"       // for IMSCClient
#include "../../../interface/msc_res.h"          // for MSC_PTYPE、FD_MSC_MSGT
#include "../msgtypedef.h"                       // for CControlMsg
#include "../streamaccess.h"                     // for CStreamAccess
#include <string.h>

//通过消息中心往控制客户端发送信息
class CCtrlClientSender
{
public:
	CCtrlClientSender(bool toCenter)
	{
		if(toCenter)
			m_nReceiverType = static_cast<long>(MSC_PTYPE_CTRLCLIENT);//ctrlclient
		else
			m_nReceiverType = static_cast<long>(MSC_PTYPE_DATAPROC);//smgserver
		
		m_msg.nType = CTRL_MSC_MSGT;
		m_msg.nLevel = 1;
		m_msg.nLength = 0;
		m_msg.pBuf = 0;
		m_bNewBuf = false;
		m_byName = false;
	}
	
	virtual ~CCtrlClientSender()
	{
		if(m_bNewBuf) delete []m_msg.pBuf;
	}

	bool Send(IMSCClient* pMscClient)
	{
		if(!pMscClient || !m_msg.pBuf) return false;
		if(m_byName)
			return pMscClient->Post(&m_msg, By_PartName, (long)m_sReceiver, 4000);
		else
			return pMscClient->Post(&m_msg, By_PartType, m_nReceiverType, 10000);
	}
	
protected:
	void InitMessageHead(CControlMsg::MsgGroup msgGroup, CControlMsg::MsgType msgType, long msgLen)
	{
		m_msg.nLength = msgLen + 2;
		m_msg.pBuf = new unsigned char[m_msg.nLength];
		memset(m_msg.pBuf, 0, m_msg.nLength);
		m_stream.SetBuffer(m_msg.pBuf);
		m_stream.WriteBYTE(msgGroup);
		m_stream.WriteBYTE(msgType);
		m_bNewBuf = true;
	}

	void SetMessagePointer(const unsigned char* content, int length)
	{
		m_msg.nLength = length;
		m_msg.pBuf = (unsigned char*)content;
		m_bNewBuf = false;
	}

	void SetReceiverName(const char* sReceiver = 0)
	{
		if(sReceiver)
		{
			m_byName = true;
			strncpy(m_sReceiver, sReceiver, 127);
			m_sReceiver[127] = '\0';
		}
		else
		{
			m_byName = false;
		}
	}

protected:
	CStreamAccess m_stream;

private:
	TMSCMES m_msg;
	bool m_bNewBuf;
	bool m_byName;
	long m_nReceiverType;
	char m_sReceiver[128];
};

#endif
