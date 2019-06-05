/*****************************************************************************/
/*��̵����ɷ����޹�˾                                     ��Ȩ��2006-2015   */
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
    ��Ŀ����    ��  ͨѶ������
    �ļ���      ��  CSFDefine.h
    ����        ��  ���ļ����ͳһ���ݽ����ӿڵ��������͵Ȼ�������
    �汾        ��  1.0.1
    ����        ��  ��տΰ

    ��������    ��  2006.4
  
    �޸ļ�¼
         1.�޸����ڣ�2007.5    ���޸��ߣ���տΰ   
		   ����������͵Ķ���
		 2.�޸����ڣ�2008.5    ���޸��ߣ���տΰ   
		   �������������͵Ķ���
*/

#ifndef CSFDEFINE_H
#define CSFDEFINE_H

#include "csfint64define.h"

#define     CSF_NULL                       0


#define     CSF_BOOL_FALSE                 0
#define     CSF_BOOL_TRUE                  1

/****************************CSF��ʹ�õı������ȵĶ���**********************/

#define     CSF_DLEN_NULL                  0

//char���͵ĳ���
#define 	CSF_DLEN_CHAR                  1     
//unsigned char���͵ĳ���
#define 	CSF_DLEN_UCHAR                 1     
//signed char ���͵ĳ���
#define 	CSF_DLEN_INT8                  1     
//unsigned char ���͵ĳ���
#define 	CSF_DLEN_UINT8                 1     
//short���͵ĳ���
#define 	CSF_DLEN_INT16                 2     
//unsigned short���͵ĳ���
#define 	CSF_DLEN_UINT16                2     
//int���͵ĳ���
#define 	CSF_DLEN_INT32                 4     
//unsigned int ���͵ĳ���
#define 	CSF_DLEN_UINT32                4     
//int64���͵ĳ���
#define 	CSF_DLEN_INT64                 8     
//unsigned int64 ���͵ĳ���
#define 	CSF_DLEN_UINT64                8     
//�����ȸ������ĳ���
#define     CSF_DLEN_FLOAT                 4     
//˫���ȸ������ĳ���
#define     CSF_DLEN_DOUBLE                8     
//ʱ��ĳ���
#define     CSF_DLEN_TIME                  8

//�ַ����ĳ��ȣ�����strΪ�ַ���ָ�룩,��ѭ��׼C/C++�淶����������δ��NULL��
#define     CSF_DLEN_STRING(str)           strlen(str) + 1
               
/****************************CSF��ʹ�õı������ȵĶ���**********************/


/**************************CSF��ʹ�ñ����Ļ�������******************************/
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
#define     CSF_STRING                     char*   //���Ȳ��ó���250�ֽ�
#define     CSF_FLOAT                      float
#define     CSF_DOUBLE                     double
#define     CSF_BOOLEAN                    unsigned char
#define     CSF_TIME                       double
#define     CSF_FILE                       char*

#define     CSF_OBJ                        CCSF_GDO

/**************************CSF��ʹ�õı�������******************************/


#define     CSF_MAX_REF_LEN                250
#define     CSF_IP_STRLEN                  16


//����ģ������ö��
typedef enum
{
	CSF_COMMED_TCPCLIENT  =      1,
	CSF_COMMED_TCPSERVER  ,
	CSF_COMMED_RS485      ,
	CSF_COMMED_P2P        ,
    CSF_COMMED_UDP,
} CSF_COMMED_TYPE;

//CSF��CSF��ʹ�õı������͵�ö��
typedef enum 
{	
	//��
    CSF_DT_NULL           =       0,

	//��������	
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

	//�������ͣ�������ѭ��CCSFPropValueBlockBase�����壨��μ�CSFBaseInterface.h��
	CSF_DT_OBJ            , 

	//��������,��ѭ��CSF_ARRAY�����壨��μ�CSFBaseInterface.h)
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

//�߼�����      1��100
//ר�����ݶ���:   101��200
//��Ч����201
//ͨ�ö���255

//��ЧDO����
#define   CSF_OBJTYPE_INVALIDATE              201

//��Ч����ID
#define   CSF_OBJID_INVALIDATE                0

//��Ч��������
#define   CSF_OBJATRI_INVALIDATE              0

//ͨ�����ݶ���
#define   CSF_OBJTYPE_GERERAL                 255

//�Ƿ����߼�����
#define   IS_LO(nType)       (nType > 0 && nType <= 100)

//�Ƿ���ͨ�����ݶ���
#define   IS_GDO(nType)       (nType == CSF_OBJTYPE_GERERAL)

#endif
