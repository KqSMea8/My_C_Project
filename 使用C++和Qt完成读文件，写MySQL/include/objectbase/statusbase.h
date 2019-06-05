//statusbase.h
#ifndef _STATUSBASE_PENGSHIKANG_20131112_H_
#define _STATUSBASE_PENGSHIKANG_20131112_H_

#ifdef _MSC_VER
	#ifdef STATUSBASE
		#define STATUSCODE_EXPORT __declspec(dllexport)
	#else
		#define STATUSCODE_EXPORT __declspec(dllimport)
	#endif
#else
	#define STATUSCODE_EXPORT
#endif

#endif 
