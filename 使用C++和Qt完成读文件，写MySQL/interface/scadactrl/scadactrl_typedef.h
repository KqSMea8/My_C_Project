/*******************************************************
 * scadactrl_typedef.h -- scada枚举及typedef
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRL_TYPEDEF_H_20080708
#define __SCADACTRL_TYPEDEF_H_20080708

#include "./scadactrl_defines.h"

/***
 *控制枚举定义
 ***/
typedef struct
{
	typedef enum {
		typeNone = 0, typeAnalog, typeStatus, typeAccumulator,
		typeControl, typeSetting, typeSettingArea, typeAlarm,
		typeStation, typeBay, typeEquip, typeSOE, typeSystem,
		typeObjEnd,
	} ScadaObjType; //SCADA对象枚举

	typedef enum { 
		None = 0,
		RealMode,		//真实模式
		EmulationMode	//模拟预演模式
	} ControlMode;
	
} CRequestItem;

class IControlBase;
/***
 * 异步控制回调接口 由控制客户端调用者实现
 ***/
class IAsyncReturn
{
public:
	/*
	 * 控制返回处理方法
	 * 参数:
	   result -- 控制结果 0-成功； 1-失败；2-超时；3-控制被拒绝；4-遥控撤销成功；5-系统自动取消；6-用户取消操作
	   caller -- IControlBase* 返回结果对应的控制操作
	 * 返回: void
	 */
	virtual void OnReturn(int result, IControlBase* caller)=0;

public:
    static const char* GetIntfName() {return IID_IAsyncReturn;}; 
};

#endif