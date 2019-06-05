#ifndef _OBJSYSCOMMON_EXPORT_DEF__H_
#define _OBJSYSCOMMON_EXPORT_DEF__H_

#ifndef OBJSYSCOMMON_CLASS
	#ifdef _MSC_VER
		#ifdef OBJSYSCOMMON_DLL
			#define OBJSYSCOMMON_CLASS __declspec(dllexport)
		#else
			#define OBJSYSCOMMON_CLASS __declspec(dllimport)
		#endif
	#else
		#define OBJSYSCOMMON_CLASS
	#endif
#endif

#endif



