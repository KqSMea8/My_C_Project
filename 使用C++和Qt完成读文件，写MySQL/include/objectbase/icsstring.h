#ifndef _ICSSTRING__H_
#define _ICSSTRING__H_

#include "objectbase.h" // for OBJECTBASE_EXPORT
#include <string.h>

#define STRING_INIT_LENGTH	32
const char CASE_SUB = 'a' - 'A';

/*
Ϊ�˽��QString������������ڲ��������ǿ����������,�ر�дCICSString��:
1, CICSString����ͳ����'/0'������C�ַ���
2, CICSString���ڲ��������Ǳ���,����˫�ֽ��ַ����ֽ��ַ�,�ַ�ת���Ľ����ȷ��(��ÿһ���ַ����д���:��MakeLower��)
3, CICSString��const��Ա�������̰߳�ȫ��,������̵߳��ù����CICSStringʵ��ʱ�����һ�����÷�const��Ա����,����Ҫͬ��
4, �ַ����洢�ռ��ʼ��Ϊ32���ֽڳ���,������ʱ����
5, ���еĲ�����λ�ö���zero-based
6, CICSString��Ĵ�෽������CString,��������QString
*/
class OBJECTBASE_EXPORT CICSString
{
protected:
	char* m_pStr;
	int m_iCapacity;	
	bool IncreaseCapacity(int len = 0);
public:
	CICSString();
	~CICSString();
	CICSString(const char* pstr);
	CICSString(const CICSString& strSrc);
	int GetLength() const;
	operator const char*() const;
	void Format(const char* pFormatStr, ...);

	const CICSString& operator=(const CICSString& stringSrc);
	const CICSString& operator=(const char* pstr);
	const CICSString& operator+=(const CICSString& str);
	const CICSString& operator+=(const char* pstr);
	const CICSString& operator+=(char ch);
	
	//ȡ���ַ���(zero-based)
	CICSString Mid(int nFirst, int nCount) const;
	CICSString Mid(int nFirst) const;
	CICSString Left(int nCount) const;
	CICSString Right(int nCount) const;
	
	// ����߿�ʼ����,û���ҵ�����-1(zero-based)
	int Find(char ch) const;
	// ����ߵ�nStart���ַ���ʼ����,û���ҵ�����-1(zero-based)
	int Find(char ch, int nStart) const;

	//�������ַ���
	int Find(const char* pSubStr) const;
	int Find(const char* pSubStr, int nStart) const;

	// ת��Ϊ��д
	void MakeUpper();
	// ת��ΪСд
	void MakeLower();
	// �ߵ�˳��
	void MakeReverse();

	// ȥ��������еĿո�
	void TrimRight();
	// ȥ���ұ����еĿո�
	void TrimLeft();

	// ȥ��Ŀ���ַ����ַ���
	void TrimRight(char chTarget);	
	void TrimRight(const char* strTarget);
	void TrimLeft(char chTarget);
	void TrimLeft(const char*strTarget);

	// �滻�ַ����ַ�����
	int Replace(char chOld, char chNew);
	int Replace(const char* pOldStr, const char* pNewStr);
	int Remove(char chRemove);

	// �����ַ����ַ���(zero-based)
	int Insert(int nIndex, char ch);
	int Insert(int nIndex, const char*pstr);

	// ɾ���ַ�
	int Delete(int nIndex, int nCount = 1);	

	friend CICSString OBJECTBASE_EXPORT operator+(const CICSString& string1, const CICSString& string2);
	friend CICSString OBJECTBASE_EXPORT operator+(const CICSString& str, char ch);
	friend CICSString OBJECTBASE_EXPORT operator+(char ch, const CICSString& str);
	friend CICSString OBJECTBASE_EXPORT operator+(const CICSString& str, const char* pstr);
	friend CICSString OBJECTBASE_EXPORT operator+(const char*pstr, const CICSString& str);
};

inline int OBJECTBASE_EXPORT icsstrcmp(const char *str1, const char *str2)
{
    return (str1 && str2) ? strcmp(str1, str2) : (str1 ? 1 : (str2 ? -1 : 0));
}

inline bool OBJECTBASE_EXPORT icsIsUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

inline char OBJECTBASE_EXPORT icsToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + CASE_SUB;
    else
        return c;
}

inline bool OBJECTBASE_EXPORT icsIsLower(char c)
{ 
	return c >= 'a' && c <= 'z';
}

inline char OBJECTBASE_EXPORT icsToUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - CASE_SUB;
    else
        return c;
}

inline bool OBJECTBASE_EXPORT operator==(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) == 0;}
inline bool OBJECTBASE_EXPORT operator==(const CICSString& s1, const char* s2)
{return icsstrcmp((const char*)s1, s2) == 0;}
inline bool OBJECTBASE_EXPORT operator==(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) == 0;}
inline bool OBJECTBASE_EXPORT operator!=(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) != 0;}
inline bool OBJECTBASE_EXPORT operator!=(const CICSString& s1, const char* s2)
{return icsstrcmp((const char*)s1, s2) != 0;}
inline bool OBJECTBASE_EXPORT operator!=(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) != 0;}
inline bool OBJECTBASE_EXPORT operator<(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) < 0;}
inline bool OBJECTBASE_EXPORT operator<(const CICSString& s1, const char*s2)
{return icsstrcmp((const char*)s1, s2) < 0;}
inline bool OBJECTBASE_EXPORT operator<(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) < 0;}
inline bool OBJECTBASE_EXPORT operator>(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) > 0;}
inline bool OBJECTBASE_EXPORT operator>(const CICSString& s1, const char* s2)
{return icsstrcmp((const char*)s1, s2) > 0;}
inline bool OBJECTBASE_EXPORT operator>(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) > 0;}
inline bool OBJECTBASE_EXPORT operator<=(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) <= 0;}
inline bool OBJECTBASE_EXPORT operator<=(const CICSString& s1, const char* s2)
{return icsstrcmp((const char*)s1, s2) <= 0;}
inline bool OBJECTBASE_EXPORT operator<=(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) <= 0;}
inline bool OBJECTBASE_EXPORT operator>=(const CICSString& s1, const CICSString& s2)
{return icsstrcmp((const char*)s1, (const char*)s2) >= 0;}
inline bool OBJECTBASE_EXPORT operator>=(const CICSString& s1, const char* s2)
{return icsstrcmp((const char*)s1, s2) >= 0;}
inline bool OBJECTBASE_EXPORT operator>=(const char* s1, const CICSString& s2)
{return icsstrcmp(s1, (const char*)s2) >= 0;}

CICSString OBJECTBASE_EXPORT operator+(const CICSString& string1, const CICSString& string2);
CICSString OBJECTBASE_EXPORT operator+(const CICSString& str, char ch);
CICSString OBJECTBASE_EXPORT operator+(char ch, const CICSString& str);
CICSString OBJECTBASE_EXPORT operator+(const CICSString& str, const char* pstr);
CICSString OBJECTBASE_EXPORT operator+(const char*pstr, const CICSString& str);

void OBJECTBASE_EXPORT ICSStringToChar(const CICSString& s, char* p, int size);

#endif
