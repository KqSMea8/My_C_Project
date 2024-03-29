/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2008-2015   */
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
    项目名称    ：  变电站及集控中心
    文件名      ：  LogicObject_SCADA.h
    描述        ：  数据类型定义
    版本        ：  1.0.1
    作者        ：  连湛伟

    创建日期    ：  2009.2
*/

#ifndef LOGICOBJECT_SCADA_H
#define LOGICOBJECT_SCADA_H

/**************************对象类型定义*****************************/
//逻辑对象///////////////////////////////////////////////

//监控中心
//系统
#define   CSF_OBJTYPE_JKZ_SYSTEM          1
//站
#define   CSF_OBJTYPE_JKZ_STATION         2
//RUT
#define   CSF_OBJTYPE_JKZ_RTU             3


//数字化变电站（61850)
//全站
#define   CSF_OBJTYPE_61850_STATION         4
//装置
#define   CSF_OBJTYPE_61850_IED             5
//逻辑设备
#define   CSF_OBJTYPE_61850_LD              6
//逻辑节点
#define   CSF_OBJTYPE_61850_LN              7


//普通变电站（103/104)
//全站
#define   CSF_OBJTYPE_60870_STATION           8
//装置
#define   CSF_OBJTYPE_60870_IED               9
//逻辑设备
#define   CSF_OBJTYPE_60870_SECTOR            10
/**************************对象类型定义*****************************/


#endif
