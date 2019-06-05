/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2006-2015   */
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
    文件名      ：  CSFCfgInterface.h
    描述        ：  本文件定义了统一数据模型配置接口
    版本        ：  1.0.1
    作者        ：  连湛伟
    
    创建日期    ：  2008.9     

*/


#ifndef CSFCFGINTERFACE_H
#define CSFCFGINTERFACE_H

#include "csfdataobject.h"

/*************************************************
  类名称:  ICSF_CDE_ModeCallBackInteface
  类描述:  运行状态回调接口
*************************************************/
class ICSF_CDE_ModeCallBackInteface
{
public:
	/***************************************************************************
	函数：GetModeReturn
	功能：获取对方的运行模式的异步方式返回
	参数：
          CSF_UINT8 nMode,运行模式
		    （1；2；3参见相关约定文档）
          
    返回：无
    说明：
	***************************************************************************/
	virtual void GetModeReturn(CSF_UINT8 nMode,
		CSF_UINT32 nNode = 1,
		CSF_UINT32 nProt = 1,
		CSF_UINT32 m_nApp = 1)                 = 0;
};

/*************************************************
  类名称:  ICSF_CDE_ModeInteface
  类描述:  运行状态接口
*************************************************/
class ICSF_CDE_ModeInteface
{
public:
	/***************************************************************************
	函数：InformRunMode
	功能：通知自己当前的运行模式
	参数：
          CSF_UINT8 nMode,运行模式（1；2；3参见相关约定文档）
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
	***************************************************************************/
	virtual CSF_INT32 InformRunMode(CSF_UINT8 nMode,
		CSF_UINT32 nNode = 1,
		CSF_UINT32 nProt = 1,
		CSF_UINT32 m_nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetRunMode
	功能：获取对方的运行模式
	参数：
          CSF_UINT8* pMode,运行模式
		    （0:需要等待回调接口的返回；1；2；3参见相关约定文档）
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
	***************************************************************************/
	virtual CSF_INT32 GetRunMode(CSF_UINT8* pMode,
		CSF_UINT32 nNode = 1,
		CSF_UINT32 nProt = 1,
		CSF_UINT32 m_nApp = 1)                 = 0;

public:
	/*名称：ExchAdvise
	描述：设置回调接口
	参数：   
	ICSF_CDE_ModeCallBackInteface* pCallBack，传递回调接口
	返回值：
	无
	*/
	virtual void ExchAdvise(ICSF_CDE_ModeCallBackInteface* pCallBack) = 0;  

};


/*************************************************
  类名称:  ICSF_CDE_CfgCallBackInteface
  类描述:  配置回调接口，
*************************************************/
class ICSF_CDE_CfgCallBackInteface
{
//整体配置
public:
	/***************************************************************************
	函数：ClearConfigReturn
	功能：清除配置返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void ClearConfigReturn(CSF_UINT32 nResult,
						CSF_UINT32 nNode = 1,
						CSF_UINT32 nProt = 1,
						CSF_UINT32 nApp = 1)                 = 0;


//数据源及通道
public:
	/***************************************************************************
	函数：AddSrcReturn
	功能：添加数据源返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void AddSrcReturn(CSF_UINT32 nResult)                 = 0;


	/***************************************************************************
	函数：DelSrcReturn
	功能：删除数据源返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void DelSrcReturn(CSF_UINT32 nResult)                 = 0;


	/***************************************************************************
	函数：AddSrcChnlReturn
	功能：添加数据源返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void AddSrcChnlReturn(CSF_UINT32 nResult)             = 0;


	/***************************************************************************
	函数：DelSrcChnlReturn
	功能：清除配置返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void DelSrcChnlReturn(CSF_UINT32 nResult)             = 0;



//逻辑对象及数据对象配置信息
public:
	/***************************************************************************
	函数：AddObjReturn
	功能：添加数据源返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void AddObjReturn(CSF_UINT32 nResult,
						CSF_UINT32 nNode = 1,
						CSF_UINT32 nProt = 1,
						CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：SetObjReturn
	功能：添加数据源返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void SetObjReturn(CSF_UINT32 nResult,
						CSF_UINT32 nNode = 1,
						CSF_UINT32 nProt = 1,
						CSF_UINT32 nApp = 1)                 = 0;


	/***************************************************************************
	函数：DelObjReturn
	功能：删除对象返回
	参数：
	      CSF_UINT32 nResult,
		             0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令   
          
    返回：无
    说明：
	***************************************************************************/
	virtual void DelObjReturn(CSF_UINT32 nResult,
						CSF_UINT32 nNode = 1,
						CSF_UINT32 nProt = 1,
						CSF_UINT32 nApp = 1)                 = 0;

};


/*************************************************
  类名称:  ICSF_CDE_CfgInteface
  类描述:  配置接口，
*************************************************/
class ICSF_CDE_CfgInteface
{
//整体配置
public:
	/***************************************************************************
	函数：ClearConfig()
	功能：清理配置信息（包括相关的lo与do，不包含src与srcchnl）
	参数：
	      CSF_UINT32 nNode，通讯主机ID
	
	      CSF_UINT32 nProt，协议解析模块Id
	  
		  CSF_UINT32 nApp， 应用Id  
          
    返回：CSF_INT32，0：成功
                     1：失败
					 2: 需要等待回调接口(ClearConfigReturn)的返回
    说明：
			1）本函数的返回值如果为2，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   ClearConfigReturnn函数回调，才能获取结果
	        
	***************************************************************************/
	virtual CSF_INT32 ClearConfig(
		                    CSF_UINT32 nNode = 1,
		                    CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)          = 0;


//数据源及通道
public: 
	/***************************************************************************
	函数：AddSrc
	功能：添加数据源对象
	参数：
          CCSFList<CCSF_Src>* pSrcList，数据源对象链表
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令
					 2: 指令被框架接收，但执行结果需要等待回调通知
    说明：
			1）本函数的返回值如果为2，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   DelSrcChnlReturn函数回调才能获取删除结果
	        
	***************************************************************************/
	virtual CSF_INT32 AddSrc(
		CCSFList<CCSF_Src>* pSrcList)          = 0;


