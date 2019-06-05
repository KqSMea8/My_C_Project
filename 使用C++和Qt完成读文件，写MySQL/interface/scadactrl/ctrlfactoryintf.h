/*******************************************************
 * ctrlfactoryintf.h -- scada控制工厂接口
 * 
 * date: 2008.07.08 hongkeqin@xjgc.com
 *******************************************************/

#ifndef __CTRLFACTORYINTF_H_20080708
#define __CTRLFACTORYINTF_H_20080708

#include "../icsunknown.h"
#include "./scadactrl_typedef.h"
#include "./scadactrl_defines.h"
//std header
#include <vector>

class IControlTypeBase;
class IScadaControlType;
class IScadaOperateType;
class IScadaSettingType;

/***
 * 控制类型工厂接口
 * 功能: 获取控制类型
 ***/
class IControlFactory : public IICSUnknown
{
public:
	/*
	 * 获取当前所有控制类型列表
	 * 参数:无
	 * 返回: const std::vector<IControlTypeBase*>&
		!!注意: 用户不需管理容器中每个对象的引用计数
		以下若无特别说明, 返回的接口对象都需用户释放
	 */
	virtual const std::vector<IControlTypeBase*>& ListTypes() = 0;
	
	/*
	 * 根据类型名称返回控制类型(基类)
	 * 参数:
	   tpName -- 类型名称
	 * 返回: IControlTypeBase*
	 */
	virtual IControlTypeBase* GetTypeByName(const char* tpName) = 0;

	/*
	 * 根据类型名称返回控制类型
	 * 参数:
	   tpName -- 类型名称
	 * 返回: IScadaControlType*
	 */
	virtual IScadaControlType* GetControlTypeByName(const char* tpName) = 0;

	/*
	 * 根据类型名称返回操作类型
	 * 参数:
	   tpName -- 类型名称
	 * 返回: IScadaOperateType*
	 */
	virtual IScadaOperateType* GetOperateTypeByName(const char* tpName) = 0;
	/*
	 * 根据类型名称返回设置类型
	 * 参数:
	   tpName -- 类型名称
	 * 返回: IScadaSettingType*
	 */
	virtual IScadaSettingType* GetSettingTypeByName(const char* tpName) = 0;

public:
    static const char* GetIntfName() {return IID_IControlFactory;}; 
};

#endif