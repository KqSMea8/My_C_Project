// dataproxylib.h: implement for the CTaskIndexLib class.
#ifndef _DATAPROXYLIB_2008_06_12_PENGSHIKANG_H_
#define _DATAPROXYLIB_2008_06_12_PENGSHIKANG_H_

#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB
#include "../../interface/idataproxy.h" // for IDataProxyApp

#define APPID_SCADAPROC           20
#define APPID_STATUSPROC           1
#define APPID_ANALOGPROC           2
#define APPID_ACCUMUPROC           3
#define APPID_CONTROL              4
#define APPID_CSFCONFIG            5
#define APPID_SOEPROC              6
#define APPID_FAULTPROC            7

//DLL输出的接口对象引用
class CDataProxy : public CIntfObjPtrB<IDataProxyApp>
{
public:
	CDataProxy() : CIntfObjPtrB<IDataProxyApp>(
		DLL_DATAPROXY, false, CID_DATAPROXY, IID_DATAPROXY)
	{
		this->m_pObj = CreateObject();
	}

	CDataProxy(CSF_UINT8 nAppId, IDataProxyCallback* pUser, CSF_UINT32 count=0, CSF_UINT8 dataTypes[]=0) 
		: CIntfObjPtrB<IDataProxyApp>(DLL_DATAPROXY, false, CID_DATAPROXY, IID_DATAPROXY)
	{
		m_pParams[0] = &nAppId;     //客户端模块标识
		m_pParams[1] = pUser;       //用户指针
		m_pParams[2] = &count;      //订阅的数据类型个数
		m_pParams[3] = dataTypes;   //订阅的数据类型数组
		this->m_pObj = CreateObject(m_pParams);
	}
	
	//创建一个新的接口对象保留
	IDataProxyApp* CreateDataProxy()
	{
		return CreateObject(m_pParams);
	}

private:
	void* m_pParams[8];
};

#endif 
