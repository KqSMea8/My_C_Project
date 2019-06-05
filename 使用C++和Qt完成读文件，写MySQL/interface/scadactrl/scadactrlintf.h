/*******************************************************
 * scadactrlintf.h -- scada控制接口定义
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 * revised:
		.修改IScadaOperate接口 2008.08.06 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRLINTF_H_20080708
#define __SCADACTRLINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"
//std header
#include <vector>

class IScadaControlType;
class IControlValue;
class IScadaOperateType;
class IScadaSettingType;
class IScadaRingType;

/***
 * 控制基类接口
 ***/
class IControlBase : public IICSUnknown
{
public:
	/* 获得错误描述信息
	 * 参数: 无
	 * 返回: const char* 错误描述
	 */
	virtual const char* ErrorMsg() = 0;
   
	/* 
	 * 获得当前控制对象的控制模式 
	 * 参数: 无
	 * 返回: 控制模式
	   CRequestItem::ControlMode -- CRequestItem::RealMode 真实模式
									CRequestItem::EmulationMode 模拟预演模式
	 */
	virtual CRequestItem::ControlMode Mode() = 0;

	/*
	 * 获得当前控制对象设定的超时时间
	 * 参数: 无
	 * 返回: int 超时时间(单位: 毫秒)
		> 0 -- 超时时间; -1 -- 用户未定义,按系统默认设置; 0 -- 永不超时; 
	 */
	virtual int TimeOut() = 0;

	/*
	 * 设置当前控制对象的超时时间
	 * 参数:
	   msec -- 超时时间(单位: 毫秒)
	 * 返回: void
	 */
	virtual void SetTimeOut(int msec) = 0;

	/*
	 * 获得当前控制对象的用户信息
	 * 参数: 无
	 * 返回: const char* 用户ID 
	 */
	virtual const char* UserID() = 0;

	/*
	 * 设定当前控制对象的用户信息
	 * 参数:
	   userID -- const char* 用户ID
	 * 返回: void
	 */
	virtual void SetUser(const char* userID) = 0;

	/*
	 * 获得（当前控制的）本工作站ID
	 * 参数: 无
	 * 返回: const char* 工作站ID 
	 */
	virtual const char* WorkstationID() = 0;

	/*
	 * 设定当前控制的工作站ID
	 * 参数:
	   wkstationID -- const char* 工作站ID
	 * 返回: void
	 */
	virtual void SetWorkstation(const char* wkstationID) = 0;

	/*
	 * 清空设置
	 * 参数: 无
	 * 返回: void 
	 */
	virtual void Clear() = 0;

	/*
	 * 设定异步控制回调接口(仅异步控制使用)
	 * 参数:
	   ptr -- IAsyncReturn* 回调接口指针
	 * 返回: void
	 */
	virtual void SetCallBack(IAsyncReturn* ptr) = 0;

public:
    static const char* GetIntfName() {return IID_IControlBase;}; 

};

/***
 * Scada控制接口
 ***/
class IScadaControl : public IControlBase
{
public:
	/*
	 * 获取当前控制对象的控制类型
	 * 参数:无
	 * 返回: IScadaControlType* 控制类型接口指针
	 */
	virtual IScadaControlType* Type() = 0;

	/*
	 * 枚举所有控制值（控制值不一定有效）
	 * 参数: 无
	 * 返回: std::vector<IControlValue*> 控制值集合
		!!注意: vector容器对象销毁前，用户需释放其中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual std::vector<IControlValue*> ListValues() = 0;

	/*
	 * 根据控制对象ID枚举控制值
	 * 参数:
	   controlID -- 控制对象ID
	 * 返回: std::vector<IControlValue*> 控制值集合
		!!注意: vector容器对象销毁前，用户需释放其中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual std::vector<IControlValue*> ListValues(int controlID) = 0;

	/*
	 * 执行控制
	 * 参数:
	   controlID -- 控制对象ID
	   ctrlValueID -- 控制值ID ( IControlValue*->ID() )
	 * 返回: int
			 0-成功； 1-失败；2-超时；3-控制被拒绝；4-遥控撤销成功；5-系统自动取消；6-用户取消操作
	 */
	virtual int Execute(int controlID, int ctrlValueID) = 0;

