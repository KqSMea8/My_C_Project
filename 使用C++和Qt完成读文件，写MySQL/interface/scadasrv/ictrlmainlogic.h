/*******************************************************
 * ictrlmainlogic.h -- 服务端控制主业务类接口
 *******************************************************/

#ifndef __ICONTROLMAINLOGIC_PENGSHIKANG_H_20130301
#define __ICONTROLMAINLOGIC_PENGSHIKANG_H_20130301

#include "scadadatadef.h"                        // for OPERATETYPE、ControlLogInfo

class ICtrlMainInfo;
class ICtrlRelatData;

class ICtrlMainLogic
{
public:
	//检查控制量ID是否有效
	virtual bool CheckAndStartControl(int sid, int ctrlId, int& ctrlPos, CONTROLORIGIN ctrlQrigin, bool bCheckControl, bool bCanWait, bool isSelCtrl=false, bool isMultSrc=false) = 0;
	//根据控制量位置和操作类型得到控制对应的控制命令值。
	virtual bool GetCtrlValueByCtrlType(int ctrlPos, OPERATETYPE ctrlType, int& ctrlValTypPos, int& ctrlValue) = 0;
	//更新当前控制信息
	virtual void UpdateControlLogInfo(ControlLogInfo* pCtrlInfo) = 0;
	//自动执行控制命令
	virtual int AutoExecuteCommand(int ctrlPos, float ctrlValue, int ctrlValTypPos, double aimValue, const ControlLogInfo* pCtrlInfo, 
		AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0, int relativeType=1, bool needGuard=false, const char* userName="") = 0;

	//设置是否需要等待控制结果返回（群控时设置为false）
	virtual bool SetNeedWaitFlag(bool needWait) = 0;

	virtual ICtrlMainInfo* GetControlMainInfo() = 0;
	virtual ICtrlRelatData* GetCtrlRelatedData() = 0;
};

#endif