	/***************************************************************************
	函数：GetSrc
	功能：读取数据源
	参数：          
          
    返回：CCSFList<CCSF_Src>*，数据源列表，CSF_NULL时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_Src>* GetSrc()         = 0;

	
	/***************************************************************************
	函数：DelSrc
	功能：删除数据源对象
	参数：
          CCSFList<CCSF_Src>* pSrcList，数据源对象链表,每个src的Id为必有成员  
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令
					 2: 指令被框架接收，但执行结果需要等待回调通知
    说明：
			1）本函数的返回值如果为2，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   DelSrcChnlReturn函数回调才能获取删除结果
	        
	***************************************************************************/
	virtual CSF_INT32 DelSrc(
		CCSFList<CCSF_Src>* pSrcList)          = 0;


	/***************************************************************************
	函数：DelSrcChnl
	功能：删除数据源通道
	参数：
          CCSFList<CCSF_SrcChnl>* pSrcChnlList，某个（或多个）数据源相关的所有通道   
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令
					 2: 指令被框架接收，但执行结果需要等待回调通知
    说明：
			1）本函数的返回值如果为2，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   DelSrcChnlReturn函数回调才能获取删除结果
			
	***************************************************************************/
	virtual CSF_INT32 DelSrcChnl(
		CCSFList<CCSF_SrcChnl>* pSrcChnlList)          = 0;

	/***************************************************************************
	函数：AddSrcChnl
	功能：添加数据源通道
	参数：
          CCSFList<CCSF_SrcChnl>* pSrcChnlList，数据源相关的所有通道   
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
                     1：失败，表示框架目前无法接收此指令
					 2: 指令被框架接收，但执行结果需要等待回调通知
    说明：
			1）本函数的返回值如果为2，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   AddSrcChnlReturn函数回调后，才允许进行下一次AddSrcChnl调用；
	        2）要求Src对象的Id >= 1
			3）在添加“通道时”，必须一次性添加某个数据源所有的相关通道
	***************************************************************************/
	virtual CSF_INT32 AddSrcChnl(
		CCSFList<CCSF_SrcChnl>* pSrcChnlList)          = 0;

