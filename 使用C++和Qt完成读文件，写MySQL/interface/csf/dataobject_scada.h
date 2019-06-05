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
    文件名      ：  DataObject_SCADA.h
    描述        ：  数据类型定义
    版本        ：  1.0.1
    作者        ：  连湛伟

    创建日期    ：  2008.5
*/

#ifndef DATAOBJECT_SCADA_H
#define DATAOBJECT_SCADA_H

#include "csfdataobject.h"
#include "logicobject_scada.h"

/**************************传送原因定义*****************************/
//未知
#define   CSF_TRANS_CAUSE_UNKNOWN     0
//发生变化，主动上传
#define   CSF_TRANS_CAUSE_DCHG        1
//品质因数变化，主动上传（包含值同时上传）
#define   CSF_TRANS_CAUSE_QCHG        2
//数据刷新，主动上传
#define   CSF_TRANS_CAUSE_DESCPD      3
//周期上传
#define   CSF_TRANS_CAUSE_INTGPD      4
//总招回应
#define   CSF_TRANS_CAUSE_GI          5
/**************************传送原因定义*****************************/


/**************************对象类型定义*****************************/

//数据对象///////////////////////////////////////////////
//状态量
#define   CSF_OBJTYPE_STATUS          101
//实数模拟量
#define   CSF_OBJTYPE_RANALOG         102
//复数模拟量
#define   CSF_OBJTYPE_CANALOG         103
//整数定值量
#define   CSF_OBJTYPE_ISETTING        104
//模拟定值量
#define   CSF_OBJTYPE_ASETTING        105
//累加量
#define   CSF_OBJTYPE_ACCUMULATOR     106
//整数型控制量
#define   CSF_OBJTYPE_ICONTROL        107
//实数型控制量，暂不处理
#define   CSF_OBJTYPE_ACONTROL        108
//定值区
#define   CSF_OBJTYPE_SETTINGAREA     109
//设备描述
#define   CSF_OBJTYPE_DEVICEDESC      110
//事件量（故障报告）
#define   CSF_OBJTYPE_EVENTREPORT     111
//通用量
#define   CSF_OBJTYPE_GENERAL     255                //WX Modify
/**************************对象类型定义*****************************/


/**************************对象属性定义*****************************/
//状态量对象属性///////////////////////////////////////////////
//单点状态
#define   CSF_DOA_STATUS_SPS              1
//双点状态
#define   CSF_DOA_STATUS_DPS              2
//整数状态
#define   CSF_DOA_STATUS_INS              3
//保护启动
#define   CSF_DOA_STATUS_ACD              4
//保护动作
#define   CSF_DOA_STATUS_ACT              5
//违例计数，暂不处理
#define   CSF_DOA_STATUS_SEC              6
//二进制计数器读数，转为脉冲量（累加量）处理
#define   CSF_DOA_STATUS_BCR              7

//控制量对象属性///////////////////////////////////////////////
//单点控制
#define   CSF_DOA_ICONTROL_SPC            1
//双点控制
#define   CSF_DOA_ICONTROL_DPC            2
//整数控制
#define   CSF_DOA_ICONTROL_INC            3
//二进制受控步进控制
#define   CSF_DOA_ICONTROL_BSC            4
//整数受控步进控制，暂不处理
#define   CSF_DOA_ICONTROL_ISC            5

//状态量定值对象属性///////////////////////////////////////////////
//单点状态量定值
#define   CSF_DOA_ISETTING_SPG            1
//整数状态量定值
#define   CSF_DOA_ISETTING_ING            2
//定值曲线
#define   CSF_DOA_ASETTING_CUR            3

//定值区对象属性///////////////////////////////////////////////
//当前定值区
#define   CSF_SETTINGAREA_CUR             1
//当前编辑区
#define   CSF_SETTINGAREA_EDT             2
//定值区数目
#define   CSF_SETTINGAREA_NUM             3
/**************************对象属性定义*****************************/


/**************************Set类型（控制类型）定义*****************************/
//未知
#define   CSF_SET_TYPE_UNKNOWN            0
//选控
#define   CSF_SET_TYPE_SELECT             1
//执行
#define   CSF_SET_TYPE_OPERATE            2
//撤销
#define   CSF_SET_TYPE_CANCEL             3

