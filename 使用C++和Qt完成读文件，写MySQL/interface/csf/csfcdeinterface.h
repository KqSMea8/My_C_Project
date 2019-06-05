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
    文件名      ：  CSFCdeInterface.h
    描述        ：  本文件定义了统一数据模型交换接口
    版本        ：  1.0.1
    作者        ：  连湛伟
    
    创建日期    ：  2006.4
      
        修改记录
            1.
               修改日期：2007.6    ；修改者：连湛伟
			2.
               修改日期：2008.5    ；修改者：连湛伟

*/


#ifndef CSFCDEINTERFACE_H
#define CSFCDEINTERFACE_H

#include "csfdataobject.h"

/*****************************************************
  类名称:  ICSF_CDE_ExchCallBackInterface
  类描述:  数据交互接口定义，CSF提供
  
  说明：   请首先参阅ICSF_CDE_ExchInteface
*****************************************************/
class ICSF_CDE_ExchCallBackInterface
{
public:
	/***************************************************************************
	函数：SubscriptionAck
	功能：对订阅成功的“数据项”进行确认
	参数：
          CSF_INT32 nSubscbID，确认订阅的ID    

          CSF_UINT32 nApp,确认进行订阅的App
   
	      CSF_UINT32 nSrc,确认订阅的数据源

          CCSFList<CSF_UCHAR>* pDOTypeList,确认要订阅的数据类型
                      请参阅本函数说明2；

    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
          1. 应用程序只有收到“订阅确认”，方能认为订阅成功。只要订阅成功，除非进行
             “订阅撤销”，否则订阅一直有效，即使应用程序退出，或者链路中断

          2. 订阅确认根据项目的需要，可以不传数据，此时pDOTypeList可为CSF_NULL

		  3. 在订阅多项数据内容时，只要有一项无法完成，此次订阅就会返回失败确认
	***************************************************************************/
    virtual CSF_INT32 SubscriptionAck(
        CSF_UINT32 nSubscbID,
		CSF_UINT32 nApp,
        CSF_UINT32 nSrc,
        CCSFList<CSF_UCHAR>* pDOTypeList)                   = 0;

	/***************************************************************************
	函数：Issuance
	功能：根据“Subscription”订阅，当相应的数据主动上传是时，CSF框架会向订阅的app
	      进行数据的“发布”
	参数：
           CSF_INT32 nIssueID，相应“订阅”的ID
		  
           CSF_BOOL bNeedAck，要求接收者（应用层）是否需要给出确认（1时，要求应用
		        需要使用IssuanceAck给出确认）
              
           CSF_UINT32 nTimeout，超时要求，届时如果没有发送成功，csf框架将不再发送此
                Issuance的数据

           CCSFList<CCSFTransBlock>* pDataList，产生的数据的内容
		       
    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
          1. 对于“订阅ID”，0被CSF框架自身所保留使用，所有应用相关的数据,其订阅ID
             必须大于0          
         
		   2. 如果发布的数据是“文件”类型，值的内容是“包含文件名称的全路径”
	***************************************************************************/
	virtual CSF_INT32 Issuance(
        CSF_UINT32 nIssueID,
        CSF_BOOLEAN bNeedAck,
        CSF_UINT32 nTimeout,
		CCSFTransBlock* pTransBlock)                 = 0;

	/***************************************************************************
	函数：GetReturn
	功能：根据“GetData”的要求，当相应数据产生时，通讯处理模块传递它们
	参数：
          CSF_BOOLEAN bRealData，数据是否是直接从数据源读取的

          CSF_UINT32 nResult，本次读取数据的结果
                0,表示全部，成功返回本次所有GetData所要求的数据
                1,表示部分成功，但是还没有全部完成本次所有GetData所要求的数据
                2,表示失败，此时参数中所有的属性值无效
                3,表示失败，有多个Get指令同时下发至同一数据源（后来者失败）
                4,表示失败，此时无法从数据源获取数据（bRealData＝1时可能发生）
    
          CSF_UINT32 nTimeout，超时要求，届时如果没有发送成功，csf框架将不再发
               送此GetReturn所返回的数据
               
          CCSFList<CCSFTransBlock>* pDataList，产生的数据的内容

     返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                      1：失败，表示框架目前无法接收此指令

     说明：
     
       1. 如果返回的数据是“文件”类型，要求pPropList包含的全部是文件，值的内容是
          “包含文件名称的全路径”

	***************************************************************************/
    virtual CSF_INT32 GetReturn(
        CSF_BOOLEAN bRealData,
        CSF_UINT32 nResult,
        CSF_UINT32 nTimeout,
		CCSFTransBlock* pTransBlock)                 = 0;

