#ifndef _HMITRENDWND_MACRODEF_H_
#define _HMITRENDWND_MACRODEF_H_


#ifdef _MSC_VER
#ifdef HMITRENDWND_DLL
#define HMITRENDWND_EXPORT __declspec(dllexport)
#else
#define HMITRENDWND_EXPORT __declspec(dllimport)
#endif
#else
#define HMITRENDWND_EXPORT
#endif


#endif	//_HMITRENDWND_MACRODEF_H_