//修改定值
#define	  CSF_SET_TYPE_MODIFYSETTING	  4
//切换定值区
#define   CSF_SET_TYPE_SWITCHAREA		  5
//预装定值
#define	  CSF_SET_TYPE_PRESETSETTING	  6
//固化定值
#define   CSF_SET_TYPE_SAVESETTING        7
//撤销定值
#define   CSF_SET_TYPE_CANCELSETTING      8
//下装定值
#define		CSF_SET_TYPE_SETTING		  9
//切换激活区定值区    WX Modify
#define   CSF_SET_TYPE_SWITCHACTAREA		  16            
//切换编辑区定值区    WX Modify
#define   CSF_SET_TYPE_SWITCHEDITAREA		  17
/**************************Set类型（控制类型）定义*****************************/

/**************************分接头控制目标值（BSC）定义*****************************/
//停
#define   CSF_BSC_VALUE_STOP              1
//降
#define   CSF_BSC_VALUE_LOWER             2
//升
#define   CSF_BSC_VALUE_HIGH              3
//保持
#define   CSF_BSC_VALUE_RESERVE           4
/**************************Set类型（控制类型）定义*****************************/


/*************************************************
  类名称:  CCSF_SDO_Status
  类描述:  状态量对象
*************************************************/
class CCSF_SDO_Status : public  CCSF_Data
{
public:
	//状态量的原始值
	CSF_INT32                m_nRawValue;
	
	//本值的品质描述
	CSF_UINT32               m_nQuality;
	
	//本值原始时标
	CSF_DOUBLE               m_dTimeStamp;

	//状态量类型
	//  (1－SPS；2－DPS；3－INS；4－ACT；5－ACD；6－SEC)
	//参见上述“状态量对象属性”定义
	CSF_UINT8                m_nSType;

