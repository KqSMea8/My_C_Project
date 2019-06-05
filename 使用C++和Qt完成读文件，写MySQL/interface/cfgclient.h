#ifndef CFGMAN_CLIENT_H
#define CFGMAN_CLIENT_H

#ifdef _MSC_VER
	#ifdef CFGCLIENT_EXPORT
		#define CFGCLIENT_API __declspec(dllexport)
	#else
		#define CFGCLIENT_API __declspec(dllimport)
	#endif
#else
	#define CFGCLIENT_API
#endif

#define REGISTER_NAME_LENGTH 32

typedef enum
{
    CFGSRV_ROLE_UNKNOWN = 1, //未知的角色
    CFGSRV_ROLE_ENABLED,     //主用角色
    CFGSRV_ROLE_STANDBY,     //备用角色
    CFGSRV_ROLE_DISABLED     //不可用角色
} CFGSRV_ROLE;
/*
 *	1 UNKNOWN,2 ENABLED,3 STANDBY,4 DISABLED
 */

typedef void (*CONFIG_CALLBACK_STATCHANGE) (int role);

extern "C"
{
	//进程调用的接口，注册自己在cfgctrl数据库中配置的进程名
	//长度不超过12,长度超过12或 重复初始化返回false
	CFGCLIENT_API bool CfgClientInit(const char* process_name);

	//以模块名来注册角色分配客户端,模块名最大长度是32，超过会被截断
	CFGCLIENT_API void CfgRegisterCallBack(const char* registerName,CONFIG_CALLBACK_STATCHANGE pState);
	//模块registerName停止接受角色分配
	CFGCLIENT_API void StopCfgClient(const char* registerName);
	//打印当前进程的所有注册信息，可选使用
	CFGCLIENT_API void DumpInfo();
}

#endif