	/*
	 * 执行控制
	 * 参数:
	   controlID -- 控制对象ID
	   ctrlValueID -- 控制值ID ( IControlValue*->ID() )
	   userID -- const char* 用户ID
	   wkstationID -- const char* 工作站ID
	 * 返回: int
			 0-成功； 1-失败；2-超时；3-控制被拒绝；4-遥控撤销成功；5-系统自动取消；6-用户取消操作
	 */
	virtual int Execute(int controlID, int ctrlValueID, const char* userID, const char* wkstationID) = 0;

		/*
	 * 执行控制
	 * 参数:
	   controlID -- 控制对象ID
	   ctrlValueID -- 控制值ID ( IControlValue*->ID() )
	   CRequestItem::ScadaObjType -- scada类型
	   */

	virtual int Execute(int controlID, int ctrlValueID,CRequestItem::ScadaObjType objType) = 0;
	virtual int StyleSwitch(int styleid) = 0;//模式切换
	virtual int SequenceCtrl(int ctrlid) = 0;//顺控
	virtual int GroupCtrl(int ftype) = 0;//发电机群控


	virtual bool BeginGroupControl() = 0;  //不知道什么作用 
	virtual bool EndGroupControl() = 0;	//不知道什么作用 
	
public:
    static const char* GetIntfName() {return IID_IScadaControl;}; 
};

/***
 * Scada操作接口
 ***/
class IScadaOperate : public IControlBase
{
public:
	/*
	 * 获取当前操作对象的操作类型
	 * 参数: 无
	 * 返回: IScadaOperateType* 操作类型接口指针
	 */
	virtual IScadaOperateType* Type() = 0;

	/*
	 * 枚举所有控制值（控制值不一定有效, IControl*->IsValid()无意义）
	 * 参数: 无
	 * 返回: std::vector<IControlValue*> 控制值集合
		!!注意: vector容器对象销毁前，用户需释放其中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual std::vector<IControlValue*> ListValues() = 0;

	/*
	 * 根据操作对象类型枚举所有控制值（控制值不一定有效）
	 * 参数:
	   objType -- CRequestItem::ScadaObjType 操作对象类型
	 * 返回: std::vector<IControlValue*> 控制值集合
		!!注意: vector容器对象销毁前，用户需释放其中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual std::vector<IControlValue*> ListValues(CRequestItem::ScadaObjType objType) = 0;

	/*
	 * 根据操作对象ID和类型枚举所有控制值
	 * 参数:
	   id -- 操作对象ID
	   objType -- CRequestItem::ScadaObjType 操作对象类型
	 * 返回: std::vector<IControlValue*> 控制值集合
		!!注意: vector容器对象销毁前，用户需释放其中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual std::vector<IControlValue*> ListValues(int id, CRequestItem::ScadaObjType objType) = 0;

	/*
	 * 执行操作
	 * 参数:
	   id -- 操作对象ID
	   objType -- CRequestItem::ScadaObjType 操作对象类型
	   ctrlValueID -- 控制值ID ( IControlValue*->ID() )
	 * 返回: int
			 0-成功; 1-失败; 2-超时; 3-操作被拒绝；6-用户取消操作
	 */
	virtual int Execute(int id, CRequestItem::ScadaObjType objType, int ctrlValueID) = 0; 

	/*
	 * 执行操作
	 * 参数:
	   id -- 操作对象ID
	   objType -- CRequestItem::ScadaObjType 操作对象类型
	   ctrlValueID -- 控制值ID ( IControlValue*->ID() )
	   userID -- const char* 用户ID
	   wkstationID -- const char* 工作站ID
	 * 返回: int
			 0-成功; 1-失败; 2-超时; 3-操作被拒绝；6-用户取消操作
	 */
	virtual int Execute(int id, CRequestItem::ScadaObjType objType, int ctrlValueID, const char* userID, const char* wkstationID) = 0;

public:
    static const char* GetIntfName() {return IID_IScadaOperate;}; 

};

