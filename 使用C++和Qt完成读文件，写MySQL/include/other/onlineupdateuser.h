// onlineupdateuser.h: implement for the COnlineUpdateUser class.
#ifndef _ONLINEUPDATEUSER_2008_11_04_PENGSHIKANG_H_
#define _ONLINEUPDATEUSER_2008_11_04_PENGSHIKANG_H_

#include "../commgr/intfobjptr.h"               // for CIntfObjPtr
#include "../../interface/onlineupdateclient.h" // for OnlineUpdateClient

#define MODULE_ONLINEUPDATECLIENT	"onlineupdateclient"
#define METHOD_GETONLINEUPDATEUSER	"GetOnlineUpdateInterface" // OnlineUpdateClient* GetOnlineUpdateInterface();

//DLL����Ľӿڶ�������
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
	
	//�����ࣺ�������߸��¿ͻ�
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
	
	//��ȡ�����������߸��¿ͻ�
	void AddRef()
	{
		m_pObj = 0;
	}
	
	//�����ࣺ�ͷ����߸��¿ͻ�
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
