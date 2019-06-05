//ismoothctrl.h

#ifndef _ISMOOTHCTRL_H__INCLUDED_
#define _ISMOOTHCTRL_H__INCLUDED_

#include "icontrolstrategy.h"                       // for IICSUnknown

class IGeneratorMgr;
class IStorageMgr;
class IStorageDao;
class ISmoothCtrlDao;
class ISMicgridDao;

class ISmoothCtrl : virtual public IControlStrategy
{
public:
	virtual bool MakeStrategy() = 0;

	//更新子微网有功功率平滑控制实时值
	virtual void RefreshMicgridSmoothValues() = 0;

	//传入外部对象
	virtual void SetGeneratorMgr(IGeneratorMgr* pGeneratorMgr) = 0;

	virtual void SetStorageMgr(IStorageMgr* pStorageMgr) = 0;

	virtual void SetStorageDao(IStorageDao* pStorage) = 0;

	virtual void SetSmoothCtrlDao(ISmoothCtrlDao* pSmoothCtrl) = 0;

	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;

};