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
    文件名      ：  CSFDefine.h
    描述        ：  本文件完成统一数据交换接口的数据类型等基本定义
    版本        ：  1.0.1
    作者        ：  连湛伟

    创建日期    ：  2006.4
  
    修改记录
         1.修改日期：2007.5    ；修改者：连湛伟   
		   变更基本类型的定义
		 2.修改日期：2008.5    ；修改者：连湛伟   
		   增添复合数据类型的定义
*/

#ifndef CSFDEFINE_H
#define CSFDEFINE_H

#include "csfint64define.h"

#define     CSF_NULL                       0


#define     CSF_BOOL_FALSE                 0
#define     CSF_BOOL_TRUE                  1

/****************************CSF所使用的变量长度的定义**********************/

#define     CSF_DLEN_NULL                  0

//char类型的长度
#define 	CSF_DLEN_CHAR                  1     
//unsigned char类型的长度
#define 	CSF_DLEN_UCHAR                 1     
//signed char 类型的长度
#define 	CSF_DLEN_INT8                  1     
//unsigned char 类型的长度
#define 	CSF_DLEN_UINT8                 1     
//short类型的长度
#define 	CSF_DLEN_INT16                 2     
//unsigned short类型的长度
#define 	CSF_DLEN_UINT16                2     
//int类型的长度
#define 	CSF_DLEN_INT32                 4     
//unsigned int 类型的长度
#define 	CSF_DLEN_UINT32                4     
//int64类型的长度
#define 	CSF_DLEN_INT64                 8     
//unsigned int64 类型的长度
#define 	CSF_DLEN_UINT64                8     
//单精度浮点数的长度
#define     CSF_DLEN_FLOAT                 4     
//双精度浮点数的长度
#define     CSF_DLEN_DOUBLE                8     
//时间的长度
#define     CSF_DLEN_TIME                  8

//字符串的长度（参数str为字符串指针）,遵循标准C/C++规范，不包括串未“NULL”
#define     CSF_DLEN_STRING(str)           strlen(str) + 1
               
/****************************CSF所使用的变量长度的定义**********************/


/**************************CSF所使用变量的基本类型******************************/
#define     CSF_VOID                       void
#define     CSF_CHAR                       char    
#define     CSF_UCHAR                      unsigned char          
#define     CSF_INT8                       char
#define     CSF_UINT8                      unsigned char
#define     CSF_INT16                      short
#define     CSF_UINT16                     unsigned short
#define     CSF_INT32                      long
#define     CSF_UINT32                     unsigned long
#define     CSF_INT64                      LONG64
#define     CSF_UINT64                     ULONG64
#define     CSF_STRING                     char*   //长度不得超过250字节
#define     CSF_FLOAT                      float
#define     CSF_DOUBLE                     double
#define     CSF_BOOLEAN                    unsigned char
#define     CSF_TIME                       double
#define     CSF_FILE                       char*

#define     CSF_OBJ                        CCSF_GDO

/**************************CSF所使用的变量类型******************************/


#define     CSF_MAX_REF_LEN                250
#define     CSF_IP_STRLEN                  16


//介质模块类型枚举
typedef enum
{
	CSF_COMMED_TCPCLIENT  =      1,
	CSF_COMMED_TCPSERVER  ,
	CSF_COMMED_RS485      ,
	CSF_COMMED_P2P        ,
    CSF_COMMED_UDP,
} CSF_COMMED_TYPE;

//CSF对CSF所使用的变量类型的枚举
typedef enum 
{	
	//空
    CSF_DT_NULL           =       0,

	//基本类型	
	CSF_DT_INT8           =       1,
	CSF_DT_UINT8          ,
	CSF_DT_INT16          ,
	CSF_DT_UINT16         ,
	CSF_DT_INT32          ,
	CSF_DT_UINT32         ,
	CSF_DT_INT64          ,
	CSF_DT_UINT64         ,
	CSF_DT_FLOAT          ,
	CSF_DT_DOUBLE         ,
	CSF_DT_BOOL           ,		
	CSF_DT_TIME           ,
	CSF_DT_STRING         ,      
	CSF_DT_FILE           ,	

	//对象类型，对象遵循“CCSFPropValueBlockBase”定义（请参见CSFBaseInterface.h）
	CSF_DT_OBJ            , 

	//数组类型,遵循“CSF_ARRAY”定义（请参见CSFBaseInterface.h)
	CSF_DT_ARRAY_INT8      ,
	CSF_DT_ARRAY_UINT8     ,
	CSF_DT_ARRAY_INT16     ,
	CSF_DT_ARRAY_UINT16    ,
	CSF_DT_ARRAY_INT32     ,
	CSF_DT_ARRAY_UINT32    ,
	CSF_DT_ARRAY_INT64     ,
	CSF_DT_ARRAY_UINT64    ,
	CSF_DT_ARRAY_FLOAT     ,
	CSF_DT_ARRAY_DOUBLE    ,
	CSF_DT_ARRAY_BOOL      ,
	CSF_DT_ARRAY_TIME      ,

	CSF_DT_ARRAY_STRING    ,           
	CSF_DT_ARRAY_OBJ                    
}CSF_DATA_TYPE,*PCSF_DATA_TYPE;

#define   CSF_MODEL_BOOT                      1
#define   CSF_MODEL_DATPARSE                  2
#define   CSF_MODEL_NODEMAN                   3
#define   CSF_MODEL_MESACCESS                 4
#define   CSF_MODEL_DATACCESS                 5
#define   CSF_MODEL_NETSRV                    6
#define   CSF_MODEL_NPGROUP                   7
#define   CSF_MODEL_APPINTERFACE              8
#define   CSF_MODEL_CSFVIEW                   9
#define   CSF_MODEL_PROTOCAL                  10
#define   CSF_MODEL_MEDIUMONE                 11
#define   CSF_MODEL_ITG                       12
#define   CSF_MODEL_SETUP                     13

#define   CSF_EVENTLEVEL_NORMAL               1
#define   CSF_EVENTLEVEL_WARN                 2
#define   CSF_EVENTLEVEL_ERROR                3

#define   CSF_INNERMES_DUTYDP                 0x01
#define   CSF_INNERMES_DUTYDPACK              0x02
#define   CSF_INNERMES_POOLOK                 0x03
#define   CSF_INNERMES_SPYMSG                 0x04
#define   CSF_INNERMES_ROUTE                  0x09
#define   CSF_INNERMES_ROUTEACK               0x0a
#define   CSF_INNERMES_QUIT                   0x0b

//逻辑对象：      1－100
//专用数据对象:   101－200
//无效对象：201
//通用对象：255

//无效DO类型
#define   CSF_OBJTYPE_INVALIDATE              201

//无效对象ID
#define   CSF_OBJID_INVALIDATE                0

//无效数据属性
#define   CSF_OBJATRI_INVALIDATE              0

//通用数据对象
#define   CSF_OBJTYPE_GERERAL                 255

//是否是逻辑对象
#define   IS_LO(nType)       (nType > 0 && nType <= 100)

//是否是通用数据对象
#define   IS_GDO(nType)       (nType == CSF_OBJTYPE_GERERAL)

#endif
