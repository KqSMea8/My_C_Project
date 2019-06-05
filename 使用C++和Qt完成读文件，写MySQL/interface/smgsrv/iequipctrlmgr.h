//iequipctrlmgr.h

#ifndef _IEQUIPMENTCONTROLMGR_PENGSHIKANG_20140214_H_
#define _IEQUIPMENTCONTROLMGR_PENGSHIKANG_20140214_H_

class IAGeneratorMgr;
class IGeneratorMgr;
class IAStorageMgr;
class IStorageMgr;
class ILoadMgr;
class IReactCompMgr;
class ITransformerMgr;
class IGroupCtrlMgr;
class IActionAlarm;
class IAutoCtrl;
class IMSCClient;

class IEquipCtrlMgr
{
public:
	virtual IAGeneratorMgr * GetAGeneratorMgr() = 0;
	virtual IGeneratorMgr  * GetGeneratorMgr() = 0;
	virtual IAStorageMgr   * GetAStorageMgr() = 0;
	virtual IStorageMgr    * GetStorageMgr() = 0;
	virtual ILoadMgr       * GetLoadMgr() = 0;
	virtual IReactCompMgr  * GetReactCompMgr() = 0;
	virtual ITransformerMgr* GetTransformerMgr() = 0;
	virtual IAutoCtrl      * GetAutoCtrlor() = 0;
	virtual IGroupCtrlMgr  * GetGroupCtrlMgr() = 0;
	virtual IActionAlarm   * GetActionAlarm() = 0;
	virtual IMSCClient     * GetMscClient() = 0;
};

#endif
