/*****************************************************************************/
/*��̵����ɷ����޹�˾                                     ��Ȩ��2008-2015   */
/*****************************************************************************/
/* ��Դ���뼰������ĵ�Ϊ���������̵����ɷ����޹�˾�������У�δ��������    */
/* �ɲ��������޸Ļ򷢲�������׷����صķ������Ρ�                          */
/*                                                                           */
/*                      ���������̹ɷ����޹�˾                             */
/*                      www.xjgc.com                                         */
/*                      (0374) 321 2924                                      */
/*                                                                           */
/*****************************************************************************/

/*
    ��Ŀ����    ��  ���վ����������
    �ļ���      ��  DataObject_SCADA.h
    ����        ��  �������Ͷ���
    �汾        ��  1.0.1
    ����        ��  ��տΰ

    ��������    ��  2008.5
*/

#ifndef DATAOBJECT_SCADA_H
#define DATAOBJECT_SCADA_H

#include "csfdataobject.h"
#include "logicobject_scada.h"

/**************************����ԭ����*****************************/
//δ֪
#define   CSF_TRANS_CAUSE_UNKNOWN     0
//�����仯�������ϴ�
#define   CSF_TRANS_CAUSE_DCHG        1
//Ʒ�������仯�������ϴ�������ֵͬʱ�ϴ���
#define   CSF_TRANS_CAUSE_QCHG        2
//����ˢ�£������ϴ�
#define   CSF_TRANS_CAUSE_DESCPD      3
//�����ϴ�
#define   CSF_TRANS_CAUSE_INTGPD      4
//���л�Ӧ
#define   CSF_TRANS_CAUSE_GI          5
/**************************����ԭ����*****************************/


/**************************�������Ͷ���*****************************/

//���ݶ���///////////////////////////////////////////////
//״̬��
#define   CSF_OBJTYPE_STATUS          101
//ʵ��ģ����
#define   CSF_OBJTYPE_RANALOG         102
//����ģ����
#define   CSF_OBJTYPE_CANALOG         103
//������ֵ��
#define   CSF_OBJTYPE_ISETTING        104
//ģ�ⶨֵ��
#define   CSF_OBJTYPE_ASETTING        105
//�ۼ���
#define   CSF_OBJTYPE_ACCUMULATOR     106
//�����Ϳ�����
#define   CSF_OBJTYPE_ICONTROL        107
//ʵ���Ϳ��������ݲ�����
#define   CSF_OBJTYPE_ACONTROL        108
//��ֵ��
#define   CSF_OBJTYPE_SETTINGAREA     109
//�豸����
#define   CSF_OBJTYPE_DEVICEDESC      110
//�¼��������ϱ��棩
#define   CSF_OBJTYPE_EVENTREPORT     111
//ͨ����
#define   CSF_OBJTYPE_GENERAL     255                //WX Modify
/**************************�������Ͷ���*****************************/


/**************************�������Զ���*****************************/
//״̬����������///////////////////////////////////////////////
//����״̬
#define   CSF_DOA_STATUS_SPS              1
//˫��״̬
#define   CSF_DOA_STATUS_DPS              2
//����״̬
#define   CSF_DOA_STATUS_INS              3
//��������
#define   CSF_DOA_STATUS_ACD              4
//��������
#define   CSF_DOA_STATUS_ACT              5
//Υ���������ݲ�����
#define   CSF_DOA_STATUS_SEC              6
//�����Ƽ�����������תΪ���������ۼ���������
#define   CSF_DOA_STATUS_BCR              7

//��������������///////////////////////////////////////////////
//�������
#define   CSF_DOA_ICONTROL_SPC            1
//˫�����
#define   CSF_DOA_ICONTROL_DPC            2
//��������
#define   CSF_DOA_ICONTROL_INC            3
//�������ܿز�������
#define   CSF_DOA_ICONTROL_BSC            4
//�����ܿز������ƣ��ݲ�����
#define   CSF_DOA_ICONTROL_ISC            5

//״̬����ֵ��������///////////////////////////////////////////////
//����״̬����ֵ
#define   CSF_DOA_ISETTING_SPG            1
//����״̬����ֵ
#define   CSF_DOA_ISETTING_ING            2
//��ֵ����
#define   CSF_DOA_ASETTING_CUR            3

//��ֵ����������///////////////////////////////////////////////
//��ǰ��ֵ��
#define   CSF_SETTINGAREA_CUR             1
//��ǰ�༭��
#define   CSF_SETTINGAREA_EDT             2
//��ֵ����Ŀ
#define   CSF_SETTINGAREA_NUM             3
/**************************�������Զ���*****************************/


/**************************Set���ͣ��������ͣ�����*****************************/
//δ֪
#define   CSF_SET_TYPE_UNKNOWN            0
//ѡ��
#define   CSF_SET_TYPE_SELECT             1
//ִ��
#define   CSF_SET_TYPE_OPERATE            2
//����
#define   CSF_SET_TYPE_CANCEL             3