/***
 * Scada设置接口
 ***/
class IScadaSetting : public IControlBase
{
public:
	/*
	 * 获取当前设置对象的设置类型
	 * 参数:无
	 * 返回: IScadaSettingType* 设置类型接口指针
	 */
	virtual IScadaSettingType* Type() = 0;

	/*
	* 基本信息召唤
	* 参数:
	commsrcID -- src源号
	cpuID -- CPU号
	* 返回: void 
	* !!本函数采用异步机制，由回调函数IAsyncReturn::OnReturn(...)通知用户返回
	*/
	virtual void CallBase(int commsrcID, int cpuID) = 0;

	/*
	 * 定值召唤
	 * 参数:
	   commsrcID -- 设置对象ID
	   cpuID -- cpuid
	   nArea     -- 定值区
	   nCount	 -- [Out] 数组大小
	   pPoints	 -- [Out] 数组大小
	   pcoes	 -- [Out] 系数(数组)
	   pvals	 -- [Out] 值(数组)
	 * 返回: void 
	 * !!本函数采用异步机制，由回调函数IAsyncReturn::OnReturn(...)通知用户返回
	 */
	virtual void CallSetting(int commsrcID, int cpuID, int& nArea, int& nCount, int* pPoints, double* pcoes, double* pvals) = 0;

	/*
	 * 版本召唤
	 * 参数:
	   settingID  -- 设置对象ID
	   idString	  -- [Out] C字符串
	   softwareId -- [Out] 软件ID
	 * 返回: void 
	 * !!本函数采用异步机制，由回调函数IAsyncReturn::OnReturn(...)通知用户返回
		 以下若无特别说明，均采用同步调用机制
	 */
	virtual void CallVersion(int commsrcID,char* strVender, char* strSoftver, char* strMode, int bufSize) = 0;

	/*
	 * 修改定值
	 * 参数:
	   settingID -- 设置对象ID
	   nArea     -- 定值区
	   nStart	 -- 起始序号
	   nSize	 -- 数组大小
	   pcoes	 -- 系数(数组)
	   pvals	 -- 值(数组)
	 * 返回: int
			 0-成功; 1-失败; 2-超时; 3-设置被拒绝；6-用户取消操作
	 */
	virtual int ModifySetting(int commsrcID,  int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;

	/*
	 * 定值区切换
	 * 参数:
	   settingID -- 设置对象ID
	   cpuID -- cpuid
	   nArea     -- 定值区
	 * 返回: int
			 0-成功; 1-失败; 2-超时; 3-设置被拒绝；6-用户取消操作
	 */
	virtual int SwitchArea(int commsrcID, int nArea) = 0;
	virtual int SwitchActArea(int commsrcID, int cpuID, int nArea) = 0;
	virtual int SwitchEditArea(int commsrcID, int cpuID, int nArea) = 0;

	virtual void PresetSetting(int commsrcID, int cpuID, int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;
	virtual void PresetSetting_ByS(int commsrcID, int cpuID, int nArea, int nStartPoint, int nCount, const double* pcoes, const double* pvals) = 0;
	virtual void SaveOrCancel(int commsrcID, int cpuID, int nArea, int nPoint, bool bSave) = 0;
	virtual void ScadaSetting(int commsrcID,int cpu, int iarea,int settingid) = 0;


public:
    static const char* GetIntfName() {return IID_IScadaSetting;}; 
};

/*
class IScadaRing : public IControlBase
{
public:
	virtual IScadaRingType* Type() = 0;
	virtual bool RingBell() = 0;
	virtual bool RingWhistle() = 0;
	virtual bool MuteBell() = 0;
	virtual bool MuteWhistle() = 0;

	static const char* GetInfName()
	{
		return IID_IScadaRing;
	}
};
*/

#endif