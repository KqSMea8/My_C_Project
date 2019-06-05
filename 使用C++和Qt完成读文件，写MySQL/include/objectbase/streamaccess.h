/*******************************************************
 * streamaccess.h -- ��������д���ʲ���
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

	/////////////////////////////////////ʵ��IICSStream�ӿ�///////////////////////////////////////////

	virtual int AddRef();
	virtual int Release();
	virtual bool QueryInterface(const char *InterfaceName, void **ppUnknown);

    /*�ж��Ƿ�ɶ�*/
	virtual bool CanRead();
    /*�ж��Ƿ��д*/
	virtual bool CanWrite();
    /*��ȡ���ĳ���*/
	virtual int Length();

    /*
        ����  �ܡ�      ���������nSize�ֽڵ�������buf
        ����  ����      buff    ��������
                        nSize   Ҫ�����ֽ���
        ������ֵ��      ʵ�ʶ������ֽ���
    */
	virtual int Read(BYTE *buff, int nSize);
    /*
        ����  �ܡ�      �ѻ�����buff��nSize���ֽ�д������
        ����  ����      buff    д������
                        nSize   Ҫд���ֽ���
        ������ֵ��      ʵ��д���ֽ���
    */
	virtual int Write(BYTE * buff, int nSize);

    /*
        ����  �ܡ�      ��λ��[ע��:��ʱ����]
        ����  ����      origin  ��ʵλ��
                        offset  �ƶ��ֽ���
        ������ֵ��      ʵ��д���ֽ���
    */
	virtual bool Seek(int origin, int offset);
    /*
        ����  �ܡ�      ��¡һ����
        ����  ����      ppStream[out]   ��ŷ��صĿ�¡���ӿ�
        ������ֵ��      ��
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
