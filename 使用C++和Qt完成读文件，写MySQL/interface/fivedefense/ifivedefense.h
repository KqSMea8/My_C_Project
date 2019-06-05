//ifivedefense.h
#ifndef _IFIVEDEFENSE_2009_09_18_PENGSHIKANG_INCLUDED_
#define _IFIVEDEFENSE_2009_09_18_PENGSHIKANG_INCLUDED_

#include "../icsunknown.h"              // for IICSUnknown

#define DLL_FIVEDEFENSE           "fivedefense"
#define CLSID_FIVEDEFENSE         "cfivedefense"
#define IID_IFIVEDEFENSE          "ifivedefense"

//对象信息下行接口
class IFiveDefenseCallback;
class IFiveDefense : virtual public IICSUnknown
{
public:
	//服务宿主-注册服务宿主回调接口
	virtual void RegCallback( const char* szApp, IFiveDefenseCallback* pCallBack ) = 0;

	//服务宿主-启动与五防主机通信接口服务
	virtual void StartServer() = 0;
	//服务宿主-终止与五防主机通信接口服务
	virtual void StopServer() = 0;
	//服务宿主-监控主机主备角色切换通知
	virtual void RoleChange(int StatMachine,int StatNet1,int StatNet2) = 0;

	//监控向五防主机发送变化数据
	virtual void SendStatusChange(int nStatusID,int nType,int nValue,bool bManSet) = 0;//单双点值处理
	virtual void SendAnalogChange(int nAnalogID, int nType, short sValue,bool bManSet) = 0;
	//监控请求五防主机解锁
	virtual void SendPrevent (int nStatusID,int nValue,bool bDouble) = 0;

public:
	static char* GetIntfName() {return IID_IFIVEDEFENSE;}
};

//对象信息上行接口
class IFiveDefenseCallback
{
public:
	//五防主机向监控下发解锁令
	virtual void OnPreventControl(int nStatusID, bool bLock, double dt) = 0;
	//监控请求五防主机解锁返回
	virtual void OnPreventBack(int nStatusID,bool bSuccess,double dt) = 0;
	//五防向监控主机发送人工置位信号
	virtual void OnStatusChange(int nStatusID,int value, int quality, double dt) = 0;//单双点值处理
};

#endif
