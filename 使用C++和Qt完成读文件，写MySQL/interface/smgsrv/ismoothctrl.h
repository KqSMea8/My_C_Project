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

	//������΢���й�����ƽ������ʵʱֵ
	virtual void RefreshMicgridSmoothValues() = 0;

	//�����ⲿ����
	virtual void SetGeneratorMgr(IGeneratorMgr* pGeneratorMgr) = 0;

	virtual void SetStorageMgr(IStorageMgr* pStorageMgr) = 0;

	virtual void SetStorageDao(IStorageDao* pStorage) = 0;

	virtual void SetSmoothCtrlDao(ISmoothCtrlDao* pSmoothCtrl) = 0;

	virtual void SetSMicgridDao(ISMicgridDao* pSMicgrid) = 0;

};