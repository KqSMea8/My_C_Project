#ifndef _HMITRENDOBJ_MACRODEF_H_
#define _HMITRENDOBJ_MACRODEF_H_


#ifdef _MSC_VER
#ifdef HMITRENDOBJ_DLL
#define HMITRENDOBJ_EXPORT __declspec(dllexport)
#else
#define HMITRENDOBJ_EXPORT __declspec(dllimport)
#endif
#else
#define HMITRENDOBJ_EXPORT
#endif

#endif	//_HMITRENDOBJ_MACRODEF_H_