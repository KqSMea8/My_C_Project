#ifndef __GENERALINTFIMPL_EXPORT_DEF_H_INCLUDED__
#define __GENERALINTFIMPL_EXPORT_DEF_H_INCLUDED__

#ifndef GENERALINTFIMPL_CLASS
	#ifdef _MSC_VER
		#ifdef GENERALINTFIMPL_DLL
			#define GENERALINTFIMPL_CLASS __declspec(dllexport)
		#else
			#define GENERALINTFIMPL_CLASS __declspec(dllimport)
		#endif
	#else
		#define GENERALINTFIMPL_CLASS
	#endif
#endif

#endif



