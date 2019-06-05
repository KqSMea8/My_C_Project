//mscdatasender_his.h                            // for CHisSaveSender

#ifndef _HISSAVESENDER_PENGSHIKANG_2015_07_09_H_
#define _HISSAVESENDER_PENGSHIKANG_2015_07_09_H_

#include "../../../interface/imscclient.h"       // for IMSCClient
#include "../../../interface/msc_res.h"          // for MSC_PTYPE、FD_MSC_MSGT
#include "../msgtypedef.h"                       // for CControlMsg
#include "../streamaccess.h"                     // for CStreamAccess
#include <string.h>

//消息数据通过消息中心往其他服务程序发送
class CHisSaveSender
{
public:
	CHisSaveSender(bool toCenter, MSC_MSGT msgClass)
	{
		if(toCenter)
			m_nReceiverType = static_cast<long>(MSC_PTYPE_HISSTRAGY);//hisstragy
		else
			m_nReceiverType = static_cast<long>(MSC_PTYPE_DATAPROC);//smgserver
		
		m_msg.nType = (unsigned short)msgClass;
		m_msg.nLevel = 1;
		m_msg.nLength = 0;
		m_msg.pBuf = 0;
	}
	
	virtual ~CHisSaveSender()
	{
		if(m_msg.pBuf) delete []m_msg.pBuf;
	}
	
	bool Send(IMSCClient* pMscClient)
	{
		if(!pMscClient || !m_msg.pBuf) return false;
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
	}

protected:
	CStreamAccess m_stream;

private:
	TMSCMES m_msg;
	long m_nReceiverType;
};

#endif
