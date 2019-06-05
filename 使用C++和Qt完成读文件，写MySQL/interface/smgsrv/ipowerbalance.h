//ipowerbalance.h

#ifndef _IPOWERBALANCE_NGSHIKANG_20130228_H_
#define _IPOWERBALANCE_NGSHIKANG_20130228_H_

#include "icontrolstrategy.h"                    // for IControlStrategy
class IGeneratorMgr;
class ILoadMgr;
class ISMicgridDao;
class IStorageDao;

class IPowerBalance : virtual public IControlStrategy 
{
public:
	//传入外部对象
	virtual void SetGeneratorManager(IGeneratorMgr* pGenCtrlor) = 0;
	virtual void SetLoadManager(ILoadMgr* pStorCtrlor) = 0;
	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;
	virtual void SetStorageDao(IStorageDao* pStorage) = 0;
};

#endif
