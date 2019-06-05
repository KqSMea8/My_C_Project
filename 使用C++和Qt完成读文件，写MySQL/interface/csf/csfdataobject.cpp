
#include "csfdataobject.h"
#include "dataobject_scada.h"
#include "string.h"

CCSF_GDA::CCSF_GDA()
{
	m_sName = CSF_NULL;
	m_nValType = CSF_DT_NULL;
	m_pValues = CSF_NULL;
	m_lValTotalLen = CSF_DLEN_NULL;
}

CCSF_GDA::~CCSF_GDA()
{

}

void CCSF_GDA::Clear(CSF_BOOLEAN bDel)
{
	if(m_pValues == CSF_NULL)
	{
		return;
	}
	
	if(bDel == CSF_BOOL_FALSE)
	{
		m_pValues = CSF_NULL;
	}
	else
	{
		if(m_nValType >= CSF_DT_INT8 &&
		          m_nValType < CSF_DT_OBJ)
		{
			if(m_pValues)
			{
				delete m_pValues;
				m_pValues = CSF_NULL;
			}
		}
		else if(m_nValType == CSF_DT_OBJ)
		{
			((CCSF_GDO*)m_pValues)->Clear(CSF_BOOL_TRUE);
			
			delete m_pValues;

			m_pValues = CSF_NULL;
		}
		else if(m_nValType > CSF_DT_OBJ &&
			m_nValType < CSF_DT_ARRAY_STRING)
		{
			CSF_ARRAY* pArray = (CSF_ARRAY*)m_pValues;
			
			delete pArray->Values.pCSFInt8;
			delete pArray;	

			m_pValues = CSF_NULL;
		}
		else if(m_nValType == CSF_DT_ARRAY_STRING)
		{
			CSF_ARRAY* pArray = (CSF_ARRAY*)m_pValues;
			for(int i = 0;i < pArray->nNum;i++)
			{
				delete pArray->Values.pCSFString[i];
			}
			delete pArray->Values.pCSFString;
			delete pArray;	
			
			m_pValues = CSF_NULL;
		}
		else if(m_nValType == CSF_DT_ARRAY_OBJ)
		{
			CSF_ARRAY* pArray = (CSF_ARRAY*)m_pValues;
			for(int i = 0;i < pArray->nNum;i++)
			{
				((CCSF_GDO*)m_pValues)->Clear(CSF_BOOL_TRUE);			
			}
			delete pArray->Values.pCSFObj;
			delete pArray;	
			
			m_pValues = CSF_NULL;
		}
	}
	
	if(m_sName != CSF_NULL)
	{
		delete m_sName;
		m_sName = CSF_NULL;
	}
	
	m_nValType = CSF_DT_NULL;
	m_lValTotalLen = CSF_DLEN_NULL;
}

CSF_BOOLEAN CCSF_GDA::Set(CSF_CHAR* psName,
				         CSF_UINT8 nType,
				         CSF_UINT16 nLen,
				         CSF_VOID* pValue,
						 CSF_BOOLEAN bAllocate)
{
	if(m_sName != CSF_NULL || m_pValues != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}

	CSF_CHAR* pN = CSF_NULL;
	if(psName != CSF_NULL)
	{
		int nslen = strlen(psName);
		if(nslen > 0)	
		{
			pN = new CSF_CHAR[nslen+1];
			strcpy(pN,psName);
		}
	}
	
	CSF_UCHAR* pTV = CSF_NULL;
    if(nType != CSF_DT_NULL)
    {
		if(bAllocate && nLen > 0 && pValue != CSF_NULL)
		{
			pTV = new CSF_UCHAR[nLen];
			memcpy(pTV,pValue,nLen);
		}
		else
		{
			pTV = (CSF_UINT8*)pValue;
		}
    }
	    
    m_sName = pN;
    m_lValTotalLen = nLen;
    m_pValues = pTV;
    m_nValType = nType;
	
    return CSF_BOOL_TRUE;
}

