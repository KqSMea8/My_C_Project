// iemergeexchange.h: interface for the IEmergeExchange class.
//
////////////////////////////////////////////////////////////////////////

#ifndef AFX_CONTI_EXCHANGECURVE_H__91A01EE2_B624_41A6_856A_69FF841445BE__INCLUDED_
#define AFX_CONTI_EXCHANGECURVE_H__91A01EE2_B624_41A6_856A_69FF841445BE__INCLUDED_

#include "icontrolstrategy.h"                  //for IControlStrategy

class IGeneratorMgr;
class ILoadMgr;
class IStorageMgr;

class IEmergeExchange : public IControlStrategy  
{
public:
	//传入外部对象
	virtual void SetStorageMgr(IStorageMgr* pStorageMgr) = 0;
	virtual void SetGeneratorMgr(IGeneratorMgr* pGeneratorMgr) = 0;
	virtual void SetLoadMgr(ILoadMgr* pLoadMgr) = 0;
};

#endif
