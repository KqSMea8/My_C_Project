// onlinemodel.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _ONLINEMODEL_H_
#define _ONLINEMODEL_H_

#include "../../interface/ionlinemodel.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class COnlineModel: public CIntfObjPtrB<IOnlineModel>
{
public:
	COnlineModel() : CIntfObjPtrB<IOnlineModel>(
		DLL_ONLINEMODEL, CID_ONLINEMODEL, IID_ONLINEMODEL) {}
};

#endif
