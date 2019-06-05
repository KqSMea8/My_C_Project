#ifndef _SETTINGOPERATE__H_
#define _SETTINGOPERATE__H_
#include "operateintf.h"

#define IID_IControlClientInfo	"IControlClientInfo"
#define IID_ICommand			"ICommand"
#define IID_ICallDZ				"ICallDZ"
#define IID_IModifyDZ			"IModifyDZ"
#define IID_ICallVersion		"ICallVersion"
#define IID_ISwitchZone         "ISwitchZone"
#define IID_ICallZone			"ICallZone"
#define OPCLSID_CallDZ			"calldz"
#define OPCLSID_ModifyDZ		"modifydz"
#define OPCLSID_CallVersion		"callversion"
#define OPCLSID_SwitchZone      "switchzone"
#define OPCLSID_CallZone		"callzone"
#define IID_ISettingOrderSender	"ISettingOrderSender"
#define IID_ISettingOrderSinker	"ISettingOrderSinker"	

class IControlClientInfo : public IICSUnknown
{
public:
	virtual void SetClientModule(const char* module)=0;
	virtual void GetClientModule(char* module, int nSize)=0;
	virtual void SetControlTag(int tag)=0;
	virtual int GetControlTag()=0;
public:
	static char* GetIntfName(){return IID_IControlClientInfo;};
};

class ICommand : public IICSUnknown
{
public:
	virtual bool NeedBack()=0;
	virtual void SendCommand(IICSUnknown* pOrderSender)=0;	
	virtual void GetCommandSinker(IICSUnknown** ppSinker)=0;
	virtual bool CanRelease()=0;	
};

class IDZCommond : public IICSUnknown
{
public:
	virtual void SetDev(int dev)=0;
	virtual void SetCPU(int cpu)=0;
	virtual void SetZone(int zone)=0;
	virtual void SetDZNum(int num)=0;
};

class ICallDZ : public IDZCommond
{
public:		
	virtual int GetZone()=0;
	virtual void GetDZValue(int index, double* pValue, BYTE* qos)=0;

	virtual int GetGroupNum()=0;
};

class IModifyDZ : public IDZCommond
{
public:	
	virtual void SetGroupNum(int num)=0;
	virtual void SetDZValue(int index, double value, BYTE qos)=0;

	virtual void SetStartNum(int num)=0;
};

class ICallVersion : public IICSUnknown
{
public:
	virtual void SetDev(int dev)=0;

 	virtual int	 GetLdNum() = 0;

	//按照序号获取ld名字和版本号
 	virtual void GetVersionByIndex(int index, char* version, int size) = 0;
	virtual void GetLdNameByIndex(int index, char* ldName, int size) = 0;
};

class ISwitchZone : public IICSUnknown
{
public:
	virtual void SetDev(int dev)=0;
	virtual void SetCpu(int cpu)=0;
	virtual void SetZone(int zone)=0;
	virtual int GetDev()=0;
	virtual int GetCpu()=0;
	virtual int GetZone()=0;
};

class ICallZone : public IICSUnknown
{
public:
	virtual void SetDev(int dev)=0;
	virtual void SetLD(int ld)=0;
	virtual int GetDev()=0;
	virtual int GetLD()=0;
	virtual int GetZoneNum() = 0;
	virtual int GetCurrentRunZone() = 0;
	virtual int GetCurrentEditZone() = 0;
};

#define	MODULE_SETTINGCTRL	"SettingCtrlClient"
#define MODULE_SETTINGCOMPS	"SettingComps"

#endif
