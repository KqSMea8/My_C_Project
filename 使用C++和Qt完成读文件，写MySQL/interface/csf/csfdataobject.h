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
    项目名称    ：  通讯服务框架
    文件名      ：  CSFBaseInterface.h
    描述        ：  本文件定义了通讯服务框架所有接口需要的基本对象
    版本        ：  1.0.1
    作者        ：  连湛伟

    创建日期    ：  2008.5
*/

#ifndef CSFDATAOBJECT_H
#define CSFDATAOBJECT_H

//#include "csfdefine.h"
#include "csflist.h"

class CCSF_GDO;


/*************************************************
  类名称:  CCSF_Src
  类描述:  数据源对象
*************************************************/
class CCSF_Src
{
public:
	//数据源通道Id
	CSF_UINT32 m_nId;

	//名称，可为空
	CSF_CHAR*  m_sName;

	//描述，可为空
	CSF_CHAR*  m_sDes;

	//属性，具体含义参见不同项目约定
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
  类名称:  CCSF_SrcChnl
  类描述:  数据源通道对象
*************************************************/
class CCSF_SrcChnl
{
public:
	//数据源通道Id
	CSF_UINT32 m_nId;

	//数据源对象Id
	CSF_UINT32 m_nSrc;

	//数据源通道所连接的通讯主机，大于0
	CSF_UINT32 m_nFronter;

	//该通道的优先级（数据源有多个通道时有效，默认1，1－》4优先级递减
	CSF_UINT32 m_nPriority;

	//0，单网；2，双网
	CSF_UCHAR  m_nDoubleNet;

	//网一IP地址
	CSF_CHAR*  m_sIP1;

	//网一端口
	CSF_UINT32 m_nPort1;

	//网二IP地址，m_nDoubleNet＝0时无效，可为空
	CSF_CHAR*  m_sIP2;
	
	//网二端口，m_nDoubleNet＝0时无效
	CSF_UINT32 m_nPort2;

	//协议解析模块ID
	CSF_UINT16 m_nProtId;

	//描述，可为空
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
  类名称:  CCSF_GDA
  类描述:  统一数据模型在使用通用数据对象进行数据
           交换时所用到的“数据属性”
*************************************************/
class CCSF_GDA
{	
public:

	/*void CloneGDA(CCSF_GDA* obj)
	{
		Set(obj->m_sName, obj->m_nValType, obj->m_lValTotalLen, obj->m_pValues, CSF_BOOL_TRUE);
	}*/
	/***************************************************************************
	函数：Set
	功能：设置“一般”类型（非数组，非对象）的属性

	参数：
          CSF_CHAR* psName,属性名称，不可为空

		  CSF_UCHAR nType,属性的类型，参见“CSFDefine.h”

          CSF_USHORT nLen,属性值所占内存的长度（Byte）

          CSF_VOID* pValue，指向属性值的指针

          CSF_BOOLEAN bAllocate，标识是否在CCSF_DA对象中分配新的
		          内存保存该属性的值,
				     0: 则直接使用外部传递的内存空间;
				     1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
	说明：    
		  1.  如果某个”属性“只有名称，没有值时，要求：
		        值的长度为：CSF_DLEN_NULL
		        “值指针”为：      0
		  2.  如果Set字符串时，长度必须包含“NULL”   
	***************************************************************************/
	CSF_BOOLEAN Set(CSF_CHAR* psName,
		         CSF_UINT8 nType,
		         CSF_UINT16 nLen,
				 CSF_VOID* pValue,
				 CSF_BOOLEAN bAllocate);

	/***************************************************************************
	函数：SetObj
	功能：设置“对象”类型的属性

	参数：
          CSF_CHAR* psName,属性名称，不可为空

		  CCSF_DO* pObj,要添加的对象

          CSF_BOOLEAN bAllocate，标识是否在CCSF_DA对象中分配新的
		          内存保存该属性的值,
				     0: 则直接使用外部传递的内存空间;
				     1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
    说明：
	***************************************************************************/
	CSF_BOOLEAN SetObj(CSF_CHAR* psName,
		CCSF_GDO* pObj,
		CSF_BOOLEAN bAllocate);

	/***************************************************************************
	函数：SetArray
	功能：设置“数组类型”的属性

	参数：
	       CSF_CHAR* psName,属性名称，不可为空
	
	       CSF_UCHAR nType,数组属性的类型，参见“CSFDefine.h”
	  
		   CSF_USHORT nUnitNum,数组的单元数目
		
           CSF_VOID* pValue，指向数组属性的指针
		  
		   CSF_BOOLEAN bAllocate，标识是否在CCSF_DA对象中分配新的
		          内存保存该属性的值,
				  0: 则直接使用外部传递的内存空间;
				  1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
    说明：
	***************************************************************************/
	CSF_BOOLEAN SetArray(CSF_CHAR* psName,
		CSF_UINT8 nType,
		CSF_UINT16 nUnitNum,
		CSF_VOID* pValues,
		CSF_BOOLEAN bAllocate);

