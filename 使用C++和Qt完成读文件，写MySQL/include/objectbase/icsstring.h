#ifndef _ICSSTRING__H_
#define _ICSSTRING__H_

#include "objectbase.h" // for OBJECTBASE_EXPORT
#include <string.h>

#define STRING_INIT_LENGTH	32
const char CASE_SUB = 'a' - 'A';

/*
为了解决QString的隐含共享和内部函数都是可重入的问题,特编写CICSString类:
1, CICSString代表传统的以'/0'结束的C字符串
2, CICSString类内部处理不考虑编码,对于双字节字符多字节字符,字符转换的结果不确定(对每一个字符进行处理:如MakeLower等)
3, CICSString的const成员函数是线程安全的,当你多线程调用共享的CICSString实例时如果有一处调用非const成员函数,则都需要同步
4, 字符串存储空间初始化为32个字节长度,当不够时翻倍
5, 所有的操作的位置都是zero-based
6, CICSString类的大多方法抄自CString,少数抄自QString
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
	
	//取子字符串(zero-based)
	CICSString Mid(int nFirst, int nCount) const;
	CICSString Mid(int nFirst) const;
	CICSString Left(int nCount) const;
	CICSString Right(int nCount) const;
	
	// 从左边开始查找,没有找到返回-1(zero-based)
	int Find(char ch) const;
	// 从左边第nStart个字符开始查找,没有找到返回-1(zero-based)
	int Find(char ch, int nStart) const;

	//查找子字符串
	int Find(const char* pSubStr) const;
	int Find(const char* pSubStr, int nStart) const;

	// 转换为大写
	void MakeUpper();
	// 转换为小写
	void MakeLower();
	// 颠倒顺序
	void MakeReverse();

	// 去掉左边所有的空格
	void TrimRight();
	// 去掉右边所有的空格
	void TrimLeft();

	// 去掉目标字符或字符串
	void TrimRight(char chTarget);	
	void TrimRight(const char* strTarget);
	void TrimLeft(char chTarget);
	void TrimLeft(const char*strTarget);

	// 替换字符或字符哈串
	int Replace(char chOld, char chNew);
	int Replace(const char* pOldStr, const char* pNewStr);
	int Remove(char chRemove);

	// 插入字符或字符串(zero-based)
	int Insert(int nIndex, char ch);
	int Insert(int nIndex, const char*pstr);

	// 删除字符
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
