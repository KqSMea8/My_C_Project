#ifndef __ISIMULATORCTRL__H_
#define __ISIMULATORCTRL__H_

#include "objsintf.h"
#include "ivisionstate.h"

#define IID_ISimulatorCtrl		"isimulatorctrl"
#define MODULE_SIMULATORCTRL	"simulatorctrl"
#define CLISD_SimulatorCtrl		"simulatorctrl"

typedef void (*OnGuardianMethod)(ITaskObject* pObj, IUserObject* pUser, const char* operate, int nTimeLimit);

class ISimulatorCtrl : public IICSUnknown
{
public:
	virtual bool CloseSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool CloseExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool OpenSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool OpenExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool RiseSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool RiseExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool DropSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool DropExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool StopSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool StopExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool LongSelect(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool LongExecute(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual bool FloatSelect(ITaskObject* pControl, double newval, int nTimeLimit) = 0;
	virtual bool FloatExecute(ITaskObject* pControl, double newval, int nTimeLimit) = 0;
	virtual bool CancelOrder(ITaskObject* pControl) = 0;
	virtual bool ApplyPrevent(ITaskObject* pControl, int newval, int nTimeLimit) = 0;
	virtual int PreventState(ITaskObject* pControl, int nTimeLimit) = 0;
	virtual int GetControlResult() = 0;
	virtual bool StartControl(IUserObject* pUser, int nTimeLimit) = 0;
	virtual bool EndControl(int nTimeLimit) = 0;
	virtual bool RequestGuardian(const char* computer, ITaskObject*pObj, \
					const char* operate, IUserObject* pOperator, int nTimeLimit) = 0;
	virtual void GuardianResult(IUserObject* pUser, int result) = 0;
	virtual void SetGuardianFunc(OnGuardianMethod) = 0;
	virtual bool CheckCtrlResult(ITaskObject* pControl, int newval, bool bCheck, int nTimeLimit) = 0;
	virtual bool FloatCheckCtrlResult(ITaskObject* pControl, double newval, bool bCheck, int nTimeLimit) = 0;
	virtual bool StationLockReq(ITaskObject* pControl, int nTimeLimit) = 0;	
	virtual double ComputeExpression(const char* exp, bool& bOK) = 0;
	virtual bool SimulatorCheck(ITaskObject* pControl, int newval) = 0;
	virtual void StartOPSimulator(IUserObject* pUser) = 0;
	virtual void EndOPSimulator() = 0;
	virtual void StopOPSimulator() = 0;
	virtual void ClearOPSimulator(IUserObject* pUser) = 0;
	virtual void StartPRGSimulator(IUserObject* pUser) = 0;
	virtual void EndPRGSimulator(IUserObject* pUser) = 0;
	virtual VISIONSTATE GetSimulatorState() = 0;
	virtual bool GetSimulatorObject(const char* clsid, int id, IICSRtdbObject** ppObject) = 0;
	
	//2011年3月22日 Add by baotanl，目前遥控面板设置用户时，先startcontrol，后设置用户，导致遥控面板设置用户无效，故设置用记接口。
	virtual void SetUserObj(IUserObject* pUser) = 0;
public:
    static char *GetIntfName()
    {
        return IID_ISimulatorCtrl;
    };
};

#endif
