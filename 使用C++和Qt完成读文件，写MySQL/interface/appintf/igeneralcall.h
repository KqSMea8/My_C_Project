#ifndef _IGENERALCALL__H_
#define _IGENERALCALL__H_

#include "icsunknown.h"

#define IID_IGeneralComm		"igeneralcomm"
#define IID_IGeneralCommEx		"igeneralcommex"
#define IID_IGeneralCall		"igeneralcall"
#define IID_IGeneralCallEvent	"igeneralcallevent"

#define CLSID_GeneralCall		"generalcall"

//总召下发接口,由通讯实现
class IGeneralComm : public IICSUnknown
{
public:
	//src对应通道组,lo对应装置ID
	virtual bool SendCallCmd(int src, int lo) = 0;
};

class IGeneralCommEx : public IICSUnknown
{
public:
	//召唤对象数据(objtype: 使用CSF对象类型定义)
	virtual bool GetObjValue(int objtype, int objid) = 0;
};



/*总召唤原因
GT_COMMRECOVERY:	通讯恢复
GT_INITIAL:			被控站初始化
GT_OPERATION:		业务总召
GT_MANUAL:			手动总召
GT_GETDATA:			按点召唤数据
*/
enum GENERALCALL_TYPE{GT_COMMRECOVERY = 0, GT_INITIAL, GT_OPERATION, GT_MANUAL, GT_GETDATA };

//总召接口,总召唤模块实现
class IGeneralCall : public IICSUnknown
{
public:
	virtual bool AddCallCmd(int src, int lo, GENERALCALL_TYPE gt) = 0;
	virtual bool DelCallCmd(int src, int lo) = 0;
	virtual void SetGeneralComm(IGeneralComm* pComm) = 0;
};

//总召唤通讯事件接口:通讯调用,总召唤模块接收
class IGeneralCallEvent : public IICSUnknown
{
public:
	virtual void OnCallConfirm(int src, int lo, bool bSuc) = 0;
	virtual void OnCallOver(int src, int lo, bool bSuc) = 0;
};

#define MODULE_GENERALCALL	"generalcall"

#endif