CSF_BOOLEAN CCSF_GDA::SetObj(CSF_CHAR* psName,
						    CCSF_GDO* pObj,
							CSF_BOOLEAN bAllocate)
{
    CSF_OBJ* pNewObj = CSF_NULL;
	
	if(pObj == CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}
	
	if(bAllocate)
	{
		if(CCSF_GDO::CopyObj(&pNewObj,pObj,CSF_BOOL_TRUE) 
			        == CSF_BOOL_FALSE)
		{
			return CSF_BOOL_FALSE;
		}
	}
	else
	{
		pNewObj = pObj;
	}

	if(Set(psName,CSF_DT_OBJ,sizeof(CSF_DT_OBJ),(CSF_UCHAR*)pNewObj,CSF_BOOL_FALSE) 
		            == CSF_BOOL_FALSE)
	{
		pNewObj->Clear(CSF_BOOL_TRUE);
		delete pNewObj;

		return CSF_BOOL_FALSE;
	}
	else
	{
	    return CSF_BOOL_TRUE;
	}
}

CSF_BOOLEAN CCSF_GDA::SetArray(CSF_CHAR* psName,
					 CSF_UINT8 nType,
					 CSF_UINT16 nUnitNum,
					 CSF_VOID* pValues,
		             CSF_BOOLEAN bAllocate)
{
    CSF_ARRAY* pArray = CSF_NULL;
	void* pV = CSF_NULL;
	
    if(nType != CSF_DT_NULL)
    {
        if(pValues == CSF_NULL || nUnitNum <= 0)
        {
            return CSF_BOOL_FALSE;
        }
		
		pArray = new CSF_ARRAY;
		if(pArray == CSF_NULL)
		{
			return CSF_BOOL_FALSE;
		}
		
		pArray->nNum = nUnitNum;
		
		if(nType == CSF_DT_ARRAY_INT8 || nType == CSF_DT_ARRAY_UINT8)
		{
			if(bAllocate)
			{
				pArray->Values.pCSFInt8 = new CSF_INT8[nUnitNum];
				if(pArray->Values.pCSFInt8 == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					memcpy(pArray->Values.pCSFInt8,pValues,
						nUnitNum*CSF_DLEN_INT8);
					pV = pArray->Values.pCSFInt8;
				}
			}
			else
			{
				pArray->Values.pCSFInt8 = (CSF_INT8*)pValues;
			}
		}     
		else if(nType == CSF_DT_ARRAY_INT16 || 
			    nType == CSF_DT_ARRAY_UINT16)
		{
			if(bAllocate)
			{
				pArray->Values.pCSFInt16 = new CSF_INT16[nUnitNum];
				if(pArray->Values.pCSFInt16 == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					memcpy(pArray->Values.pCSFInt16,pValues,
						nUnitNum*CSF_DLEN_INT16);
					pV = pArray->Values.pCSFInt16;
				}
			}
			else
			{
				pArray->Values.pCSFInt16 = (CSF_INT16*)pValues;
			}
		}
		else if(nType == CSF_DT_ARRAY_INT32 || 
			    nType == CSF_DT_ARRAY_UINT32)
		{
			if(bAllocate)
			{
				pArray->Values.pCSFInt32 = new CSF_INT32[nUnitNum];
				if(pArray->Values.pCSFInt32 == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					memcpy(pArray->Values.pCSFInt32,pValues,
						   nUnitNum*CSF_DLEN_INT32);
					pV = pArray->Values.pCSFInt32;
				}
			}
			else
			{
				pArray->Values.pCSFInt32 = (CSF_INT32*)pValues;
			}
		}
		else if(nType == CSF_DT_ARRAY_FLOAT)
		{
			if(bAllocate)
			{
				pArray->Values.pCSFFloat = new CSF_FLOAT[nUnitNum];
				if(pArray->Values.pCSFFloat == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					memcpy(pArray->Values.pCSFFloat,
						   pValues,nUnitNum*CSF_DLEN_FLOAT);
					pV = pArray->Values.pCSFFloat;
				}
			}
			else
			{
				pArray->Values.pCSFFloat = (CSF_FLOAT*)pValues;
			}
		}
		else if(nType == CSF_DT_ARRAY_DOUBLE 
			    || nType == CSF_DT_TIME)
		{
			if(bAllocate)
			{
				pArray->Values.pCSFDouble = new CSF_DOUBLE[nUnitNum];
				if(pArray->Values.pCSFDouble == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					memcpy(pArray->Values.pCSFDouble,
						   pValues,nUnitNum*CSF_DLEN_DOUBLE);
					pV = pArray->Values.pCSFDouble;
				}
			}
			else
			{
				pArray->Values.pCSFDouble = (CSF_DOUBLE*)pValues;
			}
		}
		else if(nType == CSF_DT_ARRAY_STRING)
		{	
			if(bAllocate)
			{
				pArray->Values.pCSFString = new CSF_STRING[nUnitNum];
				if(pArray->Values.pCSFString == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					for(int i = 0;i < nUnitNum;i++)
					{
						int sl = strlen(((CSF_STRING*)pValues)[i]);
						pArray->Values.pCSFString[i] = new CSF_CHAR[sl+1];
						if(pArray->Values.pCSFString[i] == CSF_NULL)
						{
							for(int j=0;j<i;j++)
							{
								delete pArray->Values.pCSFString[j];
							}
							delete pArray->Values.pCSFString;
							delete pArray;
							return CSF_BOOL_FALSE;						 
						}
						else
						{
							memcpy(pArray->Values.pCSFString[i],
								   *((CSF_STRING*)pValues + i),sl+1);
						}
					}
				}
			}
			else
			{
				pArray->Values.pCSFString = (CSF_STRING*)pValues;
			}
		}
		else if(nType == CSF_DT_ARRAY_OBJ)
		{		
			if(bAllocate)
			{
				pArray->Values.pCSFObj = new CSF_OBJ[nUnitNum];
				if(pArray->Values.pCSFObj == CSF_NULL)
				{
					delete pArray;
					return CSF_BOOL_FALSE;
				}
				else
				{
					for(int i = 0;i < nUnitNum;i++)
					{
						CSF_OBJ* pCSFObj = &pArray->Values.pCSFObj[i];
						if(CCSF_GDO::CopyObj(&pCSFObj,
							((CSF_OBJ*)pValues)+i,false) == false)
						{
							delete pArray;
							return CSF_BOOL_FALSE;
						}	
						 
					}
				}
			}
			else
			{
				pArray->Values.pCSFObj = (CSF_OBJ*)pValues;
			}
		}
		else
		{
			delete pArray;
			return CSF_BOOL_FALSE;
		}
    }

	if(Set(psName,nType,sizeof(CSF_ARRAY),
		   (CSF_UCHAR*)pArray,CSF_BOOL_FALSE) == CSF_BOOL_FALSE)
	{
		delete pArray;
		return CSF_BOOL_FALSE;
	}
	else
	{
		return CSF_BOOL_TRUE;
	}
}