	/***************************************************************************
	函数：SetReturn
	功能：根据“SetData”的要求，当相应数据产生时，通讯处理模块传递它们
	参数：
          CSF_UINT32 nResult，本次设置数据的结果  
              0,表示全部，成功设置本次SetData所要求的数据，参数中所有的属性值有效
              1,表示全部，成功设置本次SetData所要求的数据，参数中所有的属性值无效
              2,表示成功，但是还没有全部完成本次所有SetData所要求的数据
              3,表示失败，参数中所有的属性值有效
              4,表示失败，参数中所有的属性值无效
              5,表示失败，有多个Set指令同时下发至同一数据源（后来者失败）

          CSF_UINT32 nSetType, 返回所对应的设置类型

          CSF_UINT32g nTimeout，超时要求，届时如果没有发送成功，csf框架将不再发
              送此SetReturn所返回的数据

          CCSFList<CCSFTransBlock>* pDataList，产生的数据的内容

    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
	***************************************************************************/
	virtual CSF_INT32 SetReturn(
        CSF_UINT32 nResult,
		CSF_UINT32 nSetType, 
        CSF_UINT32 nTimeout,
		CCSFTransBlock* pTransBlock)                  = 0;	
}; 

/*************************************************
  类名称:  ICM_ExchInteface
  类描述:  数据交互接口定义，通讯处理模块提供
           CSF需要从通讯处理模块获得，完成数据交换
*************************************************/
class ICSF_CDE_ExchInteface
{
public:
	/***************************************************************************
	函数：Subscription
	功能：通知CSF框架，某个应用（app)希望“订阅”的数据，当外部数据源主动上传
	      相应的数据时，csf框架会利用Issuance进行发布，直到CancelSubscription发生
	参数：
          CSF_INT32 nSubscbID，本次订阅的ID，在“撤销订阅”，以及数据发布时使用；   

          CSF_UINT32 nApp,进行订阅的App；

          CSF_UINT32 nSrc,订阅所针对的数据源，为“OxFFFFFFFF”时，表示针对全部数据源

          CCSFList<CSF_UCHAR> *pDOTypeList，要订阅的“数据类型”，数据类型的定义请参见
		             DataObject_SCADA.h中“专用DO类型定义”；
					 特别地：如果DOTypeList为“CSF_NULL”，标识订阅全部数据类型
 
    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
          1. 特别需要注意的是，nSubscbID等于0是由CSF框架自身保留使用的，外部应用相关
             数据的订阅ID必须是大于0

          2. 本函数返回0，仅表示指令可以传送，订阅是否真正成功，
		     需要通过SubscriptionAck函数确认 
	***************************************************************************/
    virtual CSF_INT32 Subscription(
        CSF_UINT32 nSubscbID,
		CSF_UINT32 nApp,
        CSF_UINT32 nSrc,
 		CCSFList<CSF_UCHAR>* pDOTypeList)                             = 0;

	/***************************************************************************
	函数：CancelSubscription
	功能：撤销已有的订阅
	参数：
	      CSF_UINT32 nSrcId,取消订阅的数据源
	      CSF_UINT32 nAppId,取消订阅的App
          CSF_INT32 nSubscbID，订阅的ID

    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令

	***************************************************************************/
	virtual CSF_INT32 CancelSubscription(
		CSF_UINT32 nSubscbID,
		CSF_UINT32 nAppId,        
        CSF_UINT32 nSrcId)                                          = 0;

