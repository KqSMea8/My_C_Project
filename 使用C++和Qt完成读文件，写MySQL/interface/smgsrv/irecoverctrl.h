// irecoverctrl.h
//
//////////////////////////////////////////////////////////////////////

#ifndef _IRECOVERCTRL__H__INTERFACE_
#define _IRECOVERCTRL__H__INTERFACE_

#include "icontrolstrategy.h"                       // for IControlStrategy

class IGeneratorMgr;
class IStorageMgr;
class ILoadMgr;

class RecoverCtrl : virtual public IControlStrategy
{
	//传入外部对象
	virtual void SetGeneratorMgr(IGeneratorMgr* pGeneratorMgr) = 0;
	virtual void SetStorageMgr(IStorageMgr* pStorageMgr) = 0;
	virtual void SetLoadMgr(ILoadMgr* pLoadMgr) = 0;
};