	/***************************************************************************
	函数：Clear
	功能：清除本对象相关内存，包括m_psName所用内存

	参数：
		   CSF_BOOLEAN bDel,标识是否delete掉该对象中保存属性“值
		       (m_pValues)”的内存
          
    返回：无
    说明：
	***************************************************************************/
	void Clear(CSF_BOOLEAN bDel);

public:
	//属性的名称，不可为NULL
	CSF_CHAR*        m_sName;
	
	//缓存的大小
	CSF_UINT16       m_lValTotalLen;
	
	//数据的类型
	CSF_UINT8        m_nValType;
	
	//缓存地址 特别：若为字符串，长度不得超过250
	CSF_UCHAR*       m_pValues;

public:
    CCSF_GDA();
	~CCSF_GDA();
};

/*************************************************
  类名称:  CCSF_Type
  类描述:  对象类型
*************************************************/
class CCSF_Type
{
public:
	//设置“描述”
	CSF_BOOLEAN SetDes(CSF_CHAR* psDes);

	//读取“描述”
	CSF_CHAR* GetDes();

	//删除“描述”
    void RemoveDes();

	//读取类型
	CSF_UINT8 GetType();	

protected:
	//对象的类型
	CSF_UCHAR m_nType;

	//对象的描述
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
  类名称:  CCSF_Data
  类描述:  数据对象基类
*************************************************/
class CCSF_Data : public CCSF_Type
{
public:
	//设置参引
	CSF_BOOLEAN SetReference(CSF_CHAR* psReference);

	//删除参引
    void RemoveReference();

public:
    //对象的参引，CSF_NULL时，本参引无效，使用m_nId
	CSF_CHAR*        m_sRef;
	
    //对象的id，当值为CSF_OBJID_INVALIDATE时，本标识无效，
	//    此时应当使用m_sObjReference
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
  类名称:  CCSF_Object
  类描述:  CSF框架基本对象
*************************************************/
class CCSF_Object : public CCSF_Data
{
public:
	//设置类型
	CSF_VOID SetType(CSF_UINT8 nType);

public:
	//CSF对象
	CSF_UINT64             m_nCSFID;

	//父对象ID
	CSF_UINT32             m_nElder;

