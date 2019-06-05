/*****************************************************************************/
/*许继电气股份有限公司                                     版权：2006-2010   */
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
    文件名      ：  CSFList.h
    描述        ：  本文件定义了CSF框架所使用链表
    版本        ：  1.0.1
    作者        ：  连湛伟
    
    创建日期    ：  2007.7    
*/


#ifndef CSFLIST_H
#define CSFLIST_H

#include "csfdefine.h"
#include <stdio.h>
/*****************************************************
  类名称:  CCSFListMember
  类描述:  CSF链表的节点
*****************************************************/
template<class T> class CCSFListMember
{
public:
    CCSFListMember()
    {
        m_pNext = 0;
    }
    CCSFListMember<T> *m_pNext;
    T* m_pObj;
};

template <class T> class CCSFList_Iterator;
template<class T> class CCSFList;

/*****************************************************
  类名称:  CCSFList
  类描述:  CSF链表
*****************************************************/
template<class T> class CCSFList
{
    friend class CCSFList_Iterator<T>;
public:

	CCSFList(CCSFList* pList)
	{
        if(pList)
        {
		    m_pList = pList;
            m_nSize = -1;
        }
        else
        {
            CCSFList();
        }
	}


    CCSFList()
    {
        m_nSize = 0;
        m_pFirst = CSF_NULL;
        m_pLast  = CSF_NULL;
    }
/*    
	~CCSFList()
	{
	}
*/
private:
    CSF_INT32 m_nSize;
    CCSFListMember<T>* m_pFirst;
    CCSFListMember<T>* m_pLast;
    CCSFList* m_pList;

protected:
    //index从0开始
    CCSFListMember<T>* GetEntryAt(CSF_INT32 index)
    {
        CSF_INT32 nSize;
        CCSFListMember<T>* pCurrent = CSF_NULL;

        if(m_nSize == -1)
        {
            nSize = m_pList->m_nSize;
            pCurrent = (m_pList->m_pFirst);
        }
        else
        {
            nSize = m_nSize;
            pCurrent = m_pFirst;
        }

        if( nSize == 0 || index >= nSize || index < 0)
        {
            return CSF_NULL;
        }

        for(CSF_INT32 i = 0; i < index ; i++)
        {
            pCurrent = pCurrent->m_pNext;            
        }	
        return pCurrent;
    }	
    
    //index从0开始
    void RemoveEntryAt(CSF_INT32 index)
    {
        CSF_INT32* pnSize;
        CCSFListMember<T>** pCurrent = CSF_NULL;
        CCSFListMember<T>* pCurrent2 = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pnSize = &m_pList->m_nSize;
            pCurrent = &(m_pList->m_pFirst);
        }
        else
        {
            pnSize = &m_nSize;
            pCurrent = &m_pFirst;
        }

        if((*pnSize) <= 0 || index >= (*pnSize) || index < 0)
        {
            return;
        }
        
        if(index == 0)
        {
            CCSFListMember<T>* pTemp = *pCurrent;
            
            *pCurrent = (*pCurrent)->m_pNext;
            (*pnSize) --;
            
            delete pTemp;
        }
        else
        {
            int nTemp = index - 1;
            pCurrent2 = *pCurrent;

            for(CSF_INT32 i = 0; i < nTemp; i++)
            {
                pCurrent2 = pCurrent2->m_pNext;            
            }	

            CCSFListMember<T>* pte = (*pCurrent)->m_pNext;
            (*pCurrent)->m_pNext = pte->m_pNext;

            delete pte;
 
            (*pnSize) --;
        }
    }

