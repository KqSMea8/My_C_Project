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
    ��Ŀ����    ��  ͨѶ������
    �ļ���      ��  CSFBaseInterface.h
    ����        ��  ���ļ�������ͨѶ���������нӿ���Ҫ�Ļ�������
    �汾        ��  1.0.1
    ����        ��  ��տΰ

    ��������    ��  2008.5
*/

#ifndef CSFDATAOBJECT_H
#define CSFDATAOBJECT_H

//#include "csfdefine.h"
#include "csflist.h"

class CCSF_GDO;


/*************************************************
  ������:  CCSF_Src
  ������:  ����Դ����
*************************************************/
class CCSF_Src
{
public:
	//����Դͨ��Id
	CSF_UINT32 m_nId;

	//���ƣ���Ϊ��
	CSF_CHAR*  m_sName;

	//��������Ϊ��
	CSF_CHAR*  m_sDes;

	//���ԣ����庬��μ���ͬ��ĿԼ��
	CSF_INT32  m_nAttribute;

public:
	CCSF_Src()
	{
		m_sDes = CSF_NULL;
		m_sName = CSF_NULL;
	}
	~CCSF_Src()
	{
		if(m_sName)
		{
			delete m_sName;
		}
		if(m_sDes)
		{
			delete m_sDes;
		}
	}
};

/*************************************************
  ������:  CCSF_SrcChnl
  ������:  ����Դͨ������
*************************************************/
class CCSF_SrcChnl
{
public:
	//����Դͨ��Id
	CSF_UINT32 m_nId;

	//����Դ����Id
	CSF_UINT32 m_nSrc;

	//����Դͨ�������ӵ�ͨѶ����������0
	CSF_UINT32 m_nFronter;

	//��ͨ�������ȼ�������Դ�ж��ͨ��ʱ��Ч��Ĭ��1��1����4���ȼ��ݼ�
	CSF_UINT32 m_nPriority;

	//0��������2��˫��
	CSF_UCHAR  m_nDoubleNet;

	//��һIP��ַ
	CSF_CHAR*  m_sIP1;

	//��һ�˿�
	CSF_UINT32 m_nPort1;

	//����IP��ַ��m_nDoubleNet��0ʱ��Ч����Ϊ��
	CSF_CHAR*  m_sIP2;
	
	//�����˿ڣ�m_nDoubleNet��0ʱ��Ч
	CSF_UINT32 m_nPort2;

	//Э�����ģ��ID
	CSF_UINT16 m_nProtId;

	//��������Ϊ��
	CSF_CHAR*  m_sDes;
public:
	CCSF_SrcChnl()
	{
		m_sIP1 = 0;
		m_sIP2 = 0;
		m_sDes = 0;
	}
	~CCSF_SrcChnl()
	{
		if(m_sIP1)
		{
			delete m_sIP1;
		}
		if(m_sIP2)
		{
			delete m_sIP2;
		}
		if(m_sDes)
		{
			delete m_sDes;
		}
	}
};

/*************************************************
  ������:  CCSF_GDA
  ������:  ͳһ����ģ����ʹ��ͨ�����ݶ����������
           ����ʱ���õ��ġ��������ԡ�
*************************************************/
class CCSF_GDA
{	
public:

	/*void CloneGDA(CCSF_GDA* obj)
	{
		Set(obj->m_sName, obj->m_nValType, obj->m_lValTotalLen, obj->m_pValues, CSF_BOOL_TRUE);
	}*/
	/***************************************************************************
	������Set
	���ܣ����á�һ�㡱���ͣ������飬�Ƕ��󣩵�����

	������
          CSF_CHAR* psName,�������ƣ�����Ϊ��

		  CSF_UCHAR nType,���Ե����ͣ��μ���CSFDefine.h��

          CSF_USHORT nLen,����ֵ��ռ�ڴ�ĳ��ȣ�Byte��

          CSF_VOID* pValue��ָ������ֵ��ָ��

          CSF_BOOLEAN bAllocate����ʶ�Ƿ���CCSF_DA�����з����µ�
		          �ڴ汣������Ե�ֵ,
				     0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				     1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
	˵����    
		  1.  ���ĳ�������ԡ�ֻ�����ƣ�û��ֵʱ��Ҫ��
		        ֵ�ĳ���Ϊ��CSF_DLEN_NULL
		        ��ֵָ�롱Ϊ��      0
		  2.  ���Set�ַ���ʱ�����ȱ��������NULL��   
	***************************************************************************/
	CSF_BOOLEAN Set(CSF_CHAR* psName,
		         CSF_UINT8 nType,
		         CSF_UINT16 nLen,
				 CSF_VOID* pValue,
				 CSF_BOOLEAN bAllocate);

