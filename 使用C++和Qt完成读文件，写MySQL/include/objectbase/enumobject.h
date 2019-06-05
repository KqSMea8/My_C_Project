#ifndef _ENUMOBJECT__H_
#define _ENUMOBJECT__H_

#include <q3ptrlist.h>
#include "objectbase.h" // for OBJECTBASE_EXPORT
#include "intfobject.h" // for CIntfObject
#include "../../interface/generalintf.h" // for IICSEnum

typedef Q3PtrList<IICSUnknown> OBJECTBASE_EXPORT IUnkownList;

/*
实现枚举接口类CEnumObject定义
它以一个指针接口List(IUnkownList)为构造函数
*/
class OBJECTBASE_EXPORT CEnumObject : public CIntfObject  
{
public:
    CEnumObject(IICSUnknown *pOuter = 0);
    CEnumObject(IUnkownList &unknownlst, IICSUnknown *pOuter = 0);
    virtual ~CEnumObject();
    virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);

protected:
	int GetCount();
	void First();
	void Skip(int nElement);
	int Next(int nElement, IICSUnknown **ppObjs);
	void Clone(IICSEnum **ppEnum);
	
    //interface IEnum
public:
    class OBJECTBASE_EXPORT XEnum : public IICSEnum
    {
    public:
        CEnumObject *m_pParent;        
        virtual int AddRef()
        {  
            return m_pParent->AddRef();
        };
        virtual int Release()
        {  
			return m_pParent->Release();
        };
        virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown)
        {  
            return m_pParent->QueryInterface(InterfaceName, ppUnknown);
        };

        virtual int GetCount()
        {   
            return m_pParent->GetCount();
        };
        virtual void Reset()
        {   
            m_pParent->First();
        };
        virtual void Skip(int nElement)
        {   
            m_pParent->Skip(nElement);
        };
        virtual int Next(int nElement, IICSUnknown **ppObjs)
        {   
            return m_pParent->Next(nElement, ppObjs);
        };
        virtual void Clone(IICSEnum **ppEnum)
        {  
            m_pParent->Clone(ppEnum);
        };
    }m_Enum;
	
private:
	friend class CEnumObject::XEnum;
    IUnkownList m_lstIUnknown;
};

#endif 