//�޸Ķ�ֵ
#define	  CSF_SET_TYPE_MODIFYSETTING	  4
//�л���ֵ��
#define   CSF_SET_TYPE_SWITCHAREA		  5
//Ԥװ��ֵ
#define	  CSF_SET_TYPE_PRESETSETTING	  6
//�̻���ֵ
#define   CSF_SET_TYPE_SAVESETTING        7
//������ֵ
#define   CSF_SET_TYPE_CANCELSETTING      8
//��װ��ֵ
#define		CSF_SET_TYPE_SETTING		  9
//�л���������ֵ��    WX Modify
#define   CSF_SET_TYPE_SWITCHACTAREA		  16            
//�л��༭����ֵ��    WX Modify
#define   CSF_SET_TYPE_SWITCHEDITAREA		  17
/**************************Set���ͣ��������ͣ�����*****************************/

/**************************�ֽ�ͷ����Ŀ��ֵ��BSC������*****************************/
//ͣ
#define   CSF_BSC_VALUE_STOP              1
//��
#define   CSF_BSC_VALUE_LOWER             2
//��
#define   CSF_BSC_VALUE_HIGH              3
//����
#define   CSF_BSC_VALUE_RESERVE           4
/**************************Set���ͣ��������ͣ�����*****************************/


/*************************************************
  ������:  CCSF_SDO_Status
  ������:  ״̬������
*************************************************/
class CCSF_SDO_Status : public  CCSF_Data
{
public:
	//״̬����ԭʼֵ
	CSF_INT32                m_nRawValue;
	
	//��ֵ��Ʒ������
	CSF_UINT32               m_nQuality;
	
	//��ֵԭʼʱ��
	CSF_DOUBLE               m_dTimeStamp;

	//״̬������
	//  (1��SPS��2��DPS��3��INS��4��ACT��5��ACD��6��SEC)
	//�μ�������״̬���������ԡ�����
	CSF_UINT8                m_nSType;

