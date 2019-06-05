/*****************************************************************************/
/*许继电气股份有限公司                                     版权：		     */
/*****************************************************************************/
/* 本源代码及其相关文档为河南许昌许继电气股份有限公司独家所有，未经明文许    */
/* 可不得擅自修改或发布，否则将追究相关的法律责任。                          */
/*                                                                           */
/*                      河南许昌许继股份有限公司                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/

/*
    项目名称    ：  通讯服务框架
    文件名      ：  CSFDPInterface.h
    描述        ：  
    版本        ：  0.0.1
    作者        ：  高建琨
    日期        ：  2008.6
*/
#ifndef CSFAPPINTERFACE_H
#define CSFAPPINTERFACE_H

#include "csfcdeinterface.h"
#include "csfcfginterface.h"

#ifdef WIN32
#ifdef CSFAPPINTERFACE_DLL                    
class _declspec(dllimport) ICSF_APP_CallBackInterface;
class _declspec(dllexport) ICSF_APP_Interface;
extern "C" 
	_declspec(dllexport) ICSFUnknown* GetCSFUnknown();
#else                                           
class _declspec(dllexport) ICSF_APP_CallBackInterface;
class _declspec(dllimport) ICSF_APP_Interface;
extern "C" 
	_declspec(dllimport) ICSFUnknown* GetCSFUnknown();
#endif
#else//UNIX,LINUX等(gnu)
class ICSFUnknown;
class ICSF_APP_CallBackInterface;
class ICSF_APP_Interface;
extern "C" 
	  ICSFUnknown* GetCSFUnknown();
#endif


/*************************************************
  类名称:  ICSF_APP_CallBackInterface
  类描述:  CSF与外部应用交互接口定义
*************************************************/
class ICSF_APP_CallBackInterface  :public ICSF_CDE_ExchCallBackInterface,
								   public ICSF_CDE_CfgCallBackInteface,
								   public ICSF_CDE_ModeCallBackInteface//调用方定义的类
{
public:
		/**
		参数:nSrcId 服务id
		nCSFId A/B网标志 0:A网 1:B网 
			   0xffffffff表示该服务失去联系
		bState 通道 0:断,1主通道,2连通 // 彭世康 20111228 注释
		*/
	virtual void SrcStateChanged(CSF_UINT32 nSrcId,
		CSF_UINT32 nCSFId,
		CSF_UINT32 nDpId,
		CSF_BOOLEAN bState)	= 0;

	/**
		参数:nNode 前置机id;nProt 协议id
	
			nState 登陆结果 0:不成功,1:成功
		注意:当tcp发生断开时,我会主动报登陆失败的
	*/
	virtual void LoginReturn(CSF_UINT8 nNode,CSF_UINT8 nProt,CSF_UINT8 nState) =0;
};

/*************************************************
  类名称:  ICSF_APP_Interface
  类描述:  CSF框架应用服务接口定义
*************************************************/
class ICSF_APP_Interface :  public ICSFUnknown
{
public:
	/***************************************************************************
	函数：Initialize
	功能：初始化本模块（CSF的应用服务接口AppInterface）
	参数：int m_nAppid app传递的应用id
	返回：CSF_INT32，0：成功，初始化成功
	                 1：失败，初始化失败

	说明：用户在使用本模块时，应当首先调用此函数
	***************************************************************************/
	virtual CSF_INT32 Initialize (unsigned int m_nAppid)                                =  0;

	/***************************************************************************
	函数：Finalize
	功能：清理本模块所使用资源
	参数：无
	返回：无

	说明：用户在退出程序时，需要调用本函数释放资源
	***************************************************************************/
	virtual void Finalize ()                                       =  0;

	/***************************************************************************
	函数：SetAppWorkState
	功能：设置目前本应用服务接口的工作状态
	参数：CSF_BOOLEAN bWork  0-〉表示备  1-〉表示主

    说明：如果后台应用采用的是主备系统，
	      需要利用此函数通知CSF服务接口本机当前的主备状态
	***************************************************************************/
	virtual void SetAppWorkState(CSF_BOOLEAN bWork)                =  0;


	/***************************************************************************
	名称：  Advise
	描述：  设置回调接口
	参数：  ICSF_APP_CallBackInterface* pCallback，回调接口
	返回值：无

	说明：  设置回调接口
	***************************************************************************/
	virtual void Advise(ICSF_APP_CallBackInterface* pCallback)=0;
public:
	ICSF_CDE_ExchInteface*  m_pExchInterface;
	ICSF_CDE_CfgInteface* m_pCfgInterface;
};

#endif