	//状态量属性（0未知，1普通，2告警，3装置通讯状态，
	//            4压板，5保护启动，6保护出口）
	//目前：只用0
	CSF_UINT8                m_nAttribute;
	
public:
	CCSF_SDO_Status()
	{
		m_nType = CSF_OBJTYPE_STATUS;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  类名称:  CCSF_SDO_RAnalog
  类描述:  实数模拟量对象
*************************************************/
class CCSF_SDO_RAnalog : public  CCSF_Data
{
public:
	//值标识(1,m_fRawValue有效；2，m_nRawValue;3两者都有效）
	CSF_UINT8                 m_nRIFMark;

	//模拟量的原始值
	CSF_FLOAT                 m_fRawValue;   

	//模拟量的原始值
	CSF_INT32                 m_nRawValue;  

	//本值的品质描述
	CSF_UINT32                m_nQuality;
	
	//本值原始时标
	CSF_DOUBLE                m_dTimeStamp;

	//模拟量属性（目前总为0）
	CSF_UINT8                 m_nAttribute;

public:
	CCSF_SDO_RAnalog()
	{
		m_nType = CSF_OBJTYPE_RANALOG;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  类名称:  CCSF_SDO_CAnalog
  类描述:  复数模拟量对象
  说明：
         m_nMark:1,m_fRawValue有效；2，m_nRawValue;3两者都有效
		         4
*************************************************/
class CCSF_SDO_CAnalog : public  CCSF_SDO_RAnalog
{	
public:
	// 幅值与角度使用标记（1－幅值有效；2－角度有效；3两者都有效）
	CSF_UINT8                 m_nRAMark;

	//值标识(1,m_fAngValue有效；2，m_nAngValue;3两者都有效）
	CSF_UINT8                 m_nAIFMark;

	//复角原始值
	CSF_FLOAT                 m_fAngValue;   
	
	//复角原始值
	CSF_UINT32                m_nAngValue;  

public:
	CCSF_SDO_CAnalog()
	{
		m_nType = CSF_OBJTYPE_CANALOG;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  类名称:  CCSF_SDO_Accumulator
  类描述:  脉冲量对象
*************************************************/
class CCSF_SDO_Accumulator : public  CCSF_Data
{
public:
	//当前值
	CSF_UINT32               m_nActValue;

	//本值的品质描述
	CSF_UINT32               m_nQuality;
	
	//本值原始时标
	CSF_DOUBLE               m_dTimeStamp;

public:
	CCSF_SDO_Accumulator()
	{
		m_nType = CSF_OBJTYPE_ACCUMULATOR;
	}
};

/*************************************************
  类名称:  CCSF_SDO_ISetting
  类描述:  整数定值对象
*************************************************/
class CCSF_SDO_ISetting : public  CCSF_Data
{	
public:
	//整数定值
	CSF_INT32                m_nISValue;

	//整数定值类型(1,单点定值；2，整数定值；3，定值曲线)
	CSF_UINT8                m_nISType;

	//定值系数
	CSF_UINT8                m_nRate;

public:
	CCSF_SDO_ISetting()
	{
		m_nType = CSF_OBJTYPE_ISETTING;
	}
};

/*************************************************
  类名称:  CCSFTDO_CBZ8600_AnaSetting
  类描述:  模拟量定值对象
*************************************************/
class CCSF_SDO_ASetting : public  CCSF_Data
{	
public:
	//值标识(1,m_fASValue有效；2，m_nASValue有效;3两者都有效）
	CSF_UINT8                 m_nMark;
	
	//模拟量的原始值
	CSF_FLOAT                 m_fASValue;   
	
	//模拟量的原始值
	CSF_UINT32                m_nASValue;  

	//定值系数
	CSF_UINT8                m_nRate;

public:
	CCSF_SDO_ASetting()
	{
		m_nType = CSF_OBJTYPE_ASETTING;
	}
};

/*************************************************
  类名称:  CCSF_SDO_IControl
  类描述:  状态量型控制对象
*************************************************/
class CCSF_SDO_IControl : public  CCSF_Data
{
public:
	//整数控制值
	CSF_INT32                m_nICValue;

	//状态量控制类型
	//  (1－SPC；2－DPC；3－INC；4－BSC；5－ISC)
	//参见上述“状态量控制类型”定义
	CSF_UINT8                m_nCType;

	//本值的品质描述
	CSF_UINT32               m_nQuality;
	
	//本值原始时标
	CSF_DOUBLE               m_dTimeStamp;
	
public:
	CCSF_SDO_IControl()
	{
		m_nType = CSF_OBJTYPE_ICONTROL;
	}
};

/*************************************************
  类名称:  CCSF_SDO_AControl
  类描述:  模拟量型控制对象
*************************************************/
class CCSF_SDO_AControl : public  CCSF_Data
{	
public:
	//值标识(1,m_fValue有效；2，m_nValue有效;3，两者都有效）
	CSF_UINT8                 m_nMark;
	
	//控制模拟量的值
	CSF_FLOAT                 m_fValue;   
	
	//控制模拟量的值
	CSF_UINT32                m_nValue;  

	//本值的品质描述
	CSF_UINT32               m_nQuality;
	
	//本值原始时标
	CSF_DOUBLE               m_dTimeStamp;
public:
	CCSF_SDO_AControl()
	{
		m_nType = CSF_OBJTYPE_ACONTROL;
	}
};

/*************************************************
  类名称:  CCSF_SDO_SettingArea
  类描述:  定值区对象
*************************************************/
class CCSF_SDO_SettingArea : public  CCSF_Data
{	
public:
    //定值类型(1,当前定值区；2，当前编辑区）
	CSF_UINT8                m_nSAType;

	//定值区
	CSF_UINT8                m_nAreaValue;	

public:
	CCSF_SDO_SettingArea()
	{
		m_nType = CSF_OBJTYPE_SETTINGAREA;
	}
};

/*************************************************
  类名称:  CCSF_SDO_DeviceDsc
  类描述:  设备描述
*************************************************/
class CCSF_SDO_DeviceDsc : public  CCSF_Data
{	
public:
    //制造商
	CSF_STRING                m_sVender;

	//软件版本
	CSF_STRING                m_sSoftVer;	

	//模型
	CSF_STRING                m_sMode;

public:
	CCSF_SDO_DeviceDsc()
	{
		m_nType = CSF_OBJTYPE_DEVICEDESC;
		m_sVender = 0;
		m_sSoftVer = 0;
		m_sMode = 0;
	}
};

/*************************************************
  类名称:  CCSF_SDO_EventReport
  类描述:  事件量（或故障报告）
  
  说明：   
*************************************************/
class CCSF_SDO_EventReport : public  CCSF_SDO_Status
{	
public:
	//设置附加参数
	CSF_BOOLEAN SetRecord(const CSF_FLOAT* psRecord, CSF_UINT16 nNum);

	//得到附加参数
	const CSF_FLOAT* GetRecord(CSF_UINT16& nNum);

	//删除附加参数
	void RemoveRecord();

	//相对时间
	CSF_DOUBLE               m_dTimeSpan;

	//事件序号
	CSF_UINT16               m_FalutNum;

	//事件类型
	CSF_UINT32               m_FaultType;
	
	//附加参数的数目
	CSF_UINT16               m_nNum;

	//附加参数
	CSF_FLOAT*               m_pfRecord;

public:
	CCSF_SDO_EventReport()
	{
		m_nType = CSF_OBJTYPE_EVENTREPORT;
		m_pfRecord = 0;
		m_nNum = 0;
	}

	~CCSF_SDO_EventReport()
	{
		RemoveRecord();
	}
};

#endif
