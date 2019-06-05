#ifndef _COMMDEFINE_H
#define _COMMDEFINE_H

#ifdef WIN32

#if (_MSC_VER >= 1300)                  //vc7.1����
typedef unsigned long long  ULONG64;    ///<64λ�޷�������
typedef signed   long long  LONG64;     ///<64λ�з�������
#define INT64C(var) (var## LL)
#else                                   // vc6�Լ���
typedef unsigned __int64    ULONG64;    ///<64λ�޷�������
typedef signed   __int64    LONG64;     ///<64λ�з�������

#define INT64C(var) (var## L)

#endif
#else //gcc�汾
typedef unsigned long long  ULONG64;    ///<64λ�޷�������
typedef signed   long long  LONG64;     ///<64λ�з�������
#define INT64C(var) ( var ## LL)

#endif

#endif

