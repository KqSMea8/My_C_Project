/*
文件名: IntfObject.h
描述:   定义类CIntfObjectImpl.h
*/
#ifndef _INTFOBJECT__H_
#define _INTFOBJECT__H_
#include <qmutex.h>
#include "icsunknown.h"

#include "genintfexpdef.h"

/*
CIntfObjectImpl:
(1) 实现IICSUnknown接口
(2) 提供虚函数以让派生类可以实现基类实现的接口(objQueryInterface)
(3) 支持聚合
*/
class GENERALINTFIMPL_CLASS CIntfObjectImpl: virtual public IICSUnknown  
{
public:                     
    virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown);
    virtual int AddRef();
    virtual int Release();

    CIntfObjectImpl(IICSUnknown *pOuter = 0);
    virtual ~CIntfObjectImpl();
protected:
    int m_iRef;                         //引用计数
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
    //对象本身的IICSUnknown接口实现
    virtual int ObjAddRef();
    virtual int ObjRelease();
    virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);
};

#endif 
