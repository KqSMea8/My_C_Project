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
IICSEnum枚举接口
*/
class IICSEnum : public IICSUnknown
{
public:
    /*
        【功  能】      skip nElelement,返回当前接口
        【参  数】      无
    */
    virtual int GetCount()=0;

    /*
        【功  能】      skip nElelement,返回当前接口
        【参  数】      nElement        跳过nElement个接口
                        ppObjs          返回当前接口
    */
    virtual int Next(int nElement, IICSUnknown **ppObjs)=0;

    /*
        【功  能】      skip nElelement
        【参  数】      nElement        跳过nElement个接口
                        ppObjs          返回当前接口
    */
    virtual void Skip(int nElement)=0;

    /*
        【功  能】      复位
        【参  数】      无
    */
    virtual void Reset()=0;

    /*
        【功  能】      克隆一个枚举接口
        【参  数】      无
    */
    virtual void Clone(IICSEnum **ppEnum)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSEnum;
    };
};

/*
IICSStream接口
*/
class IICSStream : public IICSUnknown
{
public:
    /*
        【功  能】      判断是否可读
        【参  数】      无
    */
    virtual bool CanRead()=0;

    /*
        【功  能】      判断是否可写
        【参  数】      无
    */
    virtual bool CanWrite()=0;

    /*
        【功  能】      获取流的长度
        【参  数】      无
    */
    virtual int Length()=0;

    /*
        【功  能】      从流里读出nSize字节到缓冲区buf
        【参  数】      buff    读缓冲区
                        nSize   要读的字节数
        【返回值】      实际读出的字节数
    */
    virtual int Read(BYTE *buff, int nSize)=0;

    /*
        【功  能】      把缓冲区buff的nSize个字节写道流中
        【参  数】      buff    写缓冲区
                        nSize   要写的字节数
        【返回值】      实际写的字节数
    */
    virtual int Write(BYTE * buff, int nSize)=0;

    /*
        【功  能】      定位流[注意:暂时无用]
        【参  数】      origin  其实位置
                        offset  移动字节数
        【返回值】      实际写的字节数
    */
    virtual bool Seek(int origin, int offset)=0;

    /*
        【功  能】      克隆一个流
        【参  数】      ppStream[out]   存放返回的克隆流接口
        【返回值】      无
    */
    virtual void Clone(IICSStream **ppStream)=0;
public:
    static char *GetIntfName()
    {
        return IID_IICSStream;
    };
};

/*
定义永久化支持接口
*/
class IICSPersistStream : public IICSUnknown
{	
public:
	//获取类名称
	virtual void GetClassID(char* clsid, int size)=0;
	//获取类所在的模块
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
