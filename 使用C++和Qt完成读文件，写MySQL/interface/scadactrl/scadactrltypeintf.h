/*******************************************************
 * scadactrltypeintf.h -- scada控制类型接口定义
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __SCADACTRLTYPEINTF_H_20080708
#define __SCADACTRLTYPEINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"

class IScadaControl;
class IScadaOperate;
class IScadaSetting;

/*****
 * 控制类型基类接口
 *****/
class IControlTypeBase : public IICSUnknown
{
public:
	/*
	 * 获取名称
	 * 参数: 无
	 * 返回: const char* 
	 */
	virtual const char* Name() = 0;

	/*
	 * 获取描述
	 * 参数: 无
	 * 返回: const char* 
	 */
	virtual const char* Desc() = 0;

public:
    static const char* GetIntfName() {return IID_IControlTypeBase;}; 
};

/*****
 * Scada控制类型接口
 *****/
class IScadaControlType : public IControlTypeBase
{
public:
	/*
	 * 创建Scada控制对象
	 * 参数: 无
	 * 返回: IScadaControl*
	 */
	virtual IScadaControl* CreateControl() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaControlType;}; 

};

/*****
 * Scada控制值类型接口
 *****/
class IControlValue : public IControlTypeBase
{
public:
	/*
	 * 获取当前控制值类型ID
	 * 参数: 无
	 * 返回: int 对应控合、控分、升、降、停等具体类型的ID
	 */
	virtual int ID() = 0;

	/*
	 * 获取当前控制操作类型
	 * 参数: 无
	 * 返回: int 对应控合、控分、升、降、停等具体类型的编码值
	 */
	virtual int Value() = 0;

	/*
	 * （根据当前状态量值判断）当前控制值是否有效
	 * 参数: 无
	 * 返回: bool
			true -- 控制有效
			false -- 控制无效
	 */
	virtual bool IsValid() = 0;

public:
    static const char* GetIntfName() {return IID_IControlValue;}; 

};

/*****
 * Scada操作类型接口
 *****/
class IScadaOperateType : public IControlTypeBase
{
public:
	/*
	 * 创建Scada操作对象
	 * 参数: 无
	 * 返回: IScadaOperate*
	 */
	virtual IScadaOperate* CreateOperate() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaOperateType;}; 
};

/*****
 * Scada设置类型接口
 *****/
class IScadaSettingType : public IControlTypeBase
{
public:
	/*
	 * 创建Scada设置对象
	 * 参数: 无
	 * 返回: IScadaOperate*
	 */
	virtual IScadaSetting* CreateSetting() = 0;

public:
    static const char* GetIntfName() {return IID_IScadaSettingType;}; 
};
#endif

