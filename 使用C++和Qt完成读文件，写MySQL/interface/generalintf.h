#ifndef _GENERATEINTF__H_
#define _GENERATEINTF__H_

#include "icsunknown.h"
#include "qiptr.h"

class IICSStream;
class IICSEnum;
class IICSPersistStream;

#define DLL_OBJECTBASE          "objectbase"
#define CLSID_IICSEnum          "icsenum"
#define IID_IICSEnum			"iicsenum"
#define IID_IICSStream			"iicsstream"
#define IID_IICSPersistStream	"iicspersiststream"
#define CLSID_ICSStream			"icsstream"

typedef unsigned char BYTE;

/*
IICSEnumö�ٽӿ�
*/
class IICSEnum : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      skip nElelement,���ص�ǰ�ӿ�
        ����  ����      ��
    */
    virtual int GetCount()=0;

    /*
        ����  �ܡ�      skip nElelement,���ص�ǰ�ӿ�
        ����  ����      nElement        ����nElement���ӿ�
                        ppObjs          ���ص�ǰ�ӿ�
    */
    virtual int Next(int nElement, IICSUnknown **ppObjs)=0;

    /*
        ����  �ܡ�      skip nElelement
        ����  ����      nElement        ����nElement���ӿ�
                        ppObjs          ���ص�ǰ�ӿ�
    */
    virtual void Skip(int nElement)=0;

    /*
        ����  �ܡ�      ��λ
        ����  ����      ��
    */
    virtual void Reset()=0;

    /*
        ����  �ܡ�      ��¡һ��ö�ٽӿ�
        ����  ����      ��
    */
    virtual void Clone(IICSEnum **ppEnum)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSEnum;
    };
};

/*
IICSStream�ӿ�
*/
class IICSStream : public IICSUnknown
{
public:
    /*
        ����  �ܡ�      �ж��Ƿ�ɶ�
        ����  ����      ��
    */
    virtual bool CanRead()=0;

    /*
        ����  �ܡ�      �ж��Ƿ��д
        ����  ����      ��
    */
    virtual bool CanWrite()=0;

    /*
        ����  �ܡ�      ��ȡ���ĳ���
        ����  ����      ��
    */
    virtual int Length()=0;

    /*
        ����  �ܡ�      ���������nSize�ֽڵ�������buf
        ����  ����      buff    ��������
                        nSize   Ҫ�����ֽ���
        ������ֵ��      ʵ�ʶ������ֽ���
    */
    virtual int Read(BYTE *buff, int nSize)=0;

    /*
        ����  �ܡ�      �ѻ�����buff��nSize���ֽ�д������
        ����  ����      buff    д������
                        nSize   Ҫд���ֽ���
        ������ֵ��      ʵ��д���ֽ���
    */
    virtual int Write(BYTE * buff, int nSize)=0;

    /*
        ����  �ܡ�      ��λ��[ע��:��ʱ����]
        ����  ����      origin  ��ʵλ��
                        offset  �ƶ��ֽ���
        ������ֵ��      ʵ��д���ֽ���
    */
    virtual bool Seek(int origin, int offset)=0;

    /*
        ����  �ܡ�      ��¡һ����
        ����  ����      ppStream[out]   ��ŷ��صĿ�¡���ӿ�
        ������ֵ��      ��
    */
    virtual void Clone(IICSStream **ppStream)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSStream;
    };
};

/*
�������û�֧�ֽӿ�
*/
class IICSPersistStream : public IICSUnknown
{	
public:
	//��ȡ������
	virtual void GetClassID(char* clsid, int size)=0;
	//��ȡ�����ڵ�ģ��
	virtual void GetModule(char* module, int size)=0;
	virtual bool Load(IICSStream* pStream)=0;
	virtual bool Save(IICSStream* pStream)=0;
public:
	static	char* GetIntfName(){return IID_IICSPersistStream;};
};

typedef CQIPtr<IICSStream>			ICSStream;
typedef CQIPtr<IICSEnum>			ICSEnum;
typedef CQIPtr<IICSPersistStream>	ICSPersistStream;

#endif 
