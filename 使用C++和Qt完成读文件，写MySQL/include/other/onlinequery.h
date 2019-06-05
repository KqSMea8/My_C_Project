// onlinequery.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _ONLINEQUERY_H_
#define _ONLINEQUERY_H_

#include "../../interface/ionlinequery.h"
#include "../commgr/intfobjptrb.h"      // for CIntfObjPtrB<IntfObj>

class COnlineQuery: public CIntfObjPtrB<IOnlineQuery>
{
public:
	COnlineQuery() : CIntfObjPtrB<IOnlineQuery>(
		DLL_ONLINEQUERY, CID_ONLINEQUERY, IID_ONLINEQUERY) {}
};

#endif