public:
	CSF_INT32 Size()
	{
        CSF_INT32* pnSize;
        
        if(m_nSize == -1)
        {
            pnSize = &m_pList->m_nSize;
        }
        else
        {
            pnSize = &m_nSize;
        }
        
        return *pnSize;
	}

    CSF_BOOLEAN AddTail(T *pEntry)  
	{
		if(pEntry == CSF_NULL)
		{
			return CSF_BOOL_FALSE;
		}
		
		CCSFListMember<T>* pNew = new CCSFListMember<T>;
		if(pNew == CSF_NULL)
		{
			return CSF_BOOL_FALSE;
		}
		else
		{
			pNew->m_pObj = pEntry;
			pNew->m_pNext = CSF_NULL;
		}
		
        CSF_INT32* pnSize;
        CCSFListMember<T>** pFirst = CSF_NULL;
        CCSFListMember<T>** pLast = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pnSize = &m_pList->m_nSize;
            pFirst = &(m_pList->m_pFirst);
            pLast = &(m_pList->m_pLast);
        }
        else
        {
            pnSize = &m_nSize;
            pFirst = &m_pFirst;
            pLast = &m_pLast;
        }

		if((*pFirst) == CSF_NULL)
		{
			*pFirst = pNew;
			*pLast = pNew;
		}
		else
		{
			(*pLast)->m_pNext = pNew;
			(*pLast) = pNew;
		}
		
		(*pnSize) ++;
		
		return CSF_BOOL_TRUE;
	}

    CSF_BOOLEAN AddHead(T *pEntry)  
    {
        if(pEntry == CSF_NULL)
        {
            return CSF_BOOL_FALSE;
        }
        
        CCSFListMember<T>* pNew = new CCSFListMember<T>;
        if(pNew == CSF_NULL)
        {
            return CSF_BOOL_FALSE;
        }
        else
        {
            pNew->m_pObj = pEntry;
            pNew->m_pNext = m_pFirst;
        }

        CSF_INT32* pnSize;
        CCSFListMember<T>** pFirst = CSF_NULL;
        CCSFListMember<T>** pLast = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pnSize = &m_pList->m_nSize;
            pFirst = &(m_pList->m_pFirst);
            pLast = &(m_pList->m_pLast);
        }
        else
        {
            pnSize = &m_nSize;
            pFirst = &m_pFirst;
            pLast = &m_pLast;
        }

        if(*pLast == CSF_NULL)
        {
            *pFirst = pNew;
            *pLast  = pNew;
        }
        else
        {
            pNew->m_pNext = (*pFirst);
            (*pFirst) = pNew;
        }

        (*pnSize) ++;
        
        return CSF_BOOL_TRUE;
	}

    //index从0开始
    CSF_BOOLEAN InsertAt(CSF_INT32 index,T *pEntry)
    {
        CSF_INT32* pnSize;
        CCSFListMember<T>** pFirst = CSF_NULL;
        CCSFListMember<T>** pLast = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pnSize = &m_pList->m_nSize;
            pFirst = &(m_pList->m_pFirst);
            pLast = &(m_pList->m_pLast);
        }
        else
        {
            pnSize = &m_nSize;
            pFirst = &m_pFirst;
            pLast = &m_pList;
        }

        if(index > *pnSize || index < 0)
        {
            return CSF_BOOL_FALSE;
        }
        
        CCSFListMember<T>* pNew = new CCSFListMember<T>;
        if(pNew == CSF_NULL)
        {
            return CSF_BOOL_FALSE;
        }
        else
        {
            pNew->m_pObj = pEntry;		
        }
        
        if(index == 0)
        {
            if(*pnSize == 0)
            {
                pNew->m_pNext = CSF_NULL;
                *pFirst = pNew;
                *pLast = pNew;                   
            }
            else
            {
                pNew->m_pNext = *pFirst;
                *pFirst = pNew;                
            }    
        }
        else
        {
            int nTemp = index - 1;
            for(CSF_INT32 i = 0; i < nTemp ; i++)
            {
                *pFirst = (*pFirst)->m_pNext;            
            }
            pNew->m_pNext = (*pFirst)->m_pNext;
            (*pFirst)->m_pNext = pNew;        
        }
        
        (*pnSize) ++;
        return CSF_BOOL_TRUE;
	}

    //index从0开始
    T * GetAt(CSF_INT32 index)
    {
        CCSFListMember<T>* pCurrent = GetEntryAt(index);
        if(pCurrent)
        {
            return pCurrent->m_pObj;
        }
        else
        {
            return CSF_NULL;
        }
	}

    T * GetFirst()
    {
        CCSFListMember<T>** pFirst = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pFirst = &(m_pList->m_pFirst);
        }
        else
        {
            pFirst = &m_pFirst;
        }

        if(*pFirst)
        {
            return (*pFirst)->m_pObj;
        }
        else
        {
            return CSF_NULL;
        }
    }

    T * GetLast()
    {
        CCSFListMember<T>** pLast = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pLast = &(m_pList->m_pLast);
        }
        else
        {
            pLast = &m_pLast;
        }

        if(*pLast)
        {
            return (*pLast)->m_pObj;
        }
        else
        {
            return CSF_NULL;
        }
    }

	CSF_BOOLEAN Have(T* pEntry)
	{
        CCSFListMember<T>** pFirst = CSF_NULL;
        
        if(m_nSize == -1)
        {
            pFirst = &(m_pList->m_pFirst);
        }
        else
        {
            pFirst = &m_pFirst;
        }

		while((*pFirst) != CSF_NULL)
		{
			if(pEntry == (*pFirst)->m_pObj)
			{
				return CSF_BOOL_TRUE;
			}
            *pFirst = (*pFirst)->m_pNext;
		}
		return CSF_BOOL_FALSE;
	}

    void Clear()
    {
        while(m_nSize > 0)
        {
            RemoveEntryAt(0);
        }		
	}

    void RemoveTail()
    {
        RemoveEntryAt(m_nSize-1);
    }

    void RemoveHead()
    {
        RemoveEntryAt(0);
    }

    void RemoveAt(CSF_INT32 index)
    {
        RemoveEntryAt(index);
    }
};

template <class T> class CCSFList_Iterator
{
    friend class CCSFList<T>;

public:
    CCSFList_Iterator (CCSFList<T>* pl)
    {
        nIndex_ = 0;
        list_ = pl;

        if(pl)
        {
            if(pl->m_nSize == -1)
            {
                node_ = pl->m_pList->m_pFirst;
            }
            else
            {
                node_ = pl->m_pFirst;
            }
            
        }
        else
        {
            node_ = CSF_NULL;
        }
    }
    T* Do()
    {
        if(node_)
        {
            return node_->m_pObj;
        }
        else
        {
            return CSF_NULL;
        }            
    }
	void operator++ (void)
    {
        if(node_ && node_->m_pNext)
        {
            nIndex_ ++;
            node_ = node_->m_pNext;
        }
        else
        {
            node_ = CSF_NULL;
        }
    }
    void remove()
    {
        list_->RemoveEntryAt(nIndex_);
        if(nIndex_ > 0)
        {
            nIndex_ --;
        }
    }

private:
    CCSFList<T> *list_;
    CCSFListMember<T> *node_;
    CSF_INT32 nIndex_;
};

#endif
