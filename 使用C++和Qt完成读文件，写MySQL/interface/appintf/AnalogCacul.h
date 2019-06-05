//==============================================AnalogCal.h==================================================//
#ifndef _INCLUDE_ANALOGCAL_H_
#define _INCLUDE_ANALOGCAL_H_

#include "icsunknown.h"
#include "objsintf.h"

#define IID_IAnalogCacul "IAnalogCacul"
#define MODULE_ANALOGTR	 "analogtr"

class IAnalogCacul;

typedef bool (*RegisterAnalogCacul)(IAnalogCacul* pCacul);

#define METHOD_REGISTERANALOGCACUL "RegisterCacul"

class IAnalogCacul : public IICSUnknown
{
public:
	virtual bool Cacul(ITaskObject* pOldAna, ITaskObject* pNewAna, double* pval, int quality, double dt)=0;
};

#endif //_INCLUDE_ANALOGCAL_H_
