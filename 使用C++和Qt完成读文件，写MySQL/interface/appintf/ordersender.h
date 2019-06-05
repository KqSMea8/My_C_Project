//==============================================AnalogCal.h==================================================//
#ifndef  INCLUDE_ORDERSENDER_H 
#define  INCLUDE_ORDERSENDER_H 

#include "objsintf.h"
//#include "ICSUnknown.h"

class IOrderSender : public IICSUnknown
{
public:
	//发送选择令（预发指令）
	virtual bool SendSwitchSelectByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchSelectByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//5发送选择令（预发指令）
	virtual bool SendGradsSelectByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsSelectByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//6
	virtual bool SendLongSelectByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongSelectByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//7发送选择令（预发指令）
	virtual bool SendFloatSelectByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatSelectByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//8发送执行令（确认指令）
	virtual bool SendSwitchExcuteByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchExcuteByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//9发送执行令（确认指令）
	virtual bool SendGradsExcuteByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsExcuteByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//10发送执行令（确认指令）
	virtual bool SendLongExcuteByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongExcuteByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//11发送执行令（确认指令）
	virtual bool SendFloatExcuteByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatExcuteByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//12发送撤消指令
	virtual bool SendSwitchCancelByID(int idControl, int old_val, int new_val, bool bDouble)=0;
	virtual bool SendSwitchCancelByObj(ITaskObject* pControl, int old_val, int new_val, bool bDouble)=0;

	//13发送撤消指令
	virtual bool SendGradsCancelByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendGradsCancelByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//14发送撤消指令
	virtual bool SendLongCancelByID(int idControl, int old_val, int new_val)=0;
	virtual bool SendLongCancelByObj(ITaskObject* pControl, int old_val, int new_val)=0;

	//15发送撤消指令
	virtual bool SendFloatCancelByID(int idControl, double old_val, double new_val)=0;
	virtual bool SendFloatCancelByObj(ITaskObject* pControl, double old_val, double new_val)=0;

	//监控请求五防指令
	virtual bool SendPreventByID(int idControl,int nValue,bool bDouble)=0;
	virtual bool SendPreventByObj(ITaskObject* pControl,int nValue,bool bDouble)=0;

	//向五防转发遥测遥信值
	virtual bool SendAnalogToPrevent(int idAnalog, double value)=0;
	virtual bool SendStatusToPrevent(int idStatus, int val, bool dbflag)=0;

	virtual bool SCADALockReq(int chgrpid, int idControl) = 0;
};


class ISettingOrderSender : public IICSUnknown
{	
public:
	//定值召唤
	virtual bool  SendCallSetting(long idIED, long nCPUNO, long nZone)=0;

	//定值修改预发                                                                                                系数           值   
	virtual bool  SendSelSetting(long idIED, long nCPUNO, long nZone, long nSize, long nStart,double* pcoes, double* pvals)=0;

	//定值区切换
	virtual bool  SendSwitchSetting(long idIED, long nCPUNO, long nZone)=0;

	//定值修改预发取消
	virtual bool  SendCancelSetting(long idIED, long nCPUNO, long nZone)=0;

	//定值修改执行
	virtual bool SendAckSetting(long idIED, long nCPUNO, long nZone)=0;

	//定值版本号
	virtual bool SendAskSettingVer(long idIED,long nCPUNO)=0;
	//动作报告召唤
	virtual bool  SendCallProtect(long nDevNo, long nCpuNo, long nSinNo) =0;
	//运行事件及自检报告召唤
    virtual bool  SendCallEvent(int idIED, int iSinNo) =0;

	virtual bool SendAnalogManSet(bool bSet, int iIedid, int iId, double Value) = 0;
	virtual bool SendPulseManSet(bool bSet, int iIedid, int iId, double value) = 0;
	virtual bool SendStatusManSet(bool bSet, int iIedid, int iId, int Value) = 0;
	virtual bool SendCallZone(int idIED, int iLD) = 0;
};
#endif // INCLUDE ANALOGCAL H 