void CCSF_Type::RemoveDes()
{
	if(m_sDes != CSF_NULL)
	{
		delete m_sDes;
		m_sDes = CSF_NULL;
	}
}

CSF_BOOLEAN CCSF_Type::SetDes(CSF_CHAR* psDes)
{
/*
	if(m_sDes != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}
*/

	CSF_CHAR* pN = CSF_NULL;
	if(psDes != CSF_NULL)
	{
		int nslen = strlen(psDes);
		if(nslen > 0)	
		{
			pN = new CSF_CHAR[nslen+1];
			strcpy(pN,psDes);
		}
	}
	
	m_sDes = pN;
	return CSF_BOOL_TRUE;
}

CSF_UINT8 CCSF_Type::GetType()
{
	return m_nType;
}

CSF_CHAR* CCSF_Type::GetDes()
{
	return m_sDes;
}

CSF_BOOLEAN CCSF_Data::SetReference(CSF_CHAR* psReference)
{
/*
	if(m_sRef != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}
*/

	CSF_CHAR* pN = CSF_NULL;
	if(psReference != CSF_NULL)
	{
		int nslen = strlen(psReference);
		if(nslen > 0)	
		{
			pN = new CSF_CHAR[nslen+1];
			strcpy(pN,psReference);
		}
	}
	
	m_sRef = pN;
	return CSF_BOOL_TRUE;
}

void CCSF_Data::RemoveReference()
{
	if(m_sRef != CSF_NULL)
	{
		delete m_sRef;
		m_sRef = CSF_NULL;
	}
}

