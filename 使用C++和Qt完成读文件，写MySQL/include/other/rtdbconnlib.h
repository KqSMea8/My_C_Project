// rtdblib.h: implement for the CRtdbConn class.
#ifndef _RTDBINTFLIB_2007_12_24_PENGSHIKANG_H_
#define _RTDBINTFLIB_2007_12_24_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"                // for CIntfObjPtr
#include "../../interface/rtdbintf.h"            // for IRTDBConnection

#define MODULE_RTDBINTF			"rtdbintf"
#define METHOD_CREATECONNECTION "CreateRtdbConnection" // int CreateRtdbConnection(IRTDBConnection** ppConn);

//DLL输出的接口对象引用
class CRtdbConn : public CIntfObjPtr<IRTDBConnection>
{
public:
	CRtdbConn() : CIntfObjPtr<IRTDBConnection>(MODULE_RTDBINTF, false)
	{
		this->m_pObj = CreateObject();
	}
	
	virtual ~CRtdbConn()
	{
		FreeIntf();
	}
	
	//处理父类：创建一个新的DLL输出接口类对象指针。
	IRTDBConnection* CreateObject(void*[]=0) 
	{
		IRTDBConnection* pObj = 0;
		typedef int (*CreateConnectionMethod)(IRTDBConnection**);
		CreateConnectionMethod DoCreateConn = (CreateConnectionMethod)GetActionPtr(METHOD_CREATECONNECTION);
		if(DoCreateConn) DoCreateConn(&pObj);
		return pObj;
	}
	
	//处理父类：释放DLL输出接口类对象指针。
	virtual void FreeObject(IRTDBConnection** ppObj)
	{
		if(ppObj && *ppObj)
		{
			IRTDBConnection* pConn = (IRTDBConnection*)*ppObj;
			pConn->Disconnect();
			pConn->Release();
			*ppObj = 0;
		}
	}
	
};
	
#endif 
