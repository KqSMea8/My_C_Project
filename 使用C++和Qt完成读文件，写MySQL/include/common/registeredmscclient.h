//registeredmscclient.h

#ifndef _REGISTEREDMSCCLIENT_PENGSHIKANG_2009_10_13_H_
#define _REGISTEREDMSCCLIENT_PENGSHIKANG_2009_10_13_H_

#include "../other/msclientobj.h"                // for CMscClientObj
#include "sglocalhostinfo.h"                     // for SGLocalHostInfo

static unsigned int g_nProcessNo = 0;

//创建已登录的消息中心客户端
class CRegisteredMscClient
{
public:
	//创建已登录的消息中心客户端
	static IMSCClient* CreateMSCClient(IMSCClientCallBack* pCallBack, const char* sProcessName, 
		unsigned short nModuleType, long nMesTypeNum, unsigned short* pMesTypes)
	{
		char psModel[64], psMachine[64], cliName[256];
		SGLocalHostInfo::GetModelName(psModel);
		SGLocalHostInfo::GetLocalMachine(psMachine);
		//sprintf(cliName, "%s_%s", psMachine, sProcessName);
		sprintf(cliName, "%s_%s_%03d", psMachine, sProcessName, ++g_nProcessNo);
		return CMSClientObj::CreateRegisteredMSCClient(pCallBack, 
			psModel, cliName, nModuleType, nMesTypeNum, pMesTypes);
	}

	//删除消息中心客户端
	static void DeleteMSCClient(IMSCClient* pMscClient)
	{
		CMSClientObj::FreeMSCClient(&pMscClient);
	}

protected:
	CRegisteredMscClient();
	virtual ~CRegisteredMscClient();

};

#endif
