
#ifndef _ICSSTREAM__H_
#define _ICSSTREAM__H_

#include "intfobject.h"
#include "../../interface/generalintf.h" // for IICSStream

#define DEFAULT_STREAM_LEN 1024
#define DEFAULT_INCREMENT_LEN 256

/*
ÀàCICSStream¶¨Òå
*/
class OBJECTBASE_EXPORT CICSStream : public CIntfObject  
{
protected:
    BYTE *m_pBuffer;
    BYTE *m_psRead;
    BYTE *m_psWrite;
    int m_iCapacity;
    bool SetCapacity(int len);
    bool IncreaseCapacity(int len = DEFAULT_INCREMENT_LEN);
public:     
    CICSStream(IICSUnknown *pOuter = 0);
    virtual ~CICSStream();
    bool ObjQueryInterface(const char *InterfaceName, void **ppUnknown);
public:
    bool CanRead();     
    bool CanWrite();
    int Length();       
    int Read(BYTE *buff, int nSize);
    int Write(BYTE *buff, int nSize);
    bool Seek(int origin, int offset);
    void Clone(IICSStream **ppStream);
    class OBJECTBASE_EXPORT XICSStream: public IICSStream
    {
    public:
        CICSStream *m_pParent;
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
        virtual bool CanRead()
        {   
            return m_pParent->CanRead();
        };
        virtual bool CanWrite()
        {   
            return m_pParent->CanWrite();
        };
        virtual int Length()
        {   
            return m_pParent->Length();
        };      
        virtual int Read(BYTE *buff, int nSize)
        {   
            return m_pParent->Read(buff, nSize);
        };
        virtual int Write(BYTE *buff, int nSize)
        {   
            return m_pParent->Write(buff, nSize);
        };
        virtual bool Seek(int origin, int offset)
        {   
            return m_pParent->Seek(origin, offset);
        };
        virtual void Clone(IICSStream **ppStream)
        {   
            m_pParent->Clone(ppStream);
        };
    }m_ICSStream;
};

#endif 