	/***************************************************************************
	������SetObj
	���ܣ����á��������͵�����

	������
          CSF_CHAR* psName,�������ƣ�����Ϊ��

		  CCSF_DO* pObj,Ҫ��ӵĶ���

          CSF_BOOLEAN bAllocate����ʶ�Ƿ���CCSF_DA�����з����µ�
		          �ڴ汣������Ե�ֵ,
				     0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				     1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
    ˵����
	***************************************************************************/
	CSF_BOOLEAN SetObj(CSF_CHAR* psName,
		CCSF_GDO* pObj,
		CSF_BOOLEAN bAllocate);

	/***************************************************************************
	������SetArray
	���ܣ����á��������͡�������

	������
	       CSF_CHAR* psName,�������ƣ�����Ϊ��
	
	       CSF_UCHAR nType,�������Ե����ͣ��μ���CSFDefine.h��
	  
		   CSF_USHORT nUnitNum,����ĵ�Ԫ��Ŀ
		
           CSF_VOID* pValue��ָ���������Ե�ָ��
		  
		   CSF_BOOLEAN bAllocate����ʶ�Ƿ���CCSF_DA�����з����µ�
		          �ڴ汣������Ե�ֵ,
				  0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				  1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
    ˵����
	***************************************************************************/
	CSF_BOOLEAN SetArray(CSF_CHAR* psName,
		CSF_UINT8 nType,
		CSF_UINT16 nUnitNum,
		CSF_VOID* pValues,
		CSF_BOOLEAN bAllocate);

	/***************************************************************************
	������Clear
	���ܣ��������������ڴ棬����m_psName�����ڴ�

	������
		   CSF_BOOLEAN bDel,��ʶ�Ƿ�delete���ö����б������ԡ�ֵ
		       (m_pValues)�����ڴ�
          
    ���أ���
    ˵����
	***************************************************************************/
	void Clear(CSF_BOOLEAN bDel);

public:
	//���Ե����ƣ�����ΪNULL
	CSF_CHAR*        m_sName;
	
	//����Ĵ�С
	CSF_UINT16       m_lValTotalLen;
	
	//���ݵ�����
	CSF_UINT8        m_nValType;
	
	//�����ַ �ر���Ϊ�ַ��������Ȳ��ó���250
	CSF_UCHAR*       m_pValues;

public:
    CCSF_GDA();
	~CCSF_GDA();
};

/*************************************************
  ������:  CCSF_Type
  ������:  ��������
*************************************************/
class CCSF_Type
{
public:
	//���á�������
	CSF_BOOLEAN SetDes(CSF_CHAR* psDes);

	//��ȡ��������
	CSF_CHAR* GetDes();

	//ɾ����������
    void RemoveDes();

	//��ȡ����
	CSF_UINT8 GetType();	

protected:
	//���������
	CSF_UCHAR m_nType;

	//���������
	CSF_CHAR* m_sDes;
	
public:
	CCSF_Type()
	{
		m_sDes = CSF_NULL;
		m_nType = CSF_OBJTYPE_INVALIDATE;
	}
	
	~CCSF_Type()
	{
		if(m_sDes != CSF_NULL)
		{
			delete m_sDes;
		}
	}
};

/*************************************************
  ������:  CCSF_Data
  ������:  ���ݶ������
*************************************************/
class CCSF_Data : public CCSF_Type
{
public:
	//���ò���
	CSF_BOOLEAN SetReference(CSF_CHAR* psReference);

	//ɾ������
    void RemoveReference();

public:
    //����Ĳ�����CSF_NULLʱ����������Ч��ʹ��m_nId
	CSF_CHAR*        m_sRef;
	
    //�����id����ֵΪCSF_OBJID_INVALIDATEʱ������ʶ��Ч��
	//    ��ʱӦ��ʹ��m_sObjReference
    CSF_UINT32       m_nAppId;
	
public:
    CCSF_Data()
	{
		m_sRef = CSF_NULL;
		m_nAppId = CSF_OBJID_INVALIDATE;
	}
	~CCSF_Data()
	{
		if(m_sRef != CSF_NULL)
		{
			delete m_sRef;
		}
	}
};

