// iislandstrategy.h: interface for the IIslandStrategy class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _IISLANDCONTROLSTRATEGY_H__PENGSHIKANG_20150420__INCLUDED_
#define _IISLANDCONTROLSTRATEGY_H__PENGSHIKANG_20150420__INCLUDED_

#include "../icsunknown.h"                       // for IICSUnknown
#include "smgdatadef.h"                          // for MicgridObectInfo

//struct MicgridObectInfo;

#define SMGISLANDPROCESS_MODULE     "smgislandproc"
#define SMGISLANDPROCESS_CLASSID    "cSmgIslandProcess"
#define SMGISLANDPROCESS_INTFID     "iSmgIslandProcess"

class IIslandStrategy : virtual public IICSUnknown 
{
public:
	//执行微电网的自动控制策略
	virtual bool ExecuteStrategy(MicgridObectInfo* pCurMgObj, int proFlag) = 0;
};

#endif
