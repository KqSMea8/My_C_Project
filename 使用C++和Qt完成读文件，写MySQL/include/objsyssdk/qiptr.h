#ifndef _QIPTR__H_
#define _QIPTR__H_
/*
智能指针模板，摘抄自ATL
*/

/*
_NoAddRefReleaseOnCComPtr类是防止智能指针调用引用计数
*/
template <class T>
    class _NoAddRefReleaseOnCComPtr : public T
{
private:
    virtual int AddRef()=0;
    virtual int Release()=0;
};

template <class T>
class CQIPtr
{
public:
    typedef T _PtrClass;
    CQIPtr()
    {
        p = 0;
    };
    CQIPtr(T *lp)
    {
        if ((p = lp) != 0)
            p->AddRef();
    };
    CQIPtr(const CQIPtr<T>&lp)
    {
        if ((p = lp.p) != 0)
            p->AddRef();
    };  
    CQIPtr(IICSUnknown *lp)
    {
        p = 0;
        if (lp != 0)
        {               
            lp->QueryInterface(T::GetIntfName(), (void **)&p);
        }
    };  
    ~ CQIPtr()
    {
        if (p)
            p->Release();
    };
    void Release()
    {
        IICSUnknown *pTemp = p;
        if (pTemp)
        {
            p = 0;
            pTemp->Release();
        }
    };
    operator T*() const
    {
        return p;
    };
    T&operator *() const
    {
        return *p;
    };
    T**operator &()
    {
        return &p;
    };
    _NoAddRefReleaseOnCComPtr <T>*operator->() const
    {
        return (_NoAddRefReleaseOnCComPtr <T>*)p;
    };
    T *operator = (T *lp)
    {
        if (lp != 0)
            lp->AddRef();
        if (p)
            p->Release();
        p = lp;
        return p;               
    };
    T *operator = (const CQIPtr <T>&lp)
    {
        if (lp.p != 0)
            lp.p->AddRef();
        if (p)
            p->Release();
        p = lp.p;
        return p;
    };  
    T*operator = (IICSUnknown *lp)
    {
        IICSUnknown *pTemp = p;
        if (lp != 0)
        {
            lp->QueryInterface(T::GetIntfName(), (void **)&p);
        }
		else
		{
			p = (T*)0;
		}
        if (pTemp)
            pTemp->Release();
        return p;
    };
    bool operator !() const
    {
        return (p == 0);
    };
    bool operator<(T*pT) const
    {
        return p < pT;
    };
    bool operator == (T *pT) const
    {
        return p == pT;
    };
    bool IsEqualObject(IICSUnknown *pOther)
    {
        if ((p == 0) &&(pOther == 0))
            return true; 
        if ((p == 0) || (pOther == 0))
            return false; 
        IICSUnknown *punk1;
        IICSUnknown *punk2;    
        p->QueryInterface((char *)IICSUnknown::GetIntfName(), (void **)&punk1);
        pOther->QueryInterface(IICSUnknown::GetIntfName(), (void **)&punk2);
        bool b = (punk1 == punk2);
        punk1->Release();
        punk2->Release();
        return punk1 == punk2;
    };  
    bool operator == (IICSUnknown *pOther)
    {
        return IsEqualObject(pOther);
    };
    void Attach(T *p2)
    {
        if (p)
            p->Release();
        p = p2;
    };
    bool Attach(IICSUnknown*lp)
    {    
        T*p1 = 0;       
        if (lp != 0)
        {
           lp->QueryInterface(T::GetIntfName(), (void **)&p1);
        }
        if (p1)
        {
            if (p) p->Release();
            p = p1;
            return true;
        }
        else return false;        
    };
    T *Detach()
    {
        T *pt = p;
        p = 0;
        return pt;
    };
    T *p;
};

#endif
