#ifndef _COMMDEFINE_H
#define _COMMDEFINE_H

#ifdef WIN32

#if (_MSC_VER >= 1300)                  //vc7.1以上
typedef unsigned long long  ULONG64;    ///<64位无符号整数
typedef signed   long long  LONG64;     ///<64位有符号整数
#define INT64C(var) (var## LL)
#else                                   // vc6以及下
typedef unsigned __int64    ULONG64;    ///<64位无符号整数
typedef signed   __int64    LONG64;     ///<64位有符号整数

#define INT64C(var) (var## L)

#endif
#else //gcc版本
typedef unsigned long long  ULONG64;    ///<64位无符号整数
typedef signed   long long  LONG64;     ///<64位有符号整数
#define INT64C(var) ( var ## LL)

#endif

#endif

