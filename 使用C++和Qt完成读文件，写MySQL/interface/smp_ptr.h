//smp_ptr.h
#ifndef _SIMPLEAUTOPTR__H_
#define _SIMPLEAUTOPTR__H_
/*
 * 
 * a simple smart ptr
 * references:
		#std::auto_ptr
		#ics8000 >> CQIPtr
 * 2008.11.18 hkq
 */

/*
_NoRefOPOnSmpPtr类是防止智能指针调用引用计数
*/
template <class T>
    class _NoRefOPOnSmpPtr : public T
{
private:
    virtual int AddRef()=0;
    virtual int Release()=0;
};

//class IICSUnknown;

/******************************************************************************
 * 一个简单的智能指针： 
 *
 * note:
   1.使用SmpPtr的目的是为了更好的管理内存防止泄漏。为避免用户错误使用，
     SmpPtr不允许隐式构造。智能指针有一定的局限性，不能完全替代原始指针;

   2.copy construction, assignment of SmpPtr<T>操作时对象所有权会转移
     , 即：rvalue会无效; 因此，
		!不用将SmpPtr<T>作为参数传入其它函数中（可以使用SmpPtr<T>->Get()获得原始指针）
		!不要将SmpPtr<T>用在标准容器中 e.g. std::vector et al.

   3.暂不支持SmpPtr<T> baseObj = SmpPtr<T2> derivedObj;

 * conditions:
   SmpPtr<T> 管理的T*必须是COM-like对象，即：继承了IICSUnknown接口

 * usage:
   1. const SmpPtr<T> pObj(new T()); //here 'const' is recommended to use
	  if(pObj.NotNull()) { // or if(!pObj.IsNull()) or if(false == !pObj)
	    pObj->method_of_T();	}

   2. SmpPtr<T> pNonConstObj;	//non-const obj for re-assignment
	  const SmpPtr<T> pConstObj(new T());
	  pNonConstObj = pConstObj; //(after this, pConstObj points to Null;)
 
 * author: hongkeqin@xjgc.com
 * date: 2008.11.18
 ******************************************************************************/
template <class T>
class SmpPtr
{
public:
	typedef T element_type;
	typedef SmpPtr<T> _Self;

    SmpPtr()
    {
        m_p = 0;
    }

    explicit SmpPtr(T* _px)
    {
        m_p = _px;
    }
	
	//note: ownership transferred
    SmpPtr(_Self& _r) : m_p(_r.Free()) {}
	
    ~ SmpPtr()
    {
        Reset(0);
    };
	
    T* Get() const
    {
        return m_p;
    }
	
	//C-style conversion : 不提供operator T*()操作
    T& operator *() const
    {
        return *m_p;
    }
	
    _NoRefOPOnSmpPtr<T>* operator->() const
    {
        return (_NoRefOPOnSmpPtr<T>*)m_p;
    }
	
    _Self& operator =(const _Self& _r)
    {
        Reset(const_cast<_Self&>(_r).Free());
        return *this;
    } 

	//no public operator =(const T*) is provided, use this method instead
	void Reset(T* _px = 0) {
		T* _pt = this->m_p;
		if(_pt != _px && _pt)
			_pt->Release(); //
		this->m_p = _px;
	}
	
    bool operator !() const
    {
        return (m_p == 0);
    }

	bool IsNull() const { //2008.11.18
		return (m_p == 0);
	}

	bool NotNull() const {
		return !IsNull();
	}

    bool operator == (const T* pT) const
    {
        return m_p == pT;
    }	

    bool operator != (const T* pT) const
    {
        return !(this ==(pT));
    }	
	
    bool operator == (const _Self& _px) const
    {
        return m_p == _px.m_p;
    }	

    bool operator != (const _Self& _px) const
    {
        return !(this ==_px);
    }
private:
    T* m_p;

	/*
	 *	hidden from user (prone to error when using this) 
		, see Reset(T*) instead
	 */
	T* operator = (const T* _px)		
    {
        Reset(const_cast<T*>(_px));
        return m_p;
    }

    /*bool operator == (IICSUnknown* pOther)	//hidden
    {
        return false;
    }*/
	
    /*
	 * note: T::GetIntfName() must be defined, when using this method
	 * Be cautious to use this method.
	 */
	/*explicit SmpPtr(IICSUnknown* _px)
    {
        m_p = 0;
        if (_px != 0) {               
            _px->QueryInterface(T::GetIntfName(), (void **)&m_p);
			_px->Release(); //
        }
    } */ 
	
    /*
	 * note: T::GetIntfName() must be defined, when using this method
	 * Be cautious to use this method.
	 */
    /*T* operator = (IICSUnknown* _px)
    {
        IICSUnknown* pTemp = m_p;
        if (_px != 0) {
            _px->QueryInterface(T::GetIntfName(), (void **)&m_p);
			_px->Release(); //
        }
		else {
			m_p = (T*)0;
		}
        if(pTemp)
            pTemp->Release();
        return m_p;
    }*/
	
	T* Free() {
		T* _px = this->m_p;
		this->m_p = 0;
		return _px;
	}

};

#endif