/*************************************************
  ������:  CCSF_Object
  ������:  CSF��ܻ�������
*************************************************/
class CCSF_Object : public CCSF_Data
{
public:
	//��������
	CSF_VOID SetType(CSF_UINT8 nType);

public:
	//CSF����
	CSF_UINT64             m_nCSFID;

	//������ID
	CSF_UINT32             m_nElder;

	//��������
	CCSFList<CSF_VOID>   m_nAttrList;

public:
    CCSF_Object()
	{
		//��Ч����
		//m_nAttribute = CSF_OBJATRI_INVALIDATE;
		//��Ч����
		m_nCSFID = CSF_OBJID_INVALIDATE;
	}
	~CCSF_Object(){};
};

/*************************************************
  ������:  CCSF_GDO
  ������:  ͨ�����ݶ���
*************************************************/
class CCSF_GDO : public CCSF_Data
{
public:
	//���Լ�
	CCSFList<CCSF_GDA>  m_PropList;

protected:
	//��������
	CSF_UINT8          m_nGType;
public:
	//���Լ�
	CCSF_GDO()
	{
		m_nType = CSF_OBJTYPE_GERERAL;
		
		m_nGType = CSF_OBJID_INVALIDATE;
	}

public:
	/***************************************************************************
	������SetOneProp
	���ܣ����á�һ�㡱���ͣ������飬�Ƕ��󣩵�����

	������
          CSF_CHAR* psName,�������ƣ�����Ϊ��

		  CSF_UCHAR nType,���Ե����ͣ��μ���CSFDefine.h��

          CSF_USHORT nLen,����ֵ��ռ�ڴ�ĳ��ȣ�Byte��

          CSF_VOID* pValue��ָ������ֵ��ָ��
         
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
	˵����    
		  1.  ���ĳ�������ԡ�ֻ�����ƣ�û��ֵʱ��Ҫ��
			    ֵ�ĳ���Ϊ��CSF_DLEN_NULL
			   ��ֵָ�롱Ϊ��      0
		  2.  ���Set�ַ���ʱ�����ȱ��������NULL��   
	***************************************************************************/
	CSF_BOOLEAN SetOneProp(CSF_CHAR* psName,
						   CSF_UINT8 nType,
						   CSF_UINT16 nLen,
						   CSF_VOID* pValue,
						   CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	������SetArrayProp
	���ܣ����á��������͡�������

	������
	       CSF_CHAR* psName,�������ƣ�����Ϊ��
	
	       CSF_UCHAR nType,�������Ե����ͣ��μ���CSFDefine.h��
	  
		   CSF_USHORT nUnitNum,����ĵ�Ԫ��Ŀ
		
           CSF_VOID* pValue��ָ���������Ե�ָ��
		  
		   CSF_BOOLEAN bAllocate����ʶ�Ƿ���CCSF_DA�����з����µ�
		          �ڴ汣������Ե�ֵ,
				  0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				  1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
    ˵����
	***************************************************************************/
	CSF_BOOLEAN SetArrayProp(CSF_CHAR* psName,
		              CSF_UINT8 nType,
		              CSF_UINT16 nUnitNum,
					  CSF_VOID* pValues,
					  CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	������SetObjProp
	���ܣ����á��������͵�����

	������
          CSF_CHAR* psName,�������ƣ�����Ϊ��

		  CCSF_GDO* pObj,Ҫ��ӵĶ���

          CSF_BOOLEAN bAllocate����ʶ�Ƿ���CCSF_DA�����з����µ�
		          �ڴ汣������Ե�ֵ,
				     0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				     1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
    ˵����
	***************************************************************************/
	CSF_BOOLEAN SetObjProp(CSF_CHAR* psName,
		            CCSF_GDO* pObj,
					CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	������CopyObj
	���ܣ�����һ������

	������
          CCSF_GDO** pNewObj,Ŀ�Ķ���

		  CCSF_GDO* pObj,Դ����

          CSF_BOOLEAN bAllocate����ʶ�Ƿ���* pNewObjָ������µ�
		          �ڴ汣���pObj��ֵ,
				     0: ��ֱ��ʹ���ⲿ���ݵ��ڴ�ռ�;
				     1: ������ڴ���б���
          
    ���أ�CSF_INT32��1���ɹ�
                     0��ʧ��
    ˵����
	***************************************************************************/
	static CSF_BOOLEAN CopyObj(CCSF_GDO** pNewObj,
		CCSF_GDO* pObj,
		CSF_BOOLEAN bAllocate);


	//�õ�ĳ�����Ե�ֵ��voidָ�룩
	void* GetValue(CSF_CHAR* psName);

	/***************************************************************************
	������RemoveOneProp
	���ܣ�ɾ��ĳ������

	������
	      CSF_CHAR* psName,�������ƣ�����Ϊ��

		  CCSF_DO* pObj,Դ����

          CSF_BOOLEAN bDel����ʶ�Ƿ�ɾ���ö������ڿռ�
          
    ���أ���
    ˵����
	***************************************************************************/
	void RemoveOneProp(CSF_CHAR* psName,CSF_BOOLEAN bDel);

	/***************************************************************************
	������Clear
	���ܣ�������������ڴ棨����m_sRef���������������

	������
          CSF_BOOLEAN bDel����ʶ�Ƿ�delete���ö�������������ÿ������
		       �б��桰ֵ(m_pValues)�����ڴ�
          
    ���أ���
    ˵����
	***************************************************************************/
	void Clear(CSF_BOOLEAN bDel);

	//��ȡ����
	CSF_UINT8 GetType();
	
	//��������
	CSF_VOID SetType(CSF_UINT8 nType);
};

/*************************************************
  ������:  CCSF_DOSet
  ������:  ͨ�����ݶ���
*************************************************/
/*
class CCSF_DOSet : public CCSF_Data
{
public:
	//���ݶ���ID��
	CCSFList<CSF_UINT32>  m_DOList;
	
public:
	//���Լ�
	CCSF_DOSet()
	{
		m_nType = OBJTYPE_CSF_LOGIC;
	}
};
*/

/*************************************************
  ������:  CCSFTransBlock
  ������:  CSFʹ��CCCSFTransBlock����ͨѶ����
*************************************************/
class CCSFTransBlock
{
public:
    //����Դ����ID������0��Ч
	CSF_UINT32             m_nSrc;

    //Ӧ��ģ��ID������0��Ч
	CSF_UINT32             m_nApp; 

    //���ݴ���ԭ�򣬴���0��Ч
    CSF_UINT8              m_nCause;

	//����
	CCSFList<CCSF_Data>  
		                   m_DataObjList;

public:
	/***************************************************************************
	������AddObj
	���ܣ����һ������

	������
          CCSF_Data* pData��Ҫ��ӵĶ���
          
    ���أ���
    ˵����
	***************************************************************************/
	CSF_BOOLEAN AddObj(CCSF_Data* pData);

	/***************************************************************************
	������Clear
	���ܣ�������������ڴ棨��ն�������

	������
          CSF_BOOLEAN bDel����ʶ�Ƿ�delete���ö���������ÿ������
		       �б��桰ֵ�����ڴ�
          
    ���أ���
    ˵����
	***************************************************************************/
	void Clear(CSF_BOOLEAN bDel);

public:
    CCSFTransBlock()
    {
        m_nSrc = 0xFFFFFFFF;
        m_nApp = 1;
		m_nCause = 0;
    }
};

/*************************************************
  ������:  ICSFUnknown
  ������:  CSF�ӿڵĻ���
           CSF���������ⲿ�����ʱ��������ȡ��Ӧ�ӿ�
*************************************************/
class ICSFUnknown
{
public:
	virtual void QueryInterface(char* InterfaceName, 
		                        void** ppUnknown) = 0;
};

/*************************************************
  ������:  CSF_ARRAY
  ������:  ͨ�����ݶ��������������ԡ���ʹ�õ�����
*************************************************/
struct CSF_ARRAY
{
    //������������Ԫ����Ŀ
	unsigned short nNum;

	union Array{		
		CSF_INT8*       pCSFInt8;
		CSF_UINT8*      pCSFUint8;
		CSF_INT16*      pCSFInt16;
		CSF_UINT16*     pCSFUint16;
		CSF_INT32*      pCSFInt32;
		CSF_UINT32*     pCSFUint32;
		CSF_FLOAT*      pCSFFloat;
		CSF_DOUBLE*     pCSFDouble;
		CSF_BOOLEAN*    pCSFBool;
		CSF_TIME*       pCSFTime;
		CSF_STRING*     pCSFString;            
		CSF_OBJ*        pCSFObj;                 
	} Values;
};

#endif
