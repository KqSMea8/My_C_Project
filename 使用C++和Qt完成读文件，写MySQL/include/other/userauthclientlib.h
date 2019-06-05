// userauthclientlib.h: IUserAuthClient loader
#ifndef _USERAUTHCLIENTLIB_20081008
#define _USERAUTHCLIENTLIB_20081008

#include "../commgr/intfobjptra.h"     // for CIntfObjPtrA
#include "../../interface/iuserauthclient.h"

//DLL����Ľӿڶ�������
class CUserAuthClientLib : public CIntfObjPtrA<IUserAuthClient>
{
public:
	CUserAuthClientLib() : CIntfObjPtrA<IUserAuthClient>
		(MODEL_USERAUTH_CLIENT, CLSID_UserAuthClient, IID_IUserAuthClient) { }
};
	
#endif 