	/***************************************************************************
	函数：GetSrcChnlBySrc
	功能：读取数据源
	参数：          
          
    返回：CCSFList<CCSF_SrcChnl>*，数据源列表，CSF_NULL时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_SrcChnl>* GetSrcChnlBySrc(CSF_INT32 nSrc)         = 0;

	/***************************************************************************
	函数：GetAllSrcChnl
	功能：读取数据源
	参数：          
          
    返回：CCSFList<CCSF_SrcChnl>*，数据源列表，CSF_NULL时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_SrcChnl>* GetAllSrcChnl()         = 0;


//逻辑对象及数据对象配置信息
public:
	/***************************************************************************
	函数：GetObjByCSFId
	功能：根据ID获取对象
	参数：
          CSF_UINT64 nId，要获取对象的ID
          
    返回：CCSF_Object*，对象指针，CSF_NULL标识失败
    说明：
	***************************************************************************/
	virtual CCSF_Object* GetObjByCSFId(CSF_UINT64 nId,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetObjByAppId
	功能：根据ID获取对象
	参数：
          CSF_UINT32 nId，要获取对象的ID
          
    返回：CCSF_Object*，对象指针，CSF_NULL标识失败
    说明：
	***************************************************************************/
	virtual CCSF_Object* GetObjByAppId(CSF_UINT32 nId,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetObjByType
	功能：根据类型获取对象
	参数：
          CSF_UCHAR nType，要获取对象的类型
          
    返回：CCSFList<CCSF_Object>*，对象列表，，CSF_NULL时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_Object>* GetObjByType(
							CSF_UCHAR nType,	
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetObjByElderId
	功能：根据父对象获取对象
	参数：
          CSF_UINT32 nElder,要父对象的ID

          CSF_UCHAR  subType,子对象的类型，0xFF时，标识所有子对象
          
    返回：CCSFList<CCSF_Object>*，对象列表，，CSF_NULL时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_Object>* GetObjByElderId(
							CSF_UINT32 nElder,
							CSF_UCHAR  subType,		
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetAllDoAppIdAndRefByType
	功能：根据数据对象的类型获取所有数据对象的Id和参引
	参数：
          CCSFList<CSF_CHAR>**,所有数据对象的参引；
          CCSFList<CSF_UINT32>**,所有数据对象的ID（应用识别）；
		  CSF_UINT8 nSpecDoType,要求的数据对象类型，0xFF表示所有类型DO
          
    返回：CSF_UINT32，对象数目，0时失败
    说明：
	***************************************************************************/
	virtual CSF_UINT32 GetAllDoAppIdAndRefByType(
							CCSFList<CSF_CHAR>**,
							CCSFList<CSF_UINT32>**,
							CSF_UINT8 nSpecDoType,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：GetAllDoAppIdAndCSFIdByType
	功能：根据数据对象的类型获取所有数据对象的AppId和CSDId
	参数：
          CCSFList<CSF_UINT64>** ppCSFIdList,所有数据对象的CSFId；
          CCSFList<CSF_UINT32>** ppAppIdList,所有数据对象的AppID；
		  CSF_UINT8 nSpecDoType,要求的数据对象类型，0xFF表示所有类型DO
          
    返回：CSF_UINT32，对象数目，0时失败
    说明：
	***************************************************************************/
	virtual CSF_UINT32 GetAllDoAppIdAndCSFIdByType(
							CCSFList<CSF_UINT64>** ppCSFIdList,
							CCSFList<CSF_UINT32>** ppAppIdList,
							CSF_UINT8 nSpecDoType,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;


	/***************************************************************************
	函数：GetAllLoIDAndAppId
	功能：获取逻辑对象的Id与AppId
	参数：
          CCSFList<CSF_UINT32>** ppIdList, 要获取的所有逻辑对象Id
          CCSFList<CSF_UINT32>** ppAppIdList,要获取的所有逻辑对象AppId
		  CSF_UINT8 nLoType,要求的逻辑对象类型，0xFF表示所有类型LO
          
    返回：CSF_UINT32，对象数目，0时失败
    说明：
	***************************************************************************/
	virtual CSF_UINT32 GetAllLoIDAndAppId(
		CCSFList<CSF_UINT32>** ppIdList,
		CCSFList<CSF_UINT32>** ppAppIdList,
		CSF_UINT8 nLoType,
		CSF_UINT32 nNode = 1,
		CSF_UINT32 nProt = 1,
		CSF_UINT32 nApp = 1)                 = 0;


	/***************************************************************************
	函数：GetLoByAttribute
	功能：根据属性获取相应逻辑对象
	参数：
          CSF_UCHAR  nLOType, 要获取的逻辑对象的类型,0xFF指所有逻辑对象
          CSF_UINT32 nAttribute，要获取的逻辑对象的属性
          
    返回：CSF_UINT32，对象数目，0时失败
    说明：
	***************************************************************************/
	virtual CCSFList<CCSF_Object>* GetLoByAttribute(
		CSF_UCHAR  nLOType,
		CSF_UINT32 nAttribute)                 = 0;


	/***************************************************************************
	函数：AddObj
	功能：添加对象
	参数：
          CCSFList<CCSF_Object>* pObjList,添加的对象

          CSF_UINT32 nNode，通讯主机ID

          CSF_UINT32 nProt，协议解析模块Id
 
          CSF_UINT32 nApp， 应用Id
		  
	返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
			         1：失败，表示框架目前无法接收此指令
					 2: 失败，表示对象重复
					 3: 指令被框架接收，但执行结果需要等待回调通知
    说明：
			1）本函数的返回值如果为3，必须等待ICSF_CDE_CfgCallBackInteface接口的
			   AddObjReturn函数回调后，才允许进行下一次AddObj调用；
	        1）针对同一个对象，在调用完AddObj添加后，可以使用SetObj对这个新添的对象
	           进行修改，譬如修改其des，oid等等；
	***************************************************************************/
	virtual CSF_INT32 AddObj(CCSFList<CCSF_Object>* pObjList,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;
	
	/***************************************************************************
	函数：SetObj
	功能：修改对象
	参数：
          CCSFList<CCSF_Object>* pObjList,修改的对象，没有修改的属性可以为空

          CSF_UINT8  nValidate, 1：csfid有效，修改的是除csfid之外的属性
		                        2：appid有效，修改的是除appid之外的属性
								3：Ref(参引)有效，修改的是除参引之外的属性
          
	返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
			         1：失败，表示框架目前无法接收此指令
					 2：失败，表示无法修改的属性
					 3: 指令被框架接收，但执行结果需要等待回调通知
    说明：
	***************************************************************************/
	virtual CSF_INT32 SetObj(CCSFList<CCSF_Object>* pObjList,
		                    CSF_UINT8  nValidate,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;
	
	/***************************************************************************
	函数：SetAppIdByCSFId
	功能：修改对象
	参数：
          CCSFList<CSF_UINT64>* pIdList,数据对象Id链表（应用识别）;
		  CCSFList<CSF_UINT64>* pCSFIdList,数据对象CSFId;
		  CSF_UINT32 nSize,对象的数目
          CSF_UINT8 nType,对象类型
          
	返回：CSF_INT32，0：成功，表示指令被框架接收，并完成处理
					 1：失败，表示框架目前无法接收此指令
					 2：失败，表示无法修改的属性
					 3: 指令被框架接收，但执行结果需要等待回调通知
    说明：
	***************************************************************************/
	virtual CSF_INT32 SetAppIdByCSFId(CSF_UINT32* pIdList,
							CSF_UINT64* pCSFIdList,
							CSF_UINT32 nSize,
							CSF_UINT8 nType,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;




	/***************************************************************************
	函数：DelObjByCSFId
	功能：根据CSFID删除对象
	参数：
          CSF_UINT64 nId，要删除对象的CSFID
          
	返回：CSF_INT32，
	        0：成功，表示指令被框架接收，并完成处理
			1：失败，表示框架目前无法接收此指令
			2：失败，表示无法修改的属性
			3: 指令被框架接收，但执行结果需要等待回调通知(DelObjReturn)
    说明：
	***************************************************************************/
	virtual CSF_INT32 DelObjByCSFId(CSF_UINT64 nId,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：DelObjByAppId
	功能：根据AppID删除对象
	参数：
          CSF_UINT32 nId，要删除对象的AppID
          
	返回：CSF_INT32，
			0：成功，表示指令被框架接收，并完成处理
			1：失败，表示框架目前无法接收此指令
			2：失败，表示无法修改的属性
			3: 指令被框架接收，但执行结果需要等待回调通知(DelObjReturn)
    说明：
	***************************************************************************/
	virtual CSF_INT32 DelObjByAppId(CSF_UINT32 nId,
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：DelObjByType
	功能：根据类型删除对象
	参数：
          CSF_UCHAR nType，要删除对象的类型
          
	返回：CSF_INT32，
			0：成功，表示指令被框架接收，并完成处理
			1：失败，表示框架目前无法接收此指令
			2：失败，表示无法修改的属性
			3: 指令被框架接收，但执行结果需要等待回调通知(DelObjReturn)
    说明：
	***************************************************************************/
	virtual CSF_INT32 DelObjByType(
							CSF_UCHAR nType,	
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

	/***************************************************************************
	函数：DelObjByElderId
	功能：根据父对象删除对象
	参数：
          CSF_UINT32 nElder,要删除对象的父对象的ID

          CSF_UCHAR  subType,子对象的类型，0xFF时，标识所有子对象
          
	返回：CSF_INT32，
			0：成功，表示指令被框架接收，并完成处理
			1：失败，表示框架目前无法接收此指令
			2：失败，表示无法修改的属性
			3: 指令被框架接收，但执行结果需要等待回调通知(DelObjReturn)
    说明：
	***************************************************************************/
	virtual CSF_INT32 DelObjByElderId(
							CSF_UINT32 nElder,
							CSF_UCHAR  subType,		
							CSF_UINT32 nNode = 1,
							CSF_UINT32 nProt = 1,
							CSF_UINT32 nApp = 1)                 = 0;

public:
	/*名称：ExchAdvise
	描述：设置回调接口
	参数：   
	       ICSF_CDE_CfgCallBackInteface* pCallBack，传递回调接口
	返回值：
	无
	*/
	virtual void ExchAdvise(ICSF_CDE_CfgCallBackInteface* pCallBack) = 0;  

public:
	ICSF_CDE_ModeInteface*  m_pModeInterface;
	ICSF_CDE_CfgInteface()
	{
		m_pModeInterface = CSF_NULL;
	}
};

#endif
