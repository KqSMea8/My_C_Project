//==============================================AnalogCal.h==================================================//
#ifndef  INCLUDE_ORDERSINKER_H 
#define  INCLUDE_ORDERSINKER_H 

#include "objsintf.h"
#include "ProtectReportIntf.h"

class IOrderSinker : public IICSUnknown
{
public:
	//选择令返回（预发指令）
	virtual void SelectOrderBack(int idControl, bool bSucc, double tm)=0;
	//执行令返回（确认指令）
	virtual void ExcuteOrderBack(int idControl, bool bSucc, double dt)=0;
	//撤销指令返回
	virtual void CancelOrderBack(int idControl, bool bSucc, double dt)=0;
	//选择令返回（预发指令）
	virtual void SelectOrderBackByObj(ITaskObject* pObject, bool bSucc, double tm)=0;
	//执行令返回（确认指令）
	virtual void ExcuteOrderBackByObj(ITaskObject* pObject, bool bSucc, double dt)=0;
	//撤销指令返回
	virtual void CancelOrderBackByObj(ITaskObject* pObject, bool bSucc, double dt)=0;


	//五防遥控
	virtual void PreventControl(int idControl, bool bLock, double dt)=0;

	//监控请求五防返回
	virtual void PreventBack(int idControl,bool bSuccess,double dt) = 0; 

  	/*
	远动闭锁请求返回
	【in】int chgrpid	远动通道组ID
	【in】int controlid	请求遥控点的ID
	【in】int bLock	1:闭锁;0:通过
	【out，ref】bool	无用
	*/	
	virtual void SCADALockRes(int chgrpid, int idControl, bool bLock) = 0;

	/*
	远动请求监控站闭锁
	【in】Int chgrpid	远动通道组ID
	【in】Int controlid	请求遥控点的ID
	【out，ref】bool bLock	1:闭锁;0:通过
	*/
	virtual void YDLockReq(int chgrpid, int idControl, bool& bLock) = 0;
};

class ISettingOrderSinker : public IICSUnknown
{
public:
	//定值召唤返回
	virtual void SettingCallReturn(long idIED, long nCPUNO, long nZone, long bSucc, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//定值执行令返回
	virtual void SettingReturn(long idIED, long nCPUNO, long nZone, long bSucc)=0;

	//定值区切换返回
	virtual void SettingSwitchReturn(long idIED, long nCPUNO, long nZone, long bSucc)=0;

	//定值修改预发返回
	virtual void SettingSelReturn(long idIED, long nCPUNO, long nZone, long bSucc, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//定值版本号返回
	virtual void SettingVerReturn(long idIED,long nCPUNO,char* idString,char* softwareId)=0;

	//动作报告受召唤返回
	virtual void ProtectCallReturn(char cResult, bool bActive,/*long bSucc,*/long nDev, long nCpu, \
						long nSin, IProtectObject* pObject)=0;
	//运行事件及自检报告召唤返回
	virtual void EventCallReturn( char cResult, long nDev, long nSin, IProtectObject* pObject) =0;

	virtual void ManSetReturn(bool bSet, bool bSucc, int iIedid, int iId) = 0;

	virtual void ZoneCallReturn(bool bSucc, int iIedid, int iLd, int iZoneNum, int iCurntRun, int iCurntEdit) = 0;
};

#endif // INCLUDE ANALOGCAL H 