	//对象属性
	CCSFList<CSF_VOID>   m_nAttrList;

public:
    CCSF_Object()
	{
		//无效属性
		//m_nAttribute = CSF_OBJATRI_INVALIDATE;
		//无效对象
		m_nCSFID = CSF_OBJID_INVALIDATE;
	}
	~CCSF_Object(){};
};

/*************************************************
  类名称:  CCSF_GDO
  类描述:  通用数据对象
*************************************************/
class CCSF_GDO : public CCSF_Data
{
public:
	//属性集
	CCSFList<CCSF_GDA>  m_PropList;

protected:
	//对象类型
	CSF_UINT8          m_nGType;
public:
	//属性集
	CCSF_GDO()
	{
		m_nType = CSF_OBJTYPE_GERERAL;
		
		m_nGType = CSF_OBJID_INVALIDATE;
	}

public:
	/***************************************************************************
	函数：SetOneProp
	功能：设置“一般”类型（非数组，非对象）的属性

	参数：
          CSF_CHAR* psName,属性名称，不可为空

		  CSF_UCHAR nType,属性的类型，参见“CSFDefine.h”

          CSF_USHORT nLen,属性值所占内存的长度（Byte）

          CSF_VOID* pValue，指向属性值的指针
         
    返回：CSF_INT32，1：成功
                     0：失败
	说明：    
		  1.  如果某个”属性“只有名称，没有值时，要求：
			    值的长度为：CSF_DLEN_NULL
			   “值指针”为：      0
		  2.  如果Set字符串时，长度必须包含“NULL”   
	***************************************************************************/
	CSF_BOOLEAN SetOneProp(CSF_CHAR* psName,
						   CSF_UINT8 nType,
						   CSF_UINT16 nLen,
						   CSF_VOID* pValue,
						   CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	函数：SetArrayProp
	功能：设置“数组类型”的属性

	参数：
	       CSF_CHAR* psName,属性名称，不可为空
	
	       CSF_UCHAR nType,数组属性的类型，参见“CSFDefine.h”
	  
		   CSF_USHORT nUnitNum,数组的单元数目
		
           CSF_VOID* pValue，指向数组属性的指针
		  
		   CSF_BOOLEAN bAllocate，标识是否在CCSF_DA对象中分配新的
		          内存保存该属性的值,
				  0: 则直接使用外部传递的内存空间;
				  1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
    说明：
	***************************************************************************/
	CSF_BOOLEAN SetArrayProp(CSF_CHAR* psName,
		              CSF_UINT8 nType,
		              CSF_UINT16 nUnitNum,
					  CSF_VOID* pValues,
					  CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	函数：SetObjProp
	功能：设置“对象”类型的属性

	参数：
          CSF_CHAR* psName,属性名称，不可为空

		  CCSF_GDO* pObj,要添加的对象

          CSF_BOOLEAN bAllocate，标识是否在CCSF_DA对象中分配新的
		          内存保存该属性的值,
				     0: 则直接使用外部传递的内存空间;
				     1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
    说明：
	***************************************************************************/
	CSF_BOOLEAN SetObjProp(CSF_CHAR* psName,
		            CCSF_GDO* pObj,
					CSF_BOOLEAN bAllocate);
	
	/***************************************************************************
	函数：CopyObj
	功能：拷贝一个对象

	参数：
          CCSF_GDO** pNewObj,目的对象

		  CCSF_GDO* pObj,源对象

          CSF_BOOLEAN bAllocate，标识是否在* pNewObj指针分配新的
		          内存保存该pObj的值,
				     0: 则直接使用外部传递的内存空间;
				     1: 则分配内存进行保存
          
    返回：CSF_INT32，1：成功
                     0：失败
    说明：
	***************************************************************************/
	static CSF_BOOLEAN CopyObj(CCSF_GDO** pNewObj,
		CCSF_GDO* pObj,
		CSF_BOOLEAN bAllocate);


	//得到某个属性的值（void指针）
	void* GetValue(CSF_CHAR* psName);

	/***************************************************************************
	函数：RemoveOneProp
	功能：删除某个属性

	参数：
	      CSF_CHAR* psName,属性名称，不可为空

		  CCSF_DO* pObj,源对象

          CSF_BOOLEAN bDel，标识是否删除该对象所在空间
          
    返回：无
    说明：
	***************************************************************************/
	void RemoveOneProp(CSF_CHAR* psName,CSF_BOOLEAN bDel);

	/***************************************************************************
	函数：Clear
	功能：清理本对象相关内存（包括m_sRef，与清空属性链表）

	参数：
          CSF_BOOLEAN bDel，标识是否delete掉该对象属性链表中每个属性
		       中保存“值(m_pValues)”的内存
          
    返回：无
    说明：
	***************************************************************************/
	void Clear(CSF_BOOLEAN bDel);

	//读取类型
	CSF_UINT8 GetType();
	
	//设置类型
	CSF_VOID SetType(CSF_UINT8 nType);
};

/*************************************************
  类名称:  CCSF_DOSet
  类描述:  通用数据对象集
*************************************************/
/*
class CCSF_DOSet : public CCSF_Data
{
public:
	//数据对象ID集
	CCSFList<CSF_UINT32>  m_DOList;
	
public:
	//属性集
	CCSF_DOSet()
	{
		m_nType = OBJTYPE_CSF_LOGIC;
	}
};
*/

/*************************************************
  类名称:  CCSFTransBlock
  类描述:  CSF使用CCCSFTransBlock进行通讯传输
*************************************************/
class CCSFTransBlock
{
public:
    //数据源对象ID，大于0有效
	CSF_UINT32             m_nSrc;

    //应用模块ID，大于0有效
	CSF_UINT32             m_nApp; 

    //数据传送原因，大于0有效
    CSF_UINT8              m_nCause;

	//对象集
	CCSFList<CCSF_Data>  
		                   m_DataObjList;

public:
	/***************************************************************************
	函数：AddObj
	功能：添加一个对象

	参数：
          CCSF_Data* pData，要添加的对象
          
    返回：无
    说明：
	***************************************************************************/
	CSF_BOOLEAN AddObj(CCSF_Data* pData);

	/***************************************************************************
	函数：Clear
	功能：清理本对象相关内存（清空对象链表）

	参数：
          CSF_BOOLEAN bDel，标识是否delete掉该对象链表中每个对象
		       中保存“值”的内存
          
    返回：无
    说明：
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
  类名称:  ICSFUnknown
  类描述:  CSF接口的基类
           CSF加载所有外部共享库时，用来获取相应接口
*************************************************/
class ICSFUnknown
{
public:
	virtual void QueryInterface(char* InterfaceName, 
		                        void** ppUnknown) = 0;
};

/*************************************************
  类名称:  CSF_ARRAY
  类描述:  通用数据对象“数组类型属性”所使用的数组
*************************************************/
struct CSF_ARRAY
{
    //数组所包含单元的数目
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