	/***************************************************************************
	函数：GetData
	功能：通知通讯处理模块，APP希望“得到”的数据，
	      通讯处理模块需要利用GetReturn返回相关的结果
	参数：
          CSF_BOOLEAN bRealData，是否要求直接从数据源读取，否则可以从CSF框架的
                     数据缓存中读取

          CSF_UINT32 nTimeout，超时要求，届时如果没有发送成功，csf框架将不再发送此
                               Get指令，GetReturn不会被调用
          
          CCSFList<CCSFTransBlock>* pPropList,要读取的数据
                               请参阅本函数说明1与2；

    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
         1. pTransBlock中的对象，要么为“GDO”（逻辑对象），要么为“专用DO，
		             如某个具体的状态量，累加量等”，指示所要读取的对象
             
			         如果为GDO（CCSF_GDO，逻辑对象）时，type与id为该逻辑
					 对象的表征，其属性链表为要读取的该对象的“数
					 据类型”，属性的名字分别为：“dotype1”，“dotype2” ... ；
					 特别地，要读取该逻辑对象“所有数据”时，属性链表为空即可；
					 
					 譬如：要读取该逻辑对象下所有的“状态量”，则：name = dotype1 ；
					 value = CSF_OBJTYPE_ACCUMULATOR(106)
                     

         2. 参数pPropList->m_PropList中（属性名链表）的任一个属性名，
                     可使用“抽象描述－ALL”；
                     其中，根据需要m_lValTotalLen可以为0，此时m_pValues为NULL
 
         3. 对于同一数据源来讲，同时只能有一个Get指令，否则框架会利用GetReturn返回
                     失败（nResult＝＝3）
                     
    ***************************************************************************/
	virtual CSF_INT32 GetData(
        CSF_BOOLEAN bRealData,
		CSF_UINT32 nTimeout,
        CCSFTransBlock* pTransBlock)              = 0;
	
	/***************************************************************************
	函数：SetData
	功能：通知通讯处理模块，CSF希望“设置”的数据，
	      通讯处理模块需要利用SetReturn返回相关的结果
	参数：
          CSF_UINT8 nSetType，设置的类型（控制类型）
		  
          CSF_UINT32 nTimeout，超时要求，届时如果没有发送成功，csf框架将不再发送此
                               Set指令，SetReturn不会被调用
          
          CCSFTransBlock* pTransBlock，设置的内容

     返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                      1：失败，表示框架目前无法接收此指令
    
     说明：
          1. 对于同一数据源来讲，同时只能有一个Set指令，否则框架会利用SetReturn返回
                     失败（nResult == 5）
          2. 如果设置的数据是“文件”类型，要求pDataList包含的全部是文件，值的内容是
            “包含文件名称的全路径”

    ***************************************************************************/
	virtual CSF_INT32 SetData(
        CSF_UINT8 nSetType,
		CSF_UINT32 nTimeout,
        CCSFTransBlock* pTransBlock)                = 0;

	/***************************************************************************
	函数：IssuanceAck
	功能：对发布数据者所发布的、要求给予确认数据的确认
	参数：
          CSF_INT32 nSubscbID，要确认的数据发布的ID    
          
          CCSFListTrans<CCSFPropNameBlockBase>* pPropNameList,要确认的数据
          
    返回：CSF_INT32，0：成功，表示指令被框架接收，准备发送
                     1：失败，表示框架目前无法接收此指令
    说明：
          1. 确认数据的发布并不是csf框架给出的，而是由应用层给出的，并且只针对
             发布者所要求给出确认的数据
	***************************************************************************/
    virtual CSF_INT32 IssuanceAck(
        CSF_INT32 nIssueID,
        CCSFTransBlock* pTransBlock)           = 0;
    
public:
	/*名称：ExchAdvise
	描述：设置回调接口
	参数：   
	ICSF_CDE_ExchCallBackInterface* pCallBack，给通信处理模块的回调接口
	返回值：
	无
	*/
	virtual void ExchAdvise(ICSF_CDE_ExchCallBackInterface* pCallBack) = 0;  

};

#endif
