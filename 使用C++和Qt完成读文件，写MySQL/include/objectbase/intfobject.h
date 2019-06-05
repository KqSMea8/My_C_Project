/*
文件名: intfObject.h
描述:   定义类CIntfObject.h
*/
#ifndef _INTFOBJECT__H_
#define _INTFOBJECT__H_

#include <qmutex.h>
#include <qstring.h> 
//Added by qt3to4:
#include <Q3CString>

#include "objectbase.h" // for OBJECTBASE_EXPORT
#include "../../interface/icsunknown.h" // for IICSUnknown
/*
CIntfObject:
(1) 实现IICSUnknown接口
(2) 提供虚函数以让派生类可以实现基类实现的接口(objQueryInterface)
*/
#define CIntfObject CXIntfObject

class OBJECTBASE_EXPORT CIntfObject : virtual public IICSUnknown  
{
public:                     
    CIntfObject(IICSUnknown *pOuter = 0);
    virtual ~CIntfObject();
	
    virtual int AddRef();
    virtual int Release();
    virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown);

protected:
    //对象本身的IICSUnknown接口实现
    virtual int ObjAddRef();
    virtual int ObjRelease();
    virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);
	
    int m_iRef;                         //引用计数
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
};

//锁类：用于函数内部
class OBJECTBASE_EXPORT CLocker
{
private:
    QMutex *m_pMutex;
public:
    CLocker(QMutex *mutex)
    {   
        m_pMutex = mutex; 
        m_pMutex->lock();
    };
    ~CLocker()
    {   
        m_pMutex->unlock();
    };
};

int OBJECTBASE_EXPORT QStringToChar(QString &s, char *pchar, int nSize);
int OBJECTBASE_EXPORT QCStringToChar(Q3CString &s, char *pchar, int nSize);
void OBJECTBASE_EXPORT WriteRunLog(const char* model, const char* format, ...);
int OBJECTBASE_EXPORT IStringToHandle(const char* str);

#endif 
