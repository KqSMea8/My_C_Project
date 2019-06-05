#ifndef _ICSMAP_H_
#define _ICSMAP_H_

#include <Q3ValueList>
#include <qvariant.h>

/* 模仿 qt 中的 qmap 写的一个类。只插数据不排序 

   只根据需要写了一些必需的方法，
 
   该类的特点是：
   不排序
   不完整
   不保证效率

   如果需要使用，请切记以上几点。
   如果有某种方法本类中不包含，请自己加上（注意注释）。

   张展国 2008/10/17 */
template<class Key, class T>
class ICSMapIterator;

template<class Key, class T>
class ICSMap
{
private :
	Q3ValueList<Key> m_LKey;
	Q3ValueList<T>   m_LData;

//	int m_iIndex;
public:
	int Find(Key keyIn)
	{
		for(int it = 0 ; it < m_LKey.count() ; it ++)
		{
			Key sTemp = m_LKey[it];
			if(m_LKey[it] == keyIn)
			{
				return it ;
			}
		}

		return -1;
	};


	typedef ICSMapIterator<Key,T> iterator;
	typedef ICSMapIterator<Key,T> Iterator;
	
	int size()
	{
		return itemCount();
	}

	int itemCount()
	{
		return m_LKey.count();
	}

	ICSMapIterator<Key,T> insert(Key keyIn,T dataIn)
	{
		m_LKey.append(keyIn);
		m_LData.append(dataIn);

		if(0 == 1)
		{
			for(int x = 0 ; x < m_LKey.count() ; x ++)
			{
				Key sT = m_LKey[x];
				T sTy = m_LData[x];
			}

			

		}

		return ICSMapIterator<Key,T>(keyIn,dataIn,this,m_LKey.count() - 1);
	};

	void insert(ICSMap<Key,T> mOther)
	{
		ICSMapIterator<Key,T> it = mOther.begin();
		for( ; /*it != mapProp.end()*/!it.isEnd(); ++it )
		{
			insert(it.key(),it.data());
		}
	};

	
	ICSMapIterator<Key,T> update(Key keyIn,T dataIn)
	{
		int iFind = Find(keyIn);
		if(iFind >= 0)
		{
			m_LData[iFind] = dataIn;
			return ICSMapIterator<Key,T>(m_LKey[iFind],m_LData[iFind],this,iFind);
		}
		else return insert(keyIn,dataIn);

	};

	bool getvalue(int iIndex , Key& keyOut , T& dataOut)
	{
		if( iIndex <0 || iIndex >= m_LKey.count() )
		{
			return false;
		}
		keyOut = m_LKey[iIndex];
		dataOut = m_LData[iIndex];
		return true;
	};

	bool remove(Key keyIn)
	{
		int iFind = Find(keyIn);
		if(iFind >= 0)
		{
			if(m_LData.remove(m_LData[iFind]))
			{
				return m_LKey.remove(m_LKey[iFind]);
			}

			else
			{
				return false;
			}
			
		}

		return false;
	};

	void clear()
	{
		m_LKey.clear();
		m_LData.clear();
	}

	ICSMapIterator<Key,T> operator [] (Key keyIn)
	{
		int iFind = Find(keyIn);
		if(iFind >= 0)
		{
			return ICSMapIterator<Key,T>(m_LKey[iFind],m_LData[iFind],this,iFind);
		}
//
//		/* 加入  2008/10/17 */
		return insert(keyIn,T());
//		return ICSMapIterator<Key,T>(Key(),T(),this,-1);
	};
	
	ICSMapIterator<Key,T> begin()
	{
		if (this->size()!=0)
		{
			return ICSMapIterator<Key,T>(m_LKey[0],m_LData[0],this,0);
		}
		else
			return ICSMapIterator<Key,T>( Key(), T(), this,0 );
	};
	ICSMapIterator<Key,T> end()
	{
		if (this->size()!=0)
		{
			int iIndex = m_LKey.count() - 1;
			return ICSMapIterator<Key,T>(m_LKey[iIndex],m_LData[iIndex],this,iIndex);
		}	
		else
			return ICSMapIterator<Key,T>( Key(), T(), this,0 );
	};

	~ICSMap()
	{
		m_LData.clear();
		m_LKey.clear();
	};
	ICSMap()
	{
//		m_LData.clear();
//		m_LKey.clear();
	};
};



template<class Key, class T>
class ICSMapIterator
{
private:
public:
	Key m_Key ;
	T   m_Data;

	ICSMap<Key,T> * m_pParent;
	int m_iIndex;
public:
	Key key()
	{
		return m_Key;
	};
	
	T   data()
	{
		return m_Data;
	};

	bool isEnd()
	{
		if(!m_pParent || m_iIndex >= m_pParent->itemCount() || m_iIndex < 0)
		{
			return true;
		}
		return false;
	}
	bool operator == (ICSMapIterator iteratorOther)
	{
		if(m_Key == iteratorOther.key() && m_pParent == iteratorOther.m_pParent)
		{
			return true;
		}
		else return false;
	}

	bool operator != (ICSMapIterator iteratorOther)
	{
		if(m_Key == iteratorOther.key() && m_pParent == iteratorOther.m_pParent)
		{
			return false;
		}
		else return true;
	}

	/*ICSMapIterator<Key,T>&*/ void operator ++ ()
	{
		if(m_pParent)
		{
			m_iIndex ++ ;
			m_pParent->getvalue(m_iIndex,m_Key,m_Data);
		}
	};
	
	/* 赋值  2008/10/17 */
	ICSMapIterator<Key,T>  operator = (T dataIn)
	{
		return m_pParent->update(m_Key,dataIn);
	};

	void operator = (ICSMapIterator iteratorOther)
	{
		if(m_Key == iteratorOther.m_Key && m_pParent == iteratorOther.m_pParent)
		{
			m_pParent->update(m_Key,iteratorOther.m_Data);
		}
		
		m_Key = iteratorOther.key();
		m_Data = iteratorOther.data();
		m_pParent = iteratorOther.m_pParent;
		m_iIndex = iteratorOther.m_iIndex;
	};

	ICSMapIterator()
	{
		m_pParent = 0;
	};
	ICSMapIterator(Key keyIn,T dataIn , ICSMap<Key,T> * parentIn,int indexIn)
	{
		m_Key = keyIn;
		m_Data= dataIn;
		m_pParent = parentIn;
		m_iIndex = indexIn;
	};
};

#endif //_ICSMAP_H_