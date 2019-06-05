/*******************************************************
 * iautoctrl -- smg服务端自动控制主业务接口
 *******************************************************/

#ifndef IAUTOCTRL_PENGSHIKANG_20130301_H
#define IAUTOCTRL_PENGSHIKANG_20130301_H

#include "scadadatadef.h"                        // for OPERATETYPE、ControlLogInfo
#include "ictrlmainlogic.h"                      // for ICtrlMainLogic

class IAutoCtrl
{
public:
	//根据控制操作类型自动执行遥控操作
	virtual bool AutoExecuteControl(OPERATETYPE ctrlType, int ctrlId, bool bCheck, ControlLogInfo* pCtrlInfo, bool bCheckControl=true, AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0, int relativeType=1) = 0;
	//根据调节目标值自动执行遥调操作
	virtual bool AutoExecuteAdjust(int ctrlId, float ctrlValue, double aimValue, bool bCheck, ControlLogInfo* pCtrlInfo, bool bCheckControl=true, bool isInductiveQ=false, AUTOEXECUTESELECTCMD aescType=AESC_SELECT, int relativeID=0) = 0;

	// 设置控制是否等待结果返回
	virtual bool SetWaitControlReturn(bool bWaitRet) = 0;
	// 获取连续控制休息时间（毫秒）
	virtual int GetContinueControlRestTime() = 0;

	//检查控制量ID是否可以进行自动策略控制
	virtual bool CanAutoControl(int ctrlId, int ctrlType) = 0;

	//传入外部对象
	virtual void SetControlMainLogic(ICtrlMainLogic* pCtrlMain) = 0;
};

#endif