/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2006-2007   */
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
    文件名      ：  CSFIdInterface.h
    描述        ：  本文件定义了生成csfid的接口
    版本        ：  0.0.1
    作者        ：  连湛伟
    日期        ：  2008.7
*/

#ifndef CSFIDINTERFACE_H
#define CSFIDINTERFACE_H

	/***************************************************************************
	函数：GetCSFId
	功能：根据协议相关标识字获取CSFID
	参数：
          int nProtocal，协议标识
                  
          int nParaNum，协议参数（标识字）数量

          int* pnPara，相关协议参数数组，

    返回：CSF_INT64，所生成csfid
    说明：
          1. 104规约定义如下：
		     nProtocal = 4
			 nParaNum  = 4
             pnPara，按照顺序，其参数依次为“ASDU类型，装置地址，扇区地址，信息体地址”
	***************************************************************************/


#ifdef WIN32
#ifdef CSFIDGRENTE_DLL_FILE  
extern "C"       
      _declspec(dllexport) CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#else                                   
extern "C" 
      _declspec(dllimport) CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#endif//#ifdef PROTMODEL_DLL_FILE 
#else//UNIX,LINUX等（gnu）
extern "C" 
      CSF_INT64 GetCSFId(int nProtocal,int nParaNum,int* pnPara);
#endif

#endif
