/*********************************************************
 * scadactrl_defines.h -- scadactrl模块宏定义
 * date: 2008-07-08(hongkeqin@xjgc.com)
 *********************************************************/

#ifndef SCADACTRL_DEFINES_H
#define SCADACTRL_DEFINES_H

#define MODULE_SCADACTRLCLIENT "ctrlclient"
#define MODULE_SCADACTRLSERVER "ctrlserver"

#define CLSID_IControlFactory		"2D27C20C-0563-4d1c-A00D-A50C87071264" //GUID
#define CLSID_IRAWCTRL				"A6491917-E048-4973-ADA7-62133C63DB71"

#define IID_IControlFactory			"IControlFactory"		//控制类型工厂接口
#define IID_IControlTypeBase		"IControlTypeBase"		//控制类型基类接口
#define IID_IScadaControlType		"IScadaControlType"		//Scada控制类型接口
#define IID_IControlValue			"IControlValue"			//Scada控制值类型接口
#define IID_IScadaOperateType		"IScadaOperateType"		//Scada操作类型接口
#define IID_IScadaSettingType		"IScadaSettingType"		//Scada设置类型接口
#define IID_IControlBase			"IControlBase"			//控制基类接口
#define IID_IScadaControl			"IScadaControl"			//Scada控制接口
#define IID_IScadaOperate			"IScadaOperate"			//Scada操作接口
#define IID_IScadaSetting			"IScadaSetting"			//Scada设置接口
#define IID_IAsyncReturn			"IAsyncReturn"			//异步控制回调接口，由控制客户端调用者实现
#define IID_IRAWCTRL				"IRawCtrl"				//控制下发原子接口

#endif