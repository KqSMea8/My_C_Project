#ifndef	_TASKSHARELIB_H_
#define _TASKSHARELIB_H_

#ifdef _MSC_VER
	#ifdef TASKSHARELIB
		#define TASK_EXPORT __declspec(dllexport)
	#else
		#define TASK_EXPORT __declspec(dllimport)
	#endif
#else
	#define TASK_EXPORT
#endif

#endif 