CSF_BOOLEAN CCSF_GDO::SetOneProp(CSF_CHAR* psName,
							   CSF_UINT8 nType,
							   CSF_UINT16 nLen,
							   CSF_VOID* pValue,
							   CSF_BOOLEAN bAllocate)
{
	if(GetValue(psName) != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}

    CCSF_GDA* pProp = new CCSF_GDA;
    if(pProp == CSF_NULL)
    {
        return CSF_BOOL_FALSE;
    }
    
    if(pProp->Set(psName,nType,nLen,pValue,bAllocate) == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
	
    if(m_PropList.AddTail(pProp) == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
	else
	{
		return CSF_BOOL_TRUE;
	}
}

CSF_BOOLEAN CCSF_GDO::CopyObj(CCSF_GDO** pNewObj,
						    CCSF_GDO* pObj,
							CSF_BOOLEAN bAllocate)
{
	if(bAllocate == CSF_BOOL_FALSE)
	{
		*pNewObj = pObj;		
	}	
	else
	{
		*pNewObj = new CSF_OBJ;
		if(*pNewObj == CSF_NULL)
		{
			return CSF_BOOL_FALSE;
		}
		
		if((*pNewObj)->SetReference(pObj->m_sRef) == CSF_BOOL_FALSE)
		{
			return CSF_BOOL_FALSE;
		}	
		
		(*pNewObj)->m_nAppId = pObj->m_nAppId;
		
		(*pNewObj)->m_nType = pObj->m_nType;

		(*pNewObj)->m_nGType = pObj->m_nGType;
		
		CCSFList_Iterator<CCSF_GDA> Iter(&pObj->m_PropList);
		CCSF_GDA* pProp = Iter.Do();
		
		while(pProp)
		{
			if(pProp->m_nValType < CSF_DT_OBJ)
			{
				if((*pNewObj)->SetOneProp(pProp->m_sName,pProp->m_nValType,
					pProp->m_lValTotalLen,pProp->m_pValues,CSF_BOOL_TRUE) == false)
				{
					(*pNewObj)->Clear(CSF_BOOL_TRUE);
					delete pNewObj;
					
					return CSF_BOOL_FALSE;
				}
			}
			else if(pProp->m_nValType == CSF_DT_OBJ)
			{
				if((*pNewObj)->SetObjProp(pProp->m_sName,
					(CSF_OBJ*)pProp->m_pValues,CSF_BOOL_TRUE) == false)
				{
					(*pNewObj)->Clear(CSF_BOOL_TRUE);
					delete pNewObj;
					
					return CSF_BOOL_FALSE;
				}
			}
			else if(pProp->m_nValType > CSF_DT_OBJ && 
				pProp->m_nValType <= CSF_DT_ARRAY_OBJ)
			{
				CSF_ARRAY* pArray = (CSF_ARRAY*)pProp->m_pValues;
				if((*pNewObj)->SetArrayProp(pProp->m_sName,pProp->m_nValType,
					pArray->nNum,(void*)pArray->Values.pCSFInt8,CSF_BOOL_TRUE) == false)
				{
					(*pNewObj)->Clear(CSF_BOOL_TRUE);
					delete pNewObj;
					
					return CSF_BOOL_FALSE;
				}
			}
			else
			{
				(*pNewObj)->Clear(CSF_BOOL_TRUE);
				delete pNewObj;
				
				return CSF_BOOL_FALSE;
			}
			
			++Iter;
			pProp = Iter.Do();
		}
	}
	return CSF_BOOL_TRUE;
}

CSF_BOOLEAN CCSF_GDO::SetArrayProp(CSF_CHAR* psName,
						 CSF_UINT8 nType,
						 CSF_UINT16 nUnitNum,
						 CSF_VOID* pValues,
						 CSF_BOOLEAN bAllocate)
{
	if(GetValue(psName) != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}
	
    CCSF_GDA* pProp = new CCSF_GDA;
    if(pProp == CSF_NULL)
    {
        return CSF_BOOL_FALSE;
    }

	if(pProp->SetArray(psName,nType,nUnitNum,pValues,bAllocate) 
		      == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
    
    if(m_PropList.AddTail(pProp) == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
	else
	{
		return CSF_BOOL_TRUE;
	}
}
CSF_BOOLEAN CCSF_GDO::SetObjProp(
			  CSF_CHAR* psName,
			  CCSF_GDO* pObj,
			  CSF_BOOLEAN bAllocate)
{
	if(GetValue(psName) != CSF_NULL)
	{
		return CSF_BOOL_FALSE;
	}

    CCSF_GDA* pProp = new CCSF_GDA;
    if(pProp == CSF_NULL)
    {
        return CSF_BOOL_FALSE;
    }
	
	if(pProp->SetObj(psName,pObj,bAllocate) == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
    
    if(m_PropList.AddTail(pProp) == CSF_BOOL_FALSE)
	{
		delete pProp;
		return CSF_BOOL_FALSE;
	}
	else
	{
		return CSF_BOOL_TRUE;
	}
}

void* CCSF_GDO::GetValue(CSF_CHAR* psName)
{
    CCSFList_Iterator<CCSF_GDA> Iter(&m_PropList);
    CCSF_GDA* pProp = Iter.Do();
    
    while(pProp)
    {
        if(strcmp(pProp->m_sName,psName)==0)
        {
            return pProp->m_pValues;			
		}
        ++Iter;
        pProp = Iter.Do();
    }
	
	return CSF_NULL;
}

void CCSF_GDO::RemoveOneProp(CSF_CHAR* psName,CSF_BOOLEAN bDel)
{
    CCSFList_Iterator<CCSF_GDA> Iter(&m_PropList);
    CCSF_GDA* pProp = Iter.Do();
    
    while(pProp)
    {
        if(strcmp(pProp->m_sName,psName)==0)
        {
			pProp->Clear(bDel);

            delete pProp;
			
            Iter.remove();
            return;
        }
		
        ++Iter;
        pProp = Iter.Do();
    }
}

CSF_UINT8 CCSF_GDO::GetType()
{
	return m_nGType;
}

CSF_VOID CCSF_GDO::SetType(CSF_UINT8 nType)
{
	m_nGType = nType;
}
void CCSF_GDO::Clear(CSF_BOOLEAN bDel)
{
    CCSFList_Iterator<CCSF_GDA> Iter(&m_PropList);
    CCSF_GDA* pProp = Iter.Do();
    
	if(bDel)
	{
		while(pProp)
		{
			pProp->Clear(bDel);
			delete pProp;

			++Iter;
			pProp = Iter.Do();
		}
	}
	m_PropList.Clear();
	
	RemoveDes();
	RemoveReference();
}

CSF_VOID CCSF_Object::SetType(CSF_UINT8 nType)
{
	m_nType = nType;
}

//设置附加参数
CSF_BOOLEAN CCSF_SDO_EventReport::SetRecord(const CSF_FLOAT* psRecord, CSF_UINT16 nNum)
{
	if(psRecord != CSF_NULL && nNum > 0)
	{
		m_nNum = nNum;
		m_pfRecord = new CSF_FLOAT[nNum];
		memcpy(m_pfRecord, psRecord, nNum * sizeof(CSF_FLOAT));
	}
	else
	{
		m_nNum = 0;
		m_pfRecord = CSF_NULL;
	}
	return CSF_BOOL_TRUE;
}

//得到附加参数
const CSF_FLOAT* CCSF_SDO_EventReport::GetRecord(CSF_UINT16& nNum)
{
	nNum = m_nNum;
	return m_pfRecord;
}

//删除附加参数
void CCSF_SDO_EventReport::RemoveRecord()
{
	if(m_pfRecord != CSF_NULL)
	{
		delete[] m_pfRecord;
		m_pfRecord = CSF_NULL;
	}
	m_nNum = 0;
}

/////////////////////////////////////////////////////////////////////////////////////

CSF_BOOLEAN CCSFTransBlock::AddObj(CCSF_Data* pData)
{
	return m_DataObjList.AddTail(pData);
}

void CCSFTransBlock::Clear(CSF_BOOLEAN bDel)
{
	if(bDel == CSF_BOOL_TRUE)
	{
		CCSFList_Iterator<CCSF_Data> ObjIter(&m_DataObjList);
		CCSF_Data* pObj = ObjIter.Do();
		while(pObj)
		{
			if(IS_GDO(pObj->GetType()))
			{
				((CCSF_GDO*)pObj)->Clear(bDel);
			}
			
			if(bDel)
			{
				delete pObj;
			}
			
			
			++ObjIter;
			pObj = ObjIter.Do();        
		}
	}

    m_DataObjList.Clear();         //清除链表单元
}


/*
void ClearPropValueBlock(CCSFPropValueBlockBase* pValueBlock,bool bDel)
{
    CCSFPropValueBlockBaseO BB(pValueBlock);
    BB.ClearAllProp();        //清除一个点中的所有属性
    BB.RemoveReference();     //清除一个点的参引
 
	if(bDel)
	{
        delete pValueBlock;        //清除点    
	}
}

void ClearPropValueBlockList(CCSFList<CCSFPropValueBlockBase>* pPropValueList)
{
    CCSFList_Iterator<CCSFPropValueBlockBase> PropValueIter(pPropValueList);
    CCSFPropValueBlockBase* pValueBlock = PropValueIter.Do();
    while(pValueBlock)
    {
        ClearPropValueBlock(pValueBlock,true);
        
        ++PropValueIter;
        pValueBlock = PropValueIter.Do();        
    }
    pPropValueList->Clear();         //清除链表单元
}
*/
