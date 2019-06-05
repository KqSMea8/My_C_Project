/*******************************************************
 * streamaccess.h -- 数据流读写访问操作
 * 
 *******************************************************/

#ifndef STREAMACCESS_PENGSHIKANG_20120907_H
#define STREAMACCESS_PENGSHIKANG_20120907_H

#include "../objectbase/objectbase.h" // for OBJECTBASE_EXPORT
#include "../../interface/generalintf.h" // for BYTE

class OBJECTBASE_EXPORT CStreamAccess : public IICSStream
{
public:
	CStreamAccess();
	~CStreamAccess();

	/////////////////////////////////////实现IICSStream接口///////////////////////////////////////////

	virtual int AddRef();
	virtual int Release();
	virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown);

    /*判断是否可读*/
	virtual bool CanRead();
    /*判断是否可写*/
	virtual bool CanWrite();
    /*获取流的长度*/
	virtual int Length();

    /*
        【功  能】      从流里读出nSize字节到缓冲区buf
        【参  数】      buff    读缓冲区
                        nSize   要读的字节数
        【返回值】      实际读出的字节数
    */
	virtual int Read(BYTE *buff, int nSize);
    /*
        【功  能】      把缓冲区buff的nSize个字节写道流中
        【参  数】      buff    写缓冲区
                        nSize   要写的字节数
        【返回值】      实际写的字节数
    */
	virtual int Write(BYTE * buff, int nSize);

    /*
        【功  能】      定位流[注意:暂时无用]
        【参  数】      origin  其实位置
                        offset  移动字节数
        【返回值】      实际写的字节数
    */
	virtual bool Seek(int origin, int offset);
    /*
        【功  能】      克隆一个流
        【参  数】      ppStream[out]   存放返回的克隆流接口
        【返回值】      无
    */
	virtual void Clone(IICSStream **ppStream);

	////////////////////////////////////////////////////////////////////////////////

	void SetBuffer(BYTE* pBuff, unsigned int maxLen=10240);
	BYTE* GetBuffer();
	unsigned int GetMaxLength();
	unsigned int GetLength();
	void SkipAfter(int span, bool relative=true); 

	BYTE ReadBYTE();
	short ReadShort();
	int ReadInt();
	float ReadFloat();
	double ReadDouble();
	void ReadString(char* sValue, unsigned int length=255);

	void WriteBYTE(BYTE bValue);
	void WriteShort(short sValue);
	void WriteInt(int nValue);
	void WriteFloat(float fValue);
	void WriteDouble(double dValue);
	void WriteString(const char* strValue);

private:
	void ReadData(BYTE* pValue, unsigned int span);
	void WriteData(BYTE* pValue, unsigned int span);

	BYTE* m_pInitBuff;
	BYTE* m_pCurrBuff;
	unsigned int m_maxLength;
	bool m_isNew;
};

#endif