	//״̬�����ԣ�0δ֪��1��ͨ��2�澯��3װ��ͨѶ״̬��
	//            4ѹ�壬5����������6�������ڣ�
	//Ŀǰ��ֻ��0
	CSF_UINT8                m_nAttribute;
	
public:
	CCSF_SDO_Status()
	{
		m_nType = CSF_OBJTYPE_STATUS;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  ������:  CCSF_SDO_RAnalog
  ������:  ʵ��ģ��������
*************************************************/
class CCSF_SDO_RAnalog : public  CCSF_Data
{
public:
	//ֵ��ʶ(1,m_fRawValue��Ч��2��m_nRawValue;3���߶���Ч��
	CSF_UINT8                 m_nRIFMark;

	//ģ������ԭʼֵ
	CSF_FLOAT                 m_fRawValue;   

	//ģ������ԭʼֵ
	CSF_INT32                 m_nRawValue;  

	//��ֵ��Ʒ������
	CSF_UINT32                m_nQuality;
	
	//��ֵԭʼʱ��
	CSF_DOUBLE                m_dTimeStamp;

	//ģ�������ԣ�Ŀǰ��Ϊ0��
	CSF_UINT8                 m_nAttribute;

public:
	CCSF_SDO_RAnalog()
	{
		m_nType = CSF_OBJTYPE_RANALOG;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  ������:  CCSF_SDO_CAnalog
  ������:  ����ģ��������
  ˵����
         m_nMark:1,m_fRawValue��Ч��2��m_nRawValue;3���߶���Ч
		         4
*************************************************/
class CCSF_SDO_CAnalog : public  CCSF_SDO_RAnalog
{	
public:
	// ��ֵ��Ƕ�ʹ�ñ�ǣ�1����ֵ��Ч��2���Ƕ���Ч��3���߶���Ч��
	CSF_UINT8                 m_nRAMark;

	//ֵ��ʶ(1,m_fAngValue��Ч��2��m_nAngValue;3���߶���Ч��
	CSF_UINT8                 m_nAIFMark;

	//����ԭʼֵ
	CSF_FLOAT                 m_fAngValue;   
	
	//����ԭʼֵ
	CSF_UINT32                m_nAngValue;  

public:
	CCSF_SDO_CAnalog()
	{
		m_nType = CSF_OBJTYPE_CANALOG;
		m_nAttribute = CSF_OBJATRI_INVALIDATE;
	}
};

/*************************************************
  ������:  CCSF_SDO_Accumulator
  ������:  ����������
*************************************************/
class CCSF_SDO_Accumulator : public  CCSF_Data
{
public:
	//��ǰֵ
	CSF_UINT32               m_nActValue;

	//��ֵ��Ʒ������
	CSF_UINT32               m_nQuality;
	
	//��ֵԭʼʱ��
	CSF_DOUBLE               m_dTimeStamp;

public:
	CCSF_SDO_Accumulator()
	{
		m_nType = CSF_OBJTYPE_ACCUMULATOR;
	}
};

/*************************************************
  ������:  CCSF_SDO_ISetting
  ������:  ������ֵ����
*************************************************/
class CCSF_SDO_ISetting : public  CCSF_Data
{	
public:
	//������ֵ
	CSF_INT32                m_nISValue;

	//������ֵ����(1,���㶨ֵ��2��������ֵ��3����ֵ����)
	CSF_UINT8                m_nISType;

	//��ֵϵ��
	CSF_UINT8                m_nRate;

public:
	CCSF_SDO_ISetting()
	{
		m_nType = CSF_OBJTYPE_ISETTING;
	}
};

/*************************************************
  ������:  CCSFTDO_CBZ8600_AnaSetting
  ������:  ģ������ֵ����
*************************************************/
class CCSF_SDO_ASetting : public  CCSF_Data
{	
public:
	//ֵ��ʶ(1,m_fASValue��Ч��2��m_nASValue��Ч;3���߶���Ч��
	CSF_UINT8                 m_nMark;
	
	//ģ������ԭʼֵ
	CSF_FLOAT                 m_fASValue;   
	
	//ģ������ԭʼֵ
	CSF_UINT32                m_nASValue;  

	//��ֵϵ��
	CSF_UINT8                m_nRate;

public:
	CCSF_SDO_ASetting()
	{
		m_nType = CSF_OBJTYPE_ASETTING;
	}
};

/*************************************************
  ������:  CCSF_SDO_IControl
  ������:  ״̬���Ϳ��ƶ���
*************************************************/
class CCSF_SDO_IControl : public  CCSF_Data
{
public:
	//��������ֵ
	CSF_INT32                m_nICValue;

	//״̬����������
	//  (1��SPC��2��DPC��3��INC��4��BSC��5��ISC)
	//�μ�������״̬���������͡�����
	CSF_UINT8                m_nCType;

	//��ֵ��Ʒ������
	CSF_UINT32               m_nQuality;
	
	//��ֵԭʼʱ��
	CSF_DOUBLE               m_dTimeStamp;
	
public:
	CCSF_SDO_IControl()
	{
		m_nType = CSF_OBJTYPE_ICONTROL;
	}
};

/*************************************************
  ������:  CCSF_SDO_AControl
  ������:  ģ�����Ϳ��ƶ���
*************************************************/
class CCSF_SDO_AControl : public  CCSF_Data
{	
public:
	//ֵ��ʶ(1,m_fValue��Ч��2��m_nValue��Ч;3�����߶���Ч��
	CSF_UINT8                 m_nMark;
	
	//����ģ������ֵ
	CSF_FLOAT                 m_fValue;   
	
	//����ģ������ֵ
	CSF_UINT32                m_nValue;  

	//��ֵ��Ʒ������
	CSF_UINT32               m_nQuality;
	
	//��ֵԭʼʱ��
	CSF_DOUBLE               m_dTimeStamp;
public:
	CCSF_SDO_AControl()
	{
		m_nType = CSF_OBJTYPE_ACONTROL;
	}
};

/*************************************************
  ������:  CCSF_SDO_SettingArea
  ������:  ��ֵ������
*************************************************/
class CCSF_SDO_SettingArea : public  CCSF_Data
{	
public:
    //��ֵ����(1,��ǰ��ֵ����2����ǰ�༭����
	CSF_UINT8                m_nSAType;

	//��ֵ��
	CSF_UINT8                m_nAreaValue;	

public:
	CCSF_SDO_SettingArea()
	{
		m_nType = CSF_OBJTYPE_SETTINGAREA;
	}
};

/*************************************************
  ������:  CCSF_SDO_DeviceDsc
  ������:  �豸����
*************************************************/
class CCSF_SDO_DeviceDsc : public  CCSF_Data
{	
public:
    //������
	CSF_STRING                m_sVender;

	//����汾
	CSF_STRING                m_sSoftVer;	

	//ģ��
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
  ������:  CCSF_SDO_EventReport
  ������:  �¼���������ϱ��棩
  
  ˵����   
*************************************************/
class CCSF_SDO_EventReport : public  CCSF_SDO_Status
{	
public:
	//���ø��Ӳ���
	CSF_BOOLEAN SetRecord(const CSF_FLOAT* psRecord, CSF_UINT16 nNum);

	//�õ����Ӳ���
	const CSF_FLOAT* GetRecord(CSF_UINT16& nNum);

	//ɾ�����Ӳ���
	void RemoveRecord();

	//���ʱ��
	CSF_DOUBLE               m_dTimeSpan;

	//�¼����
	CSF_UINT16               m_FalutNum;

	//�¼�����
	CSF_UINT32               m_FaultType;
	
	//���Ӳ�������Ŀ
	CSF_UINT16               m_nNum;

	//���Ӳ���
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
