/*
�ļ���: intfObject.h
����:   ������CIntfObject.h
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
(1) ʵ��IICSUnknown�ӿ�
(2) �ṩ�麯���������������ʵ�ֻ���ʵ�ֵĽӿ�(objQueryInterface)
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
    //�������IICSUnknown�ӿ�ʵ��
    virtual int ObjAddRef();
    virtual int ObjRelease();
    virtual bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);
	
    int m_iRef;                         //���ü���
    QMutex m_Mutex;
    IICSUnknown *m_pOuter;
};

//���ࣺ���ں����ڲ�
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
