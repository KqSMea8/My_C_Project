// onlineupdateuser.h: implement for the COnlineUpdateUser class.
#ifndef _ONLINEUPDATEUSER_2008_11_04_PENGSHIKANG_H_
#define _ONLINEUPDATEUSER_2008_11_04_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"               // for CIntfObjPtr
#include "../../interface/onlineupdateclient.h" // for OnlineUpdateClient

#define MODULE_ONLINEUPDATECLIENT	"onlineupdateclient"
#define METHOD_GETONLINEUPDATEUSER	"GetOnlineUpdateInterface" // OnlineUpdateClient* GetOnlineUpdateInterface();

//DLL输出的接口对象引用
class COnlineUpdateUser : public CIntfObjPtr<OnlineUpdateClient>
{
public:
	COnlineUpdateUser() : CIntfObjPtr<OnlineUpdateClient>(MODULE_ONLINEUPDATECLIENT)
	{
		this->m_pObj = CreateObject();
	}

	~COnlineUpdateUser()
	{
		FreeIntf();
	}
	
	//处理父类：创建在线更新客户
	virtual OnlineUpdateClient* CreateObject(void*[]=0)
	{
		typedef OnlineUpdateClient* (*GetUpdateUserMethod)();
		GetUpdateUserMethod DoGetUpdateUser = (GetUpdateUserMethod)GetActionPtr(METHOD_GETONLINEUPDATEUSER);
		if(DoGetUpdateUser)
		{
			return DoGetUpdateUser();
		}
		return 0;
	}
	
	//提取（保留）在线更新客户
	void AddRef()
	{
		m_pObj = 0;
	}
	
	//处理父类：释放在线更新客户
	virtual void FreeObject(OnlineUpdateClient** ppObj)
	{
		if(ppObj && *ppObj)
		{
			//delete *ppObj;
			//(*ppObj)->ReleaseThis();
			*ppObj = 0;
		}
	}
};
	
#endif 
