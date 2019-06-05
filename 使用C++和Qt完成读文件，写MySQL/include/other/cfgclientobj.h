// cfgclientobj.h: implement for the CCfgClientObj class.
#ifndef _CFGCLIENTOBJ_2008_02_20_PENGSHIKANG_H_
#define _CFGCLIENTOBJ_2008_02_20_PENGSHIKANG_H_

#include "../commgr/icsdllobj.h"            // for CICSDllObj
#include "../../interface/cfgclient.h"      // for CONFIG_CALLBACK_STATCHANGE

#define MODULE_CFGCLIENT		"cfgclient"

//DLL输出的接口对象引用
class CCfgClientObj : public CICSDllObj
{
public:
	CCfgClientObj() : CICSDllObj(MODULE_CFGCLIENT) { }
	
	/** 对当前进程模块，注册自己在cfgctrl数据库中配置的进程名。进程名长度不超过12。
		进程名长度超过12 或重复调用该函数，则返回false。 **/
	bool CfgClientInit(const char* processName)
	{
		typedef bool (*CfgClientInitMethod)(const char*);
		CfgClientInitMethod DoCfgClientInit = (CfgClientInitMethod)GetActionPtr("CfgClientInit");
		if(DoCfgClientInit)
			return DoCfgClientInit(processName);
		return false;
	}
	
	//对当前DLL模块注册角色分配客户端。注册的模块名最大长度是32，长度超过会被截断。
	bool CfgRegisterCallBack(const char* registerName, CONFIG_CALLBACK_STATCHANGE pState)
	{
		if(pState != 0)
		{
			typedef void (*CfgRegisterCallBackMethod)(const char*, CONFIG_CALLBACK_STATCHANGE);
			CfgRegisterCallBackMethod DoCfgRegisterCallBack = (CfgRegisterCallBackMethod)GetActionPtr("CfgRegisterCallBack");
			if(DoCfgRegisterCallBack)
			{
				DoCfgRegisterCallBack(registerName, pState);
				return true;
			}
		}
		return false;
	}

	//对当前进程模块注册角色分配客户端。注册的进程名最大长度是12，长度超过则注册失败。
	bool RegisterCfgClient(const char* registerName, CONFIG_CALLBACK_STATCHANGE pState)
	{
		if(pState && CfgClientInit(registerName))
			return CfgRegisterCallBack(registerName, pState);
		return false;
	}

	//模块registerName停止接受角色分配。可用于DLL模块和进程模块。
	void StopCfgClient(const char* registerName)
	{
		typedef void (*StopCfgClientMethod)(const char*);
		StopCfgClientMethod DoStopCfgClient = (StopCfgClientMethod)GetActionPtr("StopCfgClient");
		if(DoStopCfgClient) DoStopCfgClient(registerName);
	}

	//打印当前进程模块的所有注册信息。
	void DumpInfo()
	{
		typedef void (*DumpInfoMethod)();
		DumpInfoMethod DoDumpInfo = (DumpInfoMethod)GetActionPtr("DumpInfo");
		if(DoDumpInfo) DoDumpInfo();
	}

};
	
#endif 
