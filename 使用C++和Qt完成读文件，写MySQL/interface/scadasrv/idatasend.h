#ifndef _IDATASEND_PENGSHIKANG_20150515__H_
#define _IDATASEND_PENGSHIKANG_20150515__H_

#include "../icsunknown.h"                       // for IICSUnknown
#include "../icsvalue.h"                         // for icsvariant 
#include "dispatchtaskdata.h"                    // for DispatchTaskData

#define DATASEND_CLASSID      "cidatasend"
#define DATASEND_INTFID       "idatasend"

class IDataSend : virtual public IICSUnknown 
{
public:
	//1. 直接发送信息到调度端
	//1.1 发送模拟量到调度端
	virtual bool SendAnalogToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.2 发送状态量到调度端
	virtual bool SendStatusToMSCCenter(int id, int nValue, int nQuality, double timestamp) = 0;
	//1.3 发送累加量到调度端
	virtual bool SendAccumuToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.4 发送计算量到调度端
	virtual bool SendExprcalToMSCCenter(int id, double dValue, double timestamp) = 0;
	//1.5 发送控制结果到调度端
	virtual bool SendCtrlResultToMSCCenter(unsigned char msgType) = 0;
	//1.6 发送控制量给五防装置
	virtual bool SendControlToMSCCenter(int id, int nValue, bool isDouble=false) = 0;

	//2. 向调度端发送后台数据处理服务上线的通知
	virtual bool SendDataServerOnlineNotice() = 0;

	//3. 创建调度值对象 用于加入队列 
	//3.1 创建调度整数定值对象
	virtual DispatchSetting* CreateDispatchValue(short taskType, int dataValue, int saveValue=0, int toHisSave=0, int senderType=0, const char* senderName="") = 0;
	//3.2 创建调度实数定值对象
	virtual DispatchSetting* CreateDispatchValue(short taskType, float dataValue, int toHisSave=0, int senderType=0, const char* senderName="") = 0;
	//3.3 创建用于实时库-配置库同步的sql对象
	virtual DispatchSetting* CreateDispatchValue(int toHisSave=0,const char* sql="") = 0;

	//4. 通过单独的队列进程发送调度压板值到调度端
	//4.1 添加调度压板值到队列
	virtual void PushDispatchValue(DispatchSetting* dispValue) = 0;
	//4.2 发送调度压板值到调度端
	virtual bool PopDispatchValue(DispatchSetting* dispValue) = 0;

	//5. 直接发送调度结果
	//5.1 发送调度结果到控制客户端端
	virtual bool SendControlResult(const char* sClient, short taskType, bool bSuccessed) = 0;
	//5.2 发送调度结果到调度端
	virtual bool SendDispatchResult(short taskType, bool bSuccessed) = 0;

	//6. 直接发送压板、启动状态等信息到调度端
	//6.1 发送调度压板变更值到调度端
	virtual bool SendDispatchSwitchValue(int updateInfo, int switchValue) = 0;
	//6.2 发送调度紧急启停状态到调度端
	virtual bool SendDispatchEmergeValue(bool isSupport, int emergeValue) = 0;
	//6.3 本地压板变更后发送本地压板值到调度端
	virtual bool SendLocalSwitchValue(int localFlag) = 0;
	//6.4 AVC本地压板变更后发送本地压板值到调度端--暂时不动模型，也送远方本地压板，后期再将AGC/AVC的本地压板分开
	virtual bool SendAVCLocalSwitchValue(int localFlag) = 0;

	//7. 将业务数据发送到调度端
	//7.1 发送无功可调上/下限、可增/减无功、无功上/下调节闭锁标志到调度端  2016.4.7新增
	virtual bool SendAVCAdjustParaValue() = 0;
	//7.2 发送AGC相关参数到调度端  2016.8.22新增
	//（有功可调上/下限、可增/减有功、有功功率增/减闭锁标志、可调容量、参与调控损失有功功率、有功功率增减闭锁标志、自由发电标志）
	virtual bool SendAGCAdjustParaValue() = 0;
};

#endif
