//objectbase.h
#ifndef _OBJECTBASE__H_
#define _OBJECTBASE__H_

#ifdef _MSC_VER
	#ifdef OBJECTBASE
		#define OBJECTBASE_EXPORT __declspec(dllexport)
	#else
		#define OBJECTBASE_EXPORT __declspec(dllimport)
	#endif
#else
	#define OBJECTBASE_EXPORT
#endif

#endif 
