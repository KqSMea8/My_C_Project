//----------------------------------------------PulseCacul.h-----------------------------------------------//

#ifndef _ICS8000_PULSECACUL_H_INCLUDE_
#define _ICS8000_PULSECACUL_H_INCLUDE_

#include "icsunknown.h"
#include "objsintf.h"

#define IID_IPulseCacul "IPulseCacul"
#define MODULE_PULSETR	 "pulsetr"

class IPulseCacul;
typedef bool (*RegisterPulseCacul)(IPulseCacul* pCacul);

#define METHOD_REGISTERPULSECACUL "RegisterCacul"

class IPulseCacul : public IICSUnknown
{
public:
	virtual bool Cacul(ITaskObject* pOldPulse, ITaskObject* pNewPulse, double* pval, int quality, double dt)=0;
};

#endif //_ICS8000_PULSECACUL_H_INCLUDE_
