/*
�ļ���: IntfObject.h
����:   ������CIntfObjectImpl.h
*/
#ifndef _INTFOBJECT__H_
#define _INTFOBJECT__H_
#include <qmutex.h>
#include "icsunknown.h"

#include "genintfexpdef.h"

/*
CIntfObjectImpl:
(1) ʵ��IICSUnknown�ӿ�
(2) �ṩ�麯���������������ʵ�ֻ���ʵ�ֵĽӿ�(objQueryInterface)
(3) ֧�־ۺ�
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
    int m_iRef;                         //���ü���
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
    //�������IICSUnknown�ӿ�ʵ��
    virtual int ObjAddRef();
    virtual int ObjRelease();
    virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);
};

#endif 
