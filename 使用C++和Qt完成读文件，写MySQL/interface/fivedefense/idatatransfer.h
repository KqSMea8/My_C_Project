//idatatransfer.h
#ifndef IDATATRANSFER_PENGSHIKANG_20140320_H
#define IDATATRANSFER_PENGSHIKANG_20140320_H

#include "../icsunknown.h"              // for IICSUnknown

#define DLL_DATATRANSFER           "fivedefense"
#define CLSID_DATATRANSFER         "cdatatransfer"
#define IID_DATATRANSFER           "idatatransfer"

class IDataTransferCallBack;

/************************************************************************/
/* IDataTransfer数据转发接口
/* 功能：监控系统向五防装置转发四遥数据；
/************************************************************************/
class IDataTransfer : virtual public IICSUnknown
{
public:
	//设置回调接口
	virtual void Advise(IDataTransferCallBack* pCallback) = 0;

	//向远动或五防送四遥，iDescSystem=0：五防，iDescSystem=1：远动。
	//(1)监控系统向五防装置转发遥测数据
	virtual void SendStatus(int iDescSystem, int iID,int iValue, double dTime, int iQuality, bool bManSet=false) = 0;
	//(2)监控系统向五防装置转发遥信数据
	virtual void SendAnalog(int iDescSystem, int iID,double dValue, double dTime, int iQuality, bool bManSet=false) = 0;
	//监控系统向五防装置转发SOE数据
	virtual void SendSoe(int iDescSystem, int iID, int iValue, double dSpan, char *pCFace, double dTime) = 0; 
	//(3)监控系统向五防装置发送遥控效验令
	virtual void SendControl(int iDescSystem, int iCtrlCmdType, int iID, int iOldValue, int iNewValue, bool bDouble) = 0;
	//监控系统向五防装置转发控制结果信息
	virtual void SendControlBack(int iDescSystem, int iCtrlBackType, int iID,bool bExecSuccess,double dTime) = 0;
};

//五防装置向监控系统发送数据
class IDataTransferCallBack
{
public:
	//(1)五防向监控发送遥信值
	virtual void SetAnalogValueByID(int idAnalog, double value, int quality, double dt) = 0;
	//(2)五防向监控发送遥测值
	virtual void SetStatusValueByID(int idStatus, int value, int quality, double dt) = 0;
	//(?)五防向监控发送SOE值
	virtual void SetSOEValueByID(int idStatus, int value, double span, char* cFace, double dt) = 0;
	//(3)五防请求监控闭锁/解锁
	virtual void PreventControl(int idControl, bool bLock, double dt) = 0;
	//(4)五防向监控返回校验结果
	virtual void PreventBack(int idControl,bool bSucc,double dt) = 0;
	//五防向监控返回执行令结果
	virtual void ExecuteOrderBackByID(int idControl, bool bSucc, double dt) = 0;
	//五防向监控发送选控令
	virtual bool SendSwitchSelectByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//五防向监控发送直控令
	virtual bool SendSwitchExcuteByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//五防向监控发送撤销令
	virtual bool SendSwitchCancelByID(int idControl, int old_val, int new_val, bool bDouble) = 0;
	//(5)五防向监控发送通道状态变化信息
	virtual bool SendChannelState( int iChnlType, int iNodeId, char* sIp, int iState ) = 0;
};


#endif