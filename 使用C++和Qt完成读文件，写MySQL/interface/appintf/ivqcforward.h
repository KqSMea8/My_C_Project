/*******************************************************************************************************
 * ivqcforward.h -- VQC数据转发接口定义
 * 
 * date: 2008.12.27 hongkeqin@xjgc.com
 * revised:
		增加IRecvData回调接口定义
		增加RegisterCallBack(...)方法
		增加ForwardData(int, VQC_T::tCMDTYPE, const QVariant&, VQC_T::tRETVAL)方法 2009.05.12
		修改ForwardData(int, VQC_T::tCMDTYPE, const QVariant&, VQC_T::tRETVAL)说明 2009.06.09
 *******************************************************************************************************/

#ifndef _IVQCFORWARD_H_
#define _IVQCFORWARD_H_

#include "icsunknown.h"
#include "vqcforwardtypes.h"
//std header
#include <qvariant.h>

#define CLSID_VQCFORWARD	"A57D592C-5B47-4fe5-B30A-183266D40400"
#define IID_IVQCFORWARD		"ivqcforward"
#define IID_ICVTFORWARD		"icvtforward"
#define IID_ISMFORWARD		"ismforward"
#define MODULE_VQCFORWARD	"vqcforward"

class IRecvData
{
public:
	/*
	 * 1. 处理 远端发来的数据请求
	 * 1.1 当cmdType=VQC_T::CALLDATA时，表示总召，这时id, var参数无效
	 * 参数：
	   id -- 对象ID
	   cmdType -- 指令类型
	   var -- QVariant 请求内容
	 * 返回：void
	 */
	virtual void OnRecv(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var) = 0;

	//virtual void OnRecv(IICSStream* pStream);
};

 /***
 * VQC数据转发接口
 ***/
class IVQCForward : public IICSUnknown
{
public:
	
	/*
	 * 转发数据
	 * 参数：
	   id -- 对象ID
	   var -- QVariant 待转发数据
	   timeStamp -- 数据时标
	 * 返回：int
			 0--成功; -1--失败;
	 */
	virtual int ForwardData(int id, const QVariant& var, double timeStamp) = 0; 
	
	/* 获得错误描述信息
	 * 参数：无
	 * 返回: const char* 错误描述
	 */
	virtual const char* ErrorMsg() = 0;

	/* 注册回调接口 [回调接口用于接收远端发来的数据请求]
	 * 参数：
		ptr -- 回调接口
	 * 返回：void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. 转发数据 [用于转发数据请求执行后的结果]
	 * 2. 响应总召数据，这时cmdType=VQC_T::CALLDATA, 参数ret无效 09.06.09
	 * 参数:
	   id -- 对象ID
	   cmdType -- 指令类型
	   var -- QVariant 请求内容
	   ret -- 数据请求处理结果
	 * 返回: int
			 0--成功; -1--失败;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_IVQCFORWARD; } 

};


 /***
 * CVT数据转发接口
 ***/
class ICVTForward : public IICSUnknown
{
public:
	
	/*
	 * 转发遥信数据
	 * 参数：
	   id -- 遥信ID
	   val -- 值
	   timeStamp -- 数据时标
	 * 返回：int
			 0--成功; -1--失败;
	 */
	virtual int ForwardStatus(int id, int val, double timeStamp) = 0; 
	
	/*
	 * 转发遥测数据
	 * 参数：
	   id -- ID
	   val -- 值
	   timeStamp -- 数据时标
	 * 返回：int
			 0--成功; -1--失败;
	 */
	virtual int ForwardAnalog(int id, double val, double timeStamp) = 0; 

	/* 获得错误描述信息
	 * 参数：无
	 * 返回: const char* 错误描述
	 */
	virtual const char* ErrorMsg() = 0;

	/* 注册回调接口 [回调接口用于接收远端发来的数据请求]
	 * 参数：
		ptr -- 回调接口
	 * 返回：void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. 转发数据 [用于转发数据请求执行后的结果]
	 * 2. 响应总召数据，这时cmdType=VQC_T::CALLDATA, 参数ret无效
	 * 参数:
	   id -- 对象ID
	   cmdType -- 指令类型
	   var -- QVariant 请求内容
	   ret -- 数据请求处理结果
	 * 返回: int
			 0--成功; -1--失败;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_ICVTFORWARD; } 

};


/***
 *  接地选线（SM）数据转发接口
 ***/
class ISMForward : public IICSUnknown
{
public:
	
	/*
	 * 转发遥信数据
	 * 参数：
	   id -- 遥信ID
	   val -- 值
	   timeStamp -- 数据时标
	 * 返回：int
			 0--成功; -1--失败;
	 */
	virtual int ForwardStatus(int id, int val, double timeStamp) = 0; 
	
	/*
	 * 转发遥测数据
	 * 参数：
	   id -- ID
	   val -- 值
	   timeStamp -- 数据时标
	 * 返回：int
			 0--成功; -1--失败;
	 */
	virtual int ForwardAnalog(int id, double val, double timeStamp) = 0; 

	/* 获得错误描述信息
	 * 参数：无
	 * 返回: const char* 错误描述
	 */
	virtual const char* ErrorMsg() = 0;

	/* 注册回调接口 [回调接口用于接收远端发来的数据请求]
	 * 参数：
		ptr -- 回调接口
	 * 返回：void
	 */
	virtual void RegisterCallBack(IRecvData* ptr) = 0;

	/*
	 * 1. 转发数据 [用于转发数据请求执行后的结果]
	 * 2. 响应总召数据，这时cmdType=VQC_T::CALLDATA, 参数ret无效
	 * 参数:
	   id -- 对象ID
	   cmdType -- 指令类型
	   var -- QVariant 请求内容
	   ret -- 数据请求处理结果
	 * 返回: int
			 0--成功; -1--失败;
	 */
	virtual int ForwardData(int id, VQC_T::tCMDTYPE cmdType, const QVariant& var, VQC_T::tRETVAL ret) = 0; 
	
public:
    static const char* GetIntfName() { return IID_ICVTFORWARD; } 

};

#endif 
